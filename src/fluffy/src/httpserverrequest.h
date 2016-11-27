#ifndef QYVLIK_HTTP_HTTPSERVERREQUEST_H
#define QYVLIK_HTTP_HTTPSERVERREQUEST_H

#include <QObject>
#include <QHttpServerRequest>

namespace qyvlik {
namespace http {

class HttpServerRequest : public qhttp::QHttpAbstractInput
{
    Q_OBJECT
public:
    explicit HttpServerRequest(qhttp::server::QHttpRequest* httpRequest,QObject *parent = 0);
    ~HttpServerRequest();
signals:

public slots:

public:
    Q_INVOKABLE const qhttp::THeaderHash &headers() const override;

    Q_INVOKABLE const QString &httpVersion() const override;

    Q_INVOKABLE bool isSuccessful() const override;

    Q_INVOKABLE void collectData(int atMost) override;

    Q_INVOKABLE const QByteArray &collectedData() const override;

    Q_INVOKABLE qhttp::THttpMethod method() const;

    Q_INVOKABLE const QString methodString() const;

    Q_INVOKABLE const QUrl& url() const;

    Q_INVOKABLE const QString& remoteAddress() const;

    Q_INVOKABLE quint16 remotePort() const;
private:
    qhttp::server::QHttpRequest* mHttpRequest;
};

} // namespace http
} // namespace qyvlik

#endif // QYVLIK_HTTP_HTTPSERVERREQUEST_H
