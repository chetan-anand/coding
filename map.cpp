#include <iostream>
#include <map>
#include <string>
using namespace std;

int main ()
{
  int i;
  map<char,string> mymap;
  map<int,int> mapi;
  pair<int,int> temp;

  /*iserting process
  a) either by mapname[key]=value -> last insert will be there
  b) or by inserting using pair -> insert cannot happen if map already contain the key
  */
  
  for(i=10;i>=1;i--)
  {
    temp=make_pair(i,i+2);
    mapi.insert(temp);
  }
  for(i=10;i>=1;i--)
  {
    temp=make_pair(i,i+2);
    mapi.insert(temp);
  }
  //////////////////////////////////////////////////////////////////////////////////////
  /*Access process -> 
  a) by -> or by .*/
    
  map<int,int>:: iterator it;

  for(it=mapi.begin();it!=mapi.end();it++)
  {
    cout<<it->first<<" "<<it->second<<endl;
  }
  for(it=mapi.begin();it!=mapi.end();it++)
  {
    cout<<(*it).first<<" "<<(*it).second<<endl;
  }

  for(i=0;i<mapi.size();i++)
  {
    cout<<mapi[i]<<endl;
  }

cout << "map now contains " << mapi.size() << " elements." << endl;

  // mymap['a']="an element";
  // mymap['b']="another element";
  // mymap['c']=mymap['b'];

  // cout << "mymap['a'] is " << mymap['a'] << endl;
  // cout << "mymap['b'] is " << mymap['b'] << endl;
  // cout << "mymap['c'] is " << mymap['c'] << endl;
  // //cout << "mymap['d'] is " << mymap['d'] << endl;

  // cout << "mymap now contains " << (int) mymap.size() << " elements." << endl;

  return 0;
}