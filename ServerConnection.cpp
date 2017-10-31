#include "ServerConnection.h"

ServerConnection::ServerConnection() : m_tcpServer(new QTcpServer(this)),
    m_client(NULL){
    if (!m_tcpServer->listen()) {
        qDebug() << "Unable to start the server: " + m_tcpServer->errorString();
        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty()) {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    }

    connect(m_tcpServer, &QTcpServer::newConnection, this, &ServerConnection::acceptConnection);

    QString strWindowTitle = "IP:" + ipAddress + "-port: " + QString::number(m_tcpServer->serverPort());
    qDebug() << strWindowTitle;
    setIpAddress(ipAddress);
    setPort(m_tcpServer->serverPort());
}

ServerConnection::~ServerConnection() {
    m_tcpServer->close();

    if(m_client){
        m_client->close();
        delete m_client;
    }
}

void ServerConnection::setUpWithIpAndPort(const QString ipAddress, const int port) {
    Q_UNUSED(ipAddress)
    Q_UNUSED(port)
}

void ServerConnection::sendMessage(const QString message) {
    if(m_client){
        m_client->write(message.toStdString().c_str());
        m_client->flush();
    }
}

void ServerConnection::receiveMessage() {
    if(m_client){
        setCurrentMessage(QString::fromUtf8(m_client->readLine()).trimmed());
    }
}

void ServerConnection::requestConnection() {
    // TODO
}

void ServerConnection::acceptConnection() {
    m_client = m_tcpServer->nextPendingConnection();

    if(m_client){
        qDebug() << "A client connected";
        connect(m_client, &QIODevice::readyRead, this, &ServerConnection::receiveMessage);
        //    connect(m_client, SIGNAL(disconnected()), this, SLOT(disconnected()));
    }
}
