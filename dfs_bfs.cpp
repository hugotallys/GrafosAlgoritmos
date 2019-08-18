#include <iostream>
#include "Graph.hpp"

void dfs_visit(Graph g, llint s, llint *t, llint *v, llint *p)
{
    llint i;
    *t = *t + 1;
    v[s] = *t;
    
    for (edge e : g.vertices[s])
    {
        std::cout << e.vertex;
        if (!v[e.vertex])
        {
            p[e.vertex] = s;
            dfs_visit(g, e.vertex, t, v, p);
        }
    }    
}

void dfs(Graph g)
{
    llint i, time;
    llint *par, *vis;

    vis = new llint[g.V];
    par = new llint[g.V];
    time = -1;

    for (i = 0; i < g.V; i++)
    {
        vis[i] = 0;
        par[i] = -1;
    }

    for (i = 0; i < g.V; i++)
    {
        if (!vis[i])
            dfs_visit(g, i, &time, vis, par);
    }

    std::cout << "DFS visit array: " << std::endl;
    for (i = 0; i < g.V; i++)
    {
        std::cout << "|" << vis[i] << "| ";
    }
    
    std::cout << "DFS parent array: " << std::endl;
    for (i = 0; i < g.V; i++)
    {
        std::cout << "|" << par[i] << "| ";
    }
}

int main(int argc, char const *argv[])
{
    llint i;
    llint num_ver, num_edges;

    std::cin >> num_ver >> num_edges;

    Graph graph(num_ver);
    llint source, target, weight;

    for (i = 0; i < num_edges; i++)
    {
        std::cin >> source >> target >> weight;
        graph.add_edge(source, target, weight);
    }

    graph.print();
    dfs(graph);

    return 0;
}
