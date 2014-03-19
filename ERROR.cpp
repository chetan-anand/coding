#include <bits/stdc++.h>
using namespace std;

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

int main(void) 
{
	int t,i,j,k,l,temp;
	char s[110000];
	fastRead_int(t);
	while(t--)
	{
		temp=0;
		fastRead_string(s);
  		//printf("%s\n", s);
		if(strlen(s)<3){printf("Bad\n");}
		else
		{
			for(i=0;i<=strlen(s)-3;i++)
			{
				if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0')
				{
					temp=1;
					break;
				}
				else if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1')
				{	
					temp=1;	
					break;
				}
			}
			if(temp==0){printf("Bad\n");}
 			else{printf("Good\n");}
		} 
 	}
	return 0;
}