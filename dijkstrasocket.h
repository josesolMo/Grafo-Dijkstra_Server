/**
  * @file dijkstrasocket.h
  * @title Dijkstra Socket
  * @brief Extiende de QTcpSockety contiene la lógica para comunicar al cliente con la implementación del grafo
  * @version 1.0
  * @author JoseSol
  * @date 02/03/2020
  */

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
