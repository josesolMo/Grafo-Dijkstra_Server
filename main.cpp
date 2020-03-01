#include <QCoreApplication>
#include "dijkstraserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DijkstraServer Server;
    if (!Server.startServer(3333)) {
        qDebug() << "Error: " << Server.errorString();
        return 1;
    }
    qDebug() << "Server started...";
    return a.exec();
}
