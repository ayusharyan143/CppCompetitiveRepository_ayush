// 0/1 Knapsack 


#include<bits/stdc++.h>
using namespace std ; 

int knapSack( int capacity , vector<int>  &profit , vector<int>  &weight , int n  )
{

    vector<vector<int>> dp( n+1 , vector<int>(capacity+1)) ;

    for( int i = 0 ; i <= n ; i++ )
    {
        for( int  j = 0 ; j <= capacity ; j++ )
        {
            if( i==0 || j==0 )
            {
                dp[i][j] = 0 ; 
            }
            else if( weight[i-1] <= j  )
            {
                dp[i][j] = max( profit[i-1] + dp[i-1][ j - weight[i-1]] , dp[i-1][j]) ;
            }
            else 
            {
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }

    return dp[n][capacity] ;

}





int main()
{
    int bag = 4 ; 
    vector<int>  profit  = {1,2,3};
    vector<int>  weight  = {4,5,1 };

    int n = profit.size();

    cout<<"maximum value  thief generated : "<< knapSack( bag , profit , weight , n );


}