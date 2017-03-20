#include "photomanager.h"

#include <QDebug>
#include <QImage>
#include <QPrinter>
#include <QPainter>
#include <QRect>

PhotoManager::PhotoManager(QObject *parent) : QObject(parent), _downloadID(""), _imageProvider(QQmlImageProviderBase::Image)
{

}

void PhotoManager::setPath(const QString &path)
{
    _path = path;
    emit pathChanged();
    qDebug() << path;
}

QString PhotoManager::path() const
{
    return _path;
}

QString PhotoManager::downloadID() const
{
    return _downloadID;
}

bool PhotoManager::printCurrentImage(Configuration* configuration)
{
    if(!configuration->printEnabled() || _path == "")
        return false;
    QImage image(_path);

    QPrinter printer(configuration->printPrinterMode());
    printer.setPrinterName(configuration->printName());
    printer.setOrientation(configuration->printOrientation());
    printer.setPaperSize(configuration->printPaperSize());
    printer.setPaperSource(configuration->printPaperSource());
    printer.setFullPage(configuration->printFullPage());


    // These are for debugging purposes, so there's no paper wasted
    //printer.setOutputFileName("test.pdf");
    //printer.setOutputFormat(QPrinter::PdfFormat);

    QPainter painter;
    painter.begin(&printer);

    int width = printer.width();
    int height = static_cast<int>(image.height() * (static_cast<double>(width) / static_cast<double>(image.width())));

    if(height > printer.height()) {
        height = printer.height();
        width = static_cast<int>(image.width() * (static_cast<double>(height) / static_cast<double>(image.height())));
    }

    int x = 0;
    int y = 0;

    if(configuration->printCenter()) {
        x = (printer.width() - width) / 2;
        y = (printer.height() - height) / 2;
    }

    painter.drawImage(QRect(x, y, width, height), image);

    painter.end();

    return true;
}
