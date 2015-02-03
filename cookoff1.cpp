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

//////////////////////////////////////////////

int main()
{
    int t;
    //cin>>t;
    fastRead_int(t);
    while(t--)
    {
        string str;
        cin>>str;
        //fastRead_string(str);
        int cnt=0;
        int maxv=INT_MIN;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='(')
            {

                cnt++;
            }
            else
            {

                cnt--;
            }
            maxv=max(maxv,cnt);
        }
        //cout<<maxv<<endl;
        string temp;
        for(int i=0;i<maxv;i++)
        {
            temp=temp+'(';
        }
        for(int i=0;i<maxv;i++)
        {

            temp=temp+')';
        }
        cout<<temp<<endl;
    }

    return 0;
}
