#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger()
{

}

void ConsoleLogger::writeOut(std::string & data)
{
    std::cout << data << std::endl;
}

ConsoleLogger::~ConsoleLogger()
{

}