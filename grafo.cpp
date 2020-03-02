#include "grafo.h"
#include <QTextStream>
#include <iostream>

using namespace std;

Grafo::Grafo()
{
    //int **g,nNodos;
    this->nNodos=5;
    this->g=new int*[nNodos];
    for (int i = 0; i < nNodos; ++i) {
        g[i] = new int[nNodos];
    }

    g[0][0]= 0;
    g[0][1]= 1;
    g[0][2]= 0;
    g[0][3]= 3;
    g[0][4]= 10;

    g[1][0]= 1;
    g[1][1]= 0;
    g[1][2]= 5;
    g[1][3]= 0;
    g[1][4]= 0;

    g[2][0]= 0;
    g[2][1]= 5;
    g[2][2]= 0;
    g[2][3]= 2;
    g[2][4]= 1;

    g[3][0]= 3;
    g[3][1]= 0;
    g[3][2]= 2;
    g[3][3]= 0;
    g[3][4]= 6;

    g[4][0]= 10;
    g[4][1]= 0;
    g[4][2]= 1;
    g[4][3]= 6;
    g[4][4]= 0;

}

Grafo::~Grafo()
{
    for (int i = 0; i < nNodos; i++) {
        delete[] g[i];
    }
    delete[] g;
    //cout<<"se borra"<<endl;;
}

// Prints shortest paths from src to all other vertices
QString Grafo::dijkstra(int startnode, int endnode)
{
    string response = "";
    int n = nNodos;
    int cost[nNodos][nNodos],distance[nNodos],pred[nNodos];
    int visited[nNodos],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(g[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=g[i][j];
    for(i=0;i<n;i++) {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1) {
        mindistance=INFINITY;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i]) {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i]) {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
    for(i=0;i<n;i++)
        if(i!=startnode) {
            if (i == endnode) {
                //cout << "\nDistancia mas corta del nodo " << startnode <<" al nodo "<< i << " = " << distance[i]<<endl;
                response="\nDistancia mas corta del nodo "+to_string(startnode);
                response+=" al nodo "+to_string(i)+" = ";
                response+=to_string(distance[i]);
                response+="\n";
                //cout << "Camino = " << i;
                response+="Camino = "+to_string(i);
                j = i;
                do {
                    j = pred[j];
                    //cout << " <- " << j;
                    response+=" <- "+to_string(j);
                } while (j != startnode);
                //cout<<""<<endl;
                response+="\n";
                }
            }
    return QString::fromStdString(response);
}
