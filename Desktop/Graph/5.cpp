// krushkal algo MST 

#include<bits/stdc++.h>

using namespace std ; 

int find( vector<int> &parent , int i )
{
    if( parent[i]  == -1 )
    {
        return i ; 
    }
    
    return find( parent , parent[i]);

}


void Union( vector<int> &parent , int  x , int y )
{
    parent[x] = y ; 
}


int Krushkal( int v ,  vector<vector<pair<int,int>>> &adjlist )
{
    vector<pair<int,pair<int,int>>> edges ; 

    for( int i = 0 ; i < v ; i++ )
    {
        for( auto it : adjlist[i])
        {
            int adjNode = it.first ; 
            int w = it.second ; 
            int node = i ; 

            edges.push_back({w,{node,adjNode}}) ;

        }
    }

    sort( edges.begin() , edges.end() ) ;

    int countMST = 0 ; 

    vector<int> parent( v  , -1 ) ;

    for( auto it : edges )
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        int x = find(parent, u);
        int y = find(parent, v);

        if( x != y )
        {
            countMST += w ; 
            Union( parent , x , y );

        }


    }

    return countMST ; 



}

int main()
{
    int v = 9 ; 

    vector<vector<pair<int,int>>> adjlist(v) ;

    adjlist[1].push_back({2, 7});
    adjlist[2].push_back({1, 7});
   
    adjlist[1].push_back({3, 8});
    adjlist[3].push_back({1, 8});

    adjlist[2].push_back({3, 3});
    adjlist[3].push_back({2, 3});

   
    adjlist[2].push_back({4, 5});
    adjlist[4].push_back({2, 5});

    adjlist[3].push_back({5, 3});
    adjlist[5].push_back({3, 3});

    adjlist[4].push_back({5, 2});
    adjlist[5].push_back({4, 2});

    adjlist[4].push_back({6, 4});
    adjlist[6].push_back({4, 4});

    adjlist[6].push_back({5, 2});
    adjlist[5].push_back({6, 2});


    int mstWeight = Krushkal(v, adjlist );

    cout << "Weight of MST: " << mstWeight << endl;



}