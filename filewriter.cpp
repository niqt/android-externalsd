#include "filewriter.h"
#include <QFile>
#include <QDir>

FileWriter::FileWriter(QObject *parent): QObject(parent)
{

}

QString FileWriter::read(const QString &fileName)
{
    QFile file(fileName);
    QString data;
    QString path = QString(qgetenv("SECONDARY_STORAGE")) + "/" + fileName;
    if (file.open(QIODevice::ReadOnly)) {
        data = QString(file.readAll());
        file.close();
    }
    return data;
}

bool FileWriter::write(const QString &fileName, const QString &data)
{
    QFile file(fileName);
    QString path = QString(qgetenv("SECONDARY_STORAGE")) + "/" + fileName;
    if (file.open(QIODevice::WriteOnly)) {
        if (file.write(data.toStdString().c_str()) > 0) {
            file.close();
            return true;
        }
    }
    return false;
}

bool FileWriter::mkdir(const QString &dirName)
{
    QString path = QString(qgetenv("SECONDARY_STORAGE")) + "/" + dirName;
    QDir newDir;
    if (newDir.mkdir(path))
        return true;
    return false;
}
