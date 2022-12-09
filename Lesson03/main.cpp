#include <iostream>
#include "Lib/Graph.h"
using namespace std;

// void sortEdge(Graph<int> G){
//     for(int i = 0; i < G.v; i++){
//         for(int j = 0; j < G.v; j++){
//             if(edge[i].w < edge[j].w){
//                 swap(G.G[i], G.G[i][j]);
//             }
//         }
//     }
// }

// void Kruskal(int s, Graph<int> G){
//     sortEdge(G);
// 
//   
//}


int Prim(int s, Graph<int> G, bool save){
    bool S[G.v + 1] = {false};

    S[s] = true;
    int iS = 1;
    int cost = 0;
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
        cout << x + 1 << " " << y + 1 << " " << G.G[x][y] << endl;
        cost += Mi;
        S[y] = true;
        iS += 1;
    }

    return cost;
}

int main(){
    Graph<int> G;
    G.getFile("PRIM.INP");
    G.show();

    cout << "===============" << endl;
    // for(int i = 0; i < G.v; i++){
    //     for(int j = 0; j < G.v; j++){
    //         if(G.G[i][j] == 0 || G.G[i][j] == INF) continue;
    //         cout << i + 1 << " " << j + 1 << " " << G.G[i][j] << endl;
    //     }
    // }
    // cout << G.v << " " << G.e;
    cout << Prim(1, G, 0);
    return 0;
}