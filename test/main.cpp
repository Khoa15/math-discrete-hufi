#include <bits/stdc++.h>
// #include "../Global/Graph.h"
using namespace std;

struct Edge{
    int u, v;
    Edge* Next;
    Edge() : u(0), v(0), Next(NULL) {}
    Edge(int x, int y) : u(x), v(y), Next(NULL) {}
};

struct Vertex{
    Edge* head;
    Edge* tail;
    Vertex *Next;
    Vertex() : head(0), tail(0), Next(NULL) {}
};

struct Graph{
    Vertex* head;
    Vertex* tail;

    Graph() : head(NULL), tail(NULL) {}
};


int main(){
    int n;
    Graph graph;
    fstream f;
    f.open("../Buoi02/BRIDGE.INP", ios::in);
    
    f.close();



    return 0;
}