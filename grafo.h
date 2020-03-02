#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>
#include<stdio.h>
#include <QTextStream>

using namespace std;
#define INFINITY 9999
#define max 9

class Grafo
{
public:
    Grafo();  // Constructor

    QString dijkstra(int G[max][max],int startnode,int endnode);
};

#endif // GRAFO_H
