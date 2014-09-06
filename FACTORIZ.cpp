#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("i.txt","r",stdin);
    long long int t,n,m,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<long long int> ans;
        //int cnt=0;
        long long int temp=n;
        for(long long int d = 2; d*d <= temp; d++){
            while(temp % d == 0){
                //cnt++;
                ans.push_back(d);
                temp /= d;
            }
        }
        if(temp != 1)
        {
            //cnt++;
            ans.push_back(temp);
        }
        //cout<<cnt<<endl;
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
    }
	return 0;
}

