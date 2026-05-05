#include "DocumentModule.h"
#include "DocumentSaver.h"
#include "Logger.h"
#include <iostream>
#include <string>

namespace DocumentModule
{
    void SaveUserDocument()
    {
        std::string fileName;
        std::string content;

        std::cout << "Document file name: ";
        std::getline(std::cin, fileName);

        std::cout << "Document content: ";
        std::getline(std::cin, content);

        DocumentSaver::Instance().SetRepositoryPath("documents");
        DocumentSaver::Instance().SaveDocument(fileName, content);

        Logger::Instance().Log("UserAction: user saved document");

        std::cout << "Document saved.\n";
    }

    void ShowDocumentSaverAddress()
    {
        std::cout << "DocumentSaver address: " << &DocumentSaver::Instance() << std::endl;

        Logger::Instance().Log("UserAction: user viewed DocumentSaver address");
    }
}