#pragma once
#ifndef MY_HELP_HPP
#define MY_HELP_HPP
#define MY_STL_namespace_name my_std
#define MY_STL_namespace_begin      \
    namespace MY_STL_namespace_name \
    {
#define MY_STL_namespace_end }
#define MY MY_STL_namespace_name::

MY_STL_namespace_begin

/*防警告*/
#define Inline
/*防警告*/
#define Constexpr
#define CSTD ::
#define GLOBAL ::
#define STD MY_STL_namespace_name::
#define From_Right_to_Left __cdecl
#define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 16ull
    MY_STL_namespace_end

#endif //MY_HELP

#ifdef NOT_REALIZE_TREAD
    namespace my_std
{
    STD pmr::get_default_resource() noexcept;
    STD pmr::new_delete_resource() noexcept;
    operator new(STD size_t); //all
    operator delete();        //all

#endif //NOT_REALIZE_TREAD