#pragma once
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <string>
#include <exception>
// file error
class MyFileException : public std::exception
{
public:
    MyFileException();
    const char* what() const throw();
};
// input error
class MyInputException : public std::exception
{
public:
    MyInputException();
    const char* what() const throw();
};

#endif