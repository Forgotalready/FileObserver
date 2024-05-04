#include "FileManager.h"

FileManager::FileManager(ILog* log)
{
    logger = log;

    Q_ASSERT_X(logger !=  nullptr, "constructor FileManager", "Logger not initilize");

    if(logger)
        connect(this,
                &FileManager::outputSignal,
                logger,
                &ILog::notify);
    else
        qWarning("constructor FileManager: Logger not initialized");
}

void FileManager::updateFileState()
{
    for(File* t : trackFiles)
        t->updateState();

    QVector<QString> output;
    for(File* t : changedFiles)
        output.push_back(t->getFullInform());

    if(!changedFiles.empty()){
        emit outputSignal(output);
        changedFiles.clear();
    }
}

void FileManager::addFile(const QString &path)
{
    Q_ASSERT_X(logger !=  nullptr, "addFile method FileManager", "Logger not initilize");

    for(auto file : trackFiles){
        if(file->getPath() == path){
            qWarning("File already exists");
            return;
        }
    }

    File* t = new(std::nothrow) File(path);

    Q_ASSERT_X(t != nullptr, "FileManager Add File method", "File not initilize, out of memory");

    if(logger)
        logger->log(t->getPath() + QString(" added"));
    else
        qWarning("addFile method FileManager: Logger not initialized");

    if(t){
        connect(t,
                &File::fileChange,
                this,
                &FileManager::fileChange);
        trackFiles.push_back(t);
    }else{
        qWarning("FileManager Add File method : File not initilize, out of memory");
    }
}

void FileManager::deleteFile(const QString &path)
{
    auto elem = trackFiles.begin();
    while(elem != trackFiles.end()){
        if((*elem)->getPath() == path){
            trackFiles.erase(elem);
            break;
        }
    }
}

FileManager::~FileManager()
{
    for(File* t : trackFiles){
        delete t;
        t = nullptr;
    }

    for(File* t : trackFiles){
        delete t;
        t = nullptr;
    }
}

void FileManager::fileChange(File* t)
{
    changedFiles.push_back(t);
}
