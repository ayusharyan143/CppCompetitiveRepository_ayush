// Navi string matching 

#include<bits/stdc++.h>

using namespace std ; 



void naviSearch( string t , string p )
{
    int n = t.size();
    int m = p.size();

    for( int i = 0 ; i <= n-m ; i++ )
    {
        int j ;

        for( j = 0 ; j < m ; j++ )
        {
            if( t[i+j] != p[j] )
            {
                break ; 
            }
        }

        if( j == m ) cout<<"Pattern is found in Text at Shift : "<<i<<endl ; 
    }


}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA" ;

    naviSearch( text , pattern );


}