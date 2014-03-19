#include<bits/stdc++.h>
using namespace std;

inline void fastRead_int(long long int &x) {
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

int temp[10000];
int main() 
{ 
    long long int a,b,l,d,s,c,t;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld %lld",&l,&d,&s,&c);
        a=s;
        if(d==1)
        {
            if(s>=l){printf("\nALIVE AND KICKING");}
            else{printf("\nDEAD AND ROTTING");}
        }
        else
        {
            for(b=1;b<d;b++)
            {
                a=a+a*c;
                if(a>=l){break;}
            }
            if(a<l){printf("\nDEAD AND ROTTING");}
            else{printf("\nALIVE AND KICKING");}
        }
    }
    return 0;
} 