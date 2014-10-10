#include <stdio.h>
#define INTMOD  25000000175LL
#define actualmod 1000000007
 
long long mod2mod(long long a, long long b) {
	long long t1;
 
	if (b > (long long) (1 << 60) / INTMOD) {
		t1 = 2 * mod2mod(a, b / 2) % INTMOD;
		if (b & 1)
			t1 = (t1 + a) % INTMOD;
		return t1;
	} else
		return a * b % INTMOD;
 
}
 
long long mod(long long n) {
	if (n == 1)
		return 26;
 
	long long t = mod(n / 2);
	// prlong longf ("for %lld returning %lld\n",n/2 , t);
	return (mod2mod(t, t)) *((n & 1) ? 26 : 1) % INTMOD;
 
}
 
int main(long long argc, char *argv[]) {
	long long t, n, ans;
	long long temp;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		temp = mod((n + (n & 1)) / 2);
		//printf("%lld-----\n", temp);
		ans = ((long long) 2 * (temp - 1) * 26 / 25 % actualmod- ((n & 1) ? temp : 0)) % actualmod;
		if (ans < 0)
			ans += actualmod;
		printf("%lld\n", ans);
	}
	return 0;
}