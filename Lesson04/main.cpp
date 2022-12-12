#include <iostream>
#include <stack>
#include "Lib/Graph.h"

using namespace std;

void Hamilton(Graph G, int start, int* vertex, int n, bool visited[]){
    if(n >= G.v) cout << endl;
    for(int i = 0; i < G.v;i++){
        if(G.W[start][i] == 0 || visited[i]) continue;
        cout << i + 1 << "\t";
        visited[i] = false;
        vertex[n] = i;
        Hamilton(G, i, vertex, n + 1, visited);
        visited[i] = true;
    }
}

int main(){
    Graph G;

    G.getFile("HAMILTON.INP");

    G.show();

    cout << "===========\n";
    bool visited[G.v] = {false};
    int vertex[G.v] = {0};
    vertex[0] = 1;
    visited[0] = true;
    Hamilton(G, 0, vertex, 1, visited);
    return 0;
}