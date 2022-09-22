#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> umap;

void printGraph(string pos)
{
    cout << pos << " ";

    while (umap.find(pos) != umap.end())
    {
        pos = umap[pos];
        cout << pos << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    string start;
    set<string> srcs;
    set<string> dests;
    for (int i = 0; i < n; i++)
    {
        string src, dst;
        cin >> src >> dst;
        umap[src] = dst;

        srcs.insert(src);
        dests.insert(dst);
    }
    for (auto s : srcs)
        if (dests.find(s) == dests.end())
        {
            printGraph(s);
            return 0;
        }

    return 0;
}
