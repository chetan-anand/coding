#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	long long int inp,i,j,k;
	cin>>inp;
	if(inp%3==0){printf("yes\n");}
	else if ((inp+5)%6==0){printf("yes\n");}
	else{printf("no\n");}
	return 0;
}