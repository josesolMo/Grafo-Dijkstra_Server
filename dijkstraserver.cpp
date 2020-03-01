#include "dijkstraserver.h"
#include "dijkstrasocket.h"
#include <QTextStream>
#include <QDebug>

DijkstraServer::DijkstraServer(QObject *parent)
    :QTcpServer(parent)
{
}

bool DijkstraServer::startServer(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

void DijkstraServer::incomingConnection(qintptr handle)
{
    qDebug() << "Client connected with handle: " << handle;
    auto socket = new DijkstraSocket(handle, this);
    mSockets << socket;

    for (auto i : mSockets){
        QTextStream T(i);
        T << "Server: Se ha conectado: " << handle;
        i->flush();
    }

    connect(socket, &DijkstraSocket::DijkstraReadyRead, [&](DijkstraSocket *S)
    {
        qDebug() << "DijkstraReadyRead";
        QTextStream T(S);
        auto text = T.readAll();

        for (auto i : mSockets) {
            QTextStream K(i);
            K << text;
            i->flush();
        }
    });

    connect(socket, &DijkstraSocket::DijkstraStateChanged,
            [&](DijkstraSocket *S, int ST){
        qDebug() << "DijkstraStateChanged with handle: "
                 << S->socketDescriptor();
        if (ST == QTcpSocket::UnconnectedState) {
            qDebug() << "Unconnected state with handle: "
                     << S->socketDescriptor();
            mSockets.removeOne(S);
            for (auto i : mSockets) {
                QTextStream K(i);
                K << "Server: El cliente "
                  << S->socketDescriptor()
                  << " se ha desconcetado...";
                i->flush();
            }
        }
    });
}

