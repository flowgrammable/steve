; ModuleID = 'libsteve.cpp'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"struct.std::piecewise_construct_t" = type { i8 }
%"class.std::ios_base::Init" = type { i8 }
%"struct.__gnu_cxx::__ops::_Iter_less_iter" = type { i8 }
%"struct.__gnu_cxx::__ops::_Iter_less_val" = type { i8 }
%"struct.__gnu_cxx::__ops::_Val_less_iter" = type { i8 }
%"struct.__gnu_cxx::__ops::_Iter_equal_to_iter" = type { i8 }
%"struct.__gnu_cxx::__ops::_Iter_equal_to_val" = type { i8 }
%"class.std::exception" = type { i32 (...)** }
%"class.std::bad_exception" = type { %"class.std::exception" }
%"class.std::__exception_ptr::exception_ptr" = type { i8* }
%"class.std::nested_exception" = type { i32 (...)**, %"class.std::__exception_ptr::exception_ptr" }
%"class.std::bad_alloc" = type { %"class.std::exception" }
%"class.std::bad_array_new_length" = type { %"class.std::bad_alloc" }
%"struct.std::_Bit_reference" = type { i64*, i64 }
%"struct.std::_Bit_iterator_base" = type <{ i64*, i32, [4 x i8] }>
%"struct.std::_Bit_iterator" = type { %"struct.std::_Bit_iterator_base.base", [4 x i8] }
%"struct.std::_Bit_iterator_base.base" = type <{ i64*, i32 }>
%"struct.std::_Bit_const_iterator" = type { %"struct.std::_Bit_iterator_base.base", [4 x i8] }
%"struct.std::iterator" = type { i8 }
%"struct.std::hash" = type { i8 }
%"struct.std::hash.0" = type { i8 }
%"struct.std::hash.2" = type { i8 }
%"struct.std::hash.4" = type { i8 }
%"struct.std::hash.6" = type { i8 }
%"struct.std::hash.8" = type { i8 }
%"struct.std::hash.10" = type { i8 }
%"struct.std::hash.12" = type { i8 }
%"struct.std::hash.14" = type { i8 }
%"struct.std::hash.16" = type { i8 }
%"struct.std::hash.18" = type { i8 }
%"struct.std::hash.20" = type { i8 }
%"struct.std::hash.22" = type { i8 }
%"struct.std::hash.24" = type { i8 }
%"struct.std::hash.26" = type { i8 }
%"struct.std::hash.28" = type { i8 }
%"struct.std::hash.30" = type { i8 }
%"struct.fp::Packet" = type <{ %"struct.fp::Buffer::Flowpath", i32, [4 x i8], i64, i8*, i32, [4 x i8] }>
%"struct.fp::Buffer::Flowpath" = type { %"struct.fp::Buffer::Base" }
%"struct.fp::Buffer::Base" = type { i32 (...)**, i8* }
%"struct.fp::Binding" = type { i16, i16 }
%"struct.fp::Binding_list" = type { [4 x %"struct.fp::Binding"], i32 }
%"struct.fp::Environment" = type { [16 x %"struct.fp::Binding_list"] }
%"struct.fp::Context" = type { %"struct.fp::Packet"*, %"struct.fp::Metadata", %"struct.fp::Context_current", i32, i32, i32, i32, %"struct.fp::Action_set", %"struct.fp::Environment", %"struct.fp::Environment" }
%"struct.fp::Metadata" = type { i64 }
%"struct.fp::Context_current" = type { i16, %"struct.fp::Table"*, %"struct.fp::Flow"* }
%"struct.fp::Table" = type opaque
%"struct.fp::Flow" = type opaque
%"struct.fp::Action_set" = type { %"class.std::vector" }
%"class.std::vector" = type { %"struct.std::_Vector_base" }
%"struct.std::_Vector_base" = type { %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl" }
%"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl" = type { %"struct.fp::Action"*, %"struct.fp::Action"*, %"struct.fp::Action"* }
%"struct.fp::Action" = type { %"union.fp::Action::Value", i8 }
%"union.fp::Action::Value" = type { %"struct.fp::Set_action" }
%"struct.fp::Set_action" = type { %"struct.fp::Field", i8* }
%"struct.fp::Field" = type { i8, i16, i16 }
%"class.std::allocator" = type { i8 }
%"class.__gnu_cxx::__normal_iterator" = type { %"struct.fp::Action"* }
%struct.ldiv_t = type { i64, i64 }
%struct.lldiv_t = type { i64, i64 }
%struct.__locale_struct = type { [13 x %struct.__locale_data*], i16*, i32*, i32*, [13 x i8*] }
%struct.__locale_data = type opaque
%struct.__va_list_tag = type { i32, i32, i8*, i8* }
%class.__pthread_cleanup_class = type { void (i8*)*, i8*, i32, i32 }
%union.pthread_attr_t = type { i64, [48 x i8] }
%union.pthread_mutex_t = type { %"struct.(anonymous union)::__pthread_mutex_s" }
%"struct.(anonymous union)::__pthread_mutex_s" = type { i32, i32, i32, i32, i32, i16, i16, %struct.__pthread_internal_list }
%struct.__pthread_internal_list = type { %struct.__pthread_internal_list*, %struct.__pthread_internal_list* }
%union.pthread_mutexattr_t = type { i32 }
%struct.timespec = type { i64, i64 }
%union.pthread_cond_t = type { %struct.anon }
%struct.anon = type { i32, i32, i64, i64, i64, i8*, i32, i32 }
%"class.std::basic_string" = type { %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" }
%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" = type { i8* }
%"class.std::allocator.32" = type { i8 }
%"class.std::basic_string.35" = type { %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Alloc_hider" }
%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Alloc_hider" = type { i32* }
%"class.std::allocator.36" = type { i8 }
%"struct.std::hash.39" = type { i8 }
%"struct.std::hash.41" = type { i8 }
%"struct.std::hash.43" = type { i8 }
%"class.std::basic_string.45" = type { %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Alloc_hider" }
%"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Alloc_hider" = type { i16* }
%"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep" = type { %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep_base" }
%"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep_base" = type { i64, i64, i32 }
%"struct.std::hash.49" = type { i8 }
%"class.std::basic_string.51" = type { %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Alloc_hider" }
%"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Alloc_hider" = type { i32* }
%"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep" = type { %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep_base" }
%"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep_base" = type { i64, i64, i32 }
%"class.std::random_device" = type { %union.anon }
%union.anon = type { %"class.std::mersenne_twister_engine" }
%"class.std::mersenne_twister_engine" = type { [624 x i64], i64 }
%"struct.std::bernoulli_distribution::param_type" = type { double }
%"class.std::bernoulli_distribution" = type { %"struct.std::bernoulli_distribution::param_type" }
%"class.std::seed_seq" = type { %"class.std::vector.55" }
%"class.std::vector.55" = type { %"struct.std::_Vector_base.56" }
%"struct.std::_Vector_base.56" = type { %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl" }
%"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl" = type { i32*, i32*, i32* }
%"class.std::locale" = type { %"class.std::locale::_Impl"* }
%"class.std::locale::_Impl" = type { i32, %"class.std::locale::facet"**, i64, %"class.std::locale::facet"**, i8** }
%"class.std::locale::facet" = type <{ i32 (...)**, i32, [4 x i8] }>
%"class.std::locale::id" = type { i64 }
%"class.std::ios_base" = type { i32 (...)**, i64, i64, i32, i32, i32, %"struct.std::ios_base::_Callback_list"*, %"struct.std::ios_base::_Words", [8 x %"struct.std::ios_base::_Words"], i32, %"struct.std::ios_base::_Words"*, %"class.std::locale" }
%"struct.std::ios_base::_Callback_list" = type { %"struct.std::ios_base::_Callback_list"*, void (i32, %"class.std::ios_base"*, i32)*, i32, i32 }
%"struct.std::ios_base::_Words" = type { i8*, i64 }
%"class.std::ctype" = type <{ %"class.std::locale::facet.base", [4 x i8], %struct.__locale_struct*, i8, [7 x i8], i32*, i32*, i16*, i8, [256 x i8], [256 x i8], i8, [6 x i8] }>
%"class.std::locale::facet.base" = type <{ i32 (...)**, i32 }>
%"struct.std::random_access_iterator_tag" = type { i8 }
%"class.std::allocator.57" = type { i8 }
%"class.__gnu_cxx::new_allocator.58" = type { i8 }
%"class.std::allocator.61" = type { i8 }
%"class.__gnu_cxx::new_allocator.62" = type { i8 }
%"class.__gnu_cxx::new_allocator.33" = type { i8 }
%"class.__gnu_cxx::new_allocator.37" = type { i8 }
%"struct.std::forward_iterator_tag" = type { i8 }
%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep" = type { %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep_base" }
%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep_base" = type { i64, i64, i32 }
%"struct.std::__false_type" = type { i8 }
%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep" = type { %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep_base" }
%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep_base" = type { i64, i64, i32 }
%"class.__gnu_cxx::new_allocator" = type { i8 }
%"class.std::move_iterator" = type { %"struct.fp::Action"* }
%"class.std::initializer_list" = type { double*, i64 }
%"class.std::initializer_list.64" = type { i8*, i64 }

@_ZStL19piecewise_construct = internal constant %"struct.std::piecewise_construct_t" undef, align 1
@_ZTVSt9exception = external unnamed_addr constant [5 x i8*]
@_ZTVSt13bad_exception = external unnamed_addr constant [5 x i8*]
@_ZTVSt16nested_exception = external unnamed_addr constant [4 x i8*]
@_ZTVSt9bad_alloc = external unnamed_addr constant [5 x i8*]
@_ZTVSt20bad_array_new_length = external unnamed_addr constant [5 x i8*]
@_ZN9__gnu_cxx24__numeric_traits_integerIlE5__maxE = linkonce_odr constant i64 9223372036854775807, align 8
@_ZN2fpL13Packet_memoryE = internal constant i32 0, align 4
@_ZN2fpL15Metadata_memoryE = internal constant i32 1, align 4
@.str = private unnamed_addr constant [12 x i8] c"!is_empty()\00", align 1
@.str1 = private unnamed_addr constant [14 x i8] c"./binding.hpp\00", align 1
@__PRETTY_FUNCTION__._ZNK2fp12Binding_list3topEv = private unnamed_addr constant [49 x i8] c"const fp::Binding &fp::Binding_list::top() const\00", align 1
@__PRETTY_FUNCTION__._ZN2fp12Binding_list3topEv = private unnamed_addr constant [37 x i8] c"fp::Binding &fp::Binding_list::top()\00", align 1
@__PRETTY_FUNCTION__._ZNK2fp12Binding_list6bottomEv = private unnamed_addr constant [52 x i8] c"const fp::Binding &fp::Binding_list::bottom() const\00", align 1
@__PRETTY_FUNCTION__._ZN2fp12Binding_list6bottomEv = private unnamed_addr constant [40 x i8] c"fp::Binding &fp::Binding_list::bottom()\00", align 1
@.str2 = private unnamed_addr constant [11 x i8] c"!is_full()\00", align 1
@__PRETTY_FUNCTION__._ZN2fp12Binding_list4pushENS_7BindingE = private unnamed_addr constant [41 x i8] c"void fp::Binding_list::push(fp::Binding)\00", align 1
@__PRETTY_FUNCTION__._ZN2fp12Binding_list4pushEt = private unnamed_addr constant [43 x i8] c"void fp::Binding_list::push(std::uint16_t)\00", align 1
@__PRETTY_FUNCTION__._ZN2fp12Binding_list3popEv = private unnamed_addr constant [29 x i8] c"void fp::Binding_list::pop()\00", align 1
@.str3 = private unnamed_addr constant [25 x i8] c"0 <= n && n < max_fields\00", align 1
@__PRETTY_FUNCTION__._ZN2fp11Environment4pushEiNS_7BindingE = private unnamed_addr constant [45 x i8] c"void fp::Environment::push(int, fp::Binding)\00", align 1
@__PRETTY_FUNCTION__._ZN2fp11Environment3popEi = private unnamed_addr constant [31 x i8] c"void fp::Environment::pop(int)\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"n != 0\00", align 1
@__PRETTY_FUNCTION__._ZN2fp7BindingC2Ett = private unnamed_addr constant [51 x i8] c"fp::Binding::Binding(std::uint16_t, std::uint16_t)\00", align 1
@_ZZL18__gthread_active_pvE20__gthread_active_ptr = internal constant i8* bitcast (i32 (i32*, void (i8*)*)* @__pthread_key_create to i8*), align 8
@_ZN9__gnu_cxx24__numeric_traits_integerIiE5__maxE = linkonce_odr constant i32 2147483647, align 4
@_ZN9__gnu_cxx24__numeric_traits_integerIiE5__minE = linkonce_odr constant i32 -2147483648, align 4
@_ZN9__gnu_cxx25__numeric_traits_floatingIfE16__max_exponent10E = linkonce_odr constant i32 38, align 4
@_ZN9__gnu_cxx25__numeric_traits_floatingIdE16__max_exponent10E = linkonce_odr constant i32 308, align 4
@_ZN9__gnu_cxx25__numeric_traits_floatingIeE16__max_exponent10E = linkonce_odr constant i32 4932, align 4
@.str5 = private unnamed_addr constant [5 x i8] c"stoi\00", align 1
@.str6 = private unnamed_addr constant [5 x i8] c"stol\00", align 1
@.str7 = private unnamed_addr constant [6 x i8] c"stoul\00", align 1
@.str8 = private unnamed_addr constant [6 x i8] c"stoll\00", align 1
@.str9 = private unnamed_addr constant [7 x i8] c"stoull\00", align 1
@.str10 = private unnamed_addr constant [5 x i8] c"stof\00", align 1
@.str11 = private unnamed_addr constant [5 x i8] c"stod\00", align 1
@.str12 = private unnamed_addr constant [6 x i8] c"stold\00", align 1
@.str13 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str14 = private unnamed_addr constant [3 x i8] c"%u\00", align 1
@.str15 = private unnamed_addr constant [4 x i8] c"%ld\00", align 1
@.str16 = private unnamed_addr constant [4 x i8] c"%lu\00", align 1
@.str17 = private unnamed_addr constant [5 x i8] c"%lld\00", align 1
@.str18 = private unnamed_addr constant [5 x i8] c"%llu\00", align 1
@.str19 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@.str20 = private unnamed_addr constant [4 x i8] c"%Lf\00", align 1
@.str21 = private unnamed_addr constant [3 x i32] [i32 37, i32 100, i32 0], align 4
@.str22 = private unnamed_addr constant [3 x i32] [i32 37, i32 117, i32 0], align 4
@.str23 = private unnamed_addr constant [4 x i32] [i32 37, i32 108, i32 100, i32 0], align 4
@.str24 = private unnamed_addr constant [4 x i32] [i32 37, i32 108, i32 117, i32 0], align 4
@.str25 = private unnamed_addr constant [5 x i32] [i32 37, i32 108, i32 108, i32 100, i32 0], align 4
@.str26 = private unnamed_addr constant [5 x i32] [i32 37, i32 108, i32 108, i32 117, i32 0], align 4
@.str27 = private unnamed_addr constant [3 x i32] [i32 37, i32 102, i32 0], align 4
@.str28 = private unnamed_addr constant [4 x i32] [i32 37, i32 76, i32 102, i32 0], align 4
@_ZNSt17integral_constantIbLb1EE5valueE = linkonce_odr constant i8 1, align 1
@_ZNSt17integral_constantIbLb0EE5valueE = linkonce_odr constant i8 0, align 1
@_ZTVNSt6locale5facetE = external unnamed_addr constant [4 x i8*]
@_ZN9__gnu_cxx24__numeric_traits_integerImE8__digitsE = linkonce_odr constant i32 64, align 4
@_ZN9__gnu_cxx24__numeric_traits_integerIcE5__maxE = linkonce_odr constant i8 127, align 1
@_ZN9__gnu_cxx24__numeric_traits_integerIsE5__minE = linkonce_odr constant i16 -32768, align 2
@_ZN9__gnu_cxx24__numeric_traits_integerIsE5__maxE = linkonce_odr constant i16 32767, align 2
@_ZN9__gnu_cxx24__numeric_traits_integerIlE5__minE = linkonce_odr constant i64 -9223372036854775808, align 8
@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external global i8
@.str29 = private unnamed_addr constant [42 x i8] c"basic_string::_S_construct null not valid\00", align 1
@.str30 = private unnamed_addr constant [28 x i8] c"vector::_M_emplace_back_aux\00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_libsteve.cpp, i8* null }]

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i1 @_ZN9__gnu_cxx17__is_null_pointerEDn(i8*) #0 {
  %2 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  ret i1 true
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops16__iter_less_iterEv() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Iter_less_iter", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops15__iter_less_valEv() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Iter_less_val", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops15__iter_comp_valENS0_15_Iter_less_iterE() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Iter_less_val", align 1
  %2 = alloca %"struct.__gnu_cxx::__ops::_Iter_less_iter", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops15__val_less_iterEv() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Val_less_iter", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops15__val_comp_iterENS0_15_Iter_less_iterE() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Val_less_iter", align 1
  %2 = alloca %"struct.__gnu_cxx::__ops::_Iter_less_iter", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops20__iter_equal_to_iterEv() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Iter_equal_to_iter", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops19__iter_equal_to_valEv() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Iter_equal_to_val", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx5__ops15__iter_comp_valENS0_19_Iter_equal_to_iterE() #0 {
  %1 = alloca %"struct.__gnu_cxx::__ops::_Iter_equal_to_val", align 1
  %2 = alloca %"struct.__gnu_cxx::__ops::_Iter_equal_to_iter", align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZSt4__lgi(i32 %__n) #0 {
  %1 = alloca i32, align 4
  store i32 %__n, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = call i32 @llvm.ctlz.i32(i32 %2, i1 true)
  %4 = sext i32 %3 to i64
  %5 = sub i64 31, %4
  %6 = trunc i64 %5 to i32
  ret i32 %6
}

; Function Attrs: nounwind readnone
declare i32 @llvm.ctlz.i32(i32, i1) #1

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZSt4__lgj(i32 %__n) #0 {
  %1 = alloca i32, align 4
  store i32 %__n, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = call i32 @llvm.ctlz.i32(i32 %2, i1 true)
  %4 = sext i32 %3 to i64
  %5 = sub i64 31, %4
  %6 = trunc i64 %5 to i32
  ret i32 %6
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt4__lgl(i64 %__n) #0 {
  %1 = alloca i64, align 8
  store i64 %__n, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i64 @llvm.ctlz.i64(i64 %2, i1 true)
  %4 = trunc i64 %3 to i32
  %5 = sext i32 %4 to i64
  %6 = sub i64 63, %5
  ret i64 %6
}

; Function Attrs: nounwind readnone
declare i64 @llvm.ctlz.i64(i64, i1) #1

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt4__lgm(i64 %__n) #0 {
  %1 = alloca i64, align 8
  store i64 %__n, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i64 @llvm.ctlz.i64(i64 %2, i1 true)
  %4 = trunc i64 %3 to i32
  %5 = sext i32 %4 to i64
  %6 = sub i64 63, %5
  ret i64 %6
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt4__lgx(i64 %__n) #0 {
  %1 = alloca i64, align 8
  store i64 %__n, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i64 @llvm.ctlz.i64(i64 %2, i1 true)
  %4 = trunc i64 %3 to i32
  %5 = sext i32 %4 to i64
  %6 = sub i64 63, %5
  ret i64 %6
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt4__lgy(i64 %__n) #0 {
  %1 = alloca i64, align 8
  store i64 %__n, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i64 @llvm.ctlz.i64(i64 %2, i1 true)
  %4 = trunc i64 %3 to i32
  %5 = sext i32 %4 to i64
  %6 = sub i64 63, %5
  ret i64 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt9exceptionC2Ev(%"class.std::exception"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::exception"*, align 8
  store %"class.std::exception"* %this, %"class.std::exception"** %1, align 8
  %2 = load %"class.std::exception"** %1
  %3 = bitcast %"class.std::exception"* %2 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ([5 x i8*]* @_ZTVSt9exception, i64 0, i64 2) to i32 (...)**), i32 (...)*** %3
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt13bad_exceptionC2Ev(%"class.std::bad_exception"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::bad_exception"*, align 8
  store %"class.std::bad_exception"* %this, %"class.std::bad_exception"** %1, align 8
  %2 = load %"class.std::bad_exception"** %1
  %3 = bitcast %"class.std::bad_exception"* %2 to %"class.std::exception"*
  call void @_ZNSt9exceptionC2Ev(%"class.std::exception"* %3) #8
  %4 = bitcast %"class.std::bad_exception"* %2 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ([5 x i8*]* @_ZTVSt13bad_exception, i64 0, i64 2) to i32 (...)**), i32 (...)*** %4
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZNSt15__exception_ptr4swapERNS_13exception_ptrES1_(%"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %__lhs, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %__rhs) #0 {
  %1 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  %2 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  store %"class.std::__exception_ptr::exception_ptr"* %__lhs, %"class.std::__exception_ptr::exception_ptr"** %1, align 8
  store %"class.std::__exception_ptr::exception_ptr"* %__rhs, %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  %3 = load %"class.std::__exception_ptr::exception_ptr"** %1, align 8
  %4 = load %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  call void @_ZNSt15__exception_ptr13exception_ptr4swapERS0_(%"class.std::__exception_ptr::exception_ptr"* %3, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %4) #8
  ret void
}

; Function Attrs: nounwind
declare void @_ZNSt15__exception_ptr13exception_ptr4swapERS0_(%"class.std::__exception_ptr::exception_ptr"*, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8)) #3

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt15__exception_ptr13exception_ptrC2EDn(%"class.std::__exception_ptr::exception_ptr"* %this, i8*) unnamed_addr #2 align 2 {
  %2 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  %3 = alloca i8*, align 8
  store %"class.std::__exception_ptr::exception_ptr"* %this, %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  store i8* %0, i8** %3, align 8
  %4 = load %"class.std::__exception_ptr::exception_ptr"** %2
  %5 = getelementptr inbounds %"class.std::__exception_ptr::exception_ptr"* %4, i32 0, i32 0
  store i8* null, i8** %5, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) %"class.std::__exception_ptr::exception_ptr"* @_ZNSt15__exception_ptr13exception_ptraSEOS0_(%"class.std::__exception_ptr::exception_ptr"* %this, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %__o) #2 align 2 {
  %1 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  %2 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  %3 = alloca %"class.std::__exception_ptr::exception_ptr", align 8
  store %"class.std::__exception_ptr::exception_ptr"* %this, %"class.std::__exception_ptr::exception_ptr"** %1, align 8
  store %"class.std::__exception_ptr::exception_ptr"* %__o, %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  %4 = load %"class.std::__exception_ptr::exception_ptr"** %1
  %5 = load %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  call void @_ZNSt15__exception_ptr13exception_ptrC2EOS0_(%"class.std::__exception_ptr::exception_ptr"* %3, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %5) #8
  call void @_ZNSt15__exception_ptr13exception_ptr4swapERS0_(%"class.std::__exception_ptr::exception_ptr"* %3, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %4) #8
  call void @_ZNSt15__exception_ptr13exception_ptrD1Ev(%"class.std::__exception_ptr::exception_ptr"* %3) #8
  ret %"class.std::__exception_ptr::exception_ptr"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt15__exception_ptr13exception_ptrC2EOS0_(%"class.std::__exception_ptr::exception_ptr"* %this, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %__o) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  %2 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  store %"class.std::__exception_ptr::exception_ptr"* %this, %"class.std::__exception_ptr::exception_ptr"** %1, align 8
  store %"class.std::__exception_ptr::exception_ptr"* %__o, %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  %3 = load %"class.std::__exception_ptr::exception_ptr"** %1
  %4 = getelementptr inbounds %"class.std::__exception_ptr::exception_ptr"* %3, i32 0, i32 0
  %5 = load %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  %6 = getelementptr inbounds %"class.std::__exception_ptr::exception_ptr"* %5, i32 0, i32 0
  %7 = load i8** %6, align 8
  store i8* %7, i8** %4, align 8
  %8 = load %"class.std::__exception_ptr::exception_ptr"** %2, align 8
  %9 = getelementptr inbounds %"class.std::__exception_ptr::exception_ptr"* %8, i32 0, i32 0
  store i8* null, i8** %9, align 8
  ret void
}

; Function Attrs: nounwind
declare void @_ZNSt15__exception_ptr13exception_ptrD1Ev(%"class.std::__exception_ptr::exception_ptr"*) #3

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt15__exception_ptr13exception_ptrcvbEv(%"class.std::__exception_ptr::exception_ptr"* %this) #2 align 2 {
  %1 = alloca %"class.std::__exception_ptr::exception_ptr"*, align 8
  store %"class.std::__exception_ptr::exception_ptr"* %this, %"class.std::__exception_ptr::exception_ptr"** %1, align 8
  %2 = load %"class.std::__exception_ptr::exception_ptr"** %1
  %3 = getelementptr inbounds %"class.std::__exception_ptr::exception_ptr"* %2, i32 0, i32 0
  %4 = load i8** %3, align 8
  %5 = icmp ne i8* %4, null
  ret i1 %5
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt17rethrow_if_nestedRKSt16nested_exception(%"class.std::nested_exception"* dereferenceable(16) %__ex) #4 {
  %1 = alloca %"class.std::nested_exception"*, align 8
  store %"class.std::nested_exception"* %__ex, %"class.std::nested_exception"** %1, align 8
  %2 = load %"class.std::nested_exception"** %1, align 8
  call void @_ZNKSt16nested_exception14rethrow_nestedEv(%"class.std::nested_exception"* %2) #17
  unreachable
                                                  ; No predecessors!
  ret void
}

; Function Attrs: noreturn uwtable
define linkonce_odr void @_ZNKSt16nested_exception14rethrow_nestedEv(%"class.std::nested_exception"* %this) #5 align 2 {
  %1 = alloca %"class.std::nested_exception"*, align 8
  %2 = alloca %"class.std::__exception_ptr::exception_ptr", align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"class.std::nested_exception"* %this, %"class.std::nested_exception"** %1, align 8
  %5 = load %"class.std::nested_exception"** %1
  %6 = getelementptr inbounds %"class.std::nested_exception"* %5, i32 0, i32 1
  call void @_ZNSt15__exception_ptr13exception_ptrC1ERKS0_(%"class.std::__exception_ptr::exception_ptr"* %2, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %6) #8
  invoke void @_ZSt17rethrow_exceptionNSt15__exception_ptr13exception_ptrE(%"class.std::__exception_ptr::exception_ptr"* %2) #17
          to label %7 unwind label %8

; <label>:7                                       ; preds = %0
  unreachable

; <label>:8                                       ; preds = %0
  %9 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %10 = extractvalue { i8*, i32 } %9, 0
  store i8* %10, i8** %3
  %11 = extractvalue { i8*, i32 } %9, 1
  store i32 %11, i32* %4
  call void @_ZNSt15__exception_ptr13exception_ptrD1Ev(%"class.std::__exception_ptr::exception_ptr"* %2) #8
  br label %13
                                                  ; No predecessors!
  ret void

; <label>:13                                      ; preds = %8
  %14 = load i8** %3
  %15 = load i32* %4
  %16 = insertvalue { i8*, i32 } undef, i8* %14, 0
  %17 = insertvalue { i8*, i32 } %16, i32 %15, 1
  resume { i8*, i32 } %17
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt16nested_exceptionC2Ev(%"class.std::nested_exception"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::nested_exception"*, align 8
  store %"class.std::nested_exception"* %this, %"class.std::nested_exception"** %1, align 8
  %2 = load %"class.std::nested_exception"** %1
  %3 = bitcast %"class.std::nested_exception"* %2 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ([4 x i8*]* @_ZTVSt16nested_exception, i64 0, i64 2) to i32 (...)**), i32 (...)*** %3
  %4 = getelementptr inbounds %"class.std::nested_exception"* %2, i32 0, i32 1
  call void @_ZSt17current_exceptionv(%"class.std::__exception_ptr::exception_ptr"* sret %4) #8
  ret void
}

; Function Attrs: nounwind
declare void @_ZSt17current_exceptionv(%"class.std::__exception_ptr::exception_ptr"* sret) #3

; Function Attrs: noreturn
declare void @_ZSt17rethrow_exceptionNSt15__exception_ptr13exception_ptrE(%"class.std::__exception_ptr::exception_ptr"*) #6

; Function Attrs: nounwind
declare void @_ZNSt15__exception_ptr13exception_ptrC1ERKS0_(%"class.std::__exception_ptr::exception_ptr"*, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8)) #3

declare i32 @__gxx_personality_v0(...)

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNKSt16nested_exception10nested_ptrEv(%"class.std::__exception_ptr::exception_ptr"* noalias sret %agg.result, %"class.std::nested_exception"* %this) #2 align 2 {
  %1 = alloca %"class.std::nested_exception"*, align 8
  store %"class.std::nested_exception"* %this, %"class.std::nested_exception"** %1, align 8
  %2 = load %"class.std::nested_exception"** %1
  %3 = getelementptr inbounds %"class.std::nested_exception"* %2, i32 0, i32 1
  call void @_ZNSt15__exception_ptr13exception_ptrC1ERKS0_(%"class.std::__exception_ptr::exception_ptr"* %agg.result, %"class.std::__exception_ptr::exception_ptr"* dereferenceable(8) %3) #8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZnwmPv(i64, i8* %__p) #0 {
  %2 = alloca i64, align 8
  %3 = alloca i8*, align 8
  store i64 %0, i64* %2, align 8
  store i8* %__p, i8** %3, align 8
  %4 = load i8** %3, align 8
  ret i8* %4
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZnamPv(i64, i8* %__p) #0 {
  %2 = alloca i64, align 8
  %3 = alloca i8*, align 8
  store i64 %0, i64* %2, align 8
  store i8* %__p, i8** %3, align 8
  %4 = load i8** %3, align 8
  ret i8* %4
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZdlPvS_(i8*, i8*) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  store i8* %0, i8** %3, align 8
  store i8* %1, i8** %4, align 8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZdaPvS_(i8*, i8*) #0 {
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  store i8* %0, i8** %3, align 8
  store i8* %1, i8** %4, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt9bad_allocC2Ev(%"class.std::bad_alloc"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::bad_alloc"*, align 8
  store %"class.std::bad_alloc"* %this, %"class.std::bad_alloc"** %1, align 8
  %2 = load %"class.std::bad_alloc"** %1
  %3 = bitcast %"class.std::bad_alloc"* %2 to %"class.std::exception"*
  call void @_ZNSt9exceptionC2Ev(%"class.std::exception"* %3) #8
  %4 = bitcast %"class.std::bad_alloc"* %2 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ([5 x i8*]* @_ZTVSt9bad_alloc, i64 0, i64 2) to i32 (...)**), i32 (...)*** %4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt20bad_array_new_lengthC2Ev(%"class.std::bad_array_new_length"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::bad_array_new_length"*, align 8
  store %"class.std::bad_array_new_length"* %this, %"class.std::bad_array_new_length"** %1, align 8
  %2 = load %"class.std::bad_array_new_length"** %1
  %3 = bitcast %"class.std::bad_array_new_length"* %2 to %"class.std::bad_alloc"*
  call void @_ZNSt9bad_allocC2Ev(%"class.std::bad_alloc"* %3) #8
  %4 = bitcast %"class.std::bad_array_new_length"* %2 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ([5 x i8*]* @_ZTVSt20bad_array_new_length, i64 0, i64 2) to i32 (...)**), i32 (...)*** %4
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt4swapSt14_Bit_referenceS_(i64* %__x.coerce0, i64 %__x.coerce1, i64* %__y.coerce0, i64 %__y.coerce1) #0 {
  %__x = alloca %"struct.std::_Bit_reference", align 8
  %__y = alloca %"struct.std::_Bit_reference", align 8
  %__tmp = alloca i8, align 1
  %1 = bitcast %"struct.std::_Bit_reference"* %__x to { i64*, i64 }*
  %2 = getelementptr { i64*, i64 }* %1, i32 0, i32 0
  store i64* %__x.coerce0, i64** %2
  %3 = getelementptr { i64*, i64 }* %1, i32 0, i32 1
  store i64 %__x.coerce1, i64* %3
  %4 = bitcast %"struct.std::_Bit_reference"* %__y to { i64*, i64 }*
  %5 = getelementptr { i64*, i64 }* %4, i32 0, i32 0
  store i64* %__y.coerce0, i64** %5
  %6 = getelementptr { i64*, i64 }* %4, i32 0, i32 1
  store i64 %__y.coerce1, i64* %6
  %7 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %__x) #8
  %8 = zext i1 %7 to i8
  store i8 %8, i8* %__tmp, align 1
  %9 = call dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSERKS_(%"struct.std::_Bit_reference"* %__x, %"struct.std::_Bit_reference"* dereferenceable(16) %__y) #8
  %10 = load i8* %__tmp, align 1
  %11 = trunc i8 %10 to i1
  %12 = call dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSEb(%"struct.std::_Bit_reference"* %__y, i1 zeroext %11) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  %2 = load %"struct.std::_Bit_reference"** %1
  %3 = getelementptr inbounds %"struct.std::_Bit_reference"* %2, i32 0, i32 0
  %4 = load i64** %3, align 8
  %5 = load i64* %4, align 8
  %6 = getelementptr inbounds %"struct.std::_Bit_reference"* %2, i32 0, i32 1
  %7 = load i64* %6, align 8
  %8 = and i64 %5, %7
  %9 = icmp ne i64 %8, 0
  %10 = xor i1 %9, true
  %11 = xor i1 %10, true
  ret i1 %11
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSERKS_(%"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"* dereferenceable(16) %__x) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  %2 = alloca %"struct.std::_Bit_reference"*, align 8
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  store %"struct.std::_Bit_reference"* %__x, %"struct.std::_Bit_reference"** %2, align 8
  %3 = load %"struct.std::_Bit_reference"** %1
  %4 = load %"struct.std::_Bit_reference"** %2, align 8
  %5 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %4) #8
  %6 = call dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSEb(%"struct.std::_Bit_reference"* %3, i1 zeroext %5) #8
  ret %"struct.std::_Bit_reference"* %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSEb(%"struct.std::_Bit_reference"* %this, i1 zeroext %__x) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  %2 = alloca i8, align 1
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  %3 = zext i1 %__x to i8
  store i8 %3, i8* %2, align 1
  %4 = load %"struct.std::_Bit_reference"** %1
  %5 = load i8* %2, align 1
  %6 = trunc i8 %5 to i1
  br i1 %6, label %7, label %14

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %"struct.std::_Bit_reference"* %4, i32 0, i32 1
  %9 = load i64* %8, align 8
  %10 = getelementptr inbounds %"struct.std::_Bit_reference"* %4, i32 0, i32 0
  %11 = load i64** %10, align 8
  %12 = load i64* %11, align 8
  %13 = or i64 %12, %9
  store i64 %13, i64* %11, align 8
  br label %22

; <label>:14                                      ; preds = %0
  %15 = getelementptr inbounds %"struct.std::_Bit_reference"* %4, i32 0, i32 1
  %16 = load i64* %15, align 8
  %17 = xor i64 %16, -1
  %18 = getelementptr inbounds %"struct.std::_Bit_reference"* %4, i32 0, i32 0
  %19 = load i64** %18, align 8
  %20 = load i64* %19, align 8
  %21 = and i64 %20, %17
  store i64 %21, i64* %19, align 8
  br label %22

; <label>:22                                      ; preds = %14, %7
  ret %"struct.std::_Bit_reference"* %4
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt4swapSt14_Bit_referenceRb(i64* %__x.coerce0, i64 %__x.coerce1, i8* dereferenceable(1) %__y) #0 {
  %__x = alloca %"struct.std::_Bit_reference", align 8
  %1 = alloca i8*, align 8
  %__tmp = alloca i8, align 1
  %2 = bitcast %"struct.std::_Bit_reference"* %__x to { i64*, i64 }*
  %3 = getelementptr { i64*, i64 }* %2, i32 0, i32 0
  store i64* %__x.coerce0, i64** %3
  %4 = getelementptr { i64*, i64 }* %2, i32 0, i32 1
  store i64 %__x.coerce1, i64* %4
  store i8* %__y, i8** %1, align 8
  %5 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %__x) #8
  %6 = zext i1 %5 to i8
  store i8 %6, i8* %__tmp, align 1
  %7 = load i8** %1, align 8
  %8 = load i8* %7, align 1
  %9 = trunc i8 %8 to i1
  %10 = call dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSEb(%"struct.std::_Bit_reference"* %__x, i1 zeroext %9) #8
  %11 = load i8* %__tmp, align 1
  %12 = trunc i8 %11 to i1
  %13 = load i8** %1, align 8
  %14 = zext i1 %12 to i8
  store i8 %14, i8* %13, align 1
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt4swapRbSt14_Bit_reference(i8* dereferenceable(1) %__x, i64* %__y.coerce0, i64 %__y.coerce1) #0 {
  %__y = alloca %"struct.std::_Bit_reference", align 8
  %1 = alloca i8*, align 8
  %__tmp = alloca i8, align 1
  %2 = bitcast %"struct.std::_Bit_reference"* %__y to { i64*, i64 }*
  %3 = getelementptr { i64*, i64 }* %2, i32 0, i32 0
  store i64* %__y.coerce0, i64** %3
  %4 = getelementptr { i64*, i64 }* %2, i32 0, i32 1
  store i64 %__y.coerce1, i64* %4
  store i8* %__x, i8** %1, align 8
  %5 = load i8** %1, align 8
  %6 = load i8* %5, align 1
  %7 = trunc i8 %6 to i1
  %8 = zext i1 %7 to i8
  store i8 %8, i8* %__tmp, align 1
  %9 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %__y) #8
  %10 = load i8** %1, align 8
  %11 = zext i1 %9 to i8
  store i8 %11, i8* %10, align 1
  %12 = load i8* %__tmp, align 1
  %13 = trunc i8 %12 to i1
  %14 = call dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSEb(%"struct.std::_Bit_reference"* %__y, i1 zeroext %13) #8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZStmiRKSt18_Bit_iterator_baseS1_(%"struct.std::_Bit_iterator_base"* dereferenceable(16) %__x, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %__y) #0 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %__x, %"struct.std::_Bit_iterator_base"** %1, align 8
  store %"struct.std::_Bit_iterator_base"* %__y, %"struct.std::_Bit_iterator_base"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1, align 8
  %4 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 0
  %5 = load i64** %4, align 8
  %6 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %7 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %6, i32 0, i32 0
  %8 = load i64** %7, align 8
  %9 = ptrtoint i64* %5 to i64
  %10 = ptrtoint i64* %8 to i64
  %11 = sub i64 %9, %10
  %12 = sdiv exact i64 %11, 8
  %13 = mul nsw i64 64, %12
  %14 = load %"struct.std::_Bit_iterator_base"** %1, align 8
  %15 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %14, i32 0, i32 1
  %16 = load i32* %15, align 4
  %17 = zext i32 %16 to i64
  %18 = add nsw i64 %13, %17
  %19 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %20 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %19, i32 0, i32 1
  %21 = load i32* %20, align 4
  %22 = zext i32 %21 to i64
  %23 = sub nsw i64 %18, %22
  ret i64 %23
}

; Function Attrs: inlinehint uwtable
define linkonce_odr { i64*, i32 } @_ZStpllRKSt13_Bit_iterator(i64 %__n, %"struct.std::_Bit_iterator"* dereferenceable(16) %__x) #4 {
  %1 = alloca %"struct.std::_Bit_iterator", align 8
  %2 = alloca i64, align 8
  %3 = alloca %"struct.std::_Bit_iterator"*, align 8
  store i64 %__n, i64* %2, align 8
  store %"struct.std::_Bit_iterator"* %__x, %"struct.std::_Bit_iterator"** %3, align 8
  %4 = load %"struct.std::_Bit_iterator"** %3, align 8
  %5 = load i64* %2, align 8
  %6 = call { i64*, i32 } @_ZNKSt13_Bit_iteratorplEl(%"struct.std::_Bit_iterator"* %4, i64 %5)
  %7 = bitcast %"struct.std::_Bit_iterator"* %1 to { i64*, i32 }*
  %8 = getelementptr { i64*, i32 }* %7, i32 0, i32 0
  %9 = extractvalue { i64*, i32 } %6, 0
  store i64* %9, i64** %8, align 1
  %10 = getelementptr { i64*, i32 }* %7, i32 0, i32 1
  %11 = extractvalue { i64*, i32 } %6, 1
  store i32 %11, i32* %10, align 1
  %12 = bitcast %"struct.std::_Bit_iterator"* %1 to { i64*, i32 }*
  %13 = load { i64*, i32 }* %12, align 1
  ret { i64*, i32 } %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNKSt13_Bit_iteratorplEl(%"struct.std::_Bit_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator", align 8
  %2 = alloca %"struct.std::_Bit_iterator"*, align 8
  %3 = alloca i64, align 8
  %__tmp = alloca %"struct.std::_Bit_iterator", align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %2, align 8
  store i64 %__i, i64* %3, align 8
  %4 = load %"struct.std::_Bit_iterator"** %2
  %5 = bitcast %"struct.std::_Bit_iterator"* %__tmp to i8*
  %6 = bitcast %"struct.std::_Bit_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %5, i8* %6, i64 16, i32 8, i1 false)
  %7 = load i64* %3, align 8
  %8 = call dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratorpLEl(%"struct.std::_Bit_iterator"* %__tmp, i64 %7)
  %9 = bitcast %"struct.std::_Bit_iterator"* %1 to i8*
  %10 = bitcast %"struct.std::_Bit_iterator"* %8 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %9, i8* %10, i64 16, i32 8, i1 false)
  %11 = bitcast %"struct.std::_Bit_iterator"* %1 to { i64*, i32 }*
  %12 = load { i64*, i32 }* %11, align 1
  ret { i64*, i32 } %12
}

; Function Attrs: inlinehint uwtable
define linkonce_odr { i64*, i32 } @_ZStpllRKSt19_Bit_const_iterator(i64 %__n, %"struct.std::_Bit_const_iterator"* dereferenceable(16) %__x) #4 {
  %1 = alloca %"struct.std::_Bit_const_iterator", align 8
  %2 = alloca i64, align 8
  %3 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  store i64 %__n, i64* %2, align 8
  store %"struct.std::_Bit_const_iterator"* %__x, %"struct.std::_Bit_const_iterator"** %3, align 8
  %4 = load %"struct.std::_Bit_const_iterator"** %3, align 8
  %5 = load i64* %2, align 8
  %6 = call { i64*, i32 } @_ZNKSt19_Bit_const_iteratorplEl(%"struct.std::_Bit_const_iterator"* %4, i64 %5)
  %7 = bitcast %"struct.std::_Bit_const_iterator"* %1 to { i64*, i32 }*
  %8 = getelementptr { i64*, i32 }* %7, i32 0, i32 0
  %9 = extractvalue { i64*, i32 } %6, 0
  store i64* %9, i64** %8, align 1
  %10 = getelementptr { i64*, i32 }* %7, i32 0, i32 1
  %11 = extractvalue { i64*, i32 } %6, 1
  store i32 %11, i32* %10, align 1
  %12 = bitcast %"struct.std::_Bit_const_iterator"* %1 to { i64*, i32 }*
  %13 = load { i64*, i32 }* %12, align 1
  ret { i64*, i32 } %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNKSt19_Bit_const_iteratorplEl(%"struct.std::_Bit_const_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator", align 8
  %2 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %3 = alloca i64, align 8
  %__tmp = alloca %"struct.std::_Bit_const_iterator", align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %2, align 8
  store i64 %__i, i64* %3, align 8
  %4 = load %"struct.std::_Bit_const_iterator"** %2
  %5 = bitcast %"struct.std::_Bit_const_iterator"* %__tmp to i8*
  %6 = bitcast %"struct.std::_Bit_const_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %5, i8* %6, i64 16, i32 8, i1 false)
  %7 = load i64* %3, align 8
  %8 = call dereferenceable(16) %"struct.std::_Bit_const_iterator"* @_ZNSt19_Bit_const_iteratorpLEl(%"struct.std::_Bit_const_iterator"* %__tmp, i64 %7)
  %9 = bitcast %"struct.std::_Bit_const_iterator"* %1 to i8*
  %10 = bitcast %"struct.std::_Bit_const_iterator"* %8 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %9, i8* %10, i64 16, i32 8, i1 false)
  %11 = bitcast %"struct.std::_Bit_const_iterator"* %1 to { i64*, i32 }*
  %12 = load { i64*, i32 }* %11, align 1
  ret { i64*, i32 } %12
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt14__fill_bvectorSt13_Bit_iteratorS_b(i64* %__first.coerce0, i32 %__first.coerce1, i64* %__last.coerce0, i32 %__last.coerce1, i1 zeroext %__x) #4 {
  %__first = alloca %"struct.std::_Bit_iterator", align 8
  %__last = alloca %"struct.std::_Bit_iterator", align 8
  %1 = alloca i8, align 1
  %2 = alloca %"struct.std::_Bit_reference", align 8
  %3 = bitcast %"struct.std::_Bit_iterator"* %__first to { i64*, i32 }*
  %4 = getelementptr { i64*, i32 }* %3, i32 0, i32 0
  store i64* %__first.coerce0, i64** %4
  %5 = getelementptr { i64*, i32 }* %3, i32 0, i32 1
  store i32 %__first.coerce1, i32* %5
  %6 = bitcast %"struct.std::_Bit_iterator"* %__last to { i64*, i32 }*
  %7 = getelementptr { i64*, i32 }* %6, i32 0, i32 0
  store i64* %__last.coerce0, i64** %7
  %8 = getelementptr { i64*, i32 }* %6, i32 0, i32 1
  store i32 %__last.coerce1, i32* %8
  %9 = zext i1 %__x to i8
  store i8 %9, i8* %1, align 1
  br label %10

; <label>:10                                      ; preds = %24, %0
  %11 = bitcast %"struct.std::_Bit_iterator"* %__first to %"struct.std::_Bit_iterator_base"*
  %12 = bitcast %"struct.std::_Bit_iterator"* %__last to %"struct.std::_Bit_iterator_base"*
  %13 = call zeroext i1 @_ZNKSt18_Bit_iterator_baseneERKS_(%"struct.std::_Bit_iterator_base"* %11, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %12)
  br i1 %13, label %14, label %26

; <label>:14                                      ; preds = %10
  %15 = call { i64*, i64 } @_ZNKSt13_Bit_iteratordeEv(%"struct.std::_Bit_iterator"* %__first)
  %16 = bitcast %"struct.std::_Bit_reference"* %2 to { i64*, i64 }*
  %17 = getelementptr { i64*, i64 }* %16, i32 0, i32 0
  %18 = extractvalue { i64*, i64 } %15, 0
  store i64* %18, i64** %17, align 1
  %19 = getelementptr { i64*, i64 }* %16, i32 0, i32 1
  %20 = extractvalue { i64*, i64 } %15, 1
  store i64 %20, i64* %19, align 1
  %21 = load i8* %1, align 1
  %22 = trunc i8 %21 to i1
  %23 = call dereferenceable(16) %"struct.std::_Bit_reference"* @_ZNSt14_Bit_referenceaSEb(%"struct.std::_Bit_reference"* %2, i1 zeroext %22) #8
  br label %24

; <label>:24                                      ; preds = %14
  %25 = call dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratorppEv(%"struct.std::_Bit_iterator"* %__first)
  br label %10

; <label>:26                                      ; preds = %10
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt18_Bit_iterator_baseneERKS_(%"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store %"struct.std::_Bit_iterator_base"* %__i, %"struct.std::_Bit_iterator_base"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1
  %4 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %5 = call zeroext i1 @_ZNKSt18_Bit_iterator_baseeqERKS_(%"struct.std::_Bit_iterator_base"* %3, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %4)
  %6 = xor i1 %5, true
  ret i1 %6
}

; Function Attrs: uwtable
define linkonce_odr { i64*, i64 } @_ZNKSt13_Bit_iteratordeEv(%"struct.std::_Bit_iterator"* %this) #7 align 2 {
  %1 = alloca %"struct.std::_Bit_reference", align 8
  %2 = alloca %"struct.std::_Bit_iterator"*, align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator"** %2
  %4 = bitcast %"struct.std::_Bit_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %5 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %4, i32 0, i32 0
  %6 = load i64** %5, align 8
  %7 = bitcast %"struct.std::_Bit_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %8 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %7, i32 0, i32 1
  %9 = load i32* %8, align 4
  %10 = zext i32 %9 to i64
  %11 = shl i64 1, %10
  call void @_ZNSt14_Bit_referenceC2EPmm(%"struct.std::_Bit_reference"* %1, i64* %6, i64 %11)
  %12 = bitcast %"struct.std::_Bit_reference"* %1 to { i64*, i64 }*
  %13 = load { i64*, i64 }* %12, align 1
  ret { i64*, i64 } %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratorppEv(%"struct.std::_Bit_iterator"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator"*, align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %1, align 8
  %2 = load %"struct.std::_Bit_iterator"** %1
  %3 = bitcast %"struct.std::_Bit_iterator"* %2 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base10_M_bump_upEv(%"struct.std::_Bit_iterator_base"* %3)
  ret %"struct.std::_Bit_iterator"* %2
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt4fillSt13_Bit_iteratorS_RKb(i64* %__first.coerce0, i32 %__first.coerce1, i64* %__last.coerce0, i32 %__last.coerce1, i8* dereferenceable(1) %__x) #4 {
  %__first = alloca %"struct.std::_Bit_iterator", align 8
  %__last = alloca %"struct.std::_Bit_iterator", align 8
  %1 = alloca i8*, align 8
  %2 = alloca i32, align 4
  %3 = alloca %"struct.std::_Bit_iterator", align 8
  %4 = alloca %"struct.std::_Bit_iterator", align 8
  %5 = alloca %"struct.std::_Bit_iterator", align 8
  %6 = alloca %"struct.std::_Bit_iterator", align 8
  %7 = alloca %"struct.std::_Bit_iterator", align 8
  %8 = alloca %"struct.std::_Bit_iterator", align 8
  %9 = bitcast %"struct.std::_Bit_iterator"* %__first to { i64*, i32 }*
  %10 = getelementptr { i64*, i32 }* %9, i32 0, i32 0
  store i64* %__first.coerce0, i64** %10
  %11 = getelementptr { i64*, i32 }* %9, i32 0, i32 1
  store i32 %__first.coerce1, i32* %11
  %12 = bitcast %"struct.std::_Bit_iterator"* %__last to { i64*, i32 }*
  %13 = getelementptr { i64*, i32 }* %12, i32 0, i32 0
  store i64* %__last.coerce0, i64** %13
  %14 = getelementptr { i64*, i32 }* %12, i32 0, i32 1
  store i32 %__last.coerce1, i32* %14
  store i8* %__x, i8** %1, align 8
  %15 = bitcast %"struct.std::_Bit_iterator"* %__first to %"struct.std::_Bit_iterator_base"*
  %16 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %15, i32 0, i32 0
  %17 = load i64** %16, align 8
  %18 = bitcast %"struct.std::_Bit_iterator"* %__last to %"struct.std::_Bit_iterator_base"*
  %19 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %18, i32 0, i32 0
  %20 = load i64** %19, align 8
  %21 = icmp ne i64* %17, %20
  br i1 %21, label %22, label %71

; <label>:22                                      ; preds = %0
  %23 = bitcast %"struct.std::_Bit_iterator"* %__first to %"struct.std::_Bit_iterator_base"*
  %24 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %23, i32 0, i32 0
  %25 = load i64** %24, align 8
  %26 = getelementptr inbounds i64* %25, i64 1
  %27 = bitcast %"struct.std::_Bit_iterator"* %__last to %"struct.std::_Bit_iterator_base"*
  %28 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %27, i32 0, i32 0
  %29 = load i64** %28, align 8
  %30 = load i8** %1, align 8
  %31 = load i8* %30, align 1
  %32 = trunc i8 %31 to i1
  %33 = select i1 %32, i32 -1, i32 0
  store i32 %33, i32* %2
  call void @_ZSt4fillIPmiEvT_S1_RKT0_(i64* %26, i64* %29, i32* dereferenceable(4) %2)
  %34 = bitcast %"struct.std::_Bit_iterator"* %3 to i8*
  %35 = bitcast %"struct.std::_Bit_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %34, i8* %35, i64 16, i32 8, i1 false)
  %36 = bitcast %"struct.std::_Bit_iterator"* %__first to %"struct.std::_Bit_iterator_base"*
  %37 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %36, i32 0, i32 0
  %38 = load i64** %37, align 8
  %39 = getelementptr inbounds i64* %38, i64 1
  call void @_ZNSt13_Bit_iteratorC2EPmj(%"struct.std::_Bit_iterator"* %4, i64* %39, i32 0)
  %40 = load i8** %1, align 8
  %41 = load i8* %40, align 1
  %42 = trunc i8 %41 to i1
  %43 = bitcast %"struct.std::_Bit_iterator"* %3 to { i64*, i32 }*
  %44 = getelementptr { i64*, i32 }* %43, i32 0, i32 0
  %45 = load i64** %44, align 1
  %46 = getelementptr { i64*, i32 }* %43, i32 0, i32 1
  %47 = load i32* %46, align 1
  %48 = bitcast %"struct.std::_Bit_iterator"* %4 to { i64*, i32 }*
  %49 = getelementptr { i64*, i32 }* %48, i32 0, i32 0
  %50 = load i64** %49, align 1
  %51 = getelementptr { i64*, i32 }* %48, i32 0, i32 1
  %52 = load i32* %51, align 1
  call void @_ZSt14__fill_bvectorSt13_Bit_iteratorS_b(i64* %45, i32 %47, i64* %50, i32 %52, i1 zeroext %42)
  %53 = bitcast %"struct.std::_Bit_iterator"* %__last to %"struct.std::_Bit_iterator_base"*
  %54 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %53, i32 0, i32 0
  %55 = load i64** %54, align 8
  call void @_ZNSt13_Bit_iteratorC2EPmj(%"struct.std::_Bit_iterator"* %5, i64* %55, i32 0)
  %56 = bitcast %"struct.std::_Bit_iterator"* %6 to i8*
  %57 = bitcast %"struct.std::_Bit_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %56, i8* %57, i64 16, i32 8, i1 false)
  %58 = load i8** %1, align 8
  %59 = load i8* %58, align 1
  %60 = trunc i8 %59 to i1
  %61 = bitcast %"struct.std::_Bit_iterator"* %5 to { i64*, i32 }*
  %62 = getelementptr { i64*, i32 }* %61, i32 0, i32 0
  %63 = load i64** %62, align 1
  %64 = getelementptr { i64*, i32 }* %61, i32 0, i32 1
  %65 = load i32* %64, align 1
  %66 = bitcast %"struct.std::_Bit_iterator"* %6 to { i64*, i32 }*
  %67 = getelementptr { i64*, i32 }* %66, i32 0, i32 0
  %68 = load i64** %67, align 1
  %69 = getelementptr { i64*, i32 }* %66, i32 0, i32 1
  %70 = load i32* %69, align 1
  call void @_ZSt14__fill_bvectorSt13_Bit_iteratorS_b(i64* %63, i32 %65, i64* %68, i32 %70, i1 zeroext %60)
  br label %89

; <label>:71                                      ; preds = %0
  %72 = bitcast %"struct.std::_Bit_iterator"* %7 to i8*
  %73 = bitcast %"struct.std::_Bit_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %72, i8* %73, i64 16, i32 8, i1 false)
  %74 = bitcast %"struct.std::_Bit_iterator"* %8 to i8*
  %75 = bitcast %"struct.std::_Bit_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %74, i8* %75, i64 16, i32 8, i1 false)
  %76 = load i8** %1, align 8
  %77 = load i8* %76, align 1
  %78 = trunc i8 %77 to i1
  %79 = bitcast %"struct.std::_Bit_iterator"* %7 to { i64*, i32 }*
  %80 = getelementptr { i64*, i32 }* %79, i32 0, i32 0
  %81 = load i64** %80, align 1
  %82 = getelementptr { i64*, i32 }* %79, i32 0, i32 1
  %83 = load i32* %82, align 1
  %84 = bitcast %"struct.std::_Bit_iterator"* %8 to { i64*, i32 }*
  %85 = getelementptr { i64*, i32 }* %84, i32 0, i32 0
  %86 = load i64** %85, align 1
  %87 = getelementptr { i64*, i32 }* %84, i32 0, i32 1
  %88 = load i32* %87, align 1
  call void @_ZSt14__fill_bvectorSt13_Bit_iteratorS_b(i64* %81, i32 %83, i64* %86, i32 %88, i1 zeroext %78)
  br label %89

; <label>:89                                      ; preds = %71, %22
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt4fillIPmiEvT_S1_RKT0_(i64* %__first, i64* %__last, i32* dereferenceable(4) %__value) #0 {
  %1 = alloca i64*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32*, align 8
  store i64* %__first, i64** %1, align 8
  store i64* %__last, i64** %2, align 8
  store i32* %__value, i32** %3, align 8
  %4 = load i64** %1, align 8
  %5 = call i64* @_ZSt12__niter_baseIPmENSt11_Niter_baseIT_E13iterator_typeES2_(i64* %4)
  %6 = load i64** %2, align 8
  %7 = call i64* @_ZSt12__niter_baseIPmENSt11_Niter_baseIT_E13iterator_typeES2_(i64* %6)
  %8 = load i32** %3, align 8
  call void @_ZSt8__fill_aIPmiEN9__gnu_cxx11__enable_ifIXsr11__is_scalarIT0_EE7__valueEvE6__typeET_S6_RKS3_(i64* %5, i64* %7, i32* dereferenceable(4) %8)
  ret void
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #8

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt13_Bit_iteratorC2EPmj(%"struct.std::_Bit_iterator"* %this, i64* %__x, i32 %__y) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %1, align 8
  store i64* %__x, i64** %2, align 8
  store i32 %__y, i32* %3, align 4
  %4 = load %"struct.std::_Bit_iterator"** %1
  %5 = bitcast %"struct.std::_Bit_iterator"* %4 to %"struct.std::_Bit_iterator_base"*
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  call void @_ZNSt18_Bit_iterator_baseC2EPmj(%"struct.std::_Bit_iterator_base"* %5, i64* %6, i32 %7)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt14_Bit_referenceC2Ev(%"struct.std::_Bit_reference"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  %2 = load %"struct.std::_Bit_reference"** %1
  %3 = getelementptr inbounds %"struct.std::_Bit_reference"* %2, i32 0, i32 0
  store i64* null, i64** %3, align 8
  %4 = getelementptr inbounds %"struct.std::_Bit_reference"* %2, i32 0, i32 1
  store i64 0, i64* %4, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt14_Bit_referenceeqERKS_(%"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"* dereferenceable(16) %__x) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  %2 = alloca %"struct.std::_Bit_reference"*, align 8
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  store %"struct.std::_Bit_reference"* %__x, %"struct.std::_Bit_reference"** %2, align 8
  %3 = load %"struct.std::_Bit_reference"** %1
  %4 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %3) #8
  %5 = zext i1 %4 to i32
  %6 = load %"struct.std::_Bit_reference"** %2, align 8
  %7 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %6) #8
  %8 = zext i1 %7 to i32
  %9 = icmp eq i32 %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt14_Bit_referenceltERKS_(%"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"* dereferenceable(16) %__x) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  %2 = alloca %"struct.std::_Bit_reference"*, align 8
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  store %"struct.std::_Bit_reference"* %__x, %"struct.std::_Bit_reference"** %2, align 8
  %3 = load %"struct.std::_Bit_reference"** %1
  %4 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %3) #8
  br i1 %4, label %8, label %5

; <label>:5                                       ; preds = %0
  %6 = load %"struct.std::_Bit_reference"** %2, align 8
  %7 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %6) #8
  br label %8

; <label>:8                                       ; preds = %5, %0
  %9 = phi i1 [ false, %0 ], [ %7, %5 ]
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt14_Bit_reference4flipEv(%"struct.std::_Bit_reference"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  %2 = load %"struct.std::_Bit_reference"** %1
  %3 = getelementptr inbounds %"struct.std::_Bit_reference"* %2, i32 0, i32 1
  %4 = load i64* %3, align 8
  %5 = getelementptr inbounds %"struct.std::_Bit_reference"* %2, i32 0, i32 0
  %6 = load i64** %5, align 8
  %7 = load i64* %6, align 8
  %8 = xor i64 %7, %4
  store i64 %8, i64* %6, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt18_Bit_iterator_baseC2EPmj(%"struct.std::_Bit_iterator_base"* %this, i64* %__x, i32 %__y) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store i64* %__x, i64** %2, align 8
  store i32 %__y, i32* %3, align 4
  %4 = load %"struct.std::_Bit_iterator_base"** %1
  %5 = bitcast %"struct.std::_Bit_iterator_base"* %4 to %"struct.std::iterator"*
  %6 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %4, i32 0, i32 0
  %7 = load i64** %2, align 8
  store i64* %7, i64** %6, align 8
  %8 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %4, i32 0, i32 1
  %9 = load i32* %3, align 4
  store i32 %9, i32* %8, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt18_Bit_iterator_base10_M_bump_upEv(%"struct.std::_Bit_iterator_base"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  %2 = load %"struct.std::_Bit_iterator_base"** %1
  %3 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %2, i32 0, i32 1
  %4 = load i32* %3, align 4
  %5 = add i32 %4, 1
  store i32 %5, i32* %3, align 4
  %6 = icmp eq i32 %4, 63
  br i1 %6, label %7, label %12

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %2, i32 0, i32 1
  store i32 0, i32* %8, align 4
  %9 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %2, i32 0, i32 0
  %10 = load i64** %9, align 8
  %11 = getelementptr inbounds i64* %10, i32 1
  store i64* %11, i64** %9, align 8
  br label %12

; <label>:12                                      ; preds = %7, %0
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt18_Bit_iterator_base12_M_bump_downEv(%"struct.std::_Bit_iterator_base"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  %2 = load %"struct.std::_Bit_iterator_base"** %1
  %3 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %2, i32 0, i32 1
  %4 = load i32* %3, align 4
  %5 = add i32 %4, -1
  store i32 %5, i32* %3, align 4
  %6 = icmp eq i32 %4, 0
  br i1 %6, label %7, label %12

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %2, i32 0, i32 1
  store i32 63, i32* %8, align 4
  %9 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %2, i32 0, i32 0
  %10 = load i64** %9, align 8
  %11 = getelementptr inbounds i64* %10, i32 -1
  store i64* %11, i64** %9, align 8
  br label %12

; <label>:12                                      ; preds = %7, %0
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt18_Bit_iterator_base7_M_incrEl(%"struct.std::_Bit_iterator_base"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca i64, align 8
  %__n = alloca i64, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store i64 %__i, i64* %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1
  %4 = load i64* %2, align 8
  %5 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 1
  %6 = load i32* %5, align 4
  %7 = zext i32 %6 to i64
  %8 = add nsw i64 %4, %7
  store i64 %8, i64* %__n, align 8
  %9 = load i64* %__n, align 8
  %10 = sdiv i64 %9, 64
  %11 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 0
  %12 = load i64** %11, align 8
  %13 = getelementptr inbounds i64* %12, i64 %10
  store i64* %13, i64** %11, align 8
  %14 = load i64* %__n, align 8
  %15 = srem i64 %14, 64
  store i64 %15, i64* %__n, align 8
  %16 = load i64* %__n, align 8
  %17 = icmp slt i64 %16, 0
  br i1 %17, label %18, label %24

; <label>:18                                      ; preds = %0
  %19 = load i64* %__n, align 8
  %20 = add nsw i64 %19, 64
  store i64 %20, i64* %__n, align 8
  %21 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 0
  %22 = load i64** %21, align 8
  %23 = getelementptr inbounds i64* %22, i32 -1
  store i64* %23, i64** %21, align 8
  br label %24

; <label>:24                                      ; preds = %18, %0
  %25 = load i64* %__n, align 8
  %26 = trunc i64 %25 to i32
  %27 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 1
  store i32 %26, i32* %27, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt18_Bit_iterator_baseeqERKS_(%"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store %"struct.std::_Bit_iterator_base"* %__i, %"struct.std::_Bit_iterator_base"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1
  %4 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 0
  %5 = load i64** %4, align 8
  %6 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %7 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %6, i32 0, i32 0
  %8 = load i64** %7, align 8
  %9 = icmp eq i64* %5, %8
  br i1 %9, label %10, label %17

; <label>:10                                      ; preds = %0
  %11 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 1
  %12 = load i32* %11, align 4
  %13 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %14 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %13, i32 0, i32 1
  %15 = load i32* %14, align 4
  %16 = icmp eq i32 %12, %15
  br label %17

; <label>:17                                      ; preds = %10, %0
  %18 = phi i1 [ false, %0 ], [ %16, %10 ]
  ret i1 %18
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt18_Bit_iterator_baseltERKS_(%"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store %"struct.std::_Bit_iterator_base"* %__i, %"struct.std::_Bit_iterator_base"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1
  %4 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 0
  %5 = load i64** %4, align 8
  %6 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %7 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %6, i32 0, i32 0
  %8 = load i64** %7, align 8
  %9 = icmp ult i64* %5, %8
  br i1 %9, label %26, label %10

; <label>:10                                      ; preds = %0
  %11 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 0
  %12 = load i64** %11, align 8
  %13 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %14 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %13, i32 0, i32 0
  %15 = load i64** %14, align 8
  %16 = icmp eq i64* %12, %15
  br i1 %16, label %17, label %24

; <label>:17                                      ; preds = %10
  %18 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %3, i32 0, i32 1
  %19 = load i32* %18, align 4
  %20 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %21 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %20, i32 0, i32 1
  %22 = load i32* %21, align 4
  %23 = icmp ult i32 %19, %22
  br label %24

; <label>:24                                      ; preds = %17, %10
  %25 = phi i1 [ false, %10 ], [ %23, %17 ]
  br label %26

; <label>:26                                      ; preds = %24, %0
  %27 = phi i1 [ true, %0 ], [ %25, %24 ]
  ret i1 %27
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt18_Bit_iterator_basegtERKS_(%"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store %"struct.std::_Bit_iterator_base"* %__i, %"struct.std::_Bit_iterator_base"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1
  %4 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %5 = call zeroext i1 @_ZNKSt18_Bit_iterator_baseltERKS_(%"struct.std::_Bit_iterator_base"* %4, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %3)
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt18_Bit_iterator_baseleERKS_(%"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store %"struct.std::_Bit_iterator_base"* %__i, %"struct.std::_Bit_iterator_base"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1
  %4 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %5 = call zeroext i1 @_ZNKSt18_Bit_iterator_baseltERKS_(%"struct.std::_Bit_iterator_base"* %4, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %3)
  %6 = xor i1 %5, true
  ret i1 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt18_Bit_iterator_basegeERKS_(%"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator_base"*, align 8
  store %"struct.std::_Bit_iterator_base"* %this, %"struct.std::_Bit_iterator_base"** %1, align 8
  store %"struct.std::_Bit_iterator_base"* %__i, %"struct.std::_Bit_iterator_base"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator_base"** %1
  %4 = load %"struct.std::_Bit_iterator_base"** %2, align 8
  %5 = call zeroext i1 @_ZNKSt18_Bit_iterator_baseltERKS_(%"struct.std::_Bit_iterator_base"* %3, %"struct.std::_Bit_iterator_base"* dereferenceable(16) %4)
  %6 = xor i1 %5, true
  ret i1 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt13_Bit_iteratorC2Ev(%"struct.std::_Bit_iterator"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator"*, align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %1, align 8
  %2 = load %"struct.std::_Bit_iterator"** %1
  %3 = bitcast %"struct.std::_Bit_iterator"* %2 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_baseC2EPmj(%"struct.std::_Bit_iterator_base"* %3, i64* null, i32 0)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNKSt13_Bit_iterator13_M_const_castEv(%"struct.std::_Bit_iterator"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator", align 8
  %2 = alloca %"struct.std::_Bit_iterator"*, align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %2, align 8
  %3 = load %"struct.std::_Bit_iterator"** %2
  %4 = bitcast %"struct.std::_Bit_iterator"* %1 to i8*
  %5 = bitcast %"struct.std::_Bit_iterator"* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %4, i8* %5, i64 16, i32 8, i1 false)
  %6 = bitcast %"struct.std::_Bit_iterator"* %1 to { i64*, i32 }*
  %7 = load { i64*, i32 }* %6, align 1
  ret { i64*, i32 } %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt14_Bit_referenceC2EPmm(%"struct.std::_Bit_reference"* %this, i64* %__x, i64 %__y) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_reference"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i64, align 8
  store %"struct.std::_Bit_reference"* %this, %"struct.std::_Bit_reference"** %1, align 8
  store i64* %__x, i64** %2, align 8
  store i64 %__y, i64* %3, align 8
  %4 = load %"struct.std::_Bit_reference"** %1
  %5 = getelementptr inbounds %"struct.std::_Bit_reference"* %4, i32 0, i32 0
  %6 = load i64** %2, align 8
  store i64* %6, i64** %5, align 8
  %7 = getelementptr inbounds %"struct.std::_Bit_reference"* %4, i32 0, i32 1
  %8 = load i64* %3, align 8
  store i64 %8, i64* %7, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNSt13_Bit_iteratorppEi(%"struct.std::_Bit_iterator"* %this, i32) #2 align 2 {
  %2 = alloca %"struct.std::_Bit_iterator", align 8
  %3 = alloca %"struct.std::_Bit_iterator"*, align 8
  %4 = alloca i32, align 4
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %3, align 8
  store i32 %0, i32* %4, align 4
  %5 = load %"struct.std::_Bit_iterator"** %3
  %6 = bitcast %"struct.std::_Bit_iterator"* %2 to i8*
  %7 = bitcast %"struct.std::_Bit_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 16, i32 8, i1 false)
  %8 = bitcast %"struct.std::_Bit_iterator"* %5 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base10_M_bump_upEv(%"struct.std::_Bit_iterator_base"* %8)
  %9 = bitcast %"struct.std::_Bit_iterator"* %2 to { i64*, i32 }*
  %10 = load { i64*, i32 }* %9, align 1
  ret { i64*, i32 } %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratormmEv(%"struct.std::_Bit_iterator"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator"*, align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %1, align 8
  %2 = load %"struct.std::_Bit_iterator"** %1
  %3 = bitcast %"struct.std::_Bit_iterator"* %2 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base12_M_bump_downEv(%"struct.std::_Bit_iterator_base"* %3)
  ret %"struct.std::_Bit_iterator"* %2
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNSt13_Bit_iteratormmEi(%"struct.std::_Bit_iterator"* %this, i32) #2 align 2 {
  %2 = alloca %"struct.std::_Bit_iterator", align 8
  %3 = alloca %"struct.std::_Bit_iterator"*, align 8
  %4 = alloca i32, align 4
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %3, align 8
  store i32 %0, i32* %4, align 4
  %5 = load %"struct.std::_Bit_iterator"** %3
  %6 = bitcast %"struct.std::_Bit_iterator"* %2 to i8*
  %7 = bitcast %"struct.std::_Bit_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 16, i32 8, i1 false)
  %8 = bitcast %"struct.std::_Bit_iterator"* %5 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base12_M_bump_downEv(%"struct.std::_Bit_iterator_base"* %8)
  %9 = bitcast %"struct.std::_Bit_iterator"* %2 to { i64*, i32 }*
  %10 = load { i64*, i32 }* %9, align 1
  ret { i64*, i32 } %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratorpLEl(%"struct.std::_Bit_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %1, align 8
  store i64 %__i, i64* %2, align 8
  %3 = load %"struct.std::_Bit_iterator"** %1
  %4 = bitcast %"struct.std::_Bit_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %5 = load i64* %2, align 8
  call void @_ZNSt18_Bit_iterator_base7_M_incrEl(%"struct.std::_Bit_iterator_base"* %4, i64 %5)
  ret %"struct.std::_Bit_iterator"* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratormIEl(%"struct.std::_Bit_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %1, align 8
  store i64 %__i, i64* %2, align 8
  %3 = load %"struct.std::_Bit_iterator"** %1
  %4 = load i64* %2, align 8
  %5 = sub nsw i64 0, %4
  %6 = call dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratorpLEl(%"struct.std::_Bit_iterator"* %3, i64 %5)
  ret %"struct.std::_Bit_iterator"* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNKSt13_Bit_iteratormiEl(%"struct.std::_Bit_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator", align 8
  %2 = alloca %"struct.std::_Bit_iterator"*, align 8
  %3 = alloca i64, align 8
  %__tmp = alloca %"struct.std::_Bit_iterator", align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %2, align 8
  store i64 %__i, i64* %3, align 8
  %4 = load %"struct.std::_Bit_iterator"** %2
  %5 = bitcast %"struct.std::_Bit_iterator"* %__tmp to i8*
  %6 = bitcast %"struct.std::_Bit_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %5, i8* %6, i64 16, i32 8, i1 false)
  %7 = load i64* %3, align 8
  %8 = call dereferenceable(16) %"struct.std::_Bit_iterator"* @_ZNSt13_Bit_iteratormIEl(%"struct.std::_Bit_iterator"* %__tmp, i64 %7)
  %9 = bitcast %"struct.std::_Bit_iterator"* %1 to i8*
  %10 = bitcast %"struct.std::_Bit_iterator"* %8 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %9, i8* %10, i64 16, i32 8, i1 false)
  %11 = bitcast %"struct.std::_Bit_iterator"* %1 to { i64*, i32 }*
  %12 = load { i64*, i32 }* %11, align 1
  ret { i64*, i32 } %12
}

; Function Attrs: uwtable
define linkonce_odr { i64*, i64 } @_ZNKSt13_Bit_iteratorixEl(%"struct.std::_Bit_iterator"* %this, i64 %__i) #7 align 2 {
  %1 = alloca %"struct.std::_Bit_reference", align 8
  %2 = alloca %"struct.std::_Bit_iterator"*, align 8
  %3 = alloca i64, align 8
  %4 = alloca %"struct.std::_Bit_iterator", align 8
  store %"struct.std::_Bit_iterator"* %this, %"struct.std::_Bit_iterator"** %2, align 8
  store i64 %__i, i64* %3, align 8
  %5 = load %"struct.std::_Bit_iterator"** %2
  %6 = load i64* %3, align 8
  %7 = call { i64*, i32 } @_ZNKSt13_Bit_iteratorplEl(%"struct.std::_Bit_iterator"* %5, i64 %6)
  %8 = bitcast %"struct.std::_Bit_iterator"* %4 to { i64*, i32 }*
  %9 = getelementptr { i64*, i32 }* %8, i32 0, i32 0
  %10 = extractvalue { i64*, i32 } %7, 0
  store i64* %10, i64** %9, align 1
  %11 = getelementptr { i64*, i32 }* %8, i32 0, i32 1
  %12 = extractvalue { i64*, i32 } %7, 1
  store i32 %12, i32* %11, align 1
  %13 = call { i64*, i64 } @_ZNKSt13_Bit_iteratordeEv(%"struct.std::_Bit_iterator"* %4)
  %14 = bitcast %"struct.std::_Bit_reference"* %1 to { i64*, i64 }*
  %15 = getelementptr { i64*, i64 }* %14, i32 0, i32 0
  %16 = extractvalue { i64*, i64 } %13, 0
  store i64* %16, i64** %15, align 1
  %17 = getelementptr { i64*, i64 }* %14, i32 0, i32 1
  %18 = extractvalue { i64*, i64 } %13, 1
  store i64 %18, i64* %17, align 1
  %19 = bitcast %"struct.std::_Bit_reference"* %1 to { i64*, i64 }*
  %20 = load { i64*, i64 }* %19, align 1
  ret { i64*, i64 } %20
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt19_Bit_const_iteratorC2Ev(%"struct.std::_Bit_const_iterator"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  %2 = load %"struct.std::_Bit_const_iterator"** %1
  %3 = bitcast %"struct.std::_Bit_const_iterator"* %2 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_baseC2EPmj(%"struct.std::_Bit_iterator_base"* %3, i64* null, i32 0)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt19_Bit_const_iteratorC2EPmj(%"struct.std::_Bit_const_iterator"* %this, i64* %__x, i32 %__y) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  store i64* %__x, i64** %2, align 8
  store i32 %__y, i32* %3, align 4
  %4 = load %"struct.std::_Bit_const_iterator"** %1
  %5 = bitcast %"struct.std::_Bit_const_iterator"* %4 to %"struct.std::_Bit_iterator_base"*
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  call void @_ZNSt18_Bit_iterator_baseC2EPmj(%"struct.std::_Bit_iterator_base"* %5, i64* %6, i32 %7)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt19_Bit_const_iteratorC2ERKSt13_Bit_iterator(%"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_iterator"* dereferenceable(16) %__x) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %2 = alloca %"struct.std::_Bit_iterator"*, align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  store %"struct.std::_Bit_iterator"* %__x, %"struct.std::_Bit_iterator"** %2, align 8
  %3 = load %"struct.std::_Bit_const_iterator"** %1
  %4 = bitcast %"struct.std::_Bit_const_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %5 = load %"struct.std::_Bit_iterator"** %2, align 8
  %6 = bitcast %"struct.std::_Bit_iterator"* %5 to %"struct.std::_Bit_iterator_base"*
  %7 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %6, i32 0, i32 0
  %8 = load i64** %7, align 8
  %9 = load %"struct.std::_Bit_iterator"** %2, align 8
  %10 = bitcast %"struct.std::_Bit_iterator"* %9 to %"struct.std::_Bit_iterator_base"*
  %11 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %10, i32 0, i32 1
  %12 = load i32* %11, align 4
  call void @_ZNSt18_Bit_iterator_baseC2EPmj(%"struct.std::_Bit_iterator_base"* %4, i64* %8, i32 %12)
  ret void
}

; Function Attrs: uwtable
define linkonce_odr { i64*, i32 } @_ZNKSt19_Bit_const_iterator13_M_const_castEv(%"struct.std::_Bit_const_iterator"* %this) #7 align 2 {
  %1 = alloca %"struct.std::_Bit_iterator", align 8
  %2 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %2, align 8
  %3 = load %"struct.std::_Bit_const_iterator"** %2
  %4 = bitcast %"struct.std::_Bit_const_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %5 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %4, i32 0, i32 0
  %6 = load i64** %5, align 8
  %7 = bitcast %"struct.std::_Bit_const_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %8 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %7, i32 0, i32 1
  %9 = load i32* %8, align 4
  call void @_ZNSt13_Bit_iteratorC2EPmj(%"struct.std::_Bit_iterator"* %1, i64* %6, i32 %9)
  %10 = bitcast %"struct.std::_Bit_iterator"* %1 to { i64*, i32 }*
  %11 = load { i64*, i32 }* %10, align 1
  ret { i64*, i32 } %11
}

; Function Attrs: uwtable
define linkonce_odr zeroext i1 @_ZNKSt19_Bit_const_iteratordeEv(%"struct.std::_Bit_const_iterator"* %this) #7 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %2 = alloca %"struct.std::_Bit_reference", align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  %3 = load %"struct.std::_Bit_const_iterator"** %1
  %4 = bitcast %"struct.std::_Bit_const_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %5 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %4, i32 0, i32 0
  %6 = load i64** %5, align 8
  %7 = bitcast %"struct.std::_Bit_const_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %8 = getelementptr inbounds %"struct.std::_Bit_iterator_base"* %7, i32 0, i32 1
  %9 = load i32* %8, align 4
  %10 = zext i32 %9 to i64
  %11 = shl i64 1, %10
  call void @_ZNSt14_Bit_referenceC2EPmm(%"struct.std::_Bit_reference"* %2, i64* %6, i64 %11)
  %12 = call zeroext i1 @_ZNKSt14_Bit_referencecvbEv(%"struct.std::_Bit_reference"* %2) #8
  ret i1 %12
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_const_iterator"* @_ZNSt19_Bit_const_iteratorppEv(%"struct.std::_Bit_const_iterator"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  %2 = load %"struct.std::_Bit_const_iterator"** %1
  %3 = bitcast %"struct.std::_Bit_const_iterator"* %2 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base10_M_bump_upEv(%"struct.std::_Bit_iterator_base"* %3)
  ret %"struct.std::_Bit_const_iterator"* %2
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNSt19_Bit_const_iteratorppEi(%"struct.std::_Bit_const_iterator"* %this, i32) #2 align 2 {
  %2 = alloca %"struct.std::_Bit_const_iterator", align 8
  %3 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %4 = alloca i32, align 4
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %3, align 8
  store i32 %0, i32* %4, align 4
  %5 = load %"struct.std::_Bit_const_iterator"** %3
  %6 = bitcast %"struct.std::_Bit_const_iterator"* %2 to i8*
  %7 = bitcast %"struct.std::_Bit_const_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 16, i32 8, i1 false)
  %8 = bitcast %"struct.std::_Bit_const_iterator"* %5 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base10_M_bump_upEv(%"struct.std::_Bit_iterator_base"* %8)
  %9 = bitcast %"struct.std::_Bit_const_iterator"* %2 to { i64*, i32 }*
  %10 = load { i64*, i32 }* %9, align 1
  ret { i64*, i32 } %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_const_iterator"* @_ZNSt19_Bit_const_iteratormmEv(%"struct.std::_Bit_const_iterator"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  %2 = load %"struct.std::_Bit_const_iterator"** %1
  %3 = bitcast %"struct.std::_Bit_const_iterator"* %2 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base12_M_bump_downEv(%"struct.std::_Bit_iterator_base"* %3)
  ret %"struct.std::_Bit_const_iterator"* %2
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNSt19_Bit_const_iteratormmEi(%"struct.std::_Bit_const_iterator"* %this, i32) #2 align 2 {
  %2 = alloca %"struct.std::_Bit_const_iterator", align 8
  %3 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %4 = alloca i32, align 4
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %3, align 8
  store i32 %0, i32* %4, align 4
  %5 = load %"struct.std::_Bit_const_iterator"** %3
  %6 = bitcast %"struct.std::_Bit_const_iterator"* %2 to i8*
  %7 = bitcast %"struct.std::_Bit_const_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 16, i32 8, i1 false)
  %8 = bitcast %"struct.std::_Bit_const_iterator"* %5 to %"struct.std::_Bit_iterator_base"*
  call void @_ZNSt18_Bit_iterator_base12_M_bump_downEv(%"struct.std::_Bit_iterator_base"* %8)
  %9 = bitcast %"struct.std::_Bit_const_iterator"* %2 to { i64*, i32 }*
  %10 = load { i64*, i32 }* %9, align 1
  ret { i64*, i32 } %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_const_iterator"* @_ZNSt19_Bit_const_iteratorpLEl(%"struct.std::_Bit_const_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  store i64 %__i, i64* %2, align 8
  %3 = load %"struct.std::_Bit_const_iterator"** %1
  %4 = bitcast %"struct.std::_Bit_const_iterator"* %3 to %"struct.std::_Bit_iterator_base"*
  %5 = load i64* %2, align 8
  call void @_ZNSt18_Bit_iterator_base7_M_incrEl(%"struct.std::_Bit_iterator_base"* %4, i64 %5)
  ret %"struct.std::_Bit_const_iterator"* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"struct.std::_Bit_const_iterator"* @_ZNSt19_Bit_const_iteratormIEl(%"struct.std::_Bit_const_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  store i64 %__i, i64* %2, align 8
  %3 = load %"struct.std::_Bit_const_iterator"** %1
  %4 = load i64* %2, align 8
  %5 = sub nsw i64 0, %4
  %6 = call dereferenceable(16) %"struct.std::_Bit_const_iterator"* @_ZNSt19_Bit_const_iteratorpLEl(%"struct.std::_Bit_const_iterator"* %3, i64 %5)
  ret %"struct.std::_Bit_const_iterator"* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr { i64*, i32 } @_ZNKSt19_Bit_const_iteratormiEl(%"struct.std::_Bit_const_iterator"* %this, i64 %__i) #2 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator", align 8
  %2 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %3 = alloca i64, align 8
  %__tmp = alloca %"struct.std::_Bit_const_iterator", align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %2, align 8
  store i64 %__i, i64* %3, align 8
  %4 = load %"struct.std::_Bit_const_iterator"** %2
  %5 = bitcast %"struct.std::_Bit_const_iterator"* %__tmp to i8*
  %6 = bitcast %"struct.std::_Bit_const_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %5, i8* %6, i64 16, i32 8, i1 false)
  %7 = load i64* %3, align 8
  %8 = call dereferenceable(16) %"struct.std::_Bit_const_iterator"* @_ZNSt19_Bit_const_iteratormIEl(%"struct.std::_Bit_const_iterator"* %__tmp, i64 %7)
  %9 = bitcast %"struct.std::_Bit_const_iterator"* %1 to i8*
  %10 = bitcast %"struct.std::_Bit_const_iterator"* %8 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %9, i8* %10, i64 16, i32 8, i1 false)
  %11 = bitcast %"struct.std::_Bit_const_iterator"* %1 to { i64*, i32 }*
  %12 = load { i64*, i32 }* %11, align 1
  ret { i64*, i32 } %12
}

; Function Attrs: uwtable
define linkonce_odr zeroext i1 @_ZNKSt19_Bit_const_iteratorixEl(%"struct.std::_Bit_const_iterator"* %this, i64 %__i) #7 align 2 {
  %1 = alloca %"struct.std::_Bit_const_iterator"*, align 8
  %2 = alloca i64, align 8
  %3 = alloca %"struct.std::_Bit_const_iterator", align 8
  store %"struct.std::_Bit_const_iterator"* %this, %"struct.std::_Bit_const_iterator"** %1, align 8
  store i64 %__i, i64* %2, align 8
  %4 = load %"struct.std::_Bit_const_iterator"** %1
  %5 = load i64* %2, align 8
  %6 = call { i64*, i32 } @_ZNKSt19_Bit_const_iteratorplEl(%"struct.std::_Bit_const_iterator"* %4, i64 %5)
  %7 = bitcast %"struct.std::_Bit_const_iterator"* %3 to { i64*, i32 }*
  %8 = getelementptr { i64*, i32 }* %7, i32 0, i32 0
  %9 = extractvalue { i64*, i32 } %6, 0
  store i64* %9, i64** %8, align 1
  %10 = getelementptr { i64*, i32 }* %7, i32 0, i32 1
  %11 = extractvalue { i64*, i32 } %6, 1
  store i32 %11, i32* %10, align 1
  %12 = call zeroext i1 @_ZNKSt19_Bit_const_iteratordeEv(%"struct.std::_Bit_const_iterator"* %3)
  ret i1 %12
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIbEclEb(%"struct.std::hash"* %this, i1 zeroext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash"*, align 8
  %2 = alloca i8, align 1
  store %"struct.std::hash"* %this, %"struct.std::hash"** %1, align 8
  %3 = zext i1 %__val to i8
  store i8 %3, i8* %2, align 1
  %4 = load %"struct.std::hash"** %1
  %5 = load i8* %2, align 1
  %6 = trunc i8 %5 to i1
  %7 = zext i1 %6 to i64
  ret i64 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIcEclEc(%"struct.std::hash.0"* %this, i8 signext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.0"*, align 8
  %2 = alloca i8, align 1
  store %"struct.std::hash.0"* %this, %"struct.std::hash.0"** %1, align 8
  store i8 %__val, i8* %2, align 1
  %3 = load %"struct.std::hash.0"** %1
  %4 = load i8* %2, align 1
  %5 = sext i8 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIaEclEa(%"struct.std::hash.2"* %this, i8 signext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.2"*, align 8
  %2 = alloca i8, align 1
  store %"struct.std::hash.2"* %this, %"struct.std::hash.2"** %1, align 8
  store i8 %__val, i8* %2, align 1
  %3 = load %"struct.std::hash.2"** %1
  %4 = load i8* %2, align 1
  %5 = sext i8 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIhEclEh(%"struct.std::hash.4"* %this, i8 zeroext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.4"*, align 8
  %2 = alloca i8, align 1
  store %"struct.std::hash.4"* %this, %"struct.std::hash.4"** %1, align 8
  store i8 %__val, i8* %2, align 1
  %3 = load %"struct.std::hash.4"** %1
  %4 = load i8* %2, align 1
  %5 = zext i8 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIwEclEw(%"struct.std::hash.6"* %this, i32 signext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.6"*, align 8
  %2 = alloca i32, align 4
  store %"struct.std::hash.6"* %this, %"struct.std::hash.6"** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load %"struct.std::hash.6"** %1
  %4 = load i32* %2, align 4
  %5 = sext i32 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIDsEclEDs(%"struct.std::hash.8"* %this, i16 zeroext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.8"*, align 8
  %2 = alloca i16, align 2
  store %"struct.std::hash.8"* %this, %"struct.std::hash.8"** %1, align 8
  store i16 %__val, i16* %2, align 2
  %3 = load %"struct.std::hash.8"** %1
  %4 = load i16* %2, align 2
  %5 = zext i16 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIDiEclEDi(%"struct.std::hash.10"* %this, i32 zeroext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.10"*, align 8
  %2 = alloca i32, align 4
  store %"struct.std::hash.10"* %this, %"struct.std::hash.10"** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load %"struct.std::hash.10"** %1
  %4 = load i32* %2, align 4
  %5 = zext i32 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIsEclEs(%"struct.std::hash.12"* %this, i16 signext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.12"*, align 8
  %2 = alloca i16, align 2
  store %"struct.std::hash.12"* %this, %"struct.std::hash.12"** %1, align 8
  store i16 %__val, i16* %2, align 2
  %3 = load %"struct.std::hash.12"** %1
  %4 = load i16* %2, align 2
  %5 = sext i16 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIiEclEi(%"struct.std::hash.14"* %this, i32 %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.14"*, align 8
  %2 = alloca i32, align 4
  store %"struct.std::hash.14"* %this, %"struct.std::hash.14"** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load %"struct.std::hash.14"** %1
  %4 = load i32* %2, align 4
  %5 = sext i32 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIlEclEl(%"struct.std::hash.16"* %this, i64 %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.16"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::hash.16"* %this, %"struct.std::hash.16"** %1, align 8
  store i64 %__val, i64* %2, align 8
  %3 = load %"struct.std::hash.16"** %1
  %4 = load i64* %2, align 8
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIxEclEx(%"struct.std::hash.18"* %this, i64 %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.18"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::hash.18"* %this, %"struct.std::hash.18"** %1, align 8
  store i64 %__val, i64* %2, align 8
  %3 = load %"struct.std::hash.18"** %1
  %4 = load i64* %2, align 8
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashItEclEt(%"struct.std::hash.20"* %this, i16 zeroext %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.20"*, align 8
  %2 = alloca i16, align 2
  store %"struct.std::hash.20"* %this, %"struct.std::hash.20"** %1, align 8
  store i16 %__val, i16* %2, align 2
  %3 = load %"struct.std::hash.20"** %1
  %4 = load i16* %2, align 2
  %5 = zext i16 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIjEclEj(%"struct.std::hash.22"* %this, i32 %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.22"*, align 8
  %2 = alloca i32, align 4
  store %"struct.std::hash.22"* %this, %"struct.std::hash.22"** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load %"struct.std::hash.22"** %1
  %4 = load i32* %2, align 4
  %5 = zext i32 %4 to i64
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashImEclEm(%"struct.std::hash.24"* %this, i64 %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.24"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::hash.24"* %this, %"struct.std::hash.24"** %1, align 8
  store i64 %__val, i64* %2, align 8
  %3 = load %"struct.std::hash.24"** %1
  %4 = load i64* %2, align 8
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIyEclEy(%"struct.std::hash.26"* %this, i64 %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.26"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::hash.26"* %this, %"struct.std::hash.26"** %1, align 8
  store i64 %__val, i64* %2, align 8
  %3 = load %"struct.std::hash.26"** %1
  %4 = load i64* %2, align 8
  ret i64 %4
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZNSt10_Hash_impl4hashEPKvmm(i8* %__ptr, i64 %__clength, i64 %__seed) #7 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i64, align 8
  store i8* %__ptr, i8** %1, align 8
  store i64 %__clength, i64* %2, align 8
  store i64 %__seed, i64* %3, align 8
  %4 = load i8** %1, align 8
  %5 = load i64* %2, align 8
  %6 = load i64* %3, align 8
  %7 = call i64 @_ZSt11_Hash_bytesPKvmm(i8* %4, i64 %5, i64 %6)
  ret i64 %7
}

declare i64 @_ZSt11_Hash_bytesPKvmm(i8*, i64, i64) #9

; Function Attrs: uwtable
define linkonce_odr i64 @_ZNSt14_Fnv_hash_impl4hashEPKvmm(i8* %__ptr, i64 %__clength, i64 %__seed) #7 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i64, align 8
  store i8* %__ptr, i8** %1, align 8
  store i64 %__clength, i64* %2, align 8
  store i64 %__seed, i64* %3, align 8
  %4 = load i8** %1, align 8
  %5 = load i64* %2, align 8
  %6 = load i64* %3, align 8
  %7 = call i64 @_ZSt15_Fnv_hash_bytesPKvmm(i8* %4, i64 %5, i64 %6)
  ret i64 %7
}

declare i64 @_ZSt15_Fnv_hash_bytesPKvmm(i8*, i64, i64) #9

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIfEclEf(%"struct.std::hash.28"* %this, float %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.28"*, align 8
  %2 = alloca float, align 4
  store %"struct.std::hash.28"* %this, %"struct.std::hash.28"** %1, align 8
  store float %__val, float* %2, align 4
  %3 = load %"struct.std::hash.28"** %1
  %4 = load float* %2, align 4
  %5 = fcmp une float %4, 0.000000e+00
  br i1 %5, label %6, label %9

; <label>:6                                       ; preds = %0
  %7 = invoke i64 @_ZNSt10_Hash_impl4hashIfEEmRKT_(float* dereferenceable(4) %2)
          to label %8 unwind label %12

; <label>:8                                       ; preds = %6
  br label %10

; <label>:9                                       ; preds = %0
  br label %10

; <label>:10                                      ; preds = %9, %8
  %11 = phi i64 [ %7, %8 ], [ 0, %9 ]
  ret i64 %11

; <label>:12                                      ; preds = %6
  %13 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %14 = extractvalue { i8*, i32 } %13, 0
  call void @__clang_call_terminate(i8* %14) #18
  unreachable
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZNSt10_Hash_impl4hashIfEEmRKT_(float* dereferenceable(4) %__val) #7 align 2 {
  %1 = alloca float*, align 8
  store float* %__val, float** %1, align 8
  %2 = load float** %1, align 8
  %3 = bitcast float* %2 to i8*
  %4 = call i64 @_ZNSt10_Hash_impl4hashEPKvmm(i8* %3, i64 4, i64 3339675911)
  ret i64 %4
}

; Function Attrs: noinline noreturn nounwind
define linkonce_odr hidden void @__clang_call_terminate(i8*) #10 {
  %2 = call i8* @__cxa_begin_catch(i8* %0) #8
  call void @_ZSt9terminatev() #18
  unreachable
}

declare i8* @__cxa_begin_catch(i8*)

declare void @_ZSt9terminatev()

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashIdEclEd(%"struct.std::hash.30"* %this, double %__val) #2 align 2 {
  %1 = alloca %"struct.std::hash.30"*, align 8
  %2 = alloca double, align 8
  store %"struct.std::hash.30"* %this, %"struct.std::hash.30"** %1, align 8
  store double %__val, double* %2, align 8
  %3 = load %"struct.std::hash.30"** %1
  %4 = load double* %2, align 8
  %5 = fcmp une double %4, 0.000000e+00
  br i1 %5, label %6, label %9

; <label>:6                                       ; preds = %0
  %7 = invoke i64 @_ZNSt10_Hash_impl4hashIdEEmRKT_(double* dereferenceable(8) %2)
          to label %8 unwind label %12

; <label>:8                                       ; preds = %6
  br label %10

; <label>:9                                       ; preds = %0
  br label %10

; <label>:10                                      ; preds = %9, %8
  %11 = phi i64 [ %7, %8 ], [ 0, %9 ]
  ret i64 %11

; <label>:12                                      ; preds = %6
  %13 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %14 = extractvalue { i8*, i32 } %13, 0
  call void @__clang_call_terminate(i8* %14) #18
  unreachable
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZNSt10_Hash_impl4hashIdEEmRKT_(double* dereferenceable(8) %__val) #7 align 2 {
  %1 = alloca double*, align 8
  store double* %__val, double** %1, align 8
  %2 = load double** %1, align 8
  %3 = bitcast double* %2 to i8*
  %4 = call i64 @_ZNSt10_Hash_impl4hashEPKvmm(i8* %3, i64 8, i64 3339675911)
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNK2fp6Packet4dataEv(%"struct.fp::Packet"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Packet"*, align 8
  store %"struct.fp::Packet"* %this, %"struct.fp::Packet"** %1, align 8
  %2 = load %"struct.fp::Packet"** %1
  %3 = getelementptr inbounds %"struct.fp::Packet"* %2, i32 0, i32 0
  %4 = bitcast %"struct.fp::Buffer::Flowpath"* %3 to %"struct.fp::Buffer::Base"*
  %5 = getelementptr inbounds %"struct.fp::Buffer::Base"* %4, i32 0, i32 1
  %6 = load i8** %5, align 8
  ret i8* %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZN2fp6Packet4dataEv(%"struct.fp::Packet"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Packet"*, align 8
  store %"struct.fp::Packet"* %this, %"struct.fp::Packet"** %1, align 8
  %2 = load %"struct.fp::Packet"** %1
  %3 = getelementptr inbounds %"struct.fp::Packet"* %2, i32 0, i32 0
  %4 = bitcast %"struct.fp::Buffer::Flowpath"* %3 to %"struct.fp::Buffer::Base"*
  %5 = getelementptr inbounds %"struct.fp::Buffer::Base"* %4, i32 0, i32 1
  %6 = load i8** %5, align 8
  ret i8* %6
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(4) %"struct.fp::Binding"* @_ZNK2fp12Binding_list3topEv(%"struct.fp::Binding_list"* %this) #4 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = call zeroext i1 @_ZNK2fp12Binding_list8is_emptyEv(%"struct.fp::Binding_list"* %2)
  br i1 %3, label %5, label %4

; <label>:4                                       ; preds = %0
  br label %7

; <label>:5                                       ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 82, i8* getelementptr inbounds ([49 x i8]* @__PRETTY_FUNCTION__._ZNK2fp12Binding_list3topEv, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %7

; <label>:7                                       ; preds = %6, %4
  %8 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 1
  %9 = load i32* %8, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 0
  %12 = getelementptr inbounds [4 x %"struct.fp::Binding"]* %11, i32 0, i64 %10
  ret %"struct.fp::Binding"* %12
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNK2fp12Binding_list8is_emptyEv(%"struct.fp::Binding_list"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 1
  %4 = load i32* %3, align 4
  %5 = icmp eq i32 %4, -1
  ret i1 %5
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #11

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(4) %"struct.fp::Binding"* @_ZN2fp12Binding_list3topEv(%"struct.fp::Binding_list"* %this) #4 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = call zeroext i1 @_ZNK2fp12Binding_list8is_emptyEv(%"struct.fp::Binding_list"* %2)
  br i1 %3, label %5, label %4

; <label>:4                                       ; preds = %0
  br label %7

; <label>:5                                       ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 90, i8* getelementptr inbounds ([37 x i8]* @__PRETTY_FUNCTION__._ZN2fp12Binding_list3topEv, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %7

; <label>:7                                       ; preds = %6, %4
  %8 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 1
  %9 = load i32* %8, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 0
  %12 = getelementptr inbounds [4 x %"struct.fp::Binding"]* %11, i32 0, i64 %10
  ret %"struct.fp::Binding"* %12
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(4) %"struct.fp::Binding"* @_ZNK2fp12Binding_list6bottomEv(%"struct.fp::Binding_list"* %this) #4 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = call zeroext i1 @_ZNK2fp12Binding_list8is_emptyEv(%"struct.fp::Binding_list"* %2)
  br i1 %3, label %5, label %4

; <label>:4                                       ; preds = %0
  br label %7

; <label>:5                                       ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 99, i8* getelementptr inbounds ([52 x i8]* @__PRETTY_FUNCTION__._ZNK2fp12Binding_list6bottomEv, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %7

; <label>:7                                       ; preds = %6, %4
  %8 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 0
  %9 = getelementptr inbounds [4 x %"struct.fp::Binding"]* %8, i32 0, i64 0
  ret %"struct.fp::Binding"* %9
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(4) %"struct.fp::Binding"* @_ZN2fp12Binding_list6bottomEv(%"struct.fp::Binding_list"* %this) #4 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = call zeroext i1 @_ZNK2fp12Binding_list8is_emptyEv(%"struct.fp::Binding_list"* %2)
  br i1 %3, label %5, label %4

; <label>:4                                       ; preds = %0
  br label %7

; <label>:5                                       ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 107, i8* getelementptr inbounds ([40 x i8]* @__PRETTY_FUNCTION__._ZN2fp12Binding_list6bottomEv, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %7

; <label>:7                                       ; preds = %6, %4
  %8 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 0
  %9 = getelementptr inbounds [4 x %"struct.fp::Binding"]* %8, i32 0, i64 0
  ret %"struct.fp::Binding"* %9
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp12Binding_list4pushENS_7BindingE(%"struct.fp::Binding_list"* %this, i32 %b.coerce) #4 align 2 {
  %b = alloca %"struct.fp::Binding", align 4
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  %2 = bitcast %"struct.fp::Binding"* %b to i32*
  store i32 %b.coerce, i32* %2, align 1
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %3 = load %"struct.fp::Binding_list"** %1
  %4 = call zeroext i1 @_ZNK2fp12Binding_list7is_fullEv(%"struct.fp::Binding_list"* %3)
  br i1 %4, label %6, label %5

; <label>:5                                       ; preds = %0
  br label %8

; <label>:6                                       ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([11 x i8]* @.str2, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 118, i8* getelementptr inbounds ([41 x i8]* @__PRETTY_FUNCTION__._ZN2fp12Binding_list4pushENS_7BindingE, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %8

; <label>:8                                       ; preds = %7, %5
  %9 = getelementptr inbounds %"struct.fp::Binding_list"* %3, i32 0, i32 1
  %10 = load i32* %9, align 4
  %11 = add nsw i32 %10, 1
  store i32 %11, i32* %9, align 4
  %12 = sext i32 %11 to i64
  %13 = getelementptr inbounds %"struct.fp::Binding_list"* %3, i32 0, i32 0
  %14 = getelementptr inbounds [4 x %"struct.fp::Binding"]* %13, i32 0, i64 %12
  %15 = bitcast %"struct.fp::Binding"* %14 to i8*
  %16 = bitcast %"struct.fp::Binding"* %b to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %15, i8* %16, i64 4, i32 2, i1 false)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNK2fp12Binding_list7is_fullEv(%"struct.fp::Binding_list"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 1
  %4 = load i32* %3, align 4
  %5 = icmp eq i32 %4, 3
  ret i1 %5
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp12Binding_list4pushEt(%"struct.fp::Binding_list"* %this, i16 zeroext %n) #4 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  %2 = alloca i16, align 2
  %3 = alloca %"struct.fp::Binding", align 2
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  store i16 %n, i16* %2, align 2
  %4 = load %"struct.fp::Binding_list"** %1
  %5 = call zeroext i1 @_ZNK2fp12Binding_list7is_fullEv(%"struct.fp::Binding_list"* %4)
  br i1 %5, label %7, label %6

; <label>:6                                       ; preds = %0
  br label %9

; <label>:7                                       ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([11 x i8]* @.str2, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 127, i8* getelementptr inbounds ([43 x i8]* @__PRETTY_FUNCTION__._ZN2fp12Binding_list4pushEt, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %9

; <label>:9                                       ; preds = %8, %6
  %10 = getelementptr inbounds %"struct.fp::Binding_list"* %4, i32 0, i32 1
  %11 = load i32* %10, align 4
  %12 = add nsw i32 %11, 1
  store i32 %12, i32* %10, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds %"struct.fp::Binding_list"* %4, i32 0, i32 0
  %15 = getelementptr inbounds [4 x %"struct.fp::Binding"]* %14, i32 0, i64 %13
  %16 = load i16* %2, align 2
  call void @_ZN2fp7BindingC2Et(%"struct.fp::Binding"* %3, i16 zeroext %16)
  %17 = bitcast %"struct.fp::Binding"* %15 to i8*
  %18 = bitcast %"struct.fp::Binding"* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %17, i8* %18, i64 4, i32 2, i1 false)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN2fp7BindingC2Et(%"struct.fp::Binding"* %this, i16 zeroext %o) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.fp::Binding"*, align 8
  %2 = alloca i16, align 2
  store %"struct.fp::Binding"* %this, %"struct.fp::Binding"** %1, align 8
  store i16 %o, i16* %2, align 2
  %3 = load %"struct.fp::Binding"** %1
  %4 = getelementptr inbounds %"struct.fp::Binding"* %3, i32 0, i32 0
  %5 = load i16* %2, align 2
  store i16 %5, i16* %4, align 2
  %6 = getelementptr inbounds %"struct.fp::Binding"* %3, i32 0, i32 1
  store i16 0, i16* %6, align 2
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp12Binding_list3popEv(%"struct.fp::Binding_list"* %this) #4 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = call zeroext i1 @_ZNK2fp12Binding_list8is_emptyEv(%"struct.fp::Binding_list"* %2)
  br i1 %3, label %5, label %4

; <label>:4                                       ; preds = %0
  br label %7

; <label>:5                                       ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 137, i8* getelementptr inbounds ([29 x i8]* @__PRETTY_FUNCTION__._ZN2fp12Binding_list3popEv, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %7

; <label>:7                                       ; preds = %6, %4
  %8 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 1
  %9 = load i32* %8, align 4
  %10 = add nsw i32 %9, -1
  store i32 %10, i32* %8, align 4
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp11Environment4pushEiNS_7BindingE(%"struct.fp::Environment"* %this, i32 %n, i32 %b.coerce) #4 align 2 {
  %b = alloca %"struct.fp::Binding", align 4
  %1 = alloca %"struct.fp::Environment"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca %"struct.fp::Binding", align 2
  %4 = bitcast %"struct.fp::Binding"* %b to i32*
  store i32 %b.coerce, i32* %4, align 1
  store %"struct.fp::Environment"* %this, %"struct.fp::Environment"** %1, align 8
  store i32 %n, i32* %2, align 4
  %5 = load %"struct.fp::Environment"** %1
  %6 = load i32* %2, align 4
  %7 = icmp sle i32 0, %6
  br i1 %7, label %8, label %12

; <label>:8                                       ; preds = %0
  %9 = load i32* %2, align 4
  %10 = icmp slt i32 %9, 16
  br i1 %10, label %11, label %12

; <label>:11                                      ; preds = %8
  br label %14

; <label>:12                                      ; preds = %8, %0
  call void @__assert_fail(i8* getelementptr inbounds ([25 x i8]* @.str3, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 171, i8* getelementptr inbounds ([45 x i8]* @__PRETTY_FUNCTION__._ZN2fp11Environment4pushEiNS_7BindingE, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %14

; <label>:14                                      ; preds = %13, %11
  %15 = load i32* %2, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds %"struct.fp::Environment"* %5, i32 0, i32 0
  %18 = getelementptr inbounds [16 x %"struct.fp::Binding_list"]* %17, i32 0, i64 %16
  %19 = bitcast %"struct.fp::Binding"* %3 to i8*
  %20 = bitcast %"struct.fp::Binding"* %b to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %19, i8* %20, i64 4, i32 2, i1 false)
  %21 = bitcast %"struct.fp::Binding"* %3 to i32*
  %22 = load i32* %21, align 1
  call void @_ZN2fp12Binding_list4pushENS_7BindingE(%"struct.fp::Binding_list"* %18, i32 %22)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp11Environment3popEi(%"struct.fp::Environment"* %this, i32 %n) #4 align 2 {
  %1 = alloca %"struct.fp::Environment"*, align 8
  %2 = alloca i32, align 4
  store %"struct.fp::Environment"* %this, %"struct.fp::Environment"** %1, align 8
  store i32 %n, i32* %2, align 4
  %3 = load %"struct.fp::Environment"** %1
  %4 = load i32* %2, align 4
  %5 = icmp sle i32 0, %4
  br i1 %5, label %6, label %10

; <label>:6                                       ; preds = %0
  %7 = load i32* %2, align 4
  %8 = icmp slt i32 %7, 16
  br i1 %8, label %9, label %10

; <label>:9                                       ; preds = %6
  br label %12

; <label>:10                                      ; preds = %6, %0
  call void @__assert_fail(i8* getelementptr inbounds ([25 x i8]* @.str3, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 179, i8* getelementptr inbounds ([31 x i8]* @__PRETTY_FUNCTION__._ZN2fp11Environment3popEi, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %12

; <label>:12                                      ; preds = %11, %9
  %13 = load i32* %2, align 4
  %14 = sext i32 %13 to i64
  %15 = getelementptr inbounds %"struct.fp::Environment"* %3, i32 0, i32 0
  %16 = getelementptr inbounds [16 x %"struct.fp::Binding_list"]* %15, i32 0, i64 %14
  call void @_ZN2fp12Binding_list3popEv(%"struct.fp::Binding_list"* %16)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNK2fp7Binding10is_partialEv(%"struct.fp::Binding"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Binding"*, align 8
  store %"struct.fp::Binding"* %this, %"struct.fp::Binding"** %1, align 8
  %2 = load %"struct.fp::Binding"** %1
  %3 = getelementptr inbounds %"struct.fp::Binding"* %2, i32 0, i32 1
  %4 = load i16* %3, align 2
  %5 = zext i16 %4 to i32
  %6 = icmp eq i32 %5, 0
  ret i1 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN2fp12Binding_listC2Ev(%"struct.fp::Binding_list"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.fp::Binding_list"*, align 8
  store %"struct.fp::Binding_list"* %this, %"struct.fp::Binding_list"** %1, align 8
  %2 = load %"struct.fp::Binding_list"** %1
  %3 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 0
  %4 = getelementptr inbounds %"struct.fp::Binding_list"* %2, i32 0, i32 1
  store i32 -1, i32* %4, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(20) %"struct.fp::Binding_list"* @_ZNK2fp11EnvironmentixEi(%"struct.fp::Environment"* %this, i32 %n) #2 align 2 {
  %1 = alloca %"struct.fp::Environment"*, align 8
  %2 = alloca i32, align 4
  store %"struct.fp::Environment"* %this, %"struct.fp::Environment"** %1, align 8
  store i32 %n, i32* %2, align 4
  %3 = load %"struct.fp::Environment"** %1
  %4 = load i32* %2, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %"struct.fp::Environment"* %3, i32 0, i32 0
  %7 = getelementptr inbounds [16 x %"struct.fp::Binding_list"]* %6, i32 0, i64 %5
  ret %"struct.fp::Binding_list"* %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(20) %"struct.fp::Binding_list"* @_ZN2fp11EnvironmentixEi(%"struct.fp::Environment"* %this, i32 %n) #2 align 2 {
  %1 = alloca %"struct.fp::Environment"*, align 8
  %2 = alloca i32, align 4
  store %"struct.fp::Environment"* %this, %"struct.fp::Environment"** %1, align 8
  store i32 %n, i32* %2, align 4
  %3 = load %"struct.fp::Environment"** %1
  %4 = load i32* %2, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %"struct.fp::Environment"* %3, i32 0, i32 0
  %7 = getelementptr inbounds [16 x %"struct.fp::Binding_list"]* %6, i32 0, i64 %5
  ret %"struct.fp::Binding_list"* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN2fp7Context7advanceEt(%"struct.fp::Context"* %this, i16 zeroext %n) #0 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i16, align 2
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  store i16 %n, i16* %2, align 2
  %3 = load %"struct.fp::Context"** %1
  %4 = load i16* %2, align 2
  %5 = zext i16 %4 to i32
  %6 = getelementptr inbounds %"struct.fp::Context"* %3, i32 0, i32 2
  %7 = getelementptr inbounds %"struct.fp::Context_current"* %6, i32 0, i32 0
  %8 = load i16* %7, align 2
  %9 = zext i16 %8 to i32
  %10 = add nsw i32 %9, %5
  %11 = trunc i32 %10 to i16
  store i16 %11, i16* %7, align 2
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i16 @_ZNK2fp7Context6offsetEv(%"struct.fp::Context"* %this) #0 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 2
  %4 = getelementptr inbounds %"struct.fp::Context_current"* %3, i32 0, i32 0
  %5 = load i16* %4, align 2
  ret i16 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZNK2fp7Context8positionEv(%"struct.fp::Context"* %this) #0 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 0
  %4 = load %"struct.fp::Packet"** %3, align 8
  %5 = call i8* @_ZN2fp6Packet4dataEv(%"struct.fp::Packet"* %4)
  %6 = call zeroext i16 @_ZNK2fp7Context6offsetEv(%"struct.fp::Context"* %2)
  %7 = zext i16 %6 to i32
  %8 = sext i32 %7 to i64
  %9 = getelementptr inbounds i8* %5, i64 %8
  ret i8* %9
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZN2fp7Context8positionEv(%"struct.fp::Context"* %this) #0 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 0
  %4 = load %"struct.fp::Packet"** %3, align 8
  %5 = call i8* @_ZN2fp6Packet4dataEv(%"struct.fp::Packet"* %4)
  %6 = call zeroext i16 @_ZNK2fp7Context6offsetEv(%"struct.fp::Context"* %2)
  %7 = zext i16 %6 to i32
  %8 = sext i32 %7 to i64
  %9 = getelementptr inbounds i8* %5, i64 %8
  ret i8* %9
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp7Context12write_actionENS_6ActionE(%"struct.fp::Context"* %this, %"struct.fp::Action"* byval align 8 %a) #4 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 7
  %4 = bitcast %"struct.fp::Action_set"* %3 to %"class.std::vector"*
  call void @_ZNSt6vectorIN2fp6ActionESaIS1_EE9push_backERKS1_(%"class.std::vector"* %4, %"struct.fp::Action"* dereferenceable(24) %a)
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt6vectorIN2fp6ActionESaIS1_EE9push_backERKS1_(%"class.std::vector"* %this, %"struct.fp::Action"* dereferenceable(24) %__x) #7 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store %"struct.fp::Action"* %__x, %"struct.fp::Action"** %2, align 8
  %3 = load %"class.std::vector"** %1
  %4 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %5 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %5, i32 0, i32 1
  %7 = load %"struct.fp::Action"** %6, align 8
  %8 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %9 = getelementptr inbounds %"struct.std::_Vector_base"* %8, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %9, i32 0, i32 2
  %11 = load %"struct.fp::Action"** %10, align 8
  %12 = icmp ne %"struct.fp::Action"* %7, %11
  br i1 %12, label %13, label %27

; <label>:13                                      ; preds = %0
  %14 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %15 = getelementptr inbounds %"struct.std::_Vector_base"* %14, i32 0, i32 0
  %16 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %15 to %"class.std::allocator"*
  %17 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %18 = getelementptr inbounds %"struct.std::_Vector_base"* %17, i32 0, i32 0
  %19 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %18, i32 0, i32 1
  %20 = load %"struct.fp::Action"** %19, align 8
  %21 = load %"struct.fp::Action"** %2, align 8
  call void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE9constructIS1_JRKS1_EEEDTcl12_S_constructfp_fp0_spclsr3stdE7forwardIT0_Efp1_EEERS2_PT_DpOS7_(%"class.std::allocator"* dereferenceable(1) %16, %"struct.fp::Action"* %20, %"struct.fp::Action"* dereferenceable(24) %21)
  %22 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %23 = getelementptr inbounds %"struct.std::_Vector_base"* %22, i32 0, i32 0
  %24 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %23, i32 0, i32 1
  %25 = load %"struct.fp::Action"** %24, align 8
  %26 = getelementptr inbounds %"struct.fp::Action"* %25, i32 1
  store %"struct.fp::Action"* %26, %"struct.fp::Action"** %24, align 8
  br label %29

; <label>:27                                      ; preds = %0
  %28 = load %"struct.fp::Action"** %2, align 8
  call void @_ZNSt6vectorIN2fp6ActionESaIS1_EE19_M_emplace_back_auxIJRKS1_EEEvDpOT_(%"class.std::vector"* %3, %"struct.fp::Action"* dereferenceable(24) %28)
  br label %29

; <label>:29                                      ; preds = %27, %13
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp7Context13apply_actionsEv(%"struct.fp::Context"* %this) #4 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %__range = alloca %"struct.fp::Action_set"*, align 8
  %__begin = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %__end = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %a = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"struct.fp::Action", align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %3 = load %"struct.fp::Context"** %1
  %4 = getelementptr inbounds %"struct.fp::Context"* %3, i32 0, i32 7
  store %"struct.fp::Action_set"* %4, %"struct.fp::Action_set"** %__range, align 8
  %5 = load %"struct.fp::Action_set"** %__range, align 8
  %6 = bitcast %"struct.fp::Action_set"* %5 to %"class.std::vector"*
  %7 = call %"struct.fp::Action"* @_ZNSt6vectorIN2fp6ActionESaIS1_EE5beginEv(%"class.std::vector"* %6) #8
  %8 = getelementptr %"class.__gnu_cxx::__normal_iterator"* %__begin, i32 0, i32 0
  store %"struct.fp::Action"* %7, %"struct.fp::Action"** %8
  %9 = load %"struct.fp::Action_set"** %__range, align 8
  %10 = bitcast %"struct.fp::Action_set"* %9 to %"class.std::vector"*
  %11 = call %"struct.fp::Action"* @_ZNSt6vectorIN2fp6ActionESaIS1_EE3endEv(%"class.std::vector"* %10) #8
  %12 = getelementptr %"class.__gnu_cxx::__normal_iterator"* %__end, i32 0, i32 0
  store %"struct.fp::Action"* %11, %"struct.fp::Action"** %12
  br label %13

; <label>:13                                      ; preds = %20, %0
  %14 = call zeroext i1 @_ZN9__gnu_cxxneIPN2fp6ActionESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_(%"class.__gnu_cxx::__normal_iterator"* dereferenceable(8) %__begin, %"class.__gnu_cxx::__normal_iterator"* dereferenceable(8) %__end) #8
  br i1 %14, label %15, label %22

; <label>:15                                      ; preds = %13
  %16 = call dereferenceable(24) %"struct.fp::Action"* @_ZNK9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEEdeEv(%"class.__gnu_cxx::__normal_iterator"* %__begin) #8
  store %"struct.fp::Action"* %16, %"struct.fp::Action"** %a, align 8
  %17 = load %"struct.fp::Action"** %a, align 8
  %18 = bitcast %"struct.fp::Action"* %2 to i8*
  %19 = bitcast %"struct.fp::Action"* %17 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %18, i8* %19, i64 24, i32 8, i1 false)
  call void @_ZN2fp7Context12apply_actionENS_6ActionE(%"struct.fp::Context"* %3, %"struct.fp::Action"* byval align 8 %2)
  br label %20

; <label>:20                                      ; preds = %15
  %21 = call dereferenceable(8) %"class.__gnu_cxx::__normal_iterator"* @_ZN9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEEppEv(%"class.__gnu_cxx::__normal_iterator"* %__begin) #8
  br label %13

; <label>:22                                      ; preds = %13
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt6vectorIN2fp6ActionESaIS1_EE5beginEv(%"class.std::vector"* %this) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %2 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %2, align 8
  %3 = load %"class.std::vector"** %2
  %4 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %5 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %5, i32 0, i32 0
  call void @_ZN9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator"* %1, %"struct.fp::Action"** dereferenceable(8) %6) #8
  %7 = getelementptr %"class.__gnu_cxx::__normal_iterator"* %1, i32 0, i32 0
  %8 = load %"struct.fp::Action"** %7
  ret %"struct.fp::Action"* %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt6vectorIN2fp6ActionESaIS1_EE3endEv(%"class.std::vector"* %this) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %2 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %2, align 8
  %3 = load %"class.std::vector"** %2
  %4 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %5 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %5, i32 0, i32 1
  call void @_ZN9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator"* %1, %"struct.fp::Action"** dereferenceable(8) %6) #8
  %7 = getelementptr %"class.__gnu_cxx::__normal_iterator"* %1, i32 0, i32 0
  %8 = load %"struct.fp::Action"** %7
  ret %"struct.fp::Action"* %8
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i1 @_ZN9__gnu_cxxneIPN2fp6ActionESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_(%"class.__gnu_cxx::__normal_iterator"* dereferenceable(8) %__lhs, %"class.__gnu_cxx::__normal_iterator"* dereferenceable(8) %__rhs) #0 {
  %1 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  %2 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %__lhs, %"class.__gnu_cxx::__normal_iterator"** %1, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %__rhs, %"class.__gnu_cxx::__normal_iterator"** %2, align 8
  %3 = load %"class.__gnu_cxx::__normal_iterator"** %1, align 8
  %4 = call dereferenceable(8) %"struct.fp::Action"** @_ZNK9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator"* %3) #8
  %5 = load %"struct.fp::Action"** %4
  %6 = load %"class.__gnu_cxx::__normal_iterator"** %2, align 8
  %7 = call dereferenceable(8) %"struct.fp::Action"** @_ZNK9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator"* %6) #8
  %8 = load %"struct.fp::Action"** %7
  %9 = icmp ne %"struct.fp::Action"* %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(24) %"struct.fp::Action"* @_ZNK9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEEdeEv(%"class.__gnu_cxx::__normal_iterator"* %this) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %this, %"class.__gnu_cxx::__normal_iterator"** %1, align 8
  %2 = load %"class.__gnu_cxx::__normal_iterator"** %1
  %3 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator"* %2, i32 0, i32 0
  %4 = load %"struct.fp::Action"** %3, align 8
  ret %"struct.fp::Action"* %4
}

declare void @_ZN2fp7Context12apply_actionENS_6ActionE(%"struct.fp::Context"*, %"struct.fp::Action"* byval align 8) #9

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) %"class.__gnu_cxx::__normal_iterator"* @_ZN9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEEppEv(%"class.__gnu_cxx::__normal_iterator"* %this) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %this, %"class.__gnu_cxx::__normal_iterator"** %1, align 8
  %2 = load %"class.__gnu_cxx::__normal_iterator"** %1
  %3 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator"* %2, i32 0, i32 0
  %4 = load %"struct.fp::Action"** %3, align 8
  %5 = getelementptr inbounds %"struct.fp::Action"* %4, i32 1
  store %"struct.fp::Action"* %5, %"struct.fp::Action"** %3, align 8
  ret %"class.__gnu_cxx::__normal_iterator"* %2
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN2fp7Context13clear_actionsEv(%"struct.fp::Context"* %this) #0 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 7
  %4 = bitcast %"struct.fp::Action_set"* %3 to %"class.std::vector"*
  call void @_ZNSt6vectorIN2fp6ActionESaIS1_EE5clearEv(%"class.std::vector"* %4) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6vectorIN2fp6ActionESaIS1_EE5clearEv(%"class.std::vector"* %this) #2 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %2 = load %"class.std::vector"** %1
  %3 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  %4 = getelementptr inbounds %"struct.std::_Vector_base"* %3, i32 0, i32 0
  %5 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %4, i32 0, i32 0
  %6 = load %"struct.fp::Action"** %5, align 8
  call void @_ZNSt6vectorIN2fp6ActionESaIS1_EE15_M_erase_at_endEPS1_(%"class.std::vector"* %2, %"struct.fp::Action"* %6) #8
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp7Context11bind_headerEi(%"struct.fp::Context"* %this, i32 %id) #4 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca %"struct.fp::Binding", align 2
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  store i32 %id, i32* %2, align 4
  %4 = load %"struct.fp::Context"** %1
  %5 = getelementptr inbounds %"struct.fp::Context"* %4, i32 0, i32 8
  %6 = load i32* %2, align 4
  %7 = call zeroext i16 @_ZNK2fp7Context6offsetEv(%"struct.fp::Context"* %4)
  call void @_ZN2fp7BindingC2Et(%"struct.fp::Binding"* %3, i16 zeroext %7)
  %8 = bitcast %"struct.fp::Binding"* %3 to i32*
  %9 = load i32* %8, align 1
  call void @_ZN2fp11Environment4pushEiNS_7BindingE(%"struct.fp::Environment"* %5, i32 %6, i32 %9)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp7Context10bind_fieldEitt(%"struct.fp::Context"* %this, i32 %id, i16 zeroext %off, i16 zeroext %len) #4 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i16, align 2
  %4 = alloca i16, align 2
  %5 = alloca %"struct.fp::Binding", align 2
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  store i32 %id, i32* %2, align 4
  store i16 %off, i16* %3, align 2
  store i16 %len, i16* %4, align 2
  %6 = load %"struct.fp::Context"** %1
  %7 = getelementptr inbounds %"struct.fp::Context"* %6, i32 0, i32 9
  %8 = load i32* %2, align 4
  %9 = load i16* %3, align 2
  %10 = load i16* %4, align 2
  call void @_ZN2fp7BindingC2Ett(%"struct.fp::Binding"* %5, i16 zeroext %9, i16 zeroext %10)
  %11 = bitcast %"struct.fp::Binding"* %5 to i32*
  %12 = load i32* %11, align 1
  call void @_ZN2fp11Environment4pushEiNS_7BindingE(%"struct.fp::Environment"* %7, i32 %8, i32 %12)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN2fp7BindingC2Ett(%"struct.fp::Binding"* %this, i16 zeroext %o, i16 zeroext %n) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.fp::Binding"*, align 8
  %2 = alloca i16, align 2
  %3 = alloca i16, align 2
  store %"struct.fp::Binding"* %this, %"struct.fp::Binding"** %1, align 8
  store i16 %o, i16* %2, align 2
  store i16 %n, i16* %3, align 2
  %4 = load %"struct.fp::Binding"** %1
  %5 = getelementptr inbounds %"struct.fp::Binding"* %4, i32 0, i32 0
  %6 = load i16* %2, align 2
  store i16 %6, i16* %5, align 2
  %7 = getelementptr inbounds %"struct.fp::Binding"* %4, i32 0, i32 1
  %8 = load i16* %3, align 2
  store i16 %8, i16* %7, align 2
  %9 = load i16* %3, align 2
  %10 = zext i16 %9 to i32
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %12, label %13

; <label>:12                                      ; preds = %0
  br label %15

; <label>:13                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8]* @.str4, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8]* @.str1, i32 0, i32 0), i32 33, i8* getelementptr inbounds ([51 x i8]* @__PRETTY_FUNCTION__._ZN2fp7BindingC2Ett, i32 0, i32 0)) #18
  unreachable
                                                  ; No predecessors!
  br label %15

; <label>:15                                      ; preds = %14, %12
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZNK2fp7Context9get_fieldEt(%"struct.fp::Context"* %this, i16 zeroext %off) #0 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i16, align 2
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  store i16 %off, i16* %2, align 2
  %3 = load %"struct.fp::Context"** %1
  %4 = getelementptr inbounds %"struct.fp::Context"* %3, i32 0, i32 0
  %5 = load %"struct.fp::Packet"** %4, align 8
  %6 = call i8* @_ZN2fp6Packet4dataEv(%"struct.fp::Packet"* %5)
  %7 = load i16* %2, align 2
  %8 = zext i16 %7 to i32
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds i8* %6, i64 %9
  ret i8* %10
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZN2fp7Context9get_fieldEt(%"struct.fp::Context"* %this, i16 zeroext %off) #0 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i16, align 2
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  store i16 %off, i16* %2, align 2
  %3 = load %"struct.fp::Context"** %1
  %4 = getelementptr inbounds %"struct.fp::Context"* %3, i32 0, i32 0
  %5 = load %"struct.fp::Packet"** %4, align 8
  %6 = call i8* @_ZN2fp6Packet4dataEv(%"struct.fp::Packet"* %5)
  %7 = load i16* %2, align 2
  %8 = zext i16 %7 to i32
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds i8* %6, i64 %9
  ret i8* %10
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(4) %"struct.fp::Binding"* @_ZNK2fp7Context17get_field_bindingEi(%"struct.fp::Context"* %this, i32 %fld) #4 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  store i32 %fld, i32* %2, align 4
  %3 = load %"struct.fp::Context"** %1
  %4 = getelementptr inbounds %"struct.fp::Context"* %3, i32 0, i32 9
  %5 = load i32* %2, align 4
  %6 = call dereferenceable(20) %"struct.fp::Binding_list"* @_ZNK2fp11EnvironmentixEi(%"struct.fp::Environment"* %4, i32 %5)
  %7 = call dereferenceable(4) %"struct.fp::Binding"* @_ZNK2fp12Binding_list3topEv(%"struct.fp::Binding_list"* %6)
  ret %"struct.fp::Binding"* %7
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(4) %"struct.fp::Binding"* @_ZN2fp7Context17get_field_bindingEi(%"struct.fp::Context"* %this, i32 %fld) #4 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  store i32 %fld, i32* %2, align 4
  %3 = load %"struct.fp::Context"** %1
  %4 = getelementptr inbounds %"struct.fp::Context"* %3, i32 0, i32 9
  %5 = load i32* %2, align 4
  %6 = call dereferenceable(20) %"struct.fp::Binding_list"* @_ZN2fp11EnvironmentixEi(%"struct.fp::Environment"* %4, i32 %5)
  %7 = call dereferenceable(4) %"struct.fp::Binding"* @_ZN2fp12Binding_list3topEv(%"struct.fp::Binding_list"* %6)
  ret %"struct.fp::Binding"* %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN2fp7ContextD2Ev(%"struct.fp::Context"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 7
  call void @_ZN2fp10Action_setD2Ev(%"struct.fp::Action_set"* %3) #8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZN2fp10Action_setD2Ev(%"struct.fp::Action_set"* %this) unnamed_addr #0 align 2 {
  %1 = alloca %"struct.fp::Action_set"*, align 8
  store %"struct.fp::Action_set"* %this, %"struct.fp::Action_set"** %1, align 8
  %2 = load %"struct.fp::Action_set"** %1
  %3 = bitcast %"struct.fp::Action_set"* %2 to %"class.std::vector"*
  call void @_ZNSt6vectorIN2fp6ActionESaIS1_EED2Ev(%"class.std::vector"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Packet"* @_ZNK2fp7Context6packetEv(%"struct.fp::Context"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 0
  %4 = load %"struct.fp::Packet"** %3, align 8
  ret %"struct.fp::Packet"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Packet"* @_ZN2fp7Context6packetEv(%"struct.fp::Context"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 0
  %4 = load %"struct.fp::Packet"** %3, align 8
  ret %"struct.fp::Packet"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) %"struct.fp::Metadata"* @_ZNK2fp7Context8metadataEv(%"struct.fp::Context"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 1
  ret %"struct.fp::Metadata"* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) %"struct.fp::Metadata"* @_ZN2fp7Context8metadataEv(%"struct.fp::Context"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 1
  ret %"struct.fp::Metadata"* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Table"* @_ZNK2fp7Context13current_tableEv(%"struct.fp::Context"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 2
  %4 = getelementptr inbounds %"struct.fp::Context_current"* %3, i32 0, i32 1
  %5 = load %"struct.fp::Table"** %4, align 8
  ret %"struct.fp::Table"* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Flow"* @_ZNK2fp7Context12current_flowEv(%"struct.fp::Context"* %this) #2 align 2 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %this, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 2
  %4 = getelementptr inbounds %"struct.fp::Context_current"* %3, i32 0, i32 2
  %5 = load %"struct.fp::Flow"** %4, align 8
  ret %"struct.fp::Flow"* %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt3absl(i64 %__i) #0 {
  %1 = alloca i64, align 8
  store i64 %__i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = sub i64 0, %2
  %4 = icmp sge i64 %2, 0
  %5 = select i1 %4, i64 %2, i64 %3
  ret i64 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr { i64, i64 } @_ZSt3divll(i64 %__i, i64 %__j) #0 {
  %1 = alloca %struct.ldiv_t, align 8
  %2 = alloca i64, align 8
  %3 = alloca i64, align 8
  store i64 %__i, i64* %2, align 8
  store i64 %__j, i64* %3, align 8
  %4 = load i64* %2, align 8
  %5 = load i64* %3, align 8
  %6 = call { i64, i64 } @ldiv(i64 %4, i64 %5) #1
  %7 = bitcast %struct.ldiv_t* %1 to { i64, i64 }*
  %8 = getelementptr { i64, i64 }* %7, i32 0, i32 0
  %9 = extractvalue { i64, i64 } %6, 0
  store i64 %9, i64* %8, align 1
  %10 = getelementptr { i64, i64 }* %7, i32 0, i32 1
  %11 = extractvalue { i64, i64 } %6, 1
  store i64 %11, i64* %10, align 1
  %12 = bitcast %struct.ldiv_t* %1 to { i64, i64 }*
  %13 = load { i64, i64 }* %12, align 1
  ret { i64, i64 } %13
}

; Function Attrs: nounwind readnone
declare { i64, i64 } @ldiv(i64, i64) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt3absx(i64 %__x) #0 {
  %1 = alloca i64, align 8
  store i64 %__x, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = sub i64 0, %2
  %4 = icmp sge i64 %2, 0
  %5 = select i1 %4, i64 %2, i64 %3
  ret i64 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr { i64, i64 } @_ZN9__gnu_cxx3divExx(i64 %__n, i64 %__d) #0 {
  %1 = alloca %struct.lldiv_t, align 8
  %2 = alloca i64, align 8
  %3 = alloca i64, align 8
  store i64 %__n, i64* %2, align 8
  store i64 %__d, i64* %3, align 8
  %4 = load i64* %2, align 8
  %5 = load i64* %3, align 8
  %6 = sdiv i64 %4, %5
  %7 = getelementptr inbounds %struct.lldiv_t* %1, i32 0, i32 0
  store i64 %6, i64* %7, align 8
  %8 = load i64* %2, align 8
  %9 = load i64* %3, align 8
  %10 = srem i64 %8, %9
  %11 = getelementptr inbounds %struct.lldiv_t* %1, i32 0, i32 1
  store i64 %10, i64* %11, align 8
  %12 = bitcast %struct.lldiv_t* %1 to { i64, i64 }*
  %13 = load { i64, i64 }* %12, align 1
  ret { i64, i64 } %13
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr double @_ZSt3absd(double %__x) #0 {
  %1 = alloca double, align 8
  store double %__x, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call double @llvm.fabs.f64(double %2) #19
  ret double %3
}

; Function Attrs: nounwind readnone
declare double @llvm.fabs.f64(double) #1

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt3absf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @llvm.fabs.f32(float %2) #19
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @llvm.fabs.f32(float) #1

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3abse(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @llvm.fabs.f80(x86_fp80 %2) #19
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @llvm.fabs.f80(x86_fp80) #1

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4acosf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @acosf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @acosf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4acose(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @acosl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @acosl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4asinf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @asinf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @asinf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4asine(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @asinl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @asinl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4atanf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @atanf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @atanf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4atane(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @atanl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @atanl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt5atan2ff(float %__y, float %__x) #0 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__y, float* %1, align 4
  store float %__x, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @atan2f(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @atan2f(float, float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5atan2ee(x86_fp80 %__y, x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__y, x86_fp80* %1, align 16
  store x86_fp80 %__x, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @atan2l(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @atan2l(x86_fp80, x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4ceilf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @ceilf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @ceilf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4ceile(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @ceill(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @ceill(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt3cosf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @cosf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @cosf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3cose(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @cosl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @cosl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4coshf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @coshf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @coshf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4coshe(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @coshl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @coshl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt3expf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @expf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @expf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3expe(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @expl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @expl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4fabsf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @llvm.fabs.f32(float %2) #19
  ret float %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4fabse(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @llvm.fabs.f80(x86_fp80 %2) #19
  ret x86_fp80 %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt5floorf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @floorf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @floorf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5floore(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @floorl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @floorl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4fmodff(float %__x, float %__y) #0 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = frem float %3, %4
  ret float %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4fmodee(x86_fp80 %__x, x86_fp80 %__y) #0 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = frem x86_fp80 %3, %4
  ret x86_fp80 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt5frexpfPi(float %__x, i32* %__exp) #0 {
  %1 = alloca float, align 4
  %2 = alloca i32*, align 8
  store float %__x, float* %1, align 4
  store i32* %__exp, i32** %2, align 8
  %3 = load float* %1, align 4
  %4 = load i32** %2, align 8
  %5 = call float @frexpf(float %3, i32* %4) #8
  ret float %5
}

; Function Attrs: nounwind
declare float @frexpf(float, i32*) #3

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5frexpePi(x86_fp80 %__x, i32* %__exp) #0 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca i32*, align 8
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store i32* %__exp, i32** %2, align 8
  %3 = load x86_fp80* %1, align 16
  %4 = load i32** %2, align 8
  %5 = call x86_fp80 @frexpl(x86_fp80 %3, i32* %4) #8
  ret x86_fp80 %5
}

; Function Attrs: nounwind
declare x86_fp80 @frexpl(x86_fp80, i32*) #3

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt5ldexpfi(float %__x, i32 %__exp) #0 {
  %1 = alloca float, align 4
  %2 = alloca i32, align 4
  store float %__x, float* %1, align 4
  store i32 %__exp, i32* %2, align 4
  %3 = load float* %1, align 4
  %4 = load i32* %2, align 4
  %5 = call float @ldexpf(float %3, i32 %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @ldexpf(float, i32) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5ldexpei(x86_fp80 %__x, i32 %__exp) #0 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca i32, align 4
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store i32 %__exp, i32* %2, align 4
  %3 = load x86_fp80* %1, align 16
  %4 = load i32* %2, align 4
  %5 = call x86_fp80 @ldexpl(x86_fp80 %3, i32 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @ldexpl(x86_fp80, i32) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt3logf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @logf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @logf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3loge(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @logl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @logl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt5log10f(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @log10f(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @log10f(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5log10e(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @log10l(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @log10l(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4modffPf(float %__x, float* %__iptr) #0 {
  %1 = alloca float, align 4
  %2 = alloca float*, align 8
  store float %__x, float* %1, align 4
  store float* %__iptr, float** %2, align 8
  %3 = load float* %1, align 4
  %4 = load float** %2, align 8
  %5 = call float @modff(float %3, float* %4) #8
  ret float %5
}

; Function Attrs: nounwind
declare float @modff(float, float*) #3

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4modfePe(x86_fp80 %__x, x86_fp80* %__iptr) #0 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80*, align 8
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80* %__iptr, x86_fp80** %2, align 8
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80** %2, align 8
  %5 = call x86_fp80 @modfl(x86_fp80 %3, x86_fp80* %4) #8
  ret x86_fp80 %5
}

; Function Attrs: nounwind
declare x86_fp80 @modfl(x86_fp80, x86_fp80*) #3

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt3powff(float %__x, float %__y) #0 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @powf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @powf(float, float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3powee(x86_fp80 %__x, x86_fp80 %__y) #0 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @powl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @powl(x86_fp80, x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt3sinf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @sinf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @sinf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3sine(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @sinl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @sinl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4sinhf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @sinhf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @sinhf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4sinhe(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @sinhl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @sinhl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4sqrtf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @sqrtf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @sqrtf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4sqrte(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @sqrtl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @sqrtl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt3tanf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @tanf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @tanf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3tane(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @tanl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @tanl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt4tanhf(float %__x) #0 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @tanhf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @tanhf(float) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4tanhe(x86_fp80 %__x) #0 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @tanhl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @tanhl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZSt10fpclassifyf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = fcmp oeq float %2, 0.000000e+00
  br i1 %3, label %4, label %6

; <label>:4                                       ; preds = %11, %8, %6, %0
  %5 = phi i32 [ 2, %0 ], [ 0, %6 ], [ 1, %8 ], [ %13, %11 ]
  ret i32 %5

; <label>:6                                       ; preds = %0
  %7 = fcmp uno float %2, %2
  br i1 %7, label %4, label %8

; <label>:8                                       ; preds = %6
  %9 = call float @llvm.fabs.f32(float %2) #19
  %10 = fcmp oeq float %9, 0x7FF0000000000000
  br i1 %10, label %4, label %11

; <label>:11                                      ; preds = %8
  %12 = fcmp uge float %9, 0x3810000000000000
  %13 = select i1 %12, i32 4, i32 3
  br label %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZSt10fpclassifyd(double %__x) #2 {
  %1 = alloca double, align 8
  store double %__x, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = fcmp oeq double %2, 0.000000e+00
  br i1 %3, label %4, label %6

; <label>:4                                       ; preds = %11, %8, %6, %0
  %5 = phi i32 [ 2, %0 ], [ 0, %6 ], [ 1, %8 ], [ %13, %11 ]
  ret i32 %5

; <label>:6                                       ; preds = %0
  %7 = fcmp uno double %2, %2
  br i1 %7, label %4, label %8

; <label>:8                                       ; preds = %6
  %9 = call double @llvm.fabs.f64(double %2) #19
  %10 = fcmp oeq double %9, 0x7FF0000000000000
  br i1 %10, label %4, label %11

; <label>:11                                      ; preds = %8
  %12 = fcmp uge double %9, 0x10000000000000
  %13 = select i1 %12, i32 4, i32 3
  br label %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZSt10fpclassifye(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = fcmp oeq x86_fp80 %2, 0xK00000000000000000000
  br i1 %3, label %4, label %6

; <label>:4                                       ; preds = %11, %8, %6, %0
  %5 = phi i32 [ 2, %0 ], [ 0, %6 ], [ 1, %8 ], [ %13, %11 ]
  ret i32 %5

; <label>:6                                       ; preds = %0
  %7 = fcmp uno x86_fp80 %2, %2
  br i1 %7, label %4, label %8

; <label>:8                                       ; preds = %6
  %9 = call x86_fp80 @llvm.fabs.f80(x86_fp80 %2) #19
  %10 = fcmp oeq x86_fp80 %9, 0xK7FFF8000000000000000
  br i1 %10, label %4, label %11

; <label>:11                                      ; preds = %8
  %12 = fcmp uge x86_fp80 %9, 0xK00018000000000000000
  %13 = select i1 %12, i32 4, i32 3
  br label %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt8isfinitef(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = fcmp oeq float %2, %2
  %4 = call float @llvm.fabs.f32(float %2) #19
  %5 = fcmp une float %4, 0x7FF0000000000000
  %6 = and i1 %3, %5
  ret i1 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt8isfinited(double %__x) #2 {
  %1 = alloca double, align 8
  store double %__x, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = fcmp oeq double %2, %2
  %4 = call double @llvm.fabs.f64(double %2) #19
  %5 = fcmp une double %4, 0x7FF0000000000000
  %6 = and i1 %3, %5
  ret i1 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt8isfinitee(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = fcmp oeq x86_fp80 %2, %2
  %4 = call x86_fp80 @llvm.fabs.f80(x86_fp80 %2) #19
  %5 = fcmp une x86_fp80 %4, 0xK7FFF8000000000000000
  %6 = and i1 %3, %5
  ret i1 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt5isinff(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @llvm.fabs.f32(float %2) #19
  %4 = fcmp oeq float %3, 0x7FF0000000000000
  ret i1 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt5isinfd(double %__x) #2 {
  %1 = alloca double, align 8
  store double %__x, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call double @llvm.fabs.f64(double %2) #19
  %4 = fcmp oeq double %3, 0x7FF0000000000000
  ret i1 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt5isinfe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @llvm.fabs.f80(x86_fp80 %2) #19
  %4 = fcmp oeq x86_fp80 %3, 0xK7FFF8000000000000000
  ret i1 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt5isnanf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = fcmp uno float %2, %2
  ret i1 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt5isnand(double %__x) #2 {
  %1 = alloca double, align 8
  store double %__x, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = fcmp uno double %2, %2
  ret i1 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt5isnane(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = fcmp uno x86_fp80 %2, %2
  ret i1 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt8isnormalf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = fcmp oeq float %2, %2
  %4 = call float @llvm.fabs.f32(float %2) #19
  %5 = fcmp ult float %4, 0x7FF0000000000000
  %6 = fcmp uge float %4, 0x3810000000000000
  %7 = and i1 %3, %5
  %8 = and i1 %7, %6
  ret i1 %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt8isnormald(double %__x) #2 {
  %1 = alloca double, align 8
  store double %__x, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = fcmp oeq double %2, %2
  %4 = call double @llvm.fabs.f64(double %2) #19
  %5 = fcmp ult double %4, 0x7FF0000000000000
  %6 = fcmp uge double %4, 0x10000000000000
  %7 = and i1 %3, %5
  %8 = and i1 %7, %6
  ret i1 %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt8isnormale(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = fcmp oeq x86_fp80 %2, %2
  %4 = call x86_fp80 @llvm.fabs.f80(x86_fp80 %2) #19
  %5 = fcmp ult x86_fp80 %4, 0xK7FFF8000000000000000
  %6 = fcmp uge x86_fp80 %4, 0xK00018000000000000000
  %7 = and i1 %3, %5
  %8 = and i1 %7, %6
  ret i1 %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt7signbitf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = bitcast float %2 to i32
  %4 = icmp slt i32 %3, 0
  ret i1 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt7signbitd(double %__x) #2 {
  %1 = alloca double, align 8
  store double %__x, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = bitcast double %2 to i64
  %4 = icmp slt i64 %3, 0
  ret i1 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt7signbite(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = bitcast x86_fp80 %2 to i80
  %4 = icmp slt i80 %3, 0
  ret i1 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt9isgreaterff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = fpext float %3 to double
  %5 = load float* %2, align 4
  %6 = fpext float %5 to double
  %7 = fcmp ogt double %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt9isgreaterdd(double %__x, double %__y) #2 {
  %1 = alloca double, align 8
  %2 = alloca double, align 8
  store double %__x, double* %1, align 8
  store double %__y, double* %2, align 8
  %3 = load double* %1, align 8
  %4 = load double* %2, align 8
  %5 = fcmp ogt double %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt9isgreateree(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = fcmp ogt x86_fp80 %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt14isgreaterequalff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = fpext float %3 to double
  %5 = load float* %2, align 4
  %6 = fpext float %5 to double
  %7 = fcmp oge double %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt14isgreaterequaldd(double %__x, double %__y) #2 {
  %1 = alloca double, align 8
  %2 = alloca double, align 8
  store double %__x, double* %1, align 8
  store double %__y, double* %2, align 8
  %3 = load double* %1, align 8
  %4 = load double* %2, align 8
  %5 = fcmp oge double %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt14isgreaterequalee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = fcmp oge x86_fp80 %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt6islessff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = fpext float %3 to double
  %5 = load float* %2, align 4
  %6 = fpext float %5 to double
  %7 = fcmp olt double %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt6islessdd(double %__x, double %__y) #2 {
  %1 = alloca double, align 8
  %2 = alloca double, align 8
  store double %__x, double* %1, align 8
  store double %__y, double* %2, align 8
  %3 = load double* %1, align 8
  %4 = load double* %2, align 8
  %5 = fcmp olt double %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt6islessee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = fcmp olt x86_fp80 %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt11islessequalff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = fpext float %3 to double
  %5 = load float* %2, align 4
  %6 = fpext float %5 to double
  %7 = fcmp ole double %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt11islessequaldd(double %__x, double %__y) #2 {
  %1 = alloca double, align 8
  %2 = alloca double, align 8
  store double %__x, double* %1, align 8
  store double %__y, double* %2, align 8
  %3 = load double* %1, align 8
  %4 = load double* %2, align 8
  %5 = fcmp ole double %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt11islessequalee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = fcmp ole x86_fp80 %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt13islessgreaterff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = fpext float %3 to double
  %5 = load float* %2, align 4
  %6 = fpext float %5 to double
  %7 = fcmp one double %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt13islessgreaterdd(double %__x, double %__y) #2 {
  %1 = alloca double, align 8
  %2 = alloca double, align 8
  store double %__x, double* %1, align 8
  store double %__y, double* %2, align 8
  %3 = load double* %1, align 8
  %4 = load double* %2, align 8
  %5 = fcmp one double %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt13islessgreateree(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = fcmp one x86_fp80 %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt11isunorderedff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = fpext float %3 to double
  %5 = load float* %2, align 4
  %6 = fpext float %5 to double
  %7 = fcmp uno double %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt11isunordereddd(double %__x, double %__y) #2 {
  %1 = alloca double, align 8
  %2 = alloca double, align 8
  store double %__x, double* %1, align 8
  store double %__y, double* %2, align 8
  %3 = load double* %1, align 8
  %4 = load double* %2, align 8
  %5 = fcmp uno double %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSt11isunorderedee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = fcmp uno x86_fp80 %3, %4
  ret i1 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5acoshf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @acoshf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @acoshf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5acoshe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @acoshl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @acoshl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5asinhf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @asinhf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @asinhf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5asinhe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @asinhl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @asinhl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5atanhf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @atanhf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @atanhf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5atanhe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @atanhl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @atanhl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4cbrtf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @cbrtf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @cbrtf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4cbrte(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @cbrtl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @cbrtl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt8copysignff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @copysignf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @copysignf(float, float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt8copysignee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @copysignl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @copysignl(x86_fp80, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt3erff(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @erff(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @erff(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3erfe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @erfl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @erfl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4erfcf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @erfcf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @erfcf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4erfce(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @erfcl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @erfcl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4exp2f(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @exp2f(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @exp2f(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4exp2e(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @exp2l(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @exp2l(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5expm1f(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @expm1f(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @expm1f(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5expm1e(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @expm1l(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @expm1l(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4fdimff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @fdimf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @fdimf(float, float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4fdimee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @fdiml(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @fdiml(x86_fp80, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt3fmafff(float %__x, float %__y, float %__z) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  %3 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  store float %__z, float* %3, align 4
  %4 = load float* %1, align 4
  %5 = load float* %3, align 4
  %6 = load float* %2, align 4
  %7 = call float @llvm.fma.f32(float %4, float %6, float %5)
  ret float %7
}

; Function Attrs: nounwind readnone
declare float @llvm.fma.f32(float, float, float) #1

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt3fmaeee(x86_fp80 %__x, x86_fp80 %__y, x86_fp80 %__z) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  %3 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  store x86_fp80 %__z, x86_fp80* %3, align 16
  %4 = load x86_fp80* %1, align 16
  %5 = load x86_fp80* %3, align 16
  %6 = load x86_fp80* %2, align 16
  %7 = call x86_fp80 @llvm.fma.f80(x86_fp80 %4, x86_fp80 %6, x86_fp80 %5)
  ret x86_fp80 %7
}

; Function Attrs: nounwind readnone
declare x86_fp80 @llvm.fma.f80(x86_fp80, x86_fp80, x86_fp80) #1

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4fmaxff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @fmaxf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @fmaxf(float, float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4fmaxee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @fmaxl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @fmaxl(x86_fp80, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4fminff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @fminf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @fminf(float, float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4fminee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @fminl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @fminl(x86_fp80, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5hypotff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @hypotf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @hypotf(float, float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5hypotee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @hypotl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @hypotl(x86_fp80, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZSt5ilogbf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call i32 @ilogbf(float %2) #1
  ret i32 %3
}

; Function Attrs: nounwind readnone
declare i32 @ilogbf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZSt5ilogbe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call i32 @ilogbl(x86_fp80 %2) #1
  ret i32 %3
}

; Function Attrs: nounwind readnone
declare i32 @ilogbl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt6lgammaf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @lgammaf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @lgammaf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt6lgammae(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @lgammal(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @lgammal(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt6llrintf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call i64 @llrintf(float %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @llrintf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt6llrinte(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call i64 @llrintl(x86_fp80 %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @llrintl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt7llroundf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call i64 @llroundf(float %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @llroundf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt7llrounde(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call i64 @llroundl(x86_fp80 %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @llroundl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5log1pf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @log1pf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @log1pf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5log1pe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @log1pl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @log1pl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4log2f(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @log2f(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @log2f(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4log2e(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @log2l(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @log2l(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4logbf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @logbf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @logbf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4logbe(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @logbl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @logbl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt5lrintf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call i64 @lrintf(float %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @lrintf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt5lrinte(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call i64 @lrintl(x86_fp80 %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @lrintl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt6lroundf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call i64 @lroundf(float %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @lroundf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZSt6lrounde(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call i64 @lroundl(x86_fp80 %2) #1
  ret i64 %3
}

; Function Attrs: nounwind readnone
declare i64 @lroundl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt9nearbyintf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @nearbyintf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @nearbyintf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt9nearbyinte(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @nearbyintl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @nearbyintl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt9nextafterff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @nextafterf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @nextafterf(float, float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt9nextafteree(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @nextafterl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @nextafterl(x86_fp80, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt10nexttowardfe(float %__x, x86_fp80 %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca x86_fp80, align 16
  store float %__x, float* %1, align 4
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load float* %1, align 4
  %4 = load x86_fp80* %2, align 16
  %5 = call float @nexttowardf(float %3, x86_fp80 %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @nexttowardf(float, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt10nexttowardee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @nexttowardl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @nexttowardl(x86_fp80, x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt9remainderff(float %__x, float %__y) #2 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  %3 = load float* %1, align 4
  %4 = load float* %2, align 4
  %5 = call float @remainderf(float %3, float %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @remainderf(float, float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt9remainderee(x86_fp80 %__x, x86_fp80 %__y) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  %3 = load x86_fp80* %1, align 16
  %4 = load x86_fp80* %2, align 16
  %5 = call x86_fp80 @remainderl(x86_fp80 %3, x86_fp80 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @remainderl(x86_fp80, x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr float @_ZSt6remquoffPi(float %__x, float %__y, i32* %__pquo) #0 {
  %1 = alloca float, align 4
  %2 = alloca float, align 4
  %3 = alloca i32*, align 8
  store float %__x, float* %1, align 4
  store float %__y, float* %2, align 4
  store i32* %__pquo, i32** %3, align 8
  %4 = load float* %1, align 4
  %5 = load float* %2, align 4
  %6 = load i32** %3, align 8
  %7 = call float @remquof(float %4, float %5, i32* %6) #8
  ret float %7
}

; Function Attrs: nounwind
declare float @remquof(float, float, i32*) #3

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt6remquoeePi(x86_fp80 %__x, x86_fp80 %__y, i32* %__pquo) #0 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca x86_fp80, align 16
  %3 = alloca i32*, align 8
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store x86_fp80 %__y, x86_fp80* %2, align 16
  store i32* %__pquo, i32** %3, align 8
  %4 = load x86_fp80* %1, align 16
  %5 = load x86_fp80* %2, align 16
  %6 = load i32** %3, align 8
  %7 = call x86_fp80 @remquol(x86_fp80 %4, x86_fp80 %5, i32* %6) #8
  ret x86_fp80 %7
}

; Function Attrs: nounwind
declare x86_fp80 @remquol(x86_fp80, x86_fp80, i32*) #3

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt4rintf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @rintf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @rintf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt4rinte(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @rintl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @rintl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5roundf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @roundf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @roundf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5rounde(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @roundl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @roundl(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt7scalblnfl(float %__x, i64 %__ex) #2 {
  %1 = alloca float, align 4
  %2 = alloca i64, align 8
  store float %__x, float* %1, align 4
  store i64 %__ex, i64* %2, align 8
  %3 = load float* %1, align 4
  %4 = load i64* %2, align 8
  %5 = call float @scalblnf(float %3, i64 %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @scalblnf(float, i64) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt7scalblnel(x86_fp80 %__x, i64 %__ex) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca i64, align 8
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store i64 %__ex, i64* %2, align 8
  %3 = load x86_fp80* %1, align 16
  %4 = load i64* %2, align 8
  %5 = call x86_fp80 @scalblnl(x86_fp80 %3, i64 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @scalblnl(x86_fp80, i64) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt6scalbnfi(float %__x, i32 %__ex) #2 {
  %1 = alloca float, align 4
  %2 = alloca i32, align 4
  store float %__x, float* %1, align 4
  store i32 %__ex, i32* %2, align 4
  %3 = load float* %1, align 4
  %4 = load i32* %2, align 4
  %5 = call float @scalbnf(float %3, i32 %4) #1
  ret float %5
}

; Function Attrs: nounwind readnone
declare float @scalbnf(float, i32) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt6scalbnei(x86_fp80 %__x, i32 %__ex) #2 {
  %1 = alloca x86_fp80, align 16
  %2 = alloca i32, align 4
  store x86_fp80 %__x, x86_fp80* %1, align 16
  store i32 %__ex, i32* %2, align 4
  %3 = load x86_fp80* %1, align 16
  %4 = load i32* %2, align 4
  %5 = call x86_fp80 @scalbnl(x86_fp80 %3, i32 %4) #1
  ret x86_fp80 %5
}

; Function Attrs: nounwind readnone
declare x86_fp80 @scalbnl(x86_fp80, i32) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt6tgammaf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @tgammaf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @tgammaf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt6tgammae(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @tgammal(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @tgammal(x86_fp80) #12

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZSt5truncf(float %__x) #2 {
  %1 = alloca float, align 4
  store float %__x, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = call float @truncf(float %2) #1
  ret float %3
}

; Function Attrs: nounwind readnone
declare float @truncf(float) #12

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZSt5trunce(x86_fp80 %__x) #2 {
  %1 = alloca x86_fp80, align 16
  store x86_fp80 %__x, x86_fp80* %1, align 16
  %2 = load x86_fp80* %1, align 16
  %3 = call x86_fp80 @truncl(x86_fp80 %2) #1
  ret x86_fp80 %3
}

; Function Attrs: nounwind readnone
declare x86_fp80 @truncl(x86_fp80) #12

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32* @_ZSt6wcschrPww(i32* %__p, i32 signext %__c) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__p, i32** %1, align 8
  store i32 %__c, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %2, align 4
  %5 = call i32* @wcschr(i32* %3, i32 signext %4) #20
  ret i32* %5
}

; Function Attrs: nounwind readonly
declare i32* @wcschr(i32*, i32 signext) #13

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32* @_ZSt7wcspbrkPwPKw(i32* %__s1, i32* %__s2) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__s1, i32** %1, align 8
  store i32* %__s2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32** %2, align 8
  %5 = call i32* @wcspbrk(i32* %3, i32* %4) #20
  ret i32* %5
}

; Function Attrs: nounwind readonly
declare i32* @wcspbrk(i32*, i32*) #13

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32* @_ZSt7wcsrchrPww(i32* %__p, i32 signext %__c) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__p, i32** %1, align 8
  store i32 %__c, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %2, align 4
  %5 = call i32* @wcsrchr(i32* %3, i32 signext %4) #20
  ret i32* %5
}

; Function Attrs: nounwind readonly
declare i32* @wcsrchr(i32*, i32 signext) #13

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32* @_ZSt6wcsstrPwPKw(i32* %__s1, i32* %__s2) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__s1, i32** %1, align 8
  store i32* %__s2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32** %2, align 8
  %5 = call i32* @wcsstr(i32* %3, i32* %4) #20
  ret i32* %5
}

; Function Attrs: nounwind readonly
declare i32* @wcsstr(i32*, i32*) #13

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32* @_ZSt7wmemchrPwwm(i32* %__p, i32 signext %__c, i64 %__n) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i64, align 8
  store i32* %__p, i32** %1, align 8
  store i32 %__c, i32* %2, align 4
  store i64 %__n, i64* %3, align 8
  %4 = load i32** %1, align 8
  %5 = load i32* %2, align 4
  %6 = load i64* %3, align 8
  %7 = call i32* @wmemchr(i32* %4, i32 signext %5, i64 %6) #20
  ret i32* %7
}

; Function Attrs: nounwind readonly
declare i32* @wmemchr(i32*, i32 signext, i64) #13

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt11char_traitsIcE6assignERcRKc(i8* dereferenceable(1) %__c1, i8* dereferenceable(1) %__c2) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  store i8* %__c1, i8** %1, align 8
  store i8* %__c2, i8** %2, align 8
  %3 = load i8** %2, align 8
  %4 = load i8* %3, align 1
  %5 = load i8** %1, align 8
  store i8 %4, i8* %5, align 1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIcE2eqERKcS2_(i8* dereferenceable(1) %__c1, i8* dereferenceable(1) %__c2) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  store i8* %__c1, i8** %1, align 8
  store i8* %__c2, i8** %2, align 8
  %3 = load i8** %1, align 8
  %4 = load i8* %3, align 1
  %5 = sext i8 %4 to i32
  %6 = load i8** %2, align 8
  %7 = load i8* %6, align 1
  %8 = sext i8 %7 to i32
  %9 = icmp eq i32 %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIcE2ltERKcS2_(i8* dereferenceable(1) %__c1, i8* dereferenceable(1) %__c2) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  store i8* %__c1, i8** %1, align 8
  store i8* %__c2, i8** %2, align 8
  %3 = load i8** %1, align 8
  %4 = load i8* %3, align 1
  %5 = zext i8 %4 to i32
  %6 = load i8** %2, align 8
  %7 = load i8* %6, align 1
  %8 = zext i8 %7 to i32
  %9 = icmp slt i32 %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIcE7compareEPKcS2_m(i8* %__s1, i8* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i64, align 8
  store i8* %__s1, i8** %1, align 8
  store i8* %__s2, i8** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i8** %1, align 8
  %5 = load i8** %2, align 8
  %6 = load i64* %3, align 8
  %7 = call i32 @memcmp(i8* %4, i8* %5, i64 %6) #8
  ret i32 %7
}

; Function Attrs: nounwind
declare i32 @memcmp(i8*, i8*, i64) #3

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt11char_traitsIcE6lengthEPKc(i8* %__s) #2 align 2 {
  %1 = alloca i8*, align 8
  store i8* %__s, i8** %1, align 8
  %2 = load i8** %1, align 8
  %3 = call i64 @strlen(i8* %2) #8
  ret i64 %3
}

; Function Attrs: nounwind
declare i64 @strlen(i8*) #3

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNSt11char_traitsIcE4findEPKcmRS1_(i8* %__s, i64 %__n, i8* dereferenceable(1) %__a) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i8*, align 8
  store i8* %__s, i8** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i8* %__a, i8** %3, align 8
  %4 = load i8** %1, align 8
  %5 = load i8** %3, align 8
  %6 = load i8* %5, align 1
  %7 = sext i8 %6 to i32
  %8 = load i64* %2, align 8
  %9 = call i8* @memchr(i8* %4, i32 %7, i64 %8) #8
  ret i8* %9
}

; Function Attrs: nounwind
declare i8* @memchr(i8*, i32, i64) #3

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNSt11char_traitsIcE4moveEPcPKcm(i8* %__s1, i8* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i64, align 8
  store i8* %__s1, i8** %1, align 8
  store i8* %__s2, i8** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i8** %1, align 8
  %5 = load i8** %2, align 8
  %6 = load i64* %3, align 8
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %4, i8* %5, i64 %6, i32 1, i1 false)
  ret i8* %4
}

; Function Attrs: nounwind
declare void @llvm.memmove.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #8

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNSt11char_traitsIcE4copyEPcPKcm(i8* %__s1, i8* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i64, align 8
  store i8* %__s1, i8** %1, align 8
  store i8* %__s2, i8** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i8** %1, align 8
  %5 = load i8** %2, align 8
  %6 = load i64* %3, align 8
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %4, i8* %5, i64 %6, i32 1, i1 false)
  ret i8* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNSt11char_traitsIcE6assignEPcmc(i8* %__s, i64 %__n, i8 signext %__a) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i8, align 1
  store i8* %__s, i8** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i8 %__a, i8* %3, align 1
  %4 = load i8** %1, align 8
  %5 = load i8* %3, align 1
  %6 = sext i8 %5 to i32
  %7 = trunc i32 %6 to i8
  %8 = load i64* %2, align 8
  call void @llvm.memset.p0i8.i64(i8* %4, i8 %7, i64 %8, i32 1, i1 false)
  ret i8* %4
}

; Function Attrs: nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #8

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt11char_traitsIcE12to_char_typeERKi(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  store i32* %__c, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = load i32* %2, align 4
  %4 = trunc i32 %3 to i8
  ret i8 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIcE11to_int_typeERKc(i8* dereferenceable(1) %__c) #2 align 2 {
  %1 = alloca i8*, align 8
  store i8* %__c, i8** %1, align 8
  %2 = load i8** %1, align 8
  %3 = load i8* %2, align 1
  %4 = zext i8 %3 to i32
  ret i32 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIcE11eq_int_typeERKiS2_(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %2, align 8
  %6 = load i32* %5, align 4
  %7 = icmp eq i32 %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIcE3eofEv() #2 align 2 {
  ret i32 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIcE7not_eofERKi(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  store i32* %__c, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = load i32* %2, align 4
  %4 = call i32 @_ZNSt11char_traitsIcE3eofEv() #8
  %5 = icmp eq i32 %3, %4
  br i1 %5, label %6, label %7

; <label>:6                                       ; preds = %0
  br label %10

; <label>:7                                       ; preds = %0
  %8 = load i32** %1, align 8
  %9 = load i32* %8, align 4
  br label %10

; <label>:10                                      ; preds = %7, %6
  %11 = phi i32 [ 0, %6 ], [ %9, %7 ]
  ret i32 %11
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt11char_traitsIwE6assignERwRKw(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %2, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %1, align 8
  store i32 %4, i32* %5, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIwE2eqERKwS2_(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %2, align 8
  %6 = load i32* %5, align 4
  %7 = icmp eq i32 %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIwE2ltERKwS2_(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %2, align 8
  %6 = load i32* %5, align 4
  %7 = icmp slt i32 %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIwE7compareEPKwS2_m(i32* %__s1, i32* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  store i32* %__s1, i32** %1, align 8
  store i32* %__s2, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i32** %1, align 8
  %5 = load i32** %2, align 8
  %6 = load i64* %3, align 8
  %7 = call i32 @wmemcmp(i32* %4, i32* %5, i64 %6) #20
  ret i32 %7
}

; Function Attrs: nounwind readonly
declare i32 @wmemcmp(i32*, i32*, i64) #13

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt11char_traitsIwE6lengthEPKw(i32* %__s) #2 align 2 {
  %1 = alloca i32*, align 8
  store i32* %__s, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = call i64 @wcslen(i32* %2) #20
  ret i64 %3
}

; Function Attrs: nounwind readonly
declare i64 @wcslen(i32*) #13

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIwE4findEPKwmRS1_(i32* %__s, i64 %__n, i32* dereferenceable(4) %__a) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i32*, align 8
  store i32* %__s, i32** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i32* %__a, i32** %3, align 8
  %4 = load i32** %1, align 8
  %5 = load i32** %3, align 8
  %6 = load i32* %5, align 4
  %7 = load i64* %2, align 8
  %8 = call i32* @wmemchr(i32* %4, i32 signext %6, i64 %7) #20
  ret i32* %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIwE4moveEPwPKwm(i32* %__s1, i32* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  store i32* %__s1, i32** %1, align 8
  store i32* %__s2, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i32** %1, align 8
  %5 = load i32** %2, align 8
  %6 = load i64* %3, align 8
  %7 = call i32* @wmemmove(i32* %4, i32* %5, i64 %6) #8
  ret i32* %7
}

; Function Attrs: nounwind
declare i32* @wmemmove(i32*, i32*, i64) #3

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIwE4copyEPwPKwm(i32* %__s1, i32* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  store i32* %__s1, i32** %1, align 8
  store i32* %__s2, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i32** %1, align 8
  %5 = load i32** %2, align 8
  %6 = load i64* %3, align 8
  %7 = call i32* @wmemcpy(i32* %4, i32* %5, i64 %6) #8
  ret i32* %7
}

; Function Attrs: nounwind
declare i32* @wmemcpy(i32*, i32*, i64) #3

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIwE6assignEPwmw(i32* %__s, i64 %__n, i32 signext %__a) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i32, align 4
  store i32* %__s, i32** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i32 %__a, i32* %3, align 4
  %4 = load i32** %1, align 8
  %5 = load i32* %3, align 4
  %6 = load i64* %2, align 8
  %7 = call i32* @wmemset(i32* %4, i32 signext %5, i64 %6) #8
  ret i32* %7
}

; Function Attrs: nounwind
declare i32* @wmemset(i32*, i32 signext, i64) #3

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt11char_traitsIwE12to_char_typeERKj(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  store i32* %__c, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = load i32* %2, align 4
  ret i32 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIwE11to_int_typeERKw(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  store i32* %__c, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = load i32* %2, align 4
  ret i32 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIwE11eq_int_typeERKjS2_(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %2, align 8
  %6 = load i32* %5, align 4
  %7 = icmp eq i32 %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIwE3eofEv() #2 align 2 {
  ret i32 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIwE7not_eofERKj(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__c, i32** %1, align 8
  %3 = load i32** %1, align 8
  %4 = call i32 @_ZNSt11char_traitsIwE3eofEv() #8
  store i32 %4, i32* %2
  %5 = call zeroext i1 @_ZNSt11char_traitsIwE11eq_int_typeERKjS2_(i32* dereferenceable(4) %3, i32* dereferenceable(4) %2) #8
  br i1 %5, label %6, label %7

; <label>:6                                       ; preds = %0
  br label %10

; <label>:7                                       ; preds = %0
  %8 = load i32** %1, align 8
  %9 = load i32* %8, align 4
  br label %10

; <label>:10                                      ; preds = %7, %6
  %11 = phi i32 [ 0, %6 ], [ %9, %7 ]
  ret i32 %11
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt11char_traitsIDsE6assignERDsRKDs(i16* dereferenceable(2) %__c1, i16* dereferenceable(2) %__c2) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16*, align 8
  store i16* %__c1, i16** %1, align 8
  store i16* %__c2, i16** %2, align 8
  %3 = load i16** %2, align 8
  %4 = load i16* %3, align 2
  %5 = load i16** %1, align 8
  store i16 %4, i16* %5, align 2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIDsE2eqERKDsS2_(i16* dereferenceable(2) %__c1, i16* dereferenceable(2) %__c2) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16*, align 8
  store i16* %__c1, i16** %1, align 8
  store i16* %__c2, i16** %2, align 8
  %3 = load i16** %1, align 8
  %4 = load i16* %3, align 2
  %5 = zext i16 %4 to i32
  %6 = load i16** %2, align 8
  %7 = load i16* %6, align 2
  %8 = zext i16 %7 to i32
  %9 = icmp eq i32 %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIDsE2ltERKDsS2_(i16* dereferenceable(2) %__c1, i16* dereferenceable(2) %__c2) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16*, align 8
  store i16* %__c1, i16** %1, align 8
  store i16* %__c2, i16** %2, align 8
  %3 = load i16** %1, align 8
  %4 = load i16* %3, align 2
  %5 = zext i16 %4 to i32
  %6 = load i16** %2, align 8
  %7 = load i16* %6, align 2
  %8 = zext i16 %7 to i32
  %9 = icmp slt i32 %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIDsE7compareEPKDsS2_m(i16* %__s1, i16* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i32, align 4
  %2 = alloca i16*, align 8
  %3 = alloca i16*, align 8
  %4 = alloca i64, align 8
  %__i = alloca i64, align 8
  store i16* %__s1, i16** %2, align 8
  store i16* %__s2, i16** %3, align 8
  store i64 %__n, i64* %4, align 8
  store i64 0, i64* %__i, align 8
  br label %5

; <label>:5                                       ; preds = %29, %0
  %6 = load i64* %__i, align 8
  %7 = load i64* %4, align 8
  %8 = icmp ult i64 %6, %7
  br i1 %8, label %9, label %32

; <label>:9                                       ; preds = %5
  %10 = load i64* %__i, align 8
  %11 = load i16** %2, align 8
  %12 = getelementptr inbounds i16* %11, i64 %10
  %13 = load i64* %__i, align 8
  %14 = load i16** %3, align 8
  %15 = getelementptr inbounds i16* %14, i64 %13
  %16 = call zeroext i1 @_ZNSt11char_traitsIDsE2ltERKDsS2_(i16* dereferenceable(2) %12, i16* dereferenceable(2) %15) #8
  br i1 %16, label %17, label %18

; <label>:17                                      ; preds = %9
  store i32 -1, i32* %1
  br label %33

; <label>:18                                      ; preds = %9
  %19 = load i64* %__i, align 8
  %20 = load i16** %3, align 8
  %21 = getelementptr inbounds i16* %20, i64 %19
  %22 = load i64* %__i, align 8
  %23 = load i16** %2, align 8
  %24 = getelementptr inbounds i16* %23, i64 %22
  %25 = call zeroext i1 @_ZNSt11char_traitsIDsE2ltERKDsS2_(i16* dereferenceable(2) %21, i16* dereferenceable(2) %24) #8
  br i1 %25, label %26, label %27

; <label>:26                                      ; preds = %18
  store i32 1, i32* %1
  br label %33

; <label>:27                                      ; preds = %18
  br label %28

; <label>:28                                      ; preds = %27
  br label %29

; <label>:29                                      ; preds = %28
  %30 = load i64* %__i, align 8
  %31 = add i64 %30, 1
  store i64 %31, i64* %__i, align 8
  br label %5

; <label>:32                                      ; preds = %5
  store i32 0, i32* %1
  br label %33

; <label>:33                                      ; preds = %32, %26, %17
  %34 = load i32* %1
  ret i32 %34
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt11char_traitsIDsE6lengthEPKDs(i16* %__s) #2 align 2 {
  %1 = alloca i16*, align 8
  %__i = alloca i64, align 8
  %2 = alloca i16, align 2
  store i16* %__s, i16** %1, align 8
  store i64 0, i64* %__i, align 8
  br label %3

; <label>:3                                       ; preds = %9, %0
  %4 = load i64* %__i, align 8
  %5 = load i16** %1, align 8
  %6 = getelementptr inbounds i16* %5, i64 %4
  store i16 0, i16* %2
  %7 = call zeroext i1 @_ZNSt11char_traitsIDsE2eqERKDsS2_(i16* dereferenceable(2) %6, i16* dereferenceable(2) %2) #8
  %8 = xor i1 %7, true
  br i1 %8, label %9, label %12

; <label>:9                                       ; preds = %3
  %10 = load i64* %__i, align 8
  %11 = add i64 %10, 1
  store i64 %11, i64* %__i, align 8
  br label %3

; <label>:12                                      ; preds = %3
  %13 = load i64* %__i, align 8
  ret i64 %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr i16* @_ZNSt11char_traitsIDsE4findEPKDsmRS1_(i16* %__s, i64 %__n, i16* dereferenceable(2) %__a) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16*, align 8
  %3 = alloca i64, align 8
  %4 = alloca i16*, align 8
  %__i = alloca i64, align 8
  store i16* %__s, i16** %2, align 8
  store i64 %__n, i64* %3, align 8
  store i16* %__a, i16** %4, align 8
  store i64 0, i64* %__i, align 8
  br label %5

; <label>:5                                       ; preds = %20, %0
  %6 = load i64* %__i, align 8
  %7 = load i64* %3, align 8
  %8 = icmp ult i64 %6, %7
  br i1 %8, label %9, label %23

; <label>:9                                       ; preds = %5
  %10 = load i64* %__i, align 8
  %11 = load i16** %2, align 8
  %12 = getelementptr inbounds i16* %11, i64 %10
  %13 = load i16** %4, align 8
  %14 = call zeroext i1 @_ZNSt11char_traitsIDsE2eqERKDsS2_(i16* dereferenceable(2) %12, i16* dereferenceable(2) %13) #8
  br i1 %14, label %15, label %19

; <label>:15                                      ; preds = %9
  %16 = load i16** %2, align 8
  %17 = load i64* %__i, align 8
  %18 = getelementptr inbounds i16* %16, i64 %17
  store i16* %18, i16** %1
  br label %24

; <label>:19                                      ; preds = %9
  br label %20

; <label>:20                                      ; preds = %19
  %21 = load i64* %__i, align 8
  %22 = add i64 %21, 1
  store i64 %22, i64* %__i, align 8
  br label %5

; <label>:23                                      ; preds = %5
  store i16* null, i16** %1
  br label %24

; <label>:24                                      ; preds = %23, %15
  %25 = load i16** %1
  ret i16* %25
}

; Function Attrs: nounwind uwtable
define linkonce_odr i16* @_ZNSt11char_traitsIDsE4moveEPDsPKDsm(i16* %__s1, i16* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16*, align 8
  %3 = alloca i64, align 8
  store i16* %__s1, i16** %1, align 8
  store i16* %__s2, i16** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i16** %1, align 8
  %5 = bitcast i16* %4 to i8*
  %6 = load i16** %2, align 8
  %7 = bitcast i16* %6 to i8*
  %8 = load i64* %3, align 8
  %9 = mul i64 %8, 2
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %5, i8* %7, i64 %9, i32 2, i1 false)
  %10 = bitcast i8* %5 to i16*
  ret i16* %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr i16* @_ZNSt11char_traitsIDsE4copyEPDsPKDsm(i16* %__s1, i16* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16*, align 8
  %3 = alloca i64, align 8
  store i16* %__s1, i16** %1, align 8
  store i16* %__s2, i16** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i16** %1, align 8
  %5 = bitcast i16* %4 to i8*
  %6 = load i16** %2, align 8
  %7 = bitcast i16* %6 to i8*
  %8 = load i64* %3, align 8
  %9 = mul i64 %8, 2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %5, i8* %7, i64 %9, i32 2, i1 false)
  %10 = bitcast i8* %5 to i16*
  ret i16* %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr i16* @_ZNSt11char_traitsIDsE6assignEPDsmDs(i16* %__s, i64 %__n, i16 zeroext %__a) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i16, align 2
  %__i = alloca i64, align 8
  store i16* %__s, i16** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i16 %__a, i16* %3, align 2
  store i64 0, i64* %__i, align 8
  br label %4

; <label>:4                                       ; preds = %12, %0
  %5 = load i64* %__i, align 8
  %6 = load i64* %2, align 8
  %7 = icmp ult i64 %5, %6
  br i1 %7, label %8, label %15

; <label>:8                                       ; preds = %4
  %9 = load i64* %__i, align 8
  %10 = load i16** %1, align 8
  %11 = getelementptr inbounds i16* %10, i64 %9
  call void @_ZNSt11char_traitsIDsE6assignERDsRKDs(i16* dereferenceable(2) %11, i16* dereferenceable(2) %3) #8
  br label %12

; <label>:12                                      ; preds = %8
  %13 = load i64* %__i, align 8
  %14 = add i64 %13, 1
  store i64 %14, i64* %__i, align 8
  br label %4

; <label>:15                                      ; preds = %4
  %16 = load i16** %1, align 8
  ret i16* %16
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt11char_traitsIDsE12to_char_typeERKt(i16* dereferenceable(2) %__c) #2 align 2 {
  %1 = alloca i16*, align 8
  store i16* %__c, i16** %1, align 8
  %2 = load i16** %1, align 8
  %3 = load i16* %2, align 2
  ret i16 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt11char_traitsIDsE11to_int_typeERKDs(i16* dereferenceable(2) %__c) #2 align 2 {
  %1 = alloca i16*, align 8
  store i16* %__c, i16** %1, align 8
  %2 = load i16** %1, align 8
  %3 = load i16* %2, align 2
  ret i16 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIDsE11eq_int_typeERKtS2_(i16* dereferenceable(2) %__c1, i16* dereferenceable(2) %__c2) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16*, align 8
  store i16* %__c1, i16** %1, align 8
  store i16* %__c2, i16** %2, align 8
  %3 = load i16** %1, align 8
  %4 = load i16* %3, align 2
  %5 = zext i16 %4 to i32
  %6 = load i16** %2, align 8
  %7 = load i16* %6, align 2
  %8 = zext i16 %7 to i32
  %9 = icmp eq i32 %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt11char_traitsIDsE3eofEv() #2 align 2 {
  ret i16 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt11char_traitsIDsE7not_eofERKt(i16* dereferenceable(2) %__c) #2 align 2 {
  %1 = alloca i16*, align 8
  %2 = alloca i16, align 2
  store i16* %__c, i16** %1, align 8
  %3 = load i16** %1, align 8
  %4 = call zeroext i16 @_ZNSt11char_traitsIDsE3eofEv() #8
  store i16 %4, i16* %2
  %5 = call zeroext i1 @_ZNSt11char_traitsIDsE11eq_int_typeERKtS2_(i16* dereferenceable(2) %3, i16* dereferenceable(2) %2) #8
  br i1 %5, label %6, label %7

; <label>:6                                       ; preds = %0
  br label %11

; <label>:7                                       ; preds = %0
  %8 = load i16** %1, align 8
  %9 = load i16* %8, align 2
  %10 = zext i16 %9 to i32
  br label %11

; <label>:11                                      ; preds = %7, %6
  %12 = phi i32 [ 0, %6 ], [ %10, %7 ]
  %13 = trunc i32 %12 to i16
  ret i16 %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt11char_traitsIDiE6assignERDiRKDi(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %2, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %1, align 8
  store i32 %4, i32* %5, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIDiE2eqERKDiS2_(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %2, align 8
  %6 = load i32* %5, align 4
  %7 = icmp eq i32 %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIDiE2ltERKDiS2_(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %2, align 8
  %6 = load i32* %5, align 4
  %7 = icmp ult i32 %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIDiE7compareEPKDiS2_m(i32* %__s1, i32* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64, align 8
  %__i = alloca i64, align 8
  store i32* %__s1, i32** %2, align 8
  store i32* %__s2, i32** %3, align 8
  store i64 %__n, i64* %4, align 8
  store i64 0, i64* %__i, align 8
  br label %5

; <label>:5                                       ; preds = %29, %0
  %6 = load i64* %__i, align 8
  %7 = load i64* %4, align 8
  %8 = icmp ult i64 %6, %7
  br i1 %8, label %9, label %32

; <label>:9                                       ; preds = %5
  %10 = load i64* %__i, align 8
  %11 = load i32** %2, align 8
  %12 = getelementptr inbounds i32* %11, i64 %10
  %13 = load i64* %__i, align 8
  %14 = load i32** %3, align 8
  %15 = getelementptr inbounds i32* %14, i64 %13
  %16 = call zeroext i1 @_ZNSt11char_traitsIDiE2ltERKDiS2_(i32* dereferenceable(4) %12, i32* dereferenceable(4) %15) #8
  br i1 %16, label %17, label %18

; <label>:17                                      ; preds = %9
  store i32 -1, i32* %1
  br label %33

; <label>:18                                      ; preds = %9
  %19 = load i64* %__i, align 8
  %20 = load i32** %3, align 8
  %21 = getelementptr inbounds i32* %20, i64 %19
  %22 = load i64* %__i, align 8
  %23 = load i32** %2, align 8
  %24 = getelementptr inbounds i32* %23, i64 %22
  %25 = call zeroext i1 @_ZNSt11char_traitsIDiE2ltERKDiS2_(i32* dereferenceable(4) %21, i32* dereferenceable(4) %24) #8
  br i1 %25, label %26, label %27

; <label>:26                                      ; preds = %18
  store i32 1, i32* %1
  br label %33

; <label>:27                                      ; preds = %18
  br label %28

; <label>:28                                      ; preds = %27
  br label %29

; <label>:29                                      ; preds = %28
  %30 = load i64* %__i, align 8
  %31 = add i64 %30, 1
  store i64 %31, i64* %__i, align 8
  br label %5

; <label>:32                                      ; preds = %5
  store i32 0, i32* %1
  br label %33

; <label>:33                                      ; preds = %32, %26, %17
  %34 = load i32* %1
  ret i32 %34
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt11char_traitsIDiE6lengthEPKDi(i32* %__s) #2 align 2 {
  %1 = alloca i32*, align 8
  %__i = alloca i64, align 8
  %2 = alloca i32, align 4
  store i32* %__s, i32** %1, align 8
  store i64 0, i64* %__i, align 8
  br label %3

; <label>:3                                       ; preds = %9, %0
  %4 = load i64* %__i, align 8
  %5 = load i32** %1, align 8
  %6 = getelementptr inbounds i32* %5, i64 %4
  store i32 0, i32* %2
  %7 = call zeroext i1 @_ZNSt11char_traitsIDiE2eqERKDiS2_(i32* dereferenceable(4) %6, i32* dereferenceable(4) %2) #8
  %8 = xor i1 %7, true
  br i1 %8, label %9, label %12

; <label>:9                                       ; preds = %3
  %10 = load i64* %__i, align 8
  %11 = add i64 %10, 1
  store i64 %11, i64* %__i, align 8
  br label %3

; <label>:12                                      ; preds = %3
  %13 = load i64* %__i, align 8
  ret i64 %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIDiE4findEPKDimRS1_(i32* %__s, i64 %__n, i32* dereferenceable(4) %__a) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  %4 = alloca i32*, align 8
  %__i = alloca i64, align 8
  store i32* %__s, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  store i32* %__a, i32** %4, align 8
  store i64 0, i64* %__i, align 8
  br label %5

; <label>:5                                       ; preds = %20, %0
  %6 = load i64* %__i, align 8
  %7 = load i64* %3, align 8
  %8 = icmp ult i64 %6, %7
  br i1 %8, label %9, label %23

; <label>:9                                       ; preds = %5
  %10 = load i64* %__i, align 8
  %11 = load i32** %2, align 8
  %12 = getelementptr inbounds i32* %11, i64 %10
  %13 = load i32** %4, align 8
  %14 = call zeroext i1 @_ZNSt11char_traitsIDiE2eqERKDiS2_(i32* dereferenceable(4) %12, i32* dereferenceable(4) %13) #8
  br i1 %14, label %15, label %19

; <label>:15                                      ; preds = %9
  %16 = load i32** %2, align 8
  %17 = load i64* %__i, align 8
  %18 = getelementptr inbounds i32* %16, i64 %17
  store i32* %18, i32** %1
  br label %24

; <label>:19                                      ; preds = %9
  br label %20

; <label>:20                                      ; preds = %19
  %21 = load i64* %__i, align 8
  %22 = add i64 %21, 1
  store i64 %22, i64* %__i, align 8
  br label %5

; <label>:23                                      ; preds = %5
  store i32* null, i32** %1
  br label %24

; <label>:24                                      ; preds = %23, %15
  %25 = load i32** %1
  ret i32* %25
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIDiE4moveEPDiPKDim(i32* %__s1, i32* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  store i32* %__s1, i32** %1, align 8
  store i32* %__s2, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i32** %1, align 8
  %5 = bitcast i32* %4 to i8*
  %6 = load i32** %2, align 8
  %7 = bitcast i32* %6 to i8*
  %8 = load i64* %3, align 8
  %9 = mul i64 %8, 4
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %5, i8* %7, i64 %9, i32 4, i1 false)
  %10 = bitcast i8* %5 to i32*
  ret i32* %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIDiE4copyEPDiPKDim(i32* %__s1, i32* %__s2, i64 %__n) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  store i32* %__s1, i32** %1, align 8
  store i32* %__s2, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load i32** %1, align 8
  %5 = bitcast i32* %4 to i8*
  %6 = load i32** %2, align 8
  %7 = bitcast i32* %6 to i8*
  %8 = load i64* %3, align 8
  %9 = mul i64 %8, 4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %5, i8* %7, i64 %9, i32 4, i1 false)
  %10 = bitcast i8* %5 to i32*
  ret i32* %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNSt11char_traitsIDiE6assignEPDimDi(i32* %__s, i64 %__n, i32 zeroext %__a) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i32, align 4
  %__i = alloca i64, align 8
  store i32* %__s, i32** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i32 %__a, i32* %3, align 4
  store i64 0, i64* %__i, align 8
  br label %4

; <label>:4                                       ; preds = %12, %0
  %5 = load i64* %__i, align 8
  %6 = load i64* %2, align 8
  %7 = icmp ult i64 %5, %6
  br i1 %7, label %8, label %15

; <label>:8                                       ; preds = %4
  %9 = load i64* %__i, align 8
  %10 = load i32** %1, align 8
  %11 = getelementptr inbounds i32* %10, i64 %9
  call void @_ZNSt11char_traitsIDiE6assignERDiRKDi(i32* dereferenceable(4) %11, i32* dereferenceable(4) %3) #8
  br label %12

; <label>:12                                      ; preds = %8
  %13 = load i64* %__i, align 8
  %14 = add i64 %13, 1
  store i64 %14, i64* %__i, align 8
  br label %4

; <label>:15                                      ; preds = %4
  %16 = load i32** %1, align 8
  ret i32* %16
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt11char_traitsIDiE12to_char_typeERKj(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  store i32* %__c, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = load i32* %2, align 4
  ret i32 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIDiE11to_int_typeERKDi(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  store i32* %__c, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = load i32* %2, align 4
  ret i32 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt11char_traitsIDiE11eq_int_typeERKjS2_(i32* dereferenceable(4) %__c1, i32* dereferenceable(4) %__c2) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__c1, i32** %1, align 8
  store i32* %__c2, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32** %2, align 8
  %6 = load i32* %5, align 4
  %7 = icmp eq i32 %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIDiE3eofEv() #2 align 2 {
  ret i32 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt11char_traitsIDiE7not_eofERKj(i32* dereferenceable(4) %__c) #2 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__c, i32** %1, align 8
  %3 = load i32** %1, align 8
  %4 = call i32 @_ZNSt11char_traitsIDiE3eofEv() #8
  store i32 %4, i32* %2
  %5 = call zeroext i1 @_ZNSt11char_traitsIDiE11eq_int_typeERKjS2_(i32* dereferenceable(4) %3, i32* dereferenceable(4) %2) #8
  br i1 %5, label %6, label %7

; <label>:6                                       ; preds = %0
  br label %10

; <label>:7                                       ; preds = %0
  %8 = load i32** %1, align 8
  %9 = load i32* %8, align 4
  br label %10

; <label>:10                                      ; preds = %7, %6
  %11 = phi i32 [ 0, %6 ], [ %9, %7 ]
  ret i32 %11
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZSt16__convert_from_vRKP15__locale_structPciPKcz(%struct.__locale_struct** dereferenceable(8) %__cloc, i8* %__out, i32 %__size, i8* %__fmt, ...) #0 {
  %1 = alloca %struct.__locale_struct**, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32, align 4
  %4 = alloca i8*, align 8
  %__old = alloca %struct.__locale_struct*, align 8
  %__args = alloca [1 x %struct.__va_list_tag], align 16
  %__ret = alloca i32, align 4
  store %struct.__locale_struct** %__cloc, %struct.__locale_struct*** %1, align 8
  store i8* %__out, i8** %2, align 8
  store i32 %__size, i32* %3, align 4
  store i8* %__fmt, i8** %4, align 8
  %5 = load %struct.__locale_struct*** %1, align 8
  %6 = load %struct.__locale_struct** %5, align 8
  %7 = call %struct.__locale_struct* @__uselocale(%struct.__locale_struct* %6) #8
  store %struct.__locale_struct* %7, %struct.__locale_struct** %__old, align 8
  %8 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %9 = bitcast %struct.__va_list_tag* %8 to i8*
  call void @llvm.va_start(i8* %9)
  %10 = load i8** %2, align 8
  %11 = load i32* %3, align 4
  %12 = sext i32 %11 to i64
  %13 = load i8** %4, align 8
  %14 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %15 = call i32 @vsnprintf(i8* %10, i64 %12, i8* %13, %struct.__va_list_tag* %14) #8
  store i32 %15, i32* %__ret, align 4
  %16 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %17 = bitcast %struct.__va_list_tag* %16 to i8*
  call void @llvm.va_end(i8* %17)
  %18 = load %struct.__locale_struct** %__old, align 8
  %19 = call %struct.__locale_struct* @__uselocale(%struct.__locale_struct* %18) #8
  %20 = load i32* %__ret, align 4
  ret i32 %20
}

; Function Attrs: nounwind
declare %struct.__locale_struct* @__uselocale(%struct.__locale_struct*) #3

; Function Attrs: nounwind
declare void @llvm.va_start(i8*) #8

; Function Attrs: nounwind
declare i32 @vsnprintf(i8*, i64, i8*, %struct.__va_list_tag*) #3

; Function Attrs: nounwind
declare void @llvm.va_end(i8*) #8

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN23__pthread_cleanup_classC2EPFvPvES0_(%class.__pthread_cleanup_class* %this, void (i8*)* %__fct, i8* %__arg) unnamed_addr #2 align 2 {
  %1 = alloca %class.__pthread_cleanup_class*, align 8
  %2 = alloca void (i8*)*, align 8
  %3 = alloca i8*, align 8
  store %class.__pthread_cleanup_class* %this, %class.__pthread_cleanup_class** %1, align 8
  store void (i8*)* %__fct, void (i8*)** %2, align 8
  store i8* %__arg, i8** %3, align 8
  %4 = load %class.__pthread_cleanup_class** %1
  %5 = getelementptr inbounds %class.__pthread_cleanup_class* %4, i32 0, i32 0
  %6 = load void (i8*)** %2, align 8
  store void (i8*)* %6, void (i8*)** %5, align 8
  %7 = getelementptr inbounds %class.__pthread_cleanup_class* %4, i32 0, i32 1
  %8 = load i8** %3, align 8
  store i8* %8, i8** %7, align 8
  %9 = getelementptr inbounds %class.__pthread_cleanup_class* %4, i32 0, i32 2
  store i32 1, i32* %9, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN23__pthread_cleanup_classD2Ev(%class.__pthread_cleanup_class* %this) unnamed_addr #2 align 2 {
  %1 = alloca %class.__pthread_cleanup_class*, align 8
  store %class.__pthread_cleanup_class* %this, %class.__pthread_cleanup_class** %1, align 8
  %2 = load %class.__pthread_cleanup_class** %1
  %3 = getelementptr inbounds %class.__pthread_cleanup_class* %2, i32 0, i32 2
  %4 = load i32* %3, align 4
  %5 = icmp ne i32 %4, 0
  br i1 %5, label %6, label %12

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %class.__pthread_cleanup_class* %2, i32 0, i32 0
  %8 = load void (i8*)** %7, align 8
  %9 = getelementptr inbounds %class.__pthread_cleanup_class* %2, i32 0, i32 1
  %10 = load i8** %9, align 8
  invoke void %8(i8* %10)
          to label %11 unwind label %13

; <label>:11                                      ; preds = %6
  br label %12

; <label>:12                                      ; preds = %11, %0
  ret void

; <label>:13                                      ; preds = %6
  %14 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %15 = extractvalue { i8*, i32 } %14, 0
  call void @__clang_call_terminate(i8* %15) #18
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN23__pthread_cleanup_class9__setdoitEi(%class.__pthread_cleanup_class* %this, i32 %__newval) #2 align 2 {
  %1 = alloca %class.__pthread_cleanup_class*, align 8
  %2 = alloca i32, align 4
  store %class.__pthread_cleanup_class* %this, %class.__pthread_cleanup_class** %1, align 8
  store i32 %__newval, i32* %2, align 4
  %3 = load %class.__pthread_cleanup_class** %1
  %4 = load i32* %2, align 4
  %5 = getelementptr inbounds %class.__pthread_cleanup_class* %3, i32 0, i32 2
  store i32 %4, i32* %5, align 4
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZN23__pthread_cleanup_class7__deferEv(%class.__pthread_cleanup_class* %this) #7 align 2 {
  %1 = alloca %class.__pthread_cleanup_class*, align 8
  store %class.__pthread_cleanup_class* %this, %class.__pthread_cleanup_class** %1, align 8
  %2 = load %class.__pthread_cleanup_class** %1
  %3 = getelementptr inbounds %class.__pthread_cleanup_class* %2, i32 0, i32 3
  %4 = call i32 @pthread_setcanceltype(i32 0, i32* %3)
  ret void
}

declare i32 @pthread_setcanceltype(i32, i32*) #9

; Function Attrs: uwtable
define linkonce_odr void @_ZNK23__pthread_cleanup_class9__restoreEv(%class.__pthread_cleanup_class* %this) #7 align 2 {
  %1 = alloca %class.__pthread_cleanup_class*, align 8
  store %class.__pthread_cleanup_class* %this, %class.__pthread_cleanup_class** %1, align 8
  %2 = load %class.__pthread_cleanup_class** %1
  %3 = getelementptr inbounds %class.__pthread_cleanup_class* %2, i32 0, i32 3
  %4 = load i32* %3, align 4
  %5 = call i32 @pthread_setcanceltype(i32 %4, i32* null)
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL18__gthread_active_pv() #0 {
  %1 = load i8** @_ZZL18__gthread_active_pvE20__gthread_active_ptr, align 8
  %2 = icmp ne i8* %1, null
  %3 = zext i1 %2 to i32
  ret i32 %3
}

; Function Attrs: nounwind
declare extern_weak i32 @__pthread_key_create(i32*, void (i8*)*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL16__gthread_createPmPFPvS0_ES0_(i64* %__threadid, i8* (i8*)* %__func, i8* %__args) #0 {
  %1 = alloca i64*, align 8
  %2 = alloca i8* (i8*)*, align 8
  %3 = alloca i8*, align 8
  store i64* %__threadid, i64** %1, align 8
  store i8* (i8*)* %__func, i8* (i8*)** %2, align 8
  store i8* %__args, i8** %3, align 8
  %4 = load i64** %1, align 8
  %5 = load i8* (i8*)** %2, align 8
  %6 = load i8** %3, align 8
  %7 = call i32 @pthread_create(i64* %4, %union.pthread_attr_t* null, i8* (i8*)* %5, i8* %6) #8
  ret i32 %7
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_create(i64*, %union.pthread_attr_t*, i8* (i8*)*, i8*) #3

; Function Attrs: inlinehint uwtable
define internal i32 @_ZL14__gthread_joinmPPv(i64 %__threadid, i8** %__value_ptr) #4 {
  %1 = alloca i64, align 8
  %2 = alloca i8**, align 8
  store i64 %__threadid, i64* %1, align 8
  store i8** %__value_ptr, i8*** %2, align 8
  %3 = load i64* %1, align 8
  %4 = load i8*** %2, align 8
  %5 = call i32 @pthread_join(i64 %3, i8** %4)
  ret i32 %5
}

declare extern_weak i32 @pthread_join(i64, i8**) #9

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL16__gthread_detachm(i64 %__threadid) #0 {
  %1 = alloca i64, align 8
  store i64 %__threadid, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 @pthread_detach(i64 %2) #8
  ret i32 %3
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_detach(i64) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL15__gthread_equalmm(i64 %__t1, i64 %__t2) #0 {
  %1 = alloca i64, align 8
  %2 = alloca i64, align 8
  store i64 %__t1, i64* %1, align 8
  store i64 %__t2, i64* %2, align 8
  %3 = load i64* %1, align 8
  %4 = load i64* %2, align 8
  %5 = call i32 @pthread_equal(i64 %3, i64 %4) #8
  ret i32 %5
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_equal(i64, i64) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i64 @_ZL14__gthread_selfv() #0 {
  %1 = call i64 @pthread_self() #8
  ret i64 %1
}

; Function Attrs: nounwind
declare extern_weak i64 @pthread_self() #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL15__gthread_yieldv() #0 {
  %1 = call i32 @sched_yield() #8
  ret i32 %1
}

; Function Attrs: nounwind
declare extern_weak i32 @sched_yield() #3

; Function Attrs: inlinehint uwtable
define internal i32 @_ZL14__gthread_oncePiPFvvE(i32* %__once, void ()* %__func) #4 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  %3 = alloca void ()*, align 8
  store i32* %__once, i32** %2, align 8
  store void ()* %__func, void ()** %3, align 8
  %4 = call i32 @_ZL18__gthread_active_pv()
  %5 = icmp ne i32 %4, 0
  br i1 %5, label %6, label %10

; <label>:6                                       ; preds = %0
  %7 = load i32** %2, align 8
  %8 = load void ()** %3, align 8
  %9 = call i32 @pthread_once(i32* %7, void ()* %8)
  store i32 %9, i32* %1
  br label %11

; <label>:10                                      ; preds = %0
  store i32 -1, i32* %1
  br label %11

; <label>:11                                      ; preds = %10, %6
  %12 = load i32* %1
  ret i32 %12
}

declare extern_weak i32 @pthread_once(i32*, void ()*) #9

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL20__gthread_key_createPjPFvPvE(i32* %__key, void (i8*)* %__dtor) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca void (i8*)*, align 8
  store i32* %__key, i32** %1, align 8
  store void (i8*)* %__dtor, void (i8*)** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load void (i8*)** %2, align 8
  %5 = call i32 @pthread_key_create(i32* %3, void (i8*)* %4) #8
  ret i32 %5
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_key_create(i32*, void (i8*)*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL20__gthread_key_deletej(i32 %__key) #0 {
  %1 = alloca i32, align 4
  store i32 %__key, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = call i32 @pthread_key_delete(i32 %2) #8
  ret i32 %3
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_key_delete(i32) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i8* @_ZL21__gthread_getspecificj(i32 %__key) #0 {
  %1 = alloca i32, align 4
  store i32 %__key, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = call i8* @pthread_getspecific(i32 %2) #8
  ret i8* %3
}

; Function Attrs: nounwind
declare extern_weak i8* @pthread_getspecific(i32) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL21__gthread_setspecificjPKv(i32 %__key, i8* %__ptr) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8*, align 8
  store i32 %__key, i32* %1, align 4
  store i8* %__ptr, i8** %2, align 8
  %3 = load i32* %1, align 4
  %4 = load i8** %2, align 8
  %5 = call i32 @pthread_setspecific(i32 %3, i8* %4) #8
  ret i32 %5
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_setspecific(i32, i8*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal void @_ZL29__gthread_mutex_init_functionP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %1, align 8
  %2 = call i32 @_ZL18__gthread_active_pv()
  %3 = icmp ne i32 %2, 0
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load %union.pthread_mutex_t** %1, align 8
  %6 = call i32 @pthread_mutex_init(%union.pthread_mutex_t* %5, %union.pthread_mutexattr_t* null) #8
  br label %7

; <label>:7                                       ; preds = %4, %0
  ret void
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_mutex_init(%union.pthread_mutex_t*, %union.pthread_mutexattr_t*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL23__gthread_mutex_destroyP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca i32, align 4
  %2 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  %3 = call i32 @_ZL18__gthread_active_pv()
  %4 = icmp ne i32 %3, 0
  br i1 %4, label %5, label %8

; <label>:5                                       ; preds = %0
  %6 = load %union.pthread_mutex_t** %2, align 8
  %7 = call i32 @pthread_mutex_destroy(%union.pthread_mutex_t* %6) #8
  store i32 %7, i32* %1
  br label %9

; <label>:8                                       ; preds = %0
  store i32 0, i32* %1
  br label %9

; <label>:9                                       ; preds = %8, %5
  %10 = load i32* %1
  ret i32 %10
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_mutex_destroy(%union.pthread_mutex_t*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL20__gthread_mutex_lockP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca i32, align 4
  %2 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  %3 = call i32 @_ZL18__gthread_active_pv()
  %4 = icmp ne i32 %3, 0
  br i1 %4, label %5, label %8

; <label>:5                                       ; preds = %0
  %6 = load %union.pthread_mutex_t** %2, align 8
  %7 = call i32 @pthread_mutex_lock(%union.pthread_mutex_t* %6) #8
  store i32 %7, i32* %1
  br label %9

; <label>:8                                       ; preds = %0
  store i32 0, i32* %1
  br label %9

; <label>:9                                       ; preds = %8, %5
  %10 = load i32* %1
  ret i32 %10
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_mutex_lock(%union.pthread_mutex_t*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL23__gthread_mutex_trylockP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca i32, align 4
  %2 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  %3 = call i32 @_ZL18__gthread_active_pv()
  %4 = icmp ne i32 %3, 0
  br i1 %4, label %5, label %8

; <label>:5                                       ; preds = %0
  %6 = load %union.pthread_mutex_t** %2, align 8
  %7 = call i32 @pthread_mutex_trylock(%union.pthread_mutex_t* %6) #8
  store i32 %7, i32* %1
  br label %9

; <label>:8                                       ; preds = %0
  store i32 0, i32* %1
  br label %9

; <label>:9                                       ; preds = %8, %5
  %10 = load i32* %1
  ret i32 %10
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_mutex_trylock(%union.pthread_mutex_t*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL25__gthread_mutex_timedlockP15pthread_mutex_tPK8timespec(%union.pthread_mutex_t* %__mutex, %struct.timespec* %__abs_timeout) #0 {
  %1 = alloca i32, align 4
  %2 = alloca %union.pthread_mutex_t*, align 8
  %3 = alloca %struct.timespec*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  store %struct.timespec* %__abs_timeout, %struct.timespec** %3, align 8
  %4 = call i32 @_ZL18__gthread_active_pv()
  %5 = icmp ne i32 %4, 0
  br i1 %5, label %6, label %10

; <label>:6                                       ; preds = %0
  %7 = load %union.pthread_mutex_t** %2, align 8
  %8 = load %struct.timespec** %3, align 8
  %9 = call i32 @pthread_mutex_timedlock(%union.pthread_mutex_t* %7, %struct.timespec* %8) #8
  store i32 %9, i32* %1
  br label %11

; <label>:10                                      ; preds = %0
  store i32 0, i32* %1
  br label %11

; <label>:11                                      ; preds = %10, %6
  %12 = load i32* %1
  ret i32 %12
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_mutex_timedlock(%union.pthread_mutex_t*, %struct.timespec*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL22__gthread_mutex_unlockP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca i32, align 4
  %2 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  %3 = call i32 @_ZL18__gthread_active_pv()
  %4 = icmp ne i32 %3, 0
  br i1 %4, label %5, label %8

; <label>:5                                       ; preds = %0
  %6 = load %union.pthread_mutex_t** %2, align 8
  %7 = call i32 @pthread_mutex_unlock(%union.pthread_mutex_t* %6) #8
  store i32 %7, i32* %1
  br label %9

; <label>:8                                       ; preds = %0
  store i32 0, i32* %1
  br label %9

; <label>:9                                       ; preds = %8, %5
  %10 = load i32* %1
  ret i32 %10
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_mutex_unlock(%union.pthread_mutex_t*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL30__gthread_recursive_mutex_lockP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %1, align 8
  %2 = load %union.pthread_mutex_t** %1, align 8
  %3 = call i32 @_ZL20__gthread_mutex_lockP15pthread_mutex_t(%union.pthread_mutex_t* %2)
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL33__gthread_recursive_mutex_trylockP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %1, align 8
  %2 = load %union.pthread_mutex_t** %1, align 8
  %3 = call i32 @_ZL23__gthread_mutex_trylockP15pthread_mutex_t(%union.pthread_mutex_t* %2)
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL35__gthread_recursive_mutex_timedlockP15pthread_mutex_tPK8timespec(%union.pthread_mutex_t* %__mutex, %struct.timespec* %__abs_timeout) #0 {
  %1 = alloca %union.pthread_mutex_t*, align 8
  %2 = alloca %struct.timespec*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %1, align 8
  store %struct.timespec* %__abs_timeout, %struct.timespec** %2, align 8
  %3 = load %union.pthread_mutex_t** %1, align 8
  %4 = load %struct.timespec** %2, align 8
  %5 = call i32 @_ZL25__gthread_mutex_timedlockP15pthread_mutex_tPK8timespec(%union.pthread_mutex_t* %3, %struct.timespec* %4)
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL32__gthread_recursive_mutex_unlockP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %1, align 8
  %2 = load %union.pthread_mutex_t** %1, align 8
  %3 = call i32 @_ZL22__gthread_mutex_unlockP15pthread_mutex_t(%union.pthread_mutex_t* %2)
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL33__gthread_recursive_mutex_destroyP15pthread_mutex_t(%union.pthread_mutex_t* %__mutex) #0 {
  %1 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %1, align 8
  %2 = load %union.pthread_mutex_t** %1, align 8
  %3 = call i32 @_ZL23__gthread_mutex_destroyP15pthread_mutex_t(%union.pthread_mutex_t* %2)
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL24__gthread_cond_broadcastP14pthread_cond_t(%union.pthread_cond_t* %__cond) #0 {
  %1 = alloca %union.pthread_cond_t*, align 8
  store %union.pthread_cond_t* %__cond, %union.pthread_cond_t** %1, align 8
  %2 = load %union.pthread_cond_t** %1, align 8
  %3 = call i32 @pthread_cond_broadcast(%union.pthread_cond_t* %2) #8
  ret i32 %3
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_cond_broadcast(%union.pthread_cond_t*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL21__gthread_cond_signalP14pthread_cond_t(%union.pthread_cond_t* %__cond) #0 {
  %1 = alloca %union.pthread_cond_t*, align 8
  store %union.pthread_cond_t* %__cond, %union.pthread_cond_t** %1, align 8
  %2 = load %union.pthread_cond_t** %1, align 8
  %3 = call i32 @pthread_cond_signal(%union.pthread_cond_t* %2) #8
  ret i32 %3
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_cond_signal(%union.pthread_cond_t*) #3

; Function Attrs: inlinehint uwtable
define internal i32 @_ZL19__gthread_cond_waitP14pthread_cond_tP15pthread_mutex_t(%union.pthread_cond_t* %__cond, %union.pthread_mutex_t* %__mutex) #4 {
  %1 = alloca %union.pthread_cond_t*, align 8
  %2 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_cond_t* %__cond, %union.pthread_cond_t** %1, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  %3 = load %union.pthread_cond_t** %1, align 8
  %4 = load %union.pthread_mutex_t** %2, align 8
  %5 = call i32 @pthread_cond_wait(%union.pthread_cond_t* %3, %union.pthread_mutex_t* %4)
  ret i32 %5
}

declare extern_weak i32 @pthread_cond_wait(%union.pthread_cond_t*, %union.pthread_mutex_t*) #9

; Function Attrs: inlinehint uwtable
define internal i32 @_ZL24__gthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec(%union.pthread_cond_t* %__cond, %union.pthread_mutex_t* %__mutex, %struct.timespec* %__abs_timeout) #4 {
  %1 = alloca %union.pthread_cond_t*, align 8
  %2 = alloca %union.pthread_mutex_t*, align 8
  %3 = alloca %struct.timespec*, align 8
  store %union.pthread_cond_t* %__cond, %union.pthread_cond_t** %1, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  store %struct.timespec* %__abs_timeout, %struct.timespec** %3, align 8
  %4 = load %union.pthread_cond_t** %1, align 8
  %5 = load %union.pthread_mutex_t** %2, align 8
  %6 = load %struct.timespec** %3, align 8
  %7 = call i32 @pthread_cond_timedwait(%union.pthread_cond_t* %4, %union.pthread_mutex_t* %5, %struct.timespec* %6)
  ret i32 %7
}

declare extern_weak i32 @pthread_cond_timedwait(%union.pthread_cond_t*, %union.pthread_mutex_t*, %struct.timespec*) #9

; Function Attrs: inlinehint uwtable
define internal i32 @_ZL29__gthread_cond_wait_recursiveP14pthread_cond_tP15pthread_mutex_t(%union.pthread_cond_t* %__cond, %union.pthread_mutex_t* %__mutex) #4 {
  %1 = alloca %union.pthread_cond_t*, align 8
  %2 = alloca %union.pthread_mutex_t*, align 8
  store %union.pthread_cond_t* %__cond, %union.pthread_cond_t** %1, align 8
  store %union.pthread_mutex_t* %__mutex, %union.pthread_mutex_t** %2, align 8
  %3 = load %union.pthread_cond_t** %1, align 8
  %4 = load %union.pthread_mutex_t** %2, align 8
  %5 = call i32 @_ZL19__gthread_cond_waitP14pthread_cond_tP15pthread_mutex_t(%union.pthread_cond_t* %3, %union.pthread_mutex_t* %4)
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL22__gthread_cond_destroyP14pthread_cond_t(%union.pthread_cond_t* %__cond) #0 {
  %1 = alloca %union.pthread_cond_t*, align 8
  store %union.pthread_cond_t* %__cond, %union.pthread_cond_t** %1, align 8
  %2 = load %union.pthread_cond_t** %1, align 8
  %3 = call i32 @pthread_cond_destroy(%union.pthread_cond_t* %2) #8
  ret i32 %3
}

; Function Attrs: nounwind
declare extern_weak i32 @pthread_cond_destroy(%union.pthread_cond_t*) #3

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZN9__gnu_cxxL18__exchange_and_addEPVii(i32* %__mem, i32 %__val) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %5 = load i32** %1, align 8
  %6 = load i32* %2, align 4
  store i32 %6, i32* %3
  %7 = load i32* %3, align 4
  %8 = atomicrmw volatile add i32* %5, i32 %7 acq_rel
  store i32 %8, i32* %4, align 4
  %9 = load i32* %4, align 4
  ret i32 %9
}

; Function Attrs: inlinehint nounwind uwtable
define internal void @_ZN9__gnu_cxxL12__atomic_addEPVii(i32* %__mem, i32 %__val) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %5 = load i32** %1, align 8
  %6 = load i32* %2, align 4
  store i32 %6, i32* %3
  %7 = load i32* %3, align 4
  %8 = atomicrmw volatile add i32* %5, i32 %7 acq_rel
  store i32 %8, i32* %4, align 4
  %9 = load i32* %4, align 4
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZN9__gnu_cxxL25__exchange_and_add_singleEPii(i32* %__mem, i32 %__val) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %__result = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  store i32 %4, i32* %__result, align 4
  %5 = load i32* %2, align 4
  %6 = load i32** %1, align 8
  %7 = load i32* %6, align 4
  %8 = add nsw i32 %7, %5
  store i32 %8, i32* %6, align 4
  %9 = load i32* %__result, align 4
  ret i32 %9
}

; Function Attrs: inlinehint nounwind uwtable
define internal void @_ZN9__gnu_cxxL19__atomic_add_singleEPii(i32* %__mem, i32 %__val) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load i32* %2, align 4
  %4 = load i32** %1, align 8
  %5 = load i32* %4, align 4
  %6 = add nsw i32 %5, %3
  store i32 %6, i32* %4, align 4
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii(i32* %__mem, i32 %__val) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  %3 = alloca i32, align 4
  store i32* %__mem, i32** %2, align 8
  store i32 %__val, i32* %3, align 4
  %4 = call i32 @_ZL18__gthread_active_pv()
  %5 = icmp ne i32 %4, 0
  br i1 %5, label %6, label %10

; <label>:6                                       ; preds = %0
  %7 = load i32** %2, align 8
  %8 = load i32* %3, align 4
  %9 = call i32 @_ZN9__gnu_cxxL18__exchange_and_addEPVii(i32* %7, i32 %8)
  store i32 %9, i32* %1
  br label %14

; <label>:10                                      ; preds = %0
  %11 = load i32** %2, align 8
  %12 = load i32* %3, align 4
  %13 = call i32 @_ZN9__gnu_cxxL25__exchange_and_add_singleEPii(i32* %11, i32 %12)
  store i32 %13, i32* %1
  br label %14

; <label>:14                                      ; preds = %10, %6
  %15 = load i32* %1
  ret i32 %15
}

; Function Attrs: inlinehint nounwind uwtable
define internal void @_ZN9__gnu_cxxL21__atomic_add_dispatchEPii(i32* %__mem, i32 %__val) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = call i32 @_ZL18__gthread_active_pv()
  %4 = icmp ne i32 %3, 0
  br i1 %4, label %5, label %8

; <label>:5                                       ; preds = %0
  %6 = load i32** %1, align 8
  %7 = load i32* %2, align 4
  call void @_ZN9__gnu_cxxL12__atomic_addEPVii(i32* %6, i32 %7)
  br label %11

; <label>:8                                       ; preds = %0
  %9 = load i32** %1, align 8
  %10 = load i32* %2, align 4
  call void @_ZN9__gnu_cxxL19__atomic_add_singleEPii(i32* %9, i32 %10)
  br label %11

; <label>:11                                      ; preds = %8, %5
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr i32 @_ZSt4stoiRKSsPmi(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string"** %1, align 8
  %5 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i32 @_ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* @strtol, i8* getelementptr inbounds ([5 x i8]* @.str5, i32 0, i32 0), i8* %5, i64* %6, i32 %7)
  ret i32 %8
}

; Function Attrs: uwtable
define linkonce_odr i32 @_ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* %__convf, i8* %__name, i8* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i8*, i8**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i32, align 4
  %__endptr = alloca i8*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i8*, i8**, i32)* %__convf, i64 (i8*, i8**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i8*, i8**, i32)** %1, align 8
  %8 = load i8** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i8* %8, i8** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i8** %__endptr, align 8
  %12 = load i8** %3, align 8
  %13 = icmp eq i8* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %26, label %20

; <label>:20                                      ; preds = %16
  %21 = load i64* %__tmp, align 8
  %22 = icmp slt i64 %21, -2147483648
  br i1 %22, label %26, label %23

; <label>:23                                      ; preds = %20
  %24 = load i64* %__tmp, align 8
  %25 = icmp sgt i64 %24, 2147483647
  br i1 %25, label %26, label %28

; <label>:26                                      ; preds = %23, %20, %16
  %27 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %27) #17
  unreachable

; <label>:28                                      ; preds = %23
  %29 = load i64* %__tmp, align 8
  %30 = trunc i64 %29 to i32
  store i32 %30, i32* %__ret, align 4
  br label %31

; <label>:31                                      ; preds = %28
  br label %32

; <label>:32                                      ; preds = %31
  %33 = load i64** %4, align 8
  %34 = icmp ne i64* %33, null
  br i1 %34, label %35, label %42

; <label>:35                                      ; preds = %32
  %36 = load i8** %__endptr, align 8
  %37 = load i8** %3, align 8
  %38 = ptrtoint i8* %36 to i64
  %39 = ptrtoint i8* %37 to i64
  %40 = sub i64 %38, %39
  %41 = load i64** %4, align 8
  store i64 %40, i64* %41, align 8
  br label %42

; <label>:42                                      ; preds = %35, %32
  %43 = load i32* %__ret, align 4
  ret i32 %43
}

; Function Attrs: nounwind
declare i64 @strtol(i8*, i8**, i32) #3

; Function Attrs: nounwind
declare i8* @_ZNKSs5c_strEv(%"class.std::basic_string"*) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt4stolRKSsPmi(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string"** %1, align 8
  %5 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaIllcJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* @strtol, i8* getelementptr inbounds ([5 x i8]* @.str6, i32 0, i32 0), i8* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaIllcJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* %__convf, i8* %__name, i8* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i8*, i8**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i8*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i8*, i8**, i32)* %__convf, i64 (i8*, i8**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i8*, i8**, i32)** %1, align 8
  %8 = load i8** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i8* %8, i8** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i8** %__endptr, align 8
  %12 = load i8** %3, align 8
  %13 = icmp eq i8* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %35

; <label>:28                                      ; preds = %25
  %29 = load i8** %__endptr, align 8
  %30 = load i8** %3, align 8
  %31 = ptrtoint i8* %29 to i64
  %32 = ptrtoint i8* %30 to i64
  %33 = sub i64 %31, %32
  %34 = load i64** %4, align 8
  store i64 %33, i64* %34, align 8
  br label %35

; <label>:35                                      ; preds = %28, %25
  %36 = load i64* %__ret, align 8
  ret i64 %36
}

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt5stoulRKSsPmi(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string"** %1, align 8
  %5 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaImmcJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* @strtoul, i8* getelementptr inbounds ([6 x i8]* @.str7, i32 0, i32 0), i8* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaImmcJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* %__convf, i8* %__name, i8* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i8*, i8**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i8*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i8*, i8**, i32)* %__convf, i64 (i8*, i8**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i8*, i8**, i32)** %1, align 8
  %8 = load i8** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i8* %8, i8** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i8** %__endptr, align 8
  %12 = load i8** %3, align 8
  %13 = icmp eq i8* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %35

; <label>:28                                      ; preds = %25
  %29 = load i8** %__endptr, align 8
  %30 = load i8** %3, align 8
  %31 = ptrtoint i8* %29 to i64
  %32 = ptrtoint i8* %30 to i64
  %33 = sub i64 %31, %32
  %34 = load i64** %4, align 8
  store i64 %33, i64* %34, align 8
  br label %35

; <label>:35                                      ; preds = %28, %25
  %36 = load i64* %__ret, align 8
  ret i64 %36
}

; Function Attrs: nounwind
declare i64 @strtoul(i8*, i8**, i32) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt5stollRKSsPmi(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string"** %1, align 8
  %5 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaIxxcJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* @strtoll, i8* getelementptr inbounds ([6 x i8]* @.str8, i32 0, i32 0), i8* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaIxxcJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* %__convf, i8* %__name, i8* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i8*, i8**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i8*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i8*, i8**, i32)* %__convf, i64 (i8*, i8**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i8*, i8**, i32)** %1, align 8
  %8 = load i8** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i8* %8, i8** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i8** %__endptr, align 8
  %12 = load i8** %3, align 8
  %13 = icmp eq i8* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %35

; <label>:28                                      ; preds = %25
  %29 = load i8** %__endptr, align 8
  %30 = load i8** %3, align 8
  %31 = ptrtoint i8* %29 to i64
  %32 = ptrtoint i8* %30 to i64
  %33 = sub i64 %31, %32
  %34 = load i64** %4, align 8
  store i64 %33, i64* %34, align 8
  br label %35

; <label>:35                                      ; preds = %28, %25
  %36 = load i64* %__ret, align 8
  ret i64 %36
}

; Function Attrs: nounwind
declare i64 @strtoll(i8*, i8**, i32) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt6stoullRKSsPmi(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string"** %1, align 8
  %5 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaIyycJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* @strtoull, i8* getelementptr inbounds ([7 x i8]* @.str9, i32 0, i32 0), i8* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaIyycJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i8*, i8**, i32)* %__convf, i8* %__name, i8* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i8*, i8**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i8*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i8*, i8**, i32)* %__convf, i64 (i8*, i8**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i8*, i8**, i32)** %1, align 8
  %8 = load i8** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i8* %8, i8** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i8** %__endptr, align 8
  %12 = load i8** %3, align 8
  %13 = icmp eq i8* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %35

; <label>:28                                      ; preds = %25
  %29 = load i8** %__endptr, align 8
  %30 = load i8** %3, align 8
  %31 = ptrtoint i8* %29 to i64
  %32 = ptrtoint i8* %30 to i64
  %33 = sub i64 %31, %32
  %34 = load i64** %4, align 8
  store i64 %33, i64* %34, align 8
  br label %35

; <label>:35                                      ; preds = %28, %25
  %36 = load i64* %__ret, align 8
  ret i64 %36
}

; Function Attrs: nounwind
declare i64 @strtoull(i8*, i8**, i32) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr float @_ZSt4stofRKSsPm(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  %3 = load %"class.std::basic_string"** %1, align 8
  %4 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %3) #8
  %5 = load i64** %2, align 8
  %6 = call float @_ZN9__gnu_cxx6__stoaIffcJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(float (i8*, i8**)* @strtof, i8* getelementptr inbounds ([5 x i8]* @.str10, i32 0, i32 0), i8* %4, i64* %5)
  ret float %6
}

; Function Attrs: uwtable
define linkonce_odr float @_ZN9__gnu_cxx6__stoaIffcJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(float (i8*, i8**)* %__convf, i8* %__name, i8* %__str, i64* %__idx) #7 {
  %1 = alloca float (i8*, i8**)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %__ret = alloca float, align 4
  %__endptr = alloca i8*, align 8
  %__tmp = alloca float, align 4
  store float (i8*, i8**)* %__convf, float (i8*, i8**)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  %5 = call i32* @__errno_location() #1
  store i32 0, i32* %5, align 4
  %6 = load float (i8*, i8**)** %1, align 8
  %7 = load i8** %3, align 8
  %8 = call float %6(i8* %7, i8** %__endptr)
  store float %8, float* %__tmp, align 4
  %9 = load i8** %__endptr, align 8
  %10 = load i8** %3, align 8
  %11 = icmp eq i8* %9, %10
  br i1 %11, label %12, label %14

; <label>:12                                      ; preds = %0
  %13 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %13) #17
  unreachable

; <label>:14                                      ; preds = %0
  %15 = call i32* @__errno_location() #1
  %16 = load i32* %15, align 4
  %17 = icmp eq i32 %16, 34
  br i1 %17, label %18, label %20

; <label>:18                                      ; preds = %14
  %19 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %19) #17
  unreachable

; <label>:20                                      ; preds = %14
  %21 = load float* %__tmp, align 4
  store float %21, float* %__ret, align 4
  br label %22

; <label>:22                                      ; preds = %20
  br label %23

; <label>:23                                      ; preds = %22
  %24 = load i64** %4, align 8
  %25 = icmp ne i64* %24, null
  br i1 %25, label %26, label %33

; <label>:26                                      ; preds = %23
  %27 = load i8** %__endptr, align 8
  %28 = load i8** %3, align 8
  %29 = ptrtoint i8* %27 to i64
  %30 = ptrtoint i8* %28 to i64
  %31 = sub i64 %29, %30
  %32 = load i64** %4, align 8
  store i64 %31, i64* %32, align 8
  br label %33

; <label>:33                                      ; preds = %26, %23
  %34 = load float* %__ret, align 4
  ret float %34
}

; Function Attrs: nounwind
declare float @strtof(i8*, i8**) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr double @_ZSt4stodRKSsPm(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  %3 = load %"class.std::basic_string"** %1, align 8
  %4 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %3) #8
  %5 = load i64** %2, align 8
  %6 = call double @_ZN9__gnu_cxx6__stoaIddcJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(double (i8*, i8**)* @strtod, i8* getelementptr inbounds ([5 x i8]* @.str11, i32 0, i32 0), i8* %4, i64* %5)
  ret double %6
}

; Function Attrs: uwtable
define linkonce_odr double @_ZN9__gnu_cxx6__stoaIddcJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(double (i8*, i8**)* %__convf, i8* %__name, i8* %__str, i64* %__idx) #7 {
  %1 = alloca double (i8*, i8**)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %__ret = alloca double, align 8
  %__endptr = alloca i8*, align 8
  %__tmp = alloca double, align 8
  store double (i8*, i8**)* %__convf, double (i8*, i8**)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  %5 = call i32* @__errno_location() #1
  store i32 0, i32* %5, align 4
  %6 = load double (i8*, i8**)** %1, align 8
  %7 = load i8** %3, align 8
  %8 = call double %6(i8* %7, i8** %__endptr)
  store double %8, double* %__tmp, align 8
  %9 = load i8** %__endptr, align 8
  %10 = load i8** %3, align 8
  %11 = icmp eq i8* %9, %10
  br i1 %11, label %12, label %14

; <label>:12                                      ; preds = %0
  %13 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %13) #17
  unreachable

; <label>:14                                      ; preds = %0
  %15 = call i32* @__errno_location() #1
  %16 = load i32* %15, align 4
  %17 = icmp eq i32 %16, 34
  br i1 %17, label %18, label %20

; <label>:18                                      ; preds = %14
  %19 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %19) #17
  unreachable

; <label>:20                                      ; preds = %14
  %21 = load double* %__tmp, align 8
  store double %21, double* %__ret, align 8
  br label %22

; <label>:22                                      ; preds = %20
  br label %23

; <label>:23                                      ; preds = %22
  %24 = load i64** %4, align 8
  %25 = icmp ne i64* %24, null
  br i1 %25, label %26, label %33

; <label>:26                                      ; preds = %23
  %27 = load i8** %__endptr, align 8
  %28 = load i8** %3, align 8
  %29 = ptrtoint i8* %27 to i64
  %30 = ptrtoint i8* %28 to i64
  %31 = sub i64 %29, %30
  %32 = load i64** %4, align 8
  store i64 %31, i64* %32, align 8
  br label %33

; <label>:33                                      ; preds = %26, %23
  %34 = load double* %__ret, align 8
  ret double %34
}

; Function Attrs: nounwind
declare double @strtod(i8*, i8**) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr x86_fp80 @_ZSt5stoldRKSsPm(%"class.std::basic_string"* dereferenceable(8) %__str, i64* %__idx) #4 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i64*, align 8
  store %"class.std::basic_string"* %__str, %"class.std::basic_string"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  %3 = load %"class.std::basic_string"** %1, align 8
  %4 = call i8* @_ZNKSs5c_strEv(%"class.std::basic_string"* %3) #8
  %5 = load i64** %2, align 8
  %6 = call x86_fp80 @_ZN9__gnu_cxx6__stoaIeecJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(x86_fp80 (i8*, i8**)* @strtold, i8* getelementptr inbounds ([6 x i8]* @.str12, i32 0, i32 0), i8* %4, i64* %5)
  ret x86_fp80 %6
}

; Function Attrs: uwtable
define linkonce_odr x86_fp80 @_ZN9__gnu_cxx6__stoaIeecJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(x86_fp80 (i8*, i8**)* %__convf, i8* %__name, i8* %__str, i64* %__idx) #7 {
  %1 = alloca x86_fp80 (i8*, i8**)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i64*, align 8
  %__ret = alloca x86_fp80, align 16
  %__endptr = alloca i8*, align 8
  %__tmp = alloca x86_fp80, align 16
  store x86_fp80 (i8*, i8**)* %__convf, x86_fp80 (i8*, i8**)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i8* %__str, i8** %3, align 8
  store i64* %__idx, i64** %4, align 8
  %5 = call i32* @__errno_location() #1
  store i32 0, i32* %5, align 4
  %6 = load x86_fp80 (i8*, i8**)** %1, align 8
  %7 = load i8** %3, align 8
  %8 = call x86_fp80 %6(i8* %7, i8** %__endptr)
  store x86_fp80 %8, x86_fp80* %__tmp, align 16
  %9 = load i8** %__endptr, align 8
  %10 = load i8** %3, align 8
  %11 = icmp eq i8* %9, %10
  br i1 %11, label %12, label %14

; <label>:12                                      ; preds = %0
  %13 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %13) #17
  unreachable

; <label>:14                                      ; preds = %0
  %15 = call i32* @__errno_location() #1
  %16 = load i32* %15, align 4
  %17 = icmp eq i32 %16, 34
  br i1 %17, label %18, label %20

; <label>:18                                      ; preds = %14
  %19 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %19) #17
  unreachable

; <label>:20                                      ; preds = %14
  %21 = load x86_fp80* %__tmp, align 16
  store x86_fp80 %21, x86_fp80* %__ret, align 16
  br label %22

; <label>:22                                      ; preds = %20
  br label %23

; <label>:23                                      ; preds = %22
  %24 = load i64** %4, align 8
  %25 = icmp ne i64* %24, null
  br i1 %25, label %26, label %33

; <label>:26                                      ; preds = %23
  %27 = load i8** %__endptr, align 8
  %28 = load i8** %3, align 8
  %29 = ptrtoint i8* %27 to i64
  %30 = ptrtoint i8* %28 to i64
  %31 = sub i64 %29, %30
  %32 = load i64** %4, align 8
  store i64 %31, i64* %32, align 8
  br label %33

; <label>:33                                      ; preds = %26, %23
  %34 = load x86_fp80* %__ret, align 16
  ret x86_fp80 %34
}

; Function Attrs: nounwind
declare x86_fp80 @strtold(i8*, i8**) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringi(%"class.std::basic_string"* noalias sret %agg.result, i32 %__val) #4 {
  %1 = alloca i32, align 4
  store i32 %__val, i32* %1, align 4
  %2 = load i32* %1, align 4
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 16, i8* getelementptr inbounds ([3 x i8]* @.str13, i32 0, i32 0), i32 %2)
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* noalias sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* %__convf, i64 %__n, i8* %__fmt, ...) #7 {
  %1 = alloca i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i8*, align 8
  %__s = alloca i8*, align 8
  %__args = alloca [1 x %struct.__va_list_tag], align 16
  %__len = alloca i32, align 4
  %4 = alloca %"class.std::allocator.32", align 1
  %5 = alloca i8*
  %6 = alloca i32
  store i32 (i8*, i64, i8*, %struct.__va_list_tag*)* %__convf, i32 (i8*, i64, i8*, %struct.__va_list_tag*)** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i8* %__fmt, i8** %3, align 8
  %7 = load i64* %2, align 8
  %8 = mul i64 1, %7
  %9 = alloca i8, i64 %8
  store i8* %9, i8** %__s, align 8
  %10 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %11 = bitcast %struct.__va_list_tag* %10 to i8*
  call void @llvm.va_start(i8* %11)
  %12 = load i32 (i8*, i64, i8*, %struct.__va_list_tag*)** %1, align 8
  %13 = load i8** %__s, align 8
  %14 = load i64* %2, align 8
  %15 = load i8** %3, align 8
  %16 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %17 = call i32 %12(i8* %13, i64 %14, i8* %15, %struct.__va_list_tag* %16)
  store i32 %17, i32* %__len, align 4
  %18 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %19 = bitcast %struct.__va_list_tag* %18 to i8*
  call void @llvm.va_end(i8* %19)
  %20 = load i8** %__s, align 8
  %21 = load i8** %__s, align 8
  %22 = load i32* %__len, align 4
  %23 = sext i32 %22 to i64
  %24 = getelementptr inbounds i8* %21, i64 %23
  call void @_ZNSaIcEC1Ev(%"class.std::allocator.32"* %4) #8
  invoke void @_ZNSsC2IPcEET_S1_RKSaIcE(%"class.std::basic_string"* %agg.result, i8* %20, i8* %24, %"class.std::allocator.32"* dereferenceable(1) %4)
          to label %25 unwind label %26

; <label>:25                                      ; preds = %0
  call void @_ZNSaIcED1Ev(%"class.std::allocator.32"* %4) #8
  ret void

; <label>:26                                      ; preds = %0
  %27 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %28 = extractvalue { i8*, i32 } %27, 0
  store i8* %28, i8** %5
  %29 = extractvalue { i8*, i32 } %27, 1
  store i32 %29, i32* %6
  call void @_ZNSaIcED1Ev(%"class.std::allocator.32"* %4) #8
  br label %30

; <label>:30                                      ; preds = %26
  %31 = load i8** %5
  %32 = load i32* %6
  %33 = insertvalue { i8*, i32 } undef, i8* %31, 0
  %34 = insertvalue { i8*, i32 } %33, i32 %32, 1
  resume { i8*, i32 } %34
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringj(%"class.std::basic_string"* noalias sret %agg.result, i32 %__val) #4 {
  %1 = alloca i32, align 4
  store i32 %__val, i32* %1, align 4
  %2 = load i32* %1, align 4
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 16, i8* getelementptr inbounds ([3 x i8]* @.str14, i32 0, i32 0), i32 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringl(%"class.std::basic_string"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 32, i8* getelementptr inbounds ([4 x i8]* @.str15, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringm(%"class.std::basic_string"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 32, i8* getelementptr inbounds ([4 x i8]* @.str16, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringx(%"class.std::basic_string"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 32, i8* getelementptr inbounds ([5 x i8]* @.str17, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringy(%"class.std::basic_string"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 32, i8* getelementptr inbounds ([5 x i8]* @.str18, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringf(%"class.std::basic_string"* noalias sret %agg.result, float %__val) #4 {
  %1 = alloca float, align 4
  %__n = alloca i32, align 4
  store float %__val, float* %1, align 4
  store i32 58, i32* %__n, align 4
  %2 = load float* %1, align 4
  %3 = fpext float %2 to double
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 58, i8* getelementptr inbounds ([3 x i8]* @.str19, i32 0, i32 0), double %3)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringd(%"class.std::basic_string"* noalias sret %agg.result, double %__val) #4 {
  %1 = alloca double, align 8
  %__n = alloca i32, align 4
  store double %__val, double* %1, align 8
  store i32 328, i32* %__n, align 4
  %2 = load double* %1, align 8
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 328, i8* getelementptr inbounds ([3 x i8]* @.str19, i32 0, i32 0), double %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt9to_stringe(%"class.std::basic_string"* noalias sret %agg.result, x86_fp80 %__val) #4 {
  %1 = alloca x86_fp80, align 16
  %__n = alloca i32, align 4
  store x86_fp80 %__val, x86_fp80* %1, align 16
  store i32 4952, i32* %__n, align 4
  %2 = load x86_fp80* %1, align 16
  call void (%"class.std::basic_string"*, i32 (i8*, i64, i8*, %struct.__va_list_tag*)*, i64, i8*, ...)* @_ZN9__gnu_cxx12__to_xstringISscEET_PFiPT0_mPKS2_P13__va_list_tagEmS5_z(%"class.std::basic_string"* sret %agg.result, i32 (i8*, i64, i8*, %struct.__va_list_tag*)* @vsnprintf, i64 4952, i8* getelementptr inbounds ([4 x i8]* @.str20, i32 0, i32 0), x86_fp80 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr i32 @_ZSt4stoiRKSbIwSt11char_traitsIwESaIwEEPmi(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string.35"** %1, align 8
  %5 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i32 @_ZN9__gnu_cxx6__stoaIliwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* @wcstol, i8* getelementptr inbounds ([5 x i8]* @.str5, i32 0, i32 0), i32* %5, i64* %6, i32 %7)
  ret i32 %8
}

; Function Attrs: uwtable
define linkonce_odr i32 @_ZN9__gnu_cxx6__stoaIliwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* %__convf, i8* %__name, i32* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i32*, i32**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i32, align 4
  %__endptr = alloca i32*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i32*, i32**, i32)* %__convf, i64 (i32*, i32**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i32*, i32**, i32)** %1, align 8
  %8 = load i32** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i32* %8, i32** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i32** %__endptr, align 8
  %12 = load i32** %3, align 8
  %13 = icmp eq i32* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %26, label %20

; <label>:20                                      ; preds = %16
  %21 = load i64* %__tmp, align 8
  %22 = icmp slt i64 %21, -2147483648
  br i1 %22, label %26, label %23

; <label>:23                                      ; preds = %20
  %24 = load i64* %__tmp, align 8
  %25 = icmp sgt i64 %24, 2147483647
  br i1 %25, label %26, label %28

; <label>:26                                      ; preds = %23, %20, %16
  %27 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %27) #17
  unreachable

; <label>:28                                      ; preds = %23
  %29 = load i64* %__tmp, align 8
  %30 = trunc i64 %29 to i32
  store i32 %30, i32* %__ret, align 4
  br label %31

; <label>:31                                      ; preds = %28
  br label %32

; <label>:32                                      ; preds = %31
  %33 = load i64** %4, align 8
  %34 = icmp ne i64* %33, null
  br i1 %34, label %35, label %43

; <label>:35                                      ; preds = %32
  %36 = load i32** %__endptr, align 8
  %37 = load i32** %3, align 8
  %38 = ptrtoint i32* %36 to i64
  %39 = ptrtoint i32* %37 to i64
  %40 = sub i64 %38, %39
  %41 = sdiv exact i64 %40, 4
  %42 = load i64** %4, align 8
  store i64 %41, i64* %42, align 8
  br label %43

; <label>:43                                      ; preds = %35, %32
  %44 = load i32* %__ret, align 4
  ret i32 %44
}

; Function Attrs: nounwind
declare i64 @wcstol(i32*, i32**, i32) #3

; Function Attrs: nounwind
declare i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"*) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt4stolRKSbIwSt11char_traitsIwESaIwEEPmi(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string.35"** %1, align 8
  %5 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaIllwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* @wcstol, i8* getelementptr inbounds ([5 x i8]* @.str6, i32 0, i32 0), i32* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaIllwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* %__convf, i8* %__name, i32* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i32*, i32**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i32*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i32*, i32**, i32)* %__convf, i64 (i32*, i32**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i32*, i32**, i32)** %1, align 8
  %8 = load i32** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i32* %8, i32** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i32** %__endptr, align 8
  %12 = load i32** %3, align 8
  %13 = icmp eq i32* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %36

; <label>:28                                      ; preds = %25
  %29 = load i32** %__endptr, align 8
  %30 = load i32** %3, align 8
  %31 = ptrtoint i32* %29 to i64
  %32 = ptrtoint i32* %30 to i64
  %33 = sub i64 %31, %32
  %34 = sdiv exact i64 %33, 4
  %35 = load i64** %4, align 8
  store i64 %34, i64* %35, align 8
  br label %36

; <label>:36                                      ; preds = %28, %25
  %37 = load i64* %__ret, align 8
  ret i64 %37
}

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt5stoulRKSbIwSt11char_traitsIwESaIwEEPmi(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string.35"** %1, align 8
  %5 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaImmwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* @wcstoul, i8* getelementptr inbounds ([6 x i8]* @.str7, i32 0, i32 0), i32* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaImmwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* %__convf, i8* %__name, i32* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i32*, i32**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i32*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i32*, i32**, i32)* %__convf, i64 (i32*, i32**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i32*, i32**, i32)** %1, align 8
  %8 = load i32** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i32* %8, i32** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i32** %__endptr, align 8
  %12 = load i32** %3, align 8
  %13 = icmp eq i32* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %36

; <label>:28                                      ; preds = %25
  %29 = load i32** %__endptr, align 8
  %30 = load i32** %3, align 8
  %31 = ptrtoint i32* %29 to i64
  %32 = ptrtoint i32* %30 to i64
  %33 = sub i64 %31, %32
  %34 = sdiv exact i64 %33, 4
  %35 = load i64** %4, align 8
  store i64 %34, i64* %35, align 8
  br label %36

; <label>:36                                      ; preds = %28, %25
  %37 = load i64* %__ret, align 8
  ret i64 %37
}

; Function Attrs: nounwind
declare i64 @wcstoul(i32*, i32**, i32) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt5stollRKSbIwSt11char_traitsIwESaIwEEPmi(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string.35"** %1, align 8
  %5 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaIxxwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* @wcstoll, i8* getelementptr inbounds ([6 x i8]* @.str8, i32 0, i32 0), i32* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaIxxwJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* %__convf, i8* %__name, i32* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i32*, i32**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i32*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i32*, i32**, i32)* %__convf, i64 (i32*, i32**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i32*, i32**, i32)** %1, align 8
  %8 = load i32** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i32* %8, i32** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i32** %__endptr, align 8
  %12 = load i32** %3, align 8
  %13 = icmp eq i32* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %36

; <label>:28                                      ; preds = %25
  %29 = load i32** %__endptr, align 8
  %30 = load i32** %3, align 8
  %31 = ptrtoint i32* %29 to i64
  %32 = ptrtoint i32* %30 to i64
  %33 = sub i64 %31, %32
  %34 = sdiv exact i64 %33, 4
  %35 = load i64** %4, align 8
  store i64 %34, i64* %35, align 8
  br label %36

; <label>:36                                      ; preds = %28, %25
  %37 = load i64* %__ret, align 8
  ret i64 %37
}

; Function Attrs: nounwind
declare i64 @wcstoll(i32*, i32**, i32) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr i64 @_ZSt6stoullRKSbIwSt11char_traitsIwESaIwEEPmi(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx, i32 %__base) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32, align 4
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  store i32 %__base, i32* %3, align 4
  %4 = load %"class.std::basic_string.35"** %1, align 8
  %5 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %4) #8
  %6 = load i64** %2, align 8
  %7 = load i32* %3, align 4
  %8 = call i64 @_ZN9__gnu_cxx6__stoaIyywJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* @wcstoull, i8* getelementptr inbounds ([7 x i8]* @.str9, i32 0, i32 0), i32* %5, i64* %6, i32 %7)
  ret i64 %8
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZN9__gnu_cxx6__stoaIyywJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(i64 (i32*, i32**, i32)* %__convf, i8* %__name, i32* %__str, i64* %__idx, i32 %__base) #7 {
  %1 = alloca i64 (i32*, i32**, i32)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i32, align 4
  %__ret = alloca i64, align 8
  %__endptr = alloca i32*, align 8
  %__tmp = alloca i64, align 8
  store i64 (i32*, i32**, i32)* %__convf, i64 (i32*, i32**, i32)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  store i32 %__base, i32* %5, align 4
  %6 = call i32* @__errno_location() #1
  store i32 0, i32* %6, align 4
  %7 = load i64 (i32*, i32**, i32)** %1, align 8
  %8 = load i32** %3, align 8
  %9 = load i32* %5, align 4
  %10 = call i64 %7(i32* %8, i32** %__endptr, i32 %9)
  store i64 %10, i64* %__tmp, align 8
  %11 = load i32** %__endptr, align 8
  %12 = load i32** %3, align 8
  %13 = icmp eq i32* %11, %12
  br i1 %13, label %14, label %16

; <label>:14                                      ; preds = %0
  %15 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %15) #17
  unreachable

; <label>:16                                      ; preds = %0
  %17 = call i32* @__errno_location() #1
  %18 = load i32* %17, align 4
  %19 = icmp eq i32 %18, 34
  br i1 %19, label %20, label %22

; <label>:20                                      ; preds = %16
  %21 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %21) #17
  unreachable

; <label>:22                                      ; preds = %16
  %23 = load i64* %__tmp, align 8
  store i64 %23, i64* %__ret, align 8
  br label %24

; <label>:24                                      ; preds = %22
  br label %25

; <label>:25                                      ; preds = %24
  %26 = load i64** %4, align 8
  %27 = icmp ne i64* %26, null
  br i1 %27, label %28, label %36

; <label>:28                                      ; preds = %25
  %29 = load i32** %__endptr, align 8
  %30 = load i32** %3, align 8
  %31 = ptrtoint i32* %29 to i64
  %32 = ptrtoint i32* %30 to i64
  %33 = sub i64 %31, %32
  %34 = sdiv exact i64 %33, 4
  %35 = load i64** %4, align 8
  store i64 %34, i64* %35, align 8
  br label %36

; <label>:36                                      ; preds = %28, %25
  %37 = load i64* %__ret, align 8
  ret i64 %37
}

; Function Attrs: nounwind
declare i64 @wcstoull(i32*, i32**, i32) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr float @_ZSt4stofRKSbIwSt11char_traitsIwESaIwEEPm(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  %3 = load %"class.std::basic_string.35"** %1, align 8
  %4 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %3) #8
  %5 = load i64** %2, align 8
  %6 = call float @_ZN9__gnu_cxx6__stoaIffwJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(float (i32*, i32**)* @wcstof, i8* getelementptr inbounds ([5 x i8]* @.str10, i32 0, i32 0), i32* %4, i64* %5)
  ret float %6
}

; Function Attrs: uwtable
define linkonce_odr float @_ZN9__gnu_cxx6__stoaIffwJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(float (i32*, i32**)* %__convf, i8* %__name, i32* %__str, i64* %__idx) #7 {
  %1 = alloca float (i32*, i32**)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %__ret = alloca float, align 4
  %__endptr = alloca i32*, align 8
  %__tmp = alloca float, align 4
  store float (i32*, i32**)* %__convf, float (i32*, i32**)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  %5 = call i32* @__errno_location() #1
  store i32 0, i32* %5, align 4
  %6 = load float (i32*, i32**)** %1, align 8
  %7 = load i32** %3, align 8
  %8 = call float %6(i32* %7, i32** %__endptr)
  store float %8, float* %__tmp, align 4
  %9 = load i32** %__endptr, align 8
  %10 = load i32** %3, align 8
  %11 = icmp eq i32* %9, %10
  br i1 %11, label %12, label %14

; <label>:12                                      ; preds = %0
  %13 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %13) #17
  unreachable

; <label>:14                                      ; preds = %0
  %15 = call i32* @__errno_location() #1
  %16 = load i32* %15, align 4
  %17 = icmp eq i32 %16, 34
  br i1 %17, label %18, label %20

; <label>:18                                      ; preds = %14
  %19 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %19) #17
  unreachable

; <label>:20                                      ; preds = %14
  %21 = load float* %__tmp, align 4
  store float %21, float* %__ret, align 4
  br label %22

; <label>:22                                      ; preds = %20
  br label %23

; <label>:23                                      ; preds = %22
  %24 = load i64** %4, align 8
  %25 = icmp ne i64* %24, null
  br i1 %25, label %26, label %34

; <label>:26                                      ; preds = %23
  %27 = load i32** %__endptr, align 8
  %28 = load i32** %3, align 8
  %29 = ptrtoint i32* %27 to i64
  %30 = ptrtoint i32* %28 to i64
  %31 = sub i64 %29, %30
  %32 = sdiv exact i64 %31, 4
  %33 = load i64** %4, align 8
  store i64 %32, i64* %33, align 8
  br label %34

; <label>:34                                      ; preds = %26, %23
  %35 = load float* %__ret, align 4
  ret float %35
}

; Function Attrs: nounwind
declare float @wcstof(i32*, i32**) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr double @_ZSt4stodRKSbIwSt11char_traitsIwESaIwEEPm(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  %3 = load %"class.std::basic_string.35"** %1, align 8
  %4 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %3) #8
  %5 = load i64** %2, align 8
  %6 = call double @_ZN9__gnu_cxx6__stoaIddwJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(double (i32*, i32**)* @wcstod, i8* getelementptr inbounds ([5 x i8]* @.str11, i32 0, i32 0), i32* %4, i64* %5)
  ret double %6
}

; Function Attrs: uwtable
define linkonce_odr double @_ZN9__gnu_cxx6__stoaIddwJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(double (i32*, i32**)* %__convf, i8* %__name, i32* %__str, i64* %__idx) #7 {
  %1 = alloca double (i32*, i32**)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %__ret = alloca double, align 8
  %__endptr = alloca i32*, align 8
  %__tmp = alloca double, align 8
  store double (i32*, i32**)* %__convf, double (i32*, i32**)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  %5 = call i32* @__errno_location() #1
  store i32 0, i32* %5, align 4
  %6 = load double (i32*, i32**)** %1, align 8
  %7 = load i32** %3, align 8
  %8 = call double %6(i32* %7, i32** %__endptr)
  store double %8, double* %__tmp, align 8
  %9 = load i32** %__endptr, align 8
  %10 = load i32** %3, align 8
  %11 = icmp eq i32* %9, %10
  br i1 %11, label %12, label %14

; <label>:12                                      ; preds = %0
  %13 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %13) #17
  unreachable

; <label>:14                                      ; preds = %0
  %15 = call i32* @__errno_location() #1
  %16 = load i32* %15, align 4
  %17 = icmp eq i32 %16, 34
  br i1 %17, label %18, label %20

; <label>:18                                      ; preds = %14
  %19 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %19) #17
  unreachable

; <label>:20                                      ; preds = %14
  %21 = load double* %__tmp, align 8
  store double %21, double* %__ret, align 8
  br label %22

; <label>:22                                      ; preds = %20
  br label %23

; <label>:23                                      ; preds = %22
  %24 = load i64** %4, align 8
  %25 = icmp ne i64* %24, null
  br i1 %25, label %26, label %34

; <label>:26                                      ; preds = %23
  %27 = load i32** %__endptr, align 8
  %28 = load i32** %3, align 8
  %29 = ptrtoint i32* %27 to i64
  %30 = ptrtoint i32* %28 to i64
  %31 = sub i64 %29, %30
  %32 = sdiv exact i64 %31, 4
  %33 = load i64** %4, align 8
  store i64 %32, i64* %33, align 8
  br label %34

; <label>:34                                      ; preds = %26, %23
  %35 = load double* %__ret, align 8
  ret double %35
}

; Function Attrs: nounwind
declare double @wcstod(i32*, i32**) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr x86_fp80 @_ZSt5stoldRKSbIwSt11char_traitsIwESaIwEEPm(%"class.std::basic_string.35"* dereferenceable(8) %__str, i64* %__idx) #4 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i64*, align 8
  store %"class.std::basic_string.35"* %__str, %"class.std::basic_string.35"** %1, align 8
  store i64* %__idx, i64** %2, align 8
  %3 = load %"class.std::basic_string.35"** %1, align 8
  %4 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE5c_strEv(%"class.std::basic_string.35"* %3) #8
  %5 = load i64** %2, align 8
  %6 = call x86_fp80 @_ZN9__gnu_cxx6__stoaIeewJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(x86_fp80 (i32*, i32**)* @wcstold, i8* getelementptr inbounds ([6 x i8]* @.str12, i32 0, i32 0), i32* %4, i64* %5)
  ret x86_fp80 %6
}

; Function Attrs: uwtable
define linkonce_odr x86_fp80 @_ZN9__gnu_cxx6__stoaIeewJEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_(x86_fp80 (i32*, i32**)* %__convf, i8* %__name, i32* %__str, i64* %__idx) #7 {
  %1 = alloca x86_fp80 (i32*, i32**)*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64*, align 8
  %__ret = alloca x86_fp80, align 16
  %__endptr = alloca i32*, align 8
  %__tmp = alloca x86_fp80, align 16
  store x86_fp80 (i32*, i32**)* %__convf, x86_fp80 (i32*, i32**)** %1, align 8
  store i8* %__name, i8** %2, align 8
  store i32* %__str, i32** %3, align 8
  store i64* %__idx, i64** %4, align 8
  %5 = call i32* @__errno_location() #1
  store i32 0, i32* %5, align 4
  %6 = load x86_fp80 (i32*, i32**)** %1, align 8
  %7 = load i32** %3, align 8
  %8 = call x86_fp80 %6(i32* %7, i32** %__endptr)
  store x86_fp80 %8, x86_fp80* %__tmp, align 16
  %9 = load i32** %__endptr, align 8
  %10 = load i32** %3, align 8
  %11 = icmp eq i32* %9, %10
  br i1 %11, label %12, label %14

; <label>:12                                      ; preds = %0
  %13 = load i8** %2, align 8
  call void @_ZSt24__throw_invalid_argumentPKc(i8* %13) #17
  unreachable

; <label>:14                                      ; preds = %0
  %15 = call i32* @__errno_location() #1
  %16 = load i32* %15, align 4
  %17 = icmp eq i32 %16, 34
  br i1 %17, label %18, label %20

; <label>:18                                      ; preds = %14
  %19 = load i8** %2, align 8
  call void @_ZSt20__throw_out_of_rangePKc(i8* %19) #17
  unreachable

; <label>:20                                      ; preds = %14
  %21 = load x86_fp80* %__tmp, align 16
  store x86_fp80 %21, x86_fp80* %__ret, align 16
  br label %22

; <label>:22                                      ; preds = %20
  br label %23

; <label>:23                                      ; preds = %22
  %24 = load i64** %4, align 8
  %25 = icmp ne i64* %24, null
  br i1 %25, label %26, label %34

; <label>:26                                      ; preds = %23
  %27 = load i32** %__endptr, align 8
  %28 = load i32** %3, align 8
  %29 = ptrtoint i32* %27 to i64
  %30 = ptrtoint i32* %28 to i64
  %31 = sub i64 %29, %30
  %32 = sdiv exact i64 %31, 4
  %33 = load i64** %4, align 8
  store i64 %32, i64* %33, align 8
  br label %34

; <label>:34                                      ; preds = %26, %23
  %35 = load x86_fp80* %__ret, align 16
  ret x86_fp80 %35
}

; Function Attrs: nounwind
declare x86_fp80 @wcstold(i32*, i32**) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringi(%"class.std::basic_string.35"* noalias sret %agg.result, i32 %__val) #4 {
  %1 = alloca i32, align 4
  store i32 %__val, i32* %1, align 4
  %2 = load i32* %1, align 4
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 16, i32* getelementptr inbounds ([3 x i32]* @.str21, i32 0, i32 0), i32 %2)
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* noalias sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* %__convf, i64 %__n, i32* %__fmt, ...) #7 {
  %1 = alloca i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i32*, align 8
  %__s = alloca i32*, align 8
  %__args = alloca [1 x %struct.__va_list_tag], align 16
  %__len = alloca i32, align 4
  %4 = alloca %"class.std::allocator.36", align 1
  %5 = alloca i8*
  %6 = alloca i32
  store i32 (i32*, i64, i32*, %struct.__va_list_tag*)* %__convf, i32 (i32*, i64, i32*, %struct.__va_list_tag*)** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i32* %__fmt, i32** %3, align 8
  %7 = load i64* %2, align 8
  %8 = mul i64 4, %7
  %9 = alloca i8, i64 %8
  %10 = bitcast i8* %9 to i32*
  store i32* %10, i32** %__s, align 8
  %11 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %12 = bitcast %struct.__va_list_tag* %11 to i8*
  call void @llvm.va_start(i8* %12)
  %13 = load i32 (i32*, i64, i32*, %struct.__va_list_tag*)** %1, align 8
  %14 = load i32** %__s, align 8
  %15 = load i64* %2, align 8
  %16 = load i32** %3, align 8
  %17 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %18 = call i32 %13(i32* %14, i64 %15, i32* %16, %struct.__va_list_tag* %17)
  store i32 %18, i32* %__len, align 4
  %19 = getelementptr inbounds [1 x %struct.__va_list_tag]* %__args, i32 0, i32 0
  %20 = bitcast %struct.__va_list_tag* %19 to i8*
  call void @llvm.va_end(i8* %20)
  %21 = load i32** %__s, align 8
  %22 = load i32** %__s, align 8
  %23 = load i32* %__len, align 4
  %24 = sext i32 %23 to i64
  %25 = getelementptr inbounds i32* %22, i64 %24
  call void @_ZNSaIwEC1Ev(%"class.std::allocator.36"* %4) #8
  invoke void @_ZNSbIwSt11char_traitsIwESaIwEEC2IPwEET_S5_RKS1_(%"class.std::basic_string.35"* %agg.result, i32* %21, i32* %25, %"class.std::allocator.36"* dereferenceable(1) %4)
          to label %26 unwind label %27

; <label>:26                                      ; preds = %0
  call void @_ZNSaIwED1Ev(%"class.std::allocator.36"* %4) #8
  ret void

; <label>:27                                      ; preds = %0
  %28 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %29 = extractvalue { i8*, i32 } %28, 0
  store i8* %29, i8** %5
  %30 = extractvalue { i8*, i32 } %28, 1
  store i32 %30, i32* %6
  call void @_ZNSaIwED1Ev(%"class.std::allocator.36"* %4) #8
  br label %31

; <label>:31                                      ; preds = %27
  %32 = load i8** %5
  %33 = load i32* %6
  %34 = insertvalue { i8*, i32 } undef, i8* %32, 0
  %35 = insertvalue { i8*, i32 } %34, i32 %33, 1
  resume { i8*, i32 } %35
}

; Function Attrs: nounwind
declare i32 @vswprintf(i32*, i64, i32*, %struct.__va_list_tag*) #3

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringj(%"class.std::basic_string.35"* noalias sret %agg.result, i32 %__val) #4 {
  %1 = alloca i32, align 4
  store i32 %__val, i32* %1, align 4
  %2 = load i32* %1, align 4
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 16, i32* getelementptr inbounds ([3 x i32]* @.str22, i32 0, i32 0), i32 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringl(%"class.std::basic_string.35"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 32, i32* getelementptr inbounds ([4 x i32]* @.str23, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringm(%"class.std::basic_string.35"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 32, i32* getelementptr inbounds ([4 x i32]* @.str24, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringx(%"class.std::basic_string.35"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 32, i32* getelementptr inbounds ([5 x i32]* @.str25, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringy(%"class.std::basic_string.35"* noalias sret %agg.result, i64 %__val) #4 {
  %1 = alloca i64, align 8
  store i64 %__val, i64* %1, align 8
  %2 = load i64* %1, align 8
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 32, i32* getelementptr inbounds ([5 x i32]* @.str26, i32 0, i32 0), i64 %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringf(%"class.std::basic_string.35"* noalias sret %agg.result, float %__val) #4 {
  %1 = alloca float, align 4
  %__n = alloca i32, align 4
  store float %__val, float* %1, align 4
  store i32 58, i32* %__n, align 4
  %2 = load float* %1, align 4
  %3 = fpext float %2 to double
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 58, i32* getelementptr inbounds ([3 x i32]* @.str27, i32 0, i32 0), double %3)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringd(%"class.std::basic_string.35"* noalias sret %agg.result, double %__val) #4 {
  %1 = alloca double, align 8
  %__n = alloca i32, align 4
  store double %__val, double* %1, align 8
  store i32 328, i32* %__n, align 4
  %2 = load double* %1, align 8
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 328, i32* getelementptr inbounds ([3 x i32]* @.str27, i32 0, i32 0), double %2)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt10to_wstringe(%"class.std::basic_string.35"* noalias sret %agg.result, x86_fp80 %__val) #4 {
  %1 = alloca x86_fp80, align 16
  %__n = alloca i32, align 4
  store x86_fp80 %__val, x86_fp80* %1, align 16
  store i32 4952, i32* %__n, align 4
  %2 = load x86_fp80* %1, align 16
  call void (%"class.std::basic_string.35"*, i32 (i32*, i64, i32*, %struct.__va_list_tag*)*, i64, i32*, ...)* @_ZN9__gnu_cxx12__to_xstringISbIwSt11char_traitsIwESaIwEEwEET_PFiPT0_mPKS6_P13__va_list_tagEmS9_z(%"class.std::basic_string.35"* sret %agg.result, i32 (i32*, i64, i32*, %struct.__va_list_tag*)* @vswprintf, i64 4952, i32* getelementptr inbounds ([4 x i32]* @.str28, i32 0, i32 0), x86_fp80 %2)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashISsEclERKSs(%"struct.std::hash.39"* %this, %"class.std::basic_string"* dereferenceable(8) %__s) #2 align 2 {
  %1 = alloca %"struct.std::hash.39"*, align 8
  %2 = alloca %"class.std::basic_string"*, align 8
  store %"struct.std::hash.39"* %this, %"struct.std::hash.39"** %1, align 8
  store %"class.std::basic_string"* %__s, %"class.std::basic_string"** %2, align 8
  %3 = load %"struct.std::hash.39"** %1
  %4 = load %"class.std::basic_string"** %2, align 8
  %5 = call i8* @_ZNKSs4dataEv(%"class.std::basic_string"* %4) #8
  %6 = load %"class.std::basic_string"** %2, align 8
  %7 = call i64 @_ZNKSs6lengthEv(%"class.std::basic_string"* %6) #8
  %8 = invoke i64 @_ZNSt10_Hash_impl4hashEPKvmm(i8* %5, i64 %7, i64 3339675911)
          to label %9 unwind label %10

; <label>:9                                       ; preds = %0
  ret i64 %8

; <label>:10                                      ; preds = %0
  %11 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %12 = extractvalue { i8*, i32 } %11, 0
  call void @__clang_call_terminate(i8* %12) #18
  unreachable
}

; Function Attrs: nounwind
declare i8* @_ZNKSs4dataEv(%"class.std::basic_string"*) #3

; Function Attrs: nounwind
declare i64 @_ZNKSs6lengthEv(%"class.std::basic_string"*) #3

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashISbIwSt11char_traitsIwESaIwEEEclERKS3_(%"struct.std::hash.41"* %this, %"class.std::basic_string.35"* dereferenceable(8) %__s) #2 align 2 {
  %1 = alloca %"struct.std::hash.41"*, align 8
  %2 = alloca %"class.std::basic_string.35"*, align 8
  store %"struct.std::hash.41"* %this, %"struct.std::hash.41"** %1, align 8
  store %"class.std::basic_string.35"* %__s, %"class.std::basic_string.35"** %2, align 8
  %3 = load %"struct.std::hash.41"** %1
  %4 = load %"class.std::basic_string.35"** %2, align 8
  %5 = call i32* @_ZNKSbIwSt11char_traitsIwESaIwEE4dataEv(%"class.std::basic_string.35"* %4) #8
  %6 = bitcast i32* %5 to i8*
  %7 = load %"class.std::basic_string.35"** %2, align 8
  %8 = call i64 @_ZNKSbIwSt11char_traitsIwESaIwEE6lengthEv(%"class.std::basic_string.35"* %7) #8
  %9 = mul i64 %8, 4
  %10 = invoke i64 @_ZNSt10_Hash_impl4hashEPKvmm(i8* %6, i64 %9, i64 3339675911)
          to label %11 unwind label %12

; <label>:11                                      ; preds = %0
  ret i64 %10

; <label>:12                                      ; preds = %0
  %13 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %14 = extractvalue { i8*, i32 } %13, 0
  call void @__clang_call_terminate(i8* %14) #18
  unreachable
}

; Function Attrs: nounwind
declare i32* @_ZNKSbIwSt11char_traitsIwESaIwEE4dataEv(%"class.std::basic_string.35"*) #3

; Function Attrs: nounwind
declare i64 @_ZNKSbIwSt11char_traitsIwESaIwEE6lengthEv(%"class.std::basic_string.35"*) #3

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashISbIDsSt11char_traitsIDsESaIDsEEEclERKS3_(%"struct.std::hash.43"* %this, %"class.std::basic_string.45"* dereferenceable(8) %__s) #2 align 2 {
  %1 = alloca %"struct.std::hash.43"*, align 8
  %2 = alloca %"class.std::basic_string.45"*, align 8
  store %"struct.std::hash.43"* %this, %"struct.std::hash.43"** %1, align 8
  store %"class.std::basic_string.45"* %__s, %"class.std::basic_string.45"** %2, align 8
  %3 = load %"struct.std::hash.43"** %1
  %4 = load %"class.std::basic_string.45"** %2, align 8
  %5 = call i16* @_ZNKSbIDsSt11char_traitsIDsESaIDsEE4dataEv(%"class.std::basic_string.45"* %4) #8
  %6 = bitcast i16* %5 to i8*
  %7 = load %"class.std::basic_string.45"** %2, align 8
  %8 = call i64 @_ZNKSbIDsSt11char_traitsIDsESaIDsEE6lengthEv(%"class.std::basic_string.45"* %7) #8
  %9 = mul i64 %8, 2
  %10 = invoke i64 @_ZNSt10_Hash_impl4hashEPKvmm(i8* %6, i64 %9, i64 3339675911)
          to label %11 unwind label %12

; <label>:11                                      ; preds = %0
  ret i64 %10

; <label>:12                                      ; preds = %0
  %13 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %14 = extractvalue { i8*, i32 } %13, 0
  call void @__clang_call_terminate(i8* %14) #18
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr i16* @_ZNKSbIDsSt11char_traitsIDsESaIDsEE4dataEv(%"class.std::basic_string.45"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.45"*, align 8
  store %"class.std::basic_string.45"* %this, %"class.std::basic_string.45"** %1, align 8
  %2 = load %"class.std::basic_string.45"** %1
  %3 = call i16* @_ZNKSbIDsSt11char_traitsIDsESaIDsEE7_M_dataEv(%"class.std::basic_string.45"* %2) #8
  ret i16* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSbIDsSt11char_traitsIDsESaIDsEE6lengthEv(%"class.std::basic_string.45"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.45"*, align 8
  store %"class.std::basic_string.45"* %this, %"class.std::basic_string.45"** %1, align 8
  %2 = load %"class.std::basic_string.45"** %1
  %3 = call %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep"* @_ZNKSbIDsSt11char_traitsIDsESaIDsEE6_M_repEv(%"class.std::basic_string.45"* %2) #8
  %4 = bitcast %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep"* %3 to %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep_base"*
  %5 = getelementptr inbounds %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep_base"* %4, i32 0, i32 0
  %6 = load i64* %5, align 8
  ret i64 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt4hashISbIDiSt11char_traitsIDiESaIDiEEEclERKS3_(%"struct.std::hash.49"* %this, %"class.std::basic_string.51"* dereferenceable(8) %__s) #2 align 2 {
  %1 = alloca %"struct.std::hash.49"*, align 8
  %2 = alloca %"class.std::basic_string.51"*, align 8
  store %"struct.std::hash.49"* %this, %"struct.std::hash.49"** %1, align 8
  store %"class.std::basic_string.51"* %__s, %"class.std::basic_string.51"** %2, align 8
  %3 = load %"struct.std::hash.49"** %1
  %4 = load %"class.std::basic_string.51"** %2, align 8
  %5 = call i32* @_ZNKSbIDiSt11char_traitsIDiESaIDiEE4dataEv(%"class.std::basic_string.51"* %4) #8
  %6 = bitcast i32* %5 to i8*
  %7 = load %"class.std::basic_string.51"** %2, align 8
  %8 = call i64 @_ZNKSbIDiSt11char_traitsIDiESaIDiEE6lengthEv(%"class.std::basic_string.51"* %7) #8
  %9 = mul i64 %8, 4
  %10 = invoke i64 @_ZNSt10_Hash_impl4hashEPKvmm(i8* %6, i64 %9, i64 3339675911)
          to label %11 unwind label %12

; <label>:11                                      ; preds = %0
  ret i64 %10

; <label>:12                                      ; preds = %0
  %13 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %14 = extractvalue { i8*, i32 } %13, 0
  call void @__clang_call_terminate(i8* %14) #18
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNKSbIDiSt11char_traitsIDiESaIDiEE4dataEv(%"class.std::basic_string.51"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.51"*, align 8
  store %"class.std::basic_string.51"* %this, %"class.std::basic_string.51"** %1, align 8
  %2 = load %"class.std::basic_string.51"** %1
  %3 = call i32* @_ZNKSbIDiSt11char_traitsIDiESaIDiEE7_M_dataEv(%"class.std::basic_string.51"* %2) #8
  ret i32* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSbIDiSt11char_traitsIDiESaIDiEE6lengthEv(%"class.std::basic_string.51"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.51"*, align 8
  store %"class.std::basic_string.51"* %this, %"class.std::basic_string.51"** %1, align 8
  %2 = load %"class.std::basic_string.51"** %1
  %3 = call %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep"* @_ZNKSbIDiSt11char_traitsIDiESaIDiEE6_M_repEv(%"class.std::basic_string.51"* %2) #8
  %4 = bitcast %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep"* %3 to %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep_base"*
  %5 = getelementptr inbounds %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep_base"* %4, i32 0, i32 0
  %6 = load i64* %5, align 8
  ret i64 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE3minEv() #2 align 2 {
  ret i1 false
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE3maxEv() #2 align 2 {
  ret i1 true
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE6lowestEv() #2 align 2 {
  %1 = call zeroext i1 @_ZNSt14numeric_limitsIbE3minEv() #8
  ret i1 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE7epsilonEv() #2 align 2 {
  ret i1 false
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE11round_errorEv() #2 align 2 {
  ret i1 false
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE8infinityEv() #2 align 2 {
  ret i1 false
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE9quiet_NaNEv() #2 align 2 {
  ret i1 false
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE13signaling_NaNEv() #2 align 2 {
  ret i1 false
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt14numeric_limitsIbE10denorm_minEv() #2 align 2 {
  ret i1 false
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE3minEv() #2 align 2 {
  ret i8 -128
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE3maxEv() #2 align 2 {
  ret i8 127
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE6lowestEv() #2 align 2 {
  %1 = call signext i8 @_ZNSt14numeric_limitsIcE3minEv() #8
  ret i8 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE7epsilonEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE11round_errorEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE8infinityEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE9quiet_NaNEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE13signaling_NaNEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIcE10denorm_minEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE3minEv() #2 align 2 {
  ret i8 -128
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE3maxEv() #2 align 2 {
  ret i8 127
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE6lowestEv() #2 align 2 {
  %1 = call signext i8 @_ZNSt14numeric_limitsIaE3minEv() #8
  ret i8 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE7epsilonEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE11round_errorEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE8infinityEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE9quiet_NaNEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE13signaling_NaNEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNSt14numeric_limitsIaE10denorm_minEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE3minEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE3maxEv() #2 align 2 {
  ret i8 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE6lowestEv() #2 align 2 {
  %1 = call zeroext i8 @_ZNSt14numeric_limitsIhE3minEv() #8
  ret i8 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE7epsilonEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE11round_errorEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE8infinityEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE9quiet_NaNEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE13signaling_NaNEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i8 @_ZNSt14numeric_limitsIhE10denorm_minEv() #2 align 2 {
  ret i8 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE3minEv() #2 align 2 {
  ret i32 -2147483648
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE3maxEv() #2 align 2 {
  ret i32 2147483647
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE6lowestEv() #2 align 2 {
  %1 = call signext i32 @_ZNSt14numeric_limitsIwE3minEv() #8
  ret i32 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE7epsilonEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE11round_errorEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE8infinityEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE9quiet_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE13signaling_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i32 @_ZNSt14numeric_limitsIwE10denorm_minEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE3minEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE3maxEv() #2 align 2 {
  ret i16 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE6lowestEv() #2 align 2 {
  %1 = call zeroext i16 @_ZNSt14numeric_limitsIDsE3minEv() #8
  ret i16 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE7epsilonEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE11round_errorEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE8infinityEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE9quiet_NaNEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE13signaling_NaNEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsIDsE10denorm_minEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE3minEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE3maxEv() #2 align 2 {
  ret i32 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE6lowestEv() #2 align 2 {
  %1 = call zeroext i32 @_ZNSt14numeric_limitsIDiE3minEv() #8
  ret i32 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE7epsilonEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE11round_errorEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE8infinityEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE9quiet_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE13signaling_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i32 @_ZNSt14numeric_limitsIDiE10denorm_minEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE3minEv() #2 align 2 {
  ret i16 -32768
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE3maxEv() #2 align 2 {
  ret i16 32767
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE6lowestEv() #2 align 2 {
  %1 = call signext i16 @_ZNSt14numeric_limitsIsE3minEv() #8
  ret i16 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE7epsilonEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE11round_errorEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE8infinityEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE9quiet_NaNEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE13signaling_NaNEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i16 @_ZNSt14numeric_limitsIsE10denorm_minEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE3minEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE3maxEv() #2 align 2 {
  ret i16 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE6lowestEv() #2 align 2 {
  %1 = call zeroext i16 @_ZNSt14numeric_limitsItE3minEv() #8
  ret i16 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE7epsilonEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE11round_errorEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE8infinityEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE9quiet_NaNEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE13signaling_NaNEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i16 @_ZNSt14numeric_limitsItE10denorm_minEv() #2 align 2 {
  ret i16 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE3minEv() #2 align 2 {
  ret i32 -2147483648
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE3maxEv() #2 align 2 {
  ret i32 2147483647
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE6lowestEv() #2 align 2 {
  %1 = call i32 @_ZNSt14numeric_limitsIiE3minEv() #8
  ret i32 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE7epsilonEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE11round_errorEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE8infinityEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE9quiet_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE13signaling_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIiE10denorm_minEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE3minEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE3maxEv() #2 align 2 {
  ret i32 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE6lowestEv() #2 align 2 {
  %1 = call i32 @_ZNSt14numeric_limitsIjE3minEv() #8
  ret i32 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE7epsilonEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE11round_errorEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE8infinityEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE9quiet_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE13signaling_NaNEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt14numeric_limitsIjE10denorm_minEv() #2 align 2 {
  ret i32 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE3minEv() #2 align 2 {
  ret i64 -9223372036854775808
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE3maxEv() #2 align 2 {
  ret i64 9223372036854775807
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE6lowestEv() #2 align 2 {
  %1 = call i64 @_ZNSt14numeric_limitsIlE3minEv() #8
  ret i64 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE7epsilonEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE11round_errorEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE8infinityEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE9quiet_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE13signaling_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIlE10denorm_minEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE3minEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE3maxEv() #2 align 2 {
  ret i64 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE6lowestEv() #2 align 2 {
  %1 = call i64 @_ZNSt14numeric_limitsImE3minEv() #8
  ret i64 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE7epsilonEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE11round_errorEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE8infinityEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE9quiet_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE13signaling_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsImE10denorm_minEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE3minEv() #2 align 2 {
  ret i64 -9223372036854775808
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE3maxEv() #2 align 2 {
  ret i64 9223372036854775807
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE6lowestEv() #2 align 2 {
  %1 = call i64 @_ZNSt14numeric_limitsIxE3minEv() #8
  ret i64 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE7epsilonEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE11round_errorEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE8infinityEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE9quiet_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE13signaling_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIxE10denorm_minEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE3minEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE3maxEv() #2 align 2 {
  ret i64 -1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE6lowestEv() #2 align 2 {
  %1 = call i64 @_ZNSt14numeric_limitsIyE3minEv() #8
  ret i64 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE7epsilonEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE11round_errorEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE8infinityEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE9quiet_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE13signaling_NaNEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt14numeric_limitsIyE10denorm_minEv() #2 align 2 {
  ret i64 0
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE3minEv() #2 align 2 {
  ret float 0x3810000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE3maxEv() #2 align 2 {
  ret float 0x47EFFFFFE0000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE6lowestEv() #2 align 2 {
  ret float 0xC7EFFFFFE0000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE7epsilonEv() #2 align 2 {
  ret float 0x3E80000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE11round_errorEv() #2 align 2 {
  ret float 5.000000e-01
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE8infinityEv() #2 align 2 {
  ret float 0x7FF0000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE9quiet_NaNEv() #2 align 2 {
  ret float 0x7FF8000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE13signaling_NaNEv() #2 align 2 {
  ret float 0x7FF4000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr float @_ZNSt14numeric_limitsIfE10denorm_minEv() #2 align 2 {
  ret float 0x36A0000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE3minEv() #2 align 2 {
  ret double 0x10000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE3maxEv() #2 align 2 {
  ret double 0x7FEFFFFFFFFFFFFF
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE6lowestEv() #2 align 2 {
  ret double 0xFFEFFFFFFFFFFFFF
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE7epsilonEv() #2 align 2 {
  ret double 0x3CB0000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE11round_errorEv() #2 align 2 {
  ret double 5.000000e-01
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE8infinityEv() #2 align 2 {
  ret double 0x7FF0000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE9quiet_NaNEv() #2 align 2 {
  ret double 0x7FF8000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE13signaling_NaNEv() #2 align 2 {
  ret double 0x7FF4000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNSt14numeric_limitsIdE10denorm_minEv() #2 align 2 {
  ret double 4.940656e-324
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE3minEv() #2 align 2 {
  ret x86_fp80 0xK00018000000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE3maxEv() #2 align 2 {
  ret x86_fp80 0xK7FFEFFFFFFFFFFFFFFFF
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE6lowestEv() #2 align 2 {
  ret x86_fp80 0xKFFFEFFFFFFFFFFFFFFFF
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE7epsilonEv() #2 align 2 {
  ret x86_fp80 0xK3FC08000000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE11round_errorEv() #2 align 2 {
  ret x86_fp80 0xK3FFE8000000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE8infinityEv() #2 align 2 {
  ret x86_fp80 0xK7FFF8000000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE9quiet_NaNEv() #2 align 2 {
  ret x86_fp80 0xK7FFFC000000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE13signaling_NaNEv() #2 align 2 {
  ret x86_fp80 0xK7FFFA000000000000000
}

; Function Attrs: nounwind uwtable
define linkonce_odr x86_fp80 @_ZNSt14numeric_limitsIeE10denorm_minEv() #2 align 2 {
  ret x86_fp80 0xK00000000000000000001
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt13random_deviceC2ERKSs(%"class.std::random_device"* %this, %"class.std::basic_string"* dereferenceable(8) %__token) unnamed_addr #7 align 2 {
  %1 = alloca %"class.std::random_device"*, align 8
  %2 = alloca %"class.std::basic_string"*, align 8
  store %"class.std::random_device"* %this, %"class.std::random_device"** %1, align 8
  store %"class.std::basic_string"* %__token, %"class.std::basic_string"** %2, align 8
  %3 = load %"class.std::random_device"** %1
  %4 = load %"class.std::basic_string"** %2, align 8
  call void @_ZNSt13random_device7_M_initERKSs(%"class.std::random_device"* %3, %"class.std::basic_string"* dereferenceable(8) %4)
  ret void
}

declare void @_ZNSt13random_device7_M_initERKSs(%"class.std::random_device"*, %"class.std::basic_string"* dereferenceable(8)) #9

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt13random_deviceD2Ev(%"class.std::random_device"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::random_device"*, align 8
  store %"class.std::random_device"* %this, %"class.std::random_device"** %1, align 8
  %2 = load %"class.std::random_device"** %1
  invoke void @_ZNSt13random_device7_M_finiEv(%"class.std::random_device"* %2)
          to label %3 unwind label %4

; <label>:3                                       ; preds = %0
  ret void

; <label>:4                                       ; preds = %0
  %5 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %6 = extractvalue { i8*, i32 } %5, 0
  call void @__clang_call_terminate(i8* %6) #18
  unreachable
}

declare void @_ZNSt13random_device7_M_finiEv(%"class.std::random_device"*) #9

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt13random_device3minEv() #2 align 2 {
  %1 = call i32 @_ZNSt14numeric_limitsIjE3minEv() #8
  ret i32 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt13random_device3maxEv() #2 align 2 {
  %1 = call i32 @_ZNSt14numeric_limitsIjE3maxEv() #8
  ret i32 %1
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNKSt13random_device7entropyEv(%"class.std::random_device"* %this) #2 align 2 {
  %1 = alloca %"class.std::random_device"*, align 8
  store %"class.std::random_device"* %this, %"class.std::random_device"** %1, align 8
  %2 = load %"class.std::random_device"** %1
  ret double 0.000000e+00
}

; Function Attrs: uwtable
define linkonce_odr i32 @_ZNSt13random_deviceclEv(%"class.std::random_device"* %this) #7 align 2 {
  %1 = alloca %"class.std::random_device"*, align 8
  store %"class.std::random_device"* %this, %"class.std::random_device"** %1, align 8
  %2 = load %"class.std::random_device"** %1
  %3 = call i32 @_ZNSt13random_device9_M_getvalEv(%"class.std::random_device"* %2)
  ret i32 %3
}

declare i32 @_ZNSt13random_device9_M_getvalEv(%"class.std::random_device"*) #9

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNKSt22bernoulli_distribution10param_type1pEv(%"struct.std::bernoulli_distribution::param_type"* %this) #2 align 2 {
  %1 = alloca %"struct.std::bernoulli_distribution::param_type"*, align 8
  store %"struct.std::bernoulli_distribution::param_type"* %this, %"struct.std::bernoulli_distribution::param_type"** %1, align 8
  %2 = load %"struct.std::bernoulli_distribution::param_type"** %1
  %3 = getelementptr inbounds %"struct.std::bernoulli_distribution::param_type"* %2, i32 0, i32 0
  %4 = load double* %3, align 8
  ret double %4
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt22bernoulli_distributionC2Ed(%"class.std::bernoulli_distribution"* %this, double %__p) unnamed_addr #7 align 2 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  %2 = alloca double, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %1, align 8
  store double %__p, double* %2, align 8
  %3 = load %"class.std::bernoulli_distribution"** %1
  %4 = getelementptr inbounds %"class.std::bernoulli_distribution"* %3, i32 0, i32 0
  %5 = load double* %2, align 8
  call void @_ZNSt22bernoulli_distribution10param_typeC2Ed(%"struct.std::bernoulli_distribution::param_type"* %4, double %5)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt22bernoulli_distribution10param_typeC2Ed(%"struct.std::bernoulli_distribution::param_type"* %this, double %__p) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::bernoulli_distribution::param_type"*, align 8
  %2 = alloca double, align 8
  store %"struct.std::bernoulli_distribution::param_type"* %this, %"struct.std::bernoulli_distribution::param_type"** %1, align 8
  store double %__p, double* %2, align 8
  %3 = load %"struct.std::bernoulli_distribution::param_type"** %1
  %4 = getelementptr inbounds %"struct.std::bernoulli_distribution::param_type"* %3, i32 0, i32 0
  %5 = load double* %2, align 8
  store double %5, double* %4, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt22bernoulli_distributionC2ERKNS_10param_typeE(%"class.std::bernoulli_distribution"* %this, %"struct.std::bernoulli_distribution::param_type"* dereferenceable(8) %__p) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  %2 = alloca %"struct.std::bernoulli_distribution::param_type"*, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %1, align 8
  store %"struct.std::bernoulli_distribution::param_type"* %__p, %"struct.std::bernoulli_distribution::param_type"** %2, align 8
  %3 = load %"class.std::bernoulli_distribution"** %1
  %4 = getelementptr inbounds %"class.std::bernoulli_distribution"* %3, i32 0, i32 0
  %5 = load %"struct.std::bernoulli_distribution::param_type"** %2, align 8
  %6 = bitcast %"struct.std::bernoulli_distribution::param_type"* %4 to i8*
  %7 = bitcast %"struct.std::bernoulli_distribution::param_type"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 8, i32 8, i1 false)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt22bernoulli_distribution5resetEv(%"class.std::bernoulli_distribution"* %this) #2 align 2 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %1, align 8
  %2 = load %"class.std::bernoulli_distribution"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNKSt22bernoulli_distribution1pEv(%"class.std::bernoulli_distribution"* %this) #2 align 2 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %1, align 8
  %2 = load %"class.std::bernoulli_distribution"** %1
  %3 = getelementptr inbounds %"class.std::bernoulli_distribution"* %2, i32 0, i32 0
  %4 = call double @_ZNKSt22bernoulli_distribution10param_type1pEv(%"struct.std::bernoulli_distribution::param_type"* %3)
  ret double %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr double @_ZNKSt22bernoulli_distribution5paramEv(%"class.std::bernoulli_distribution"* %this) #2 align 2 {
  %1 = alloca %"struct.std::bernoulli_distribution::param_type", align 8
  %2 = alloca %"class.std::bernoulli_distribution"*, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %2, align 8
  %3 = load %"class.std::bernoulli_distribution"** %2
  %4 = getelementptr inbounds %"class.std::bernoulli_distribution"* %3, i32 0, i32 0
  %5 = bitcast %"struct.std::bernoulli_distribution::param_type"* %1 to i8*
  %6 = bitcast %"struct.std::bernoulli_distribution::param_type"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %5, i8* %6, i64 8, i32 8, i1 false)
  %7 = getelementptr %"struct.std::bernoulli_distribution::param_type"* %1, i32 0, i32 0
  %8 = load double* %7, align 1
  ret double %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt22bernoulli_distribution5paramERKNS_10param_typeE(%"class.std::bernoulli_distribution"* %this, %"struct.std::bernoulli_distribution::param_type"* dereferenceable(8) %__param) #2 align 2 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  %2 = alloca %"struct.std::bernoulli_distribution::param_type"*, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %1, align 8
  store %"struct.std::bernoulli_distribution::param_type"* %__param, %"struct.std::bernoulli_distribution::param_type"** %2, align 8
  %3 = load %"class.std::bernoulli_distribution"** %1
  %4 = getelementptr inbounds %"class.std::bernoulli_distribution"* %3, i32 0, i32 0
  %5 = load %"struct.std::bernoulli_distribution::param_type"** %2, align 8
  %6 = bitcast %"struct.std::bernoulli_distribution::param_type"* %4 to i8*
  %7 = bitcast %"struct.std::bernoulli_distribution::param_type"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 8, i32 8, i1 false)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt22bernoulli_distribution3minEv(%"class.std::bernoulli_distribution"* %this) #2 align 2 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %1, align 8
  %2 = load %"class.std::bernoulli_distribution"** %1
  %3 = call zeroext i1 @_ZNSt14numeric_limitsIbE3minEv() #8
  ret i1 %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt22bernoulli_distribution3maxEv(%"class.std::bernoulli_distribution"* %this) #2 align 2 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  store %"class.std::bernoulli_distribution"* %this, %"class.std::bernoulli_distribution"** %1, align 8
  %2 = load %"class.std::bernoulli_distribution"** %1
  %3 = call zeroext i1 @_ZNSt14numeric_limitsIbE3maxEv() #8
  ret i1 %3
}

; Function Attrs: inlinehint uwtable
define linkonce_odr zeroext i1 @_ZStneRKSt22bernoulli_distributionS1_(%"class.std::bernoulli_distribution"* dereferenceable(8) %__d1, %"class.std::bernoulli_distribution"* dereferenceable(8) %__d2) #4 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  %2 = alloca %"class.std::bernoulli_distribution"*, align 8
  store %"class.std::bernoulli_distribution"* %__d1, %"class.std::bernoulli_distribution"** %1, align 8
  store %"class.std::bernoulli_distribution"* %__d2, %"class.std::bernoulli_distribution"** %2, align 8
  %3 = load %"class.std::bernoulli_distribution"** %1, align 8
  %4 = load %"class.std::bernoulli_distribution"** %2, align 8
  %5 = call zeroext i1 @_ZSteqRKSt22bernoulli_distributionS1_(%"class.std::bernoulli_distribution"* dereferenceable(8) %3, %"class.std::bernoulli_distribution"* dereferenceable(8) %4)
  %6 = xor i1 %5, true
  ret i1 %6
}

; Function Attrs: uwtable
define linkonce_odr zeroext i1 @_ZSteqRKSt22bernoulli_distributionS1_(%"class.std::bernoulli_distribution"* dereferenceable(8) %__d1, %"class.std::bernoulli_distribution"* dereferenceable(8) %__d2) #7 {
  %1 = alloca %"class.std::bernoulli_distribution"*, align 8
  %2 = alloca %"class.std::bernoulli_distribution"*, align 8
  store %"class.std::bernoulli_distribution"* %__d1, %"class.std::bernoulli_distribution"** %1, align 8
  store %"class.std::bernoulli_distribution"* %__d2, %"class.std::bernoulli_distribution"** %2, align 8
  %3 = load %"class.std::bernoulli_distribution"** %1, align 8
  %4 = getelementptr inbounds %"class.std::bernoulli_distribution"* %3, i32 0, i32 0
  %5 = load %"class.std::bernoulli_distribution"** %2, align 8
  %6 = getelementptr inbounds %"class.std::bernoulli_distribution"* %5, i32 0, i32 0
  %7 = call zeroext i1 @_ZSteqRKNSt22bernoulli_distribution10param_typeES2_(%"struct.std::bernoulli_distribution::param_type"* dereferenceable(8) %4, %"struct.std::bernoulli_distribution::param_type"* dereferenceable(8) %6)
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt8seed_seqC2Ev(%"class.std::seed_seq"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::seed_seq"*, align 8
  store %"class.std::seed_seq"* %this, %"class.std::seed_seq"** %1, align 8
  %2 = load %"class.std::seed_seq"** %1
  %3 = getelementptr inbounds %"class.std::seed_seq"* %2, i32 0, i32 0
  call void @_ZNSt6vectorIjSaIjEEC2Ev(%"class.std::vector.55"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6vectorIjSaIjEEC2Ev(%"class.std::vector.55"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::vector.55"*, align 8
  store %"class.std::vector.55"* %this, %"class.std::vector.55"** %1, align 8
  %2 = load %"class.std::vector.55"** %1
  %3 = bitcast %"class.std::vector.55"* %2 to %"struct.std::_Vector_base.56"*
  invoke void @_ZNSt12_Vector_baseIjSaIjEEC2Ev(%"struct.std::_Vector_base.56"* %3)
          to label %4 unwind label %5

; <label>:4                                       ; preds = %0
  ret void

; <label>:5                                       ; preds = %0
  %6 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %7 = extractvalue { i8*, i32 } %6, 0
  call void @__clang_call_terminate(i8* %7) #18
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt8seed_seq4sizeEv(%"class.std::seed_seq"* %this) #2 align 2 {
  %1 = alloca %"class.std::seed_seq"*, align 8
  store %"class.std::seed_seq"* %this, %"class.std::seed_seq"** %1, align 8
  %2 = load %"class.std::seed_seq"** %1
  %3 = getelementptr inbounds %"class.std::seed_seq"* %2, i32 0, i32 0
  %4 = call i64 @_ZNKSt6vectorIjSaIjEE4sizeEv(%"class.std::vector.55"* %3) #8
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt6vectorIjSaIjEE4sizeEv(%"class.std::vector.55"* %this) #2 align 2 {
  %1 = alloca %"class.std::vector.55"*, align 8
  store %"class.std::vector.55"* %this, %"class.std::vector.55"** %1, align 8
  %2 = load %"class.std::vector.55"** %1
  %3 = bitcast %"class.std::vector.55"* %2 to %"struct.std::_Vector_base.56"*
  %4 = getelementptr inbounds %"struct.std::_Vector_base.56"* %3, i32 0, i32 0
  %5 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %4, i32 0, i32 1
  %6 = load i32** %5, align 8
  %7 = bitcast %"class.std::vector.55"* %2 to %"struct.std::_Vector_base.56"*
  %8 = getelementptr inbounds %"struct.std::_Vector_base.56"* %7, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %8, i32 0, i32 0
  %10 = load i32** %9, align 8
  %11 = ptrtoint i32* %6 to i64
  %12 = ptrtoint i32* %10 to i64
  %13 = sub i64 %11, %12
  %14 = sdiv exact i64 %13, 4
  ret i64 %14
}

; Function Attrs: nounwind
declare i64 @llvm.x86.rdpmc(i32) #8

; Function Attrs: nounwind
declare i64 @llvm.x86.rdtsc() #8

; Function Attrs: nounwind
declare i64 @llvm.x86.rdtscp(i8*) #8

; Function Attrs: nounwind
declare void @llvm.x86.mmx.emms() #8

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL14_mm_packs_pi16Dv1_xS_(i64 %__m1.coerce, i64 %__m2.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = bitcast <1 x i64>* %2 to i64*
  store i64 %__m1.coerce, i64* %6, align 1
  %__m1 = load <1 x i64>* %2, align 8
  %7 = bitcast <1 x i64>* %3 to i64*
  store i64 %__m2.coerce, i64* %7, align 1
  %__m2 = load <1 x i64>* %3, align 8
  store <1 x i64> %__m1, <1 x i64>* %4, align 8
  store <1 x i64> %__m2, <1 x i64>* %5, align 8
  %8 = load <1 x i64>* %4, align 8
  %9 = bitcast <1 x i64> %8 to <4 x i16>
  %10 = bitcast <4 x i16> %9 to x86_mmx
  %11 = load <1 x i64>* %5, align 8
  %12 = bitcast <1 x i64> %11 to <4 x i16>
  %13 = bitcast <4 x i16> %12 to x86_mmx
  %14 = call x86_mmx @llvm.x86.mmx.packsswb(x86_mmx %10, x86_mmx %13)
  %15 = bitcast x86_mmx %14 to <8 x i8>
  %16 = bitcast <8 x i8> %15 to <1 x i64>
  store <1 x i64> %16, <1 x i64>* %1
  %17 = bitcast <1 x i64>* %1 to i64*
  %18 = load i64* %17, align 1
  ret i64 %18
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.packsswb(x86_mmx, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL14_mm_packs_pi32Dv1_xS_(i64 %__m1.coerce, i64 %__m2.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = bitcast <1 x i64>* %2 to i64*
  store i64 %__m1.coerce, i64* %6, align 1
  %__m1 = load <1 x i64>* %2, align 8
  %7 = bitcast <1 x i64>* %3 to i64*
  store i64 %__m2.coerce, i64* %7, align 1
  %__m2 = load <1 x i64>* %3, align 8
  store <1 x i64> %__m1, <1 x i64>* %4, align 8
  store <1 x i64> %__m2, <1 x i64>* %5, align 8
  %8 = load <1 x i64>* %4, align 8
  %9 = bitcast <1 x i64> %8 to <2 x i32>
  %10 = bitcast <2 x i32> %9 to x86_mmx
  %11 = load <1 x i64>* %5, align 8
  %12 = bitcast <1 x i64> %11 to <2 x i32>
  %13 = bitcast <2 x i32> %12 to x86_mmx
  %14 = call x86_mmx @llvm.x86.mmx.packssdw(x86_mmx %10, x86_mmx %13)
  %15 = bitcast x86_mmx %14 to <4 x i16>
  %16 = bitcast <4 x i16> %15 to <1 x i64>
  store <1 x i64> %16, <1 x i64>* %1
  %17 = bitcast <1 x i64>* %1 to i64*
  %18 = load i64* %17, align 1
  ret i64 %18
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.packssdw(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.packuswb(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.punpckhbw(x86_mmx, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL17_mm_unpackhi_pi16Dv1_xS_(i64 %__m1.coerce, i64 %__m2.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = bitcast <1 x i64>* %2 to i64*
  store i64 %__m1.coerce, i64* %6, align 1
  %__m1 = load <1 x i64>* %2, align 8
  %7 = bitcast <1 x i64>* %3 to i64*
  store i64 %__m2.coerce, i64* %7, align 1
  %__m2 = load <1 x i64>* %3, align 8
  store <1 x i64> %__m1, <1 x i64>* %4, align 8
  store <1 x i64> %__m2, <1 x i64>* %5, align 8
  %8 = load <1 x i64>* %4, align 8
  %9 = bitcast <1 x i64> %8 to <4 x i16>
  %10 = bitcast <4 x i16> %9 to x86_mmx
  %11 = load <1 x i64>* %5, align 8
  %12 = bitcast <1 x i64> %11 to <4 x i16>
  %13 = bitcast <4 x i16> %12 to x86_mmx
  %14 = call x86_mmx @llvm.x86.mmx.punpckhwd(x86_mmx %10, x86_mmx %13)
  %15 = bitcast x86_mmx %14 to <4 x i16>
  %16 = bitcast <4 x i16> %15 to <1 x i64>
  store <1 x i64> %16, <1 x i64>* %1
  %17 = bitcast <1 x i64>* %1 to i64*
  %18 = load i64* %17, align 1
  ret i64 %18
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.punpckhwd(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.punpckhdq(x86_mmx, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL16_mm_unpacklo_pi8Dv1_xS_(i64 %__m1.coerce, i64 %__m2.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = bitcast <1 x i64>* %2 to i64*
  store i64 %__m1.coerce, i64* %6, align 1
  %__m1 = load <1 x i64>* %2, align 8
  %7 = bitcast <1 x i64>* %3 to i64*
  store i64 %__m2.coerce, i64* %7, align 1
  %__m2 = load <1 x i64>* %3, align 8
  store <1 x i64> %__m1, <1 x i64>* %4, align 8
  store <1 x i64> %__m2, <1 x i64>* %5, align 8
  %8 = load <1 x i64>* %4, align 8
  %9 = bitcast <1 x i64> %8 to <8 x i8>
  %10 = bitcast <8 x i8> %9 to x86_mmx
  %11 = load <1 x i64>* %5, align 8
  %12 = bitcast <1 x i64> %11 to <8 x i8>
  %13 = bitcast <8 x i8> %12 to x86_mmx
  %14 = call x86_mmx @llvm.x86.mmx.punpcklbw(x86_mmx %10, x86_mmx %13)
  %15 = bitcast x86_mmx %14 to <8 x i8>
  %16 = bitcast <8 x i8> %15 to <1 x i64>
  store <1 x i64> %16, <1 x i64>* %1
  %17 = bitcast <1 x i64>* %1 to i64*
  %18 = load i64* %17, align 1
  ret i64 %18
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.punpcklbw(x86_mmx, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL17_mm_unpacklo_pi16Dv1_xS_(i64 %__m1.coerce, i64 %__m2.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = bitcast <1 x i64>* %2 to i64*
  store i64 %__m1.coerce, i64* %6, align 1
  %__m1 = load <1 x i64>* %2, align 8
  %7 = bitcast <1 x i64>* %3 to i64*
  store i64 %__m2.coerce, i64* %7, align 1
  %__m2 = load <1 x i64>* %3, align 8
  store <1 x i64> %__m1, <1 x i64>* %4, align 8
  store <1 x i64> %__m2, <1 x i64>* %5, align 8
  %8 = load <1 x i64>* %4, align 8
  %9 = bitcast <1 x i64> %8 to <4 x i16>
  %10 = bitcast <4 x i16> %9 to x86_mmx
  %11 = load <1 x i64>* %5, align 8
  %12 = bitcast <1 x i64> %11 to <4 x i16>
  %13 = bitcast <4 x i16> %12 to x86_mmx
  %14 = call x86_mmx @llvm.x86.mmx.punpcklwd(x86_mmx %10, x86_mmx %13)
  %15 = bitcast x86_mmx %14 to <4 x i16>
  %16 = bitcast <4 x i16> %15 to <1 x i64>
  store <1 x i64> %16, <1 x i64>* %1
  %17 = bitcast <1 x i64>* %1 to i64*
  %18 = load i64* %17, align 1
  ret i64 %18
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.punpcklwd(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.punpckldq(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.padd.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.padd.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.padd.d(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.padds.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.padds.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.paddus.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.paddus.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psub.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psub.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psub.d(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psubs.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psubs.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psubus.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psubus.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmadd.wd(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmulh.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmull.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psll.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pslli.w(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psll.d(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pslli.d(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psll.q(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pslli.q(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psra.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrai.w(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psra.d(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrai.d(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrl.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrli.w(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrl.d(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrli.d(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrl.q(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psrli.q(x86_mmx, i32) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pand(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pandn(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.por(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pxor(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pcmpeq.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pcmpeq.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pcmpeq.d(x86_mmx, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL13_mm_cmpgt_pi8Dv1_xS_(i64 %__m1.coerce, i64 %__m2.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = bitcast <1 x i64>* %2 to i64*
  store i64 %__m1.coerce, i64* %6, align 1
  %__m1 = load <1 x i64>* %2, align 8
  %7 = bitcast <1 x i64>* %3 to i64*
  store i64 %__m2.coerce, i64* %7, align 1
  %__m2 = load <1 x i64>* %3, align 8
  store <1 x i64> %__m1, <1 x i64>* %4, align 8
  store <1 x i64> %__m2, <1 x i64>* %5, align 8
  %8 = load <1 x i64>* %4, align 8
  %9 = bitcast <1 x i64> %8 to <8 x i8>
  %10 = bitcast <8 x i8> %9 to x86_mmx
  %11 = load <1 x i64>* %5, align 8
  %12 = bitcast <1 x i64> %11 to <8 x i8>
  %13 = bitcast <8 x i8> %12 to x86_mmx
  %14 = call x86_mmx @llvm.x86.mmx.pcmpgt.b(x86_mmx %10, x86_mmx %13)
  %15 = bitcast x86_mmx %14 to <8 x i8>
  %16 = bitcast <8 x i8> %15 to <1 x i64>
  store <1 x i64> %16, <1 x i64>* %1
  %17 = bitcast <1 x i64>* %1 to i64*
  %18 = load i64* %17, align 1
  ret i64 %18
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pcmpgt.b(x86_mmx, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL14_mm_cmpgt_pi16Dv1_xS_(i64 %__m1.coerce, i64 %__m2.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = bitcast <1 x i64>* %2 to i64*
  store i64 %__m1.coerce, i64* %6, align 1
  %__m1 = load <1 x i64>* %2, align 8
  %7 = bitcast <1 x i64>* %3 to i64*
  store i64 %__m2.coerce, i64* %7, align 1
  %__m2 = load <1 x i64>* %3, align 8
  store <1 x i64> %__m1, <1 x i64>* %4, align 8
  store <1 x i64> %__m2, <1 x i64>* %5, align 8
  %8 = load <1 x i64>* %4, align 8
  %9 = bitcast <1 x i64> %8 to <4 x i16>
  %10 = bitcast <4 x i16> %9 to x86_mmx
  %11 = load <1 x i64>* %5, align 8
  %12 = bitcast <1 x i64> %11 to <4 x i16>
  %13 = bitcast <4 x i16> %12 to x86_mmx
  %14 = call x86_mmx @llvm.x86.mmx.pcmpgt.w(x86_mmx %10, x86_mmx %13)
  %15 = bitcast x86_mmx %14 to <4 x i16>
  %16 = bitcast <4 x i16> %15 to <1 x i64>
  store <1 x i64> %16, <1 x i64>* %1
  %17 = bitcast <1 x i64>* %1 to i64*
  %18 = load i64* %17, align 1
  ret i64 %18
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pcmpgt.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pcmpgt.d(x86_mmx, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL16_mm_setzero_si64v() #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  store <1 x i64> zeroinitializer, <1 x i64>* %2
  %3 = load <1 x i64>* %2
  store <1 x i64> %3, <1 x i64>* %1
  %4 = bitcast <1 x i64>* %1 to i64*
  %5 = load i64* %4, align 1
  ret i64 %5
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL12_mm_set_pi32ii(i32 %__i1, i32 %__i0) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %__i1, i32* %2, align 4
  store i32 %__i0, i32* %3, align 4
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = insertelement <2 x i32> undef, i32 %4, i32 0
  %7 = insertelement <2 x i32> %6, i32 %5, i32 1
  %8 = bitcast <2 x i32> %7 to x86_mmx
  %9 = bitcast x86_mmx %8 to <1 x i64>
  store <1 x i64> %9, <1 x i64>* %1
  %10 = bitcast <1 x i64>* %1 to i64*
  %11 = load i64* %10, align 1
  ret i64 %11
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL12_mm_set_pi16ssss(i16 signext %__s3, i16 signext %__s2, i16 signext %__s1, i16 signext %__s0) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca i16, align 2
  %3 = alloca i16, align 2
  %4 = alloca i16, align 2
  %5 = alloca i16, align 2
  store i16 %__s3, i16* %2, align 2
  store i16 %__s2, i16* %3, align 2
  store i16 %__s1, i16* %4, align 2
  store i16 %__s0, i16* %5, align 2
  %6 = load i16* %5, align 2
  %7 = load i16* %4, align 2
  %8 = load i16* %3, align 2
  %9 = load i16* %2, align 2
  %10 = insertelement <4 x i16> undef, i16 %6, i32 0
  %11 = insertelement <4 x i16> %10, i16 %7, i32 1
  %12 = insertelement <4 x i16> %11, i16 %8, i32 2
  %13 = insertelement <4 x i16> %12, i16 %9, i32 3
  %14 = bitcast <4 x i16> %13 to x86_mmx
  %15 = bitcast x86_mmx %14 to <1 x i64>
  store <1 x i64> %15, <1 x i64>* %1
  %16 = bitcast <1 x i64>* %1 to i64*
  %17 = load i64* %16, align 1
  ret i64 %17
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL11_mm_set_pi8cccccccc(i8 signext %__b7, i8 signext %__b6, i8 signext %__b5, i8 signext %__b4, i8 signext %__b3, i8 signext %__b2, i8 signext %__b1, i8 signext %__b0) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca i8, align 1
  %3 = alloca i8, align 1
  %4 = alloca i8, align 1
  %5 = alloca i8, align 1
  %6 = alloca i8, align 1
  %7 = alloca i8, align 1
  %8 = alloca i8, align 1
  %9 = alloca i8, align 1
  store i8 %__b7, i8* %2, align 1
  store i8 %__b6, i8* %3, align 1
  store i8 %__b5, i8* %4, align 1
  store i8 %__b4, i8* %5, align 1
  store i8 %__b3, i8* %6, align 1
  store i8 %__b2, i8* %7, align 1
  store i8 %__b1, i8* %8, align 1
  store i8 %__b0, i8* %9, align 1
  %10 = load i8* %9, align 1
  %11 = load i8* %8, align 1
  %12 = load i8* %7, align 1
  %13 = load i8* %6, align 1
  %14 = load i8* %5, align 1
  %15 = load i8* %4, align 1
  %16 = load i8* %3, align 1
  %17 = load i8* %2, align 1
  %18 = insertelement <8 x i8> undef, i8 %10, i32 0
  %19 = insertelement <8 x i8> %18, i8 %11, i32 1
  %20 = insertelement <8 x i8> %19, i8 %12, i32 2
  %21 = insertelement <8 x i8> %20, i8 %13, i32 3
  %22 = insertelement <8 x i8> %21, i8 %14, i32 4
  %23 = insertelement <8 x i8> %22, i8 %15, i32 5
  %24 = insertelement <8 x i8> %23, i8 %16, i32 6
  %25 = insertelement <8 x i8> %24, i8 %17, i32 7
  %26 = bitcast <8 x i8> %25 to x86_mmx
  %27 = bitcast x86_mmx %26 to <1 x i64>
  store <1 x i64> %27, <1 x i64>* %1
  %28 = bitcast <1 x i64>* %1 to i64*
  %29 = load i64* %28, align 1
  ret i64 %29
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #3

; Function Attrs: nounwind
declare i32 @posix_memalign(i8**, i64, i64) #3

; Function Attrs: nounwind
declare void @free(i8*) #3

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.sqrt.ss(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.sqrt.ps(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.rcp.ss(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.rcp.ps(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.rsqrt.ss(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.rsqrt.ps(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.min.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.min.ps(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.max.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.max.ps(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.cmp.ss(<4 x float>, <4 x float>, i8) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.cmp.ps(<4 x float>, <4 x float>, i8) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.comieq.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.comilt.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.comile.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.comigt.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.comige.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.comineq.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.ucomieq.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.ucomilt.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.ucomile.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.ucomigt.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.ucomige.ss(<4 x float>, <4 x float>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.ucomineq.ss(<4 x float>, <4 x float>) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i32 @_ZL14_mm_cvtss_si32Dv4_f(<4 x float> %__a) #14 {
  %1 = alloca <4 x float>, align 16
  store <4 x float> %__a, <4 x float>* %1, align 16
  %2 = load <4 x float>* %1, align 16
  %3 = call i32 @llvm.x86.sse.cvtss2si(<4 x float> %2)
  ret i32 %3
}

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.cvtss2si(<4 x float>) #1

; Function Attrs: nounwind readnone
declare i64 @llvm.x86.sse.cvtss2si64(<4 x float>) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL14_mm_cvtps_pi32Dv4_f(<4 x float> %__a) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <4 x float>, align 16
  store <4 x float> %__a, <4 x float>* %2, align 16
  %3 = load <4 x float>* %2, align 16
  %4 = call x86_mmx @llvm.x86.sse.cvtps2pi(<4 x float> %3)
  %5 = bitcast x86_mmx %4 to <2 x i32>
  %6 = bitcast <2 x i32> %5 to <1 x i64>
  store <1 x i64> %6, <1 x i64>* %1
  %7 = bitcast <1 x i64>* %1 to i64*
  %8 = load i64* %7, align 1
  ret i64 %8
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.sse.cvtps2pi(<4 x float>) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i32 @_ZL15_mm_cvttss_si32Dv4_f(<4 x float> %__a) #14 {
  %1 = alloca <4 x float>, align 16
  store <4 x float> %__a, <4 x float>* %1, align 16
  %2 = load <4 x float>* %1, align 16
  %3 = extractelement <4 x float> %2, i32 0
  %4 = fptosi float %3 to i32
  ret i32 %4
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL15_mm_cvttps_pi32Dv4_f(<4 x float> %__a) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <4 x float>, align 16
  store <4 x float> %__a, <4 x float>* %2, align 16
  %3 = load <4 x float>* %2, align 16
  %4 = call x86_mmx @llvm.x86.sse.cvttps2pi(<4 x float> %3)
  %5 = bitcast x86_mmx %4 to <2 x i32>
  %6 = bitcast <2 x i32> %5 to <1 x i64>
  store <1 x i64> %6, <1 x i64>* %1
  %7 = bitcast <1 x i64>* %1 to i64*
  %8 = load i64* %7, align 1
  ret i64 %8
}

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.sse.cvttps2pi(<4 x float>) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL14_mm_cvtsi32_ssDv4_fi(<4 x float> %__a, i32 %__b) #14 {
  %1 = alloca <4 x float>, align 16
  %2 = alloca i32, align 4
  store <4 x float> %__a, <4 x float>* %1, align 16
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %2, align 4
  %4 = sitofp i32 %3 to float
  %5 = load <4 x float>* %1, align 16
  %6 = insertelement <4 x float> %5, float %4, i32 0
  store <4 x float> %6, <4 x float>* %1, align 16
  %7 = load <4 x float>* %1, align 16
  ret <4 x float> %7
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL14_mm_cvtpi32_psDv4_fDv1_x(<4 x float> %__a, i64 %__b.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <4 x float>, align 16
  %3 = alloca <1 x i64>, align 8
  %4 = bitcast <1 x i64>* %1 to i64*
  store i64 %__b.coerce, i64* %4, align 1
  %__b = load <1 x i64>* %1, align 8
  store <4 x float> %__a, <4 x float>* %2, align 16
  store <1 x i64> %__b, <1 x i64>* %3, align 8
  %5 = load <4 x float>* %2, align 16
  %6 = load <1 x i64>* %3, align 8
  %7 = bitcast <1 x i64> %6 to <2 x i32>
  %8 = bitcast <2 x i32> %7 to x86_mmx
  %9 = call <4 x float> @llvm.x86.sse.cvtpi2ps(<4 x float> %5, x86_mmx %8)
  ret <4 x float> %9
}

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse.cvtpi2ps(<4 x float>, x86_mmx) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL11_mm_load_psPKf(float* %__p) #14 {
  %1 = alloca float*, align 8
  store float* %__p, float** %1, align 8
  %2 = load float** %1, align 8
  %3 = bitcast float* %2 to <4 x float>*
  %4 = load <4 x float>* %3, align 16
  ret <4 x float> %4
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL11_mm_set1_psf(float %__w) #14 {
  %1 = alloca float, align 4
  %2 = alloca <4 x float>, align 16
  store float %__w, float* %1, align 4
  %3 = load float* %1, align 4
  %4 = insertelement <4 x float> undef, float %3, i32 0
  %5 = load float* %1, align 4
  %6 = insertelement <4 x float> %4, float %5, i32 1
  %7 = load float* %1, align 4
  %8 = insertelement <4 x float> %6, float %7, i32 2
  %9 = load float* %1, align 4
  %10 = insertelement <4 x float> %8, float %9, i32 3
  store <4 x float> %10, <4 x float>* %2
  %11 = load <4 x float>* %2
  ret <4 x float> %11
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL14_mm_setzero_psv() #14 {
  %1 = alloca <4 x float>, align 16
  store <4 x float> zeroinitializer, <4 x float>* %1
  %2 = load <4 x float>* %1
  ret <4 x float> %2
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal void @_ZL13_mm_storeu_psPfDv4_f(float* %__p, <4 x float> %__a) #14 {
  %1 = alloca float*, align 8
  %2 = alloca <4 x float>, align 16
  store float* %__p, float** %1, align 8
  store <4 x float> %__a, <4 x float>* %2, align 16
  %3 = load float** %1, align 8
  %4 = bitcast float* %3 to i8*
  %5 = load <4 x float>* %2, align 16
  call void @llvm.x86.sse.storeu.ps(i8* %4, <4 x float> %5)
  ret void
}

; Function Attrs: nounwind
declare void @llvm.x86.sse.storeu.ps(i8*, <4 x float>) #8

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal void @_ZL13_mm_store1_psPfDv4_f(float* %__p, <4 x float> %__a) #14 {
  %1 = alloca float*, align 8
  %2 = alloca <4 x float>, align 16
  store float* %__p, float** %1, align 8
  store <4 x float> %__a, <4 x float>* %2, align 16
  %3 = load <4 x float>* %2, align 16
  %4 = load <4 x float>* %2, align 16
  %5 = shufflevector <4 x float> %3, <4 x float> %4, <4 x i32> zeroinitializer
  store <4 x float> %5, <4 x float>* %2, align 16
  %6 = load float** %1, align 8
  %7 = load <4 x float>* %2, align 16
  call void @_ZL13_mm_storeu_psPfDv4_f(float* %6, <4 x float> %7)
  ret void
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal void @_ZL12_mm_store_psPfDv4_f(float* %__p, <4 x float> %__a) #14 {
  %1 = alloca float*, align 8
  %2 = alloca <4 x float>, align 16
  store float* %__p, float** %1, align 8
  store <4 x float> %__a, <4 x float>* %2, align 16
  %3 = load <4 x float>* %2, align 16
  %4 = load float** %1, align 8
  %5 = bitcast float* %4 to <4 x float>*
  store <4 x float> %3, <4 x float>* %5, align 16
  ret void
}

; Function Attrs: nounwind
declare void @llvm.x86.mmx.movnt.dq(x86_mmx*, x86_mmx) #8

; Function Attrs: nounwind
declare void @llvm.x86.sse.sfence() #8

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmaxs.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmaxu.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmins.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pminu.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.mmx.pmovmskb(x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmulhu.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind
declare void @llvm.x86.mmx.maskmovq(x86_mmx, x86_mmx, i8*) #8

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pavg.b(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pavg.w(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.psad.bw(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind
declare void @llvm.x86.sse.stmxcsr(i8*) #8

; Function Attrs: nounwind
declare void @llvm.x86.sse.ldmxcsr(i8*) #8

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL13_mm_movehl_psDv4_fS_(<4 x float> %__a, <4 x float> %__b) #14 {
  %1 = alloca <4 x float>, align 16
  %2 = alloca <4 x float>, align 16
  store <4 x float> %__a, <4 x float>* %1, align 16
  store <4 x float> %__b, <4 x float>* %2, align 16
  %3 = load <4 x float>* %1, align 16
  %4 = load <4 x float>* %2, align 16
  %5 = shufflevector <4 x float> %3, <4 x float> %4, <4 x i32> <i32 6, i32 7, i32 2, i32 3>
  ret <4 x float> %5
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL13_mm_movelh_psDv4_fS_(<4 x float> %__a, <4 x float> %__b) #14 {
  %1 = alloca <4 x float>, align 16
  %2 = alloca <4 x float>, align 16
  store <4 x float> %__a, <4 x float>* %1, align 16
  store <4 x float> %__b, <4 x float>* %2, align 16
  %3 = load <4 x float>* %1, align 16
  %4 = load <4 x float>* %2, align 16
  %5 = shufflevector <4 x float> %3, <4 x float> %4, <4 x i32> <i32 0, i32 1, i32 4, i32 5>
  ret <4 x float> %5
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <4 x float> @_ZL14_mm_cvtpi16_psDv1_x(i64 %__a.coerce) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <1 x i64>, align 8
  %__b = alloca <1 x i64>, align 8
  %__c = alloca <1 x i64>, align 8
  %__r = alloca <4 x float>, align 16
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = alloca <1 x i64>, align 8
  %7 = alloca <1 x i64>, align 8
  %8 = alloca <1 x i64>, align 8
  %9 = alloca <1 x i64>, align 8
  %10 = alloca <1 x i64>, align 8
  %11 = alloca <1 x i64>, align 8
  %12 = alloca <1 x i64>, align 8
  %13 = alloca <1 x i64>, align 8
  %14 = alloca <1 x i64>, align 8
  %15 = bitcast <1 x i64>* %1 to i64*
  store i64 %__a.coerce, i64* %15, align 1
  %__a = load <1 x i64>* %1, align 8
  store <1 x i64> %__a, <1 x i64>* %2, align 8
  %16 = call i64 @_ZL16_mm_setzero_si64v()
  %17 = bitcast <1 x i64>* %3 to i64*
  store i64 %16, i64* %17, align 1
  %18 = load <1 x i64>* %3, align 8
  store <1 x i64> %18, <1 x i64>* %__b, align 8
  %19 = load <1 x i64>* %__b, align 8
  %20 = load <1 x i64>* %2, align 8
  store <1 x i64> %19, <1 x i64>* %4, align 8
  %21 = bitcast <1 x i64>* %4 to i64*
  %22 = load i64* %21, align 1
  store <1 x i64> %20, <1 x i64>* %5, align 8
  %23 = bitcast <1 x i64>* %5 to i64*
  %24 = load i64* %23, align 1
  %25 = call i64 @_ZL14_mm_cmpgt_pi16Dv1_xS_(i64 %22, i64 %24)
  %26 = bitcast <1 x i64>* %6 to i64*
  store i64 %25, i64* %26, align 1
  %27 = load <1 x i64>* %6, align 8
  store <1 x i64> %27, <1 x i64>* %__b, align 8
  %28 = load <1 x i64>* %2, align 8
  %29 = load <1 x i64>* %__b, align 8
  store <1 x i64> %28, <1 x i64>* %7, align 8
  %30 = bitcast <1 x i64>* %7 to i64*
  %31 = load i64* %30, align 1
  store <1 x i64> %29, <1 x i64>* %8, align 8
  %32 = bitcast <1 x i64>* %8 to i64*
  %33 = load i64* %32, align 1
  %34 = call i64 @_ZL17_mm_unpackhi_pi16Dv1_xS_(i64 %31, i64 %33)
  %35 = bitcast <1 x i64>* %9 to i64*
  store i64 %34, i64* %35, align 1
  %36 = load <1 x i64>* %9, align 8
  store <1 x i64> %36, <1 x i64>* %__c, align 8
  %37 = call <4 x float> @_ZL14_mm_setzero_psv()
  store <4 x float> %37, <4 x float>* %__r, align 16
  %38 = load <4 x float>* %__r, align 16
  %39 = load <1 x i64>* %__c, align 8
  store <1 x i64> %39, <1 x i64>* %10, align 8
  %40 = bitcast <1 x i64>* %10 to i64*
  %41 = load i64* %40, align 1
  %42 = call <4 x float> @_ZL14_mm_cvtpi32_psDv4_fDv1_x(<4 x float> %38, i64 %41)
  store <4 x float> %42, <4 x float>* %__r, align 16
  %43 = load <4 x float>* %__r, align 16
  %44 = load <4 x float>* %__r, align 16
  %45 = call <4 x float> @_ZL13_mm_movelh_psDv4_fS_(<4 x float> %43, <4 x float> %44)
  store <4 x float> %45, <4 x float>* %__r, align 16
  %46 = load <1 x i64>* %2, align 8
  %47 = load <1 x i64>* %__b, align 8
  store <1 x i64> %46, <1 x i64>* %11, align 8
  %48 = bitcast <1 x i64>* %11 to i64*
  %49 = load i64* %48, align 1
  store <1 x i64> %47, <1 x i64>* %12, align 8
  %50 = bitcast <1 x i64>* %12 to i64*
  %51 = load i64* %50, align 1
  %52 = call i64 @_ZL17_mm_unpacklo_pi16Dv1_xS_(i64 %49, i64 %51)
  %53 = bitcast <1 x i64>* %13 to i64*
  store i64 %52, i64* %53, align 1
  %54 = load <1 x i64>* %13, align 8
  store <1 x i64> %54, <1 x i64>* %__c, align 8
  %55 = load <4 x float>* %__r, align 16
  %56 = load <1 x i64>* %__c, align 8
  store <1 x i64> %56, <1 x i64>* %14, align 8
  %57 = bitcast <1 x i64>* %14 to i64*
  %58 = load i64* %57, align 1
  %59 = call <4 x float> @_ZL14_mm_cvtpi32_psDv4_fDv1_x(<4 x float> %55, i64 %58)
  store <4 x float> %59, <4 x float>* %__r, align 16
  %60 = load <4 x float>* %__r, align 16
  ret <4 x float> %60
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal i64 @_ZL14_mm_cvtps_pi16Dv4_f(<4 x float> %__a) #14 {
  %1 = alloca <1 x i64>, align 8
  %2 = alloca <4 x float>, align 16
  %__b = alloca <1 x i64>, align 8
  %__c = alloca <1 x i64>, align 8
  %3 = alloca <1 x i64>, align 8
  %4 = alloca <1 x i64>, align 8
  %5 = alloca <1 x i64>, align 8
  %6 = alloca <1 x i64>, align 8
  %7 = alloca <1 x i64>, align 8
  store <4 x float> %__a, <4 x float>* %2, align 16
  %8 = load <4 x float>* %2, align 16
  %9 = call i64 @_ZL14_mm_cvtps_pi32Dv4_f(<4 x float> %8)
  %10 = bitcast <1 x i64>* %3 to i64*
  store i64 %9, i64* %10, align 1
  %11 = load <1 x i64>* %3, align 8
  store <1 x i64> %11, <1 x i64>* %__b, align 8
  %12 = load <4 x float>* %2, align 16
  %13 = load <4 x float>* %2, align 16
  %14 = call <4 x float> @_ZL13_mm_movehl_psDv4_fS_(<4 x float> %12, <4 x float> %13)
  store <4 x float> %14, <4 x float>* %2, align 16
  %15 = load <4 x float>* %2, align 16
  %16 = call i64 @_ZL14_mm_cvtps_pi32Dv4_f(<4 x float> %15)
  %17 = bitcast <1 x i64>* %4 to i64*
  store i64 %16, i64* %17, align 1
  %18 = load <1 x i64>* %4, align 8
  store <1 x i64> %18, <1 x i64>* %__c, align 8
  %19 = load <1 x i64>* %__b, align 8
  %20 = load <1 x i64>* %__c, align 8
  store <1 x i64> %19, <1 x i64>* %5, align 8
  %21 = bitcast <1 x i64>* %5 to i64*
  %22 = load i64* %21, align 1
  store <1 x i64> %20, <1 x i64>* %6, align 8
  %23 = bitcast <1 x i64>* %6 to i64*
  %24 = load i64* %23, align 1
  %25 = call i64 @_ZL14_mm_packs_pi32Dv1_xS_(i64 %22, i64 %24)
  %26 = bitcast <1 x i64>* %7 to i64*
  store i64 %25, i64* %26, align 1
  %27 = load <1 x i64>* %7, align 8
  store <1 x i64> %27, <1 x i64>* %1
  %28 = bitcast <1 x i64>* %1 to i64*
  %29 = load i64* %28, align 1
  ret i64 %29
}

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse.movmsk.ps(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.sqrt.sd(<2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.sqrt.pd(<2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.min.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.min.pd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.max.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.max.pd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.cmp.pd(<2 x double>, <2 x double>, i8) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.cmp.sd(<2 x double>, <2 x double>, i8) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.comieq.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.comilt.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.comile.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.comigt.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.comige.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.comineq.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.ucomieq.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.ucomilt.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.ucomile.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.ucomigt.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.ucomige.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.ucomineq.sd(<2 x double>, <2 x double>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse2.cvtpd2ps(<2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.cvtps2pd(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse2.cvtdq2pd(<4 x i32>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.cvtpd2dq(<2 x double>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.cvtsd2si(<2 x double>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.cvttpd2dq(<2 x double>) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.sse.cvtpd2pi(<2 x double>) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.sse.cvttpd2pi(<2 x double>) #1

; Function Attrs: nounwind readnone
declare <2 x double> @llvm.x86.sse.cvtpi2pd(x86_mmx) #1

; Function Attrs: nounwind
declare void @llvm.x86.sse2.storeu.pd(i8*, <2 x double>) #8

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.padds.b(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.padds.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.paddus.b(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.paddus.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.pavg.b(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.pavg.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.pmadd.wd(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.pmaxs.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.pmaxu.b(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.pmins.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.pminu.b(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.pmulh.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.pmulhu.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare x86_mmx @llvm.x86.mmx.pmulu.dq(x86_mmx, x86_mmx) #1

; Function Attrs: nounwind readnone
declare <2 x i64> @llvm.x86.sse2.pmulu.dq(<4 x i32>, <4 x i32>) #1

; Function Attrs: nounwind readnone
declare <2 x i64> @llvm.x86.sse2.psad.bw(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.psubs.b(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.psubs.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.psubus.b(<16 x i8>, <16 x i8>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.psubus.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.pslli.w(<8 x i16>, i32) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.psll.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.pslli.d(<4 x i32>, i32) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.psll.d(<4 x i32>, <4 x i32>) #1

; Function Attrs: nounwind readnone
declare <2 x i64> @llvm.x86.sse2.pslli.q(<2 x i64>, i32) #1

; Function Attrs: nounwind readnone
declare <2 x i64> @llvm.x86.sse2.psll.q(<2 x i64>, <2 x i64>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.psrai.w(<8 x i16>, i32) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.psra.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.psrai.d(<4 x i32>, i32) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.psra.d(<4 x i32>, <4 x i32>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.psrli.w(<8 x i16>, i32) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.psrl.w(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.psrli.d(<4 x i32>, i32) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.psrl.d(<4 x i32>, <4 x i32>) #1

; Function Attrs: nounwind readnone
declare <2 x i64> @llvm.x86.sse2.psrli.q(<2 x i64>, i32) #1

; Function Attrs: nounwind readnone
declare <2 x i64> @llvm.x86.sse2.psrl.q(<2 x i64>, <2 x i64>) #1

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <2 x i64> @_ZL14_mm_cmpgt_epi8Dv2_xS_(<2 x i64> %__a, <2 x i64> %__b) #14 {
  %1 = alloca <2 x i64>, align 16
  %2 = alloca <2 x i64>, align 16
  store <2 x i64> %__a, <2 x i64>* %1, align 16
  store <2 x i64> %__b, <2 x i64>* %2, align 16
  %3 = load <2 x i64>* %1, align 16
  %4 = bitcast <2 x i64> %3 to <16 x i8>
  %5 = load <2 x i64>* %2, align 16
  %6 = bitcast <2 x i64> %5 to <16 x i8>
  %7 = icmp sgt <16 x i8> %4, %6
  %8 = sext <16 x i1> %7 to <16 x i8>
  %9 = bitcast <16 x i8> %8 to <2 x i64>
  ret <2 x i64> %9
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <2 x i64> @_ZL15_mm_cmpgt_epi16Dv2_xS_(<2 x i64> %__a, <2 x i64> %__b) #14 {
  %1 = alloca <2 x i64>, align 16
  %2 = alloca <2 x i64>, align 16
  store <2 x i64> %__a, <2 x i64>* %1, align 16
  store <2 x i64> %__b, <2 x i64>* %2, align 16
  %3 = load <2 x i64>* %1, align 16
  %4 = bitcast <2 x i64> %3 to <8 x i16>
  %5 = load <2 x i64>* %2, align 16
  %6 = bitcast <2 x i64> %5 to <8 x i16>
  %7 = icmp sgt <8 x i16> %4, %6
  %8 = sext <8 x i1> %7 to <8 x i16>
  %9 = bitcast <8 x i16> %8 to <2 x i64>
  ret <2 x i64> %9
}

; Function Attrs: alwaysinline inlinehint nounwind uwtable
define internal <2 x i64> @_ZL15_mm_cmpgt_epi32Dv2_xS_(<2 x i64> %__a, <2 x i64> %__b) #14 {
  %1 = alloca <2 x i64>, align 16
  %2 = alloca <2 x i64>, align 16
  store <2 x i64> %__a, <2 x i64>* %1, align 16
  store <2 x i64> %__b, <2 x i64>* %2, align 16
  %3 = load <2 x i64>* %1, align 16
  %4 = bitcast <2 x i64> %3 to <4 x i32>
  %5 = load <2 x i64>* %2, align 16
  %6 = bitcast <2 x i64> %5 to <4 x i32>
  %7 = icmp sgt <4 x i32> %4, %6
  %8 = sext <4 x i1> %7 to <4 x i32>
  %9 = bitcast <4 x i32> %8 to <2 x i64>
  ret <2 x i64> %9
}

; Function Attrs: nounwind readnone
declare i64 @llvm.x86.sse2.cvtsd2si64(<2 x double>) #1

; Function Attrs: nounwind readnone
declare <4 x float> @llvm.x86.sse2.cvtdq2ps(<4 x i32>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.cvtps2dq(<4 x float>) #1

; Function Attrs: nounwind readnone
declare <4 x i32> @llvm.x86.sse2.cvttps2dq(<4 x float>) #1

; Function Attrs: nounwind
declare void @llvm.x86.sse2.storeu.dq(i8*, <16 x i8>) #8

; Function Attrs: nounwind
declare void @llvm.x86.sse2.maskmov.dqu(<16 x i8>, <16 x i8>, i8*) #8

; Function Attrs: nounwind
declare void @llvm.x86.sse2.clflush(i8*) #8

; Function Attrs: nounwind
declare void @llvm.x86.sse2.lfence() #8

; Function Attrs: nounwind
declare void @llvm.x86.sse2.mfence() #8

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.packsswb.128(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare <8 x i16> @llvm.x86.sse2.packssdw.128(<4 x i32>, <4 x i32>) #1

; Function Attrs: nounwind readnone
declare <16 x i8> @llvm.x86.sse2.packuswb.128(<8 x i16>, <8 x i16>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.pmovmskb.128(<16 x i8>) #1

; Function Attrs: nounwind readnone
declare i32 @llvm.x86.sse2.movmsk.pd(<2 x double>) #1

; Function Attrs: nounwind
declare i8 @llvm.x86.addcarry.u32(i8, i32, i32, i8*) #8

; Function Attrs: nounwind
declare i8 @llvm.x86.addcarry.u64(i8, i64, i64, i8*) #8

; Function Attrs: nounwind
declare i8 @llvm.x86.subborrow.u32(i8, i32, i32, i8*) #8

; Function Attrs: nounwind
declare i8 @llvm.x86.subborrow.u64(i8, i64, i64, i8*) #8

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt6localeneERKS_(%"class.std::locale"* %this, %"class.std::locale"* dereferenceable(8) %__other) #2 align 2 {
  %1 = alloca %"class.std::locale"*, align 8
  %2 = alloca %"class.std::locale"*, align 8
  store %"class.std::locale"* %this, %"class.std::locale"** %1, align 8
  store %"class.std::locale"* %__other, %"class.std::locale"** %2, align 8
  %3 = load %"class.std::locale"** %1
  %4 = load %"class.std::locale"** %2, align 8
  %5 = call zeroext i1 @_ZNKSt6localeeqERKS_(%"class.std::locale"* %3, %"class.std::locale"* dereferenceable(8) %4) #8
  %6 = xor i1 %5, true
  ret i1 %6
}

; Function Attrs: nounwind
declare zeroext i1 @_ZNKSt6localeeqERKS_(%"class.std::locale"*, %"class.std::locale"* dereferenceable(8)) #3

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6locale5facetC2Em(%"class.std::locale::facet"* %this, i64 %__refs) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::locale::facet"*, align 8
  %2 = alloca i64, align 8
  store %"class.std::locale::facet"* %this, %"class.std::locale::facet"** %1, align 8
  store i64 %__refs, i64* %2, align 8
  %3 = load %"class.std::locale::facet"** %1
  %4 = bitcast %"class.std::locale::facet"* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ([4 x i8*]* @_ZTVNSt6locale5facetE, i64 0, i64 2) to i32 (...)**), i32 (...)*** %4
  %5 = getelementptr inbounds %"class.std::locale::facet"* %3, i32 0, i32 1
  %6 = load i64* %2, align 8
  %7 = icmp ne i64 %6, 0
  %8 = select i1 %7, i32 1, i32 0
  store i32 %8, i32* %5, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNKSt6locale5facet16_M_add_referenceEv(%"class.std::locale::facet"* %this) #2 align 2 {
  %1 = alloca %"class.std::locale::facet"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"class.std::locale::facet"* %this, %"class.std::locale::facet"** %1, align 8
  %4 = load %"class.std::locale::facet"** %1
  %5 = getelementptr inbounds %"class.std::locale::facet"* %4, i32 0, i32 1
  invoke void @_ZN9__gnu_cxxL21__atomic_add_dispatchEPii(i32* %5, i32 1)
          to label %6 unwind label %7

; <label>:6                                       ; preds = %0
  ret void

; <label>:7                                       ; preds = %0
  %8 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          filter [0 x i8*] zeroinitializer
  %9 = extractvalue { i8*, i32 } %8, 0
  store i8* %9, i8** %2
  %10 = extractvalue { i8*, i32 } %8, 1
  store i32 %10, i32* %3
  br label %11

; <label>:11                                      ; preds = %7
  %12 = load i8** %2
  call void @__cxa_call_unexpected(i8* %12) #17
  unreachable
}

declare void @__cxa_call_unexpected(i8*)

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNKSt6locale5facet19_M_remove_referenceEv(%"class.std::locale::facet"* %this) #2 align 2 {
  %1 = alloca %"class.std::locale::facet"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"class.std::locale::facet"* %this, %"class.std::locale::facet"** %1, align 8
  %4 = load %"class.std::locale::facet"** %1
  %5 = getelementptr inbounds %"class.std::locale::facet"* %4, i32 0, i32 1
  %6 = invoke i32 @_ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii(i32* %5, i32 -1)
          to label %7 unwind label %17

; <label>:7                                       ; preds = %0
  %8 = icmp eq i32 %6, 1
  br i1 %8, label %9, label %23

; <label>:9                                       ; preds = %7
  %10 = icmp eq %"class.std::locale::facet"* %4, null
  br i1 %10, label %16, label %11

; <label>:11                                      ; preds = %9
  %12 = bitcast %"class.std::locale::facet"* %4 to void (%"class.std::locale::facet"*)***
  %13 = load void (%"class.std::locale::facet"*)*** %12
  %14 = getelementptr inbounds void (%"class.std::locale::facet"*)** %13, i64 1
  %15 = load void (%"class.std::locale::facet"*)** %14
  call void %15(%"class.std::locale::facet"* %4) #8
  br label %16

; <label>:16                                      ; preds = %11, %9
  br label %23

; <label>:17                                      ; preds = %0
  %18 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          filter [0 x i8*] zeroinitializer
  %19 = extractvalue { i8*, i32 } %18, 0
  store i8* %19, i8** %2
  %20 = extractvalue { i8*, i32 } %18, 1
  store i32 %20, i32* %3
  br label %21

; <label>:21                                      ; preds = %17
  %22 = load i8** %2
  call void @__cxa_call_unexpected(i8* %22) #17
  unreachable

; <label>:23                                      ; preds = %16, %7
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6locale2idC2Ev(%"class.std::locale::id"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::locale::id"*, align 8
  store %"class.std::locale::id"* %this, %"class.std::locale::id"** %1, align 8
  %2 = load %"class.std::locale::id"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6locale5_Impl16_M_add_referenceEv(%"class.std::locale::_Impl"* %this) #2 align 2 {
  %1 = alloca %"class.std::locale::_Impl"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"class.std::locale::_Impl"* %this, %"class.std::locale::_Impl"** %1, align 8
  %4 = load %"class.std::locale::_Impl"** %1
  %5 = getelementptr inbounds %"class.std::locale::_Impl"* %4, i32 0, i32 0
  invoke void @_ZN9__gnu_cxxL21__atomic_add_dispatchEPii(i32* %5, i32 1)
          to label %6 unwind label %7

; <label>:6                                       ; preds = %0
  ret void

; <label>:7                                       ; preds = %0
  %8 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          filter [0 x i8*] zeroinitializer
  %9 = extractvalue { i8*, i32 } %8, 0
  store i8* %9, i8** %2
  %10 = extractvalue { i8*, i32 } %8, 1
  store i32 %10, i32* %3
  br label %11

; <label>:11                                      ; preds = %7
  %12 = load i8** %2
  call void @__cxa_call_unexpected(i8* %12) #17
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6locale5_Impl19_M_remove_referenceEv(%"class.std::locale::_Impl"* %this) #2 align 2 {
  %1 = alloca %"class.std::locale::_Impl"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"class.std::locale::_Impl"* %this, %"class.std::locale::_Impl"** %1, align 8
  %4 = load %"class.std::locale::_Impl"** %1
  %5 = getelementptr inbounds %"class.std::locale::_Impl"* %4, i32 0, i32 0
  %6 = invoke i32 @_ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii(i32* %5, i32 -1)
          to label %7 unwind label %14

; <label>:7                                       ; preds = %0
  %8 = icmp eq i32 %6, 1
  br i1 %8, label %9, label %20

; <label>:9                                       ; preds = %7
  %10 = icmp eq %"class.std::locale::_Impl"* %4, null
  br i1 %10, label %13, label %11

; <label>:11                                      ; preds = %9
  call void @_ZNSt6locale5_ImplD1Ev(%"class.std::locale::_Impl"* %4) #8
  %12 = bitcast %"class.std::locale::_Impl"* %4 to i8*
  call void @_ZdlPv(i8* %12) #21
  br label %13

; <label>:13                                      ; preds = %11, %9
  br label %20

; <label>:14                                      ; preds = %0
  %15 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          filter [0 x i8*] zeroinitializer
  %16 = extractvalue { i8*, i32 } %15, 0
  store i8* %16, i8** %2
  %17 = extractvalue { i8*, i32 } %15, 1
  store i32 %17, i32* %3
  br label %18

; <label>:18                                      ; preds = %14
  %19 = load i8** %2
  call void @__cxa_call_unexpected(i8* %19) #17
  unreachable

; <label>:20                                      ; preds = %13, %7
  ret void
}

; Function Attrs: nounwind
declare void @_ZNSt6locale5_ImplD1Ev(%"class.std::locale::_Impl"*) #3

; Function Attrs: nobuiltin nounwind
declare void @_ZdlPv(i8*) #15

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZNSt6locale5_Impl18_M_check_same_nameEv(%"class.std::locale::_Impl"* %this) #2 align 2 {
  %1 = alloca %"class.std::locale::_Impl"*, align 8
  %__ret = alloca i8, align 1
  %__i = alloca i64, align 8
  store %"class.std::locale::_Impl"* %this, %"class.std::locale::_Impl"** %1, align 8
  %2 = load %"class.std::locale::_Impl"** %1
  store i8 1, i8* %__ret, align 1
  %3 = getelementptr inbounds %"class.std::locale::_Impl"* %2, i32 0, i32 4
  %4 = load i8*** %3, align 8
  %5 = getelementptr inbounds i8** %4, i64 1
  %6 = load i8** %5, align 8
  %7 = icmp ne i8* %6, null
  br i1 %7, label %8, label %36

; <label>:8                                       ; preds = %0
  store i64 0, i64* %__i, align 8
  br label %9

; <label>:9                                       ; preds = %32, %8
  %10 = load i8* %__ret, align 1
  %11 = trunc i8 %10 to i1
  br i1 %11, label %12, label %15

; <label>:12                                      ; preds = %9
  %13 = load i64* %__i, align 8
  %14 = icmp ult i64 %13, 11
  br label %15

; <label>:15                                      ; preds = %12, %9
  %16 = phi i1 [ false, %9 ], [ %14, %12 ]
  br i1 %16, label %17, label %35

; <label>:17                                      ; preds = %15
  %18 = load i64* %__i, align 8
  %19 = getelementptr inbounds %"class.std::locale::_Impl"* %2, i32 0, i32 4
  %20 = load i8*** %19, align 8
  %21 = getelementptr inbounds i8** %20, i64 %18
  %22 = load i8** %21, align 8
  %23 = load i64* %__i, align 8
  %24 = add i64 %23, 1
  %25 = getelementptr inbounds %"class.std::locale::_Impl"* %2, i32 0, i32 4
  %26 = load i8*** %25, align 8
  %27 = getelementptr inbounds i8** %26, i64 %24
  %28 = load i8** %27, align 8
  %29 = call i32 @strcmp(i8* %22, i8* %28) #8
  %30 = icmp eq i32 %29, 0
  %31 = zext i1 %30 to i8
  store i8 %31, i8* %__ret, align 1
  br label %32

; <label>:32                                      ; preds = %17
  %33 = load i64* %__i, align 8
  %34 = add i64 %33, 1
  store i64 %34, i64* %__i, align 8
  br label %9

; <label>:35                                      ; preds = %15
  br label %36

; <label>:36                                      ; preds = %35, %0
  %37 = load i8* %__ret, align 1
  %38 = trunc i8 %37 to i1
  ret i1 %38
}

; Function Attrs: nounwind
declare i32 @strcmp(i8*, i8*) #3

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStanSt13_Ios_FmtflagsS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = and i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStorSt13_Ios_FmtflagsS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = or i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZSteoSt13_Ios_FmtflagsS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = xor i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStcoSt13_Ios_Fmtflags(i32 %__a) #0 {
  %1 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = xor i32 %2, -1
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZStoRRSt13_Ios_FmtflagsS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZStorSt13_Ios_FmtflagsS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZStaNRSt13_Ios_FmtflagsS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZStanSt13_Ios_FmtflagsS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZSteORSt13_Ios_FmtflagsS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZSteoSt13_Ios_FmtflagsS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStanSt13_Ios_OpenmodeS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = and i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStorSt13_Ios_OpenmodeS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = or i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZSteoSt13_Ios_OpenmodeS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = xor i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStcoSt13_Ios_Openmode(i32 %__a) #0 {
  %1 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = xor i32 %2, -1
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZStoRRSt13_Ios_OpenmodeS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZStorSt13_Ios_OpenmodeS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZStaNRSt13_Ios_OpenmodeS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZStanSt13_Ios_OpenmodeS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZSteORSt13_Ios_OpenmodeS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZSteoSt13_Ios_OpenmodeS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStanSt12_Ios_IostateS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = and i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStorSt12_Ios_IostateS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = or i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZSteoSt12_Ios_IostateS_(i32 %__a, i32 %__b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  store i32 %__b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = xor i32 %3, %4
  ret i32 %5
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @_ZStcoSt12_Ios_Iostate(i32 %__a) #0 {
  %1 = alloca i32, align 4
  store i32 %__a, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = xor i32 %2, -1
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZStoRRSt12_Ios_IostateS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZStorSt12_Ios_IostateS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZStaNRSt12_Ios_IostateS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZStanSt12_Ios_IostateS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(4) i32* @_ZSteORSt12_Ios_IostateS_(i32* dereferenceable(4) %__a, i32 %__b) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__a, i32** %1, align 8
  store i32 %__b, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZSteoSt12_Ios_IostateS_(i32 %4, i32 %5)
  %7 = load i32** %1, align 8
  store i32 %6, i32* %7, align 4
  ret i32* %7
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt9boolalphaRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 1)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %this, i32 %__fmtfl) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i32, align 4
  %__old = alloca i32, align 4
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i32 %__fmtfl, i32* %2, align 4
  %3 = load %"class.std::ios_base"** %1
  %4 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 3
  %5 = load i32* %4, align 4
  store i32 %5, i32* %__old, align 4
  %6 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 3
  %7 = load i32* %2, align 4
  %8 = call dereferenceable(4) i32* @_ZStoRRSt13_Ios_FmtflagsS_(i32* dereferenceable(4) %6, i32 %7)
  %9 = load i32* %__old, align 4
  ret i32 %9
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt11noboolalphaRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  call void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 1)
  %3 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %this, i32 %__mask) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i32, align 4
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i32 %__mask, i32* %2, align 4
  %3 = load %"class.std::ios_base"** %1
  %4 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 3
  %5 = load i32* %2, align 4
  %6 = call i32 @_ZStcoSt13_Ios_Fmtflags(i32 %5)
  %7 = call dereferenceable(4) i32* @_ZStaNRSt13_Ios_FmtflagsS_(i32* dereferenceable(4) %4, i32 %6)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt8showbaseRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 512)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt10noshowbaseRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  call void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 512)
  %3 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %3
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt9showpointRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 1024)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt11noshowpointRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  call void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 1024)
  %3 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %3
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt7showposRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 2048)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt9noshowposRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  call void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 2048)
  %3 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %3
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt6skipwsRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 4096)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt8noskipwsRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  call void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 4096)
  %3 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %3
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt9uppercaseRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 16384)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt11nouppercaseRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  call void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 16384)
  %3 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %3
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt7unitbufRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 8192)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt9nounitbufRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  call void @_ZNSt8ios_base6unsetfESt13_Ios_Fmtflags(%"class.std::ios_base"* %2, i32 8192)
  %3 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %3
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt8internalRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 16, i32 176)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %this, i32 %__fmtfl, i32 %__mask) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %__old = alloca i32, align 4
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i32 %__fmtfl, i32* %2, align 4
  store i32 %__mask, i32* %3, align 4
  %4 = load %"class.std::ios_base"** %1
  %5 = getelementptr inbounds %"class.std::ios_base"* %4, i32 0, i32 3
  %6 = load i32* %5, align 4
  store i32 %6, i32* %__old, align 4
  %7 = getelementptr inbounds %"class.std::ios_base"* %4, i32 0, i32 3
  %8 = load i32* %3, align 4
  %9 = call i32 @_ZStcoSt13_Ios_Fmtflags(i32 %8)
  %10 = call dereferenceable(4) i32* @_ZStaNRSt13_Ios_FmtflagsS_(i32* dereferenceable(4) %7, i32 %9)
  %11 = getelementptr inbounds %"class.std::ios_base"* %4, i32 0, i32 3
  %12 = load i32* %2, align 4
  %13 = load i32* %3, align 4
  %14 = call i32 @_ZStanSt13_Ios_FmtflagsS_(i32 %12, i32 %13)
  %15 = call dereferenceable(4) i32* @_ZStoRRSt13_Ios_FmtflagsS_(i32* dereferenceable(4) %11, i32 %14)
  %16 = load i32* %__old, align 4
  ret i32 %16
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt4leftRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 32, i32 176)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt5rightRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 128, i32 176)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt3decRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 2, i32 74)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt3hexRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 8, i32 74)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt3octRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 64, i32 74)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt5fixedRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 4, i32 260)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: inlinehint uwtable
define linkonce_odr dereferenceable(216) %"class.std::ios_base"* @_ZSt10scientificRSt8ios_base(%"class.std::ios_base"* dereferenceable(216) %__base) #4 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %__base, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1, align 8
  %3 = call i32 @_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_(%"class.std::ios_base"* %2, i32 256, i32 260)
  %4 = load %"class.std::ios_base"** %1, align 8
  ret %"class.std::ios_base"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt8ios_base14_Callback_listC2EPFvNS_5eventERS_iEiPS0_(%"struct.std::ios_base::_Callback_list"* %this, void (i32, %"class.std::ios_base"*, i32)* %__fn, i32 %__index, %"struct.std::ios_base::_Callback_list"* %__cb) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::ios_base::_Callback_list"*, align 8
  %2 = alloca void (i32, %"class.std::ios_base"*, i32)*, align 8
  %3 = alloca i32, align 4
  %4 = alloca %"struct.std::ios_base::_Callback_list"*, align 8
  store %"struct.std::ios_base::_Callback_list"* %this, %"struct.std::ios_base::_Callback_list"** %1, align 8
  store void (i32, %"class.std::ios_base"*, i32)* %__fn, void (i32, %"class.std::ios_base"*, i32)** %2, align 8
  store i32 %__index, i32* %3, align 4
  store %"struct.std::ios_base::_Callback_list"* %__cb, %"struct.std::ios_base::_Callback_list"** %4, align 8
  %5 = load %"struct.std::ios_base::_Callback_list"** %1
  %6 = getelementptr inbounds %"struct.std::ios_base::_Callback_list"* %5, i32 0, i32 0
  %7 = load %"struct.std::ios_base::_Callback_list"** %4, align 8
  store %"struct.std::ios_base::_Callback_list"* %7, %"struct.std::ios_base::_Callback_list"** %6, align 8
  %8 = getelementptr inbounds %"struct.std::ios_base::_Callback_list"* %5, i32 0, i32 1
  %9 = load void (i32, %"class.std::ios_base"*, i32)** %2, align 8
  store void (i32, %"class.std::ios_base"*, i32)* %9, void (i32, %"class.std::ios_base"*, i32)** %8, align 8
  %10 = getelementptr inbounds %"struct.std::ios_base::_Callback_list"* %5, i32 0, i32 2
  %11 = load i32* %3, align 4
  store i32 %11, i32* %10, align 4
  %12 = getelementptr inbounds %"struct.std::ios_base::_Callback_list"* %5, i32 0, i32 3
  store i32 0, i32* %12, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt8ios_base14_Callback_list16_M_add_referenceEv(%"struct.std::ios_base::_Callback_list"* %this) #2 align 2 {
  %1 = alloca %"struct.std::ios_base::_Callback_list"*, align 8
  store %"struct.std::ios_base::_Callback_list"* %this, %"struct.std::ios_base::_Callback_list"** %1, align 8
  %2 = load %"struct.std::ios_base::_Callback_list"** %1
  %3 = getelementptr inbounds %"struct.std::ios_base::_Callback_list"* %2, i32 0, i32 3
  call void @_ZN9__gnu_cxxL21__atomic_add_dispatchEPii(i32* %3, i32 1)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt8ios_base14_Callback_list19_M_remove_referenceEv(%"struct.std::ios_base::_Callback_list"* %this) #2 align 2 {
  %1 = alloca %"struct.std::ios_base::_Callback_list"*, align 8
  %__res = alloca i32, align 4
  store %"struct.std::ios_base::_Callback_list"* %this, %"struct.std::ios_base::_Callback_list"** %1, align 8
  %2 = load %"struct.std::ios_base::_Callback_list"** %1
  %3 = getelementptr inbounds %"struct.std::ios_base::_Callback_list"* %2, i32 0, i32 3
  %4 = call i32 @_ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii(i32* %3, i32 -1)
  store i32 %4, i32* %__res, align 4
  %5 = load i32* %__res, align 4
  %6 = icmp eq i32 %5, 0
  br i1 %6, label %7, label %8

; <label>:7                                       ; preds = %0
  br label %8

; <label>:8                                       ; preds = %7, %0
  %9 = load i32* %__res, align 4
  ret i32 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt8ios_base6_WordsC2Ev(%"struct.std::ios_base::_Words"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::ios_base::_Words"*, align 8
  store %"struct.std::ios_base::_Words"* %this, %"struct.std::ios_base::_Words"** %1, align 8
  %2 = load %"struct.std::ios_base::_Words"** %1
  %3 = getelementptr inbounds %"struct.std::ios_base::_Words"* %2, i32 0, i32 0
  store i8* null, i8** %3, align 8
  %4 = getelementptr inbounds %"struct.std::ios_base::_Words"* %2, i32 0, i32 1
  store i64 0, i64* %4, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNKSt8ios_base5flagsEv(%"class.std::ios_base"* %this) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1
  %3 = getelementptr inbounds %"class.std::ios_base"* %2, i32 0, i32 3
  %4 = load i32* %3, align 4
  ret i32 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32 @_ZNSt8ios_base5flagsESt13_Ios_Fmtflags(%"class.std::ios_base"* %this, i32 %__fmtfl) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i32, align 4
  %__old = alloca i32, align 4
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i32 %__fmtfl, i32* %2, align 4
  %3 = load %"class.std::ios_base"** %1
  %4 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 3
  %5 = load i32* %4, align 4
  store i32 %5, i32* %__old, align 4
  %6 = load i32* %2, align 4
  %7 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 3
  store i32 %6, i32* %7, align 4
  %8 = load i32* %__old, align 4
  ret i32 %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt8ios_base9precisionEv(%"class.std::ios_base"* %this) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1
  %3 = getelementptr inbounds %"class.std::ios_base"* %2, i32 0, i32 1
  %4 = load i64* %3, align 8
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt8ios_base9precisionEl(%"class.std::ios_base"* %this, i64 %__prec) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i64, align 8
  %__old = alloca i64, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i64 %__prec, i64* %2, align 8
  %3 = load %"class.std::ios_base"** %1
  %4 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 1
  %5 = load i64* %4, align 8
  store i64 %5, i64* %__old, align 8
  %6 = load i64* %2, align 8
  %7 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 1
  store i64 %6, i64* %7, align 8
  %8 = load i64* %__old, align 8
  ret i64 %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt8ios_base5widthEv(%"class.std::ios_base"* %this) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1
  %3 = getelementptr inbounds %"class.std::ios_base"* %2, i32 0, i32 2
  %4 = load i64* %3, align 8
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt8ios_base5widthEl(%"class.std::ios_base"* %this, i64 %__wide) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i64, align 8
  %__old = alloca i64, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i64 %__wide, i64* %2, align 8
  %3 = load %"class.std::ios_base"** %1
  %4 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 2
  %5 = load i64* %4, align 8
  store i64 %5, i64* %__old, align 8
  %6 = load i64* %2, align 8
  %7 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 2
  store i64 %6, i64* %7, align 8
  %8 = load i64* %__old, align 8
  ret i64 %8
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNKSt8ios_base6getlocEv(%"class.std::locale"* noalias sret %agg.result, %"class.std::ios_base"* %this) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1
  %3 = getelementptr inbounds %"class.std::ios_base"* %2, i32 0, i32 11
  call void @_ZNSt6localeC1ERKS_(%"class.std::locale"* %agg.result, %"class.std::locale"* dereferenceable(8) %3) #8
  ret void
}

; Function Attrs: nounwind
declare void @_ZNSt6localeC1ERKS_(%"class.std::locale"*, %"class.std::locale"* dereferenceable(8)) #3

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) %"class.std::locale"* @_ZNKSt8ios_base9_M_getlocEv(%"class.std::ios_base"* %this) #2 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  %2 = load %"class.std::ios_base"** %1
  %3 = getelementptr inbounds %"class.std::ios_base"* %2, i32 0, i32 11
  ret %"class.std::locale"* %3
}

; Function Attrs: uwtable
define linkonce_odr dereferenceable(8) i64* @_ZNSt8ios_base5iwordEi(%"class.std::ios_base"* %this, i32 %__ix) #7 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i32, align 4
  %__word = alloca %"struct.std::ios_base::_Words"*, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i32 %__ix, i32* %2, align 4
  %3 = load %"class.std::ios_base"** %1
  %4 = load i32* %2, align 4
  %5 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 9
  %6 = load i32* %5, align 4
  %7 = icmp slt i32 %4, %6
  br i1 %7, label %8, label %14

; <label>:8                                       ; preds = %0
  %9 = load i32* %2, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 10
  %12 = load %"struct.std::ios_base::_Words"** %11, align 8
  %13 = getelementptr inbounds %"struct.std::ios_base::_Words"* %12, i64 %10
  br label %17

; <label>:14                                      ; preds = %0
  %15 = load i32* %2, align 4
  %16 = call dereferenceable(16) %"struct.std::ios_base::_Words"* @_ZNSt8ios_base13_M_grow_wordsEib(%"class.std::ios_base"* %3, i32 %15, i1 zeroext true)
  br label %17

; <label>:17                                      ; preds = %14, %8
  %18 = phi %"struct.std::ios_base::_Words"* [ %13, %8 ], [ %16, %14 ]
  store %"struct.std::ios_base::_Words"* %18, %"struct.std::ios_base::_Words"** %__word, align 8
  %19 = load %"struct.std::ios_base::_Words"** %__word, align 8
  %20 = getelementptr inbounds %"struct.std::ios_base::_Words"* %19, i32 0, i32 1
  ret i64* %20
}

declare dereferenceable(16) %"struct.std::ios_base::_Words"* @_ZNSt8ios_base13_M_grow_wordsEib(%"class.std::ios_base"*, i32, i1 zeroext) #9

; Function Attrs: uwtable
define linkonce_odr dereferenceable(8) i8** @_ZNSt8ios_base5pwordEi(%"class.std::ios_base"* %this, i32 %__ix) #7 align 2 {
  %1 = alloca %"class.std::ios_base"*, align 8
  %2 = alloca i32, align 4
  %__word = alloca %"struct.std::ios_base::_Words"*, align 8
  store %"class.std::ios_base"* %this, %"class.std::ios_base"** %1, align 8
  store i32 %__ix, i32* %2, align 4
  %3 = load %"class.std::ios_base"** %1
  %4 = load i32* %2, align 4
  %5 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 9
  %6 = load i32* %5, align 4
  %7 = icmp slt i32 %4, %6
  br i1 %7, label %8, label %14

; <label>:8                                       ; preds = %0
  %9 = load i32* %2, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds %"class.std::ios_base"* %3, i32 0, i32 10
  %12 = load %"struct.std::ios_base::_Words"** %11, align 8
  %13 = getelementptr inbounds %"struct.std::ios_base::_Words"* %12, i64 %10
  br label %17

; <label>:14                                      ; preds = %0
  %15 = load i32* %2, align 4
  %16 = call dereferenceable(16) %"struct.std::ios_base::_Words"* @_ZNSt8ios_base13_M_grow_wordsEib(%"class.std::ios_base"* %3, i32 %15, i1 zeroext false)
  br label %17

; <label>:17                                      ; preds = %14, %8
  %18 = phi %"struct.std::ios_base::_Words"* [ %13, %8 ], [ %16, %14 ]
  store %"struct.std::ios_base::_Words"* %18, %"struct.std::ios_base::_Words"** %__word, align 8
  %19 = load %"struct.std::ios_base::_Words"** %__word, align 8
  %20 = getelementptr inbounds %"struct.std::ios_base::_Words"* %19, i32 0, i32 0
  ret i8** %20
}

; Function Attrs: uwtable
define linkonce_odr signext i8 @_ZNKSt5ctypeIcE7toupperEc(%"class.std::ctype"* %this, i8 signext %__c) #7 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8, align 1
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8 %__c, i8* %2, align 1
  %3 = load %"class.std::ctype"** %1
  %4 = bitcast %"class.std::ctype"* %3 to i8 (%"class.std::ctype"*, i8)***
  %5 = load i8 (%"class.std::ctype"*, i8)*** %4
  %6 = getelementptr inbounds i8 (%"class.std::ctype"*, i8)** %5, i64 2
  %7 = load i8 (%"class.std::ctype"*, i8)** %6
  %8 = load i8* %2, align 1
  %9 = call signext i8 %7(%"class.std::ctype"* %3, i8 signext %8)
  ret i8 %9
}

; Function Attrs: uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE7toupperEPcPKc(%"class.std::ctype"* %this, i8* %__lo, i8* %__hi) #7 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8* %__lo, i8** %2, align 8
  store i8* %__hi, i8** %3, align 8
  %4 = load %"class.std::ctype"** %1
  %5 = bitcast %"class.std::ctype"* %4 to i8* (%"class.std::ctype"*, i8*, i8*)***
  %6 = load i8* (%"class.std::ctype"*, i8*, i8*)*** %5
  %7 = getelementptr inbounds i8* (%"class.std::ctype"*, i8*, i8*)** %6, i64 3
  %8 = load i8* (%"class.std::ctype"*, i8*, i8*)** %7
  %9 = load i8** %2, align 8
  %10 = load i8** %3, align 8
  %11 = call i8* %8(%"class.std::ctype"* %4, i8* %9, i8* %10)
  ret i8* %11
}

; Function Attrs: uwtable
define linkonce_odr signext i8 @_ZNKSt5ctypeIcE7tolowerEc(%"class.std::ctype"* %this, i8 signext %__c) #7 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8, align 1
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8 %__c, i8* %2, align 1
  %3 = load %"class.std::ctype"** %1
  %4 = bitcast %"class.std::ctype"* %3 to i8 (%"class.std::ctype"*, i8)***
  %5 = load i8 (%"class.std::ctype"*, i8)*** %4
  %6 = getelementptr inbounds i8 (%"class.std::ctype"*, i8)** %5, i64 4
  %7 = load i8 (%"class.std::ctype"*, i8)** %6
  %8 = load i8* %2, align 1
  %9 = call signext i8 %7(%"class.std::ctype"* %3, i8 signext %8)
  ret i8 %9
}

; Function Attrs: uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE7tolowerEPcPKc(%"class.std::ctype"* %this, i8* %__lo, i8* %__hi) #7 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8* %__lo, i8** %2, align 8
  store i8* %__hi, i8** %3, align 8
  %4 = load %"class.std::ctype"** %1
  %5 = bitcast %"class.std::ctype"* %4 to i8* (%"class.std::ctype"*, i8*, i8*)***
  %6 = load i8* (%"class.std::ctype"*, i8*, i8*)*** %5
  %7 = getelementptr inbounds i8* (%"class.std::ctype"*, i8*, i8*)** %6, i64 5
  %8 = load i8* (%"class.std::ctype"*, i8*, i8*)** %7
  %9 = load i8** %2, align 8
  %10 = load i8** %3, align 8
  %11 = call i8* %8(%"class.std::ctype"* %4, i8* %9, i8* %10)
  ret i8* %11
}

; Function Attrs: uwtable
define linkonce_odr signext i8 @_ZNKSt5ctypeIcE5widenEc(%"class.std::ctype"* %this, i8 signext %__c) #7 align 2 {
  %1 = alloca i8, align 1
  %2 = alloca %"class.std::ctype"*, align 8
  %3 = alloca i8, align 1
  store %"class.std::ctype"* %this, %"class.std::ctype"** %2, align 8
  store i8 %__c, i8* %3, align 1
  %4 = load %"class.std::ctype"** %2
  %5 = getelementptr inbounds %"class.std::ctype"* %4, i32 0, i32 8
  %6 = load i8* %5, align 1
  %7 = icmp ne i8 %6, 0
  br i1 %7, label %8, label %14

; <label>:8                                       ; preds = %0
  %9 = load i8* %3, align 1
  %10 = zext i8 %9 to i64
  %11 = getelementptr inbounds %"class.std::ctype"* %4, i32 0, i32 9
  %12 = getelementptr inbounds [256 x i8]* %11, i32 0, i64 %10
  %13 = load i8* %12, align 1
  store i8 %13, i8* %1
  br label %21

; <label>:14                                      ; preds = %0
  call void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"* %4)
  %15 = bitcast %"class.std::ctype"* %4 to i8 (%"class.std::ctype"*, i8)***
  %16 = load i8 (%"class.std::ctype"*, i8)*** %15
  %17 = getelementptr inbounds i8 (%"class.std::ctype"*, i8)** %16, i64 6
  %18 = load i8 (%"class.std::ctype"*, i8)** %17
  %19 = load i8* %3, align 1
  %20 = call signext i8 %18(%"class.std::ctype"* %4, i8 signext %19)
  store i8 %20, i8* %1
  br label %21

; <label>:21                                      ; preds = %14, %8
  %22 = load i8* %1
  ret i8 %22
}

declare void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"*) #9

; Function Attrs: uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE5widenEPKcS2_Pc(%"class.std::ctype"* %this, i8* %__lo, i8* %__hi, i8* %__to) #7 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca %"class.std::ctype"*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  %5 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %2, align 8
  store i8* %__lo, i8** %3, align 8
  store i8* %__hi, i8** %4, align 8
  store i8* %__to, i8** %5, align 8
  %6 = load %"class.std::ctype"** %2
  %7 = getelementptr inbounds %"class.std::ctype"* %6, i32 0, i32 8
  %8 = load i8* %7, align 1
  %9 = sext i8 %8 to i32
  %10 = icmp eq i32 %9, 1
  br i1 %10, label %11, label %20

; <label>:11                                      ; preds = %0
  %12 = load i8** %5, align 8
  %13 = load i8** %3, align 8
  %14 = load i8** %4, align 8
  %15 = load i8** %3, align 8
  %16 = ptrtoint i8* %14 to i64
  %17 = ptrtoint i8* %15 to i64
  %18 = sub i64 %16, %17
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %12, i8* %13, i64 %18, i32 1, i1 false)
  %19 = load i8** %4, align 8
  store i8* %19, i8** %1
  br label %34

; <label>:20                                      ; preds = %0
  %21 = getelementptr inbounds %"class.std::ctype"* %6, i32 0, i32 8
  %22 = load i8* %21, align 1
  %23 = icmp ne i8 %22, 0
  br i1 %23, label %25, label %24

; <label>:24                                      ; preds = %20
  call void @_ZNKSt5ctypeIcE13_M_widen_initEv(%"class.std::ctype"* %6)
  br label %25

; <label>:25                                      ; preds = %24, %20
  %26 = bitcast %"class.std::ctype"* %6 to i8* (%"class.std::ctype"*, i8*, i8*, i8*)***
  %27 = load i8* (%"class.std::ctype"*, i8*, i8*, i8*)*** %26
  %28 = getelementptr inbounds i8* (%"class.std::ctype"*, i8*, i8*, i8*)** %27, i64 7
  %29 = load i8* (%"class.std::ctype"*, i8*, i8*, i8*)** %28
  %30 = load i8** %3, align 8
  %31 = load i8** %4, align 8
  %32 = load i8** %5, align 8
  %33 = call i8* %29(%"class.std::ctype"* %6, i8* %30, i8* %31, i8* %32)
  store i8* %33, i8** %1
  br label %34

; <label>:34                                      ; preds = %25, %11
  %35 = load i8** %1
  ret i8* %35
}

; Function Attrs: uwtable
define linkonce_odr signext i8 @_ZNKSt5ctypeIcE6narrowEcc(%"class.std::ctype"* %this, i8 signext %__c, i8 signext %__dfault) #7 align 2 {
  %1 = alloca i8, align 1
  %2 = alloca %"class.std::ctype"*, align 8
  %3 = alloca i8, align 1
  %4 = alloca i8, align 1
  %__t = alloca i8, align 1
  store %"class.std::ctype"* %this, %"class.std::ctype"** %2, align 8
  store i8 %__c, i8* %3, align 1
  store i8 %__dfault, i8* %4, align 1
  %5 = load %"class.std::ctype"** %2
  %6 = load i8* %3, align 1
  %7 = zext i8 %6 to i64
  %8 = getelementptr inbounds %"class.std::ctype"* %5, i32 0, i32 10
  %9 = getelementptr inbounds [256 x i8]* %8, i32 0, i64 %7
  %10 = load i8* %9, align 1
  %11 = icmp ne i8 %10, 0
  br i1 %11, label %12, label %18

; <label>:12                                      ; preds = %0
  %13 = load i8* %3, align 1
  %14 = zext i8 %13 to i64
  %15 = getelementptr inbounds %"class.std::ctype"* %5, i32 0, i32 10
  %16 = getelementptr inbounds [256 x i8]* %15, i32 0, i64 %14
  %17 = load i8* %16, align 1
  store i8 %17, i8* %1
  br label %39

; <label>:18                                      ; preds = %0
  %19 = bitcast %"class.std::ctype"* %5 to i8 (%"class.std::ctype"*, i8, i8)***
  %20 = load i8 (%"class.std::ctype"*, i8, i8)*** %19
  %21 = getelementptr inbounds i8 (%"class.std::ctype"*, i8, i8)** %20, i64 8
  %22 = load i8 (%"class.std::ctype"*, i8, i8)** %21
  %23 = load i8* %3, align 1
  %24 = load i8* %4, align 1
  %25 = call signext i8 %22(%"class.std::ctype"* %5, i8 signext %23, i8 signext %24)
  store i8 %25, i8* %__t, align 1
  %26 = load i8* %__t, align 1
  %27 = sext i8 %26 to i32
  %28 = load i8* %4, align 1
  %29 = sext i8 %28 to i32
  %30 = icmp ne i32 %27, %29
  br i1 %30, label %31, label %37

; <label>:31                                      ; preds = %18
  %32 = load i8* %__t, align 1
  %33 = load i8* %3, align 1
  %34 = zext i8 %33 to i64
  %35 = getelementptr inbounds %"class.std::ctype"* %5, i32 0, i32 10
  %36 = getelementptr inbounds [256 x i8]* %35, i32 0, i64 %34
  store i8 %32, i8* %36, align 1
  br label %37

; <label>:37                                      ; preds = %31, %18
  %38 = load i8* %__t, align 1
  store i8 %38, i8* %1
  br label %39

; <label>:39                                      ; preds = %37, %12
  %40 = load i8* %1
  ret i8 %40
}

; Function Attrs: uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE6narrowEPKcS2_cPc(%"class.std::ctype"* %this, i8* %__lo, i8* %__hi, i8 signext %__dfault, i8* %__to) #7 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca %"class.std::ctype"*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  %5 = alloca i8, align 1
  %6 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %2, align 8
  store i8* %__lo, i8** %3, align 8
  store i8* %__hi, i8** %4, align 8
  store i8 %__dfault, i8* %5, align 1
  store i8* %__to, i8** %6, align 8
  %7 = load %"class.std::ctype"** %2
  %8 = getelementptr inbounds %"class.std::ctype"* %7, i32 0, i32 11
  %9 = load i8* %8, align 1
  %10 = sext i8 %9 to i32
  %11 = icmp eq i32 %10, 1
  %12 = zext i1 %11 to i64
  %13 = call i64 @llvm.expect.i64(i64 %12, i64 1)
  %14 = icmp ne i64 %13, 0
  br i1 %14, label %15, label %24

; <label>:15                                      ; preds = %0
  %16 = load i8** %6, align 8
  %17 = load i8** %3, align 8
  %18 = load i8** %4, align 8
  %19 = load i8** %3, align 8
  %20 = ptrtoint i8* %18 to i64
  %21 = ptrtoint i8* %19 to i64
  %22 = sub i64 %20, %21
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %16, i8* %17, i64 %22, i32 1, i1 false)
  %23 = load i8** %4, align 8
  store i8* %23, i8** %1
  br label %39

; <label>:24                                      ; preds = %0
  %25 = getelementptr inbounds %"class.std::ctype"* %7, i32 0, i32 11
  %26 = load i8* %25, align 1
  %27 = icmp ne i8 %26, 0
  br i1 %27, label %29, label %28

; <label>:28                                      ; preds = %24
  call void @_ZNKSt5ctypeIcE14_M_narrow_initEv(%"class.std::ctype"* %7)
  br label %29

; <label>:29                                      ; preds = %28, %24
  %30 = bitcast %"class.std::ctype"* %7 to i8* (%"class.std::ctype"*, i8*, i8*, i8, i8*)***
  %31 = load i8* (%"class.std::ctype"*, i8*, i8*, i8, i8*)*** %30
  %32 = getelementptr inbounds i8* (%"class.std::ctype"*, i8*, i8*, i8, i8*)** %31, i64 9
  %33 = load i8* (%"class.std::ctype"*, i8*, i8*, i8, i8*)** %32
  %34 = load i8** %3, align 8
  %35 = load i8** %4, align 8
  %36 = load i8* %5, align 1
  %37 = load i8** %6, align 8
  %38 = call i8* %33(%"class.std::ctype"* %7, i8* %34, i8* %35, i8 signext %36, i8* %37)
  store i8* %38, i8** %1
  br label %39

; <label>:39                                      ; preds = %29, %15
  %40 = load i8** %1
  ret i8* %40
}

; Function Attrs: nounwind readnone
declare i64 @llvm.expect.i64(i64, i64) #1

declare void @_ZNKSt5ctypeIcE14_M_narrow_initEv(%"class.std::ctype"*) #9

; Function Attrs: nounwind uwtable
define linkonce_odr i16* @_ZNKSt5ctypeIcE5tableEv(%"class.std::ctype"* %this) #2 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  %2 = load %"class.std::ctype"** %1
  %3 = getelementptr inbounds %"class.std::ctype"* %2, i32 0, i32 7
  %4 = load i16** %3, align 8
  ret i16* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNKSt5ctypeIcE8do_widenEc(%"class.std::ctype"* %this, i8 signext %__c) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8, align 1
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8 %__c, i8* %2, align 1
  %3 = load %"class.std::ctype"** %1
  %4 = load i8* %2, align 1
  ret i8 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE8do_widenEPKcS2_Pc(%"class.std::ctype"* %this, i8* %__lo, i8* %__hi, i8* %__to) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8* %__lo, i8** %2, align 8
  store i8* %__hi, i8** %3, align 8
  store i8* %__to, i8** %4, align 8
  %5 = load %"class.std::ctype"** %1
  %6 = load i8** %4, align 8
  %7 = load i8** %2, align 8
  %8 = load i8** %3, align 8
  %9 = load i8** %2, align 8
  %10 = ptrtoint i8* %8 to i64
  %11 = ptrtoint i8* %9 to i64
  %12 = sub i64 %10, %11
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 %12, i32 1, i1 false)
  %13 = load i8** %3, align 8
  ret i8* %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr signext i8 @_ZNKSt5ctypeIcE9do_narrowEcc(%"class.std::ctype"* %this, i8 signext %__c, i8 signext %__dfault) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8, align 1
  %3 = alloca i8, align 1
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8 %__c, i8* %2, align 1
  store i8 %__dfault, i8* %3, align 1
  %4 = load %"class.std::ctype"** %1
  %5 = load i8* %2, align 1
  ret i8 %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE9do_narrowEPKcS2_cPc(%"class.std::ctype"* %this, i8* %__lo, i8* %__hi, i8 signext %__dfault, i8* %__to) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i8, align 1
  %5 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8* %__lo, i8** %2, align 8
  store i8* %__hi, i8** %3, align 8
  store i8 %__dfault, i8* %4, align 1
  store i8* %__to, i8** %5, align 8
  %6 = load %"class.std::ctype"** %1
  %7 = load i8** %5, align 8
  %8 = load i8** %2, align 8
  %9 = load i8** %3, align 8
  %10 = load i8** %2, align 8
  %11 = ptrtoint i8* %9 to i64
  %12 = ptrtoint i8* %10 to i64
  %13 = sub i64 %11, %12
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %7, i8* %8, i64 %13, i32 1, i1 false)
  %14 = load i8** %3, align 8
  ret i8* %14
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i1 @_ZNKSt5ctypeIcE2isEtc(%"class.std::ctype"* %this, i16 zeroext %__m, i8 signext %__c) #0 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i16, align 2
  %3 = alloca i8, align 1
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i16 %__m, i16* %2, align 2
  store i8 %__c, i8* %3, align 1
  %4 = load %"class.std::ctype"** %1
  %5 = load i8* %3, align 1
  %6 = zext i8 %5 to i64
  %7 = getelementptr inbounds %"class.std::ctype"* %4, i32 0, i32 7
  %8 = load i16** %7, align 8
  %9 = getelementptr inbounds i16* %8, i64 %6
  %10 = load i16* %9, align 2
  %11 = zext i16 %10 to i32
  %12 = load i16* %2, align 2
  %13 = zext i16 %12 to i32
  %14 = and i32 %11, %13
  %15 = icmp ne i32 %14, 0
  ret i1 %15
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE2isEPKcS2_Pt(%"class.std::ctype"* %this, i8* %__low, i8* %__high, i16* %__vec) #0 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i16*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i8* %__low, i8** %2, align 8
  store i8* %__high, i8** %3, align 8
  store i16* %__vec, i16** %4, align 8
  %5 = load %"class.std::ctype"** %1
  br label %6

; <label>:6                                       ; preds = %10, %0
  %7 = load i8** %2, align 8
  %8 = load i8** %3, align 8
  %9 = icmp ult i8* %7, %8
  br i1 %9, label %10, label %21

; <label>:10                                      ; preds = %6
  %11 = load i8** %2, align 8
  %12 = getelementptr inbounds i8* %11, i32 1
  store i8* %12, i8** %2, align 8
  %13 = load i8* %11, align 1
  %14 = zext i8 %13 to i64
  %15 = getelementptr inbounds %"class.std::ctype"* %5, i32 0, i32 7
  %16 = load i16** %15, align 8
  %17 = getelementptr inbounds i16* %16, i64 %14
  %18 = load i16* %17, align 2
  %19 = load i16** %4, align 8
  %20 = getelementptr inbounds i16* %19, i32 1
  store i16* %20, i16** %4, align 8
  store i16 %18, i16* %19, align 2
  br label %6

; <label>:21                                      ; preds = %6
  %22 = load i8** %3, align 8
  ret i8* %22
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE7scan_isEtPKcS2_(%"class.std::ctype"* %this, i16 zeroext %__m, i8* %__low, i8* %__high) #0 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i16, align 2
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i16 %__m, i16* %2, align 2
  store i8* %__low, i8** %3, align 8
  store i8* %__high, i8** %4, align 8
  %5 = load %"class.std::ctype"** %1
  br label %6

; <label>:6                                       ; preds = %26, %0
  %7 = load i8** %3, align 8
  %8 = load i8** %4, align 8
  %9 = icmp ult i8* %7, %8
  br i1 %9, label %10, label %24

; <label>:10                                      ; preds = %6
  %11 = load i8** %3, align 8
  %12 = load i8* %11, align 1
  %13 = zext i8 %12 to i64
  %14 = getelementptr inbounds %"class.std::ctype"* %5, i32 0, i32 7
  %15 = load i16** %14, align 8
  %16 = getelementptr inbounds i16* %15, i64 %13
  %17 = load i16* %16, align 2
  %18 = zext i16 %17 to i32
  %19 = load i16* %2, align 2
  %20 = zext i16 %19 to i32
  %21 = and i32 %18, %20
  %22 = icmp ne i32 %21, 0
  %23 = xor i1 %22, true
  br label %24

; <label>:24                                      ; preds = %10, %6
  %25 = phi i1 [ false, %6 ], [ %23, %10 ]
  br i1 %25, label %26, label %29

; <label>:26                                      ; preds = %24
  %27 = load i8** %3, align 8
  %28 = getelementptr inbounds i8* %27, i32 1
  store i8* %28, i8** %3, align 8
  br label %6

; <label>:29                                      ; preds = %24
  %30 = load i8** %3, align 8
  ret i8* %30
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZNKSt5ctypeIcE8scan_notEtPKcS2_(%"class.std::ctype"* %this, i16 zeroext %__m, i8* %__low, i8* %__high) #0 align 2 {
  %1 = alloca %"class.std::ctype"*, align 8
  %2 = alloca i16, align 2
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  store %"class.std::ctype"* %this, %"class.std::ctype"** %1, align 8
  store i16 %__m, i16* %2, align 2
  store i8* %__low, i8** %3, align 8
  store i8* %__high, i8** %4, align 8
  %5 = load %"class.std::ctype"** %1
  br label %6

; <label>:6                                       ; preds = %25, %0
  %7 = load i8** %3, align 8
  %8 = load i8** %4, align 8
  %9 = icmp ult i8* %7, %8
  br i1 %9, label %10, label %23

; <label>:10                                      ; preds = %6
  %11 = load i8** %3, align 8
  %12 = load i8* %11, align 1
  %13 = zext i8 %12 to i64
  %14 = getelementptr inbounds %"class.std::ctype"* %5, i32 0, i32 7
  %15 = load i16** %14, align 8
  %16 = getelementptr inbounds i16* %15, i64 %13
  %17 = load i16* %16, align 2
  %18 = zext i16 %17 to i32
  %19 = load i16* %2, align 2
  %20 = zext i16 %19 to i32
  %21 = and i32 %18, %20
  %22 = icmp ne i32 %21, 0
  br label %23

; <label>:23                                      ; preds = %10, %6
  %24 = phi i1 [ false, %6 ], [ %22, %10 ]
  br i1 %24, label %25, label %28

; <label>:25                                      ; preds = %23
  %26 = load i8** %3, align 8
  %27 = getelementptr inbounds i8* %26, i32 1
  store i8* %27, i8** %3, align 8
  br label %6

; <label>:28                                      ; preds = %23
  %29 = load i8** %3, align 8
  ret i8* %29
}

define internal void @__cxx_global_var_init() section ".text.startup" {
  call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  %1 = call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init"* @_ZStL8__ioinit, i32 0, i32 0), i8* @__dso_handle) #8
  ret void
}

declare void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*) #9

; Function Attrs: nounwind
declare void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*) #3

; Function Attrs: nounwind
declare i32 @__cxa_atexit(void (i8*)*, i8*, i8*) #8

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp23network_to_native_orderEPhi(i8* %buf, i32 %len) #4 {
  %1 = alloca i8*, align 8
  %2 = alloca i32, align 4
  store i8* %buf, i8** %1, align 8
  store i32 %len, i32* %2, align 4
  %3 = load i8** %1, align 8
  %4 = load i8** %1, align 8
  %5 = load i32* %2, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds i8* %4, i64 %6
  call void @_ZSt7reverseIPhEvT_S1_(i8* %3, i8* %7)
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt7reverseIPhEvT_S1_(i8* %__first, i8* %__last) #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca %"struct.std::random_access_iterator_tag", align 1
  %4 = alloca %"struct.std::random_access_iterator_tag", align 1
  store i8* %__first, i8** %1, align 8
  store i8* %__last, i8** %2, align 8
  %5 = load i8** %1, align 8
  %6 = load i8** %2, align 8
  call void @_ZSt19__iterator_categoryIPhENSt15iterator_traitsIT_E17iterator_categoryERKS2_(i8** dereferenceable(8) %1)
  call void @_ZSt9__reverseIPhEvT_S1_St26random_access_iterator_tag(i8* %5, i8* %6)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZN2fp23native_to_network_orderEPhi(i8* %buf, i32 %len) #4 {
  %1 = alloca i8*, align 8
  %2 = alloca i32, align 4
  store i8* %buf, i8** %1, align 8
  store i32 %len, i32* %2, align 4
  %3 = load i8** %1, align 8
  %4 = load i8** %1, align 8
  %5 = load i32* %2, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds i8* %4, i64 %6
  call void @_ZSt7reverseIPhEvT_S1_(i8* %3, i8* %7)
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @fp_get_packet_in_port(%"struct.fp::Context"* %c) #0 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %c, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1, align 8
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 3
  %4 = load i32* %3, align 4
  ret i32 %4
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i32 @fp_get_packet_in_phys_port(%"struct.fp::Context"* %c) #0 {
  %1 = alloca %"struct.fp::Context"*, align 8
  store %"struct.fp::Context"* %c, %"struct.fp::Context"** %1, align 8
  %2 = load %"struct.fp::Context"** %1, align 8
  %3 = getelementptr inbounds %"struct.fp::Context"* %2, i32 0, i32 4
  %4 = load i32* %3, align 4
  ret i32 %4
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @fp_advance_header(%"struct.fp::Context"* %cxt, i16 zeroext %n) #0 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i16, align 2
  store %"struct.fp::Context"* %cxt, %"struct.fp::Context"** %1, align 8
  store i16 %n, i16* %2, align 2
  %3 = load %"struct.fp::Context"** %1, align 8
  %4 = load i16* %2, align 2
  call void @_ZN2fp7Context7advanceEt(%"struct.fp::Context"* %3, i16 zeroext %4)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @fp_bind_header(%"struct.fp::Context"* %cxt, i32 %id) #4 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  store %"struct.fp::Context"* %cxt, %"struct.fp::Context"** %1, align 8
  store i32 %id, i32* %2, align 4
  %3 = load %"struct.fp::Context"** %1, align 8
  %4 = load i32* %2, align 4
  call void @_ZN2fp7Context11bind_headerEi(%"struct.fp::Context"* %3, i32 %4)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @fp_bind_field(%"struct.fp::Context"* %cxt, i32 %id, i16 zeroext %off, i16 zeroext %len) #4 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i16, align 2
  %4 = alloca i16, align 2
  %abs_off = alloca i32, align 4
  store %"struct.fp::Context"* %cxt, %"struct.fp::Context"** %1, align 8
  store i32 %id, i32* %2, align 4
  store i16 %off, i16* %3, align 2
  store i16 %len, i16* %4, align 2
  %5 = load %"struct.fp::Context"** %1, align 8
  %6 = call zeroext i16 @_ZNK2fp7Context6offsetEv(%"struct.fp::Context"* %5)
  %7 = zext i16 %6 to i32
  %8 = load i16* %3, align 2
  %9 = zext i16 %8 to i32
  %10 = add nsw i32 %7, %9
  store i32 %10, i32* %abs_off, align 4
  %11 = load %"struct.fp::Context"** %1, align 8
  %12 = load i32* %2, align 4
  %13 = load i32* %abs_off, align 4
  %14 = trunc i32 %13 to i16
  %15 = load i16* %4, align 2
  call void @_ZN2fp7Context10bind_fieldEitt(%"struct.fp::Context"* %11, i32 %12, i16 zeroext %14, i16 zeroext %15)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @fp_alias_bind(%"struct.fp::Context"* %cxt, i32 %original, i32 %alias, i16 zeroext %off, i16 zeroext %len) #4 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i16, align 2
  %5 = alloca i16, align 2
  %abs_off = alloca i32, align 4
  store %"struct.fp::Context"* %cxt, %"struct.fp::Context"** %1, align 8
  store i32 %original, i32* %2, align 4
  store i32 %alias, i32* %3, align 4
  store i16 %off, i16* %4, align 2
  store i16 %len, i16* %5, align 2
  %6 = load %"struct.fp::Context"** %1, align 8
  %7 = call zeroext i16 @_ZNK2fp7Context6offsetEv(%"struct.fp::Context"* %6)
  %8 = zext i16 %7 to i32
  %9 = load i16* %4, align 2
  %10 = zext i16 %9 to i32
  %11 = add nsw i32 %8, %10
  store i32 %11, i32* %abs_off, align 4
  %12 = load %"struct.fp::Context"** %1, align 8
  %13 = load i32* %2, align 4
  %14 = load i32* %abs_off, align 4
  %15 = trunc i32 %14 to i16
  %16 = load i16* %5, align 2
  call void @_ZN2fp7Context10bind_fieldEitt(%"struct.fp::Context"* %12, i32 %13, i16 zeroext %15, i16 zeroext %16)
  %17 = load %"struct.fp::Context"** %1, align 8
  %18 = load i32* %3, align 4
  %19 = load i32* %abs_off, align 4
  %20 = trunc i32 %19 to i16
  %21 = load i16* %5, align 2
  call void @_ZN2fp7Context10bind_fieldEitt(%"struct.fp::Context"* %17, i32 %18, i16 zeroext %20, i16 zeroext %21)
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr i8* @fp_read_field(%"struct.fp::Context"* %cxt, i32 %fld, i8* %ret) #4 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i8*, align 8
  %b = alloca %"struct.fp::Binding", align 2
  %p = alloca i8*, align 8
  store %"struct.fp::Context"* %cxt, %"struct.fp::Context"** %1, align 8
  store i32 %fld, i32* %2, align 4
  store i8* %ret, i8** %3, align 8
  %4 = load %"struct.fp::Context"** %1, align 8
  %5 = load i32* %2, align 4
  %6 = call dereferenceable(4) %"struct.fp::Binding"* @_ZN2fp7Context17get_field_bindingEi(%"struct.fp::Context"* %4, i32 %5)
  %7 = bitcast %"struct.fp::Binding"* %b to i8*
  %8 = bitcast %"struct.fp::Binding"* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %7, i8* %8, i64 4, i32 2, i1 false)
  %9 = load %"struct.fp::Context"** %1, align 8
  %10 = getelementptr inbounds %"struct.fp::Binding"* %b, i32 0, i32 0
  %11 = load i16* %10, align 2
  %12 = call i8* @_ZN2fp7Context9get_fieldEt(%"struct.fp::Context"* %9, i16 zeroext %11)
  store i8* %12, i8** %p, align 8
  %13 = load i8** %p, align 8
  %14 = load i8** %p, align 8
  %15 = getelementptr inbounds %"struct.fp::Binding"* %b, i32 0, i32 1
  %16 = load i16* %15, align 2
  %17 = zext i16 %16 to i32
  %18 = sext i32 %17 to i64
  %19 = getelementptr inbounds i8* %14, i64 %18
  %20 = load i8** %3, align 8
  %21 = call i8* @_ZSt4copyIPhS0_ET0_T_S2_S1_(i8* %13, i8* %19, i8* %20)
  %22 = load i8** %3, align 8
  %23 = getelementptr inbounds %"struct.fp::Binding"* %b, i32 0, i32 1
  %24 = load i16* %23, align 2
  %25 = zext i16 %24 to i32
  call void @_ZN2fp23network_to_native_orderEPhi(i8* %22, i32 %25)
  %26 = load i8** %3, align 8
  ret i8* %26
}

; Function Attrs: uwtable
define linkonce_odr i8* @_ZSt4copyIPhS0_ET0_T_S2_S1_(i8* %__first, i8* %__last, i8* %__result) #7 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  store i8* %__first, i8** %1, align 8
  store i8* %__last, i8** %2, align 8
  store i8* %__result, i8** %3, align 8
  %4 = load i8** %1, align 8
  %5 = call i8* @_ZSt12__miter_baseIPhENSt11_Miter_baseIT_E13iterator_typeES2_(i8* %4)
  %6 = load i8** %2, align 8
  %7 = call i8* @_ZSt12__miter_baseIPhENSt11_Miter_baseIT_E13iterator_typeES2_(i8* %6)
  %8 = load i8** %3, align 8
  %9 = call i8* @_ZSt14__copy_move_a2ILb0EPhS0_ET1_T0_S2_S1_(i8* %5, i8* %7, i8* %8)
  ret i8* %9
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @fp_set_field(%"struct.fp::Context"* %cxt, i32 %fld, i32 %len, i8* %val) #4 {
  %1 = alloca %"struct.fp::Context"*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i8*, align 8
  %b = alloca %"struct.fp::Binding"*, align 8
  %p = alloca i8*, align 8
  store %"struct.fp::Context"* %cxt, %"struct.fp::Context"** %1, align 8
  store i32 %fld, i32* %2, align 4
  store i32 %len, i32* %3, align 4
  store i8* %val, i8** %4, align 8
  %5 = load %"struct.fp::Context"** %1, align 8
  %6 = load i32* %2, align 4
  %7 = call dereferenceable(4) %"struct.fp::Binding"* @_ZN2fp7Context17get_field_bindingEi(%"struct.fp::Context"* %5, i32 %6)
  store %"struct.fp::Binding"* %7, %"struct.fp::Binding"** %b, align 8
  %8 = load %"struct.fp::Context"** %1, align 8
  %9 = load %"struct.fp::Binding"** %b, align 8
  %10 = getelementptr inbounds %"struct.fp::Binding"* %9, i32 0, i32 0
  %11 = load i16* %10, align 2
  %12 = call i8* @_ZN2fp7Context9get_fieldEt(%"struct.fp::Context"* %8, i16 zeroext %11)
  store i8* %12, i8** %p, align 8
  %13 = load i8** %4, align 8
  %14 = load i8** %4, align 8
  %15 = load i32* %3, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds i8* %14, i64 %16
  %18 = load i8** %p, align 8
  %19 = call i8* @_ZSt4copyIPhS0_ET0_T_S2_S1_(i8* %13, i8* %17, i8* %18)
  %20 = load i8** %p, align 8
  %21 = load i32* %3, align 4
  call void @_ZN2fp23native_to_network_orderEPhi(i8* %20, i32 %21)
  %22 = load i32* %3, align 4
  %23 = trunc i32 %22 to i16
  %24 = load %"struct.fp::Binding"** %b, align 8
  %25 = getelementptr inbounds %"struct.fp::Binding"* %24, i32 0, i32 1
  store i16 %23, i16* %25, align 2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_(i8* %__first, i8* %__last, i8* %__result) #2 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %_Num = alloca i64, align 8
  store i8* %__first, i8** %1, align 8
  store i8* %__last, i8** %2, align 8
  store i8* %__result, i8** %3, align 8
  %4 = load i8** %2, align 8
  %5 = load i8** %1, align 8
  %6 = ptrtoint i8* %4 to i64
  %7 = ptrtoint i8* %5 to i64
  %8 = sub i64 %6, %7
  store i64 %8, i64* %_Num, align 8
  %9 = load i64* %_Num, align 8
  %10 = icmp ne i64 %9, 0
  br i1 %10, label %11, label %16

; <label>:11                                      ; preds = %0
  %12 = load i8** %3, align 8
  %13 = load i8** %1, align 8
  %14 = load i64* %_Num, align 8
  %15 = mul i64 1, %14
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %12, i8* %13, i64 %15, i32 1, i1 false)
  br label %16

; <label>:16                                      ; preds = %11, %0
  %17 = load i8** %3, align 8
  %18 = load i64* %_Num, align 8
  %19 = getelementptr inbounds i8* %17, i64 %18
  ret i8* %19
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZSt13__copy_move_aILb0EPhS0_ET1_T0_S2_S1_(i8* %__first, i8* %__last, i8* %__result) #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %__simple = alloca i8, align 1
  store i8* %__first, i8** %1, align 8
  store i8* %__last, i8** %2, align 8
  store i8* %__result, i8** %3, align 8
  store i8 1, i8* %__simple, align 1
  %4 = load i8** %1, align 8
  %5 = load i8** %2, align 8
  %6 = load i8** %3, align 8
  %7 = call i8* @_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIhEEPT_PKS3_S6_S4_(i8* %4, i8* %5, i8* %6)
  ret i8* %7
}

; Function Attrs: inlinehint uwtable
define linkonce_odr i8* @_ZSt12__niter_baseIPhENSt11_Niter_baseIT_E13iterator_typeES2_(i8* %__it) #4 {
  %1 = alloca i8*, align 8
  store i8* %__it, i8** %1, align 8
  %2 = load i8** %1, align 8
  %3 = call i8* @_ZNSt10_Iter_baseIPhLb0EE7_S_baseES0_(i8* %2)
  ret i8* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNSt10_Iter_baseIPhLb0EE7_S_baseES0_(i8* %__it) #2 align 2 {
  %1 = alloca i8*, align 8
  store i8* %__it, i8** %1, align 8
  %2 = load i8** %1, align 8
  ret i8* %2
}

; Function Attrs: inlinehint uwtable
define linkonce_odr i8* @_ZSt14__copy_move_a2ILb0EPhS0_ET1_T0_S2_S1_(i8* %__first, i8* %__last, i8* %__result) #4 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  store i8* %__first, i8** %1, align 8
  store i8* %__last, i8** %2, align 8
  store i8* %__result, i8** %3, align 8
  %4 = load i8** %1, align 8
  %5 = call i8* @_ZSt12__niter_baseIPhENSt11_Niter_baseIT_E13iterator_typeES2_(i8* %4)
  %6 = load i8** %2, align 8
  %7 = call i8* @_ZSt12__niter_baseIPhENSt11_Niter_baseIT_E13iterator_typeES2_(i8* %6)
  %8 = load i8** %3, align 8
  %9 = call i8* @_ZSt12__niter_baseIPhENSt11_Niter_baseIT_E13iterator_typeES2_(i8* %8)
  %10 = call i8* @_ZSt13__copy_move_aILb0EPhS0_ET1_T0_S2_S1_(i8* %5, i8* %7, i8* %9)
  ret i8* %10
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i8* @_ZSt12__miter_baseIPhENSt11_Miter_baseIT_E13iterator_typeES2_(i8* %__it) #0 {
  %1 = alloca i8*, align 8
  store i8* %__it, i8** %1, align 8
  %2 = load i8** %1, align 8
  %3 = call i8* @_ZNSt10_Iter_baseIPhLb0EE7_S_baseES0_(i8* %2)
  ret i8* %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt4swapIhEvRT_S1_(i8* dereferenceable(1) %__a, i8* dereferenceable(1) %__b) #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %__tmp = alloca i8, align 1
  store i8* %__a, i8** %1, align 8
  store i8* %__b, i8** %2, align 8
  %3 = load i8** %1, align 8
  %4 = call dereferenceable(1) i8* @_ZSt4moveIRhEONSt16remove_referenceIT_E4typeEOS2_(i8* dereferenceable(1) %3) #8
  %5 = load i8* %4
  store i8 %5, i8* %__tmp, align 1
  %6 = load i8** %2, align 8
  %7 = call dereferenceable(1) i8* @_ZSt4moveIRhEONSt16remove_referenceIT_E4typeEOS2_(i8* dereferenceable(1) %6) #8
  %8 = load i8* %7
  %9 = load i8** %1, align 8
  store i8 %8, i8* %9, align 1
  %10 = call dereferenceable(1) i8* @_ZSt4moveIRhEONSt16remove_referenceIT_E4typeEOS2_(i8* dereferenceable(1) %__tmp) #8
  %11 = load i8* %10
  %12 = load i8** %2, align 8
  store i8 %11, i8* %12, align 1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(1) i8* @_ZSt4moveIRhEONSt16remove_referenceIT_E4typeEOS2_(i8* dereferenceable(1) %__t) #2 {
  %1 = alloca i8*, align 8
  store i8* %__t, i8** %1, align 8
  %2 = load i8** %1, align 8
  ret i8* %2
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZSt9iter_swapIPhS0_EvT_T0_(i8* %__a, i8* %__b) #2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  store i8* %__a, i8** %1, align 8
  store i8* %__b, i8** %2, align 8
  %3 = load i8** %1, align 8
  %4 = load i8** %2, align 8
  call void @_ZSt4swapIhEvRT_S1_(i8* dereferenceable(1) %3, i8* dereferenceable(1) %4) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZSt9__reverseIPhEvT_S1_St26random_access_iterator_tag(i8* %__first, i8* %__last) #2 {
  %1 = alloca %"struct.std::random_access_iterator_tag", align 1
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  store i8* %__first, i8** %2, align 8
  store i8* %__last, i8** %3, align 8
  %4 = load i8** %2, align 8
  %5 = load i8** %3, align 8
  %6 = icmp eq i8* %4, %5
  br i1 %6, label %7, label %8

; <label>:7                                       ; preds = %0
  br label %22

; <label>:8                                       ; preds = %0
  %9 = load i8** %3, align 8
  %10 = getelementptr inbounds i8* %9, i32 -1
  store i8* %10, i8** %3, align 8
  br label %11

; <label>:11                                      ; preds = %15, %8
  %12 = load i8** %2, align 8
  %13 = load i8** %3, align 8
  %14 = icmp ult i8* %12, %13
  br i1 %14, label %15, label %22

; <label>:15                                      ; preds = %11
  %16 = load i8** %2, align 8
  %17 = load i8** %3, align 8
  call void @_ZSt9iter_swapIPhS0_EvT_T0_(i8* %16, i8* %17)
  %18 = load i8** %2, align 8
  %19 = getelementptr inbounds i8* %18, i32 1
  store i8* %19, i8** %2, align 8
  %20 = load i8** %3, align 8
  %21 = getelementptr inbounds i8* %20, i32 -1
  store i8* %21, i8** %3, align 8
  br label %11

; <label>:22                                      ; preds = %7, %11
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt19__iterator_categoryIPhENSt15iterator_traitsIT_E17iterator_categoryERKS2_(i8** dereferenceable(8)) #0 {
  %2 = alloca %"struct.std::random_access_iterator_tag", align 1
  %3 = alloca i8**, align 8
  store i8** %0, i8*** %3, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12_Destroy_auxILb1EE9__destroyIPjEEvT_S3_(i32*, i32*) #2 align 2 {
  %3 = alloca i32*, align 8
  %4 = alloca i32*, align 8
  store i32* %0, i32** %3, align 8
  store i32* %1, i32** %4, align 8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt8_DestroyIPjEvT_S1_(i32* %__first, i32* %__last) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  store i32* %__first, i32** %1, align 8
  store i32* %__last, i32** %2, align 8
  %3 = load i32** %1, align 8
  %4 = load i32** %2, align 8
  call void @_ZNSt12_Destroy_auxILb1EE9__destroyIPjEEvT_S3_(i32* %3, i32* %4)
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt8_DestroyIPjjEvT_S1_RSaIT0_E(i32* %__first, i32* %__last, %"class.std::allocator.57"* dereferenceable(1)) #0 {
  %2 = alloca i32*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca %"class.std::allocator.57"*, align 8
  store i32* %__first, i32** %2, align 8
  store i32* %__last, i32** %3, align 8
  store %"class.std::allocator.57"* %0, %"class.std::allocator.57"** %4, align 8
  %5 = load i32** %2, align 8
  %6 = load i32** %3, align 8
  call void @_ZSt8_DestroyIPjEvT_S1_(i32* %5, i32* %6)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(1) %"class.std::allocator.57"* @_ZNSt12_Vector_baseIjSaIjEE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.56"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Vector_base.56"*, align 8
  store %"struct.std::_Vector_base.56"* %this, %"struct.std::_Vector_base.56"** %1, align 8
  %2 = load %"struct.std::_Vector_base.56"** %1
  %3 = getelementptr inbounds %"struct.std::_Vector_base.56"* %2, i32 0, i32 0
  %4 = bitcast %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %3 to %"class.std::allocator.57"*
  ret %"class.std::allocator.57"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6vectorIjSaIjEED2Ev(%"class.std::vector.55"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::vector.55"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"class.std::vector.55"* %this, %"class.std::vector.55"** %1, align 8
  %4 = load %"class.std::vector.55"** %1
  %5 = bitcast %"class.std::vector.55"* %4 to %"struct.std::_Vector_base.56"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base.56"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %6, i32 0, i32 0
  %8 = load i32** %7, align 8
  %9 = bitcast %"class.std::vector.55"* %4 to %"struct.std::_Vector_base.56"*
  %10 = getelementptr inbounds %"struct.std::_Vector_base.56"* %9, i32 0, i32 0
  %11 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %10, i32 0, i32 1
  %12 = load i32** %11, align 8
  %13 = bitcast %"class.std::vector.55"* %4 to %"struct.std::_Vector_base.56"*
  %14 = call dereferenceable(1) %"class.std::allocator.57"* @_ZNSt12_Vector_baseIjSaIjEE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.56"* %13) #8
  invoke void @_ZSt8_DestroyIPjjEvT_S1_RSaIT0_E(i32* %8, i32* %12, %"class.std::allocator.57"* dereferenceable(1) %14)
          to label %15 unwind label %17

; <label>:15                                      ; preds = %0
  %16 = bitcast %"class.std::vector.55"* %4 to %"struct.std::_Vector_base.56"*
  call void @_ZNSt12_Vector_baseIjSaIjEED2Ev(%"struct.std::_Vector_base.56"* %16) #8
  ret void

; <label>:17                                      ; preds = %0
  %18 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %19 = extractvalue { i8*, i32 } %18, 0
  store i8* %19, i8** %2
  %20 = extractvalue { i8*, i32 } %18, 1
  store i32 %20, i32* %3
  %21 = bitcast %"class.std::vector.55"* %4 to %"struct.std::_Vector_base.56"*
  call void @_ZNSt12_Vector_baseIjSaIjEED2Ev(%"struct.std::_Vector_base.56"* %21) #8
  br label %22

; <label>:22                                      ; preds = %17
  %23 = load i8** %2
  call void @__clang_call_terminate(i8* %23) #18
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIjSaIjEED2Ev(%"struct.std::_Vector_base.56"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Vector_base.56"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"struct.std::_Vector_base.56"* %this, %"struct.std::_Vector_base.56"** %1, align 8
  %4 = load %"struct.std::_Vector_base.56"** %1
  %5 = getelementptr inbounds %"struct.std::_Vector_base.56"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %5, i32 0, i32 0
  %7 = load i32** %6, align 8
  %8 = getelementptr inbounds %"struct.std::_Vector_base.56"* %4, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %8, i32 0, i32 2
  %10 = load i32** %9, align 8
  %11 = getelementptr inbounds %"struct.std::_Vector_base.56"* %4, i32 0, i32 0
  %12 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %11, i32 0, i32 0
  %13 = load i32** %12, align 8
  %14 = ptrtoint i32* %10 to i64
  %15 = ptrtoint i32* %13 to i64
  %16 = sub i64 %14, %15
  %17 = sdiv exact i64 %16, 4
  invoke void @_ZNSt12_Vector_baseIjSaIjEE13_M_deallocateEPjm(%"struct.std::_Vector_base.56"* %4, i32* %7, i64 %17)
          to label %18 unwind label %20

; <label>:18                                      ; preds = %0
  %19 = getelementptr inbounds %"struct.std::_Vector_base.56"* %4, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIjSaIjEE12_Vector_implD2Ev(%"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %19) #8
  ret void

; <label>:20                                      ; preds = %0
  %21 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %22 = extractvalue { i8*, i32 } %21, 0
  store i8* %22, i8** %2
  %23 = extractvalue { i8*, i32 } %21, 1
  store i32 %23, i32* %3
  %24 = getelementptr inbounds %"struct.std::_Vector_base.56"* %4, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIjSaIjEE12_Vector_implD2Ev(%"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %24) #8
  br label %25

; <label>:25                                      ; preds = %20
  %26 = load i8** %2
  call void @__clang_call_terminate(i8* %26) #18
  unreachable
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIjSaIjEE13_M_deallocateEPjm(%"struct.std::_Vector_base.56"* %this, i32* %__p, i64 %__n) #7 align 2 {
  %1 = alloca %"struct.std::_Vector_base.56"*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  store %"struct.std::_Vector_base.56"* %this, %"struct.std::_Vector_base.56"** %1, align 8
  store i32* %__p, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load %"struct.std::_Vector_base.56"** %1
  %5 = load i32** %2, align 8
  %6 = icmp ne i32* %5, null
  br i1 %6, label %7, label %12

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %"struct.std::_Vector_base.56"* %4, i32 0, i32 0
  %9 = bitcast %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %8 to %"class.std::allocator.57"*
  %10 = load i32** %2, align 8
  %11 = load i64* %3, align 8
  call void @_ZNSt16allocator_traitsISaIjEE10deallocateERS0_Pjm(%"class.std::allocator.57"* dereferenceable(1) %9, i32* %10, i64 %11)
  br label %12

; <label>:12                                      ; preds = %7, %0
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIjSaIjEE12_Vector_implD2Ev(%"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %this) unnamed_addr #0 align 2 {
  %1 = alloca %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %this, %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"** %1, align 8
  %2 = load %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"** %1
  %3 = bitcast %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %2 to %"class.std::allocator.57"*
  call void @_ZNSaIjED2Ev(%"class.std::allocator.57"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSaIjED2Ev(%"class.std::allocator.57"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::allocator.57"*, align 8
  store %"class.std::allocator.57"* %this, %"class.std::allocator.57"** %1, align 8
  %2 = load %"class.std::allocator.57"** %1
  %3 = bitcast %"class.std::allocator.57"* %2 to %"class.__gnu_cxx::new_allocator.58"*
  call void @_ZN9__gnu_cxx13new_allocatorIjED2Ev(%"class.__gnu_cxx::new_allocator.58"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIjED2Ev(%"class.__gnu_cxx::new_allocator.58"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.58"*, align 8
  store %"class.__gnu_cxx::new_allocator.58"* %this, %"class.__gnu_cxx::new_allocator.58"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.58"** %1
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaIjEE10deallocateERS0_Pjm(%"class.std::allocator.57"* dereferenceable(1) %__a, i32* %__p, i64 %__n) #7 align 2 {
  %1 = alloca %"class.std::allocator.57"*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i64, align 8
  store %"class.std::allocator.57"* %__a, %"class.std::allocator.57"** %1, align 8
  store i32* %__p, i32** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load %"class.std::allocator.57"** %1, align 8
  %5 = bitcast %"class.std::allocator.57"* %4 to %"class.__gnu_cxx::new_allocator.58"*
  %6 = load i32** %2, align 8
  %7 = load i64* %3, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIjE10deallocateEPjm(%"class.__gnu_cxx::new_allocator.58"* %5, i32* %6, i64 %7)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIjE10deallocateEPjm(%"class.__gnu_cxx::new_allocator.58"* %this, i32* %__p, i64) #2 align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.58"*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca i64, align 8
  store %"class.__gnu_cxx::new_allocator.58"* %this, %"class.__gnu_cxx::new_allocator.58"** %2, align 8
  store i32* %__p, i32** %3, align 8
  store i64 %0, i64* %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator.58"** %2
  %6 = load i32** %3, align 8
  %7 = bitcast i32* %6 to i8*
  call void @_ZdlPv(i8* %7) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIjEC2Ev(%"class.__gnu_cxx::new_allocator.58"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.58"*, align 8
  store %"class.__gnu_cxx::new_allocator.58"* %this, %"class.__gnu_cxx::new_allocator.58"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.58"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSaIjEC2Ev(%"class.std::allocator.57"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::allocator.57"*, align 8
  store %"class.std::allocator.57"* %this, %"class.std::allocator.57"** %1, align 8
  %2 = load %"class.std::allocator.57"** %1
  %3 = bitcast %"class.std::allocator.57"* %2 to %"class.__gnu_cxx::new_allocator.58"*
  call void @_ZN9__gnu_cxx13new_allocatorIjEC2Ev(%"class.__gnu_cxx::new_allocator.58"* %3) #8
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIjSaIjEEC2Ev(%"struct.std::_Vector_base.56"* %this) unnamed_addr #7 align 2 {
  %1 = alloca %"struct.std::_Vector_base.56"*, align 8
  store %"struct.std::_Vector_base.56"* %this, %"struct.std::_Vector_base.56"** %1, align 8
  %2 = load %"struct.std::_Vector_base.56"** %1
  %3 = getelementptr inbounds %"struct.std::_Vector_base.56"* %2, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIjSaIjEE12_Vector_implC2Ev(%"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %3)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIjSaIjEE12_Vector_implC2Ev(%"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %this, %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"** %1, align 8
  %2 = load %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"** %1
  %3 = bitcast %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %2 to %"class.std::allocator.57"*
  call void @_ZNSaIjEC2Ev(%"class.std::allocator.57"* %3) #8
  %4 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %2, i32 0, i32 0
  store i32* null, i32** %4, align 8
  %5 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %2, i32 0, i32 1
  store i32* null, i32** %5, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base<unsigned int, std::allocator<unsigned int> >::_Vector_impl"* %2, i32 0, i32 2
  store i32* null, i32** %6, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSaIdED2Ev(%"class.std::allocator.61"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::allocator.61"*, align 8
  store %"class.std::allocator.61"* %this, %"class.std::allocator.61"** %1, align 8
  %2 = load %"class.std::allocator.61"** %1
  %3 = bitcast %"class.std::allocator.61"* %2 to %"class.__gnu_cxx::new_allocator.62"*
  call void @_ZN9__gnu_cxx13new_allocatorIdED2Ev(%"class.__gnu_cxx::new_allocator.62"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIdED2Ev(%"class.__gnu_cxx::new_allocator.62"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.62"*, align 8
  store %"class.__gnu_cxx::new_allocator.62"* %this, %"class.__gnu_cxx::new_allocator.62"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.62"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIdEC2Ev(%"class.__gnu_cxx::new_allocator.62"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.62"*, align 8
  store %"class.__gnu_cxx::new_allocator.62"* %this, %"class.__gnu_cxx::new_allocator.62"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.62"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSaIdEC2Ev(%"class.std::allocator.61"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::allocator.61"*, align 8
  store %"class.std::allocator.61"* %this, %"class.std::allocator.61"** %1, align 8
  %2 = load %"class.std::allocator.61"** %1
  %3 = bitcast %"class.std::allocator.61"* %2 to %"class.__gnu_cxx::new_allocator.62"*
  call void @_ZN9__gnu_cxx13new_allocatorIdEC2Ev(%"class.__gnu_cxx::new_allocator.62"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIcEC2Ev(%"class.__gnu_cxx::new_allocator.33"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.33"*, align 8
  store %"class.__gnu_cxx::new_allocator.33"* %this, %"class.__gnu_cxx::new_allocator.33"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.33"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep"* @_ZNKSbIDiSt11char_traitsIDiESaIDiEE6_M_repEv(%"class.std::basic_string.51"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.51"*, align 8
  store %"class.std::basic_string.51"* %this, %"class.std::basic_string.51"** %1, align 8
  %2 = load %"class.std::basic_string.51"** %1
  %3 = call i32* @_ZNKSbIDiSt11char_traitsIDiESaIDiEE7_M_dataEv(%"class.std::basic_string.51"* %2) #8
  %4 = bitcast i32* %3 to %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep"*
  %5 = getelementptr inbounds %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep"* %4, i64 -1
  ret %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Rep"* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i32* @_ZNKSbIDiSt11char_traitsIDiESaIDiEE7_M_dataEv(%"class.std::basic_string.51"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.51"*, align 8
  store %"class.std::basic_string.51"* %this, %"class.std::basic_string.51"** %1, align 8
  %2 = load %"class.std::basic_string.51"** %1
  %3 = getelementptr inbounds %"class.std::basic_string.51"* %2, i32 0, i32 0
  %4 = getelementptr inbounds %"struct.std::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t> >::_Alloc_hider"* %3, i32 0, i32 0
  %5 = load i32** %4, align 8
  ret i32* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep"* @_ZNKSbIDsSt11char_traitsIDsESaIDsEE6_M_repEv(%"class.std::basic_string.45"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.45"*, align 8
  store %"class.std::basic_string.45"* %this, %"class.std::basic_string.45"** %1, align 8
  %2 = load %"class.std::basic_string.45"** %1
  %3 = call i16* @_ZNKSbIDsSt11char_traitsIDsESaIDsEE7_M_dataEv(%"class.std::basic_string.45"* %2) #8
  %4 = bitcast i16* %3 to %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep"*
  %5 = getelementptr inbounds %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep"* %4, i64 -1
  ret %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Rep"* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i16* @_ZNKSbIDsSt11char_traitsIDsESaIDsEE7_M_dataEv(%"class.std::basic_string.45"* %this) #2 align 2 {
  %1 = alloca %"class.std::basic_string.45"*, align 8
  store %"class.std::basic_string.45"* %this, %"class.std::basic_string.45"** %1, align 8
  %2 = load %"class.std::basic_string.45"** %1
  %3 = getelementptr inbounds %"class.std::basic_string.45"* %2, i32 0, i32 0
  %4 = getelementptr inbounds %"struct.std::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t> >::_Alloc_hider"* %3, i32 0, i32 0
  %5 = load i16** %4, align 8
  ret i16* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIwEC2ERKS1_(%"class.__gnu_cxx::new_allocator.37"* %this, %"class.__gnu_cxx::new_allocator.37"* dereferenceable(1)) unnamed_addr #2 align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.37"*, align 8
  %3 = alloca %"class.__gnu_cxx::new_allocator.37"*, align 8
  store %"class.__gnu_cxx::new_allocator.37"* %this, %"class.__gnu_cxx::new_allocator.37"** %2, align 8
  store %"class.__gnu_cxx::new_allocator.37"* %0, %"class.__gnu_cxx::new_allocator.37"** %3, align 8
  %4 = load %"class.__gnu_cxx::new_allocator.37"** %2
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt10__distanceIPwENSt15iterator_traitsIT_E15difference_typeES2_S2_St26random_access_iterator_tag(i32* %__first, i32* %__last) #0 {
  %1 = alloca %"struct.std::random_access_iterator_tag", align 1
  %2 = alloca i32*, align 8
  %3 = alloca i32*, align 8
  store i32* %__first, i32** %2, align 8
  store i32* %__last, i32** %3, align 8
  %4 = load i32** %3, align 8
  %5 = load i32** %2, align 8
  %6 = ptrtoint i32* %4 to i64
  %7 = ptrtoint i32* %5 to i64
  %8 = sub i64 %6, %7
  %9 = sdiv exact i64 %8, 4
  ret i64 %9
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt19__iterator_categoryIPwENSt15iterator_traitsIT_E17iterator_categoryERKS2_(i32** dereferenceable(8)) #0 {
  %2 = alloca %"struct.std::random_access_iterator_tag", align 1
  %3 = alloca i32**, align 8
  store i32** %0, i32*** %3, align 8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt8distanceIPwENSt15iterator_traitsIT_E15difference_typeES2_S2_(i32* %__first, i32* %__last) #0 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca %"struct.std::random_access_iterator_tag", align 1
  %4 = alloca %"struct.std::random_access_iterator_tag", align 1
  store i32* %__first, i32** %1, align 8
  store i32* %__last, i32** %2, align 8
  %5 = load i32** %1, align 8
  %6 = load i32** %2, align 8
  call void @_ZSt19__iterator_categoryIPwENSt15iterator_traitsIT_E17iterator_categoryERKS2_(i32** dereferenceable(8) %1)
  %7 = call i64 @_ZSt10__distanceIPwENSt15iterator_traitsIT_E15difference_typeES2_S2_St26random_access_iterator_tag(i32* %5, i32* %6)
  ret i64 %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i1 @_ZN9__gnu_cxx17__is_null_pointerIwEEbPT_(i32* %__ptr) #0 {
  %1 = alloca i32*, align 8
  store i32* %__ptr, i32** %1, align 8
  %2 = load i32** %1, align 8
  %3 = icmp eq i32* %2, null
  ret i1 %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i1 @_ZSteqIwEbRKSaIT_ES3_(%"class.std::allocator.36"* dereferenceable(1), %"class.std::allocator.36"* dereferenceable(1)) #0 {
  %3 = alloca %"class.std::allocator.36"*, align 8
  %4 = alloca %"class.std::allocator.36"*, align 8
  store %"class.std::allocator.36"* %0, %"class.std::allocator.36"** %3, align 8
  store %"class.std::allocator.36"* %1, %"class.std::allocator.36"** %4, align 8
  ret i1 true
}

; Function Attrs: uwtable
define linkonce_odr i32* @_ZNSbIwSt11char_traitsIwESaIwEE12_S_constructIPwEES4_T_S5_RKS1_St20forward_iterator_tag(i32* %__beg, i32* %__end, %"class.std::allocator.36"* dereferenceable(1) %__a) #7 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca %"struct.std::forward_iterator_tag", align 1
  %3 = alloca i32*, align 8
  %4 = alloca i32*, align 8
  %5 = alloca %"class.std::allocator.36"*, align 8
  %6 = alloca %"class.std::allocator.36", align 1
  %7 = alloca i1
  %8 = alloca i8*
  %9 = alloca i32
  %__dnew = alloca i64, align 8
  %__r = alloca %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"*, align 8
  store i32* %__beg, i32** %3, align 8
  store i32* %__end, i32** %4, align 8
  store %"class.std::allocator.36"* %__a, %"class.std::allocator.36"** %5, align 8
  %10 = load i32** %3, align 8
  %11 = load i32** %4, align 8
  %12 = icmp eq i32* %10, %11
  store i1 false, i1* %7
  br i1 %12, label %13, label %17

; <label>:13                                      ; preds = %0
  %14 = load %"class.std::allocator.36"** %5, align 8
  call void @_ZNSaIwEC1Ev(%"class.std::allocator.36"* %6) #8
  store i1 true, i1* %7
  %15 = invoke zeroext i1 @_ZSteqIwEbRKSaIT_ES3_(%"class.std::allocator.36"* dereferenceable(1) %14, %"class.std::allocator.36"* dereferenceable(1) %6)
          to label %16 unwind label %25

; <label>:16                                      ; preds = %13
  br label %17

; <label>:17                                      ; preds = %16, %0
  %18 = phi i1 [ false, %0 ], [ %15, %16 ]
  %19 = load i1* %7
  br i1 %19, label %20, label %21

; <label>:20                                      ; preds = %17
  call void @_ZNSaIwED1Ev(%"class.std::allocator.36"* %6) #8
  br label %21

; <label>:21                                      ; preds = %20, %17
  br i1 %18, label %22, label %32

; <label>:22                                      ; preds = %21
  %23 = call dereferenceable(24) %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* @_ZNSbIwSt11char_traitsIwESaIwEE12_S_empty_repEv() #8
  %24 = call i32* @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep10_M_refdataEv(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* %23) #8
  store i32* %24, i32** %1
  br label %55

; <label>:25                                      ; preds = %13
  %26 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %27 = extractvalue { i8*, i32 } %26, 0
  store i8* %27, i8** %8
  %28 = extractvalue { i8*, i32 } %26, 1
  store i32 %28, i32* %9
  %29 = load i1* %7
  br i1 %29, label %30, label %31

; <label>:30                                      ; preds = %25
  call void @_ZNSaIwED1Ev(%"class.std::allocator.36"* %6) #8
  br label %31

; <label>:31                                      ; preds = %30, %25
  br label %57

; <label>:32                                      ; preds = %21
  %33 = load i32** %3, align 8
  %34 = call zeroext i1 @_ZN9__gnu_cxx17__is_null_pointerIwEEbPT_(i32* %33)
  br i1 %34, label %35, label %40

; <label>:35                                      ; preds = %32
  %36 = load i32** %3, align 8
  %37 = load i32** %4, align 8
  %38 = icmp ne i32* %36, %37
  br i1 %38, label %39, label %40

; <label>:39                                      ; preds = %35
  call void @_ZSt19__throw_logic_errorPKc(i8* getelementptr inbounds ([42 x i8]* @.str29, i32 0, i32 0)) #17
  unreachable

; <label>:40                                      ; preds = %35, %32
  %41 = load i32** %3, align 8
  %42 = load i32** %4, align 8
  %43 = call i64 @_ZSt8distanceIPwENSt15iterator_traitsIT_E15difference_typeES2_S2_(i32* %41, i32* %42)
  store i64 %43, i64* %__dnew, align 8
  %44 = load i64* %__dnew, align 8
  %45 = load %"class.std::allocator.36"** %5, align 8
  %46 = call %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep9_S_createEmmRKS1_(i64 %44, i64 0, %"class.std::allocator.36"* dereferenceable(1) %45)
  store %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* %46, %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"** %__r, align 8
  %47 = load %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"** %__r, align 8
  %48 = call i32* @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep10_M_refdataEv(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* %47) #8
  %49 = load i32** %3, align 8
  %50 = load i32** %4, align 8
  call void @_ZNSbIwSt11char_traitsIwESaIwEE13_S_copy_charsEPwS3_S3_(i32* %48, i32* %49, i32* %50) #8
  %51 = load %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"** %__r, align 8
  %52 = load i64* %__dnew, align 8
  call void @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep26_M_set_length_and_sharableEm(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* %51, i64 %52) #8
  %53 = load %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"** %__r, align 8
  %54 = call i32* @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep10_M_refdataEv(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* %53) #8
  store i32* %54, i32** %1
  br label %55

; <label>:55                                      ; preds = %40, %22
  %56 = load i32** %1
  ret i32* %56

; <label>:57                                      ; preds = %31
  %58 = load i8** %8
  %59 = load i32* %9
  %60 = insertvalue { i8*, i32 } undef, i8* %58, 0
  %61 = insertvalue { i8*, i32 } %60, i32 %59, 1
  resume { i8*, i32 } %61
}

; Function Attrs: nounwind
declare void @_ZNSaIwEC1Ev(%"class.std::allocator.36"*) #3

; Function Attrs: nounwind
declare void @_ZNSaIwED1Ev(%"class.std::allocator.36"*) #3

; Function Attrs: nounwind
declare dereferenceable(24) %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* @_ZNSbIwSt11char_traitsIwESaIwEE12_S_empty_repEv() #3

; Function Attrs: nounwind
declare i32* @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep10_M_refdataEv(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"*) #3

; Function Attrs: noreturn
declare void @_ZSt19__throw_logic_errorPKc(i8*) #6

declare %"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"* @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep9_S_createEmmRKS1_(i64, i64, %"class.std::allocator.36"* dereferenceable(1)) #9

; Function Attrs: nounwind
declare void @_ZNSbIwSt11char_traitsIwESaIwEE13_S_copy_charsEPwS3_S3_(i32*, i32*, i32*) #3

; Function Attrs: nounwind
declare void @_ZNSbIwSt11char_traitsIwESaIwEE4_Rep26_M_set_length_and_sharableEm(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Rep"*, i64) #3

; Function Attrs: uwtable
define linkonce_odr i32* @_ZNSbIwSt11char_traitsIwESaIwEE16_S_construct_auxIPwEES4_T_S5_RKS1_St12__false_type(i32* %__beg, i32* %__end, %"class.std::allocator.36"* dereferenceable(1) %__a) #7 align 2 {
  %1 = alloca %"struct.std::__false_type", align 1
  %2 = alloca i32*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca %"class.std::allocator.36"*, align 8
  %5 = alloca %"struct.std::forward_iterator_tag", align 1
  %6 = alloca %"struct.std::random_access_iterator_tag", align 1
  store i32* %__beg, i32** %2, align 8
  store i32* %__end, i32** %3, align 8
  store %"class.std::allocator.36"* %__a, %"class.std::allocator.36"** %4, align 8
  %7 = load i32** %2, align 8
  %8 = load i32** %3, align 8
  %9 = load %"class.std::allocator.36"** %4, align 8
  %10 = bitcast %"struct.std::random_access_iterator_tag"* %6 to %"struct.std::forward_iterator_tag"*
  %11 = call i32* @_ZNSbIwSt11char_traitsIwESaIwEE12_S_constructIPwEES4_T_S5_RKS1_St20forward_iterator_tag(i32* %7, i32* %8, %"class.std::allocator.36"* dereferenceable(1) %9)
  ret i32* %11
}

; Function Attrs: uwtable
define linkonce_odr i32* @_ZNSbIwSt11char_traitsIwESaIwEE12_S_constructIPwEES4_T_S5_RKS1_(i32* %__beg, i32* %__end, %"class.std::allocator.36"* dereferenceable(1) %__a) #7 align 2 {
  %1 = alloca i32*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca %"class.std::allocator.36"*, align 8
  %4 = alloca %"struct.std::__false_type", align 1
  store i32* %__beg, i32** %1, align 8
  store i32* %__end, i32** %2, align 8
  store %"class.std::allocator.36"* %__a, %"class.std::allocator.36"** %3, align 8
  %5 = load i32** %1, align 8
  %6 = load i32** %2, align 8
  %7 = load %"class.std::allocator.36"** %3, align 8
  %8 = call i32* @_ZNSbIwSt11char_traitsIwESaIwEE16_S_construct_auxIPwEES4_T_S5_RKS1_St12__false_type(i32* %5, i32* %6, %"class.std::allocator.36"* dereferenceable(1) %7)
  ret i32* %8
}

; Function Attrs: nounwind
declare void @_ZNSbIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS1_(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Alloc_hider"*, i32*, %"class.std::allocator.36"* dereferenceable(1)) #3

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIwED2Ev(%"class.__gnu_cxx::new_allocator.37"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.37"*, align 8
  store %"class.__gnu_cxx::new_allocator.37"* %this, %"class.__gnu_cxx::new_allocator.37"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.37"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIwEC2Ev(%"class.__gnu_cxx::new_allocator.37"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.37"*, align 8
  store %"class.__gnu_cxx::new_allocator.37"* %this, %"class.__gnu_cxx::new_allocator.37"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.37"** %1
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSbIwSt11char_traitsIwESaIwEEC2IPwEET_S5_RKS1_(%"class.std::basic_string.35"* %this, i32* %__beg, i32* %__end, %"class.std::allocator.36"* dereferenceable(1) %__a) unnamed_addr #7 align 2 {
  %1 = alloca %"class.std::basic_string.35"*, align 8
  %2 = alloca i32*, align 8
  %3 = alloca i32*, align 8
  %4 = alloca %"class.std::allocator.36"*, align 8
  store %"class.std::basic_string.35"* %this, %"class.std::basic_string.35"** %1, align 8
  store i32* %__beg, i32** %2, align 8
  store i32* %__end, i32** %3, align 8
  store %"class.std::allocator.36"* %__a, %"class.std::allocator.36"** %4, align 8
  %5 = load %"class.std::basic_string.35"** %1
  %6 = getelementptr inbounds %"class.std::basic_string.35"* %5, i32 0, i32 0
  %7 = load i32** %2, align 8
  %8 = load i32** %3, align 8
  %9 = load %"class.std::allocator.36"** %4, align 8
  %10 = call i32* @_ZNSbIwSt11char_traitsIwESaIwEE12_S_constructIPwEES4_T_S5_RKS1_(i32* %7, i32* %8, %"class.std::allocator.36"* dereferenceable(1) %9)
  %11 = load %"class.std::allocator.36"** %4, align 8
  call void @_ZNSbIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS1_(%"struct.std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> >::_Alloc_hider"* %6, i32* %10, %"class.std::allocator.36"* dereferenceable(1) %11) #8
  ret void
}

; Function Attrs: nounwind readnone
declare i32* @__errno_location() #12

; Function Attrs: noreturn
declare void @_ZSt24__throw_invalid_argumentPKc(i8*) #6

; Function Attrs: noreturn
declare void @_ZSt20__throw_out_of_rangePKc(i8*) #6

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIcED2Ev(%"class.__gnu_cxx::new_allocator.33"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.33"*, align 8
  store %"class.__gnu_cxx::new_allocator.33"* %this, %"class.__gnu_cxx::new_allocator.33"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.33"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIcEC2ERKS1_(%"class.__gnu_cxx::new_allocator.33"* %this, %"class.__gnu_cxx::new_allocator.33"* dereferenceable(1)) unnamed_addr #2 align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.33"*, align 8
  %3 = alloca %"class.__gnu_cxx::new_allocator.33"*, align 8
  store %"class.__gnu_cxx::new_allocator.33"* %this, %"class.__gnu_cxx::new_allocator.33"** %2, align 8
  store %"class.__gnu_cxx::new_allocator.33"* %0, %"class.__gnu_cxx::new_allocator.33"** %3, align 8
  %4 = load %"class.__gnu_cxx::new_allocator.33"** %2
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt10__distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_St26random_access_iterator_tag(i8* %__first, i8* %__last) #0 {
  %1 = alloca %"struct.std::random_access_iterator_tag", align 1
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  store i8* %__first, i8** %2, align 8
  store i8* %__last, i8** %3, align 8
  %4 = load i8** %3, align 8
  %5 = load i8** %2, align 8
  %6 = ptrtoint i8* %4 to i64
  %7 = ptrtoint i8* %5 to i64
  %8 = sub i64 %6, %7
  ret i64 %8
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt19__iterator_categoryIPcENSt15iterator_traitsIT_E17iterator_categoryERKS2_(i8** dereferenceable(8)) #0 {
  %2 = alloca %"struct.std::random_access_iterator_tag", align 1
  %3 = alloca i8**, align 8
  store i8** %0, i8*** %3, align 8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64 @_ZSt8distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_(i8* %__first, i8* %__last) #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca %"struct.std::random_access_iterator_tag", align 1
  %4 = alloca %"struct.std::random_access_iterator_tag", align 1
  store i8* %__first, i8** %1, align 8
  store i8* %__last, i8** %2, align 8
  %5 = load i8** %1, align 8
  %6 = load i8** %2, align 8
  call void @_ZSt19__iterator_categoryIPcENSt15iterator_traitsIT_E17iterator_categoryERKS2_(i8** dereferenceable(8) %1)
  %7 = call i64 @_ZSt10__distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_St26random_access_iterator_tag(i8* %5, i8* %6)
  ret i64 %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i1 @_ZN9__gnu_cxx17__is_null_pointerIcEEbPT_(i8* %__ptr) #0 {
  %1 = alloca i8*, align 8
  store i8* %__ptr, i8** %1, align 8
  %2 = load i8** %1, align 8
  %3 = icmp eq i8* %2, null
  ret i1 %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr zeroext i1 @_ZSteqIcEbRKSaIT_ES3_(%"class.std::allocator.32"* dereferenceable(1), %"class.std::allocator.32"* dereferenceable(1)) #0 {
  %3 = alloca %"class.std::allocator.32"*, align 8
  %4 = alloca %"class.std::allocator.32"*, align 8
  store %"class.std::allocator.32"* %0, %"class.std::allocator.32"** %3, align 8
  store %"class.std::allocator.32"* %1, %"class.std::allocator.32"** %4, align 8
  ret i1 true
}

; Function Attrs: uwtable
define linkonce_odr i8* @_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag(i8* %__beg, i8* %__end, %"class.std::allocator.32"* dereferenceable(1) %__a) #7 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca %"struct.std::forward_iterator_tag", align 1
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  %5 = alloca %"class.std::allocator.32"*, align 8
  %6 = alloca %"class.std::allocator.32", align 1
  %7 = alloca i1
  %8 = alloca i8*
  %9 = alloca i32
  %__dnew = alloca i64, align 8
  %__r = alloca %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"*, align 8
  store i8* %__beg, i8** %3, align 8
  store i8* %__end, i8** %4, align 8
  store %"class.std::allocator.32"* %__a, %"class.std::allocator.32"** %5, align 8
  %10 = load i8** %3, align 8
  %11 = load i8** %4, align 8
  %12 = icmp eq i8* %10, %11
  store i1 false, i1* %7
  br i1 %12, label %13, label %17

; <label>:13                                      ; preds = %0
  %14 = load %"class.std::allocator.32"** %5, align 8
  call void @_ZNSaIcEC1Ev(%"class.std::allocator.32"* %6) #8
  store i1 true, i1* %7
  %15 = invoke zeroext i1 @_ZSteqIcEbRKSaIT_ES3_(%"class.std::allocator.32"* dereferenceable(1) %14, %"class.std::allocator.32"* dereferenceable(1) %6)
          to label %16 unwind label %25

; <label>:16                                      ; preds = %13
  br label %17

; <label>:17                                      ; preds = %16, %0
  %18 = phi i1 [ false, %0 ], [ %15, %16 ]
  %19 = load i1* %7
  br i1 %19, label %20, label %21

; <label>:20                                      ; preds = %17
  call void @_ZNSaIcED1Ev(%"class.std::allocator.32"* %6) #8
  br label %21

; <label>:21                                      ; preds = %20, %17
  br i1 %18, label %22, label %32

; <label>:22                                      ; preds = %21
  %23 = call dereferenceable(24) %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* @_ZNSs12_S_empty_repEv() #8
  %24 = call i8* @_ZNSs4_Rep10_M_refdataEv(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* %23) #8
  store i8* %24, i8** %1
  br label %55

; <label>:25                                      ; preds = %13
  %26 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %27 = extractvalue { i8*, i32 } %26, 0
  store i8* %27, i8** %8
  %28 = extractvalue { i8*, i32 } %26, 1
  store i32 %28, i32* %9
  %29 = load i1* %7
  br i1 %29, label %30, label %31

; <label>:30                                      ; preds = %25
  call void @_ZNSaIcED1Ev(%"class.std::allocator.32"* %6) #8
  br label %31

; <label>:31                                      ; preds = %30, %25
  br label %57

; <label>:32                                      ; preds = %21
  %33 = load i8** %3, align 8
  %34 = call zeroext i1 @_ZN9__gnu_cxx17__is_null_pointerIcEEbPT_(i8* %33)
  br i1 %34, label %35, label %40

; <label>:35                                      ; preds = %32
  %36 = load i8** %3, align 8
  %37 = load i8** %4, align 8
  %38 = icmp ne i8* %36, %37
  br i1 %38, label %39, label %40

; <label>:39                                      ; preds = %35
  call void @_ZSt19__throw_logic_errorPKc(i8* getelementptr inbounds ([42 x i8]* @.str29, i32 0, i32 0)) #17
  unreachable

; <label>:40                                      ; preds = %35, %32
  %41 = load i8** %3, align 8
  %42 = load i8** %4, align 8
  %43 = call i64 @_ZSt8distanceIPcENSt15iterator_traitsIT_E15difference_typeES2_S2_(i8* %41, i8* %42)
  store i64 %43, i64* %__dnew, align 8
  %44 = load i64* %__dnew, align 8
  %45 = load %"class.std::allocator.32"** %5, align 8
  %46 = call %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* @_ZNSs4_Rep9_S_createEmmRKSaIcE(i64 %44, i64 0, %"class.std::allocator.32"* dereferenceable(1) %45)
  store %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* %46, %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"** %__r, align 8
  %47 = load %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"** %__r, align 8
  %48 = call i8* @_ZNSs4_Rep10_M_refdataEv(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* %47) #8
  %49 = load i8** %3, align 8
  %50 = load i8** %4, align 8
  call void @_ZNSs13_S_copy_charsEPcS_S_(i8* %48, i8* %49, i8* %50) #8
  %51 = load %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"** %__r, align 8
  %52 = load i64* %__dnew, align 8
  call void @_ZNSs4_Rep26_M_set_length_and_sharableEm(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* %51, i64 %52) #8
  %53 = load %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"** %__r, align 8
  %54 = call i8* @_ZNSs4_Rep10_M_refdataEv(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* %53) #8
  store i8* %54, i8** %1
  br label %55

; <label>:55                                      ; preds = %40, %22
  %56 = load i8** %1
  ret i8* %56

; <label>:57                                      ; preds = %31
  %58 = load i8** %8
  %59 = load i32* %9
  %60 = insertvalue { i8*, i32 } undef, i8* %58, 0
  %61 = insertvalue { i8*, i32 } %60, i32 %59, 1
  resume { i8*, i32 } %61
}

; Function Attrs: nounwind
declare void @_ZNSaIcEC1Ev(%"class.std::allocator.32"*) #3

; Function Attrs: nounwind
declare void @_ZNSaIcED1Ev(%"class.std::allocator.32"*) #3

; Function Attrs: nounwind
declare dereferenceable(24) %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* @_ZNSs12_S_empty_repEv() #3

; Function Attrs: nounwind
declare i8* @_ZNSs4_Rep10_M_refdataEv(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"*) #3

declare %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"* @_ZNSs4_Rep9_S_createEmmRKSaIcE(i64, i64, %"class.std::allocator.32"* dereferenceable(1)) #9

; Function Attrs: nounwind
declare void @_ZNSs13_S_copy_charsEPcS_S_(i8*, i8*, i8*) #3

; Function Attrs: nounwind
declare void @_ZNSs4_Rep26_M_set_length_and_sharableEm(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Rep"*, i64) #3

; Function Attrs: uwtable
define linkonce_odr i8* @_ZNSs16_S_construct_auxIPcEES0_T_S1_RKSaIcESt12__false_type(i8* %__beg, i8* %__end, %"class.std::allocator.32"* dereferenceable(1) %__a) #7 align 2 {
  %1 = alloca %"struct.std::__false_type", align 1
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca %"class.std::allocator.32"*, align 8
  %5 = alloca %"struct.std::forward_iterator_tag", align 1
  %6 = alloca %"struct.std::random_access_iterator_tag", align 1
  store i8* %__beg, i8** %2, align 8
  store i8* %__end, i8** %3, align 8
  store %"class.std::allocator.32"* %__a, %"class.std::allocator.32"** %4, align 8
  %7 = load i8** %2, align 8
  %8 = load i8** %3, align 8
  %9 = load %"class.std::allocator.32"** %4, align 8
  %10 = bitcast %"struct.std::random_access_iterator_tag"* %6 to %"struct.std::forward_iterator_tag"*
  %11 = call i8* @_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag(i8* %7, i8* %8, %"class.std::allocator.32"* dereferenceable(1) %9)
  ret i8* %11
}

; Function Attrs: uwtable
define linkonce_odr i8* @_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcE(i8* %__beg, i8* %__end, %"class.std::allocator.32"* dereferenceable(1) %__a) #7 align 2 {
  %1 = alloca i8*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca %"class.std::allocator.32"*, align 8
  %4 = alloca %"struct.std::__false_type", align 1
  store i8* %__beg, i8** %1, align 8
  store i8* %__end, i8** %2, align 8
  store %"class.std::allocator.32"* %__a, %"class.std::allocator.32"** %3, align 8
  %5 = load i8** %1, align 8
  %6 = load i8** %2, align 8
  %7 = load %"class.std::allocator.32"** %3, align 8
  %8 = call i8* @_ZNSs16_S_construct_auxIPcEES0_T_S1_RKSaIcESt12__false_type(i8* %5, i8* %6, %"class.std::allocator.32"* dereferenceable(1) %7)
  ret i8* %8
}

; Function Attrs: nounwind
declare void @_ZNSs12_Alloc_hiderC1EPcRKSaIcE(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider"*, i8*, %"class.std::allocator.32"* dereferenceable(1)) #3

; Function Attrs: uwtable
define linkonce_odr void @_ZNSsC2IPcEET_S1_RKSaIcE(%"class.std::basic_string"* %this, i8* %__beg, i8* %__end, %"class.std::allocator.32"* dereferenceable(1) %__a) unnamed_addr #7 align 2 {
  %1 = alloca %"class.std::basic_string"*, align 8
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca %"class.std::allocator.32"*, align 8
  store %"class.std::basic_string"* %this, %"class.std::basic_string"** %1, align 8
  store i8* %__beg, i8** %2, align 8
  store i8* %__end, i8** %3, align 8
  store %"class.std::allocator.32"* %__a, %"class.std::allocator.32"** %4, align 8
  %5 = load %"class.std::basic_string"** %1
  %6 = getelementptr inbounds %"class.std::basic_string"* %5, i32 0, i32 0
  %7 = load i8** %2, align 8
  %8 = load i8** %3, align 8
  %9 = load %"class.std::allocator.32"** %4, align 8
  %10 = call i8* @_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcE(i8* %7, i8* %8, %"class.std::allocator.32"* dereferenceable(1) %9)
  %11 = load %"class.std::allocator.32"** %4, align 8
  call void @_ZNSs12_Alloc_hiderC1EPcRKSaIcE(%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider"* %6, i8* %10, %"class.std::allocator.32"* dereferenceable(1) %11) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6vectorIN2fp6ActionESaIS1_EE15_M_erase_at_endEPS1_(%"class.std::vector"* %this, %"struct.fp::Action"* %__pos) #2 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store %"struct.fp::Action"* %__pos, %"struct.fp::Action"** %2, align 8
  %3 = load %"class.std::vector"** %1
  %4 = load %"struct.fp::Action"** %2, align 8
  %5 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %6, i32 0, i32 1
  %8 = load %"struct.fp::Action"** %7, align 8
  %9 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %10 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %9) #8
  invoke void @_ZSt8_DestroyIPN2fp6ActionES1_EvT_S3_RSaIT0_E(%"struct.fp::Action"* %4, %"struct.fp::Action"* %8, %"class.std::allocator"* dereferenceable(1) %10)
          to label %11 unwind label %16

; <label>:11                                      ; preds = %0
  %12 = load %"struct.fp::Action"** %2, align 8
  %13 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %14 = getelementptr inbounds %"struct.std::_Vector_base"* %13, i32 0, i32 0
  %15 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %14, i32 0, i32 1
  store %"struct.fp::Action"* %12, %"struct.fp::Action"** %15, align 8
  ret void

; <label>:16                                      ; preds = %0
  %17 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %18 = extractvalue { i8*, i32 } %17, 0
  call void @__clang_call_terminate(i8* %18) #18
  unreachable
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt8_DestroyIPN2fp6ActionES1_EvT_S3_RSaIT0_E(%"struct.fp::Action"* %__first, %"struct.fp::Action"* %__last, %"class.std::allocator"* dereferenceable(1)) #0 {
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  %4 = alloca %"class.std::allocator"*, align 8
  store %"struct.fp::Action"* %__first, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__last, %"struct.fp::Action"** %3, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %4, align 8
  %5 = load %"struct.fp::Action"** %2, align 8
  %6 = load %"struct.fp::Action"** %3, align 8
  call void @_ZSt8_DestroyIPN2fp6ActionEEvT_S3_(%"struct.fp::Action"* %5, %"struct.fp::Action"* %6)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  %2 = load %"struct.std::_Vector_base"** %1
  %3 = getelementptr inbounds %"struct.std::_Vector_base"* %2, i32 0, i32 0
  %4 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %3 to %"class.std::allocator"*
  ret %"class.std::allocator"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) %"struct.fp::Action"** @_ZNK9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator"* %this) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %this, %"class.__gnu_cxx::__normal_iterator"** %1, align 8
  %2 = load %"class.__gnu_cxx::__normal_iterator"** %1
  %3 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator"* %2, i32 0, i32 0
  ret %"struct.fp::Action"** %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx17__normal_iteratorIPN2fp6ActionESt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator"* %this, %"struct.fp::Action"** dereferenceable(8) %__i) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  %2 = alloca %"struct.fp::Action"**, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %this, %"class.__gnu_cxx::__normal_iterator"** %1, align 8
  store %"struct.fp::Action"** %__i, %"struct.fp::Action"*** %2, align 8
  %3 = load %"class.__gnu_cxx::__normal_iterator"** %1
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator"* %3, i32 0, i32 0
  %5 = load %"struct.fp::Action"*** %2, align 8
  %6 = load %"struct.fp::Action"** %5, align 8
  store %"struct.fp::Action"* %6, %"struct.fp::Action"** %4, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator"* %this, %"struct.fp::Action"* %__p) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"class.__gnu_cxx::new_allocator"* %this, %"class.__gnu_cxx::new_allocator"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator"** %1
  %4 = load %"struct.fp::Action"** %2, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE10_S_destroyIS1_EENSt9enable_ifIXsr6__and_INS3_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS2_PS7_(%"class.std::allocator"* dereferenceable(1) %__a, %"struct.fp::Action"* %__p) #2 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  %3 = load %"class.std::allocator"** %1, align 8
  %4 = bitcast %"class.std::allocator"* %3 to %"class.__gnu_cxx::new_allocator"*
  %5 = load %"struct.fp::Action"** %2, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator"* %4, %"struct.fp::Action"* %5)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator"* dereferenceable(1) %__a, %"struct.fp::Action"* %__p) #2 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  %3 = load %"class.std::allocator"** %1, align 8
  %4 = load %"struct.fp::Action"** %2, align 8
  call void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE10_S_destroyIS1_EENSt9enable_ifIXsr6__and_INS3_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS2_PS7_(%"class.std::allocator"* dereferenceable(1) %3, %"struct.fp::Action"* %4)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIN2fp6ActionEEEPT_PKS5_S8_S6_(%"struct.fp::Action"* %__first, %"struct.fp::Action"* %__last, %"struct.fp::Action"* %__result) #2 align 2 {
  %1 = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  %_Num = alloca i64, align 8
  store %"struct.fp::Action"* %__first, %"struct.fp::Action"** %1, align 8
  store %"struct.fp::Action"* %__last, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %3, align 8
  %4 = load %"struct.fp::Action"** %2, align 8
  %5 = load %"struct.fp::Action"** %1, align 8
  %6 = ptrtoint %"struct.fp::Action"* %4 to i64
  %7 = ptrtoint %"struct.fp::Action"* %5 to i64
  %8 = sub i64 %6, %7
  %9 = sdiv exact i64 %8, 24
  store i64 %9, i64* %_Num, align 8
  %10 = load i64* %_Num, align 8
  %11 = icmp ne i64 %10, 0
  br i1 %11, label %12, label %19

; <label>:12                                      ; preds = %0
  %13 = load %"struct.fp::Action"** %3, align 8
  %14 = bitcast %"struct.fp::Action"* %13 to i8*
  %15 = load %"struct.fp::Action"** %1, align 8
  %16 = bitcast %"struct.fp::Action"* %15 to i8*
  %17 = load i64* %_Num, align 8
  %18 = mul i64 24, %17
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %14, i8* %16, i64 %18, i32 8, i1 false)
  br label %19

; <label>:19                                      ; preds = %12, %0
  %20 = load %"struct.fp::Action"** %3, align 8
  %21 = load i64* %_Num, align 8
  %22 = getelementptr inbounds %"struct.fp::Action"* %20, i64 %21
  ret %"struct.fp::Action"* %22
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt13__copy_move_aILb1EPN2fp6ActionES2_ET1_T0_S4_S3_(%"struct.fp::Action"* %__first, %"struct.fp::Action"* %__last, %"struct.fp::Action"* %__result) #0 {
  %1 = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  %__simple = alloca i8, align 1
  store %"struct.fp::Action"* %__first, %"struct.fp::Action"** %1, align 8
  store %"struct.fp::Action"* %__last, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %3, align 8
  store i8 1, i8* %__simple, align 1
  %4 = load %"struct.fp::Action"** %1, align 8
  %5 = load %"struct.fp::Action"** %2, align 8
  %6 = load %"struct.fp::Action"** %3, align 8
  %7 = call %"struct.fp::Action"* @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIN2fp6ActionEEEPT_PKS5_S8_S6_(%"struct.fp::Action"* %4, %"struct.fp::Action"* %5, %"struct.fp::Action"* %6)
  ret %"struct.fp::Action"* %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt10_Iter_baseIPN2fp6ActionELb0EE7_S_baseES2_(%"struct.fp::Action"* %__it) #2 align 2 {
  %1 = alloca %"struct.fp::Action"*, align 8
  store %"struct.fp::Action"* %__it, %"struct.fp::Action"** %1, align 8
  %2 = load %"struct.fp::Action"** %1, align 8
  ret %"struct.fp::Action"* %2
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt12__niter_baseIPN2fp6ActionEENSt11_Niter_baseIT_E13iterator_typeES4_(%"struct.fp::Action"* %__it) #0 {
  %1 = alloca %"struct.fp::Action"*, align 8
  store %"struct.fp::Action"* %__it, %"struct.fp::Action"** %1, align 8
  %2 = load %"struct.fp::Action"** %1, align 8
  %3 = call %"struct.fp::Action"* @_ZNSt10_Iter_baseIPN2fp6ActionELb0EE7_S_baseES2_(%"struct.fp::Action"* %2)
  ret %"struct.fp::Action"* %3
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt14__copy_move_a2ILb1EPN2fp6ActionES2_ET1_T0_S4_S3_(%"struct.fp::Action"* %__first, %"struct.fp::Action"* %__last, %"struct.fp::Action"* %__result) #0 {
  %1 = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  store %"struct.fp::Action"* %__first, %"struct.fp::Action"** %1, align 8
  store %"struct.fp::Action"* %__last, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %3, align 8
  %4 = load %"struct.fp::Action"** %1, align 8
  %5 = call %"struct.fp::Action"* @_ZSt12__niter_baseIPN2fp6ActionEENSt11_Niter_baseIT_E13iterator_typeES4_(%"struct.fp::Action"* %4)
  %6 = load %"struct.fp::Action"** %2, align 8
  %7 = call %"struct.fp::Action"* @_ZSt12__niter_baseIPN2fp6ActionEENSt11_Niter_baseIT_E13iterator_typeES4_(%"struct.fp::Action"* %6)
  %8 = load %"struct.fp::Action"** %3, align 8
  %9 = call %"struct.fp::Action"* @_ZSt12__niter_baseIPN2fp6ActionEENSt11_Niter_baseIT_E13iterator_typeES4_(%"struct.fp::Action"* %8)
  %10 = call %"struct.fp::Action"* @_ZSt13__copy_move_aILb1EPN2fp6ActionES2_ET1_T0_S4_S3_(%"struct.fp::Action"* %5, %"struct.fp::Action"* %7, %"struct.fp::Action"* %9)
  ret %"struct.fp::Action"* %10
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNKSt13move_iteratorIPN2fp6ActionEE4baseEv(%"class.std::move_iterator"* %this) #2 align 2 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  store %"class.std::move_iterator"* %this, %"class.std::move_iterator"** %1, align 8
  %2 = load %"class.std::move_iterator"** %1
  %3 = getelementptr inbounds %"class.std::move_iterator"* %2, i32 0, i32 0
  %4 = load %"struct.fp::Action"** %3, align 8
  ret %"struct.fp::Action"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt10_Iter_baseISt13move_iteratorIPN2fp6ActionEELb1EE7_S_baseES4_(%"struct.fp::Action"* %__it.coerce) #2 align 2 {
  %__it = alloca %"class.std::move_iterator", align 8
  %1 = getelementptr %"class.std::move_iterator"* %__it, i32 0, i32 0
  store %"struct.fp::Action"* %__it.coerce, %"struct.fp::Action"** %1
  %2 = call %"struct.fp::Action"* @_ZNKSt13move_iteratorIPN2fp6ActionEE4baseEv(%"class.std::move_iterator"* %__it)
  ret %"struct.fp::Action"* %2
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt12__miter_baseISt13move_iteratorIPN2fp6ActionEEENSt11_Miter_baseIT_E13iterator_typeES6_(%"struct.fp::Action"* %__it.coerce) #0 {
  %__it = alloca %"class.std::move_iterator", align 8
  %1 = alloca %"class.std::move_iterator", align 8
  %2 = getelementptr %"class.std::move_iterator"* %__it, i32 0, i32 0
  store %"struct.fp::Action"* %__it.coerce, %"struct.fp::Action"** %2
  %3 = bitcast %"class.std::move_iterator"* %1 to i8*
  %4 = bitcast %"class.std::move_iterator"* %__it to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %3, i8* %4, i64 8, i32 8, i1 false)
  %5 = getelementptr %"class.std::move_iterator"* %1, i32 0, i32 0
  %6 = load %"struct.fp::Action"** %5
  %7 = call %"struct.fp::Action"* @_ZNSt10_Iter_baseISt13move_iteratorIPN2fp6ActionEELb1EE7_S_baseES4_(%"struct.fp::Action"* %6)
  ret %"struct.fp::Action"* %7
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt4copyISt13move_iteratorIPN2fp6ActionEES3_ET0_T_S6_S5_(%"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"* %__result) #0 {
  %__first = alloca %"class.std::move_iterator", align 8
  %__last = alloca %"class.std::move_iterator", align 8
  %1 = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"class.std::move_iterator", align 8
  %3 = alloca %"class.std::move_iterator", align 8
  %4 = getelementptr %"class.std::move_iterator"* %__first, i32 0, i32 0
  store %"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"** %4
  %5 = getelementptr %"class.std::move_iterator"* %__last, i32 0, i32 0
  store %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"** %5
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %1, align 8
  %6 = bitcast %"class.std::move_iterator"* %2 to i8*
  %7 = bitcast %"class.std::move_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 8, i32 8, i1 false)
  %8 = getelementptr %"class.std::move_iterator"* %2, i32 0, i32 0
  %9 = load %"struct.fp::Action"** %8
  %10 = call %"struct.fp::Action"* @_ZSt12__miter_baseISt13move_iteratorIPN2fp6ActionEEENSt11_Miter_baseIT_E13iterator_typeES6_(%"struct.fp::Action"* %9)
  %11 = bitcast %"class.std::move_iterator"* %3 to i8*
  %12 = bitcast %"class.std::move_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %11, i8* %12, i64 8, i32 8, i1 false)
  %13 = getelementptr %"class.std::move_iterator"* %3, i32 0, i32 0
  %14 = load %"struct.fp::Action"** %13
  %15 = call %"struct.fp::Action"* @_ZSt12__miter_baseISt13move_iteratorIPN2fp6ActionEEENSt11_Miter_baseIT_E13iterator_typeES6_(%"struct.fp::Action"* %14)
  %16 = load %"struct.fp::Action"** %1, align 8
  %17 = call %"struct.fp::Action"* @_ZSt14__copy_move_a2ILb1EPN2fp6ActionES2_ET1_T0_S4_S3_(%"struct.fp::Action"* %10, %"struct.fp::Action"* %15, %"struct.fp::Action"* %16)
  ret %"struct.fp::Action"* %17
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPN2fp6ActionEES5_EET0_T_S8_S7_(%"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"* %__result) #2 align 2 {
  %__first = alloca %"class.std::move_iterator", align 8
  %__last = alloca %"class.std::move_iterator", align 8
  %1 = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"class.std::move_iterator", align 8
  %3 = alloca %"class.std::move_iterator", align 8
  %4 = getelementptr %"class.std::move_iterator"* %__first, i32 0, i32 0
  store %"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"** %4
  %5 = getelementptr %"class.std::move_iterator"* %__last, i32 0, i32 0
  store %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"** %5
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %1, align 8
  %6 = bitcast %"class.std::move_iterator"* %2 to i8*
  %7 = bitcast %"class.std::move_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 8, i32 8, i1 false)
  %8 = bitcast %"class.std::move_iterator"* %3 to i8*
  %9 = bitcast %"class.std::move_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %8, i8* %9, i64 8, i32 8, i1 false)
  %10 = load %"struct.fp::Action"** %1, align 8
  %11 = getelementptr %"class.std::move_iterator"* %2, i32 0, i32 0
  %12 = load %"struct.fp::Action"** %11
  %13 = getelementptr %"class.std::move_iterator"* %3, i32 0, i32 0
  %14 = load %"struct.fp::Action"** %13
  %15 = call %"struct.fp::Action"* @_ZSt4copyISt13move_iteratorIPN2fp6ActionEES3_ET0_T_S6_S5_(%"struct.fp::Action"* %12, %"struct.fp::Action"* %14, %"struct.fp::Action"* %10)
  ret %"struct.fp::Action"* %15
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt18uninitialized_copyISt13move_iteratorIPN2fp6ActionEES3_ET0_T_S6_S5_(%"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"* %__result) #0 {
  %__first = alloca %"class.std::move_iterator", align 8
  %__last = alloca %"class.std::move_iterator", align 8
  %1 = alloca %"struct.fp::Action"*, align 8
  %__assignable = alloca i8, align 1
  %2 = alloca %"class.std::move_iterator", align 8
  %3 = alloca %"class.std::move_iterator", align 8
  %4 = getelementptr %"class.std::move_iterator"* %__first, i32 0, i32 0
  store %"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"** %4
  %5 = getelementptr %"class.std::move_iterator"* %__last, i32 0, i32 0
  store %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"** %5
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %1, align 8
  store i8 1, i8* %__assignable, align 1
  %6 = bitcast %"class.std::move_iterator"* %2 to i8*
  %7 = bitcast %"class.std::move_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 8, i32 8, i1 false)
  %8 = bitcast %"class.std::move_iterator"* %3 to i8*
  %9 = bitcast %"class.std::move_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %8, i8* %9, i64 8, i32 8, i1 false)
  %10 = load %"struct.fp::Action"** %1, align 8
  %11 = getelementptr %"class.std::move_iterator"* %2, i32 0, i32 0
  %12 = load %"struct.fp::Action"** %11
  %13 = getelementptr %"class.std::move_iterator"* %3, i32 0, i32 0
  %14 = load %"struct.fp::Action"** %13
  %15 = call %"struct.fp::Action"* @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPN2fp6ActionEES5_EET0_T_S8_S7_(%"struct.fp::Action"* %12, %"struct.fp::Action"* %14, %"struct.fp::Action"* %10)
  ret %"struct.fp::Action"* %15
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt22__uninitialized_copy_aISt13move_iteratorIPN2fp6ActionEES3_S2_ET0_T_S6_S5_RSaIT1_E(%"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"* %__result, %"class.std::allocator"* dereferenceable(1)) #0 {
  %__first = alloca %"class.std::move_iterator", align 8
  %__last = alloca %"class.std::move_iterator", align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"class.std::allocator"*, align 8
  %4 = alloca %"class.std::move_iterator", align 8
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = getelementptr %"class.std::move_iterator"* %__first, i32 0, i32 0
  store %"struct.fp::Action"* %__first.coerce, %"struct.fp::Action"** %6
  %7 = getelementptr %"class.std::move_iterator"* %__last, i32 0, i32 0
  store %"struct.fp::Action"* %__last.coerce, %"struct.fp::Action"** %7
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %2, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %3, align 8
  %8 = bitcast %"class.std::move_iterator"* %4 to i8*
  %9 = bitcast %"class.std::move_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %8, i8* %9, i64 8, i32 8, i1 false)
  %10 = bitcast %"class.std::move_iterator"* %5 to i8*
  %11 = bitcast %"class.std::move_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %10, i8* %11, i64 8, i32 8, i1 false)
  %12 = load %"struct.fp::Action"** %2, align 8
  %13 = getelementptr %"class.std::move_iterator"* %4, i32 0, i32 0
  %14 = load %"struct.fp::Action"** %13
  %15 = getelementptr %"class.std::move_iterator"* %5, i32 0, i32 0
  %16 = load %"struct.fp::Action"** %15
  %17 = call %"struct.fp::Action"* @_ZSt18uninitialized_copyISt13move_iteratorIPN2fp6ActionEES3_ET0_T_S6_S5_(%"struct.fp::Action"* %14, %"struct.fp::Action"* %16, %"struct.fp::Action"* %12)
  ret %"struct.fp::Action"* %17
}

; Function Attrs: inlinehint uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt32__make_move_if_noexcept_iteratorIPN2fp6ActionESt13move_iteratorIS2_EET0_T_(%"struct.fp::Action"* %__i) #4 {
  %1 = alloca %"class.std::move_iterator", align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"struct.fp::Action"* %__i, %"struct.fp::Action"** %2, align 8
  %3 = load %"struct.fp::Action"** %2, align 8
  call void @_ZNSt13move_iteratorIPN2fp6ActionEEC2ES2_(%"class.std::move_iterator"* %1, %"struct.fp::Action"* %3)
  %4 = getelementptr %"class.std::move_iterator"* %1, i32 0, i32 0
  %5 = load %"struct.fp::Action"** %4
  ret %"struct.fp::Action"* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt13move_iteratorIPN2fp6ActionEEC2ES2_(%"class.std::move_iterator"* %this, %"struct.fp::Action"* %__i) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"class.std::move_iterator"* %this, %"class.std::move_iterator"** %1, align 8
  store %"struct.fp::Action"* %__i, %"struct.fp::Action"** %2, align 8
  %3 = load %"class.std::move_iterator"** %1
  %4 = getelementptr inbounds %"class.std::move_iterator"* %3, i32 0, i32 0
  %5 = load %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %5, %"struct.fp::Action"** %4, align 8
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr %"struct.fp::Action"* @_ZSt34__uninitialized_move_if_noexcept_aIPN2fp6ActionES2_SaIS1_EET0_T_S5_S4_RT1_(%"struct.fp::Action"* %__first, %"struct.fp::Action"* %__last, %"struct.fp::Action"* %__result, %"class.std::allocator"* dereferenceable(1) %__alloc) #4 {
  %1 = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  %4 = alloca %"class.std::allocator"*, align 8
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = alloca %"class.std::move_iterator", align 8
  store %"struct.fp::Action"* %__first, %"struct.fp::Action"** %1, align 8
  store %"struct.fp::Action"* %__last, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__result, %"struct.fp::Action"** %3, align 8
  store %"class.std::allocator"* %__alloc, %"class.std::allocator"** %4, align 8
  %7 = load %"struct.fp::Action"** %1, align 8
  %8 = call %"struct.fp::Action"* @_ZSt32__make_move_if_noexcept_iteratorIPN2fp6ActionESt13move_iteratorIS2_EET0_T_(%"struct.fp::Action"* %7)
  %9 = getelementptr %"class.std::move_iterator"* %5, i32 0, i32 0
  store %"struct.fp::Action"* %8, %"struct.fp::Action"** %9
  %10 = load %"struct.fp::Action"** %2, align 8
  %11 = call %"struct.fp::Action"* @_ZSt32__make_move_if_noexcept_iteratorIPN2fp6ActionESt13move_iteratorIS2_EET0_T_(%"struct.fp::Action"* %10)
  %12 = getelementptr %"class.std::move_iterator"* %6, i32 0, i32 0
  store %"struct.fp::Action"* %11, %"struct.fp::Action"** %12
  %13 = load %"struct.fp::Action"** %3, align 8
  %14 = load %"class.std::allocator"** %4, align 8
  %15 = getelementptr %"class.std::move_iterator"* %5, i32 0, i32 0
  %16 = load %"struct.fp::Action"** %15
  %17 = getelementptr %"class.std::move_iterator"* %6, i32 0, i32 0
  %18 = load %"struct.fp::Action"** %17
  %19 = call %"struct.fp::Action"* @_ZSt22__uninitialized_copy_aISt13move_iteratorIPN2fp6ActionEES3_S2_ET0_T_S6_S5_RSaIT1_E(%"struct.fp::Action"* %16, %"struct.fp::Action"* %18, %"struct.fp::Action"* %13, %"class.std::allocator"* dereferenceable(1) %14)
  ret %"struct.fp::Action"* %19
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE4sizeEv(%"class.std::vector"* %this) #2 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %2 = load %"class.std::vector"** %1
  %3 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  %4 = getelementptr inbounds %"struct.std::_Vector_base"* %3, i32 0, i32 0
  %5 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %4, i32 0, i32 1
  %6 = load %"struct.fp::Action"** %5, align 8
  %7 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  %8 = getelementptr inbounds %"struct.std::_Vector_base"* %7, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %8, i32 0, i32 0
  %10 = load %"struct.fp::Action"** %9, align 8
  %11 = ptrtoint %"struct.fp::Action"* %6 to i64
  %12 = ptrtoint %"struct.fp::Action"* %10 to i64
  %13 = sub i64 %11, %12
  %14 = sdiv exact i64 %13, 24
  ret i64 %14
}

; Function Attrs: uwtable
define linkonce_odr %"struct.fp::Action"* @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE8allocateEmPKv(%"class.__gnu_cxx::new_allocator"* %this, i64 %__n, i8*) #7 align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %3 = alloca i64, align 8
  %4 = alloca i8*, align 8
  store %"class.__gnu_cxx::new_allocator"* %this, %"class.__gnu_cxx::new_allocator"** %2, align 8
  store i64 %__n, i64* %3, align 8
  store i8* %0, i8** %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator"** %2
  %6 = load i64* %3, align 8
  %7 = call i64 @_ZNK9__gnu_cxx13new_allocatorIN2fp6ActionEE8max_sizeEv(%"class.__gnu_cxx::new_allocator"* %5) #8
  %8 = icmp ugt i64 %6, %7
  br i1 %8, label %9, label %10

; <label>:9                                       ; preds = %1
  call void @_ZSt17__throw_bad_allocv() #17
  unreachable

; <label>:10                                      ; preds = %1
  %11 = load i64* %3, align 8
  %12 = mul i64 %11, 24
  %13 = call noalias i8* @_Znwm(i64 %12)
  %14 = bitcast i8* %13 to %"struct.fp::Action"*
  ret %"struct.fp::Action"* %14
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNK9__gnu_cxx13new_allocatorIN2fp6ActionEE8max_sizeEv(%"class.__gnu_cxx::new_allocator"* %this) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  store %"class.__gnu_cxx::new_allocator"* %this, %"class.__gnu_cxx::new_allocator"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator"** %1
  ret i64 768614336404564650
}

; Function Attrs: noreturn
declare void @_ZSt17__throw_bad_allocv() #6

; Function Attrs: nobuiltin
declare noalias i8* @_Znwm(i64) #16

; Function Attrs: uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt16allocator_traitsISaIN2fp6ActionEEE8allocateERS2_m(%"class.std::allocator"* dereferenceable(1) %__a, i64 %__n) #7 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  %2 = alloca i64, align 8
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %1, align 8
  store i64 %__n, i64* %2, align 8
  %3 = load %"class.std::allocator"** %1, align 8
  %4 = bitcast %"class.std::allocator"* %3 to %"class.__gnu_cxx::new_allocator"*
  %5 = load i64* %2, align 8
  %6 = call %"struct.fp::Action"* @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE8allocateEmPKv(%"class.__gnu_cxx::new_allocator"* %4, i64 %5, i8* null)
  ret %"struct.fp::Action"* %6
}

; Function Attrs: uwtable
define linkonce_odr %"struct.fp::Action"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base"* %this, i64 %__n) #7 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  store i64 %__n, i64* %2, align 8
  %3 = load %"struct.std::_Vector_base"** %1
  %4 = load i64* %2, align 8
  %5 = icmp ne i64 %4, 0
  br i1 %5, label %6, label %11

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %"struct.std::_Vector_base"* %3, i32 0, i32 0
  %8 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %7 to %"class.std::allocator"*
  %9 = load i64* %2, align 8
  %10 = call %"struct.fp::Action"* @_ZNSt16allocator_traitsISaIN2fp6ActionEEE8allocateERS2_m(%"class.std::allocator"* dereferenceable(1) %8, i64 %9)
  br label %12

; <label>:11                                      ; preds = %0
  br label %12

; <label>:12                                      ; preds = %11, %6
  %13 = phi %"struct.fp::Action"* [ %10, %6 ], [ null, %11 ]
  ret %"struct.fp::Action"* %13
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8) %__a, i64* dereferenceable(8) %__b) #2 {
  %1 = alloca i64*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i64*, align 8
  store i64* %__a, i64** %2, align 8
  store i64* %__b, i64** %3, align 8
  %4 = load i64** %2, align 8
  %5 = load i64* %4, align 8
  %6 = load i64** %3, align 8
  %7 = load i64* %6, align 8
  %8 = icmp ult i64 %5, %7
  br i1 %8, label %9, label %11

; <label>:9                                       ; preds = %0
  %10 = load i64** %3, align 8
  store i64* %10, i64** %1
  br label %13

; <label>:11                                      ; preds = %0
  %12 = load i64** %2, align 8
  store i64* %12, i64** %1
  br label %13

; <label>:13                                      ; preds = %11, %9
  %14 = load i64** %1
  ret i64* %14
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(1) %"class.std::allocator"* @_ZNKSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %this) #2 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  %2 = load %"struct.std::_Vector_base"** %1
  %3 = getelementptr inbounds %"struct.std::_Vector_base"* %2, i32 0, i32 0
  %4 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %3 to %"class.std::allocator"*
  ret %"class.std::allocator"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt16allocator_traitsISaIN2fp6ActionEEE11_S_max_sizeIKS2_vEEmRT_i(%"class.std::allocator"* dereferenceable(1) %__a, i32) #2 align 2 {
  %2 = alloca %"class.std::allocator"*, align 8
  %3 = alloca i32, align 4
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %2, align 8
  store i32 %0, i32* %3, align 4
  %4 = load %"class.std::allocator"** %2, align 8
  %5 = bitcast %"class.std::allocator"* %4 to %"class.__gnu_cxx::new_allocator"*
  %6 = call i64 @_ZNK9__gnu_cxx13new_allocatorIN2fp6ActionEE8max_sizeEv(%"class.__gnu_cxx::new_allocator"* %5) #8
  ret i64 %6
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt16allocator_traitsISaIN2fp6ActionEEE8max_sizeERKS2_(%"class.std::allocator"* dereferenceable(1) %__a) #2 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %1, align 8
  %2 = load %"class.std::allocator"** %1, align 8
  %3 = invoke i64 @_ZNSt16allocator_traitsISaIN2fp6ActionEEE11_S_max_sizeIKS2_vEEmRT_i(%"class.std::allocator"* dereferenceable(1) %2, i32 0)
          to label %4 unwind label %5

; <label>:4                                       ; preds = %0
  ret i64 %3

; <label>:5                                       ; preds = %0
  %6 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %7 = extractvalue { i8*, i32 } %6, 0
  call void @__clang_call_terminate(i8* %7) #18
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE8max_sizeEv(%"class.std::vector"* %this) #2 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %2 = load %"class.std::vector"** %1
  %3 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  %4 = call dereferenceable(1) %"class.std::allocator"* @_ZNKSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %3) #8
  %5 = call i64 @_ZNSt16allocator_traitsISaIN2fp6ActionEEE8max_sizeERKS2_(%"class.std::allocator"* dereferenceable(1) %4) #8
  ret i64 %5
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE12_M_check_lenEmPKc(%"class.std::vector"* %this, i64 %__n, i8* %__s) #7 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i8*, align 8
  %__len = alloca i64, align 8
  %4 = alloca i64, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i8* %__s, i8** %3, align 8
  %5 = load %"class.std::vector"** %1
  %6 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE8max_sizeEv(%"class.std::vector"* %5) #8
  %7 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE4sizeEv(%"class.std::vector"* %5) #8
  %8 = sub i64 %6, %7
  %9 = load i64* %2, align 8
  %10 = icmp ult i64 %8, %9
  br i1 %10, label %11, label %13

; <label>:11                                      ; preds = %0
  %12 = load i8** %3, align 8
  call void @_ZSt20__throw_length_errorPKc(i8* %12) #17
  unreachable

; <label>:13                                      ; preds = %0
  %14 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE4sizeEv(%"class.std::vector"* %5) #8
  %15 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE4sizeEv(%"class.std::vector"* %5) #8
  store i64 %15, i64* %4
  %16 = call dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8) %4, i64* dereferenceable(8) %2)
  %17 = load i64* %16
  %18 = add i64 %14, %17
  store i64 %18, i64* %__len, align 8
  %19 = load i64* %__len, align 8
  %20 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE4sizeEv(%"class.std::vector"* %5) #8
  %21 = icmp ult i64 %19, %20
  br i1 %21, label %26, label %22

; <label>:22                                      ; preds = %13
  %23 = load i64* %__len, align 8
  %24 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE8max_sizeEv(%"class.std::vector"* %5) #8
  %25 = icmp ugt i64 %23, %24
  br i1 %25, label %26, label %28

; <label>:26                                      ; preds = %22, %13
  %27 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE8max_sizeEv(%"class.std::vector"* %5) #8
  br label %30

; <label>:28                                      ; preds = %22
  %29 = load i64* %__len, align 8
  br label %30

; <label>:30                                      ; preds = %28, %26
  %31 = phi i64 [ %27, %26 ], [ %29, %28 ]
  ret i64 %31
}

; Function Attrs: noreturn
declare void @_ZSt20__throw_length_errorPKc(i8*) #6

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt6vectorIN2fp6ActionESaIS1_EE19_M_emplace_back_auxIJRKS1_EEEvDpOT_(%"class.std::vector"* %this, %"struct.fp::Action"* dereferenceable(24) %__args) #7 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %__len = alloca i64, align 8
  %__new_start = alloca %"struct.fp::Action"*, align 8
  %__new_finish = alloca %"struct.fp::Action"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store %"struct.fp::Action"* %__args, %"struct.fp::Action"** %2, align 8
  %5 = load %"class.std::vector"** %1
  %6 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE12_M_check_lenEmPKc(%"class.std::vector"* %5, i64 1, i8* getelementptr inbounds ([28 x i8]* @.str30, i32 0, i32 0))
  store i64 %6, i64* %__len, align 8
  %7 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %8 = load i64* %__len, align 8
  %9 = call %"struct.fp::Action"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base"* %7, i64 %8)
  store %"struct.fp::Action"* %9, %"struct.fp::Action"** %__new_start, align 8
  %10 = load %"struct.fp::Action"** %__new_start, align 8
  store %"struct.fp::Action"* %10, %"struct.fp::Action"** %__new_finish, align 8
  %11 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %12 = getelementptr inbounds %"struct.std::_Vector_base"* %11, i32 0, i32 0
  %13 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %12 to %"class.std::allocator"*
  %14 = load %"struct.fp::Action"** %__new_start, align 8
  %15 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE4sizeEv(%"class.std::vector"* %5) #8
  %16 = getelementptr inbounds %"struct.fp::Action"* %14, i64 %15
  %17 = load %"struct.fp::Action"** %2, align 8
  %18 = call dereferenceable(24) %"struct.fp::Action"* @_ZSt7forwardIRKN2fp6ActionEEOT_RNSt16remove_referenceIS4_E4typeE(%"struct.fp::Action"* dereferenceable(24) %17) #8
  invoke void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE9constructIS1_JRKS1_EEEDTcl12_S_constructfp_fp0_spclsr3stdE7forwardIT0_Efp1_EEERS2_PT_DpOS7_(%"class.std::allocator"* dereferenceable(1) %13, %"struct.fp::Action"* %16, %"struct.fp::Action"* dereferenceable(24) %18)
          to label %19 unwind label %35

; <label>:19                                      ; preds = %0
  store %"struct.fp::Action"* null, %"struct.fp::Action"** %__new_finish, align 8
  %20 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %21 = getelementptr inbounds %"struct.std::_Vector_base"* %20, i32 0, i32 0
  %22 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %21, i32 0, i32 0
  %23 = load %"struct.fp::Action"** %22, align 8
  %24 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %25 = getelementptr inbounds %"struct.std::_Vector_base"* %24, i32 0, i32 0
  %26 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %25, i32 0, i32 1
  %27 = load %"struct.fp::Action"** %26, align 8
  %28 = load %"struct.fp::Action"** %__new_start, align 8
  %29 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %30 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %29) #8
  %31 = invoke %"struct.fp::Action"* @_ZSt34__uninitialized_move_if_noexcept_aIPN2fp6ActionES2_SaIS1_EET0_T_S5_S4_RT1_(%"struct.fp::Action"* %23, %"struct.fp::Action"* %27, %"struct.fp::Action"* %28, %"class.std::allocator"* dereferenceable(1) %30)
          to label %32 unwind label %35

; <label>:32                                      ; preds = %19
  store %"struct.fp::Action"* %31, %"struct.fp::Action"** %__new_finish, align 8
  %33 = load %"struct.fp::Action"** %__new_finish, align 8
  %34 = getelementptr inbounds %"struct.fp::Action"* %33, i32 1
  store %"struct.fp::Action"* %34, %"struct.fp::Action"** %__new_finish, align 8
  br label %68

; <label>:35                                      ; preds = %19, %0
  %36 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %37 = extractvalue { i8*, i32 } %36, 0
  store i8* %37, i8** %3
  %38 = extractvalue { i8*, i32 } %36, 1
  store i32 %38, i32* %4
  br label %39

; <label>:39                                      ; preds = %35
  %40 = load i8** %3
  %41 = call i8* @__cxa_begin_catch(i8* %40) #8
  %42 = load %"struct.fp::Action"** %__new_finish, align 8
  %43 = icmp ne %"struct.fp::Action"* %42, null
  br i1 %43, label %56, label %44

; <label>:44                                      ; preds = %39
  %45 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %46 = getelementptr inbounds %"struct.std::_Vector_base"* %45, i32 0, i32 0
  %47 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %46 to %"class.std::allocator"*
  %48 = load %"struct.fp::Action"** %__new_start, align 8
  %49 = call i64 @_ZNKSt6vectorIN2fp6ActionESaIS1_EE4sizeEv(%"class.std::vector"* %5) #8
  %50 = getelementptr inbounds %"struct.fp::Action"* %48, i64 %49
  invoke void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator"* dereferenceable(1) %47, %"struct.fp::Action"* %50)
          to label %51 unwind label %52

; <label>:51                                      ; preds = %44
  br label %62

; <label>:52                                      ; preds = %66, %62, %56, %44
  %53 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %54 = extractvalue { i8*, i32 } %53, 0
  store i8* %54, i8** %3
  %55 = extractvalue { i8*, i32 } %53, 1
  store i32 %55, i32* %4
  invoke void @__cxa_end_catch()
          to label %67 unwind label %115

; <label>:56                                      ; preds = %39
  %57 = load %"struct.fp::Action"** %__new_start, align 8
  %58 = load %"struct.fp::Action"** %__new_finish, align 8
  %59 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %60 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %59) #8
  invoke void @_ZSt8_DestroyIPN2fp6ActionES1_EvT_S3_RSaIT0_E(%"struct.fp::Action"* %57, %"struct.fp::Action"* %58, %"class.std::allocator"* dereferenceable(1) %60)
          to label %61 unwind label %52

; <label>:61                                      ; preds = %56
  br label %62

; <label>:62                                      ; preds = %61, %51
  %63 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %64 = load %"struct.fp::Action"** %__new_start, align 8
  %65 = load i64* %__len, align 8
  invoke void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"* %63, %"struct.fp::Action"* %64, i64 %65)
          to label %66 unwind label %52

; <label>:66                                      ; preds = %62
  invoke void @__cxa_rethrow() #17
          to label %118 unwind label %52

; <label>:67                                      ; preds = %52
  br label %110

; <label>:68                                      ; preds = %32
  %69 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %70 = getelementptr inbounds %"struct.std::_Vector_base"* %69, i32 0, i32 0
  %71 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %70, i32 0, i32 0
  %72 = load %"struct.fp::Action"** %71, align 8
  %73 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %74 = getelementptr inbounds %"struct.std::_Vector_base"* %73, i32 0, i32 0
  %75 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %74, i32 0, i32 1
  %76 = load %"struct.fp::Action"** %75, align 8
  %77 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %78 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %77) #8
  call void @_ZSt8_DestroyIPN2fp6ActionES1_EvT_S3_RSaIT0_E(%"struct.fp::Action"* %72, %"struct.fp::Action"* %76, %"class.std::allocator"* dereferenceable(1) %78)
  %79 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %80 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %81 = getelementptr inbounds %"struct.std::_Vector_base"* %80, i32 0, i32 0
  %82 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %81, i32 0, i32 0
  %83 = load %"struct.fp::Action"** %82, align 8
  %84 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %85 = getelementptr inbounds %"struct.std::_Vector_base"* %84, i32 0, i32 0
  %86 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %85, i32 0, i32 2
  %87 = load %"struct.fp::Action"** %86, align 8
  %88 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %89 = getelementptr inbounds %"struct.std::_Vector_base"* %88, i32 0, i32 0
  %90 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %89, i32 0, i32 0
  %91 = load %"struct.fp::Action"** %90, align 8
  %92 = ptrtoint %"struct.fp::Action"* %87 to i64
  %93 = ptrtoint %"struct.fp::Action"* %91 to i64
  %94 = sub i64 %92, %93
  %95 = sdiv exact i64 %94, 24
  call void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"* %79, %"struct.fp::Action"* %83, i64 %95)
  %96 = load %"struct.fp::Action"** %__new_start, align 8
  %97 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %98 = getelementptr inbounds %"struct.std::_Vector_base"* %97, i32 0, i32 0
  %99 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %98, i32 0, i32 0
  store %"struct.fp::Action"* %96, %"struct.fp::Action"** %99, align 8
  %100 = load %"struct.fp::Action"** %__new_finish, align 8
  %101 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %102 = getelementptr inbounds %"struct.std::_Vector_base"* %101, i32 0, i32 0
  %103 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %102, i32 0, i32 1
  store %"struct.fp::Action"* %100, %"struct.fp::Action"** %103, align 8
  %104 = load %"struct.fp::Action"** %__new_start, align 8
  %105 = load i64* %__len, align 8
  %106 = getelementptr inbounds %"struct.fp::Action"* %104, i64 %105
  %107 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %108 = getelementptr inbounds %"struct.std::_Vector_base"* %107, i32 0, i32 0
  %109 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %108, i32 0, i32 2
  store %"struct.fp::Action"* %106, %"struct.fp::Action"** %109, align 8
  ret void

; <label>:110                                     ; preds = %67
  %111 = load i8** %3
  %112 = load i32* %4
  %113 = insertvalue { i8*, i32 } undef, i8* %111, 0
  %114 = insertvalue { i8*, i32 } %113, i32 %112, 1
  resume { i8*, i32 } %114

; <label>:115                                     ; preds = %52
  %116 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %117 = extractvalue { i8*, i32 } %116, 0
  call void @__clang_call_terminate(i8* %117) #18
  unreachable

; <label>:118                                     ; preds = %66
  unreachable
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE9constructIS1_JRKS1_EEEDTcl12_S_constructfp_fp0_spclsr3stdE7forwardIT0_Efp1_EEERS2_PT_DpOS7_(%"class.std::allocator"* dereferenceable(1) %__a, %"struct.fp::Action"* %__p, %"struct.fp::Action"* dereferenceable(24) %__args) #7 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__args, %"struct.fp::Action"** %3, align 8
  %4 = load %"class.std::allocator"** %1, align 8
  %5 = load %"struct.fp::Action"** %2, align 8
  %6 = load %"struct.fp::Action"** %3, align 8
  %7 = call dereferenceable(24) %"struct.fp::Action"* @_ZSt7forwardIRKN2fp6ActionEEOT_RNSt16remove_referenceIS4_E4typeE(%"struct.fp::Action"* dereferenceable(24) %6) #8
  call void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE12_S_constructIS1_JRKS1_EEENSt9enable_ifIXsr6__and_INS3_18__construct_helperIT_JDpT0_EE4typeEEE5valueEvE4typeERS2_PS9_DpOSA_(%"class.std::allocator"* dereferenceable(1) %4, %"struct.fp::Action"* %5, %"struct.fp::Action"* dereferenceable(24) %7)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(24) %"struct.fp::Action"* @_ZSt7forwardIRKN2fp6ActionEEOT_RNSt16remove_referenceIS4_E4typeE(%"struct.fp::Action"* dereferenceable(24) %__t) #2 {
  %1 = alloca %"struct.fp::Action"*, align 8
  store %"struct.fp::Action"* %__t, %"struct.fp::Action"** %1, align 8
  %2 = load %"struct.fp::Action"** %1, align 8
  ret %"struct.fp::Action"* %2
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"* %this, %"struct.fp::Action"* %__p, i64 %__n) #7 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca i64, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load %"struct.std::_Vector_base"** %1
  %5 = load %"struct.fp::Action"** %2, align 8
  %6 = icmp ne %"struct.fp::Action"* %5, null
  br i1 %6, label %7, label %12

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %9 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %8 to %"class.std::allocator"*
  %10 = load %"struct.fp::Action"** %2, align 8
  %11 = load i64* %3, align 8
  call void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE10deallocateERS2_PS1_m(%"class.std::allocator"* dereferenceable(1) %9, %"struct.fp::Action"* %10, i64 %11)
  br label %12

; <label>:12                                      ; preds = %7, %0
  ret void
}

declare void @__cxa_rethrow()

declare void @__cxa_end_catch()

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE10deallocateERS2_PS1_m(%"class.std::allocator"* dereferenceable(1) %__a, %"struct.fp::Action"* %__p, i64 %__n) #7 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca i64, align 8
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load %"class.std::allocator"** %1, align 8
  %5 = bitcast %"class.std::allocator"* %4 to %"class.__gnu_cxx::new_allocator"*
  %6 = load %"struct.fp::Action"** %2, align 8
  %7 = load i64* %3, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator"* %5, %"struct.fp::Action"* %6, i64 %7)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator"* %this, %"struct.fp::Action"* %__p, i64) #2 align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  %4 = alloca i64, align 8
  store %"class.__gnu_cxx::new_allocator"* %this, %"class.__gnu_cxx::new_allocator"** %2, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %3, align 8
  store i64 %0, i64* %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator"** %2
  %6 = load %"struct.fp::Action"** %3, align 8
  %7 = bitcast %"struct.fp::Action"* %6 to i8*
  call void @_ZdlPv(i8* %7) #8
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaIN2fp6ActionEEE12_S_constructIS1_JRKS1_EEENSt9enable_ifIXsr6__and_INS3_18__construct_helperIT_JDpT0_EE4typeEEE5valueEvE4typeERS2_PS9_DpOSA_(%"class.std::allocator"* dereferenceable(1) %__a, %"struct.fp::Action"* %__p, %"struct.fp::Action"* dereferenceable(24) %__args) #7 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  store %"class.std::allocator"* %__a, %"class.std::allocator"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__args, %"struct.fp::Action"** %3, align 8
  %4 = load %"class.std::allocator"** %1, align 8
  %5 = bitcast %"class.std::allocator"* %4 to %"class.__gnu_cxx::new_allocator"*
  %6 = load %"struct.fp::Action"** %2, align 8
  %7 = load %"struct.fp::Action"** %3, align 8
  %8 = call dereferenceable(24) %"struct.fp::Action"* @_ZSt7forwardIRKN2fp6ActionEEOT_RNSt16remove_referenceIS4_E4typeE(%"struct.fp::Action"* dereferenceable(24) %7) #8
  call void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator"* %5, %"struct.fp::Action"* %6, %"struct.fp::Action"* dereferenceable(24) %8)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator"* %this, %"struct.fp::Action"* %__p, %"struct.fp::Action"* dereferenceable(24) %__args) #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  %3 = alloca %"struct.fp::Action"*, align 8
  store %"class.__gnu_cxx::new_allocator"* %this, %"class.__gnu_cxx::new_allocator"** %1, align 8
  store %"struct.fp::Action"* %__p, %"struct.fp::Action"** %2, align 8
  store %"struct.fp::Action"* %__args, %"struct.fp::Action"** %3, align 8
  %4 = load %"class.__gnu_cxx::new_allocator"** %1
  %5 = load %"struct.fp::Action"** %2, align 8
  %6 = bitcast %"struct.fp::Action"* %5 to i8*
  %7 = icmp eq i8* %6, null
  br i1 %7, label %14, label %8

; <label>:8                                       ; preds = %0
  %9 = bitcast i8* %6 to %"struct.fp::Action"*
  %10 = load %"struct.fp::Action"** %3, align 8
  %11 = call dereferenceable(24) %"struct.fp::Action"* @_ZSt7forwardIRKN2fp6ActionEEOT_RNSt16remove_referenceIS4_E4typeE(%"struct.fp::Action"* dereferenceable(24) %10) #8
  %12 = bitcast %"struct.fp::Action"* %9 to i8*
  %13 = bitcast %"struct.fp::Action"* %11 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %12, i8* %13, i64 24, i32 8, i1 false)
  br label %14

; <label>:14                                      ; preds = %8, %0
  %15 = phi %"struct.fp::Action"* [ %9, %8 ], [ null, %0 ]
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEED2Ev(%"class.__gnu_cxx::new_allocator"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  store %"class.__gnu_cxx::new_allocator"* %this, %"class.__gnu_cxx::new_allocator"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator"** %1
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSaIN2fp6ActionEED2Ev(%"class.std::allocator"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::allocator"*, align 8
  store %"class.std::allocator"* %this, %"class.std::allocator"** %1, align 8
  %2 = load %"class.std::allocator"** %1
  %3 = bitcast %"class.std::allocator"* %2 to %"class.__gnu_cxx::new_allocator"*
  call void @_ZN9__gnu_cxx13new_allocatorIN2fp6ActionEED2Ev(%"class.__gnu_cxx::new_allocator"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EED2Ev(%"struct.std::_Vector_base"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  %4 = load %"struct.std::_Vector_base"** %1
  %5 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %5, i32 0, i32 0
  %7 = load %"struct.fp::Action"** %6, align 8
  %8 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %8, i32 0, i32 2
  %10 = load %"struct.fp::Action"** %9, align 8
  %11 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %12 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %11, i32 0, i32 0
  %13 = load %"struct.fp::Action"** %12, align 8
  %14 = ptrtoint %"struct.fp::Action"* %10 to i64
  %15 = ptrtoint %"struct.fp::Action"* %13 to i64
  %16 = sub i64 %14, %15
  %17 = sdiv exact i64 %16, 24
  invoke void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"* %4, %"struct.fp::Action"* %7, i64 %17)
          to label %18 unwind label %20

; <label>:18                                      ; preds = %0
  %19 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %19) #8
  ret void

; <label>:20                                      ; preds = %0
  %21 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %22 = extractvalue { i8*, i32 } %21, 0
  store i8* %22, i8** %2
  %23 = extractvalue { i8*, i32 } %21, 1
  store i32 %23, i32* %3
  %24 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %24) #8
  br label %25

; <label>:25                                      ; preds = %20
  %26 = load i8** %2
  call void @__clang_call_terminate(i8* %26) #18
  unreachable
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %this) unnamed_addr #0 align 2 {
  %1 = alloca %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %this, %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"** %1, align 8
  %2 = load %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"** %1
  %3 = bitcast %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %2 to %"class.std::allocator"*
  call void @_ZNSaIN2fp6ActionEED2Ev(%"class.std::allocator"* %3) #8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12_Destroy_auxILb1EE9__destroyIPN2fp6ActionEEEvT_S5_(%"struct.fp::Action"*, %"struct.fp::Action"*) #2 align 2 {
  %3 = alloca %"struct.fp::Action"*, align 8
  %4 = alloca %"struct.fp::Action"*, align 8
  store %"struct.fp::Action"* %0, %"struct.fp::Action"** %3, align 8
  store %"struct.fp::Action"* %1, %"struct.fp::Action"** %4, align 8
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt8_DestroyIPN2fp6ActionEEvT_S3_(%"struct.fp::Action"* %__first, %"struct.fp::Action"* %__last) #0 {
  %1 = alloca %"struct.fp::Action"*, align 8
  %2 = alloca %"struct.fp::Action"*, align 8
  store %"struct.fp::Action"* %__first, %"struct.fp::Action"** %1, align 8
  store %"struct.fp::Action"* %__last, %"struct.fp::Action"** %2, align 8
  %3 = load %"struct.fp::Action"** %1, align 8
  %4 = load %"struct.fp::Action"** %2, align 8
  call void @_ZNSt12_Destroy_auxILb1EE9__destroyIPN2fp6ActionEEEvT_S5_(%"struct.fp::Action"* %3, %"struct.fp::Action"* %4)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6vectorIN2fp6ActionESaIS1_EED2Ev(%"class.std::vector"* %this) unnamed_addr #2 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %4 = load %"class.std::vector"** %1
  %5 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %6, i32 0, i32 0
  %8 = load %"struct.fp::Action"** %7, align 8
  %9 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %10 = getelementptr inbounds %"struct.std::_Vector_base"* %9, i32 0, i32 0
  %11 = getelementptr inbounds %"struct.std::_Vector_base<fp::Action, std::allocator<fp::Action> >::_Vector_impl"* %10, i32 0, i32 1
  %12 = load %"struct.fp::Action"** %11, align 8
  %13 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %14 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %13) #8
  invoke void @_ZSt8_DestroyIPN2fp6ActionES1_EvT_S3_RSaIT0_E(%"struct.fp::Action"* %8, %"struct.fp::Action"* %12, %"class.std::allocator"* dereferenceable(1) %14)
          to label %15 unwind label %17

; <label>:15                                      ; preds = %0
  %16 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  call void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EED2Ev(%"struct.std::_Vector_base"* %16) #8
  ret void

; <label>:17                                      ; preds = %0
  %18 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %19 = extractvalue { i8*, i32 } %18, 0
  store i8* %19, i8** %2
  %20 = extractvalue { i8*, i32 } %18, 1
  store i32 %20, i32* %3
  %21 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  call void @_ZNSt12_Vector_baseIN2fp6ActionESaIS1_EED2Ev(%"struct.std::_Vector_base"* %21) #8
  br label %22

; <label>:22                                      ; preds = %17
  %23 = load i8** %2
  call void @__clang_call_terminate(i8* %23) #18
  unreachable
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt8__fill_aIPmiEN9__gnu_cxx11__enable_ifIXsr11__is_scalarIT0_EE7__valueEvE6__typeET_S6_RKS3_(i64* %__first, i64* %__last, i32* dereferenceable(4) %__value) #0 {
  %1 = alloca i64*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i32*, align 8
  %__tmp = alloca i32, align 4
  store i64* %__first, i64** %1, align 8
  store i64* %__last, i64** %2, align 8
  store i32* %__value, i32** %3, align 8
  %4 = load i32** %3, align 8
  %5 = load i32* %4, align 4
  store i32 %5, i32* %__tmp, align 4
  br label %6

; <label>:6                                       ; preds = %14, %0
  %7 = load i64** %1, align 8
  %8 = load i64** %2, align 8
  %9 = icmp ne i64* %7, %8
  br i1 %9, label %10, label %17

; <label>:10                                      ; preds = %6
  %11 = load i32* %__tmp, align 4
  %12 = sext i32 %11 to i64
  %13 = load i64** %1, align 8
  store i64 %12, i64* %13, align 8
  br label %14

; <label>:14                                      ; preds = %10
  %15 = load i64** %1, align 8
  %16 = getelementptr inbounds i64* %15, i32 1
  store i64* %16, i64** %1, align 8
  br label %6

; <label>:17                                      ; preds = %6
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64* @_ZNSt10_Iter_baseIPmLb0EE7_S_baseES0_(i64* %__it) #2 align 2 {
  %1 = alloca i64*, align 8
  store i64* %__it, i64** %1, align 8
  %2 = load i64** %1, align 8
  ret i64* %2
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr i64* @_ZSt12__niter_baseIPmENSt11_Niter_baseIT_E13iterator_typeES2_(i64* %__it) #0 {
  %1 = alloca i64*, align 8
  store i64* %__it, i64** %1, align 8
  %2 = load i64** %1, align 8
  %3 = call i64* @_ZNSt10_Iter_baseIPmLb0EE7_S_baseES0_(i64* %2)
  ret i64* %3
}

; Function Attrs: nounwind uwtable
define linkonce_odr zeroext i1 @_ZSteqRKNSt22bernoulli_distribution10param_typeES2_(%"struct.std::bernoulli_distribution::param_type"* dereferenceable(8) %__p1, %"struct.std::bernoulli_distribution::param_type"* dereferenceable(8) %__p2) #2 {
  %1 = alloca %"struct.std::bernoulli_distribution::param_type"*, align 8
  %2 = alloca %"struct.std::bernoulli_distribution::param_type"*, align 8
  store %"struct.std::bernoulli_distribution::param_type"* %__p1, %"struct.std::bernoulli_distribution::param_type"** %1, align 8
  store %"struct.std::bernoulli_distribution::param_type"* %__p2, %"struct.std::bernoulli_distribution::param_type"** %2, align 8
  %3 = load %"struct.std::bernoulli_distribution::param_type"** %1, align 8
  %4 = getelementptr inbounds %"struct.std::bernoulli_distribution::param_type"* %3, i32 0, i32 0
  %5 = load double* %4, align 8
  %6 = load %"struct.std::bernoulli_distribution::param_type"** %2, align 8
  %7 = getelementptr inbounds %"struct.std::bernoulli_distribution::param_type"* %6, i32 0, i32 0
  %8 = load double* %7, align 8
  %9 = fcmp oeq double %5, %8
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define linkonce_odr double* @_ZNKSt16initializer_listIdE3endEv(%"class.std::initializer_list"* %this) #2 align 2 {
  %1 = alloca %"class.std::initializer_list"*, align 8
  store %"class.std::initializer_list"* %this, %"class.std::initializer_list"** %1, align 8
  %2 = load %"class.std::initializer_list"** %1
  %3 = call double* @_ZNKSt16initializer_listIdE5beginEv(%"class.std::initializer_list"* %2) #8
  %4 = call i64 @_ZNKSt16initializer_listIdE4sizeEv(%"class.std::initializer_list"* %2) #8
  %5 = getelementptr inbounds double* %3, i64 %4
  ret double* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr double* @_ZNKSt16initializer_listIdE5beginEv(%"class.std::initializer_list"* %this) #2 align 2 {
  %1 = alloca %"class.std::initializer_list"*, align 8
  store %"class.std::initializer_list"* %this, %"class.std::initializer_list"** %1, align 8
  %2 = load %"class.std::initializer_list"** %1
  %3 = getelementptr inbounds %"class.std::initializer_list"* %2, i32 0, i32 0
  %4 = load double** %3, align 8
  ret double* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt16initializer_listIdE4sizeEv(%"class.std::initializer_list"* %this) #2 align 2 {
  %1 = alloca %"class.std::initializer_list"*, align 8
  store %"class.std::initializer_list"* %this, %"class.std::initializer_list"** %1, align 8
  %2 = load %"class.std::initializer_list"** %1
  %3 = getelementptr inbounds %"class.std::initializer_list"* %2, i32 0, i32 1
  %4 = load i64* %3, align 8
  ret i64 %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNKSt16initializer_listIbE3endEv(%"class.std::initializer_list.64"* %this) #2 align 2 {
  %1 = alloca %"class.std::initializer_list.64"*, align 8
  store %"class.std::initializer_list.64"* %this, %"class.std::initializer_list.64"** %1, align 8
  %2 = load %"class.std::initializer_list.64"** %1
  %3 = call i8* @_ZNKSt16initializer_listIbE5beginEv(%"class.std::initializer_list.64"* %2) #8
  %4 = call i64 @_ZNKSt16initializer_listIbE4sizeEv(%"class.std::initializer_list.64"* %2) #8
  %5 = getelementptr inbounds i8* %3, i64 %4
  ret i8* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr i8* @_ZNKSt16initializer_listIbE5beginEv(%"class.std::initializer_list.64"* %this) #2 align 2 {
  %1 = alloca %"class.std::initializer_list.64"*, align 8
  store %"class.std::initializer_list.64"* %this, %"class.std::initializer_list.64"** %1, align 8
  %2 = load %"class.std::initializer_list.64"** %1
  %3 = getelementptr inbounds %"class.std::initializer_list.64"* %2, i32 0, i32 0
  %4 = load i8** %3, align 8
  ret i8* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt16initializer_listIbE4sizeEv(%"class.std::initializer_list.64"* %this) #2 align 2 {
  %1 = alloca %"class.std::initializer_list.64"*, align 8
  store %"class.std::initializer_list.64"* %this, %"class.std::initializer_list.64"** %1, align 8
  %2 = load %"class.std::initializer_list.64"** %1
  %3 = getelementptr inbounds %"class.std::initializer_list.64"* %2, i32 0, i32 1
  %4 = load i64* %3, align 8
  ret i64 %4
}

define internal void @_GLOBAL__sub_I_libsteve.cpp() section ".text.startup" {
  call void @__cxx_global_var_init()
  ret void
}

attributes #0 = { inlinehint nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }
attributes #2 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { inlinehint uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { noreturn uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { nounwind }
attributes #9 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #10 = { noinline noreturn nounwind }
attributes #11 = { noreturn nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #12 = { nounwind readnone "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #13 = { nounwind readonly "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #14 = { alwaysinline inlinehint nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #15 = { nobuiltin nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #16 = { nobuiltin "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #17 = { noreturn }
attributes #18 = { noreturn nounwind }
attributes #19 = { readnone }
attributes #20 = { nounwind readonly }
attributes #21 = { builtin nounwind }

!llvm.ident = !{!0}

!0 = !{!"Ubuntu clang version 3.6.0-2ubuntu1~trusty1 (tags/RELEASE_360/final) (based on LLVM 3.6.0)"}
