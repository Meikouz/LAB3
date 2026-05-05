#include "DatabaseModule.h"
#include "DbManager.h"
#include "Logger.h"
#include <iostream>
#include <string>

namespace DatabaseModule
{
    void ConnectDatabase()
    {
        DbManager::Instance().Connect("LocalFileDatabase");

        Logger::Instance().Log("UserAction: user connected to database");

        std::cout << "Database connected.\n";
    }

    void ExecuteUserQuery()
    {
        std::string sql;

        std::cout << "Enter SQL query: ";
        std::getline(std::cin, sql);

        DbManager::Instance().Execute(sql);

        Logger::Instance().Log("UserAction: user executed SQL query");

        std::cout << "Query executed.\n";
    }

    void ShowDbManagerAddress()
    {
        std::cout << "DbManager address: " << &DbManager::Instance() << std::endl;

        Logger::Instance().Log("UserAction: user viewed DbManager address");
    }
}