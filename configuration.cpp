#include "configuration.h"

#include <QSettings>
#include <QStandardPaths>
#include <QDebug>

Configuration::Configuration(QObject *parent) : QObject(parent)
{
    QSettings settings("photobooth.conf", QSettings::IniFormat);

    settings.beginGroup("Images");
    _captureBasePath = settings.value("captureBasePath", QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toString();
    settings.endGroup();

    settings.beginGroup("Print");
    _printEnabled = settings.value("enabled", false).toBool();
    _printName = settings.value("name", "").toString();

    QString temp(settings.value("colorMode", "Color").toString());
    if (temp == "GrayScale") {
        _printColorMode = QPrinter::GrayScale;
    } else {
        _printColorMode = QPrinter::Color;
    }

    temp = settings.value("orientation", "Landscape").toString();
    if(temp == "Portrait") {
        _printOrientation = QPrinter::Portrait;
    } else {
        _printOrientation = QPrinter::Landscape;
    }

    temp = settings.value("paperSize", "A4").toString();
    if(temp == "A0")
        _printPaperSize = QPrinter::A0;
    else if(temp == "A1")
        _printPaperSize = QPrinter::A1;
    else if(temp == "A2")
        _printPaperSize = QPrinter::A2;
    else if(temp == "A3")
        _printPaperSize = QPrinter::A3;
    else if(temp == "A5")
        _printPaperSize = QPrinter::A5;
    else if(temp == "A6")
        _printPaperSize = QPrinter::A6;
    else if(temp == "A7")
        _printPaperSize = QPrinter::A7;
    else if(temp == "A8")
        _printPaperSize = QPrinter::A8;
    else if(temp == "A9")
        _printPaperSize = QPrinter::A9;
    else if(temp == "B0")
        _printPaperSize = QPrinter::B0;
    else if(temp == "B1")
        _printPaperSize = QPrinter::B1;
    else if(temp == "B2")
        _printPaperSize = QPrinter::B2;
    else if(temp == "B3")
        _printPaperSize = QPrinter::B3;
    else if(temp == "B4")
        _printPaperSize = QPrinter::B4;
    else if(temp == "B5")
        _printPaperSize = QPrinter::B5;
    else if(temp == "B6")
        _printPaperSize = QPrinter::B6;
    else if(temp == "B7")
        _printPaperSize = QPrinter::B7;
    else if(temp == "B8")
        _printPaperSize = QPrinter::B8;
    else if(temp == "B9")
        _printPaperSize = QPrinter::B9;
    else if(temp == "B10")
        _printPaperSize = QPrinter::B10;
    else if(temp == "C5E")
        _printPaperSize = QPrinter::C5E;
    else if(temp == "Comm10E")
        _printPaperSize = QPrinter::Comm10E;
    else if(temp == "DLE")
        _printPaperSize = QPrinter::DLE;
    else if(temp == "Executive")
        _printPaperSize = QPrinter::Executive;
    else if(temp == "Folio")
        _printPaperSize = QPrinter::Folio;
    else if(temp == "Ledger")
        _printPaperSize = QPrinter::Ledger;
    else if(temp == "Legal")
        _printPaperSize = QPrinter::Legal;
    else if(temp == "Letter")
        _printPaperSize = QPrinter::Letter;
    else if(temp == "Tabloid")
        _printPaperSize = QPrinter::Tabloid;
    else if(temp == "Custom")
        _printPaperSize = QPrinter::Custom;
    else if(temp == "A10")
        _printPaperSize = QPrinter::A10;
    else if(temp == "A3Extra")
        _printPaperSize = QPrinter::A3Extra;
    else if(temp == "A4Extra")
        _printPaperSize = QPrinter::A4Extra;
    else if(temp == "A4Plus")
        _printPaperSize = QPrinter::A4Plus;
    else if(temp == "A4Small")
        _printPaperSize = QPrinter::A4Small;
    else if(temp == "A5Extra")
        _printPaperSize = QPrinter::A5Extra;
    else if(temp == "B5Extra")
        _printPaperSize = QPrinter::B5Extra;
    else if(temp == "JisB0")
        _printPaperSize = QPrinter::JisB0;
    else if(temp == "JisB1")
        _printPaperSize = QPrinter::JisB1;
    else if(temp == "JisB2")
        _printPaperSize = QPrinter::JisB2;
    else if(temp == "JisB3")
        _printPaperSize = QPrinter::JisB3;
    else if(temp == "JisB4")
        _printPaperSize = QPrinter::JisB4;
    else if(temp == "JisB5")
        _printPaperSize = QPrinter::JisB5;
    else if(temp == "JisB6")
        _printPaperSize = QPrinter::JisB6;
    else if(temp == "JisB7")
        _printPaperSize = QPrinter::JisB7;
    else if(temp == "JisB8")
        _printPaperSize = QPrinter::JisB8;
    else if(temp == "JisB9")
        _printPaperSize = QPrinter::JisB9;
    else if(temp == "JisB10")
        _printPaperSize = QPrinter::JisB10;
    else if(temp == "AnsiA")
        _printPaperSize = QPrinter::AnsiA;
    else if(temp == "AnsiB")
        _printPaperSize = QPrinter::AnsiB;
    else if(temp == "AnsiC")
        _printPaperSize = QPrinter::AnsiC;
    else if(temp == "AnsiD")
        _printPaperSize = QPrinter::AnsiD;
    else if(temp == "AnsiE")
        _printPaperSize = QPrinter::AnsiE;
    else if(temp == "LegalExtra")
        _printPaperSize = QPrinter::LegalExtra;
    else if(temp == "LetterExtra")
        _printPaperSize = QPrinter::LetterExtra;
    else if(temp == "LetterPlus")
        _printPaperSize = QPrinter::LetterPlus;
    else if(temp == "LetterSmall")
        _printPaperSize = QPrinter::LetterSmall;
    else if(temp == "TabloidExtra")
        _printPaperSize = QPrinter::TabloidExtra;
    else if(temp == "ArchA")
        _printPaperSize = QPrinter::ArchA;
    else if(temp == "ArchB")
        _printPaperSize = QPrinter::ArchB;
    else if(temp == "ArchC")
        _printPaperSize = QPrinter::ArchC;
    else if(temp == "ArchD")
        _printPaperSize = QPrinter::ArchD;
    else if(temp == "ArchE")
        _printPaperSize = QPrinter::ArchE;
    else if(temp == "Imperial7x9")
        _printPaperSize = QPrinter::Imperial7x9;
    else if(temp == "Imperial8x10")
        _printPaperSize = QPrinter::Imperial8x10;
    else if(temp == "Imperial9x11")
        _printPaperSize = QPrinter::Imperial9x11;
    else if(temp == "Imperial9x12")
        _printPaperSize = QPrinter::Imperial9x12;
    else if(temp == "Imperial10x11")
        _printPaperSize = QPrinter::Imperial10x11;
    else if(temp == "Imperial10x13")
        _printPaperSize = QPrinter::Imperial10x13;
    else if(temp == "Imperial10x14")
        _printPaperSize = QPrinter::Imperial10x14;
    else if(temp == "Imperial12x11")
        _printPaperSize = QPrinter::Imperial12x11;
    else if(temp == "Imperial15x11")
        _printPaperSize = QPrinter::Imperial15x11;
    else if(temp == "ExecutiveStandard")
        _printPaperSize = QPrinter::ExecutiveStandard;
    else if(temp == "Note")
        _printPaperSize = QPrinter::Note;
    else if(temp == "Quarto")
        _printPaperSize = QPrinter::Quarto;
    else if(temp == "Statement")
        _printPaperSize = QPrinter::Statement;
    else if(temp == "SuperA")
        _printPaperSize = QPrinter::SuperA;
    else if(temp == "SuperB")
        _printPaperSize = QPrinter::SuperB;
    else if(temp == "Postcard")
        _printPaperSize = QPrinter::Postcard;
    else if(temp == "DoublePostcard")
        _printPaperSize = QPrinter::DoublePostcard;
    else if(temp == "Prc16K")
        _printPaperSize = QPrinter::Prc16K;
    else if(temp == "Prc32K")
        _printPaperSize = QPrinter::Prc32K;
    else if(temp == "Prc32KBig")
        _printPaperSize = QPrinter::Prc32KBig;
    else if(temp == "FanFoldUS")
        _printPaperSize = QPrinter::FanFoldUS;
    else if(temp == "FanFoldGerman")
        _printPaperSize = QPrinter::FanFoldGerman;
    else if(temp == "FanFoldGermanLegal")
        _printPaperSize = QPrinter::FanFoldGermanLegal;
    else if(temp == "EnvelopeB4")
        _printPaperSize = QPrinter::EnvelopeB4;
    else if(temp == "EnvelopeB5")
        _printPaperSize = QPrinter::EnvelopeB5;
    else if(temp == "EnvelopeB6")
        _printPaperSize = QPrinter::EnvelopeB6;
    else if(temp == "EnvelopeC0")
        _printPaperSize = QPrinter::EnvelopeC0;
    else if(temp == "EnvelopeC1")
        _printPaperSize = QPrinter::EnvelopeC1;
    else if(temp == "EnvelopeC2")
        _printPaperSize = QPrinter::EnvelopeC2;
    else if(temp == "EnvelopeC3")
        _printPaperSize = QPrinter::EnvelopeC3;
    else if(temp == "EnvelopeC4")
        _printPaperSize = QPrinter::EnvelopeC4;
    else if(temp == "EnvelopeC5")
        _printPaperSize = QPrinter::EnvelopeC5;
    else if(temp == "EnvelopeC6")
        _printPaperSize = QPrinter::EnvelopeC6;
    else if(temp == "EnvelopeC65")
        _printPaperSize = QPrinter::EnvelopeC65;
    else if(temp == "EnvelopeC7")
        _printPaperSize = QPrinter::EnvelopeC7;
    else if(temp == "EnvelopeDL")
        _printPaperSize = QPrinter::EnvelopeDL;
    else if(temp == "Envelope9")
        _printPaperSize = QPrinter::Envelope9;
    else if(temp == "Envelope10")
        _printPaperSize = QPrinter::Envelope10;
    else if(temp == "Envelope11")
        _printPaperSize = QPrinter::Envelope11;
    else if(temp == "Envelope12")
        _printPaperSize = QPrinter::Envelope12;
    else if(temp == "Envelope14")
        _printPaperSize = QPrinter::Envelope14;
    else if(temp == "EnvelopeMonarch")
        _printPaperSize = QPrinter::EnvelopeMonarch;
    else if(temp == "EnvelopePersonal")
        _printPaperSize = QPrinter::EnvelopePersonal;
    else if(temp == "EnvelopeChou3")
        _printPaperSize = QPrinter::EnvelopeChou3;
    else if(temp == "EnvelopeChou4")
        _printPaperSize = QPrinter::EnvelopeChou4;
    else if(temp == "EnvelopeInvite")
        _printPaperSize = QPrinter::EnvelopeInvite;
    else if(temp == "EnvelopeItalian")
        _printPaperSize = QPrinter::EnvelopeItalian;
    else if(temp == "EnvelopeKaku2")
        _printPaperSize = QPrinter::EnvelopeKaku2;
    else if(temp == "Envelope9")
        _printPaperSize = QPrinter::EnvelopeKaku3;
    else if(temp == "EnvelopePrc1")
        _printPaperSize = QPrinter::EnvelopePrc1;
    else if(temp == "EnvelopePrc2")
        _printPaperSize = QPrinter::EnvelopePrc2;
    else if(temp == "EnvelopePrc3")
        _printPaperSize = QPrinter::EnvelopePrc3;
    else if(temp == "EnvelopePrc4")
        _printPaperSize = QPrinter::EnvelopePrc4;
    else if(temp == "EnvelopePrc5")
        _printPaperSize = QPrinter::EnvelopePrc5;
    else if(temp == "EnvelopePrc6")
        _printPaperSize = QPrinter::EnvelopePrc6;
    else if(temp == "EnvelopePrc7")
        _printPaperSize = QPrinter::EnvelopePrc7;
    else if(temp == "EnvelopePrc8")
        _printPaperSize = QPrinter::EnvelopePrc8;
    else if(temp == "EnvelopePrc9")
        _printPaperSize = QPrinter::EnvelopePrc9;
    else if(temp == "EnvelopePrc10")
        _printPaperSize = QPrinter::EnvelopePrc10;
    else if(temp == "EnvelopeYou4")
        _printPaperSize = QPrinter::EnvelopeYou4;
    else if(temp == "LastPageSize")
        _printPaperSize = QPrinter::LastPageSize;
    else
        _printPaperSize = QPrinter::A4;

    temp = settings.value("paperSource", "Auto").toString();
    if(temp == "Cassette")
        _printPaperSource = QPrinter::Cassette;
    else if(temp == "Envelope")
        _printPaperSource = QPrinter::Envelope;
    else if(temp == "EnvelopeManual")
        _printPaperSource = QPrinter::EnvelopeManual;
    else if(temp == "FormSource")
        _printPaperSource = QPrinter::FormSource;
    else if(temp == "LargeCapacity")
        _printPaperSource = QPrinter::LargeCapacity;
    else if(temp == "LargeFormat")
        _printPaperSource = QPrinter::LargeFormat;
    else if(temp == "Lower")
        _printPaperSource = QPrinter::Lower;
    else if(temp == "MaxPageSource")
        _printPaperSource = QPrinter::MaxPageSource;
    else if(temp == "Middle")
        _printPaperSource = QPrinter::Middle;
    else if(temp == "Manual")
        _printPaperSource = QPrinter::Manual;
    else if(temp == "OnlyOne")
        _printPaperSource = QPrinter::OnlyOne;
    else if(temp == "Tractor")
        _printPaperSource = QPrinter::Tractor;
    else if(temp == "SmallFormat")
        _printPaperSource = QPrinter::SmallFormat;
    else if(temp == "Upper")
        _printPaperSource = QPrinter::Upper;
    else if(temp == "CustomSource")
        _printPaperSource = QPrinter::CustomSource;
    else if(temp == "LastPaperSource")
        _printPaperSource = QPrinter::LastPaperSource;
    else
        _printPaperSource = QPrinter::Auto;


    temp = settings.value("printerMode", "HightResolution").toString();
    if(temp == "ScreenResolution") {
        _printPrinterMode = QPrinter::ScreenResolution;
    } else {
        _printPrinterMode = QPrinter::HighResolution;
    }

    _printFullPage = settings.value("fullPage", false).toBool();
    _printCenter = settings.value("center", true).toBool();

    settings.endGroup();

    settings.beginGroup("Mail");
    _smtpEnabled = settings.value("enabled", false).toBool();
    _smtpServer = settings.value("server", "").toString();
    _smtpPort = settings.value("port", 587).toInt();
    _smtpUserName = settings.value("username", "").toString();
    _smtpPassword = settings.value("password", "").toString();
    _smtpFrom = settings.value("from", "").toString();
    _smtpDefaultSubject = settings.value("defaultSubject", "").toString();
    _smtpDefaultBody = settings.value("defaultBody", "").toString();
    settings.endGroup();

    settings.beginGroup("Web");
    _downloadEnabled = settings.value("enabled", false).toBool();
    _downloadHost = settings.value("host", "127.0.0.1").toString();
    _downloadPort = settings.value("port", 80).toInt();
    _downloadPageName = settings.value("pageName", "image").toString();
    _downloadPageLocation = settings.value("pageLocation", "").toString();
    settings.endGroup();

    if(_smtpServer == "" || _smtpUserName == "" || _smtpPassword == "" || _smtpFrom == "") {
        _smtpEnabled = false;
    }

    emit initFinished();
}

QString Configuration::captureBasePath() const
{
    return _captureBasePath;
}

bool Configuration::printEnabled() const
{
    return _printEnabled;
}

QString Configuration::printName() const
{
    return _printName;
}

QPrinter::ColorMode Configuration::printColorMode() const
{
    return _printColorMode;
}

QPrinter::Orientation Configuration::printOrientation() const
{
    return _printOrientation;
}

QPrinter::PaperSize Configuration::printPaperSize() const
{
    return _printPaperSize;
}

QPrinter::PaperSource Configuration::printPaperSource() const
{
    return _printPaperSource;
}

QPrinter::PrinterMode Configuration::printPrinterMode() const
{
    return _printPrinterMode;
}

bool Configuration::printFullPage() const
{
    return _printFullPage;
}

bool Configuration::printCenter() const
{
    return _printCenter;
}

bool Configuration::smtpEnabled() const
{
    return _smtpEnabled;
}

QString Configuration::smtpServer() const
{
    return _smtpServer;
}

int Configuration::smtpPort() const
{
    return _smtpPort;
}

QString Configuration::smtpUserName() const
{
    return _smtpUserName;
}

QString Configuration::smtpPassword() const
{
    return _smtpPassword;
}

QString Configuration::smtpFrom() const
{
    return _smtpFrom;
}

QString Configuration::smtpDefaultSubject() const
{
    return _smtpDefaultSubject;
}

QString Configuration::smtpDefaultBody() const
{
    return _smtpDefaultBody;
}

bool Configuration::downloadEnabled() const
{
    return _downloadEnabled;
}

QString Configuration::downloadHost() const
{
    return _downloadHost;
}

int Configuration::downloadPort() const
{
    return _downloadPort;
}

QString Configuration::downloadPageName() const
{
    return _downloadPageName;
}

QString Configuration::downloadPageLocation() const
{
    return _downloadPageLocation;
}
