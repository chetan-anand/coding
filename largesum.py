tc=int(raw_input())
cnt=0
for i in range(tc):
    n=int(raw_input())
    cnt=cnt+n
k=0
s=""
for i in str(cnt):
    k=k+1
    s=s+i
    if k==10:
        break
print s