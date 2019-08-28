#include <iostream>
#include <vector>
#include <algorithm>

#include "../Data_Structures/Graph.hpp"
#include "../Utility/Utils.hpp"

struct Edge
{
    llint u, v, w;
    bool operator<(Edge const& other)
    {
        return w < other.w;
    }

    Edge(llint source, llint target, llint weight) : u(source), v(target), w(weight) {}
    Edge() {}
};

llint kruskal(std::vector<Edge> &edges, llint num_v, std::vector<Edge> &mst)
{
    llint mst_cost = 0;
    std::vector<llint> tree_id(num_v);

    for (llint i = 0; i < num_v; i++)
        tree_id[i] = i;

    for (Edge e : edges)
    {
        if (tree_id[e.u] != tree_id[e.v])
        {
            mst_cost += e.w;
            mst.push_back(e);

            llint o = tree_id[e.u], n = tree_id[e.v];
            for (llint i = 0; i < num_v; i++)
            {
                if (tree_id[i] == o)
                    tree_id[i] = n;
            }
        }
    }
    
    return mst_cost;
}

int main(int argc, char const *argv[])
{
    llint i;
    llint num_ver, num_edges;

    std::cin >> num_ver >> num_edges;

    Graph graph(num_ver);
    std::vector<Edge> edges(num_edges), mst;

    llint source, target, weight;

    for (i = 0; i < num_edges; i++)
    {
        std::cin >> source >> target >> weight;
        graph.add_edge(source, target, weight);
        graph.add_edge(target, source, weight); // grafo nao dirigido
        edges[i] = Edge(source, target, weight);
    }

    std::sort(edges.begin(), edges.end());
    
    std::cout << "Input Graph:" << std::endl;
    graph.print();
    blank_line;

    std::cout << "Cost of the minimum spanning tree: " << std::endl;
    std::cout << kruskal(edges, num_ver, mst) << std::endl;
    
    std::cout << "MST edges: " << std::endl;

    for (Edge e : mst)
    {
        std::cout << e.u << "---" << e.w << "---" << e.v << std::endl;
    }
    
    return 0;
}