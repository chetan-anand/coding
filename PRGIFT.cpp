#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("i.txt","r",stdin);
    //clock_t start = clock();
    int i,j,t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int cnt=0;
        for(i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            if(temp%2==0){cnt++;}

        }
        //cout<<cnt<<endl;
        if(k==0  )
        {
            if(cnt<n)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            if(cnt>=k){cout<<"YES"<<endl;}
            else{cout<<"NO"<<endl;}
        }

    }
    //while (clock() - start < (1.0 - 0.02) * CLOCKS_PER_SEC);
    return 0;
}
