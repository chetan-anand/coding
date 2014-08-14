#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,p,i,j;
    pair<int ,int > a[110000];
    int has[110000];
    memset(has,0,sizeof(has));
    cin>>n>>k>>p;
    for(i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        has[i]=temp;
        hasrev[temp]=i;
        a[i]=make_pair(temp,i);
    }

    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",a[i].first,a[i].second);
    }
    int idx;
    for(i=1;i<n;i++)
    {
        if(a[i+1].first)
    }
    for(i=0;i<p;i++)
    {
        int x,y;
        cin>>x>>y;
        int l=hasrev[has[x]];
        int r=hasrev[has[y]];
        bool flag=false;
        for()

    }

    return 0;
}
