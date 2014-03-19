tc=int(input())
for t in range(tc):
    n=int(input())
    l=list(map(int,input().split()))
    a,b,c=map(int,input().split())
    st=input()
    fuck=True;
    temp1=0
    temp=1
    x=0
    y=n-1
    for i in range(n):
        if(st[i]=='R'):
            x,y=y,x
            fuck=not fuck
        elif(st[i]=='A'):
        	temp1=(temp1%c+a)%c
        else:
        	temp,temp1=temp%c*b,temp1%c*b
        l[x]=(l[x]*temp+temp1)%c
        if(i==n-1):
        	print(l[x])
        else:
        	print(l[x],end=" ")
        if(fuck):
        	x+=1
        else:
        	x-=1