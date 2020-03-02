#include <QCoreApplication>
#include <iostream>
#include "grafo.h"
#include "dijkstraserver.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DijkstraServer Server;
    if (!Server.startServer(3333)) {
        qDebug() << "Error: " << Server.errorString();
        return 1;
    }
    qDebug() << "Server started...";


//    int G[max][max]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

//    Grafo *g = new Grafo();
//    g->dijkstra(G,0,5);

    return a.exec();
}
