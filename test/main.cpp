#include <iostream>
#include <stack>
#include <fstream>
#include <string.h>
#include "../Global/GraphEdge.h"
#include "../Global/InputGraph.h"
using namespace std;
char* file_bai_5 = "BAI_5.INP";
char* file_bai_6 = "ONE.INP";
char* file_bai_7 = "BAI_7.INP";
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

GraphEdge<int>* getInputPracticle7(char* filename, GraphEdge<int> *G){
    fstream FILE;
    FILE.open(filename, ios::in);
    if(FILE.is_open() == false) return NULL;

    try
    {
        int n;
        FILE >> n;
        if(G == NULL){
            G = new GraphEdge<int>(n, n*n);
        }else{
            G->n = n;
        }
        int x = 0, m = 0;
        for(int i = 0; i < G->n; i++){
            for(int j = 0; j < G->n; j++){
                FILE >> x;
                if(j < i) continue;
                if(x == 0) continue;
                G->E[m].u = i + 1;
                G->E[m].v = j + 1;
                G->E[m].w = x;
                m += 1;
            }
        }
        G->m = m;
    }
    catch(const std::exception& e)
    {
        return NULL;
    }
    return G;
}

void Menu(){
    cout
        << "===========" << endl
        << "Bai 4" << endl
        << "Bai 5" << endl
        << "Bai 6" << endl
        << "Bai 7" << endl
        << "===========" << endl;
}

int main(){
    GraphEdge<int> *G = NULL;
    GraphEdge<int> *NetG = NULL;
    
    int option = 5;
    int cost = 0, n, m;

    Menu();
    cout << "Enter your option: ";
    cin >> option;
    switch (option)
    {
    case 5:
        cin >> n >> m;
        G = new GraphEdge<int>(n, m);
        for(int i = 0; i < m; i++){
            cin >> G->E[i].u >> G->E[i].v >> G->E[i].w;
        }

        cout << G->Prim(1);

        break;
    case 6:
     {
            G = getInputEdge(file_bai_6, G);
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
                int s = 0;
                bool flag = false;
                if(e.u != current && e.v != current){
                    s = current;
                    flag = true;
                }
                if(Visisted[e.u] == true) current = e.v;
                else current = e.u;
                Visisted[current] = true;
                if(flag == true){
                    cost += dfs(G->E, s, (Visisted[e.u] == true) ? e.u : e.v, G->n);
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
    {
        NetG = getInputPracticle7(file_bai_7, NetG);
        NetG->showEdge(NetG->E);
        cout << NetG->Prim(1);
        break;
    }
    default:
        break;
    }
    delete G;
    return 0;
}