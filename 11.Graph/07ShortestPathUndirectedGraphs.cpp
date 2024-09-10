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
    unordered_map<int, list<int>> adj;

public:
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
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

    vector<int> shortestPath(int n, int src, int dest)
    {

        unordered_map<int, int> parent;
        vector<bool> visited(n);
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {

            int front = q.front();
            q.pop();

            for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
            }
        }

        vector<int> ans;
        int currentNode = dest;
        ans.push_back(dest);
        while (currentNode != src)
        {
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
        }
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
        cout << "Enter the nodes" << endl;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.print();

    vector<int> ans = g.shortestPath(n, 0, 6);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    return 0;
}