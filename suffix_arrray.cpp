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

// contain the sorted suffixes of the text
pair <string,int> suffix_array[10000];

//compare function for suitable for our data container
bool comp(pair<string,int> s1,pair<string,int> s2)
{
    return s1.first<s2.first?true:false;
}


// here we are building suffix array
// Time complexity = O(n*log(n))
void build_suffix_array(string text)
{
    int i,j,k,temp;
    string str;
    int len=text.size();
    // suffixes and their position stored in container
    fd(i,text.size()-1,0)
    {
        str=text[i]+str;
        cout<<"suffixes="<<str<<endl;
        suffix_array[i]=mp(str,i);
    }
    // now sort the suffix_array
    sort(suffix_array,suffix_array+len,comp);
    rep(i,len)
    {
        cout<<suffix_array[i].first<<" "<<suffix_array[i].second<<endl;
    }
}

/// search the pattern using binary search
// search query= O(log(n))
bool search(string text,string pattern)
{
    if(pattern.size()>text.size()){return false;}
    int l=0,r=text.size()-1;

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(pattern.compare(0,pattern.size(),suffix_array[mid].first,0,pattern.size())==0)
        {
            cout<<"Is here= "<<suffix_array[mid].second<<endl;
            break;
        }

        else if(pattern<suffix_array[mid].first)
            r=mid-1;
        else
            l=mid+1;
    }
    return false;
}
int main()
{
    //freopen("i.txt","r",stdin);
    string text,pattern;
    int i,j,k,temp;
    text="banana";
    pattern="banana";
    cout<<text<<endl;
    build_suffix_array(text);
    search(text,pattern);
    //fclose(stdin);
	return 0;
}
