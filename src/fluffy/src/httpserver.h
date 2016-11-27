#ifndef QYVLIK_HTTP_HTTPSERVER_H
#define QYVLIK_HTTP_HTTPSERVER_H

#include <QObject>
#include <QHttpServer>
#include <QtQml/QQmlParserStatus>
#include "httpserverrequest.h"
#include "httpserverresponse.h"
namespace qyvlik {
namespace http {

class HttpServerRequest;
class HttpServerResponse;

class HttpServer : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)

public:
    explicit HttpServer(QObject *parent = 0);

    void classBegin() override;

    void componentComplete() override;

    Q_INVOKABLE bool listen(const QString& address, quint16 port);

    quint16 port() const;
    void setPort(const quint16 &port);

    QString address() const;
    void setAddress(const QString &address);

signals:
    void portChanged(quint16 port);
    void addressChanged(const QString& address);
    void connection(HttpServerRequest* serverRequest, HttpServerResponse* serverResponse);
public slots:
private:
    quint16 mPort;
    QString mAddress;
    qhttp::server::QHttpServer* mHttpServer;
};

class Handle : public QObject
{
    Q_OBJECT
public:
    explicit Handle(QObject* parent) :
    QObject(parent)
    { }

    Handle(qhttp::server::QHttpRequest* request, qhttp::server::QHttpResponse* response, HttpServer* httpServer);
    ~Handle() {

    }
};


} // namespace http
} // namespace qyvlik

#endif // QYVLIK_HTTP_HTTPSERVER_H
