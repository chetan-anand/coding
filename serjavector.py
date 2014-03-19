
import sys
T=int(sys.stdin.readline())

for t in range(T):
    maxx=0
    Ans=[]
    N,k=map(int,sys.stdin.readline().split())
    L=[]
    for i in range(N):
        Q=list(map(int,sys.stdin.readline().split()))
        L.append(list(Q))
    A=list(map(int,sys.stdin.readline().split()))
    for i in range(5000):
        D=[0]*N
        T=[]
        R=list(range(0,N))
        random.shuffle(R)
        ind=0
        for item in R:
            enough=False
            for j in range(k):
                D[j]+=L[item][j]
                if(D[j]>A[j]):
                    enough=True
            if(enough):
                break
            ind+=1
        if(ind!=N):
            for j in range(k):
                D[j]-=L[ind][j]
        obj=0
        for j in range(k):
            obj+=A[j]-D[j]
        obj=ind/(obj+1)
        if(obj>maxx):
            maxx=obj
            Ans=R[:ind]
    Anss+=str(len(Ans))+"\n"
    
    if(len(Ans)!=0):
        Ans.sort()
        Anss+=str(Ans[0]+1)
        for i in range(1,len(Ans)):
            Anss+=" "+str(Ans[i]+1)
        Anss+="\n"
    Anss+="\n"
sys.stdout.write(Anss)   
            
            
            

