#pragma once
#ifndef MEMORY_HPP
#define MEMORY_HPP
#include "my_STL/cstddef.hpp"
#include "my_STL/limits.hpp"
#include "my_STL/my_help.hpp"
#include "my_STL/new.hpp"
#include "my_STL/type_traits.hpp"
#include "my_STL/utility.hpp"
/**/
#include <iostream>
/**/
MY_STL_namespace_begin

    /**
     * @brief 获得对象或函数 arg 的实际地址，即使存在 operator& 的重载
     * 
     * @tparam T 类型
     * @param arg 左值对象或函数
     * @return enable_if<is_object<T>::value, T *>::type 指向arg的指针
     */
    template <class T>
    typename enable_if<is_object<T>::value, T *>::type addressof(T &arg) noexcept
{
    return reinterpret_cast<T *>(
        &const_cast<char &>(
            reinterpret_cast<const volatile char &>(arg)));
}

/**
 * @brief 获得对象或函数 arg 的实际地址，即使存在 operator& 的重载
 * 
 * @tparam T 
 * @param arg 
 * @return std::enable_if<!std::is_object<T>::value, T *>::type 
 */
template <class T>
typename enable_if<!is_object<T>::value, T *>::type addressof(T &arg) noexcept
{
    return &arg;
}

/**
 * @brief 调用 p 所指向对象的析构函数
 * 
 * @tparam T 类型
 * @param p 指向要被销毁的对象的指针
 */
template <class T>
constexpr void destroy_at(T *p)
{
    if Constexpr (is_array_v<T>)
        for (auto &elem : *p)
            (destroy_at)(addressof(elem));
    else
        p->~T();
}

/**
 * @brief 获取类型的第一个参数
 * 
 * @tparam _Type 类型
 */
template <class _Type>
struct _get_first_parameter;

/**
 * @brief 获取类型的第一个参数
 *  
 * @tparam _Type 类型
 * @tparam _first 第一个参数
 * @tparam _next 后面的参数
 */
template <template <class, class...> class _Type, class _first, class... _next>
struct _get_first_parameter<_Type<_first, _next...>>
{
    using type = _first;
};

/**
 * @brief 替换类型的第一个参数
 * 
 * @tparam _newFirst 新的第一个参数
 * @tparam _Type 原类型
 */
template <class _newFirst, class _Type>
struct _replace_first_parameter;

/**
 * @brief 替换类型的第一个参数
 * 
 * @tparam _newFirst 新的第一个参数
 * @tparam _Type 原类型
 * @tparam _first 原类型的第一个参数
 * @tparam _next 原类型后面的参数
 */
template <class _newFirst, template <class, class...> class _Type, class _first, class... _next>
struct _replace_first_parameter<_newFirst, _Type<_first, _next...>>
{
    using type = _Type<_newFirst, _next...>;
};

/**
 * @brief 为 pointer_traits 获取 element_type
 * 
 * @tparam Ptr 指针
 */
template <class _Ptr>
struct _get_element_type
{
    using type = typename _get_first_parameter<_Ptr>::type;
};

/**
 * @brief 为 pointer_traits 获取 rebind
 * 
 * @tparam _Ptr 原指针
 * @tparam _U 新指针的类型
 */
template <class _Ptr, class _U>
struct _get_rebind
{
    using type = typename _replace_first_parameter<_U, _Ptr>::type;
};

/**
    * @brief 指针特性类
    * 
    * @tparam Ptr 指针
    */
template <class Ptr>
struct pointer_traits
{
    using pointer = Ptr;
    using element_type = typename _get_element_type<Ptr>::type;
    using difference_type = ptrdiff_t;
    template <class U>
    using rebind = typename _get_rebind<U, Ptr>::type;
    using _reference_of_element_type =  conditional_t<is_void_v<element_type>, char, element_type> &;

    /**
         * @brief 指向 r 的可解引用指针
         * 
         */
    static pointer pointer_to(_reference_of_element_type r)
    {
        return Ptr::pointer_to(r);
    };
};

/**
     * @brief 指针特性类(特化)
     * 
     * @tparam T 类型
     */
template <class T>
struct pointer_traits<T *>
{
    using pointer = T *;
    using element_type = T;
    using difference_type = ptrdiff_t;
    template <class U>
    using rebind = U *;
    using _reference_of_T = conditional_t<is_void_v<T>, char, T> &;

    /**
         * @brief 指向 r 的可解引用指针
         * 
         */
    static constexpr pointer pointer_to(_reference_of_T r) noexcept
    {
        return addressof(r);
    };
};

/**
 * @brief 需要的内存位数
 * 
 * @tparam size_of_type 数据类型的位数
 * @param n 需要数据个数
 * @return my_help::size_t 需要的内存位数
 */
template <size_t size_of_type>
inline constexpr size_t _get_size(const size_t n)
{
    constexpr bool _Overflow_is_possible = size_of_type > 1;
    if (_Overflow_is_possible)
    {
        constexpr size_t _Max_n = static_cast<size_t>(-1) / size_of_type;
        if (n > _Max_n)
        {
            throw bad_array_new_length();
        }
    }
    return n * size_of_type;
} //_get_size()

/**
    * @brief 分配内存
    * 
    * @tparam T 数据类型
    * @param n 数量
    * @return T* 内存指针（数据类型指针）
    */
template <class T>
inline T *_allocate(const size_t n, T *)
{
    size_t _allocate_size = _get_size<sizeof(T)>(n);
    return _allocate_size != 0 ? static_cast<T *>(::operator new(_allocate_size)) : nullptr;
} //_allocate()

/**
     * @brief 清除内存
     * 
     * @tparam T 数据类型
     * @param p 内存指针（数据类型指针）
     * @param n 内存位数
     */
template <class T>
inline void _deallocate(T *p, const size_t n)
{
    ::operator delete(p, n);
} // _deallocate

/**
     * @brief 内存分配器
     * 
     * @tparam T 数据类型
     */
template <class T>
class allocator
{
public:
    using value_type = T;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using propagate_on_container_move_assignment = true_type;
    using is_always_equal = true_type;

    /**
     * @brief allocator 构造函数
     * 
 */
    constexpr allocator() noexcept
    {
        std::cout << "allocator created: " << this << "   size:" << sizeof(*this) << std::endl;
    }

    /**
     * @brief allocator 复制构造函数
     * 
     */
    constexpr allocator(const allocator &) noexcept
    {
        std::cout << "allocator coyied: " << this << "   size:" << sizeof(*this) << std::endl;
    }

    /**
     * @brief allocator 复制构造函数
     * 
     * @tparam U 数据类型
     */
    template <class U>
    constexpr allocator(const allocator<U> &_other) noexcept
    {
        std::cout << "allocator coyied: " << this << "   size:" << sizeof(*this) << std::endl;
    }

    /**
     * @brief allocator 析构函数
     * 
     */
    ~allocator()
    {
        std::cout << "allocator destoried: " << this << "   size:" << sizeof(*this) << std::endl;
    }

    /**
     * @brief 默认赋值运算
     * 
     * @return allocator& 引用
     */
    allocator &operator=(const allocator &_other)
    {
        if (_other != this)
        {
        }
        std::cout << "allocator coyied: " << this << "   size:" << sizeof(*this) << std::endl;
        return *this;
    };

    /**
         * @brief 分配内存
         * 
         * @param n 数量
         * @return T* 内存指针（数据类型指针）
         */
    [[nodiscard]] constexpr T *allocate(size_t n)
    {
        return _allocate(n, (T *)(0));
    }

    /**
         * @brief 清除已分配的内存（必须是通过allocate <T>（n）分配的）
         * 
         * @param p 内存指针（数据类型指针）
         * @param n 数量
         */
    void constexpr deallocate(T *p, size_t n)
    {
        return _deallocate<T>(p, sizeof(T) * n);
    }
}; //allocator

/**
 * @brief 为 allocator_traits 获取 pointer
 * 
 * @tparam _value_type 数据类型
 */
template <class _value_type>
struct _get_pointer
{
    using type = _value_type *;
};

/**
 * @brief 判断是否有hint为参数的allocate
 * 
 * @tparam _Alloc 分配器
 * @tparam _size_type 类型
 * @tparam _const_void_pointer 空指针
 */
template <class _Alloc, class _size_type, class _const_void_pointer, class = void>
struct _has_allocate_hint : false_type
{
};

/**
 * @brief 判断是否有hint为参数的allocate成员
 * 
 * @tparam _Alloc 分配器
 * @tparam _size_type 类型
 * @tparam _const_void_pointer 空指针
 */
template <class _Alloc, class _size_type, class _const_void_pointer>
struct _has_allocate_hint<_Alloc, _size_type, _const_void_pointer, void_t<decltype(declval<_Alloc &>().allocate(declval<_size_type &>(), declval<_const_void_pointer &>()))>> : true_type
{
};

/**
 * @brief 判断 分配器 有没有 construct 成员
 * 
 * @tparam _void 判断结果
 * @tparam _others 其他参数
 */
template <class _void, class... _others>
struct _has_construct : false_type
{
};

/**
 * @brief 判断 分配器 有没有 construct 成员
 * 
 * @tparam _Alloc 分配器
 * @tparam _Ptr 内存指针
 * @tparam _Args 其他参数
 */
template <class _Alloc, class _Ptr, class... _Args>
struct _has_construct<void_t<decltype(declval<_Alloc &>().construct(declval<_Ptr>(), declval<_Args>()...))>, _Alloc, _Ptr, _Args...> : true_type
{
};

/**
 * @brief 判断 分配器 有没有 destory 成员
 * 
 * @tparam _Alloc 分配器
 * @tparam _Ptr 内存指针 
 */
template <class _Alloc, class _Ptr, class = void>
struct _has_destory : false_type
{
};

/**
 * @brief 判断 分配器 有没有 destory 成员
 * 
 * @tparam _Alloc 分配器
 * @tparam _Ptr 内存指针 
 */
template <class _Alloc, class _Ptr>
struct _has_destory<_Alloc, _Ptr, void_t<decltype(declval<_Alloc &>().destory(declval<_Ptr>()))>> : true_type
{
};

/**
* @brief 判断 分配器 有没有 max_size 成员
* 
* @tparam _Alloc 分配器
*/
template <class _Alloc, class = void>
struct _has_max_size : false_type
{
};

/**
* @brief 判断 分配器 有没有 max_size 成员
* 
* @tparam _Alloc 分配器
*/
template <class _Alloc>
struct _has_max_size<_Alloc, void_t<decltype(declval<_Alloc &>().max_size())>> : true_type
{
};

/**
* @brief 判断 分配器 有没有 select_on_container_copy_construction 成员
* 
* @tparam _Alloc 分配器
*/
template <class _Alloc, class = void>
struct _has_select_on_container_copy_construction : false_type
{
};

/**
* @brief 判断 分配器 有没有 select_on_container_copy_construction 成员
* 
* @tparam _Alloc 分配器
*/
template <class _Alloc>
struct _has_select_on_container_copy_construction<_Alloc, void_t<decltype(declval<_Alloc &>().select_on_container_copy_construction())>> : true_type
{
};

/**
 * @brief 分配器特征
 * 
 * @tparam Alloc 分配器
 */
template <class Alloc>
struct allocator_traits
{
    using allocator_type = Alloc;

    using value_type = typename Alloc::value_type;

    using pointer = typename _get_pointer<value_type>::type;
    using const_pointer = typename pointer_traits<pointer>::template rebind<const value_type>;
    using void_pointer = typename pointer_traits<pointer>::template rebind<void>;
    using const_void_pointer = typename pointer_traits<pointer>::template rebind<const void>;

    using difference_type = typename Alloc ::difference_type;
    using size_type = typename Alloc ::size_type;

    using propagate_on_container_copy_assignment = false_type;
    using propagate_on_container_move_assignment = typename Alloc::propagate_on_container_move_assignment;
    using propagate_on_container_swap = false_type;
    using is_always_equal = typename Alloc::is_always_equal;

    template <class T>
    using rebind_alloc = allocator<T>;
    template <class T>
    using rebind_traits = allocator_traits<rebind_alloc<T>>;

    /**
     * @brief 用分配器 a 分配 n 个内存
     * 
     * @param a 分配器
     * @param n 类型数的个数
     * @return pointer 内存开始的地方
     */
    [[nodiscard]] static constexpr pointer allocate(Alloc &a, size_type n)
    {
        return a.allocate(n);
    };

    /**
     * @brief 用分配器 a 分配 n 个内存
     * 
     * @param a 分配器
     * @param n 类型数的个数
     * @return pointer 内存开始的地方
     */
    [[nodiscard]] static constexpr pointer allocate(Alloc &a, size_type n, const_void_pointer hint)
    {
        if Constexpr (_has_allocate_hint<Alloc, size_type, const_void_pointer>::value)
        {
            return a.allocate(n, hint);
        }
        else
        {
            return a.allocate(n);
        }
    };

    /**
     * @brief 用分配器 a 销毁 p 指向的 n 个内存
     * 
     * @param a 分配器
     * @param p 内存块开始的地方
     * @param n 内存长度（用allocate分配的）
     */
    static constexpr void deallocate(Alloc &a, pointer p, size_type n)
    {
        a.deallocate(p, n);
    };

    /**
     * @brief 在 p 所指向的通过allocate分配的的未初始化存储构造 T 类型对象
     * 
     * @tparam T 类型对象
     * @tparam Args 参数类型
     * @param a  分配器
     * @param p 内存起始点
     * @param args 参数
     */
    template <class T, class... Args>
    static constexpr void construct(Alloc &a, T *p, Args &&...args)
    {
        if Constexpr (_has_construct<Alloc, T *, Args...>::value)
        {
            a.construct(p, forward<Args>(args)...);
        }
        else
        {
            ::new (static_cast<void *>(p)) T(forward<Args>(args)...);
        }
    };

    /**
     * @brief 调用 p 所指向对象的析构函数。
     * 
     * @tparam T 类型
     * @param a 用于析构的分配器
     * @param p 指向要被销毁的对象的指针
     */
    template <class T>
    static constexpr void destroy(Alloc &a, T *p)
    {
        if Constexpr (_has_destory<Alloc, T *>::value)
        {
            a.destory(p);
        }
        else
        {
            destroy_at(p);
        }
    };

    /**
     * @brief 分配器最大理论分配大小
     * 
     * @param a 分配器
     * @return constexpr size_type 
     */
    static constexpr size_type max_size(const Alloc &a) noexcept
    {
        if Constexpr (_has_max_size<Alloc>::value)
        {
            return a.max_size();
        }
        else
        {
            return numeric_limits<size_type>::max() / sizeof(value_type);
        }
    };

    /**
     * @brief 调用分配器的复制构造函数
     * 
     * @param rhs 分配器
     * @return constexpr Alloc 新的分配器
     */
    static constexpr Alloc select_on_container_copy_construction(const Alloc &rhs)
    {
        if Constexpr (_has_select_on_container_copy_construction<Alloc>::value)
        {
            return rhs.select_on_container_copy_construction();
        }
        else
        {
            return rhs;
        }
    };
};

MY_STL_namespace_end
#endif //MEMORY_HPP