#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "configuration.h"
#include "photomanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Configuration>("itpms.PhotoBooth.config", 1, 0, "Configuration");
    qmlRegisterType<PhotoManager>("itpms.PhotoBooth.io", 1, 0, "PhotoManager");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
