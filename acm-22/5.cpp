
#include <cassert>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
    Graph(int vertices);
    void add_edge(int src, int dst);
    int count_paths(int src, int dst, int vertices);

private:
    int m_vertices;
    list<int> *m_neighbours;
    void path_counter(int src, int dst, int &path_count, vector<bool> &visited);
};

Graph::Graph(int vertices)
{
    m_vertices = vertices;
    m_neighbours = new list<int>[vertices];
}

void Graph::add_edge(int src, int dst)
{
    m_neighbours[src].push_back(dst);
}

int Graph::count_paths(int src, int dst, int vertices)
{
    int path_count = 0;
    vector<bool> visited(vertices, false);
    path_counter(src, dst, path_count, visited);
    return path_count;
}

void Graph::path_counter(int src, int dst, int &path_count, vector<bool> &visited)
{
    visited[src] = true;
    if (src == dst)
    {
        path_count++;
    }
    else
    {
        for (auto neighbour : m_neighbours[src])
        {
            if (!visited[neighbour])
                path_counter(neighbour, dst, path_count,
                             visited);
        }
    }
    visited[src] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g.add_edge(t1, t2);
    }
    cout << g.count_paths(1, 1, n);

    return 0;
}
