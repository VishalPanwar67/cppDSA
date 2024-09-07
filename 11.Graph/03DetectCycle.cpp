#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
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

    bool isCycleBFS(int srcNde, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        unordered_map<int, int> parent;
        queue<int> q;

        visited[srcNde] = true;
        parent[srcNde] = -1;
        q.push(srcNde);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto neighbour : adj[front])
            {
                if (visited[neighbour] == true && neighbour != parent[front])
                {
                    return true;
                }
                else if (visited[neighbour] == false)
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }

    bool isCycleDFS(int srcNode, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {

        visited[srcNode] = true;

        for (auto neighbour : adj[srcNode])
        {
            if (!visited[neighbour])
            {
                bool cycleDitected = isCycleDFS(neighbour, srcNode, visited, adj);
                if (cycleDitected)
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }
        return false;
    }
    string detectCycle(bool type)
    {
        // if type is 1 then call isCycleBFS

        unordered_map<int, bool> visited;
        // to handle disocnected component
        if (type == 1)
        {

            for (int i = 0; i < adj.size(); i++)
            {
                if (!visited[i])
                {
                    bool ans = isCycleBFS(i, visited, adj);

                    if (ans == 1)
                    {
                        return " Yes ";
                    }
                }
            }
            return " NO ";
        }

        // if type is 0 then call isCycleDFS
        if (type == 0)
        {
            for (int i = 0; i < adj.size(); i++)
            {
                if (!visited[i])
                {
                    bool ans = isCycleDFS(i, -1, visited, adj);

                    if (ans == 1)
                    {
                        return " Yes ";
                    }
                }
            }
            return " NO ";
        }

        return " You did not define the type correctly ";
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
        g.addEdge(u, v, 0); // 0 for undirected graph
    }
    g.print();

    // 1 to call isCycleBFS or 0 to call isCycleDFS
    cout << g.detectCycle(1);
    cout << g.detectCycle(0);

    return 0;
}