'''
Author : Chetan Anand
Contest: Hackerrank July
'''
def fact(n):
    ans=1
    for i in range(1,n+1):
        ans=ans*i
    return ans

s=raw_input()
list={}
len=0
nod=0
for ch in s:
    len=len+1
    list[ch]=[int(0)]
for ch in s:
    list[ch]=[list[ch][0]+1]
for row in list:
    if list[row][0]%2!=0:
        nod=nod+1
        if nod>1:
            break

if nod>1:
    print "0"
else:
    len=len/2
    #print len
    len=fact(len)
    #print len
    for row in list:
        len=len/fact(int(list[row][0])/2)
    len=len%1000000007
    print len
