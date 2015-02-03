#!/usr/bin/env python3
 
i = 2
st = [None]*i
 
for no in range(0,i):    
    s = input()
    st[no] = s.replace('{','').replace('}','')
    st[no] = st[no].split('","')
 
lt1 = len(st[0])
lt2 = len(st[0])
 
if (not(st[0] == st[1]) or lt1 != lt2):
    for j in range(0, lt1):
        if (st[0][j] != st[1][j]):
            key = str(st[0][j]).replace('"','').split(':')[0]
            if((j != lt1-1)):
                print("%s:" % key, end = "")
            else:
                print(key)# your code goes here