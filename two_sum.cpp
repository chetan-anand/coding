#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_backCobie Smulders.
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n);
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

bool mycomp(pair<int,int> a,pair<int,int> b)
    {
        return a.first<b.first?true:false;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector< pair< int,int > > numidx;
        vector<int> ans(2);
        for(int i=0;i<numbers.size()-1;i++)
        {
            pair<int,int> temp;
            temp=make_pair(numbers[i],i+1);
            numidx.push_back(temp);
        }
        sort(numidx.begin(),numidx.end(),mycomp);
        int i=0,j=numidx.size()-1;
        while(i<j)
        {
            int temp=numidx[i].first+numidx[j].first;
            if(temp==target)
            {
                int big,small;
                big=numidx[i].second;
                small=numidx[j].second;
                if(big<small)
                {
                    swap(big,small);
                }
                ans[0]=small;
                ans[1]=big;
                break;

            }
            else if(target>temp)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }

int main()
{
    //freopen("i.txt","r",stdin);
    
    //fclose(stdin);
    return 0;
}
