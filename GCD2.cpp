#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    int temp;
    while(b)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    //freopen("i.txt","r",stdin);
    int t,i,j,k,temp;
    cin>>t;
    while(t--)
    {
        int a;
        string s;
        cin>>a>>s;
        int b=0;
        for(i=0;i<s.size();i++)
        {
            b=b*10+(s[i]-48);
            b=b%a;
        }
        cout<<gcd(a,b)<<endl;
    }
    //fclose(stdin);
	return 0;
}

