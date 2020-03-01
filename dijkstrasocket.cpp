#include "dijkstrasocket.h"

DijkstraSocket::DijkstraSocket(qintptr handle, QObject *parent)
    : QTcpSocket (parent)
{
    setSocketDescriptor(handle);

    connect(this, &DijkstraSocket::readyRead, [&]() {
        emit DijkstraReadyRead(this);
    });

    connect(this, &DijkstraSocket::stateChanged, [&](int S){
        emit DijkstraStateChanged(this, S);
    });
}
