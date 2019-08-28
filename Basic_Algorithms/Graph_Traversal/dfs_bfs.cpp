#include <iostream>
#include <queue>
#include <string>

#include "../Utility/Utils.hpp"
#include "../Data_Structures/Graph.hpp"

void bfs_visit(Graph &g, llint s, llint &t, llint *v, llint *p)
{
    std::queue<llint> queue;
    
    v[s] = t++;

    queue.push(s);
    
    while (!queue.empty())
    {
        llint u = queue.front();
        queue.pop();

        for(edge e : g.vertices[u])
        {
            if (!v[e.vertex])
            {
                p[e.vertex] = u;
                v[e.vertex] = t++;
                queue.push(e.vertex);
            }
        }
    }
}

void dfs_visit(Graph &g, llint s, llint &t, llint *v, llint *p)
{
    v[s] = t++;

    for (edge e : g.vertices[s])
    {
        if (!v[e.vertex])
        {
            p[e.vertex] = s;
            dfs_visit(g, e.vertex, t, v, p);
        }
    }
}

void traversal(Graph &g, void (*t)(Graph&, llint, llint&, llint*, llint*))
{
    llint i, time;
    llint *vis, *par;

    time = 0;
    vis = new llint[g.V];
    par = new llint[g.V];

    for (i = 0; i < g.V; i++)
    {
        vis[i] = 0;
        par[i] = -1;
    }

    for (i = 0; i < g.V; i++)
    {
        if (!vis[i])
            t(g, i, time, vis, par);
    }

    print_arr(vis, g.V, "Visited Array:");
    print_arr(par, g.V, "Parents Array:");
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

    std::cout << "Input Graph:" << std::endl;
    graph.print();
    blank_line;

    std::cout << "Running Depth-first Search:" << std::endl;
    traversal(graph, dfs_visit);
    blank_line;

    std::cout << "Running Breadth-first Search:" << std::endl;
    traversal(graph, bfs_visit);

    return 0;
}