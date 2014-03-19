def fact(m):
    ans=1
    for j in range(1,m+1):
        ans=ans * j
    return ans

tc=int(raw_input())
for i in range(tc):
    #print i
    n=int(raw_input())
    temp=fact(n)
    print temp
