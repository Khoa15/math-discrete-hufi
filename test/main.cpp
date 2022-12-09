#include <iostream>
#include <stack>
#include "../Global/GraphEdge.h"
#include "../Global/InputGraph.h"
using namespace std;
char* filename = "BAI_5.INP";
char* file_bai_6 = "ONE.INP";

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
            bool Visisted[G->n + 1] = {false};
            int iVisisted = 1;
            stack<Edge<int>> stk;
            stk.push(G->SpanningTree[0]);
            int current = 2;
            int tmp_cost = 0;
            while(stk.empty() == false){
                Edge<int> edge = stk.top();
                if(current == edge.v) current = edge.u;
                cost += edge.w;
                stk.pop();
                if(current != edge.u){
                    // edge is U
                    // find path from U to V
                    stack<Edge<int>> stk2;
                    stk2.push(edge);
                    int curr = edge.u;
                    while(stk2.empty() == false){
                        Edge<int> edge_tmp = stk2.top();
                        if(edge_tmp.u == curr) tmp_cost = 0;
                        tmp_cost += edge_tmp.w;
                        stk2.pop();
                        
                        for(int i = 0; i < G->n - 1;i++){
                            if(G->SpanningTree[i].u == edge_tmp.u && G->SpanningTree[i].v == edge_tmp.v) continue;
                            if(G->SpanningTree[i].u == edge_tmp.v || G->SpanningTree[i].u == edge_tmp.u
                            || G->SpanningTree[i].v == edge_tmp.v || G->SpanningTree[i].v == edge_tmp.u){
                                stk2.push(G->SpanningTree[i]);
                            }
                        }
                        if(stk2.top().u == current || stk2.top().v == current){
                            break;
                        }
                    }
                }
                cost += tmp_cost;
                for(int i = 0; i < G->n - 1;i++){
                    if(G->SpanningTree[i].u == edge.u && G->SpanningTree[i].v == edge.v) continue;
                    if(G->SpanningTree[i].u == edge.v || G->SpanningTree[i].u == edge.u
                            || G->SpanningTree[i].v == edge.v || G->SpanningTree[i].v == edge.u){
                        stk.push(G->SpanningTree[i]);
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