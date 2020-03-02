#include "grafo.h"
#include <QTextStream>
#include <iostream>

using namespace std;

Grafo::Grafo()
{
}

// Prints shortest paths from src to all other vertices
QString Grafo::dijkstra(int (*G)[9], int startnode, int endnode)
{
    string response = "";
    int n = max;
    int cost[max][max],distance[max],pred[max];
    int visited[max],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
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
                cout << "\nDistancia mas corta del nodo " << startnode <<" al nodo "<< i << " = " << distance[i]<<endl;
                response="\nDistancia mas corta del nodo "+to_string(startnode);
                response+=" al nodo "+to_string(i)+" = ";
                response+=to_string(distance[i]);
                response+="\n";
                cout << "Camino = " << i;
                response+="Camino = "+to_string(i);
                j = i;
                do {
                    j = pred[j];
                    cout << " <- " << j;
                    response+=" <- "+to_string(j);
                } while (j != startnode);
                cout<<""<<endl;
                response+="\n";
                }
            }
    return QString::fromStdString(response);
}
