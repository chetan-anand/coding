#include<stdio.h>
#include<conio.h>
int main() {
    int input[] = {1,7,4,1,7,4,9,2};
    int count=0,LargestCount=0;
    for(int i=1;i<((sizeof(input)/sizeof(input[0]))-1);i++) {      //Here end before ARRAY_LENGTH-1
          if(((input[i-1]-input[i])>;0)&&((input[i]-input[i+1])<;0))
          {
               count++;                                        
          }
          else if (((input[i-1]-input[i])<;0)&&((input[i]-input[i+1])>;0))
          {
               count++;     
          } 
          else{
			  if(count>LargestCount) LargestCount = count; 
			  count=0;
          } 
		  if(count>LargestCount) LargestCount = count;
    }
    printf("The longest sequence is %d\n",LargestCount);    
    getch();
}