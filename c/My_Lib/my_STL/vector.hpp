#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "my_STL/iterator.hpp"
#include "my_STL/momery.hpp"
MY_STL_namespace_begin

    /* 声明 */
    template <class Pointer>
    class _vector_iterator;
/* 声明 */

/**
     * @brief 获取该分配器的邻近分配器
     * 
     * @tparam _alloc 分配器
     * @tparam _ty 类型
     */
template <class _alloc, class _ty>
using _get_rebind_alloc = typename allocator_traits<_alloc>::template rebind_alloc<_ty>;

/**
 * @brief 容器
 * 
 * @tparam T 类型
 * @tparam Allocator 分配器
 */
template <class T, class Allocator = allocator<T>>
class vector
{
private:
    using _Allocator = _get_rebind_alloc<Allocator, T>;
    using _Allocator_traits = allocator_traits<_Allocator>;

public:
    // 类型
    using value_type = T;
    using allocator_type = Allocator;
    using pointer = typename _Allocator_traits::pointer;
    using const_pointer = typename _Allocator_traits::const_pointer;
    using reference = value_type &;
    using const_reference = const value_type &;
    using size_type = typename _Allocator_traits::size_type;
    using difference_type = typename _Allocator_traits::difference_type;
    using iterator = _vector_iterator<T>;
    //using const_iterator = ;
    using reverse_iterator = reverse_iterator<iterator>;
    //using const_reverse_iterator = reverse_iterator<const_iterator>;

    // 构造/复制/销毁
    //constexpr vector() noexcept(noexcept(Allocator())) : vector(Allocator()) {}
    //constexpr explicit vector(const Allocator &) noexcept {};
    constexpr explicit vector(size_type n, const Allocator &allocator = Allocator()) : _vector_allocator(allocator), _vector_capacity(n)
    {
        _vector_begin = _vector_allocator.allocate(n);
        _vector_end = _vector_begin;
        _vector_capacity_fill = _vector_begin + _vector_capacity;
    };
    constexpr vector(size_type n, const T &value, const Allocator &allocator = Allocator()) : _vector_allocator(allocator), _vector_capacity(n)
    {
        _vector_begin = _vector_allocator.allocate(n);
        _vector_end = _fill_value(_vector_begin, n, value);
        _vector_capacity_fill = _vector_begin + _vector_capacity;
    };

    constexpr value_type *_fill_value(value_type *begin, size_type n, const T &value)
    {
        iterator it(_vector_begin);
    };
    //template <class InputIt>
    //constexpr vector(InputIt first, InputIt last, const Allocator & = Allocator());
    //constexpr vector(const vector &x);
    //constexpr vector(vector &&) noexcept;
    //constexpr vector(const vector &, const Allocator &);
    //constexpr vector(vector &&, const Allocator &);
    //constexpr vector(initializer_list<T>, const Allocator & = Allocator());
    //constexpr ~vector();
    //constexpr vector &operator=(const vector &x);
    //constexpr vector &operator=(vector &&x) noexcept(allocator_traits<Allocator>::propagate_on_container_move_assignment::value ||
    //                                                allocator_traits<Allocator>::is_always_equal::value);
    //constexpr vector &operator=(initializer_list<T>);
    //template <class InputIt>
    //constexpr void assign(InputIt first, InputIt last);
    //constexpr void assign(size_type n, const T &u);
    //constexpr void assign(initializer_list<T>);
    //constexpr allocator_type get_allocator() const noexcept;

    // 迭代器
    constexpr iterator begin() noexcept
    {
        return iterator(_vector_begin);
    };
    //constexpr const_iterator begin() const noexcept;
    //constexpr iterator end() noexcept;
    //constexpr const_iterator end() const noexcept;
    //constexpr reverse_iterator rbegin() noexcept;
    //constexpr const_reverse_iterator rbegin() const noexcept;
    //constexpr reverse_iterator rend() noexcept;
    //constexpr const_reverse_iterator rend() const noexcept;

    //constexpr const_iterator cbegin() const noexcept;
    //constexpr const_iterator cend() const noexcept;
    //constexpr const_reverse_iterator crbegin() const noexcept;
    //constexpr const_reverse_iterator crend() const noexcept;

    // 容量
    //[[nodiscard]] constexpr bool empty() const noexcept;
    //constexpr size_type size() const noexcept;
    //constexpr size_type max_size() const noexcept;
    //constexpr size_type capacity() const noexcept;
    //constexpr void resize(size_type sz);
    //constexpr void resize(size_type sz, const T &c);
    //constexpr void reserve(size_type n);
    //constexpr void shrink_to_fit();

    // 元素访问
    //constexpr reference operator[](size_type n);
    //constexpr const_reference operator[](size_type n) const;
    //constexpr const_reference at(size_type n) const;
    //constexpr reference at(size_type n);
    //constexpr reference front();
    //constexpr const_reference front() const;
    //constexpr reference back();
    //constexpr const_reference back() const;

    // 数据访问
    //constexpr T *data() noexcept;
    //constexpr const T *data() const noexcept;

    // 修改器
    //template <class... Args>
    //constexpr reference emplace_back(Args &&...args);
    //constexpr void push_back(const T &x);
    //constexpr void push_back(T &&x);
    //constexpr void pop_back();

    //template <class... Args>
    //constexpr iterator emplace(const_iterator position, Args &&...args);
    //constexpr iterator insert(const_iterator position, const T &x);
    //constexpr iterator insert(const_iterator position, T &&x);
    // constexpr iterator insert(const_iterator position, size_type n, const T &x);
    // template <class InputIt>
    // constexpr iterator insert(const_iterator position,
    //                           InputIt first, InputIt last);
    // constexpr iterator insert(const_iterator position, initializer_list<T> il);
    // constexpr iterator erase(const_iterator position);
    // constexpr iterator erase(const_iterator first, const_iterator last);
    // constexpr void swap(vector &) noexcept(allocator_traits<Allocator>::propagate_on_container_swap::value ||
    //                                        allocator_traits<Allocator>::is_always_equal::value);
    // constexpr void clear() noexcept;
private:
    value_type *_vector_begin;
    value_type *_vector_end;
    value_type *_vector_capacity_fill;
    size_type _vector_capacity;
    Allocator _vector_allocator;

    Allocator &_get_alloctor()
    {
        return &_vector_allocator;
    }
};

/**
 * @brief vector 迭代器
 * 
 * @tparam Pointer 指针
 */
template <class T>
class _vector_iterator
{
    using _base_iterator = iterator<random_access_iterator_tag, T>;
    using _iterator_traits = iterator_traits<_base_iterator>;

public:
    using iterator_category = typename _iterator_traits::iterator_category;
    using value_type =typename _iterator_traits::value_type;
    using difference_type =typename _iterator_traits::difference_type;
    using pointer =typename _iterator_traits::pointer;
    using reference = typename _iterator_traits::reference;

public:
    _vector_iterator(pointer address) : position(address){};

protected:
    pointer position;
};

MY_STL_namespace_end
#endif //VECTOR_HPP