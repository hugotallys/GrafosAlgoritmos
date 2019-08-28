#include <iostream>

#include "../Data_Structures/Graph.hpp"

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

    std::cout << "Graph representation: " << std::endl;
    graph.print();

    return 0;
}
