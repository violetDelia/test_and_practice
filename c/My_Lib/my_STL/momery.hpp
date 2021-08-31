#pragma once
#ifndef MEMORY_HPP
#define MEMORY_HPP
#include "my_STL/cstddef.hpp"
#include "my_STL/new.hpp"
#include "my_STL/type_traits.hpp"
/**/
#include <iostream>
#include <new>
/**/
namespace my_std
{

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
     * @brief 
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
     * @brief 从指针获取数据类型
     * 
     * @tparam Ptr 指针
     */
    template <class Ptr>
    struct _get_type_of_pointer;

    /**
     * @brief 从指针获取数据类型
     * 
     * @tparam Ptr 指针
     * @tparam T 数据类型
     * @tparam _start 星号
     */
    template <template <class, class...> class Ptr, class T, class... _start>
    struct _get_type_of_pointer<Ptr<T, _start...>>
    {
        using type = T;
    };

    /**
     * @brief 转换指针
     * 
     * @tparam Ptr 原指针
     * @tparam newType 新的类型
     */
    template <class newType, class Ptr>
    struct _rebind_pointer;

    /**
     * @brief 转换指针
     * 
     * @tparam newType 新的类型
     * @tparam Ptr 原指针
     * @tparam T 原指针类型
     * @tparam _start 星号
     */
    template <class newType, template <class, class...> class Ptr, class T, class... _start>
    struct _rebind_pointer<newType, Ptr<T, _start...>>
    {
        using newPtr = Ptr<newType, _start...>;
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
        using element_type = typename _get_type_of_pointer<Ptr>::type;
        using difference_type = ptrdiff_t;
        template <class U>
        using rebind = typename _rebind_pointer<U, Ptr>::newPtr;
        using _reference_of_element_type = conditional_t<is_void_v<element_type>, char, element_type> &;

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
        my_std::size_t _allocate_size = _get_size<sizeof(T)>(n);
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
            std::cout << "allocator created" << std::endl;
        }

        /**
         * @brief allocator 复制构造函数
         * 
         */
        constexpr allocator(const allocator &) noexcept
        {
            std::cout << "allocator coyied" << std::endl;
        }

        /**
         * @brief allocator 复制构造函数
         * 
         * @tparam U 数据类型
         */
        template <class U>
        constexpr allocator(const allocator<U> &) noexcept
        {
            std::cout << "allocator coyied" << std::endl;
        }

        /**
         * @brief allocator 析构函数
         * 
         */
        ~allocator()
        {
            std::cout << "allocator destoried" << std::endl;
        }

        /**
         * @brief 默认赋值运算
         * 
         * @return allocator& 引用
         */
        allocator &operator=(const allocator &) = default;

        /**
         * @brief 分配内存
         * 
         * @param n 数量
         * @return T* 内存指针（数据类型指针）
         */
        [[nodiscard]] T *allocate(size_t n)
        {
            return _allocate(n, (T *)(0));
        }

        /**
         * @brief 清除已分配的内存（必须是通过allocate <T>（n）分配的）
         * 
         * @param p 内存指针（数据类型指针）
         * @param n 数量
         */
        void deallocate(T *p, size_t n)
        {
            return _deallocate<T>(p, sizeof(T) * n);
        }
    }; //allocator

    template <class Alloc>
    struct allocator_traits
    {
        using allocator_type = Alloc;

        using value_type = typename Alloc::value_type;

        using pointer = typename pointer_traits<value_type>::pointer;
        using const_pointer = typename pointer_traits<pointer>::rebind<const value_type>;
        using void_pointer = typename pointer_traits<pointer>::rebind<void>;
        using const_void_pointer = typename pointer_traits<pointer>::rebind<const void>;

        using difference_type = typename Alloc ::difference_type;
        using size_type = typename Alloc ::size_type;

        using propagate_on_container_copy_assignment = typename false_type;
        using propagate_on_container_move_assignment = typename Alloc::propagate_on_container_move_assignment;
        using propagate_on_container_swap = typename false_type;
        ;
        using is_always_equal = typename Alloc::is_always_equal;

        template <class T>
        using rebind_alloc = typename allocator_type<T>;
        template <class T>
        using rebind_traits = allocator_traits<rebind_alloc<T>>;

        [[nodiscard]] static pointer allocate(Alloc &a, size_type n)
        {
            return a.allocate(n);
        };
        [[nodiscard]] static pointer allocate(Alloc &a, size_type n, const_void_pointer hint)
        {
            if constexpr (false) //暂时无此函数
            {
                return a.allocate(n, hint);
            }
            else
            {
                return a.allocate(n);
            }
        };

        static void deallocate(Alloc &a, pointer p, size_type n)
        {
             a.deallocate(p, n);
        };

        template <class T, class... Args>
        static void construct(Alloc &a, T *p, Args &&...args){

        };

        template <class T>
        static void destroy(Alloc &a, T *p);

        static size_type max_size(const Alloc &a) noexcept;

        static Alloc select_on_container_copy_construction(const Alloc &rhs);
    };

} //namespace
#endif //MEMORY_HPP