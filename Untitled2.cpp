#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("i.txt","r",stdin);
	int n; cin>>n;
	int m; cin>>m;
	vector<int> vec;
	vec.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>vec[i];
	}
	int c=0,temp;
	char ch;
	while(m--){
		cin>>ch>>temp;
		if(ch=='R'){
			int x=temp-c;
			if(x<=0)cout<<vec[x+n]<<endl;
			else cout<<vec[x]<<endl;
		}
		else if(ch=='A'){
			c=(c+temp)%n;
		}
		else{
			c=(c+(n-temp))%n;
		}
	}
	return 0;
}
