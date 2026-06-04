#ifndef FILELOGGER_H
#define FILELOGGER_H

#pragma once

#include "ILogger.h"
#include <fstream>
#include <iostream>

class FileLogger : public ILogger
{
public:
    explicit FileLogger(std::string filename);
    void writeOut(std::string &) override;
    FileLogger& operator<<(std::ostream& (*nonValueFunction)(std::ostream &value));
    template <typename T>
    FileLogger& operator<<(const T &value)
    {
        logFile << value;
        return *this;
    };
    ~FileLogger();

private:
    std::ofstream logFile;
};

#endif