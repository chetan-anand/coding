#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
int const mx = 6666;
set <unsigned long long> f;
unsigned long long fib[mx + 10];
char s[mx + 1];
int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	fib[0] = 0;
	fib[1] = 1;
	f.insert(1);
	f.insert(0);
	int i;
	for (i = 2; i <= mx; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		f.insert(fib[i]);
	}

	for (int i = 0; i <=mx; ++i)
	{
		/* code */
		printf("%llu\n",fib[i] );
	}

	int tc;
	cin>>tc;
	while (tc--){
		unsigned long long n = 0, ten = 10;
		cin>>s;
		int len = strlen(s);
		for (i = 0; i <	len; i++){
			char q = s[i];
			unsigned long long a = q - '0';
			n = n * ten + a;
		}
		printf("n=%llu\n",n );
		if (f.find(n) == f.end()) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
} 

//7766279631452241920   100000000000000000000
