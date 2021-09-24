#pragma once
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "my_STL/my_help.hpp"
#include "my_STL/type_traits.hpp"

/**/
#include <iostream>
/**/

MY_STL_namespace_begin

    /** 遗留输入迭代器标签 */
    struct input_iterator_tag
{
};

/** 遗留输出迭代器标签 */
struct output_iterator_tag
{
};

/** 遗留向前迭代器标签 */
struct forward_iterator_tag : public input_iterator_tag
{
};

/** 遗留双向迭代器标签 */
struct bidirectional_iterator_tag : public forward_iterator_tag
{
};

/** 遗留随机访问迭代器标签 */
struct random_access_iterator_tag : public bidirectional_iterator_tag
{
};

/** 遗留连续迭代器标签 */
struct contiguous_iterator_tag : public random_access_iterator_tag
{
};

/** 
 ** @brief 迭代器
 * 
 * @tparam Category 迭代器标签
 * @tparam T 类型
 * @tparam Distance 最大长度
 * @tparam Pointer 类型指针
 * @tparam &Reference 类型引用
 */
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
struct iterator
{
    using iterator_category = Category;
    using value_type = T;
    using difference_type = Distance;
    using pointer = Pointer;
    using reference = Reference;
};

/**
 * @brief 迭代器特征
 * 
 * @tparam I 迭代器
 */
template <class I>
struct iterator_traits
{
    using iterator_category = typename I::iterator_category;
    using value_type = typename I::value_type;
    using difference_type = typename I::difference_type;
    using pointer = typename I::pointer;
    using reference = typename I::reference;
};

/**
 * @brief 特化迭代器特征
 * 
 * @tparam T 一个对象
 */
template <class T>
#ifdef REQUIRES
requires is_object<T>::value
#endif //REQUIRES
    struct iterator_traits<T *>
{
    using iterator_concept = contiguous_iterator_tag;
    using iterator_category = random_access_iterator_tag;
    using value_type = remove_cv_t<T>;
    using difference_type = ptrdiff_t;
    using pointer = T *;
    using reference = T &;
};

template <class Iter>
using iter_reference_t = typename iterator_traits<Iter>::reference;

template <class Iter>
using iter_difference_t = typename iterator_traits<Iter>::difference_type;

template <class Iter>
using iter_value_t = typename iterator_traits<Iter>::value_type;

/**
 * @brief 反向迭代器
 * 
 * @tparam  base 迭代器
 */
template <class Iter>
class reverse_iterator
{
public:
    using iterator_type = Iter;
#ifdef CPLUSPLUS20
//using iterator_concept =
#endif //CPLUSPLUS20
    using iterator_category = typename iterator_traits<Iter>::iterator_category;
    using value_type = iter_value_t<Iter>;
    using difference_type = iter_difference_t<Iter>;
    using pointer = typename iterator_traits<Iter>::pointer;
    using reference = iter_reference_t<Iter>;

    /** 默认构造函数 */
    constexpr reverse_iterator()
    {
        std::cout << "reverse_iterator created: " << this << "   size:" << sizeof(*this) << std::endl;
    };

    /**
     * @brief 以 x 为 base 的构造函数
     * 
     */
    constexpr explicit reverse_iterator(Iter x) : current(move(x))
    {
        std::cout << "reverse_iterator created: " << this << "   size:" << sizeof(*this) << std::endl;
    };

    /**
     * @brief 复制构造函数
     *  
     * @tparam U 同类型的迭代器
     */
    template <class U>
    constexpr reverse_iterator(const reverse_iterator<U> &u) : current(u.base())
    {
        std::cout << "reverse_iterator copied: " << this << "   size:" << sizeof(*this) << std::endl;
    };

    /* 赋值运算符重载 */
    template <class U>
    constexpr reverse_iterator &operator=(const reverse_iterator<U> &u)
    {
        this->current = u.base();
        return *this;
    };

    /* 访问底部迭代器 */
    constexpr Iter base() const
    {
        return current;
    };

    /* 访问指向的元素 */
    constexpr reference operator*() const
    {
        Iter tmp = current;
        return *--tmp;
    };

    /* 访问指向的元素 */
    constexpr pointer operator->() const
#ifdef REQUIRES
        requires(is_pointer_v<Iter> ||
                 requires(const Iter i) { i.operator->(); });
#endif //REQUIRES
    {
        return addressof(operator*());
    };

    /* 前自增重载 */
    constexpr reverse_iterator &operator++()
    {
        --current;
        return *this;
    };

    /* 后自增重载 */
    constexpr reverse_iterator operator++(int)
    {
        reverse_iterator _temp = *this;
        --current;
        return _temp;
    };

    /* 前自减重载 */
    constexpr reverse_iterator &operator--()
    {
        ++current;
        return *this;
    };

    /* 后自减重载 */
    constexpr reverse_iterator operator--(int)
    {
        reverse_iterator _temp = *this;
        ++current;
        return _temp;
    };

    /* 返回向前 n 个位置的迭代器 */
    constexpr reverse_iterator operator+(difference_type n) const
    {
        return reverse_iterator(current - n);
    };

    /* 迭代器向前 n 个位置 */
    constexpr reverse_iterator &operator+=(difference_type n)
    {
        current -= n;
        return *this;
    };

    /* 返回向后 n 个位置的迭代器 */
    constexpr reverse_iterator operator-(difference_type n) const
    {
        return reverse_iterator(current + n);
    };

    /* 迭代器向后 n 个位置 */
    constexpr reverse_iterator &operator-=(difference_type n)
    {
        current += n;
        return *this;
    };

    /* 按索引访问元素 */
    constexpr operator[](difference_type n) const
    {
        return current[static_cast<difference_type>(-n - 1)];
    };
#ifdef CPLUSPLUS20
    friend constexpr iter_rvalue_reference_t<Iter>
    iter_move(const reverse_iterator &i) noexcept();
    template <indirectly_swappable<Iter> Iter2>
    friend constexpr void
    iter_swap(const reverse_iterator &x,
              const reverse_iterator<Iter2> &y) noexcept();
#endif //CPLUSPLUS20

protected:
    Iter current;
};

MY_STL_namespace_end
#endif //ITERATOR_HPP