#include "Logger.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <iostream>

std::ofstream Logger::_logStream;

const std::string Logger::ITEM_ERROR = "ERR 004 - Error while crearing a takeoff item.";
const std::string Logger::RECTANGLE_ERROR = "ERR 001 - Error while crearing a rectangle.";
const std::string Logger::TRIANLE_ERROR = "ERR 002 - Error while crearing a triangle.";
const std::string Logger::CIRCLE_ERROR = "ERR 003 - Error while crearing a circle.";

void Logger::open(std::string fileName)
{
	_logStream.open(fileName);
  if (!_logStream.is_open()) { return; }
}

void Logger::log(LogType logType, const std::string info)
{
	//Get the current date and time in the form of "%d-%m-%Y %H-%M-%S
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  std::string dateTime = std::format("{}-{}-{} {}-{}-{}", 
                                     now->tm_mday, now->tm_mon, now->tm_year + 1900,
                                    now->tm_hour, now->tm_min, now->tm_sec);
	//use the log type add a relevant line to the log file. In the form of: 
	//	[time-date]: Info/Error: [info]
  String logTypeStr = logType == Info? "Info" : "Error";
  std::string log = std::format("{}: {}: {}\n", dateTime, logTypeStr, info);
  _logStream << log; 
  _logStream.flush();
}

void Logger::close()
{
    //Close the log gile
  _logStream.flush();
  _logStream.close();
}
