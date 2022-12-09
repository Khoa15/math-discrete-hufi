#include <fstream>
using namespace std;
#ifdef _GRAPH_EDGE_H_
template <class T>
GraphEdge<T> *getInputEdge(char *filename, GraphEdge<T> *G){
    fstream FILE;
    FILE.open(filename, ios::in);
    if(FILE.is_open() == false) return NULL;

    try
    {
        int n, m;
        FILE >> n >> m;
        m = 4;
        if(G == NULL){
            G = new GraphEdge<T>(n, m);
        }else{
            G->n = n;
            G->m = m;
        }
        for(int i = 0; i < G->m; i++){
            FILE >> G->E[i].u >> G->E[i].v >> G->E[i].w;
        }
    }
    catch(const std::exception& e)
    {
        return NULL;
    }
    

    return G;
}
#endif