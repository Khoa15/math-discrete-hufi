#ifndef _EDGE_H_
#define _EDGE_H_

template <class T>
class Edge{
public:
    T u, v;
    int w;
    Edge() : w(0) {}
    Edge(T x, T y) : u(x), v(y) {}
    Edge(T x, T y, int z) : u(x), v(y), w(z) {}

    
};
#endif