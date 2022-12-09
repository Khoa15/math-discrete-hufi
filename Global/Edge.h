#ifndef _EDGE_H_
#define _EDGE_H_

template <class T>
class Edge{
public:
    T u, v;
    int w;
    Edge() : u(0), v(0), w(0) {}
    Edge(int x, int y) : u(x), v(y) {}
    Edge(int x, int y, int z) : u(x), v(y), w(z) {}

    
};
#endif