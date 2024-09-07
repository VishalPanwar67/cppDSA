#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    // Create Graph
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0) // For undirected graph
        {
            adj[v].push_back(u);
        }
    }

    // Print Graph
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }

    // BFS
    vector<int> bfs(int V)
    {
        vector<int> ans;
        vector<int> visited(V, 0);
        queue<int> q;

        // Starting BFS from node 0
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int x = q.front();
            ans.push_back(x);
            q.pop();

            for (auto it : adj[x])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }

    // DFS
    void dfsHelper(int node, vector<int> &visited, vector<int> &ans)
    {
        visited[node] = 1;
        ans.push_back(node);

        for (auto nextEle : adj[node])
        {
            if (!visited[nextEle])
            {
                dfsHelper(nextEle, visited, ans);
            }
        }
    }

    vector<int> dfs(int V)
    {
        vector<int> ans;
        vector<int> visited(V, 0);
        dfsHelper(0, visited, ans);
        return ans;
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
        int u, v;
        cout << "Enter the edges between nodes" << endl;
        cin >> u >> v;
        g.addEdge(u, v, 1); // 0 for undirected graph
    }

    g.print();

    // Perform BFS
    vector<int> result = g.bfs(n);
    cout << "BFS Traversal: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // Perform DFS
    vector<int> result2 = g.dfs(n);
    cout << "DFS Traversal: ";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}
