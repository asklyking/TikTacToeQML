#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include <QObject>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <Move.h>

class NetworkConnection : public QObject
{
        Q_OBJECT
    public:

        explicit NetworkConnection(QObject *parent = nullptr);
        virtual ~NetworkConnection();
        virtual void setUpWithIpAndPort(const QString ipAddress = "", const int port = 0) = 0;
        virtual void sendMessage(const QString message) = 0;
        virtual void requestConnection() = 0;
        Move convertCurrentMessageToMove();

        QString ipAddress() const;
        void setIpAddress(const QString &ipAddress);

        int port() const;
        void setPort(int port);

        QString currentMessage() const;
        void setCurrentMessage(const QString &currentMessage);

    signals:
        void isCurrentMessageChanged();

    public slots:
        virtual void receiveMessage() = 0;

    private:
        QString m_ipAddress;
        int m_port;
        QString m_currentMessage;
};

#endif // NETWORKCONNECTION_H
