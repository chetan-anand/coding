tc=int(raw_input())
while tc:
    n,m,q,k=raw_input().split()
    n,m,q,k=int(n),int(m),int(q),int(k)
    ans = 1
    for i in xrange(1,n):
        #print i
        ans=(((ans)%1000000007)*((q-i)%1000000007))%1000000007
    ans=(n*(n-1)*(m-q))%1000000007
    print ans
    
