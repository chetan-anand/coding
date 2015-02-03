#include <iostream>
#include <vector>
#define SIZE 8
#define debug(x) {cout << #x << " : " << x << endl ;}
using namespace std;
 
int main(){
    
    int a[SIZE] = {1,7,4,1,7,4,9,2};
 
    int signs[SIZE] = {0};
    int dp[SIZE] = {1};
    // we have to find the longest zig zag sequence till i
    for(int i=1;i<SIZE;i++){
        /* 
        * For each i, we should figure out the previous element to jump from.
        * it can be the one right before i or it could be element at index 0.
        * so we have to go all the way from i-1 down to 0.
        */
        
        for(int j = i-1; j>=0; j--){
            /* 
            * What's most important is.. we cannot jump from any element.. 
            * we are looking for an element which when subtracted from this 
            * has the desired sign. variable sign indicates whether the previous 
            * was a positive jump or a negative jump. 
            */
            
            int sign = signs[j];
            
            if( (sign == 0) || ( (sign < 0) && (a[i] - a[j] > 0) ) || 
                    ( (sign > 0) && (a[i] - a[j] < 0) ) ){
                 /*
                 The different cases.
                 1. sign == 0 : We are just beginning.. we can pick either 
                        positive difference or negative difference.
                        
                 2. (sign < 0) && (a[i] - a[j] > 0) : Previous value resulted in a negative 
                        difference, so we need to pick a positive differencevalue
                 3. (sign > 0) && (a[i] - a[j] < 0) : Previous value resulted in a positive 
                        difference, pick negative difference this time.
 
                 Once we have found an element, store the difference in signs, so that it 
                 helps in subsequent iterations.
                */
                dp[i] = dp[j] + 1;
                
                signs[i] = a[i] - a[j];
                break;
            }
        }
    }
 
    cout << dp[SIZE-1] << endl;
    return 0;
}