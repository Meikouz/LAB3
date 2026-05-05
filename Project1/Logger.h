#pragma once

#include "SingletonExport.h"
#include <string>
#include <fstream>
#include <mutex>

class SINGLETON_API Logger
{
public:
    static Logger& Instance();

    void Log(const std::string& message);
    void SetLogFile(const std::string& fileName);

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    Logger();
    ~Logger();

    std::ofstream file;
    std::string fileName;
    std::mutex mutex;
};