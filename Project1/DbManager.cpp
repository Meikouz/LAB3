#include "DbManager.h"
#include "Logger.h"
#include <fstream>

DbManager& DbManager::Instance()
{
    static DbManager instance;
    return instance;
}

DbManager::DbManager()
{
    connected = false;
}

DbManager::~DbManager()
{
    Disconnect();
}

void DbManager::Connect(const std::string& newConnectionString)
{
    std::lock_guard<std::mutex> lock(mutex);

    connectionString = newConnectionString;
    connected = true;

    Logger::Instance().Log("DbManager: connected to database: " + connectionString);
}

void DbManager::Disconnect()
{
    std::lock_guard<std::mutex> lock(mutex);

    if (connected)
    {
        Logger::Instance().Log("DbManager: disconnected from database");
        connected = false;
    }
}

void DbManager::Execute(const std::string& sql)
{
    std::lock_guard<std::mutex> lock(mutex);

    if (!connected)
    {
        Logger::Instance().Log("DbManager: query execution failed, database is not connected");
        return;
    }

    std::ofstream dbFile("database_operations.txt", std::ios::app);
    dbFile << "Connection: " << connectionString << std::endl;
    dbFile << "SQL: " << sql << std::endl;
    dbFile << "-----------------------------" << std::endl;

    Logger::Instance().Log("DbManager: SQL query executed: " + sql);
}

bool DbManager::IsConnected() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return connected;
}

std::string DbManager::GetConnectionString() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return connectionString;
}