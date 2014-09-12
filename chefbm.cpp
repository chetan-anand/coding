#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//using namespace std;
int main(){
int parr[100001][2];
int crow[100001],temp,temp1;
int col[100001];
int n,m,p,i,j,coun=1;
scanf("%d %d %d",&n,&m,&p);
for(i=1;i<=n;i++)
    crow[i]=0;
for(i=1;i<=p;i++){
    scanf("%d %d",&parr[i][0],&parr[i][1]);
    crow[parr[i][0]]++;
}
for(i=1;i<=n;i++){
    if(crow[i]==0)
      printf("%d\n",m-1);
    else if(crow[i]==1){
        printf("%d\n",m-1);
        coun++;
    }
    else {
        temp=0;
      for(j=1;j<=m;j++)
         col[j]=j;
            temp1=coun+crow[i];
       for(;coun<temp1;coun++)
        col[parr[coun][1]]++;
       for(j=m-1;j>0;j--){
          if(col[j+1]<col[j])
              break;
            temp=col[j+1]-col[j];
       }
       if(j==0)
           printf("%d\n",temp);
       else
        printf("-1\n");
    }
}
return 0;
}
