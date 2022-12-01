#include <iostream>
#include <fstream>
#include "TakeoffItem.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Logger.h"

TakeoffItem::TakeoffItem(std::string name, double pricePerSqF, std::ifstream& stream)
{
	_name = name;
	_pricePerSqF = pricePerSqF;
	std::string shapeType;

	//Instantiate the right shape
}

TakeoffItem::~TakeoffItem()
{
	//Add necessaery code
}

double TakeoffItem::calculatePrice()
{
	//Add necessaery code
}

void TakeoffItem::showDetails()
{
	//Add a cout line to print the details.
  //eg:
  //Wall: 2.50 sqft, $7.50
}
