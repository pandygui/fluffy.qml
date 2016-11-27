#include <QtQml>
#include "httpserver.h"
#include "httpserverrequest.h"
#include "httpserverresponse.h"

using namespace qhttp::server;

namespace qyvlik {
namespace http {


HttpServer::HttpServer(QObject *parent) :
    QObject(parent),
    mHttpServer(new QHttpServer(this))
{

}

void HttpServer::classBegin()
{

}

void HttpServer::componentComplete()
{

}

bool HttpServer::listen(const QString &address, quint16 port) {
//    this->setPort(port);
//    this->setAddress(address);
    return mHttpServer->listen(QHostAddress(address), port, [=](QHttpRequest* req, QHttpResponse* res){
        new Handle(req, res, this);
    });
}

quint16 HttpServer::port() const
{
    return mPort;
}

void HttpServer::setPort(const quint16 &port)
{
    if(mPort != port) {
        mPort = port;
        Q_EMIT portChanged(mPort);
    }
}

QString HttpServer::address() const
{
    return mAddress;
}

void HttpServer::setAddress(const QString &address)
{
    if(mAddress != address) {
        mAddress = address;
        Q_EMIT addressChanged(mAddress);
    }
}

Handle::Handle(QHttpRequest *request, QHttpResponse *response, HttpServer *httpServer):
    QObject((QObject*)request)
{
    QObject* parentPtr = request;
    HttpServerRequest*  mRequest = new HttpServerRequest(request, parentPtr);
    HttpServerResponse* mResponse = new HttpServerResponse(response, parentPtr);
    httpServer->connection(mRequest, mResponse);
}

} // namespace http
} // namespace qyvlik
