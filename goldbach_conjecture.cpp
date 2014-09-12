#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
#define max 1000000
int prime[max];

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


inline void fastRead_long(long long &x) {
    register long long c = getchar_unlocked();
    x = 0;
    long long neg = 0;

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


void initsow()
{
    int i,j,k;
    memset(prime,false,sizeof(prime));
    for(i=2;i<=sqrt(max);i++)
    {
        if(!(prime[i]))
        {
            for(j=2*i;j<=max;j+=i)
            {
                if(!prime[j]){prime[j]=true;}

            }
        }
    }

    for(i=2;i<=max;++i)
    {
        if(!(prime[i])){prime[i]=i;}
        else{prime[i]=prime[i-1];}
    }
}
int main()
{
    int i,j,k;
    initsow();
    //memset(prime,1,sizeof(prime));
    /*for(i=1;i<=100;i++)
    {
        printf("%d=%d\n",i,prime[i]);
    }*/
    int n,temp,start;
    //cin>>n;
    fastRead_int(n);
    while(n!=0)
    {
        start=n;
        while(1)
        {
            temp=prime[start];
            if(n-temp==prime[n-temp]){break;}
            start=temp-1;
        }
        printf("%d = %d + %d\n",n,n-temp,temp);
        //cin>>n;
        fastRead_int(n);
    }

    return 0;
}
