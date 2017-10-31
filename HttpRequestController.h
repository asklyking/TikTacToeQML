#ifndef HTTPREQUESTCONTROLLER_H
#define HTTPREQUESTCONTROLLER_H

#include <QObject>

class HttpRequestController : public QObject
{
        Q_OBJECT
    public:
        explicit HttpRequestController(QObject *parent = nullptr);

    signals:

    public slots:
};

#endif // HTTPREQUESTCONTROLLER_H