#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <QString>
#include <QObject>

class FileWriter: public QObject
{
    Q_OBJECT
public:
    FileWriter(QObject *parent = nullptr);
    Q_INVOKABLE static QString read(const QString &fileName);
    Q_INVOKABLE static bool write(const QString &fileName, const QString &data);
    Q_INVOKABLE static bool mkdir(const QString &dirName);
};

#endif // FILEWRITER_H
