#include "httpserverrequest.h"

namespace qyvlik {
namespace http {

HttpServerRequest::HttpServerRequest(qhttp::server::QHttpRequest *httpRequest, QObject *parent) :
    QHttpAbstractInput(parent),
    mHttpRequest(httpRequest)
{

}

HttpServerRequest::~HttpServerRequest()
{
    // do not delete mHttpRequest
}

const qhttp::THeaderHash &HttpServerRequest::headers() const
{
    return mHttpRequest->headers();
}

const QString &HttpServerRequest::httpVersion() const
{
    return mHttpRequest->httpVersion();
}

bool HttpServerRequest::isSuccessful() const
{
    return mHttpRequest->isSuccessful();
}

void HttpServerRequest::collectData(int atMost)
{
    mHttpRequest->collectData(atMost);
}

const QByteArray &HttpServerRequest::collectedData() const
{
    return mHttpRequest->collectedData();
}

qhttp::THttpMethod HttpServerRequest::method() const {
    return mHttpRequest->method();
}

const QString HttpServerRequest::methodString() const {
    return mHttpRequest->methodString();
}

const QUrl &HttpServerRequest::url() const {
    return mHttpRequest->url();
}

const QString &HttpServerRequest::remoteAddress() const {
    return mHttpRequest->remoteAddress();
}

quint16 HttpServerRequest::remotePort() const {
    return mHttpRequest->remotePort();
}

} // namespace http
} // namespace qyvlik
