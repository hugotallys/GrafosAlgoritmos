#include "Graph.hpp"

#include <iostream>

Graph::Graph(llint num_vertices)
{
    llint i;
    
    V = num_vertices;
    E = 0;
    vertices = new adjlist[num_vertices];
}

Graph::~Graph() { delete[] vertices; }

void Graph::add_edge(llint source, llint target, llint weight)
{
    vertices[source].push_back(edge(target, weight));
    E += 1;
}

void Graph::print()
{
    int i;
    std::cout << std::endl << "Adjacency List:" << std::endl;
    for (i = 0; i < V; i++)
    {
        std::cout << "[" << i << "] --> ";
        for (edge e : vertices[i])
        {
            std::cout << "(" << e.vertex << "," << e.weight << ") ";
        }
        std::cout << std::endl;
    }
}