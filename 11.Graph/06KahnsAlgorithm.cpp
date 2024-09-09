#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
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

    vector<int> kahnAlgo(int V)
    {
        vector<int> res;
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int nbr : adj[curr])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        return res;
    }
};

void printVector(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }
    g.print();

    vector<int> ans = g.kahnAlgo(n);
    printVector(ans);

    return 0;
}