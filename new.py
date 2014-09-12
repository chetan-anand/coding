n=int(raw_input())
i=n%4
#print i
cnt=1
if i==1:
	cnt=cnt+2+3
if i==2:
	cnt=cnt+4+4
if i==3:
	cnt=cnt+3+2
if i==0:
	cnt=cnt+1+1

i=n%2
if i==0:
	cnt=cnt+1
if i==1:
	cnt=cnt+4

print cnt%5


