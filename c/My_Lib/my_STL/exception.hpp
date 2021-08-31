#pragma once
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
/**/
#include <iostream>
/**/
namespace my_std
{

    /**
     * @brief 异常信息数据结构体
     * 
     */
    struct _exception_date
    {
        char const *_info;
        bool _is_handled;
    };

    class exception
    {
    public:
        /**
        * @brief exception 构造函数
        * 
        */
        exception() noexcept : _date()
        {
            std::cout << "exception created" << std::endl;
        }
        
        /**
         * @brief exception 构造函数
         * 
         * @param _message 异常信息
         * @param _is_handled 是否处理
         */
        explicit exception(char const *const _message, bool _is_handled = false) noexcept : _date()
        {
            this->_date._info = _message;
            this->_date._is_handled = _is_handled;
            std::cout << "exception created" << std::endl;
        }
        
        /**
         * @brief exception 复制构造函数
         * 
         * @param _other exception 对象
         */
        exception(exception const &_other) noexcept : _date()
        {
            _date._info = _other._date._info;
            _date._is_handled = _other._date._is_handled;
            std::cout << "exception copied" << std::endl;
        }
        
        /**
         * @brief 重载 = 
         * 
         * @param _other 要复制的异常对象
         * @return exception&  当前对象
         */
        exception &operator=(exception const &_other) noexcept
        {
            if (this != &_other)
            {
                _date._info = _other._date._info;
                _date._is_handled = _other._date._is_handled;
            }
            std::cout << "exception copied" << std::endl;
            return *this;
        }
       
        /**
         * @brief exception 析构函数
         * 
         */
        virtual ~exception() 
        {
            std::cout << "exception destoried" << std::endl;
        }
       
        /**
         * @brief 查询 exception 的异常信息
         * 
         * @return char const* 异常信息
         */
        virtual char const *what() const noexcept
        {
            return _date._info ? _date._info : "Unknown exception";
        }

    protected:
    private:
        /**
         * @brief 异常信息数据
         * 
         */
        _exception_date _date;
    }; //exception

} //namespce
#endif //EXCEPTION_HPP