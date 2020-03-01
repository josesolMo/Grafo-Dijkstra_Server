#ifndef DIJKSTRASOCKET_H
#define DIJKSTRASOCKET_H

#include <QTcpSocket>

class DijkstraSocket : public QTcpSocket
{
    Q_OBJECT
public:
    DijkstraSocket(qintptr handle, QObject *parent = nullptr);
signals:
    void DijkstraReadyRead(DijkstraSocket *);
    void DijkstraStateChanged(DijkstraSocket *, int);
};

#endif // DIJKSTRASOCKET_H
