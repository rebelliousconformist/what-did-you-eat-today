#include "FileLogger.h"

 FileLogger::FileLogger(std::string filename )
{
    logFile.open(filename.c_str(),std::ios::app);

    if (!logFile.is_open())
    {
        std::cerr << "Failed to open log file\n";
    }
}

void FileLogger::writeOut(std::string &data)
{
    if (!logFile.is_open())
    {
        std::cerr << "logfile not open" << std::endl;
    }
    logFile << data << std::endl;
    logFile.flush();
}

FileLogger& FileLogger::operator<<(std::ostream& (*nonValueFunction)(std::ostream& value)){
    nonValueFunction(logFile);
    return *this;
}


FileLogger::~FileLogger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}