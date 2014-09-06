#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		string st;
		cin >> st;
	    int size = st.size();
		long long int answer = 1LL;
		//printf("a=%lld\n",answer);
		for(int i = 0; i < size; i++)
		{
			if(i%2==0 and st.substr(i,1)=="l")
				answer = (answer%MOD*2%MOD)%MOD;
			if(i%2==0 and st.substr(i,1)=="r"){
				answer = (answer%MOD*2%MOD)%MOD;
				answer = (answer%MOD + 2%MOD)%MOD;
			}

		if(i%2!=0 and st.substr(i,1)=="l"){
				answer = (answer%MOD*2%MOD)%MOD;
				answer = (answer%MOD - 1%MOD)%MOD;
			}
			if(i%2!=0 and st.substr(i,1)=="r"){
				answer = (answer%MOD*2%MOD)%MOD;
				answer = (answer%MOD + 1%MOD)%MOD;
			}

		}
		cout << answer << endl;
	}
	//fclose(stdin);
	return 0;
}
