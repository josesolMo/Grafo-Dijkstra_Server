#ifndef DIJKSTRASERVER_H
#define DIJKSTRASERVER_H

#include <QTcpServer>

class DijkstraSocket;

class DijkstraServer : public QTcpServer
{
public:
    DijkstraServer(QObject *parent = nullptr);
    bool startServer(quint16 port);
protected:
    void incomingConnection(qintptr handle);
private:
    QList<DijkstraSocket *> mSockets;
};

#endif // DIJKSTRASERVER_H
