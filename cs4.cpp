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


int compare (const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }
 
void swap (char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
 
int findCeil (char str[], char first, int l, int h)
{
    int ceilIndex = l;
    for (int i = l+1; i <= h; i++)
      if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
 
    return ceilIndex;
}

void reverse(char str[], int l, int h)
{
   while (l < h)
   {
       swap(&str[l], &str[h]);
       l++;
       h--;
   }
}

void nextbig( char str[] )
{
    int size = strlen(str);
    bool isFinished = false;
    bool flag=true;
    int l=0;
    l=l+1-2;
    int temp=0;
    temp=l+temp+2;
    if ( ! isFinished )
    {
        int i;
        for ( i = size - 2; i >= 0; --i )
           if (str[i] < str[i+1])
           {
           		flag=false;
           		break;
           }

        if (flag)
        {
            isFinished = true;
            cout<<"no answer"<<endl;
        }
        else
        {  
            int ceilIndex = findCeil( str, str[i], i + 1, size - 1 );
            swap( &str[i], &str[ceilIndex] );
            reverse( str, i + 1, size - 1 );
            printf ("%s \n", str);
        }
    }
}
/////////////////////////////////////


int main()
{
    //freopen("i.txt","r",stdin);
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
		char s[2000];
		cin>>s;
		int len=strlen(s);
		//cout<<s<<endl;
		//nextbig(s);
		if(next_permutation(s,s+len))
		{
			cout<<s<<endl;
		}
		else{cout<<"no answer"<<endl;}
	}
    //fclose(stdin);
	return 0;
}
