def solve(n):
    ans=1
    for j in range(n):
        k=j%26
        ans=((ans%1000000009)*((26-k)%1000000009))%1000000009
        #print ans
    return ans


tc=int(raw_input())
for i in range(tc):
    n=int(raw_input())
    print solve(n)
