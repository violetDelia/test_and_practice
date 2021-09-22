
#pragma once
#ifndef MEMORY_RESOURCE_HPP
#define MEMORY_RESOURCE_HPP
#include "my_STL/cstddef.hpp"
#include "my_STL/limits.hpp"
#include "my_STL/my_help.hpp"
#include "my_STL/new.hpp"
//#include <vcruntime_new.h>
/**/
#include <iostream>
/**/
namespace STD pmr
{

    /** 用于各种封装内存资源的类 */
    class memory_resource
    {
    public:
        /*默认构造函数*/
        memory_resource()
        {
            std::cout << "memory_resource created: " << this << "   size:" << sizeof(*this) << std::endl;
        };

        /*默认复制构造函数*/
        memory_resource(const memory_resource &_other)
        {
            std::cout << "memory_resource copied" << this << "   size:" << sizeof(*this) << std::endl;
        };

        /*析构函数*/
        virtual ~memory_resource()
        {
            std::cout << "memory_resource destoried" << this << "   size:" << sizeof(*this) << std::endl;
        };

        /*默认赋值函数*/
        memory_resource &operator=(const memory_resource &_other)
        {
            std::cout << "memory_resource copied" << this << "   size:" << sizeof(*this) << std::endl;
            return *this;
        };

        /**
         * @brief 分配内存
         * 
         * @param bytes 字节数
         * @param alignment 对其要求
         */
        [[nodiscard]] void *allocate(STD size_t bytes, STD size_t alignment = alignof(STD max_align_t))
        {
            if (STD _is_pow_of_2(alignment))
            {
                std::cout << "对其要求不是2的幂" << std ::endl;
                return nullptr;
            }
            return do_allocate(bytes, alignment);
        };

        /**
         * @brief 解分配内存
         * 
         * @param p 内存指针
         * @param bytes 字节数
         * @param alignment 对其要求
         */
        void deallocate(void *p, size_t bytes, size_t alignment = alignof(max_align_t))
        {
            if (STD _is_pow_of_2(alignment))
            {
                std::cout << "it is not pow of 2" << std ::endl;
                return;
            }
            return do_deallocate(p, bytes, alignment);
        };

        /**
         * @brief 判断分配器是否相同
         * 
         * @param other 另一个分配器e 
         */
        bool is_equal(const memory_resource &other) const noexcept
        {
            return do_is_equal(other);
        };

    private:
        /**
         * @brief 分配内存
         * 
         * @param bytes 字节数
         * @param alignment 对其要求
         */
        virtual void *do_allocate(STD size_t bytes, STD size_t alignment)
        {
            if (alignment > __STDCPP_DEFAULT_NEW_ALIGNMENT__)
            {
                return operator new (bytes, STD align_val_t{(STD align_val_t)alignment});
            }
            return operator new(bytes);
        };

        /**
         * @brief 解分配内存
         * 
         * @param p 内存指针
         * @param bytes 字节数
         * @param alignment 对其要求
         */
        virtual void do_deallocate(void *p, size_t bytes, size_t alignment)
        {
            if (alignment > __STDCPP_DEFAULT_NEW_ALIGNMENT__)
            {
                return operator delete (p, bytes, STD align_val_t{(STD align_val_t)alignment});
            }
            operator delete(p, bytes);
        };

        /**
         * @brief 判断 memory_resource 是否相同
         * 
         * @param other 另一个 memory_resource
         */
        virtual bool do_is_equal(const memory_resource &other) const noexcept
        {
            return this == &other;
        };
    }; //memory_resource

    //memory_resource *_default_memory_resource = new memory_resource();

    /**
    * @brief 返回指向使用全局 operator new 与 operator delete 分配内存的 memory_resource 的指针。
    * 
    */
    memory_resource *new_delete_resource() noexcept
    {
        //return static_cast<memory_resource *>(operator new(static_cast<STD size_t>(sizeof(memory_resource))));
        void *address = operator new(static_cast<STD size_t>(sizeof(memory_resource)));
        return new (address) memory_resource();
    };

    memory_resource *get_default_resource() noexcept
    {
        return new_delete_resource();
    };

    template <class T>
    class polymorphic_allocator
    {
    private:
        /** allocator resource*/
        memory_resource *memory_rsrc = get_default_resource();

        /** destructor */

    public:
        using value_type = T;

        /** constructor */
        polymorphic_allocator() noexcept
        {

            std::cout << "polymorphic_allocator created: " << this << "   size:" << sizeof(*this) << std::endl;
        };

        /** constructor */
        polymorphic_allocator(memory_resource *r) : memory_rsrc(r)
        {
            std::cout << "polymorphic_allocator created: " << this << "   size:" << sizeof(*this) << std::endl;
        };

        /** copy constructor */
        polymorphic_allocator(const polymorphic_allocator &_other) : memory_rsrc(_other.resource())
        {
            std::cout << "polymorphic_allocator copied: " << this << "   size:" << sizeof(*this) << std::endl;
        };

        /** copy constructor */
        template <class U>
        polymorphic_allocator(const polymorphic_allocator<U> &_other) noexcept : memory_rsrc(_other.resource())
        {
            std::cout << "polymorphic_allocator copied: " << this << "   size:" << sizeof(*this) << std::endl;
        };

        /** destructor */
        ~polymorphic_allocator()
        {
            std::cout << "polymorphic_allocator distoried: " << this << "   size:" << sizeof(*this) << std::endl;
        }

        /**
         * @brief 用底层的 memory_resource 分配 n 个 T 类型对象的存储。
         * 
         * @param n 个数
         * @return Tp* 
         */
        [[nodiscard]] T *allocate(size_t n)
        {
            if (n > numeric_limits<T>::max() / sizeof(T))
                throw new bad_array_new_length();
            return static_cast<T *>(resource()->allocate(n + sizeof(T), alignof(T)));
        };

        /**
        * @brief 解分配 p 所指向的存储。
        * 
        * @param p 内存指针
        * @param n 个数
        */
        void deallocate(T *p, size_t n)
        {
            resource()->deallocate(p, n * sizeof(T), alignof(T));
        };

        /**
         * @brief 分配按指定 alignment 对齐的 nbytes 字节存储。
         * 
         * @param nbytes 字节数
         * @param alignment 对其要求
         * @return void* 内存地址
         */
        [[nodiscard]] void *allocate_bytes(size_t nbytes, size_t alignment = alignof(max_align_t))
        {
            return resource()->allocate(nbytes, alignment);
        };

        /**
         * @brief 解分配 p 所指向的存储
         * 
         * @param p 指针    
         * @param nbytes 字节数
         * @param alignment 对其要求
         */
        void deallocate_bytes(void *p, size_t nbytes, size_t alignment = alignof(max_align_t))
        {
            resource()->deallocate(p, nbytes, alignment);
        };

        /**
         * @brief 用底层内存资源分配 n 个 T 类型对象的存储。
         * 
         * @return T* 内存地址
         */
        template <class Ty>
        [[nodiscard]] Ty *allocate_object(size_t n = 1)
        {
            if (n > numeric_limits<Ty>::max() / sizeof(Ty))
                throw new bad_array_new_length();
            return static_cast<T *>(resource()->allocate(n * sizeof(T), alignof(T)));
        };

        /**
         * @brief 解分配 p 所指向的存储，
         * 
         * @tparam T 类型
         * @param p 内存地址
         * @param n 数量
         */
        template <class Ty>
        void deallocate_object(Ty *p, size_t n = 1)
        {
            resource()->deallocate(p, n * sizeof(T), alignof(T));
        };

        /**
         * @brief 分配并构造 U 类型对象。
         * 
         * @tparam T 类型
         * @tparam CtorArgs 对象参数类型
         * @param ctor_args 对象参数
         * @return T* 内存地址
         */
        template <class Ty, class... CtorArgs>
        [[nodiscard]] Ty *new_object(CtorArgs &&...ctor_args)
        {
            Ty *p = allocate_object<Ty>();
            try
            {
                construct(p, forward<CtorArgs>(ctor_args)...);
            }
            catch (...)
            {
                deallocate_object(p);
                throw;
            }
            return p;
        };

        /**
         * @brief 销毁 U 类型对象并解分配为它分配的存储。
         * 
         * @tparam T 类型   
         * @param p 内存地址
         */
        template <class Ty>
        void delete_object(Ty *p)
        {
            deallocate_object(p);
        };

        template <class Ty, class... Args>
        void construct(Ty *p, Args &&...args){
            
        };


        polymorphic_allocator select_on_container_copy_construction() const
        {
            return {};
        };

        /**
         * @brief 内存工具
         * 
         * @return memory_resource* 指针
         */
        memory_resource *resource() const
        {
            return memory_rsrc;
        };
    };
}//namespace STD pmr
#endif //MEMORY_RESOURCE_HPP