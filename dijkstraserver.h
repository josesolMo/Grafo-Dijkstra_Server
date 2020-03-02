/**
  * @file dijkstraserver.h
  * @title Dijkstra Server
  * @brief Extiende de QTcpServer y contiene la lógica para comunicar al cliente con la implementación del grafo
  * @version 1.0
  * @author JoseSol
  * @date 02/03/2020
  */

#ifndef DIJKSTRASERVER_H
#define DIJKSTRASERVER_H

#include <QTcpServer>
#include "dijkstrasocket.h"
#include "grafo.h"

class DijkstraServer : public QTcpServer
{
public:
    /**
     * @brief Constructor de DijkstraServer
     * @param parent
     */
    DijkstraServer(QObject *parent = nullptr);

    /**
     * @brief Inicia el servidor
     * @param Puerto en donde se desea iniciar el servidor
     * @return Booleano true si se logró iniciar el servidor, false si no se logró
     */
    bool startServer(quint16 port);

protected:
    /**
     * @brief Llamada por el servidor cuando hay una nueva conexión disponible, reimplementado de QTcpServer
     * @param handle del socket que envia la señal
     */
    void incomingConnection(qintptr handle);
private:
    QList<DijkstraSocket *> mSockets;
    Grafo *g;
};

#endif // DIJKSTRASERVER_H
