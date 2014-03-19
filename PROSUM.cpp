#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    
	ll t,i,j,k,n,temp,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=b=c=0;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            if(temp==0 || temp==1){a++;}
            else if(temp==2){b++;}
            else{c++;}

        }
        ll ans=(n*(n-1))/2;
            n=a+b;
            ans-=(n*(n-1))/2;
            ans-=c*a;
            printf("%lld\n",ans );
    }

    return 0;
}