#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include "NetworkConnection.h"
#include <QTcpSocket>

class ClientConnection : public NetworkConnection {
    public:
        ClientConnection();
        ~ClientConnection();

        void setUpWithIpAndPort(const QString ipAddress = "", const int port = 0);
        void sendMessage(const QString message);

        void requestConnection();

    public slots:
        void receiveMessage();
        void sendDataWhenConnected();

    private:
        QTcpSocket* m_tcpSokect;
};

#endif // CLIENTCONNECTION_H
