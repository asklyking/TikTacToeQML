#include "ClientConnection.h"

ClientConnection::ClientConnection() : m_tcpSokect(new QTcpSocket(this)) {

}

ClientConnection::~ClientConnection() {
    m_tcpSokect->close();
}

void ClientConnection::setUpWithIpAndPort(const QString ipAddress, const int port) {
    setIpAddress(ipAddress);
    setPort(port);
    requestConnection();

    connect(m_tcpSokect, &QIODevice::readyRead, this, &ClientConnection::receiveMessage);
    connect(m_tcpSokect, &QTcpSocket::connected, this, &ClientConnection::sendDataWhenConnected);
}

void ClientConnection::sendMessage(const QString message) {
    //    requestConnection();
    if(m_tcpSokect) {
        if(!message.isEmpty())
        {
            m_tcpSokect->write(message.toStdString().c_str());
            m_tcpSokect->flush();
        }
    }
}

void ClientConnection::receiveMessage() {
    if(m_tcpSokect){
        setCurrentMessage(QString::fromUtf8(m_tcpSokect->readLine()).trimmed());
    }
}

void ClientConnection::sendDataWhenConnected() {
    if(m_tcpSokect){
        if(m_tcpSokect->state() == QTcpSocket::ConnectedState) {
            qDebug() << "connected";
        }
    }
}

void ClientConnection::requestConnection() {
    if(m_tcpSokect){
        m_tcpSokect->connectToHost(ipAddress(), port());
    }
}
