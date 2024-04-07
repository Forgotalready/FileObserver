#include "FileManager.h"

FileManager::FileManager(ILog *log)
{
    logger = log;
    connect(this,
            &FileManager::outputSignal,
            logger,
            &ILog::notify);
}

void FileManager::updateFileState()
{
    for(int i = 0;i < trackFiles.size();i++)
        trackFiles[i]->updateState();

    QVector<QString> output;
    for(int i = 0;i < changedFiles.size();i++)
        output.push_back(trackFiles[i]->getFullInform());

    if(!changedFiles.empty()){
        emit outputSignal(output);
        changedFiles.clear();
    }
}

void FileManager::addFile(const QString &path)
{
    File* t = new File(path);
    connect(t,
            &File::fileChange,
            this,
            &FileManager::fileChange);
    trackFiles.push_back(t);
}

FileManager::~FileManager()
{
    for(int i = 0;i < trackFiles.size();i++){
        delete trackFiles[i];
        trackFiles[i] = nullptr;
    }

    for(int i = 0;i < changedFiles.size();i++){
        delete changedFiles[i];
        changedFiles[i] = nullptr;
    }
}

void FileManager::fileChange(File* t)
{
    changedFiles.push_back(t);
}
