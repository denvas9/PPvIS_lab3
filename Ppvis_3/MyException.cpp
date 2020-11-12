#include "MyException.h"

MyFileException::MyFileException() : std::exception() {};
const char* MyFileException::what() const throw()
{
    return "File error";
}


MyInputException::MyInputException() : std::exception() {};
const char* MyInputException::what() const throw()
{
    return "Input error";
}