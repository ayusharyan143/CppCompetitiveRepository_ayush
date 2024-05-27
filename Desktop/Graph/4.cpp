// find cycle in graph 

#include<bits/stdc++.h> 

using namespace std ; 


void addEdge( vector<vector<int>> &adjlist , int u , int v )
{
    adjlist[u].push_back(v) ;
    adjlist[v].push_back(u) ;
}












bool  bfs( vector<vector<int>> &adjList , int node , vector<bool> &visited , vector<int> &parent)
{
    queue<int> q ; 
    
    visited[node] = true ; 
    q.push( node ) ;

    while ( !q.empty() )    
    {
        int currNode = q.front() ;
        q.pop() ;

        for( int nb : adjList[currNode])
        {
            if( !visited[nb] ) 
            {
                visited[nb] = true ; 
                parent[nb] = currNode ; 
                q.push( nb ) ;

            }
            else if( parent[currNode] != nb )
            {
                return true ; 
            }
        }


    }

    return false ; 
    
}


int main()
{
    int v = 8 ; 
    vector<vector<int>> adjList(v) ;

    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 5, 7);
    addEdge(adjList, 7, 6);
    addEdge(adjList, 6, 3);
    addEdge(adjList, 3, 4);
    // addEdge(adjList, 1, 3);


    vector<bool>visited( v , false );
    vector<int> parent( v , -1 ) ;

    bool cycleFound = false ; 

    for( int i = 1 ; i < v ; i++ )    
    {
        if( !visited[i] )
        {
            if( bfs( adjList , i , visited , parent ))
            {
                cycleFound = true ; 
                break; 
            }
        }
    }


    if( cycleFound )
    {
        cout<<"There is a cycle in the graph ";
    }
    else cout<<"There is No cycle in the graph ";



}