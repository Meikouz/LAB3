#include "Logger.h"
#include "DatabaseModule.h"
#include "DocumentModule.h"
#include "AuditModule.h"

#include <iostream>
#include <limits>
#include <string>

void ShowMenu()
{
    std::cout << "\n-Singleton-\n";
    std::cout << "1. Connect database\n";
    std::cout << "2. Execute SQL query\n";
    std::cout << "3. Save document\n";
    std::cout << "4. Show DbManager address\n";
    std::cout << "5. Show DocumentSaver address\n";
    std::cout << "6. Show all Singleton addresses\n";
    std::cout << "0. Exit\n";
    std::cout << "Your choice: ";
}

int main()
{
    Logger::Instance().SetLogFile("application.log");
    Logger::Instance().Log("Program: started");

    int choice;

    do
    {
        ShowMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Logger::Instance().Log("UserAction: menu choice: " + std::to_string(choice));

        switch (choice)
        {
        case 1:
            DatabaseModule::ConnectDatabase();
            break;

        case 2:
            DatabaseModule::ExecuteUserQuery();
            break;

        case 3:
            DocumentModule::SaveUserDocument();
            break;

        case 4:
            DatabaseModule::ShowDbManagerAddress();
            break;

        case 5:
            DocumentModule::ShowDocumentSaverAddress();
            break;

        case 6:
            AuditModule::ShowAllSingletonAddresses();
            break;

        case 0:
            Logger::Instance().Log("Program: finished");
            std::cout << "Програму завершено.\n";
            break;

        default:
            Logger::Instance().Log("UserAction: invalid menu option");
            std::cout << "Некоректний вибір.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
