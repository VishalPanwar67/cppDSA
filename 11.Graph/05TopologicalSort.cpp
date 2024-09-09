#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <stack>

class Graph
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

    void toposort(int node, vector<bool> &visited, stack<int> &s)
    {
        visited[node] = true;
        for (auto nextEle : adj[node])
        {
            if (!visited[nextEle])
            {
                toposort(nextEle, visited, s);
            }
        }
        s.push(node);
    }

    vector<int> topologicalSort(int n)
    {

        vector<int> ans;
        // unordered_map<int, bool> visited;
        vector<bool> visited(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                toposort(i, visited, s);
            }
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
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
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }

    g.print();

    vector<int> ans = g.topologicalSort(n);
    printVector(ans);

    return 0;
}