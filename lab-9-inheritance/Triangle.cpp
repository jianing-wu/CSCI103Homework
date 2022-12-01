#include <fstream>
#include <sstream>
#include "Triangle.h"
#include "Logger.h"

//Add the required code here
Triangle::Triangle(std::ifstream& stream)
{
    if (!(stream >> _base >> _height))
    {
        throw Logger::TRIANGLE_ERROR;
    }
}

double Triangle::calculateArea()
{
}
