#include<bits/stdc++.h>
using namespace std;
int main()
    {
    int i,j,k,n;
    int a[200];
    cin>>n>>k;
    for(i=0;i<n;i++)
        {
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0,cnt,x;
    for(i=n-1,cnt=0;i>=0;i--,cnt++)
        {
       x=(int)(cnt/k) + 1;
       //cout<<x<<" "<<i<<endl;
        ans=ans+a[i]*x;
    }
    cout<<ans<<endl;
    return 0;
}