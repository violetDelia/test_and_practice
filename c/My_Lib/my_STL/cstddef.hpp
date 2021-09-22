#pragma once
#ifndef CSTDDEF_HPP
#define CSTDDEF_HPP
#include "my_STL/my_help.hpp"
MY_STL_namespace_begin

#ifdef MY_SYSTEM_64_WIN
    using size_t = unsigned __int64; /* 64位系统内存理论最大值 */
using ptrdiff_t = __int64;           /* 64位系统下标理论最大差值 */
#endif                               //MY_SYSTEM_64

using nullptr_t = decltype(nullptr); /* 空指针字面量 nullptr 的类型。它是既非指针类型亦非指向成员指针类型的独立类型。 */

using max_align_t = long double; /*对其的最大标量*/

/*字节*/
enum class byte : unsigned char
{
};

/*字节运算符重载*/
template <class IntType>
constexpr byte operator<<(byte b, IntType shift) noexcept
{
    return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(b) << shift));
};

/*字节运算符重载*/
template <class IntType>
constexpr byte &operator<<=(byte &b, IntType shift) noexcept
{
    return b = b << shift;
};

/*字节运算符重载*/
template <class IntType>
constexpr byte operator>>(byte b, IntType shift) noexcept
{
    return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(b) >> shift));
};

/*字节运算符重载*/
template <class IntType>
constexpr byte &operator>>=(byte &b, IntType shift) noexcept
{
    return b = b >> shift;
};

/*字节运算符重载*/
constexpr byte operator|(byte l, byte r) noexcept
{
    return static_cast<byte>(
        static_cast<unsigned char>(static_cast<unsigned int>(l) | static_cast<unsigned int>(r)));
};

/*字节运算符重载*/
constexpr byte &operator|=(byte &l, byte r) noexcept
{
    return l = l | r;
};

/*字节运算符重载*/
constexpr byte operator&(byte l, byte r) noexcept
{
    return static_cast<byte>(
        static_cast<unsigned char>(static_cast<unsigned int>(l) & static_cast<unsigned int>(r)));
}

/*字节运算符重载*/
constexpr byte &operator&=(byte &l, byte r) noexcept
{
    return l = l & r;
};

/*字节运算符重载*/
constexpr byte operator^(byte l, byte r) noexcept
{
    return static_cast<byte>(
        static_cast<unsigned char>(static_cast<unsigned int>(l) ^ static_cast<unsigned int>(r)));
};

/*字节运算符重载*/
constexpr byte &operator^=(byte &l, byte r) noexcept
{
    return l = l ^ r;
};

/*字节运算符重载*/
constexpr byte operator~(byte b) noexcept
{
    return static_cast<byte>(static_cast<unsigned char>(~static_cast<unsigned int>(b)));
};

/*转化为整形*/
template <class IntType>
constexpr IntType to_integer(byte b) noexcept
{
    return IntType(b);
};

MY_STL_namespace_end
#endif //CSTDDEF_HPP