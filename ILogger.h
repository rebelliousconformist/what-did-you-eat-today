#pragma once
#include <string>
class ILogger {
    public:
        virtual void writeOut(std::string &) = 0;
        ~ILogger() {};
};