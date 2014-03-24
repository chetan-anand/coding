// ABCSTR
// ABC-Strings
// Author: Constantine Sokol
// Complexity : O( |S| log |S| )
// Expected Verdict: AC
 
#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
 
using namespace std;
 
const int maxn = 1000100;
 
int n;
char s[ maxn ]; 
pair< int, int > p[ maxn ];
 
int main ()
{
    
    s[0] = '0'; gets( s + 1 ); n = strlen( s ) - 1;
    int a = 0, b = 0, c = 0;
    p[0] = make_pair( 0, 0 );
    for ( int i = 1; i <= n; i++ )
    {
        a += ( s[i] == 'A' );
        b += ( s[i] == 'B' );
        c += ( s[i] == 'C' );
        p[i] = make_pair( b - a, c - a );
    }
    /*cout<<"Bfore\n";
    for(int i=0;i<=n;i++)
    {
        printf("%d %d\n",p[i].first,p[i].second );
    }*/


    sort( p, p + n + 1 );
    /*cout<<"after\n";
    for(int i=0;i<=n;i++)
    {
        printf("%d %d\n",p[i].first,p[i].second );
    }*/


    long long answer = 0, plus = 0;
    pair< int, int > last( -1000000000, -1000000000 );
    for ( int i = 0; i <= n; i++ )
    {
        if ( p[i] != last )
        {
            last = p[i];
            plus = 0;
        }
        answer += plus;
        plus += 1;
    }
    printf("%lld\n", answer);
    return 0;
    return 0;
} 