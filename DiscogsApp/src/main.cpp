#include <DiscogsWrapper.h>

#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ReleaseController.h"
#include "ReleaseModel.h"
#include "ReleaseManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

//    std::unique_ptr<DiscogsWrapper>{std::make_shared<DiscogsWrapper>()};
//    auto discogs = new DiscogsWrapper();
 //   ReleaseManager releaseManager;
//    ReleaseController releaseController;
    qmlRegisterType<WantlistModel>("DiggersDelight", 1, 0, "WantlistModel");
    qmlRegisterType<ReleaseController>("DiggersDelight", 1, 0, "ReleaseController");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return a.exec();
}


//#include <QtGui/QGuiApplication>
//#include <QtQml/QQmlApplicationEngine>

//int main(int argc, char *argv[])
//{
//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;

//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    return app.exec();
//}
