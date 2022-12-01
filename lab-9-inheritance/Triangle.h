#pragma once

#include "Shape.h"
#include <fstream>

//Add the required code here
class Triangle : public Shape
{
private:
	double _base;
  double _height;
public:
	Triangle(std::ifstream& stream);
	virtual double calculateArea();
};

