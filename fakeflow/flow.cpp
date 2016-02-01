
#include "flow.hpp"
#include "system.hpp"

namespace fp
{

void Drop_miss(Flow*, Table*, Context* c)
{
  // TODO: Drop packet.
  fp_drop(c);
}

}
