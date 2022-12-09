#include <iostream>
#include <stack>
#include "../Global/GraphEdge.h"
#include "../Global/InputGraph.h"
using namespace std;
char* filename = "BAI_5.INP";
char* file_bai_6 = "ONE.INP";

int dfs(Edge<int> *E, int start, int end, int n){
    stack<Edge<int>> stk;
    stk.push(E[0]);
    int VertexStart = start;
    int cost = 0;
    while(stk.empty() == false){
        Edge<int> edge = stk.top();
        if(edge.u == VertexStart || edge.v == VertexStart) cost = 0;
        cost += edge.w;
        if(edge.u == end || edge.v == end) break;
        stk.pop();

        for(int i = 0; i < n - 1;i++){
            if(E[i].u == edge.u || E[i].u == edge.v || E[i].v == edge.u || E[i].v == edge.v){
                stk.push(E[i]);
            }
        }
    }

    return cost;
}

int main(){
    GraphEdge<int> *G = NULL;
    
    G = getInputEdge(filename, G);
    int option = 6;
    int cost = 0;

    switch (option)
    {
    case 5:
        /* code */
        break;
    case 6:
     {       G = getInputEdge(file_bai_6, G);
            G->showEdge(G->E);
            cout << G->Prim(2) << endl;
            cout << " --- " << endl;
            Edge<int> *E = G->E;
            stack<Edge<int>> stk;
            stk.push(G->E[0]);
            int current = 2;
            bool Visisted[G->n + 1] = {false};
            Visisted[current] = true;
            int cost = 0;
            while(stk.empty() == false){
                Edge<int> e = stk.top();
                if(Visisted[e.u] == true) current = e.v;
                else current = e.u;
                Visisted[current] = true;

                if(e.u == current || e.v == current){
                    cout << " HI";
                }
                cost += e.w;
                stk.pop();

                for(int i = 0; i < G->n - 1; i++){
                    if(Visisted[E[i].u] == true && Visisted[E[i].v] == true) continue;
                    if(E[i].u == e.u || E[i].u == e.v || E[i].v == e.u || E[i].v == e.v){
                        stk.push(E[i]);
                    }
                }
            }

            cout << cost;

        break;
    }
    case 7:
        break;
    default:
        break;
    }
    delete G;
    return 0;
}