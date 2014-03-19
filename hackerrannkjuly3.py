t=int(raw_input())
for tc in range(t):
    n,k=raw_input().split()
    n,k=int(n),int(k)
    ans=1<<(n-1)
    ans=str(ans)
    #rans=ans[::-1]  reverses the string
    ans=int(ans[:k])+int(ans[-k:])
    print ans
