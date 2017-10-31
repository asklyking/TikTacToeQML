#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <GameController.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GameController gameController(&engine); //share engine to game controller
    engine.rootContext()->setContextProperty("gameController",&gameController);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
