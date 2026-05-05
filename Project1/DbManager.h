#pragma once

#include "SingletonExport.h"
#include <string>
#include <mutex>

class SINGLETON_API DbManager
{
public:
    static DbManager& Instance();

    void Connect(const std::string& connectionString);
    void Disconnect();
    void Execute(const std::string& sql);

    bool IsConnected() const;
    std::string GetConnectionString() const;

    DbManager(const DbManager&) = delete;
    DbManager& operator=(const DbManager&) = delete;

private:
    DbManager();
    ~DbManager();

    bool connected;
    std::string connectionString;
    mutable std::mutex mutex;
};