#pragma once
#ifndef CMATH_HPP
#define CMATH_HPP
#include "my_STL/my_help.hpp"
#include "my_STL/type_traits.hpp"
#ifdef HAS_MATH_H
#include <math.h>
/**/
/**/
MY_STL_namespace_begin

    /**
     * @brief log10运算
     * 
     * @param x 底数
     * @return float 
     */
    inline constexpr float
    log10(float x)
{
    return CSTD log10f(x);
};

/**
 * @brief log10运算
 * 
 * @param x 底数
 * @return double 
 */
inline constexpr double log10(double x)
{
    return CSTD log10(x);
};

/**
 * @brief log10运算
 * 
 * @param x 底数
 * @return long double 
 */
inline constexpr long double log10(long double x)
{
    return CSTD log10l(x);
};

/**
 * @brief log10运算
 * 
 * @param x 底数
 * @return float 
 */
inline constexpr float log10f(float x)
{
    return CSTD log10f(x);
};

/**
 * @brief log10运算
 * 
 * @param x 底数
 * @return long double 
 */
inline constexpr long double log10l(long double x)
{
    return CSTD log10l(x);
};

/**
 * @brief log10运算
 * 
 * @tparam T 整数类型
 * @param t 数值
 * @return double 
 */
template <class T, enable_if_t<is_integral_v<T>, int> = 0>
inline constexpr double log10(T t)
{
    return CSTD log10(static_cast<double>(t));
}

MY_STL_namespace_end
#endif //_HAS_MATH_H
#endif //CMATH_HPP