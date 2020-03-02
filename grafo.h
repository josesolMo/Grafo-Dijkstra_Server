/**
  * @file grafo.h
  * @title Grafo
  * @brief Contiene un grafo y la función Dijkstra
  * @version 1.0
  * @author JoseSol
  * @date 02/03/2020
  */

#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>
#include<stdio.h>
#include <QTextStream>

using namespace std;
#define INFINITY 9999

class Grafo
{
public:
    /**
      * @brief Constructor de Grafo
      */
    Grafo();  // Constructor
    /**
      * @brief Destructor de Grafo
      */
    ~Grafo(); //Destructor

    /**
     * @brief dijkstra obtiene la distancia más corta entre dos nodos
     * @param startnode, el nodo inicial
     * @param endnode, el nodo final
     * @return Qstring con la solución, el camino y el peso total de este
     */
    QString dijkstra(int startnode,int endnode);
private:
    int** g;
    int nNodos;
};

#endif // GRAFO_H
