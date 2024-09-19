#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

class graph
{
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

    vector<pair<pair<int, int>, int>> prims(int n, int src)
    {
        vector<pair<pair<int, int>, int>> ans;
        vector<int> key(n + 1, INT_MAX);
        vector<bool> mst(n + 1, false);
        vector<int> parent(n + 1, -1);

        key[src] = 0;
        parent[src] = -1;

        for (int i = 1; i <= n; i++)
        {
            int min = INT_MAX;
            int u;

            // Find the vertex with the minimum key value that is not in MST
            for (int v = 0; v < n; v++)
            {
                if (!mst[v] && key[v] < min)
                {

                    min = key[v];
                    u = v;
                }
            }

            // If u is still -1, the graph is not fully connected
            if (u == -1)
            {
                cout << "Graph is not connected." << endl;
                break;
            }

            mst[u] = true;

            // Update the keys of the adjacent vertices
            for (auto nbr : adj[u])
            {
                int v = nbr.first;
                int weight = nbr.second;
                if (!mst[v] && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        // Collect the edges of the MST
        for (int i = 0; i < n; i++)
        {
            if (parent[i] != -1)
            {
                ans.push_back({{parent[i], i}, key[i]});
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    // cout << "Enter the number of nodes:" << endl;
    cin >> n;

    int m;
    // cout << "Enter the number of edges:" << endl;
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        // cout << "Enter the nodes and weight (u, v, wt):" << endl;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt, 0);
    }

    g.print();

    // Get the starting node from the user
    int src;
    cout << "Enter the starting node for Prim's algorithm:" << endl;
    cin >> src;

    vector<pair<pair<int, int>, int>> ans = g.prims(n, src);

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (auto i : ans)
    {
        cout << i.first.first << " - " << i.first.second << " with weight " << i.second << endl;
    }

    return 0;
}
