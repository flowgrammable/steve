
#include "buffer.hpp"
#include "port_table.hpp"
#include "system.hpp"

using namespace fp;

int main(int argc, char* argv[])
{
  int i = 0;

  try {
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

    unsigned char* data = new unsigned char[1500];
    Packet* pkt = packet_create(data, 1500, 0, nullptr, FP_BUF_ALLOC);
    dp->process(p1, pkt);

    while(i < 100) {
      ++i;
    }
  }
  catch(std::string s)
  {
    std::cout << s;
  }

  return 0;
}
