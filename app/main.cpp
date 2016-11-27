#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "httpserver.h"
#include "httpserverrequest.h"
#include "httpserverresponse.h"

using namespace qyvlik::http;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<HttpServer>("qyvlik.http.server", 0, 1, "HttpServer");
    qmlRegisterUncreatableType<HttpServerRequest>("qyvlik.http.server", 0, 1,
                                                  "HttpServerRequest",
                                                  "HttpServerRequest can not create");
    qmlRegisterUncreatableType<HttpServerResponse>("qyvlik.http.server", 0, 1,
                                                   "HttpServerResponse",
                                                   "HttpServerResponse can not create");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
