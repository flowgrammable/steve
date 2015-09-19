#ifndef STEVE_TRANSLATE_PIPELINE_HPP
#define STEVE_TRANSLATE_PIPELINE_HPP

#include "steve/net.hpp"

namespace steve
{

// Make this inherit from translator parent class???
struct Pipeline_translator
{
  // In order to translate the pipeline into C++ we need to know certain
  // things discovered during the compilation process
  // 1. All decoders, tables, their bodies, and their associated metadata
  // 2. The header environment which assigns an integer representation to header names
  // 3. The field environment which assigns an integer representation to field names
  Pipeline_translator(Pipeline const* stages)
    : pipeline_(stages)
  { }

  // translate into c++
  void translate();

  void write(String filename);

  String code;
  Pipeline const* pipeline_;
};

} // namespace steve


#endif