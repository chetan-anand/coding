global cnt
def func(x,mod,cnt):
	raw_input()
	if x%mod==0:
		print x
		return x
	if cnt>0:
		cnt=0
		return
	y=x
	func(x*10,mod,cnt+1)
	func(y*10+9,mod,cnt+1)


tc=int(raw_input())
for i in range(tc):
	n=int(raw_input())
	ans=func(9,n,0)