// Representation of Graph 

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> createAdjList(int vertices, vector<pair<int, int>> edges) {
    vector<vector<int>> adjList(vertices);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line for directed graphs
    }

    return adjList;
}

void printAdjList(const vector<vector<int>>& adjList)
{
    for (int i = 0; i < adjList.size(); ++i)
    {
        cout << i << ": ";

        for (int val : adjList[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = 5;
    vector<pair<int, int>> edges = {{0, 1} , {0,2} , {1, 2} , {1,3} , {3,4} , {2,4} };
    
    vector<vector<int>> adjList = createAdjList(vertices, edges);
    printAdjList(adjList);
    
    return 0;
}
