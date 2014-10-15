#include<bits/stdc++.h>
using namespace std;
/* Head ends here */

int pairs(int a_size, int* a, int k) {
    
   int ans=0;
    int n=a_size;
    /* Write your code here */
    sort(a,a+n);
    
    int i,j,temp;
    i=0,j=0;
    while(j<=n-1)
        {
        if(a[j]-a[i]==k)
        {
            ans++;
            i++;
            j++;
        }
        else if(a[j]-a[i]<k)
            {
            j++;
        }
        else
            {
            i++;
        }
    }
   
   return ans;
}

/* Tail starts here */
int main() {
    int res;
   
    int _a_size,_a_i,_k;
    scanf("%d %d", &_a_size,&_k);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
   res=pairs(_a_size,_a,_k);
   printf("%d\n",res);    
    return 0;
}
