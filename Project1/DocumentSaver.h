#pragma once

#include "SingletonExport.h"
#include <mutex>
#include <string>

class SINGLETON_API DocumentSaver
{
public:
    static DocumentSaver& Instance();

    void SetRepositoryPath(const std::string& path);
    void SaveDocument(const std::string& fileName, const std::string& content);

    std::string GetRepositoryPath() const;

    DocumentSaver(const DocumentSaver&) = delete;
    DocumentSaver& operator=(const DocumentSaver&) = delete;

private:
    DocumentSaver();
    ~DocumentSaver();

    std::string repositoryPath;
    mutable std::mutex mutex;
};
