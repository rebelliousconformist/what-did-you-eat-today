#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#pragma once
#include "ILogger.h"
#include <string>
#include <iostream>

class ConsoleLogger : public ILogger
{
public:
    ConsoleLogger();
    void writeOut(std::string&) override;
    template <typename T>
    ConsoleLogger& operator<<(const T& value) {
        std::cout << value << std::endl;
        return *this;
    }
    ~ConsoleLogger();

private:

};

#endif