#include "AuditModule.h"
#include "DbManager.h"
#include "DocumentSaver.h"
#include "Logger.h"
#include <iostream>

namespace AuditModule
{
    void ShowAllSingletonAddresses()
    {
        std::cout << "\nSingleton object addresses:\n";
        std::cout << "DbManager:     " << &DbManager::Instance() << std::endl;
        std::cout << "DocumentSaver: " << &DocumentSaver::Instance() << std::endl;
        std::cout << "Logger:        " << &Logger::Instance() << std::endl;

        Logger::Instance().Log("UserAction: user viewed all Singleton object addresses");
    }
}