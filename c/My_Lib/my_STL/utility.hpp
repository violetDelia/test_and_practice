#pragma once
#ifndef UTILITY_HPP
#define UTILITY_HPP
#include "my_STL/my_help.hpp"
#include "my_STL/type_traits.hpp"
namespace my_std
{

    /**
    * @brief 转发类型
    * 
    * @tparam T 类型
    * @param t 要转发的对象
    */
    template <class T>
    constexpr T &&forward(remove_reference_t<T> &t) noexcept
    {
        return static_cast<T &&>(t);
    };

    /**
 * @brief /**
 * @brief 转发参数
 * 
 * @tparam T 类型
 * @param t 要转发的参数
 */
    template <class T>
    constexpr T &&forward(remove_reference_t<T> &&t) noexcept
    {
        static_assert(!is_lvalue_reference_v<T>, "bad forward call");
        return static_cast<T &&>(t);
    };

    /**
 * @brief 获取右值引用
 * 
 * @tparam T 类型
 */
    template <class T>
    typename add_rvalue_reference<T>::type declval() noexcept;

}
#endif //UTILITY_HPP