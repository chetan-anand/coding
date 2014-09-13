#include<iostream>
#include<map>
#include<utility>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<fstream>
#define ll long long

#define s(x) scanf("%d",&(x))
#define print(x) printf("%d ",x)
#define printnl(x) printf("%d\n",x);
#define forI(i,a,b) for(int i=(a);i<=(b);i++)
#define forD(i,a,b) for(int i=(a);i>=(b);--i)
#define MOD 1000000007
#define INF_LONG 8999999999999999999
#define FOUND 1
#define NOTFOUND 0
#define INF 1000000000
using namespace::std;
int main()
{
    int len;
    bool in_queue[100010];
    queue<int> dijkstra;
    bool done_with[10];
    vector<vector<int> > node_val(10);      /*indices of nodes with digit value i*/
    char digits[100010];                    /*stores the string entered by user*/
    int dis[100010];                        /*stores the minimum distance of each node*/
    cin>>(digits+1);
    /*initialisations*/
    dis[0]=-1;
    for(int i=1;i<=100009;++i)
        dis[i]=100;
    for(int i=0;i<=9;++i)
        done_with[i]=false;
    for(int i=0;i<100009;++i)
        in_queue[i]=false;
    for(int i=1;digits[i]!='\0';++i)
    {
        node_val[digits[i]-'0'].push_back(i);
        len=i;
    }
    ++len;
    dis[len]=-1;


    /*base case*/
    dis[1]=0;
    dijkstra.push(1);
    in_queue[1]=true;

    /*inductive step*/
    while(dijkstra.empty()==false)
    {
        int node=dijkstra.front();          /*node<-index*/
        if(node==len-1)
        {
            cout<<dis[node];
            return 0;
        }
        dijkstra.pop();
        if(done_with[digits[node]-'0']==false)
        {
            done_with[digits[node]-'0']=true;
            //int i;
            for(auto i:node_val[digits[node]-'0'])
            {
                if(i!=node)
                {
                    dis[i]=dis[node]+1;
                    dijkstra.push(i);
                    in_queue[i]=true;
                }
            }
        }
        if(dis[node+1]==100 && in_queue[node+1]==false)
        {
            dis[node+1]=dis[node]+1;
            dijkstra.push(node+1);
            in_queue[node+1]=true;
        }
        if(dis[node-1]==100 && in_queue[node-1]==false)
        {
            dis[node-1]=dis[node]+1;
            dijkstra.push(node-1);
            in_queue[node-1]=true;
        }
    }
    /*for(int i=1;i<len;++i)
        cout<<dis[i];*/
    cout<<dis[len-1];
    return 0;
}
