#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include <QPrinter>

class Configuration : public QObject
{
    Q_OBJECT
    // The NOTIFY isn't necessary for functionality, but otherwise qtquick would complain
    Q_PROPERTY(QString captureBasePath READ captureBasePath NOTIFY initFinished)
    Q_PROPERTY(bool printEnabled READ printEnabled NOTIFY initFinished)
    //Q_PROPERTY(QString printName READ printName NOTIFY initFinished)
    Q_PROPERTY(bool smtpEnabled READ smtpEnabled NOTIFY initFinished)
    //Q_PROPERTY(QString smtpServer READ smtpServer)
    //Q_PROPERTY(int smtpPort READ smtpPort)
    //Q_PROPERTY(QString smtpUserName READ smtpUserName)
    //Q_PROPERTY(QString smtpPassword READ smtpPassword)
    //Q_PROPERTY(QString smtpFrom READ smtpFrom)
    Q_PROPERTY(QString smtpDefaultSubject READ smtpDefaultSubject NOTIFY initFinished)
    Q_PROPERTY(QString smtpDefaultBody READ smtpDefaultBody NOTIFY initFinished)
    Q_PROPERTY(bool downloadEnabled READ downloadEnabled NOTIFY initFinished)
    Q_PROPERTY(int downloadPort READ downloadPort NOTIFY initFinished)
    Q_PROPERTY(QString downloadPageName READ downloadPageName NOTIFY initFinished)
    //Q_PROPERTY(QString downloadPageLocation READ downloadPageLocation)
public:
    explicit Configuration(QObject *parent = 0);

    QString captureBasePath() const;

    bool printEnabled() const;
    QString printName() const;
    QPrinter::ColorMode printColorMode() const;
    QPrinter::Orientation printOrientation() const;
    QPrinter::PaperSize printPaperSize() const;
    QPrinter::PaperSource printPaperSource() const;
    QPrinter::PrinterMode printPrinterMode() const;
    bool printFullPage() const;
    bool printCenter() const;

    bool smtpEnabled() const;
    QString smtpServer() const;
    int smtpPort() const;
    QString smtpUserName() const;
    QString smtpPassword() const;
    QString smtpFrom() const;
    QString smtpDefaultSubject() const;
    QString smtpDefaultBody() const;

    bool downloadEnabled() const;
    QString downloadHost() const;
    int downloadPort() const;
    QString downloadPageName() const;
    QString downloadPageLocation() const;

private:
    QString _captureBasePath;

    bool _printEnabled;
    QString _printName;
    QPrinter::ColorMode _printColorMode;
    QPrinter::Orientation _printOrientation;
    QPrinter::PaperSize _printPaperSize;
    QPrinter::PaperSource _printPaperSource;
    QPrinter::PrinterMode _printPrinterMode;
    bool _printFullPage;
    bool _printCenter;

    bool _smtpEnabled;
    QString _smtpServer;
    int _smtpPort;
    QString _smtpUserName;
    QString _smtpPassword;
    QString _smtpFrom;
    QString _smtpDefaultSubject;
    QString _smtpDefaultBody;

    bool _downloadEnabled;
    QString _downloadHost;
    int _downloadPort;
    QString _downloadPageName;
    QString _downloadPageLocation;

signals:
    void initFinished();
};

#endif // CONFIGURATION_H
