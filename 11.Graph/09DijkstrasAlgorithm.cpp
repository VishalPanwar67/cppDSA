#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <climits>

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

    vector<int> dijkstras(int n, int src)
    {
        vector<int> distance(n, INT_MAX);
        set<pair<int, int>> st;

        distance[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {

            auto top = *(st.begin());
            int dis = top.first;
            int node = top.second;
            st.erase(st.begin());

            for (auto nbr : adj[node])
            {
                if (dis + nbr.second < distance[nbr.first])
                {
                    auto record = st.find(make_pair(distance[nbr.first], nbr.first));
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    distance[nbr.first] = dis + nbr.second;
                    st.insert(make_pair(distance[nbr.first], nbr.first));
                }
            }
        }
        return distance;
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
        g.addEdge(u, v, wt, 0);
    }
    g.print();

    vector<int> ans = g.dijkstras(n, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

/* vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distance(V, INT_MAX);
        set<pair<int, int>> st;

        distance[S] = 0;
        st.insert({0, S});

        while (!st.empty()) {
            auto top = *(st.begin());
            int dis = top.first;
            int node = top.second;
            st.erase(st.begin());

            for (auto nbr : adj[node]) {

                if (dis + nbr[1] < distance[nbr[0]]) {
                    distance[nbr[0]] = dis + nbr[1];
                    st.insert({distance[nbr[0]], nbr[0]});
                }
            }
        }

        return distance;
    }
*/