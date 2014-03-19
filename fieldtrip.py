def nck(n, k):
	if k>n or k<0:
		return 0
	if k<n-k:
		k = n-k
	ans = 1
	for i in range(1, n-k+1):
		ans = ans * (k+i) / i
	return ans

tc=int(raw_input())
while tc:
	m,n=raw_input().split()
	m,n=int(m),int(n)
	ans=(nck(m+n-2,m-1))%1000000007
	print ans
	tc=tc-1