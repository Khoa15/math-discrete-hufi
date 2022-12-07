#include <iostream>
#include "Lib/Graph.h"
using namespace std;

struct Edge{
    int u, v, w;
    Edge() : u(0), v(0), w(0) {}
    Edge(int x, int y) : u(x), v(y) {}
    Edge(int x, int y, int z) : u(x), v(y), w(z) {}
};

void show(Edge edge[], int n){
    for(int i = 0; i < n; i++){
        cout << edge[i].u << " -> " << edge[i].v << ": " << edge[i].w << endl;
    }
}

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
    // int n, flag, x, iG = 0;
    // fstream f;
    // f.open("PRIM.INP");
    // f >> flag >> n;
    // Edge graph[n*n];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         f >> x;
    //         if(x == 0 || x == INF) continue;
    //         graph[iG].u = i;
    //         graph[iG].v = j;
    //         graph[iG].w = x;
    //         iG += 1;
    //     }
    // }
    // f.close();
    // show(graph, iG);
    // cout << Prim(0, graph, iG);
    Graph<int> G;
    G.getFile("PRIM.INP");
    G.show();

    cout << "===============" << endl;

    bool S[G.v * G.v] = {false};

    S[1] = true;
    int iS = 1;
    while(iS < G.v){
        int Mi = INF, y = 0, x = 0;
        for(int i = 0; i < G.v; i++){
            if(S[i] == false) continue;
            for(int j = 0; j < G.v; j++){
                if(G.G[i][j] == 0 || G.G[i][j] == INF || S[j] == true) continue;
                if(Mi > G.G[i][j]){
                    Mi = G.G[i][j];
                    y = j;
                    x = i;
                }
            }
        }

        cout << x + 1 << " - " << y + 1 << ": " << Mi << endl;
        S[y] = true;
        iS += 1;
    }

    return 0;
}