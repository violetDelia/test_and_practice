#pragma once
#ifndef CSTDDEF_HPP
#define CSTDDEF_HPP
namespace my_std
{
    typedef unsigned long long size_t;     /* 64位系统内存理论最大值 */
    typedef long long ptrdiff_t;           /* 64位系统下标理论最大差值 */
    typedef decltype(nullptr) nullptr_t; /* 空指针字面量 nullptr 的类型。它是既非指针类型亦非指向成员指针类型的独立类型。 */
} //namespace
#endif //CSTDDEF_HPP