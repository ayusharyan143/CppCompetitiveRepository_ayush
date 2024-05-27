//  Dijkstra Algo 


#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>p ; 

void dijkstra(int v,  vector<vector<p>> &adjList , int src ,  vector<int> &dist  )
{
    priority_queue<p , vector<p> , greater<p>> pq ; 

    vector<bool> visited( v , false );

    pq.push({0,src});
    dist[src] = 0 ; 

    while( !pq.empty())
    {
        int currNode = pq.top().second ; 
        pq.pop();

        if( visited[currNode]) continue; 

        visited[currNode] = true ; 


        for( auto nb : adjList[currNode])
        {
            int V = nb.first ; 
            int wgt = nb.second ; 

            if( !visited[V] && dist[currNode] + wgt < dist[V] ) 
            {
                dist[V] = dist[currNode] + wgt ; 
                pq.push({dist[V] , V});

            }
        }

    }
}

int main()
{
    int v = 9 ; 


    vector<vector<p>> graph(v) ;

    
    // Define the graph as an adjacency list
    graph[0].push_back({1, 4});
    graph[0].push_back({7, 8});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    graph[1].push_back({7, 11});
    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});
    graph[2].push_back({8, 2});
    graph[3].push_back({2, 7});
    graph[3].push_back({4, 9});
    graph[3].push_back({5, 14});
    graph[4].push_back({3, 9});
    graph[4].push_back({5, 10});
    graph[5].push_back({2, 4});
    graph[5].push_back({3, 14});
    graph[5].push_back({4, 10});
    graph[5].push_back({6, 2});
    graph[6].push_back({5, 2});
    graph[6].push_back({7, 1});
    graph[6].push_back({8, 6});
    graph[7].push_back({0, 8});
    graph[7].push_back({1, 11});
    graph[7].push_back({6, 1});
    graph[7].push_back({8, 7});
    graph[8].push_back({2, 2});
    graph[8].push_back({6, 6});
    graph[8].push_back({7, 7});

    vector<int> dist( v , INT_MAX);
    int start = 0 ; 

    dijkstra(v, graph, start, dist);

    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < v; ++i)
    {
        cout << "Vertex " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
