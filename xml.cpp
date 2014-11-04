#include <bits/stdc++.h>
using namespace std;

int main()
{
    //string str;
   // getline(cin,str,"\0");
    /*for(i=0;newstr[i];i++)
    {
        if(str[0])
    }*/
    string str;
    int asf;
    int cnt=0;
    for(string str;getline(cin,str);)
    {
  
        //cout<<str.size()<<endl;
        int o=0;
        while(str[o]==' ')
        {
            o++;
        }
        if(str[o]=='<')
        {
            //cout<<"debug"<<endl;
            if(str[o+1]!='/')
            {
                string temp;
                for(int i=o+1;i<str.size()-1;i++)
                {
                    temp=temp+str[i];
                }
                string ans;
                for(int j=0;j<2*cnt;j++)
                {
                    cout<<" ";
                }
                ans='%'+temp;
                //cout<<"cnt= "<<cnt<<endl;
                cout<<ans<<endl;
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        else
        {
            for(int j=0;j<2*cnt;j++)
            {
                cout<<" ";
            }
            cout<<str<<endl;
        }
    }
    return 0;
}