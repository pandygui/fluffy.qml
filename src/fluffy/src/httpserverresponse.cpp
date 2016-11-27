#include "httpserverresponse.h"

namespace qyvlik {
namespace http {

HttpServerResponse::HttpServerResponse(qhttp::server::QHttpResponse *httpResponse, QObject *parent) :
    QHttpAbstractOutput(parent),
    mHttpResponse(httpResponse)
{

}

HttpServerResponse::~HttpServerResponse()
{
    // do not delete mHttpResponse
}

void HttpServerResponse::setStatusCode(qhttp::TStatusCode code) {
    mHttpResponse->setStatusCode(code);
}

void HttpServerResponse::setVersion(const QString &versionString)
{
    mHttpResponse->setVersion(versionString);
}

void HttpServerResponse::addHeader(const QByteArray &field, const QByteArray &value)
{
    mHttpResponse->addHeader(field, value);
}

qhttp::THeaderHash &HttpServerResponse::headers()
{
    return mHttpResponse->headers();
}

void HttpServerResponse::write(const QByteArray &data)
{
    mHttpResponse->write(data);
}

void HttpServerResponse::end(const QByteArray &data)
{
    mHttpResponse->end(data);
}

} // namespace http
} // namespace qyvlik
