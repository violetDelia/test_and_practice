#pragma once
#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
#include "my_STL/cstddef.hpp"
#include "my_STL/my_help.hpp"
MY_STL_namespace_begin

    /**
     * @brief 检测输入的合法性以及成员是否存在
     * 
     * @tparam  输入
     */
    template <class...>
    using void_t = void;

/**
 * @brief 去除引用
 * 
 * @tparam T 引用
 */
template <class T>
struct remove_reference
{
     using type = T;
};

/**
 * @brief 去除引用
 * 
 * @tparam T 引用
 */
template <class T>
struct remove_reference<T &>
{
     using type = T;
};

/**
 * @brief 去除引用
 * 
 * @tparam T 引用
 */
template <class T>
struct remove_reference<T &&>
{
     using type = T;
};

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

/**
     * @brief 添加引用
     * 
     * @tparam T 添加引用的对象
     */
template <class T, class = void>
struct _add_reference
{
     using _Lvalue = T;
     using _Rvalue = T;
};

/**
     * @brief 添加引用
     * 
     * @tparam T 添加引用的对象
     */
template <class T>
struct _add_reference<T, void_t<T &>>
{
     using _Lvalue = T &;
     using _Rvalue = T &&;
};

/**
     * @brief 添加左值引用
     * 
     * @tparam T 添加引用的对象
     */
template <class T>
struct add_lvalue_reference
{
     using type = typename _add_reference<T>::_Lvalue;
};

template <class T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

/**
     * @brief 添加右值引用
     * 
     * @tparam T 添加引用的对象
     */
template <class T>
struct add_rvalue_reference
{
     using type = typename _add_reference<T>::_Rvalue;
};

template <class T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

/**
     * @brief 若 ！B 能无T,反之T为类型
     * 
     * @tparam B 判断
     * @tparam T 类型
     */
template <bool B, class T = void>
struct enable_if
{
};

/**
     * @brief 返回类型
     * 
     * @tparam T 类型
     */
template <class T>
struct enable_if<true, T>
{
     typedef T type;
};

template <bool B, class T = void>
using enable_if_t = typename enable_if<B, T>::type;

/**
     * @brief 提供成员 T
     * 
     * @tparam B bool
     * @tparam T B 在编译时为 true 则定义为 T
     * @tparam F B 为 false 则定义为 F
     */
template <bool B, class T, class F>
struct conditional
{
     typedef T type;
};

/**
     * @brief 提供成员 T
     * 
     * @tparam B bool
     * @tparam T B 在编译时为 true 则定义为 T
     * @tparam F B 为 false 则定义为 F
     */
template <class T, class F>
struct conditional<false, T, F>
{
     typedef F type;
};

template <bool B, class T, class F>
using conditional_t = typename conditional<B, T, F>::type;

/**
     * @brief 去除类型的限定符
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_cv
{
     typedef T type;
};

/**
     * @brief 去除类型的限定符
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_cv<const T>
{
     typedef T type;
};

/**
     * @brief 去除类型的限定符
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_cv<volatile T>
{
     typedef T type;
};

/**
     * @brief 去除类型的限定符
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_cv<const volatile T>
{
     typedef T type;
};

template <class T>
using remove_cv_t = typename remove_cv<T>::type;

/**
     * @brief 去除类型的const
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_const
{
     typedef T type;
};

/**
     * @brief 去除类型的const
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_const<const T>
{
     typedef T type;
};

template <class T>
using remove_const_t = typename remove_const<T>::type;

/**
     * @brief 去除类型的volatile
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_volatile
{
     typedef T type;
};

/**
     * @brief 去除类型的volatile
     * 
     * @tparam T 类型
     */
template <class T>
struct remove_volatile<volatile T>
{
     typedef T type;
};

template <class T>
using remove_volatile_t = typename remove_volatile<T>::type;

/**
     * @brief 变量的特征
     * 
     * @tparam T 类型
     * @tparam v 值
     */
template <class T, T v>
struct integral_constant
{
     static constexpr T value = v;
     using value_type = T;
     using type = integral_constant; // 使用注入类名
     constexpr operator value_type() const noexcept { return value; }
     constexpr value_type operator()() const noexcept { return value; } // C++14 起
};
template <bool B>
using bool_constant = integral_constant<bool, B>;
using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

/**
     * @brief 类型是否相同
     * 
     * @tparam T 不同的两个类型
     * @tparam U 不同的两个类型
     */
template <class T, class U>
struct is_same : false_type
{
};

/**
     * @brief 类型是否相同
     * 
     * @tparam T 两个类型相同
     * 
     */
template <class T>
struct is_same<T, T> : true_type
{
};

/**
     * @brief 两个类型是否相同
     * 
     * @tparam T 其中的一个类型
     * @tparam U 其中的另一个类型
     */
template <class T, class U>
Inline constexpr bool is_same_v = is_same<T, U>::value;

/**
     * @brief 返回第一个不为空的选项
     * 
     * @tparam  选项列表
     */
template <class...>
struct disjunction : false_type
{
};

/**
     * @brief 只有一个选项时返回此对象
     * 
     * @tparam B1 对象
     */
template <class B1>
struct disjunction<B1> : B1
{
};

/**
     * @brief 若B1为空，选取下一个对象
     * 
     * @tparam B1 首要判断的对象
     * @tparam Bn 之后的对象
     */
template <class B1, class... Bn>
struct disjunction<B1, Bn...>
    : conditional_t<bool(B1::value), B1, disjunction<Bn...>>
{
};

template <class... B>
Inline constexpr bool disjunction_v = disjunction<B...>::value;

template <class _Ty, class... _Types>
Inline constexpr bool _is_any_of_v = disjunction_v<is_same<_Ty, _Types>...>;

/**
     * @brief 检查T是否为整数类型
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_integral : bool_constant<_is_any_of_v<typename remove_cv<T>::type, bool, char, char16_t, char32_t, wchar_t, short, int, long, long long, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, signed char>>
{
};

template <class T>
Inline constexpr bool is_integral_v = is_integral<T>::value;

/**
     * @brief 检查T是否为浮点类型
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_floating_point : bool_constant<_is_any_of_v<remove_cv_t<T>, float, double, long double>>
{
};

template <class T>
Inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

/**
     * @brief 检查T是否为算术类型
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_arithmetic : bool_constant<is_integral<T>::value || is_floating_point<T>::value>
{
};

template <class T>
Inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

/**
     * @brief 检查T是否为枚举类型
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_enum : bool_constant<__is_enum(T)>
{
};

template <class T>
Inline constexpr bool is_enum_v = is_enum<T>::value;

/**
     * @brief 检查T是否为数组
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_array : false_type
{
};

/**
     * @brief 检查T是否为数组
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_array<T[]> : true_type
{
};

/**
     * @brief 检查T是否为数组
     * 
     * @tparam T 检查的对象
     */
template <class T, size_t N>
struct is_array<T[N]> : true_type
{
};

template <class T>
Inline constexpr bool is_array_v = is_array<T>::value;

/**
     * @brief 检查T是否为联合体类型
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_union : bool_constant<__is_union(T)>
{
};

/**
     * @brief 检查T是否为非联合类类型 (struct and class)
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_class : bool_constant<__is_class(T)>
{
};

/**
     * @brief 检查T是否为指针
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct _is_pointer_helper : false_type
{
};

/**
     * @brief 检查T是否为指针
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct _is_pointer_helper<T *> : true_type
{
};

/**
     * @brief 检查T是否为指针
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_pointer : _is_pointer_helper<typename remove_cv<T>::type>
{
};

template <class T>
Inline constexpr bool is_pointer_v = is_pointer<T>::value;

/**
 * @brief 检查 T 是否为左值引用类型。
 * 
 * @tparam T 检查的类型
 */
template <class T>
struct is_lvalue_reference : false_type
{
};

/**
 * @brief 检查 T 是否为左值引用类型。
 * 
 * @tparam T 检查的类型
 */
template <class T>
struct is_lvalue_reference<T &> : true_type
{
};

template <class T>
Inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

/**
 * @brief 检查 T 是否为右值引用类型
 * 
 * @tparam T 类型
 */
template <class T>
struct is_rvalue_reference : STD false_type
{
};

/**
 * @brief 检查 T 是否为右值引用类型
 * 
 * @tparam T 类型
 */
template <class T>
struct is_rvalue_reference<T &&> : STD true_type
{
};

template <class T>
Inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

/**
     * @brief 检查T是否为指向非静态成员对象或非静态成员函数的指针
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct _is_member_pointer_helper : false_type
{
};

/**
     * @brief 检查T是否为指向非静态成员对象或非静态成员函数的指针
     * 
     * @tparam T 检查的对象
     */
template <class T, class U>
struct _is_member_pointer_helper<T U::*> : true_type
{
};

/**
     * @brief 检查T是否为指向非静态成员对象或非静态成员函数的指针
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_member_pointer : _is_member_pointer_helper<typename remove_cv<T>::type>
{
};

template <class T>
Inline constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

/**
     * @brief 检查T是否为 nullptr_t
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_null_pointer : is_same<my_std::nullptr_t, remove_cv_t<T>>
{
};

/**
     * @brief 检查T是否为标量类型
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_scalar : bool_constant<
                       is_arithmetic<T>::value ||
                       is_enum<T>::value ||
                       is_pointer<T>::value ||
                       is_member_pointer<T>::value ||
                       is_null_pointer<T>::value>
{
};

template <class T>
Inline constexpr bool is_scalar_v = is_scalar<T>::value;

/**
     * @brief 检查 T 是否为 void 类型
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_void : bool_constant<is_same_v<typename remove_cv<T>::type, void>>
{
};

template <class T>
Inline constexpr bool is_void_v = is_void<T>::value;

/**
     * @brief 检查T是否为对象
     * 
     * @tparam T 检查的对象
     */
template <class T>
struct is_object : bool_constant<
                       is_scalar<T>::value ||
                       is_array<T>::value ||
                       is_union<T>::value ||
                       is_class<T>::value>
{
};


template <class T>
Inline constexpr bool is_object_v = is_object<T>::value;

MY_STL_namespace_end
#endif //TYPE_TRAITS_HPP