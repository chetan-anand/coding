n,k=raw_input().split()
n=int(n)
k=int(k)
t=n*k
ans=(t**(n-2))%1000000007
ans = ans*((t-k)**(n*(k-1)))%1000000007
print int(ans%1000000007)