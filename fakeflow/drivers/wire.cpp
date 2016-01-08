
#include "buffer.hpp"
#include "port_table.hpp"
#include "system.hpp"
#include "timer.hpp"

using namespace fp;

int main(int argc, char* argv[])
{
  try {
    long long pkt_no = atoll(argv[2]);

    // Goes somewhere, IDC where.
    fp::Port* p1 = fp::create_port(fp::Port::Type::tcp, ":5000", "p1");
    std::cerr << "Created port 'p1' with id '" << p1->id() << "'\n";

    assert(p1);

    // Load the application library
    fp::load_application(argv[1]);
    std::cerr << "Loaded application\n";

    // Create the dataplane with the loaded application library.
    fp::Dataplane* dp = fp::create_dataplane("dp1", argv[1]);
    std::cerr << "Created data plane '" << dp->name() << "'\n";

    // Add all ports
    dp->add_port(p1);
    std::cerr << "Added port 'p1' to data plane 'dp1'\n";

    // Configure the data plane based on the applications needs.
    dp->configure();
    std::cerr << "Data plane configured\n";


    dp->up();
    std::cerr << "Data plane is up\n";

    std::cout << "Sending " << pkt_no << " packets.\n";

    { // block

      long long i = 0;
      Timer t;

      while(i < pkt_no) {
        Byte* data = new Byte[1500]{
          // src bytes
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          // dst bytes
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          // type bytes
          ' ', '\03', 0, 0, 0
        };

        Packet* pkt = packet_create(data, 1500, 0, nullptr, FP_BUF_ALLOC);

        dp->process(p1, pkt);
        ++i;
        packet_destroy(pkt);
      }
      // timer dtor should print time here

    } // block

  }
  catch(std::string s)
  {
    std::cout << s;
  }

  std::cout << "Done\n";

  return 0;
}
