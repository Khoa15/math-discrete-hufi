#ifndef _GRAPH_EDGE_H_
#define _GRAPH_EDGE_H_
#include "Edge.h"
#ifndef INF
#define INF 9999
#endif
#define MAX 50
using namespace std;
template <class T>
class GraphEdge{
public:
    int n, m;
    Edge<T>* E;
    Edge<T>* SpanningTree;
    GraphEdge() : n(0), m(0), E(NULL), SpanningTree(NULL) {}
    GraphEdge(int x, int y) : n(x), m(y), E(new Edge<T>[y]), SpanningTree(NULL) {}

    ~GraphEdge(){
        delete[] E;
        delete[] SpanningTree;
    }
    void showEdge(Edge<T> *edge);

    void getFile(char *filename);
    void merge(int &L, int &R, int &mid);
    void mergeSortEdge(int begin, int end);

    int Prim(int VertexStart);
    int Krusal(int VertexStart);
    int Euler();
    int EulerCycle();

};

template <class T>
void GraphEdge<T>::showEdge(Edge<T> *edge){
    for(int i = 0; i < m; i++){
        cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;
    }
}

template <class T>
void GraphEdge<T>::merge(int &L, int &R, int &mid){
    int Left = mid - L + 1,
        Right = R - mid;

    Edge<int>* left_arr = new Edge<int>[Left],
        *right_arr = new Edge<int>[Right];

    for(int i = 0; i < Left; i++){
        left_arr[i] = E[L + i];
    }

    for(int j = 0; j < Right; j++){
        right_arr[j] = E[mid + 1 + j];
    }

    int i = 0, j = 0, k = L;

    while(i < Left && j < Right){
        if(left_arr[i].w < right_arr[j].w){
            E[k] = left_arr[i];
            i += 1;
        }else{
            E[k] = right_arr[j];
            j += 1;
        }
        k++;
    }

    while(i < Left){
        E[k] = left_arr[i];
        i++;
        k++;
    }

    while(j < Right){
        E[k] = right_arr[j];
        j++;
        k++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

template <class T>
void GraphEdge<T>::mergeSortEdge(int begin, int end){
    if(begin >= end) return;

    int mid = begin + (end - begin)/2;

    mergeSortEdge(begin, mid);
    mergeSortEdge(mid + 1, end);
    merge(begin, end, mid);
}


template <class T>
int GraphEdge<T>::Prim(int VertexStart){
    VertexStart--;
    bool set_T[n + 1] = {false};
    SpanningTree = new Edge<int>[n - 1];
    int index_set_T = 1;
    set_T[VertexStart] = true;
    int cost = 0;
    while(index_set_T < n ){
        int Mi = INF, index_v = 0, index_e = 0;
        for(int i = 0; i < n; i++){
            if(set_T[i] == false) continue;
            for(int j = 0; j < m; j++){
                if(set_T[E[j].v - 1] == true && set_T[E[j].u - 1] == true || set_T[E[j].v - 1] == false && set_T[E[j].u - 1] == false ) continue;
                if(Mi > E[j].w){
                    Mi = E[j].w;
                    if(set_T[E[j].v - 1] == true) index_v = E[j].u - 1;
                    else index_v = E[j].v - 1;
                    index_e = j;
                }
            }
        }
        cout << "=======" << endl;
        cout << E[index_e].u << " " << E[index_e].v << " " << E[index_e].w << endl;
        cost += Mi;
        SpanningTree[index_set_T - 1] = E[index_e];
        set_T[index_v] = true;
        index_set_T += 1;
    }

    return cost;
}

template <class T>
int GraphEdge<T>::Krusal(int VertexStart){

}


#endif