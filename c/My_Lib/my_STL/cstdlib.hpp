#pragma once
#ifndef CSTDLIB_HPP
#define CSTDLIB_HPP
#include "my_STL/my_help.hpp"
#ifdef HAS_STDLIB_H
#include <stdlib.h>
#endif //HAS_STDLIB_H
MY_STL_namespace_begin

    /*分配 size 字节的未初始化存储。*/
    void *
    malloc(size_t size)
{
    void *address = CSTD malloc(size);
    std::cout << "malloc: " << address << "   size: " << size << std::endl;
    return address;
};

/*分配 size 字节的未初始化存储，由 alignment 指定其对齐。 size 参数必须是 alignment 的整数倍。*/
void *aligned_alloc(size_t alignment, size_t size)
{
    void *address = CSTD _aligned_malloc(size, alignment);
    std::cout << "aligned_alloc: " << address << "   size: " << size << std::endl;
    return address;
};

/*分配 num 个大小为 size 的对象的数组，并初始化所有位为零。*/
void *calloc(size_t nmemb, size_t size)
{
    void *address = CSTD calloc(nmemb, size);
    std::cout << "calloc: " << address << "   size: " << size << std::endl;
    return address;
};

/*解分配先前由 malloc()、calloc()、aligned_alloc 或 realloc() 分配的内存空间。*/
void free(void *ptr)
{
    std::cout << "free: " << ptr << std::endl;
    CSTD free(ptr);
};

/*重分配给定的内存区域。*/
void *realloc(void *ptr, size_t size)
{
    void *_old = ptr;
    void *address = CSTD realloc(ptr, size);
    std::cout << "realloc: " << _old << "->" << address << "   size: " << size << std::endl;
    return address;
};

MY_STL_namespace_end
#endif //CSTDLIB