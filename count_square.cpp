#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_back
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

bool comp(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first<p2.first){return true;}
	else if(p1.first==p2.first)
	{
		return p1.second<p2.second?true:false;
	}
	else
	{
		return false;
	}
}

int main()
{
    //freopen("i.txt","r",stdin);
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector< pair<int,int> >p;
		bool hash[102][102];
		memset(hash,0,sizeof(hash));
		rep(i,n)
		{
			int x,y;
			cin>>x>>y;
			
			// to make it in the first quadrant
			x=x+50;
			y=y+50;

			//storing presence of point in hash table
			hash[x][y]=true;

			p.push_back(make_pair(x,y));
		}

		sort(p.begin(),p.end(),comp);
		//debug
		rep(i,p.size())
		{
			cout<<p[i].first<<" "<<p[i].second<<endl;
		}
		int cnt=0;
		fi(i,0,p.size()-1)
		{
			fi(j,i+1,p.size()-1)
			{
				if(p[j].first>p[i].first && p[j].second>p[i].second)
				{
					/*int dx=p[j].first-p[i].first;
					int dy=p[j].second-p[i].second;*/
					if(hash[p[i].first][p[j].second]&&hash[p[j].first][p[i].second])
					{
						cnt++;
						//cout<<i<<"and"<<j<<endl;
					}
					if(hash[p[i].first][2*p[j].second-p[i].first]&&hash[2*p[i].first-p[j].first][p[j].second])
					{
						cnt++;
						//cout<<i<<"and"<<j<<endl;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
    //fclose(stdin);
	return 0;
}
