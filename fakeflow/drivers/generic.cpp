
#include "buffer.hpp"
#include "system.hpp"
#include "port_table.hpp"
#include "timer.hpp"
#include "capture.hpp"

#include <cstdlib>
#include <ctime>

using namespace fp;
using namespace ff;

// Asumptions:
// argv[1] will always be the pcap file name.
// This only deals with ethernet frames.
int main(int argc, char* argv[])
{
  try {
    // ---------------------------------------------------------------------- //
    //          Setup dataplane

    // Create some arbitrary ports.
    // Goes somewhere, IDC where, fakeflow doesnt really use ports anyway.
    fp::Port* p1 = fp::create_port(fp::Port::Type::tcp, ":5000", "p1");
    std::cerr << "Created port 'p1' with id '" << p1->id() << "'\n";
    fp::Port* p2 = fp::create_port(fp::Port::Type::tcp, ":5001", "p2");
    std::cerr << "Created port 'p2' with id '" << p2->id() << "'\n";
    fp::Port* p3 = fp::create_port(fp::Port::Type::tcp, ":5002", "p3");
    std::cerr << "Created port 'p3' with id '" << p3->id() << "'\n";
    fp::Port* p4 = fp::create_port(fp::Port::Type::tcp, ":5003", "p4");
    std::cerr << "Created port 'p4' with id '" << p4->id() << "'\n";
    fp::Port* p5 = fp::create_port(fp::Port::Type::tcp, ":5004", "p5");
    std::cerr << "Created port 'p5' with id '" << p5->id() << "'\n";

    // Port array.
    fp::Port* ports[5]{p1, p2, p3, p4, p5};

    // Load the application library
    fp::load_application(argv[1]);
    std::cerr << "Loaded application\n";

    // Create the dataplane with the loaded application library.
    fp::Dataplane* dp = fp::create_dataplane("dp1", argv[1]);
    std::cerr << "Created data plane '" << dp->name() << "'\n";

    // Add all ports
    dp->add_port(p1);
    dp->add_port(p2);
    dp->add_port(p3);
    dp->add_port(p4);
    dp->add_port(p5);
    dp->add_reserved_ports();

    // Configure the data plane based on the applications needs.
    dp->configure();
    std::cerr << "Data plane configured\n";

    // ---------------------------------------------------------------------- //
    //          Start feeding packets.

    std::cout << "Loading: " << argv[2] << std::endl;

    // Open an offline stream capture.
    cap::Stream cap(cap::offline(argv[2]));
    if (cap.link_type() != cap::ethernet_link) {
      std::cerr << "error: input is not ethernet\n";
      return 1;
    }

    // Iterate over each packet and and send each packet to the
    // connected host.
    int iterations = 1; // number of repeats
    if (argc > 3)
      iterations = std::stoi(argv[3]);

    // Allow for number of ports as args.
    int num_ports = 5;
    if (argc > 4)
      num_ports = std::stoi(argv[4]);

    std::uint64_t n = 0;
    std::uint64_t b = 0;
    cap::Packet p;
    int sent = 0;
    double elapsed = 0;
    std::srand(std::time(0));
    { // anon block
      Timer t;
      while (cap.get(p)) {
        for (int i = 0; i < iterations; i++) {
          std::uint8_t* buf = new std::uint8_t[p.captured_size()];
          std::unique_ptr<uint8_t> ptr(buf);
          std::memcpy(&buf[0], p.data(), p.captured_size());

          int r = std::rand() % num_ports;
          Port* rand_port = ports[r];

          fp::Packet pkt(&buf[0], p.captured_size(), 0, nullptr, FP_BUF_ALLOC);

          dp->process(rand_port, &pkt);
          // std::cout << "sent: " << p.captured_size() << " bytes\n";
          ++n, ++sent;
          b += p.captured_size();
        }
      }
      elapsed = t.elapsed();
    }; // end block

    std::cout << "Sent: " << sent << " packets." << '\n';
    std::cout << "Byte sent:" << b << " bytes." << '\n';
    std::cout << "Gigabytes sent: " << b * 1e-9 << "" << '\n';
    std::cout << "Gbits sent:" << b * 8e-9 << "" << '\n';
    std::cout << "Rate sent:" << (b * 8e-9) / elapsed << "Gbps" << '\n';
  }
  catch(std::string s)
  {
    std::cout << s << '\n';
  }
  std::cout << "Done\n";

  return 0;
}
