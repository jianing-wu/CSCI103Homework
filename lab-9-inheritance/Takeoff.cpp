#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Takeoff.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Logger.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("\nPlease specify a takeoff file.\n");
        return 0;
    }
  
    //Add code to start logger
    Logger::open("log.txt");

    Takeoff* takeoff = new Takeoff(argv[1]);
    takeoff->showReport();

    cout << endl << endl << "Press enter to quit...";
    getchar();
    takeoff->~Takeoff();

    //Add code to stop logging
    Logger::close();
 
    return 0;
}

Takeoff::Takeoff(std::string fileName)
{
    //Read the file to add takeoff items
    

    Logger::log(LogType::Info, "Starting Takeoff");
  
    while (true)
    {
        //break if there is no more lines to read from file
        try
        {
            //Add take off item
        }
        catch (...)
        {
            //log an error
        }
    }

    Logger::log(LogType::Info, "Finished Takeoff");
}

Takeoff::~Takeoff()
{
    //Clean memory
}

void Takeoff::addItem(TakeoffItem* item)
{
    //Add necessary code
}

double Takeoff::calculateTotalPrice()
{    
    //Add necessary code
}

void Takeoff::showReport()
{
    //Add necessary code 
}

