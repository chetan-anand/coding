# your code goes here
import json

str1={"Geeks":"Test1","Are":"hey","Cool":"yeah"}
str2={"Geeks":"Test1","Are":"20","Cool":['B','C']}
ans=""
for key1,val1 in str1.items():
	for key2,val2 in str2.items():
		if(key1==key2):
			if(val1!=val2):
				#print(key1)
				ans=ans+key1+':'
ans=ans[:-1]
print ans