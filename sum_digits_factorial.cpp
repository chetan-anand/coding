#include<bits/stdc++.h>
using namespace std;

int n,temp,sum;
int main ()
{   
    vector <int> digits(5000);    
    cin>>n;    
    digits[0]=1;
    digits[1]=1;
    for (int k=2;k<n+1;k++) {
        for (int i=1;i<=digits[0];i++) {
            digits[i]=digits[i]*k+temp;
            temp=0;
            if (digits[i]>9) {
                temp=digits[i]/10;
                digits[i]%=10;
                if (i==digits[0])
                digits[0]++;
            }
        }
    }   
    for (int i=digits[0];i>=1;i--)
        sum+=digits[i];
    std::cout<<sum;
}