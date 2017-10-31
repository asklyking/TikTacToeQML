#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include "NetworkConnection.h"
#include <QTcpServer>

class ServerConnection : public NetworkConnection
{
    public:
        ServerConnection();
        ~ServerConnection();

        void setUpWithIpAndPort(const QString ipAddress = "", const int port = 0);
        void sendMessage(const QString message);
        void requestConnection();
        void acceptConnection();

    signals:

    public slots:
        void receiveMessage();

    private:
        QTcpServer* m_tcpServer;
        QTcpSocket* m_client;
};

#endif // SERVERCONNECTION_H
