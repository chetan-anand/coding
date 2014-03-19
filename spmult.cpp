#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n;
	scanf("%lld",&t);
	while(t--)
	{
		queue<long long int> myqueue;
		scanf("%lld",&n);
		long long int init=9;
		myqueue.push(init);
		while(1)
		{
			long long int temp=myqueue.front();
			myqueue.pop();
			if(temp%n==0)
			{
				printf("%lld\n",temp);
				break;
			}
			myqueue.push(temp*10);
			myqueue.push(temp*10+9);
		}
	}
	return 0;
}