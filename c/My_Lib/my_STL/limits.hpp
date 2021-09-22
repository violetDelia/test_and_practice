#pragma once
#ifndef LIMITS_HPP
#define LIMITS_HPP
#include "my_STL/cfloat.hpp"
#include "my_STL/climits.hpp"
#include "my_STL/cstdint.hpp"
#include "my_STL/my_help.hpp"
MY_STL_namespace_begin

    /*浮点算术在凡将表达式结果存储于浮点类型对象时所用的舍入模式*/
    enum float_round_style {
        /*无法确定舍入风格*/
        round_indeterminate = -1,
        /*向零舍入*/
        round_toward_zero = 0,
        /*向最近可表示值舍入*/
        round_to_nearest = 1,
        /*向正无穷大舍入*/
        round_toward_infinity = 2,
        /*向负无穷大舍入*/
        round_toward_neg_infinity = 3
    };

/*浮点类型对非正规值的支持。*/
enum float_denorm_style
{
    /*无法确定是否支持非正规值*/
    denorm_indeterminate = -1,
    /*类型不支持非正规值*/
    denorm_absent = 0,
    /*类型允许非正规值*/
    denorm_present = 1
};

/*非特化的默认值*/
struct _num_base
{
    static constexpr bool is_specialized = false;                       /*是否特化*/
    static constexpr bool is_signed = false;                            /*是否是有符号类型*/
    static constexpr bool is_integer = false;                           /*是否是整数类型*/
    static constexpr bool is_exact = false;                             /*是否为一个准确数*/
    static constexpr float_round_style round_style = round_toward_zero; /*鉴别类型所用的舍入模式*/
    static constexpr bool is_bounded = false;                           /*鉴别表示有限值集合的类型*/
    static constexpr bool is_modulo = false;                            /*鉴别以模算术处理溢出的类型*/
    static constexpr int radix = 0;                                     /*用于表示该类型的数字系统的底*/
    static constexpr int digits = 0;                                    /*有效数位*/
    static constexpr int digits10 = 0;                                  /*可以无更改的与10进制位转换的有效位数*/
    static constexpr int max_digits10 = 0;                              /*精确所需位数*/
    static constexpr bool traps = false;                                /*鉴别可能导致算术运算出现陷阱的类型*/

    static constexpr bool has_infinity = false;                     /*是否能表示无穷大*/
    static constexpr bool has_quiet_NaN = false;                    /*能够表示特殊值“安静的非数”*/
    static constexpr bool has_signaling_NaN = false;                /*能够表示特殊值“发信的非数”*/
    static constexpr float_denorm_style has_denorm = denorm_absent; /*鉴别浮点类型如何支持非正规值*/
    static constexpr bool has_denorm_loss = false;                  /*鉴别浮点类型是否检测精度损失为非正规损失，而非不准确结果*/
    static constexpr bool is_iec559 = false;                        /*鉴别符合 IEC 559/IEEE 754 浮点类型*/
    static constexpr int min_exponent = 0;                          /*最小指数（以2为底）*/
    static constexpr int min_exponent10 = 0;                        /*最小指数（以10为底）*/
    static constexpr int max_exponent = 0;                          /*最大指数（以2为底）*/
    static constexpr int max_exponent10 = 0;                        /*最大指数（以10为底）*/
    static constexpr bool tinyness_before = false;                  /*鉴别检测舍入前是否非正规的浮点类型*/
};

/*整形数的特征*/
struct _num_int_base : _num_base
{
    static constexpr bool is_bounded = true;     /*鉴别表示有限值集合的类型*/
    static constexpr bool is_exact = true;       /*是否为一个准确数*/
    static constexpr bool is_integer = true;     /*是否是整数类型*/
    static constexpr bool is_specialized = true; /*是否特化*/
    static constexpr int radix = 2;              /*用于表示该类型的数字系统的进制*/
};

/*浮点数的特征*/
struct _num_float_base : _num_base
{
    static constexpr bool is_signed = true;                            /*是否是有符号类型*/
    static constexpr bool is_specialized = true;                       /*是否特化*/
    static constexpr float_round_style round_style = round_to_nearest; /*鉴别类型所用的舍入模式*/
    static constexpr int radix = FLT_RADIX;                            /*用于表示该类型的数字系统的底*/

    static constexpr float_denorm_style has_denorm = denorm_present; /*鉴别浮点类型如何支持非正规值*/
    static constexpr bool has_infinity = true;                       /*是否能表示无穷大*/
    static constexpr bool has_quiet_NaN = true;                      /*能够表示特殊值“安静的非数”*/
    static constexpr bool has_signaling_NaN = true;                  /*能够表示特殊值“发信的非数”*/
    static constexpr bool is_bounded = true;                         /*鉴别表示有限值集合的类型*/
    static constexpr bool is_iec559 = true;                          /*鉴别符合 IEC 559/IEEE 754 浮点类型*/
};

/*无特化的类型特性*/
template <class T>
class numeric_limits : public _num_base
{
public:
    /*该类型的最小值*/
    static constexpr T min() noexcept { return T(); }
    /*该类型的最大值*/
    static constexpr T max() noexcept { return T(); }
    /*该类型的最低有限值*/
    static constexpr T lowest() noexcept { return T(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr T epsilon() noexcept { return T(); }
    /*给定浮点类型的最大舍入误差*/
    static constexpr T round_error() noexcept { return T(); }
    /*给定类型的正无穷大值*/
    static constexpr T infinity() noexcept { return T(); }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr T quiet_NaN() noexcept { return T(); }
    /*给定浮点类型的发信的 NaN*/
    static constexpr T signaling_NaN() noexcept { return T(); }
    /*给定浮点类型的最小正非正规值*/
    static constexpr T denorm_min() noexcept { return T(); }
};

/*const 类型特性*/
template <class T>
class numeric_limits<const T> : public numeric_limits<T>
{
};

/*volatile 类型特性*/
template <class T>
class numeric_limits<volatile T> : public numeric_limits<T>
{
};

/*const volatile 类型特性*/
template <class T>
class numeric_limits<const volatile T> : public numeric_limits<T>
{
};

/*bool的特征*/
template <>
class numeric_limits<bool> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr bool(min)() noexcept { return false; }
    /*该类型的最大值*/
    static constexpr bool(max)() noexcept { return true; }
    /*该类型的最低有限值*/
    static constexpr bool lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr bool epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr bool round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr bool infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr bool quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr bool signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr bool denorm_min() noexcept { return 0; }
};

/*char的特性*/
template <>
class numeric_limits<char> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr char(min)() noexcept { return CHAR_MIN; }
    /*该类型的最大值*/
    static constexpr char(max)() noexcept { return CHAR_MAX; }
    /*该类型的最低有限值*/
    static constexpr char lowest() noexcept { return CHAR_MIN; }
    /*机器 epsilon 浮点数特征*/
    static constexpr char epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr char round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr char infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr char quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr char signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr char denorm_min() noexcept { return 0; }

    static constexpr bool is_signed = CHAR_MIN != 0;    /*是否是有符号类型*/
    static constexpr bool is_modulo = CHAR_MIN == 0;    /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT - is_signed; /*有效数位*/
    static constexpr int digits10 = 2;                  /*可以无更改的与10进制位转换的有效位数*/
    //static constexpr bool digits10 = (CHAR_BIT * sizeof(char) - (is_signed ? 1 : 0)) * log10(2);
};

/*signed char的特性*/
template <>
class numeric_limits<signed char> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr signed char(min)() noexcept { return SCHAR_MIN; }
    /*该类型的最大值*/
    static constexpr signed char(max)() noexcept { return SCHAR_MAX; }
    /*该类型的最低有限值*/
    static constexpr signed char lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr signed char epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr signed char round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr signed char infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr signed char quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr signed char signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr signed char denorm_min() noexcept { return 0; }

    static constexpr bool is_signed = true;     /*是否是有符号类型*/
    static constexpr int digits = CHAR_BIT - 1; /*能无更改地表示的 radix 位数*/
    static constexpr int digits10 = 2;          /*可以无更改的与10进制位转换的有效位数*/
};

/*unsigned char的特性*/
template <>
class numeric_limits<unsigned char> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr unsigned char(min)() noexcept { return 0; }
    /*该类型的最大值*/
    static constexpr unsigned char(max)() noexcept { return UCHAR_MAX; }
    /*该类型的最低有限值*/
    static constexpr unsigned char lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr unsigned char epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr unsigned char round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr unsigned char infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr unsigned char quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr unsigned char signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr unsigned char denorm_min() noexcept { return 0; }

    static constexpr bool is_modulo = true; /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT; /*能无更改地表示的 radix 位数*/
    static constexpr int digits10 = 2;      /*可以无更改的与10进制位转换的有效位数*/
};

#ifdef HAS_CHAR8_T
template <>
class numeric_limits<char8_t>
{
public:
    /*该类型的最小值*/
    static constexpr bool(min)() noexcept { return; }
    /*该类型的最大值*/
    static constexpr bool(max)() noexcept { return true; }
    /*该类型的最低有限值*/
    static constexpr bool lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr bool epsilon() noexcept { return T(); }
    /*给定浮点类型的最大舍入误差*/
    static constexpr bool round_error() noexcept { return T(); }
    /*给定类型的正无穷大值*/
    static constexpr bool infinity() noexcept { return T(); }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr bool quiet_NaN() noexcept { return T(); }
    /*给定浮点类型的发信的 NaN*/
    static constexpr bool signaling_NaN() noexcept { return T(); }
    /*给定浮点类型的最小正非正规值*/
    static constexpr bool denorm_min() noexcept { return T(); }

    static constexpr bool is_signed = CHAR_MIN != 0;     /*是否是有符号类型*/
    static constexpr bool is_modulo = CHAR_MIN == 0;     /*鉴别以模算术处理溢出的类型*/
    static constexpr bool digits = CHAR_BIT - is_signed; /*有效数位*/
    static constexpr bool digits10 = 2;                  /*可以无更改的与10进制位转换的有效位数*/
};
#endif //HAS_CHAR8_T

/*char16_t的特性*/
template <>
class numeric_limits<char16_t> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr char16_t(min)() noexcept { return 0; }
    /*该类型的最大值*/
    static constexpr char16_t(max)() noexcept { return USHRT_MAX; }
    /*该类型的最低有限值*/
    static constexpr char16_t lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr char16_t epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr char16_t round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr char16_t infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr char16_t quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr char16_t signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr char16_t denorm_min() noexcept { return 0; }

    static constexpr bool is_modulo = true;                    /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT * sizeof(char16_t); /*有效数位*/
    static constexpr int digits10 = 4;                         /*可以无更改的与10进制位转换的有效位数*/
};

/*char32_t的特性*/
template <>
class numeric_limits<char32_t> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr char32_t(min)() noexcept { return 0; }
    /*该类型的最大值*/
    static constexpr char32_t(max)() noexcept { return UINT_MAX; }
    /*该类型的最低有限值*/
    static constexpr char32_t lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr char32_t epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr char32_t round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr char32_t infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr char32_t quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr char32_t signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr char32_t denorm_min() noexcept { return 0; }

    static constexpr bool is_modulo = true;                    /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT * sizeof(char32_t); /*有效数位*/
    static constexpr int digits10 = 9;                         /*可以无更改的与10进制位转换的有效位数*/
};

/*wchar_t的特性*/
template <>
class numeric_limits<wchar_t> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr wchar_t(min)() noexcept { return WCHAR_MIN; }
    /*该类型的最大值*/
    static constexpr wchar_t(max)() noexcept { return WCHAR_MAX; }
    /*该类型的最低有限值*/
    static constexpr wchar_t lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr wchar_t epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr wchar_t round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr wchar_t infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr wchar_t quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr wchar_t signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr wchar_t denorm_min() noexcept { return 0; }

    static constexpr bool is_signed = WCHAR_MIN != 0;                     /*是否是有符号类型*/
    static constexpr bool is_modulo = WCHAR_MIN == 0;                     /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT * sizeof(wchar_t) - is_signed; /*有效数位*/
    static constexpr int digits10 = 4;                                    /*可以无更改的与10进制位转换的有效位数*/
};

/*short的特征*/
template <>
class numeric_limits<short> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr short(min)() noexcept { return SHRT_MIN; }
    /*该类型的最大值*/
    static constexpr short(max)() noexcept { return SHRT_MAX; }
    /*该类型的最低有限值*/
    static constexpr short lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr short epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr short round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr short infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr short quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr short signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr short denorm_min() noexcept { return 0; }

    static constexpr bool is_signed = true;                     /*是否是有符号类型*/
    static constexpr int digits = CHAR_BIT * sizeof(short) - 1; /*有效数位*/
    static constexpr int digits10 = 4;                          /*可以无更改的与10进制位转换的有效位数*/
};

/*int的特征*/
template <>
class numeric_limits<int> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr int(min)() noexcept { return INT_MIN; }
    /*该类型的最大值*/
    static constexpr int(max)() noexcept { return INT_MAX; }
    /*该类型的最低有限值*/
    static constexpr int lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr int epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr int round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr int infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr int quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr int signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr int denorm_min() noexcept { return 0; }

    static constexpr bool is_signed = true;                   /*是否是有符号类型*/
    static constexpr int digits = CHAR_BIT * sizeof(int) - 1; /*有效数位*/
    static constexpr int digits10 = 9;                        /*可以无更改的与10进制位转换的有效位数*/
};

/*long的特征*/
template <>
class numeric_limits<long> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr long(min)() noexcept { return LONG_MIN; }
    /*该类型的最大值*/
    static constexpr long(max)() noexcept { return LONG_MAX; }
    /*该类型的最低有限值*/
    static constexpr long lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr long epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr long round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr long infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr long quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr long signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr long denorm_min() noexcept { return 0; }

    static constexpr bool is_signed = true;                    /*是否是有符号类型*/
    static constexpr int digits = CHAR_BIT * sizeof(long) - 1; /*有效数位*/
    static constexpr int digits10 = 9;                         /*可以无更改的与10进制位转换的有效位数*/
};

/*long long的特征*/
template <>
class numeric_limits<long long> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr long long(min)() noexcept { return LLONG_MIN; }
    /*该类型的最大值*/
    static constexpr long long(max)() noexcept { return LLONG_MAX; }
    /*该类型的最低有限值*/
    static constexpr long long lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr long long epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr long long round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr long long infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr long long quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr long long signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr long long denorm_min() noexcept { return 0; }

    static constexpr bool is_signed = true;                         /*是否是有符号类型*/
    static constexpr int digits = CHAR_BIT * sizeof(long long) - 1; /*有效数位*/
    static constexpr int digits10 = 18;                             /*可以无更改的与10进制位转换的有效位数*/
};

/*unsigned short的特征*/
template <>
class numeric_limits<unsigned short> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr unsigned short(min)() noexcept { return 0; }
    /*该类型的最大值*/
    static constexpr unsigned short(max)() noexcept { return USHRT_MAX; }
    /*该类型的最低有限值*/
    static constexpr unsigned short lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr unsigned short epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr unsigned short round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr unsigned short infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr unsigned short quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr unsigned short signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr unsigned short denorm_min() noexcept { return 0; }

    static constexpr bool is_modulo = true;                          /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT * sizeof(unsigned short); /*有效数位*/
    static constexpr int digits10 = 4;                               /*可以无更改的与10进制位转换的有效位数*/
};

/*unsigned int的特征*/
template <>
class numeric_limits<unsigned int> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr unsigned int(min)() noexcept { return 0; }
    /*该类型的最大值*/
    static constexpr unsigned int(max)() noexcept { return UINT_MAX; }
    /*该类型的最低有限值*/
    static constexpr unsigned intlowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr unsigned int epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr unsigned int round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr unsigned int infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr unsigned int quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr unsigned int signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr unsigned int denorm_min() noexcept { return 0; }

    static constexpr bool is_modulo = true;                        /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT * sizeof(unsigned int); /*有效数位*/
    static constexpr int digits10 = 9;                             /*可以无更改的与10进制位转换的有效位数*/
};

/*unsigned long的特征*/
template <>
class numeric_limits<unsigned long> : public _num_int_base
{

public:
    /*该类型的最小值*/
    static constexpr unsigned long(min)() noexcept { return 0; }
    /*该类型的最大值*/
    static constexpr unsigned long(max)() noexcept { return ULONG_MAX; }
    /*该类型的最低有限值*/
    static constexpr unsigned long lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr unsigned long epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr unsigned long round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr unsigned long infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr unsigned long quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr unsigned long signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr unsigned long denorm_min() noexcept { return 0; }

    static constexpr bool is_modulo = true;                         /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT * sizeof(unsigned long); /*有效数位*/
    static constexpr int digits10 = 9;                              /*可以无更改的与10进制位转换的有效位数*/
};

/*unsigned long long的特征*/
template <>
class numeric_limits<unsigned long long> : public _num_int_base
{
public:
    /*该类型的最小值*/
    static constexpr unsigned long long(min)() noexcept { return 0; }
    /*该类型的最大值*/
    static constexpr unsigned long long(max)() noexcept { return ULLONG_MAX; }
    /*该类型的最低有限值*/
    static constexpr unsigned long long lowest() noexcept { return (min)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr unsigned long long epsilon() noexcept { return 0; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr unsigned long long round_error() noexcept { return 0; }
    /*给定类型的正无穷大值*/
    static constexpr unsigned long long infinity() noexcept { return 0; }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr unsigned long long quiet_NaN() noexcept { return 0; }
    /*给定浮点类型的发信的 NaN*/
    static constexpr unsigned long long signaling_NaN() noexcept { return 0; }
    /*给定浮点类型的最小正非正规值*/
    static constexpr unsigned long long denorm_min() noexcept { return 0; }

    static constexpr bool is_modulo = true;                 /*鉴别以模算术处理溢出的类型*/
    static constexpr int digits = CHAR_BIT * sizeof(short); /*有效数位*/
    static constexpr int digits10 = 19;                     /*可以无更改的与10进制位转换的有效位数*/
};

/*float的特征*/
template <>
class numeric_limits<float> : public _num_float_base
{
public:
    /*该类型的最小值*/
    static constexpr float(min)() noexcept { return FLT_MIN; }
    /*该类型的最大值*/
    static constexpr float(max)() noexcept { return FLT_MAX; }
    /*该类型的最低有限值*/
    static constexpr float lowest() noexcept { return -(max)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr float epsilon() noexcept { return FLT_EPSILON; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr float round_error() noexcept { return 0.5F; }
    /*给定类型的正无穷大值*/
    static constexpr float infinity() noexcept { return __builtin_huge_valf(); }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr float quiet_NaN() noexcept { return __builtin_nanf("0"); }
    /*给定浮点类型的发信的 NaN*/
    static constexpr float signaling_NaN() noexcept { return __builtin_nanf("1"); }
    /*给定浮点类型的最小正非正规值*/
    static constexpr float denorm_min() noexcept { return 1.401298464e-45F; /*FLT_TRUE_MIN;*/ }

    static constexpr int digits = FLT_MANT_DIG;           /*有效数位*/
    static constexpr int digits10 = FLT_DIG;              /*可以无更改的与10进制位转换的有效位数*/
    static constexpr int max_digits10 = 9;                //FLT_DECIMAL_DIG;  /*精确所需位数*/
    static constexpr int min_exponent = FLT_MIN_EXP;      /*最小指数（以2为底）*/
    static constexpr int min_exponent10 = FLT_MIN_10_EXP; /*最小指数（以10为底）*/
    static constexpr int max_exponent = FLT_MAX_EXP;      /*最大指数（以2为底）*/
    static constexpr int max_exponent10 = FLT_MAX_10_EXP; /*最大指数（以10为底）*/
};

/*double的特征*/
template <>
class numeric_limits<double> : public _num_float_base
{
public:
    /*该类型的最小值*/
    static constexpr double(min)() noexcept { return DBL_MIN; }
    /*该类型的最大值*/
    static constexpr double(max)() noexcept { return DBL_MAX; }
    /*该类型的最低有限值*/
    static constexpr double lowest() noexcept { return -(max)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr double epsilon() noexcept { return DBL_EPSILON; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr double round_error() noexcept { return 0.5; }
    /*给定类型的正无穷大值*/
    static constexpr double infinity() noexcept { return __builtin_huge_val(); }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr double quiet_NaN() noexcept { return __builtin_nan("0"); }
    /*给定浮点类型的发信的 NaN*/
    static constexpr double signaling_NaN() noexcept { return __builtin_nan("1"); }
    /*给定浮点类型的最小正非正规值*/
    static constexpr double denorm_min() noexcept { return 4.9406564584124654e-324; /*DBL_TRUE_MIN;*/ }

    static constexpr int digits = DBL_MANT_DIG;           /*有效数位*/
    static constexpr int digits10 = DBL_DIG;              /*可以无更改的与10进制位转换的有效位数*/
    static constexpr int max_digits10 = 17;               //DBL_DECIMAL_DIG;  /*精确所需位数*/
    static constexpr int min_exponent = DBL_MIN_EXP;      /*最小指数（以2为底）*/
    static constexpr int min_exponent10 = DBL_MIN_10_EXP; /*最小指数（以10为底）*/
    static constexpr int max_exponent = DBL_MAX_EXP;      /*最大指数（以2为底）*/
    static constexpr int max_exponent10 = DBL_MAX_10_EXP; /*最大指数（以10为底）*/
};

/*long double的特征*/
template <>
class numeric_limits<long double> : public _num_float_base
{
public:
    /*该类型的最小值*/
    static constexpr long double(min)() noexcept { return LDBL_MIN; }
    /*该类型的最大值*/
    static constexpr long double(max)() noexcept { return LDBL_MAX; }
    /*该类型的最低有限值*/
    static constexpr long double lowest() noexcept { return -(max)(); }
    /*机器 epsilon 浮点数特征*/
    static constexpr long double epsilon() noexcept { return LDBL_EPSILON; }
    /*给定浮点类型的最大舍入误差*/
    static constexpr long double round_error() noexcept { return 0.5L; }
    /*给定类型的正无穷大值*/
    static constexpr long double infinity() noexcept { return __builtin_huge_val(); }
    /*给定浮点类型的安静 NaN 值*/
    static constexpr long double quiet_NaN() noexcept { return __builtin_nan("0"); }
    /*给定浮点类型的发信的 NaN*/
    static constexpr long double signaling_NaN() noexcept { return __builtin_nan("1"); }
    /*给定浮点类型的最小正非正规值*/
    static constexpr long double denorm_min() noexcept { return 4.9406564584124654e-324; /*LDBL_TRUE_MIN;*/ }

    static constexpr int digits = LDBL_MANT_DIG;           /*有效数位*/
    static constexpr int digits10 = LDBL_DIG;              /*可以无更改的与10进制位转换的有效位数*/
    static constexpr int max_digits10 = DECIMAL_DIG;       /*精确所需位数*/
    static constexpr int min_exponent = LDBL_MIN_EXP;      /*最小指数（以2为底）*/
    static constexpr int min_exponent10 = LDBL_MIN_10_EXP; /*最小指数（以10为底）*/
    static constexpr int max_exponent = LDBL_MAX_EXP;      /*最大指数（以2为底）*/
    static constexpr int max_exponent10 = LDBL_MAX_10_EXP; /*最大指数（以10为底）*/
};

MY_STL_namespace_end
#endif //LIMITS