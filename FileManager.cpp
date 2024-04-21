#include "FileManager.h"

bool FileManager::pathValid(const QString &path)
{
    QRegExp checkPath(QString("(.*):(\\\\.*)*(\..*)"));
    return checkPath.exactMatch(path);
}

FileManager::FileManager(ILog* log)
{
    logger = nullptr;

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
    Q_ASSERT_X(logger !=  nullptr, "addFile method FileManager", "Logger not initilize");

    if(pathValid(path)){
        File* t = new File(path);
        connect(t,
                &File::fileChange,
                this,
                &FileManager::fileChange);
        if(logger)
            logger->log(t->getPath() + QString(" added"));
        else
            qWarning("addFile method FileManager: Logger not initialized");

        trackFiles.push_back(t);
    }else{
        if(logger)
            logger->log(path + QString(" incorrect"));
        else
            qWarning("addFile method FileManager: Logger not initialized");
    }
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
