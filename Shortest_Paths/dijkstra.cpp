#include <iostream>

#include "../Data_Structures/Graph.hpp"
#include "../Data_Structures/MinHeap.hpp"
#include "../Utility/Utils.hpp"

void dijkstra(Graph g, llint src, llint *dist, llint *par)
{
    llint i;
    MinHeap q(g.V);

    for (i = 0; i < g.V; i++)
    {
        dist[i] = INF;
        par[i] = -1;
        q.insert(edge(i, dist[i]));
    }

    q.decrease_key(src, dist[src] = 0);
    
    while (!q.is_empty())
    {
        edge p = q.extract_min();
        for (i = 0; i < g.vertices[p.vertex].size(); ++i)
        {
            edge v = g.vertices[p.vertex][i];
            if (dist[v.vertex] > dist[p.vertex] + v.weight)
            {
                par[v.vertex] = p.vertex;
                dist[v.vertex] = dist[p.vertex] + v.weight;
                q.decrease_key(v.vertex, dist[v.vertex]);
            }
        }
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

    llint *dist = new llint[graph.V];
    llint *par = new llint[graph.V];

    llint min_dist = INF;

    std::cout << "Input Graph:" << std::endl;
    graph.print();
    blank_line;

    std::cout << "Running Dijkstra from source (vertex 0):" << std::endl;
    dijkstra(graph, 0, dist, par);
    
    print_arr(dist, graph.V, "Minimum path-distances from source: ");
    blank_line;

    print_arr(par, graph.V, "Minimum path from source (parents array): ");
    blank_line;
    
    return 0;
}