#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	//cin>>n;
   // vector<int> myvec;
    vector< vector<int> >temp(9 );
  //  myvec.resize(n);
//    cout<<myvec.size()<<endl;
//    for(int i=0;i<myvec.size();i++)
//    {
//
//        cout<<myvec[i]<<endl;
//    }
    cout<<temp.size()<<endl;
    cout<<temp[0].size()<<endl;
    for(int i=0;i<temp.size();i++)
    {

        for(int j=0;j<temp[0].size();j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
