
import sys.psyco
psyco.full()
def solve(n):
    cnt=0
    while n:
        n=n/5
        cnt=cnt+n
    return cnt

#tc=int(raw_input())
tc=sys.stdin.readline()
for i in range(tc):
    n=int(raw_input())
    print solve(n)
