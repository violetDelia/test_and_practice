#pragma once
#ifndef CSTDINT_HPP
#define CSTDINT_HPP
#include "my_STL/my_help.hpp"
MY_STL_namespace_begin

    /*分别为宽度恰为 8、16、32 和 64 位的有符号整数类型*/
    using int8_t = signed char;
using int16_t = short;
using int32_t = int;
using int64_t = long long;

/*宽度至少有 8、16、32 和 64 位的最快的有符号整数类型*/
using int_fast8_t = signed char;
using int_fast16_t = int;
using int_fast32_t = int;
using int_fast64_t = long long;

/*分别为宽度至少有 8、16、32 和 64 位的最小的有符号整数类型*/
using int_least8_t = signed char;
using int_least16_t = short;
using int_least32_t = int;
using int_least64_t = long long;

/*最大宽度的有符号整数类型*/
using intmax_t = long long;

/*足以保有指针的有符号整数类型*/
#ifdef MY_SYSTEM_64_WIN
using intptr_t = long;
#endif //MY_SYSTEM_64_WIN

/*宽度恰为 8、16、32 和 64 位的无符号整数类型*/
using uint8_t = unsigned char;
using uint16_t = unsigned short;
using uint32_t = unsigned int;
using uint64_t = unsigned long long;

/*分别为宽度至少有 8、16、32 和 64 位的最快无符号整数类型*/
using uint_fast8_t = unsigned char;
using uint_fast16_t = unsigned int;
using uint_fast32_t = unsigned int;
using uint_fast64_t = unsigned long long;

/*分别为宽度至少有 8、16、32 和 64 位的最小无符号整数类型*/
using uint_least8_t = unsigned char;
using uint_least16_t = unsigned short;
using uint_least32_t = unsigned int;
using uint_least64_t = unsigned long long;

/*最大宽度的无符号整数类型*/
using uintmax_t = unsigned long long;

/*足以保有指针的无符号整数类型*/
#ifdef MY_SYSTEM_64_WIN
using uintptr_t = unsigned long;
#endif //MY_SYSTEM_64_WIN
MY_STL_namespace_end

#ifdef HAS_STDINT_H
#include <stdint.h>
#else
    namespace cstint
{
/*int8_t、int16_t、int32_t、int64_t 类型对象的最小值*/
#define INT8_MIN (-127i8 - 1)
#define INT16_MIN (-32767i16 - 1)
#define INT32_MIN (-2147483647i32 - 1)
#define INT64_MIN (-9223372036854775807i64 - 1)

/*int_fast8_t、int_fast16_t、int_fast32_t、int_fast64_t 类型对象的最小值*/
#define INT_FAST8_MIN INT8_MIN
#define INT_FAST16_MIN INT32_MIN
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST64_MIN INT64_MIN

/*int_least8_t、int_least16_t、int_least32_t、int_least64_t 类型对象的最小值*/
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN

/*intptr_t 类型对象的最小值*/
#ifdef MY_SYSTEM_64_WIN
#define INTPTR_MIN INT64_MIN
#endif //MY_SYSTEM_64_WIN

/*intmax_t 类型对象的最小值*/
#define INTMAX_MIN INT64_MIN

    /*int8_t、int16_t、int32_t、int64_t 类型对象的最大值*/

#define INT8_MAX 127i8
#define INT16_MAX 32767i16
#define INT32_MAX 2147483647i32
#define INT64_MAX 9223372036854775807i64

/*int_fast8_t、int_fast16_t、int_fast32_t、int_fast64_t 类型对象的最大值*/
#define INT_FAST8_MAX INT8_MAX
#define INT_FAST16_MAX INT32_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST64_MAX INT64_MAX

/*int_least8_t、int_least16_t、int_least32_t、int_least64_t 类型对象的最大值*/
#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX
#define UINT_LEAST8_MAX UINT8_MAX

/*intptr_t 类型对象的最大值*/
#ifdef MY_SYSTEM_64_WIN
#define INTPTR_MAX INT64_MAX
#endif //MY_SYSTEM_64_WIN

/*intmax_t 类型对象的最大值*/
#define INTMAX_MAX INT64_MAX

/*uint8_t、uint16_t、uint32_t、uint64_t 类型对象的最大值*/
#define UINT8_MAX 0xffui8
#define UINT16_MAX 0xffffui16
#define UINT32_MAX 0xffffffffui32
#define UINT64_MAX 0xffffffffffffffffui64

/*uint_fast8_t、uint_fast16_t、uint_fast32_t、uint_fast64_t 类型对象的最大值*/
#define UINT_FAST8_MAX UINT8_MAX
#define UINT_FAST16_MAX UINT32_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX

/*uint_least8_t、uint_least16_t、uint_least32_t、uint_least64_t 类型对象的最大值*/
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

/*uintptr_t 类型对象的最大值*/
#ifdef MY_SYSTEM_64_WIN
#define UINTPTR_MAX UINT64_MAX
#endif //MY_SYSTEM_64_WIN

/*uintmax_t 类型对象的最大值*/
#define UINTMAX_MAX UINT64_MAX

/*ptrdiff_t 类型对象的最小,最大值*/
#define PTRDIFF_MIN INTPTR_MIN
#define PTRDIFF_MAX INTPTR_MAX

/*size_t 类型对象的最大值*/
#define SIZE_MAX UINTPTR_MAX

/*sig_atomic_t 类型对象的最小，最大值*/
#define SIG_ATOMIC_MIN INT32_MIN
#define SIG_ATOMIC_MAX INT32_MAX

/*wchar_t 类型对象的最小,最大值*/
#define WCHAR_MIN 0x0000
#define WCHAR_MAX 0xffff

/*wchar_t 类型对象的最小,最大值*/
#define WINT_MIN 0x0000
#define WINT_MAX 0xffff

/*展开成拥有其实参所指定的值且类型分别为 int_least8_t、int_least16_t、int_least32_t、int_least64_t 的提升类型的整数常量表达式*/
#define INT8_C(x) (x)
#define INT16_C(x) (x)
#define INT32_C(x) (x)
#define INT64_C(x) (x##LL)

/*展开成拥有其实参所指定的值且类型分别为 uint_least8_t、uint_least16_t、uint_least32_t、uint_least64_t 的提升类型的整数常量表达式*/
#define UINT8_C(x) (x)
#define UINT16_C(x) (x)
#define UINT32_C(x) (x##U)
#define UINT64_C(x) (x##ULL)

/*展开成拥有其实参所指定的值且类型为 intmax_t 的整数常量表达式*/
#define INTMAX_C(x) INT64_C(x)

/*展开成拥有其实参所指定的值且类型为 uintmax_t 的整数常量表达式*/
#define UINTMAX_C(x) UINT64_C(x)
}
#endif //STDINT_H
#endif //CSTDINT_HPP