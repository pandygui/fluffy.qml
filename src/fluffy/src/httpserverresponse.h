#ifndef QYVLIK_HTTP_HTTPSERVERRESPONSE_H
#define QYVLIK_HTTP_HTTPSERVERRESPONSE_H

#include <QObject>
#include <QHttpServerResponse>

namespace qyvlik {
namespace http {

class HttpServerResponse : public qhttp::QHttpAbstractOutput
{
    Q_OBJECT
public:
    explicit HttpServerResponse(qhttp::server::QHttpResponse* httpResponse, QObject *parent = 0);
    ~HttpServerResponse();
signals:

public slots:

public:
    Q_INVOKABLE void setStatusCode(qhttp::TStatusCode code);

    Q_INVOKABLE void setVersion(const QString &versionString) override;

    Q_INVOKABLE void addHeader(const QByteArray &field, const QByteArray &value) override;

    Q_INVOKABLE qhttp::THeaderHash &headers() override;

    Q_INVOKABLE void write(const QByteArray &data) override;

    Q_INVOKABLE void end(const QByteArray &data) override;
private:
    qhttp::server::QHttpResponse* mHttpResponse;

};

} // namespace http
} // namespace qyvlik

#endif // QYVLIK_HTTP_HTTPSERVERRESPONSE_H
