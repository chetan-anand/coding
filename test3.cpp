#include<bits/stdc++.h>
using namespace std;

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<int> temp;
        for(int i=0;i<matrix.size();i++)
        {
            temp.push_back(matrix[i][matrix[i].size()-1]);
            //cout<<matrix[i][matrix[i].size()-1]<<endl;
        }
        vector<int>::iterator low;
        low=lower_bound(temp.begin(),temp.end(),target);
        if(low==temp.end())
            {
                //cout<<"false"<<endl;
                return false;
            }
        int idx=low-temp.begin();
        //cout<<idx<<endl;;
       
        if(binary_search(matrix[idx].begin(),matrix[idx].end(),target))
        {
            return true;
        }
        return false;
    }
int main()
{
    vector< vector<int> > v;
    std::vector<int> temp;
    temp.push_back(1);
    v.push_back(temp);
    if(searchMatrix(v,2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}