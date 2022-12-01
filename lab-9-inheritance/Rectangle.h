#pragma once

#include <fstream>
#include "Shape.h"


class Rectangle : public Shape
{
private:
	double _length;
  double _width;
public:
	Rectangle(std::ifstream& stream);
	virtual double calculateArea();
};
