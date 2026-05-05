#include "Logger.h"
#include <chrono>
#include <iomanip>
#include <sstream>

Logger& Logger::Instance()
{
    static Logger instance;
    return instance;
}

Logger::Logger()
{
    fileName = "application.log";
    file.open(fileName, std::ios::app);
}

Logger::~Logger()
{
    if (file.is_open())
    {
        file.close();
    }
}

void Logger::SetLogFile(const std::string& newFileName)
{
    std::lock_guard<std::mutex> lock(mutex);

    if (file.is_open())
    {
        file.close();
    }

    fileName = newFileName;
    file.open(fileName, std::ios::app);
}

void Logger::Log(const std::string& message)
{
    std::lock_guard<std::mutex> lock(mutex);

    if (!file.is_open())
    {
        file.open(fileName, std::ios::app);
    }

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    tm localTime{};
    localtime_s(&localTime, &time);

    file << "[" << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << "] "
        << message << std::endl;
}
