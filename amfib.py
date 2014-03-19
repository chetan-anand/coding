import math
def isPerfectSquare(x):
	s=math.sqrt(x)
	print "isPerfect YES"
	return (s*s == x)

def isFibonacci(n):
        print "isPerfect 
	return isPerfectSquare(5*n*n+4) | isPerfectSquare(5*n*n-4)

tc=int(raw_input())
for i in range(tc):
	n=int(raw_input())
	if isFibonacci(n):
		print "YES"
	else:
		print "NO"
	
