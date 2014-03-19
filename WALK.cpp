#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mat[100000];
    int n,t,i,tmp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int hat,j;
        hat=0;j=0;
        for(i=0;i<n;i++)
        {
            cin>>tmp;
            tmp=tmp+i;
            //if(i==0){hat=a[i];j=i;}
            if(hat<tmp)
            {
                hat=tmp;
                j=i;
            }
        }
        printf("%d\n",hat);
    }
    return 0;
}