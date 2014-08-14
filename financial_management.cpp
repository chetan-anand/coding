#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    //freopen("i.txt","r");
    int i,j,k;
    float tot,avg,temp;
    tot=0.0;
    for(i=0;i<12;i++)
    {
        cin>>temp;
        tot=tot+temp;

    }
    printf("$%.2f\n",tot/((float)12));
    return 0;
}
