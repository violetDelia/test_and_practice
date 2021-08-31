#pragma once
#ifndef NEW_HPP
#define NEW_HPP
#include "my_STL/exception.hpp"
/**/
/**/
namespace my_std
{
    /**
     * @brief bad_alloc 异常类 继承 exception 异常类
     * 
     */
    class bad_alloc : exception
    {
    public:
        /**
         * @brief bad_alloc 构造函数
         * 
         */
        bad_alloc() noexcept : exception("bad_alloc exception")
        {
            std::cout << "bad_alloc created" << std::endl;
        }

        /**
         * @brief bad_alloc 析构函数
         * 
         */
        ~bad_alloc()
        {
            std::cout << "bad_alloc destoried" << std::endl;
        }

    protected:
    private:
    }; //bad_alloc

    /**
     * @brief bad_array_new_length 异常类 继承 bad_alloc 异常类
     * 
     */
    class bad_array_new_length : bad_alloc
    {
    public:
        /**
         * @brief bad_array_new_length 构造函数 
         * 
         */
        bad_array_new_length() noexcept : bad_alloc()
        {
            std::cout << "bad_array_new_length created" << std::endl;
        }

        /**
         * @brief bad_array_new_length 析构函数 
         * 
         */
        ~bad_array_new_length()
        {
            std::cout << "bad_array_new_length destoried" << std::endl;
        }

    protected:
    private:
    };

} //namespce
#endif //NEW_HPP