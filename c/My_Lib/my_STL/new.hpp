#pragma once
#ifndef NEW_HPP
#define NEW_HPP
#include "my_STL/cstddef.hpp"
#include "my_STL/exception.hpp"
#include "my_STL/my_help.hpp"

/**/
#include <istream>
/**/

MY_STL_namespace_begin

    /* bad_alloc 异常类 继承 exception 异常类 */
    class bad_alloc : public exception
{
public:
    /* bad_alloc 构造函数 */
    bad_alloc() noexcept : exception("bad_alloc exception")
    {
        std::cout << "bad_alloc created: " << this << "   size:" << sizeof(*this) << std::endl;
    }

    /* bad_alloc 析构函数 */
    ~bad_alloc()
    {
        std::cout << "bad_alloc destoried: " << this << "   size:" << sizeof(*this) << std::endl;
    }

}; //bad_alloc

/**
     * @brief bad_array_new_length 异常类 继承 bad_alloc 异常类
     * 
     */
class bad_array_new_length : public bad_alloc
{
public:
    /* bad_array_new_length 构造函数 */
    bad_array_new_length() noexcept : bad_alloc()
    {
        std::cout << "bad_array_new_length created: " << this << "   size:" << sizeof(*this) << std::endl;
    }

    /* bad_array_new_length 析构函数 */
    ~bad_array_new_length()
    {
        std::cout << "bad_array_new_length destoried: " << this << "   size:" << sizeof(*this) << std::endl;
    }
}; //bad_array_new_length

/* 无异常标记 */
struct nothrow_t
{
    explicit nothrow_t() = default;
};
extern const nothrow_t nothrow;

/*在将 new 表达式和 delete 表达式用于对齐要求大于 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 的对象时，该对齐要求作为 align_val_t 类型的参数传递给分配/解分配函数。*/
enum class align_val_t : size_t
{
};

using new_handler = void (*)();

new_handler _current_handler = nullptr;

new_handler get_new_handler() noexcept
{
    return _current_handler;
};

new_handler set_new_handler(new_handler new_p) noexcept
{
    new_handler _old_handler = _current_handler;
    _current_handler = new_p;
    return _old_handler;
};

/**
     * @brief 判断_size是否是2的幂
     * 
     * @param _size 
 
     */
bool _is_pow_of_2(const size_t _size)
{
    return _size == 0 || (_size & (_size - 1)) != 0;
}

MY_STL_namespace_end

    /**
 * @brief 以分配为单个对象请求的存储
 * 
 * @param size 字节数
 * @return void* 内存地址
 */
    [[nodiscard]] void *From_Right_to_Left
    operator new(STD size_t size)
{
    size = size ? size : 1;
    void *address = nullptr;
    while (!(address = CSTD malloc(size)))
    {
        STD new_handler _current_handler = STD get_new_handler();
        if (_current_handler)
        {
            (*_current_handler)();
            address = CSTD malloc(size);
        }
        else
        {
            throw STD bad_alloc();
        }
    }
    std::cout << "operate new: " << address << "   size: " << size << std::endl;
    return address;
};

/**
 * @brief 为非数组 new 表达式调用，以分配对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 的单个对象所要求的存储
 * 
 * @param size 字节数
 * @param alignment 对其要求
 * @return void* 内存地址
 */
[[nodiscard]] void *From_Right_to_Left operator new(size_t size, STD align_val_t alignment)
{
    if (!STD _is_pow_of_2(static_cast<STD size_t>(alignment)))
    {
        return new STD bad_alloc();
    };
    size = size ? size : 1;
    void *address = nullptr;
    while (!(address = CSTD _aligned_malloc(size, static_cast<CSTD size_t>(alignment))))
    {
        STD new_handler current_handler = STD get_new_handler();
        if (current_handler)
        {
            current_handler;
            address = CSTD malloc(size);
        }
        else
        {
            throw STD bad_alloc();
        }
    }
    std::cout << "operate new: " << address << "   size: " << size << std::endl;
    return address;
}

/**
 * @brief 为不抛出非数组 new 表达式所调用。
 * @param size 字节数
 * @param nothrow 无异常标记
 * @return void* 内存地址
 */
[[nodiscard]] void *From_Right_to_Left operator new(size_t size, const STD nothrow_t &nothrow) noexcept
{
    size = size ? size : 1;
    void *address = CSTD malloc(size);
    std::cout << "operate new: " << address << "   size: " << size << std::endl;
    return address;
};

/**
 * @brief 在对象对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 时为不抛出非数组 new 表达式所调用。
 * 
 * @param size 字节数   
 * @param alignment 对其要求
 * @param nothrow 无异常标记
 * @return void* 内存地址
 */
[[nodiscard]] void *From_Right_to_Left operator new(size_t size, STD align_val_t alignment, const STD nothrow_t &nothrow) noexcept
{
    if (!STD _is_pow_of_2(static_cast<STD size_t>(alignment)))
    {
        return nullptr;
    };
    size = size ? size : 1;
    void *address = CSTD _aligned_malloc(size, static_cast<CSTD size_t>(alignment));
    std::cout << "operate new: " << address << "   size: " << size << std::endl;
    return address;
};

/**
 * @brief  为 delete 表达式所调用，以解分配先前为单对象分配的存储。
 * 
 * @param ptr 内存指针
 */
void From_Right_to_Left operator delete(void *ptr) noexcept
{
    std::cout << "operate delete: " << ptr << std::endl;
    if (ptr)
        CSTD free(ptr);
};

/**
 * @brief 为 delete 表达式所调用，以解分配先前为单对象分配的存储。
 * 
 * @param ptr 内存指针
 * @param size 字节数
 */
void From_Right_to_Left operator delete(void *ptr, STD size_t size) noexcept
{
    operator delete(ptr);
};

/**
 * @brief 除了若对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 才被调用
 * 
 * @param ptr 内存地址
 * @param alignment 对其要求
 */
void From_Right_to_Left operator delete(void *ptr, STD align_val_t alignment) noexcept
{
    std::cout << "operate delete: " << ptr << std::endl;
    CSTD _aligned_free(ptr);
};

/**
 * @brief 除了若对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 才被调用
 * 
 * @param ptr 内存地址
 * @param alignment 对其要求
 */
void From_Right_to_Left operator delete(void *ptr, STD size_t size, STD align_val_t alignment) noexcept
{
    operator delete(ptr, alignment);
};
/**
 * @brief 若对象的构造函数抛出异常，则为不抛出的单对象 new 表达式所调用。标准库实现表现同 (1)
 * 
 * @param ptr 内存指针
 * @param nothrow 无异常标记
 */
void From_Right_to_Left operator delete(void *ptr, const STD nothrow_t &nothrow) noexcept
{
    operator delete(ptr);
};
/**
 * @brief 除了若对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 才被调用
 * 
 * @param ptr 内存地址
 * @param alignment 对其要求
 * @param nothrow 无异常标记
 */
void From_Right_to_Left operator delete(void *ptr, STD align_val_t alignment, const STD nothrow_t &nothrow) noexcept
{
    operator delete(ptr, alignment);
};

/**
 * @brief  为 new[] 表达式的数组形式所调用，以分配为数组请求的所有存储（包含可能的 new 表达式开销）。
 * 
 * @param size 字节数
 * @return void* 内存地址
 */
[[nodiscard]] void *From_Right_to_Left operator new[](STD size_t size)
{
    return operator new(size);
};

/**
 * @brief 为 new[] 表达式的数组形式调用，以分配对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 的对象数组要求的所有存储
 * 
 * @param size 字节数
 * @param alignment 对其要求
 * @return void* 内存地址
 */
[[nodiscard]] void *From_Right_to_Left operator new[](STD size_t size, STD align_val_t alignment)
{
    return operator new(size, alignment);
};

/**
 * @brief 为 new[] 表达式的不抛出数组形式所调用。
 * 
 * @param size 字节数
 * @param nothrow 无异常标记
 * @return void* 内存地址
 */
[[nodiscard]] void *From_Right_to_Left operator new[](STD size_t size, const STD nothrow_t &nothrow) noexcept
{
    return operator new(size, nothrow);
}

/**
 * @brief 在数组元素的对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 时为 new[] 表达式的不抛出数组形式所调用。
 * 
 * @param size 字节数
 * @param alignment 对其要求
 * @param nothrow 无异常标记
 * @return void* 内存地址
 */
[[nodiscard]] void *From_Right_to_Left operator new[](STD size_t size, STD align_val_t alignment, const STD nothrow_t &nothrow) noexcept
{
    return operator new(size, alignment, nothrow);
};

/**
 * @brief 为 delete[] 表达式所调用，以解分配先前为对象数组分配的存储。
 * 
 * @param ptr 内存地址
 */
void From_Right_to_Left operator delete[](void *ptr) noexcept
{
    operator delete(ptr);
};

/**
 * @brief 为 delete 表达式所调用，以解分配先前为单对象分配的存储。
 * 
 * @param ptr 内存指针
 * @param size 字节数
 */
void From_Right_to_Left operator delete[](void *ptr, STD size_t size) noexcept
{
    operator delete(ptr, size);
};

/**
 * @brief 除了若对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 才被调用
 * 
 * @param ptr 内存地址
 * @param alignment 对其要求
 */
void From_Right_to_Left operator delete[](void *ptr, STD align_val_t alignment) noexcept
{
    operator delete(ptr, alignment);
};

/**
 * @brief 除了若对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 才被调用
 * 
 * @param ptr 内存地址
 * @param alignment 对其要求
 */
void From_Right_to_Left operator delete[](void *ptr, STD size_t size, STD align_val_t alignment) noexcept
{
    operator delete(ptr, size, alignment);
};

/**
 * @brief 若对象的构造函数抛出异常，则为不抛出的单对象 new 表达式所调用。标准库实现表现同 (1)
 * 
 * @param ptr 内存指针
 * @param nothrow 无异常标记
 */
void From_Right_to_Left operator delete[](void *ptr, const STD nothrow_t &nothrow) noexcept
{
    operator delete(ptr, nothrow);
};

/**
 * @brief 除了若对齐要求超出 __STDCPP_DEFAULT_NEW_ALIGNMENT__ 才被调用
 * 
 * @param ptr 内存地址
 * @param alignment 对其要求
 * @param nothrow 无异常标记
 */
void From_Right_to_Left operator delete[](void *ptr, STD align_val_t alignment, const STD nothrow_t &nothrow) noexcept
{
    operator delete(ptr, alignment, nothrow);
};

#ifdef NOT_HAS_STL
/**
 * @brief 为标准单对象布置 new 表达式所调用，
 * 
 * @param size 字节数
 * @param ptr 内存指针
 * @return void* 内存指针
 */
[[nodiscard]] void *From_Right_to_Left operator new(STD size_t size, void *ptr) noexcept
{
    std::cout << "placement new: " << ptr << std::endl;
    return ptr;
};

/**
 * @brief 为标准单对象布置 new[] 表达式所调用，
 * 
 * @param size 字节数
 * @param ptr 内存指针
 * @return void* 内存指针
 */
[[nodiscard]] void *From_Right_to_Left operator new[](STD size_t size, void *ptr) noexcept
{
    std::cout << "placement new: " << ptr << std::endl;
    return ptr;
};

void operator delete(void *ptr, void *) noexcept;
void operator delete[](void *ptr, void *) noexcept;
#endif //NOT_HAS_STL
#endif //NEW_HPP