#include "DocumentSaver.h"
#include "Logger.h"

#include <fstream>
#include <filesystem>

DocumentSaver& DocumentSaver::Instance()
{
    static DocumentSaver instance;
    return instance;
}

DocumentSaver::DocumentSaver()
{
    repositoryPath = "documents";
}

DocumentSaver::~DocumentSaver()
{
}

void DocumentSaver::SetRepositoryPath(const std::string& path)
{
    std::lock_guard<std::mutex> lock(mutex);

    repositoryPath = path;
    std::filesystem::create_directories(repositoryPath);

    Logger::Instance().Log("DocumentSaver: document repository path set: " + repositoryPath);
}

void DocumentSaver::SaveDocument(const std::string& fileName, const std::string& content)
{
    std::lock_guard<std::mutex> lock(mutex);

    std::filesystem::create_directories(repositoryPath);

    std::string fullPath = repositoryPath + "/" + fileName;

    std::ofstream document(fullPath);

    if (document.is_open())
    {
        document << content;
        document.close();

        Logger::Instance().Log("DocumentSaver: document saved: " + fullPath);
    }
    else
    {
        Logger::Instance().Log("DocumentSaver: document saving error: " + fullPath);
    }
}

std::string DocumentSaver::GetRepositoryPath() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return repositoryPath;
}