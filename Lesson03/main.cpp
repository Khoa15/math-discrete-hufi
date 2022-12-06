#include <bits/stdc++.h>
#include "Lib/Graph.h"
#define INF 100;
using namespace std;

struct Edge{
    int u, v, w;
    Edge() : u(0), v(0), w(0) {}
    Edge(int x, int y) : u(x), v(y) {}
    Edge(int x, int y, int z) : u(x), v(y), w(z) {}
};

void sortEdge(Edge edge[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(edge[i].w < edge[j].w){
                swap(edge[i].w, edge[j].w);
            }
        }
    }
}

void Kruskal(Edge edge[], int n){
    sortEdge(edge, n);
    int T[n] = {0}, iT = 0;
    int u = 0, v = 0;

    while(iT < n){
        for(int i = 0; i < n; i++){
            u = edge[i].u;
            v = edge[i].v;
            if(T[u] == true && T[v] == true) continue;
            if(T[u] == true && T[v] == false){
                T[v] = true;
                iT += 1;
            }
            if(T[u] == false && T[v] == true){
                T[u] = true;
                iT += 1;  
            }
        }

    }
}

int findVertexInEdgeArr(int vertex, Edge edge[], int n){
    for(int i = 0; i < n; i++){
        if(vertex == edge[i].u){
            return i;
        }
    }
    return -1;
}

int Prim(int s, Edge edge[], int n){
    int iT = 0;
    Edge T[n];
    bool vertex[n] = {false};
    vertex[s] = true;
    int Min = findVertexInEdgeArr(s, edge, n);
    if(Min == -1) return -1;

    while(iT < n){
        for(int i = 0; i < n; i++){
            if(edge[Min].w > edge[i].w){
                Min = i;
            }
        }

    }

    return 0;
}

int main(){
    Edge edge[12];

    edge[0].u = 1;
    edge[0].v = 2;
    edge[0].w = 3;

    edge[1].u = 1;
    edge[1].v = 5;
    edge[1].w = 1;
    
    edge[2].u = 1;
    edge[2].v = 3;
    edge[2].w = 1;

    edge[3].u = 2;
    edge[3].v = 5;
    edge[3].w = 4;

    edge[4].u = 5;
    edge[4].v = 4;
    edge[4].w = 2;

    edge[5].u = 5;
    edge[5].v = 3;
    edge[5].w = 6;

    edge[6].u = 5;
    edge[6].v = 1;
    edge[6].w = 1;

    edge[7].u = 4;
    edge[7].v = 5;
    edge[7].w = 2;

    edge[8].u = 4;
    edge[8].v = 3;
    edge[8].w = 5;

    edge[9].u = 3;
    edge[9].v = 5;
    edge[9].w = 6;

    edge[10].u = 3;
    edge[10].v = 4;
    edge[10].w = 5;

    edge[11].u = 1;
    edge[11].v = 3;
    edge[11].w = 1;

    int n = 11;

    cout << Prim(1, edge, n);

    return 0;
}