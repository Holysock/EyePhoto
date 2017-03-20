#ifndef PHOTOMANAGER_H
#define PHOTOMANAGER_H

#include <QObject>
#include <QUrl>
#include <QQuickImageProvider>

#include "configuration.h"

class PhotoManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString downloadID READ downloadID NOTIFY downloadIDChanged)
public:
    explicit PhotoManager(QObject *parent = 0);

    void setPath(const QString & path);
    QString path() const;
    QString downloadID() const;

    Q_INVOKABLE bool printCurrentImage(Configuration *configuration);

private:
    QString _path;
    QString _downloadID;

    QQuickImageProvider _imageProvider;

signals:
    void pathChanged();
    void downloadIDChanged();
};

#endif // PHOTOMANAGER_H
