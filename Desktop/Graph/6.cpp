#include <bits/stdc++.h>
using namespace std;

#define V 6 // Corrected the number of vertices to match the graph

void print(vector<int> &parent, vector<vector<pair<int, int>>> &graph)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        int u = parent[i];
        for (auto nb : graph[i])
        {
            if (nb.first == u)
            {
                cout << parent[i] << " - " << i << " \t" << nb.second << " \n";
                break;
            }
        }
    }
}

void prims(vector<vector<pair<int, int>>> &graph)
{
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;

        for (auto nb : graph[u])
        {
            int v = nb.first;
            int weight = nb.second;

            if (!inMST[v] && key[v] > weight)
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    print(parent, graph);
}

int main()
{
    vector<vector<pair<int, int>>> graph(V);

    //    u ----------> v , wt
    graph[0].push_back({1, 7});
    graph[1].push_back({0, 7});

    graph[0].push_back({2, 8});
    graph[2].push_back({0, 8});

    graph[1].push_back({3, 6});
    graph[3].push_back({1, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[2].push_back({3, 4});
    graph[3].push_back({2, 4});

    graph[2].push_back({4, 6});
    graph[4].push_back({2, 6});

    graph[3].push_back({4, 2});
    graph[4].push_back({3, 2});

    graph[3].push_back({5, 5});
    graph[5].push_back({3, 5});

    graph[5].push_back({4, 2});
    graph[4].push_back({5, 2});

    prims(graph);

    return 0;
}
