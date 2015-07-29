
namespace steve
{


// Synonymous with get_boolean_type.
inline Boolean_type const*  
get_bool_type()
{
  return get_boolean_type();
}


// Precise integer types


// Return a signed, native byte order integer with `n` bits
// of precision.
inline Integer_type const* 
get_int_type(int p)
{
  return get_integer_type(p, signed_int, native_order);
}

// Return an unsigned, native byte order integer with
// `n` bits of precision.
inline Integer_type const* 
get_uint_type(int p)
{
  return get_integer_type(p, unsigned_int, native_order);
}


// Return a signed, MSBF integer with `n` bits of precision.
inline Integer_type const* 
get_msbf_type(int p)
{
  return get_integer_type(p, signed_int, msbf_order);
}


// Return an unsigned, MSBF integer with `n` bits of precision.
inline Integer_type const* 
get_umsbf_type(int p)
{
  return get_integer_type(p, unsigned_int, msbf_order);
}


// Return a signed, LSBF integer with `n` bits of precision.
inline Integer_type const* 
get_lsbf_type(int p)
{
  return get_integer_type(p, signed_int, lsbf_order);
}


// Return an unsigned, LSBF integer with `n` bits of precision.
inline Integer_type const* 
get_ulsbf_type(int p)
{
  return get_integer_type(p, unsigned_int, lsbf_order);
}


// Common integer types


// Return the default signed integer type for the target system.
//
// TODO: Make this a runtime configuration parameter.
inline Integer_type const* 
get_short_type()
{
  return get_int_type(16);
}


// Return the default signed integer type for the target system.
//
// TODO: Make this a runtime configuration parameter.
inline Integer_type const* 
get_int_type()
{
  return get_int_type(32);
}


// Return the default signed integer type for the target system.
//
// TODO: Make this a runtime configuration parameter.
inline Integer_type const* 
get_long_type()
{
  return get_int_type(64);
}


// Returns the default unsigned short integer type for the target system.
//
// TODO: Make this a runtime configuration parameter.
inline Integer_type const*
get_ushort_type()
{
  return get_uint_type(16);
}


// Returns the default unsigned integer type for the target system.
//
// TODO: Make this a runtime configuration parameter.
inline Integer_type const* 
get_uint_type()
{
  return get_uint_type(32);
}


// Returns the default unsigned integer type for the target system.
//
// TODO: Make this a runtime configuration parameter.
inline Integer_type const* 
get_ulong_type()
{
  return get_uint_type(64);
}

} // namespace steve
