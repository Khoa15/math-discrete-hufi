#include <iostream>
#include <stack>
#include "Lib/Graph.h"

using namespace std;

void Hamilton(Graph G, int start, int j){
    stack<int> stk;
    bool visited[G.v + 1] = {false};
    stk.push(start);
    visited[start] = true;
    int last_vertex = start;
    while(stk.empty() == false){
        int s = stk.top();
        stk.pop();
        cout << s << "\t";
        for(int i = 0; i < G.v; i++){
            if(G.W[s][i] == 0 || visited[i+1] == true) continue;
            last_vertex = i+1;
            visited[i+1] = true;
            stk.push(i+1);
        }
    }
    if(last_vertex != start){
        cout << "The graph haven't hamilton circuit\n";
    }
}

int main(){
    Graph G;

    G.getFile("HAMILTON.INP");

    G.show();

    cout << "===========\n";

    Hamilton(G, 4, 06);
    return 0;
}