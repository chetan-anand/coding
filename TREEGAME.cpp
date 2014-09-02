#include<bits/stdc++.h>
using namespace std;
int depth[200002];
vector<int> adj[200002];
int main()
{
    //freopen("i.txt","r",stdin);
    clock_t start = clock();
    int t,i,j,k,n,m;
    cin>>t;
    while(t--)
    {

        memset(depth,0,sizeof(depth));

        cin>>n;
        ///// making adjacency list
        for(i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=0;j<adj[i].size();j++)
//            {
//                cout<<adj[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        /// level order transversal;
        int level=0;
        depth[1]=1;
        queue<int> q;
        q.push(1);
        int cnt=1;
        int loop=3;
        while(!(q.empty()))
        {
            level++;
            for(j=0;j<cnt;j++)
            {
                int temp;
                temp = q.front();
                //printf("%d ",temp);
                q.pop();
                depth[temp]=level;
                for(i=0;i<adj[temp].size();i++)
                {
                    q.push(adj[temp][i]);
                }

            }
            //printf("sljkdf");
            //cout<<endl;
            cnt=q.size();
        }
        ///////////////////////////////////
        sort(depth+1,depth+n+1);
//        cout<<"level="<<level<<endl;
//        for(i=1;i<=n;i++)
//        {
//            printf("%d ",depth[i]);
//        }
//        cout<<endl;
        cnt=0;
        int start=1;
        int en=n;
        while(1)
        {
            //cout<<"a"<<endl;
            for(i=start;;i++)
            {
                //cout<<"b"<<endl;
                if(depth[i+1]!=depth[i])
                {
                    //cout<<"c"<<endl;
                    start=i+1;
                    break;
                }
            }
            cnt++;
            if(depth[start]==0){
                   // cout<<"d"<<endl;
            break;}
            depth[en]=0;
            en--;
            cnt++;
            if(depth[start]==0){
                   // cout<<"d"<<endl;
            break;}
        }
        cout<<cnt<<endl;
        for(i=0;i<=n;i++)
        {
            adj[i].clear();
        }
    }

    while (clock() - start < (1.0 - 0.02) * CLOCKS_PER_SEC);
    return 0;
}
