
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int max_cube[42][42][42];
int n;
double p;
int match[42][42][42];
int possible(int m,int imp)
{
   
    int ans=0;
    int c=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++)
            {
                c+=match[i][j][k];
            
                
            }
    
    max_cube[m-1][m-1][m-1]=c;
    
    
    
    for(int i=m;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                c=c+match[i][j][k]-match[i-m][j][k];
            }
        }
        
        
        max_cube[i][m-1][m-1]=c;
    
    }
    
    c=max_cube[m-1][m-1][m-1];
    
    
   
    
    
    
    for(int i=m;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                c=c+match[j][i][k]-match[j][i-m][k];
            }
        
        }
        
        max_cube[m-1][i][m-1]=c;
        
    }
    
    c=max_cube[m-1][m-1][m-1];
    
    
       
    
    
    for(int i=m;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
                {
                    c=c+match[k][j][i]-match[k][j][i-m];
                }
        }
        
        max_cube[m-1][m-1][i]=c;
        
    }
    
    c=max_cube[m-1][m-1][m-1];
    
    
       
    
    
    for(int i=m;i<n;i++)
    {
        for(int j=m;j<n;j++)
        {
            int d=0;
            for(int k=0;k<m;k++)
            {
                d=d+match[i][j][k]-match[i-m][j][k]-match[i][j-m][k]+match[i-m][j-m][k];
                
            }
            
            max_cube[i][j][m-1]=d+max_cube[i-1][j][m-1]+max_cube[i][j-1][m-1]-max_cube[i-1][j-1][m-1];
            
        
        }
    
    }
    
            
    
    for(int i=m;i<n;i++)
    {
        for(int j=m;j<n;j++)
        {
            int d=0;
            for(int k=0;k<m;k++)
            {
                d=d+match[k][i][j]-match[k][i-m][j]-match[k][i][j-m]+match[k][i-m][j-m];
                
            }
            
            max_cube[m-1][i][j]=d+max_cube[m-1][i-1][j]+max_cube[m-1][i][j-1]-max_cube[m-1][i-1][j-1];
            
            
        }
        
    }
    
    
       
    
    for(int i=m;i<n;i++)
    {
        for(int j=m;j<n;j++)
        {
            int d=0;
            for(int k=0;k<m;k++)
            {
                d=d+match[i][k][j]-match[i-m][k][j]-match[i][k][j-m]+match[i-m][k][j-m];
                
            }
            
            max_cube[i][m-1][j]=d+max_cube[i-1][m-1][j]+max_cube[i][m-1][j-1]-max_cube[i-1][m-1][j-1];
            
            
        }
        
    }
      
    
    for(int i=m;i<n;i++)
    {
        for(int j=m;j<n;j++)
        {
            for(int k=m;k<n;k++)
            {
                max_cube[i][j][k]=max_cube[i-1][j][k]+max_cube[i][j-1][k]+max_cube[i][j][k-1]-max_cube[i-1][j-1][k]-max_cube[i][j-1][k-1]-max_cube[i-1][j][k-1]+2*max_cube[i-1][j-1][k-1];
                
                int d=match[i][j][k]-match[i-m][j][k]-match[i][j-m][k]-match[i][j][k-m]+match[i-m][j-m][k]+match[i][j-m][k-m]+match[i-m][j][k-m]-2*match[i-m][j-m][k-m];
                
                max_cube[i][j][k]+=d;
            
            
            }
        
        }
    
    }
        // cout<<imp<<endl;
    for(int i=m-1;i<n;i++)
        for(int j=m-1;j<n;j++)
            for(int k=m-1;k<n;k++)
            {
                
                if(imp>=max_cube[i][j][k])
                    ans++;
            }
    
    
    
        
    
    return ans;
        

}
int f(int i,int j,int k)
{
    return n*n*i+n*j+k;
}
int main()
{
    int test;
    cin>>test;
    
    while(test--)
    {
        cin>>n>>p;
        
        string s1,s2;
        s1.clear();
        s2.clear();
        
        cin>>s1>>s2;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                {
                    if(s1[f(i,j,k)]==s2[(f(i,j,k))])
                        match[i][j][k]=0;
                    else
                        match[i][j][k]=1;
                    
                }
            // int start=1;
            //int end=n;
            //int curr=(start+end)/2;
        int impure;
       /* while(start<=end)
        {
            
            curr=(start+end)/2;
                // cout<<curr<<endl;
            impure=ceil((double)((100-p)*curr*curr*curr)/(double)(100));
                // cout<<impure<<endl;
            if(possible(curr,impure))
            {
                    //cout<<"yo";
                    //cout<<curr<<endl;
                start=curr+1;
                
            }
            
            else
            {
                    //cout<<"blah";
                end=curr-1;
            }
            
            
            
        }
            //cout<<curr<<impure<<endl;
        int ans;
        if(start!=1)
        {
            ans=possible(start-1,impure);
        
            if(ans)
                cout<<start-1<<" "<<ans<<endl;
        
        }
        
        else
            cout<<-1<<endl;
        */
        
        int ans=0;
        
        for(int i=n;i>=1;i--)
        {
            impure=(int)((double((double)100-p)*(double)i*(double)i*(double)i)/(double)(100));
            ans=possible(i, impure);
            if(ans)
            {
                cout<<i<<" "<<ans<<endl;
                break;
            }

            
        }
        
        if(!ans)
            cout<<-1<<endl;
        
        
        
    }


}