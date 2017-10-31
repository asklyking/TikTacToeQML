#include "NetworkConnection.h"

NetworkConnection::NetworkConnection(QObject *parent) : QObject(parent),
    m_ipAddress(""),
    m_port(0),
    m_currentMessage("") {
//    connect(this,&NetworkConnection::isCurrentMessageChanged,this,&GameController::testConnectSlots);
}

NetworkConnection::~NetworkConnection() {

}

QString NetworkConnection::ipAddress() const {
    return m_ipAddress;
}

void NetworkConnection::setIpAddress(const QString &ipAddress) {
    m_ipAddress = ipAddress;
}

int NetworkConnection::port() const {
    return m_port;
}

void NetworkConnection::setPort(int port) {
    m_port = port;
}

QString NetworkConnection::currentMessage() const {
    return m_currentMessage;
}

void NetworkConnection::setCurrentMessage(const QString &currentMessage) {
    m_currentMessage = currentMessage;
    emit isCurrentMessageChanged();
}

Move NetworkConnection::convertCurrentMessageToMove() {
    Move tmpMove;
    if(currentMessage().toStdString().length() == 3){
        tmpMove.setRow(currentMessage().toStdString().at(0) - 48);
        tmpMove.setCol(currentMessage().toStdString().at(2) - 48);
    }
    return tmpMove;
}
