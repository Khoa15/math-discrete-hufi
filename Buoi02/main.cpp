#include <iostream>
#include <fstream>
using namespace std;
#include "Lib/Graph.h"

struct Edge{
    int u, v;
    Edge() : u(0), v(0) {}
};

template <class Y>
void findSmallestSpanningTree_BFS(Graph<Y> &graph){
    //BFS _ Tim kiem chieu rong
    bool isChecked[graph.v] = {false};
    Edge T[graph.v];
    int edges = 0;
    for(int i = 0; i < graph.v; i++){
        for(int j = 0; j < graph.v; j++){
            if(graph.G[i][j] == 1 && isChecked[j] == false){
                T[edges].u = i + 1;
                T[edges].v = j + 1;
                isChecked[i] = true;
                isChecked[j] = true;
                edges += 1;
                if(edges == graph.v - 1){
                    cout << "cay khung nho nhat" << endl;
                    for(int x = 0; x < edges; x++){
                        cout << T[x].u << " " << T[x].v << endl;
                    }
                    return;
                }
            }
        }
    }
}
template <class Y>
void findSmallestSpanningTree_DFS(Graph<Y> &graph){
    //DFS _ Tim kiem chieu rong
    stack<int> stk;
    bool isChecked[graph.v] = {false};
    stk.push(0);
    while(stk.empty() == false){
        int j = stk.top();
        cout << j + 1 << "\t";
        stk.pop();
        for(int i = 0; i < graph.v; i++){
            if(graph.G[j][i] != 0 && isChecked[i] == false){
                stk.push(i);
            }
        }
    }
}
int countSpanningTree_DFS(Graph<int> &graph){
    bool isChecked[graph.v] = {false};
    Edge T[graph.v];
    int edges = 0;
    int i = 1;
    for(; i < graph.v;){
        isChecked[i] = 1;
        for(int j = 1; j < graph.v; j++){
            if(graph.G[i][j] !=0 && isChecked[j] == false){
                T[edges].u = i + 1;
                T[edges].v = j + 1;
                edges += 1;
                if(edges == graph.v - 1){
                    cout << "cay khung nho nhat" << endl;
                    for(int x = 0; x < edges; x++){
                        cout << T[x].u << " " << T[x].v << endl;
                        
                    }
                    return 0;
                }
            }else i=j;
        }
    }
}
void Bai1();
void Bai2();
void Bai3();


int main(){
    int option = 2;

    switch(option){
        case 2:
            Bai2();
            break;
        case 3:
            Bai3();
            break;
    }


    return 0;
}

void Bai2(){
    Graph<int> graph;
    graph.init(false, false);
    fstream file;
    file.open("BRIDGE.INP", ios::in);
    file >> graph.v;
    for(int i = 0; i < graph.v; i++){
        for(int j = 0; j < graph.v; j++){
            file >> graph.G[i][j];
            if(graph.G[i][j] == 1){
                graph.e += 1;
            }
        }
    }

    file.close();
    graph.show();
    cout << "BFS: " << endl;
    findSmallestSpanningTree_BFS(graph);
    cout << endl << "DFS: " << endl;
    findSmallestSpanningTree_DFS(graph);
}

void Bai3(){
    Graph<int> graph;
    graph.init(false, false);
    
    fstream file;
    file.open("HAM.INP", ios::in);
    file >> graph.e;
    int u = 0, v = 0, n = 1;
    for(int i = 0; i < graph.e; i++){
        file >> u >> v;
        graph.G[u-1][v-1] = 1;
        if(n < u) n = u;
        if(n < v) n = v;
    }
    graph.v = n;
    file.close();
    graph.show();
    cout << endl;
    findSmallestSpanningTree_DFS(graph);
}
