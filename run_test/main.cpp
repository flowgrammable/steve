
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "constructs.hpp"
#include "interface.hpp"

int main()
{
  Context* c = new Context();

  void* handle;
  void (*process)(Context*);
  void (*load)();
  char *error;

  handle = dlopen ("../output.so", RTLD_LAZY);
  if (!handle) {
      fputs (dlerror(), stderr);
      exit(1);
  }

  // typecast
  load = (void (*)()) dlsym(handle, "load");
  if ((error = dlerror()) != NULL)  {
      fputs(error, stderr);
      exit(1);
  }

  // typecast
  process = (void (*)(Context*)) dlsym(handle, "process");
  if ((error = dlerror()) != NULL)  {
      fputs(error, stderr);
      exit(1);
  }

  // load
  (*load)();
  // process
  (*process)(c);

  dlclose(handle);

  puts(c->log.c_str());
}
