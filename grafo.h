#ifndef GRAFO_H
#define GRAFO_H

#include <bits/stdc++.h>
using namespace std;

# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Grafo
{
    int V;    // No. of vertices

        // In a weighted graph, we need to store vertex
        // and weight pair for every edge
        list< pair<int, int> > *adj;

    public:
        Grafo(int V);  // Constructor

        // function to add an edge to graph
        void addEdge(int u, int v, int w);

        // prints shortest path from s
        void shortestPath(int s);
};

#endif // GRAFO_H
