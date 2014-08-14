#include<bits/stdc++.h>
using namespace std;

///////////////////////// fast i/o ////////////
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

inline void fastRead_long(long long int &x) {
    register long long int c = getchar_unlocked();
    x = 0;
    long long int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}


inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}

//////////////////////////////////////////////*/

typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%llu",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%llu\n",n)
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

//////////////// bondapa /////////////
#define all(a) a.begin(),a.end()
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<llu>::max()
#define lmin numeric_limits<llu>::min()
///////////////////////////////////////
long long int a[220000],b[220000],dp[220000];
int main()
{
    //freopen("i.txt","r",stdin);
    //clock_t start = clock();
    long long int n,i,j,k,tot;
    fastRead_long(n);
    long long int cnta=0;
    long long int cntb=0;
    tot=0;
    rep(i,n)
    {
        long long int temp;
        fastRead_long(temp);
        tot+=temp;
        if(temp==1)
        {
            fastRead_long(a[cnta]);
            cnta++;
        }
        else{
            fastRead_long(b[cntb]);
            cntb++;
        }
    }
    sort(a,a+cnta);
    sort(b,b+cntb);

//    rep(i,cnta)
//    {
//        cout<<a[i]<<endl;
//    }
//
//    rep(i,cntb)
//    {
//        cout<<b[i]<<endl;
//    }
//    cout<<tot<<endl;
    long long int tempa=cnta;
    long long int tempb=cntb;
    long long int cur=0,temp1,temp2,temp3;
    for(i=2;i<=tot;i+=2)
    {
        long long int flag=0;
        temp1=temp2=temp3=0;
        if(tempb>=1)
        {
            temp1=b[tempb-1];
        }

        if(tempa>=2)
        {
            temp2=a[tempa-1]+a[tempa-2];
        }
        else if(tempa>=1)
        {
            flag=1;
            temp3=a[tempa-1];
        }

        if(flag==1)
        {
            if(temp1>temp3)
            {
                cur+=temp1;
                dp[i]=cur;
                tempb-=1;
            }
            else
            {
                cur+=temp3;
                dp[i]=cur;
                tempa-=1;
            }
        }
        else
        {
            if(temp1>temp2)
            {
                cur+=temp1;
                dp[i]=cur;
                tempb-=1;
            }
            else
            {
                cur+=temp2;
                dp[i]=cur;
                tempa-=2;
            }
        }
    }

//    for(i=2;i<=tot;i+=2)
//    {
//        cout<<"w="<<dp[i]<<endl;
//    }

    tempa=cnta;tempb=cntb;
    cur=0;
    cur+=a[tempa-1];
    dp[1]=cur;
    tempa-=1;

    for(i=3;i<=tot;i+=2)
    {
        long long int flag=0;
        temp1=temp2=temp3=0;
        if(tempb>=1)
        {
            temp1=b[tempb-1];
        }

        if(tempa>=2)
        {
            temp2=a[tempa-1]+a[tempa-2];
        }
        else if(tempa>=1)
        {
            flag=1;
            temp3=a[tempa-1];
        }

        if(flag==1)
        {
            if(temp1>temp3)
            {
                cur+=temp1;
                dp[i]=cur;
                tempb-=1;
            }
            else
            {
                cur+=temp3;
                dp[i]=cur;
                tempa-=1;
            }
        }
        else
        {
            if(temp1>temp2)
            {
                cur+=temp1;
                dp[i]=cur;
                tempb-=1;
            }
            else
            {
                cur+=temp2;
                dp[i]=cur;
                tempa-=2;
            }
        }
    }

    for(i=1;i<=tot;i+=1)
    {
        printf("%lld ",dp[i]);
    }
    printf("\n");
    //while (clock() - start < (1.0 - 0.02) * CLOCKS_PER_SEC);
    //fclose(stdin);
	return 0;
}

