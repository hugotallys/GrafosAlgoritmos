#ifndef GRAPH
#define GRAPH

#include <vector>

typedef long long int llint;

struct __edge__
{
    llint vertex;
    llint weight;

    __edge__(llint v, llint w) : vertex(v), weight(w) { }
};

typedef struct __edge__ edge;

typedef std::vector<edge> adjlist;

class Graph
{
public:
    llint V;
    llint E;
    adjlist *vertices;

    Graph(llint num_vertices);
    ~Graph();
    void add_edge(llint source, llint target, llint weight);
    void print();
};

#endif