#include <iostream>
#include <fstream>
#include <sstream>
#include "Rectangle.h"
#include "Logger.h"

Rectangle::Rectangle(std::ifstream& stream)
{
    if (!(stream >> _length >> _width))
    {
        throw Logger::RECTANGLE_ERROR;
    }
}

//Add the required code here
double Rectangle::calculateArea()
{
}







