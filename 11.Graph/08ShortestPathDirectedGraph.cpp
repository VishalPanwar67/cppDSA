#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class graph
{
    // unordered_map<int, list<int>> adj;
    unordered_map<int, list<pair<int, int>>> adj;

public:
    void addEdge(int u, int v, int wt, bool direction)
    {
        adj[u].push_back({v, wt});
        if (direction == 0)
        {
            adj[v].push_back({u, wt});
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cout << "Enter the nodes" << endl;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt, 1);
    }
    g.print();

    return 0;
}