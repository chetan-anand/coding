#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////

///////////////////////// fast i/o ////////////
inline void fastRead_int(int &x) { 
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
        x = -x;
}


inline void fastRead_long(long long &x) {
    register long long c = getchar_unlocked();
    x = 0;
    long long neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
        x = -x;
}



///////////////////////////////////////////////////////////////////////
bool removable(vector<int> neighbor, vector<int> cover);
int max_removable(vector<vector<int> > neighbors, vector<int> cover);
vector<int> procedure_1(vector<vector<int> > neighbors, vector<int> cover);
vector<int> procedure_2(vector<vector<int> > neighbors, vector<int> cover, int k);
int cover_size(vector<int> cover);
/*ifstream infile ("i.txt");
ofstream outfile ("sets.txt");*/

int main()
{
 //Read Graph
 //cout<<"Independent Set Algorithm."<<endl;
 int temp,n,m, i, j, k, K, p, q, r, s, min, edge, counter=0;

/////////////////////////////////////////////////////////////////////////////////

int a[21][21],ki[22][21000];
    memset(a,0,sizeof(a));memset(ki,0,sizeof(ki));
    fastRead_int(temp);
    fastRead_int(m);
    for(i=0;i<m;i++)
    {
        fastRead_int(k);
        for(j=0;j<k;j++)
        {
            fastRead_int(temp);
            ki[i][temp]=1;
        }
    }

    for(i=0;i<m-1;i++)
    {
        bool edge=false;
        for(j=i+1;j<m;j++)
        {
            for(k=1;k<=temp;k++)
            {
                if(ki[i][k]==1 && ki[j][k]==1){a[i][j]=1;a[j][i]=1;}
            }
        }
    }
    /*printf("%d\n",m);
    for (i = 0; i < m; ++i)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/



 /////////////////////////////////////////////////////////////////////////////////




 //infile>>n;
 n=m;
 vector< vector<int> > graph;
 for(i=0; i<n; i++)
 {
  vector<int> row;
  for(j=0; j<n; j++)
  {
   //infile>>edge;
    edge=a[i][j];
   row.push_back(edge);
  }
  graph.push_back(row);
 }
 //Find Neighbors
 vector<vector<int> > neighbors;
 for(i=0; i<graph.size(); i++)
 {
  vector<int> neighbor;
  for(j=0; j<graph[i].size(); j++)
  if(graph[i][j]==1) neighbor.push_back(j);
  neighbors.push_back(neighbor);
 }
 //cout<<"Graph has n = "<<n<<" vertices."<<endl;
 //Read maximum size of Independent Set wanted
 //cout<<"Find an Independent Set of size at least k = ";
 //cin>>K;
 K=n; 
 k=n-K;
 //Find Independent Sets
 bool found=false;
 //cout<<"Finding Independent Sets..."<<endl;
 min=n+1;
 vector<vector<int> > covers;
 vector<int> allcover;
 for(i=0; i<graph.size(); i++)
 allcover.push_back(1);
 for(i=0; i<allcover.size(); i++)
 {
  if(found) break;
  counter++;
  // cout<<counter<<". ";  outfile<<counter<<". ";
  vector<int> cover=allcover;
  cover[i]=0;
  cover=procedure_1(neighbors,cover);
  s=cover_size(cover);
  if(s<min) min=s;
  if(s<=k)
  {
   //outfile<<"Independent Set ("<<n-s<<"): ";
   for(j=0; j<cover.size(); j++) if(cover[j]==0) 
    /*outfile<<j+1<<" ";
   outfile<<endl;*/
   //cout<<"Independent Set Size: "<<n-s<<endl;
   covers.push_back(cover);
   found=true;
   break;
  }
  for(j=0; j<n-k; j++)
  cover=procedure_2(neighbors,cover,j);
  s=cover_size(cover);
  if(s<min) min=s;
  //outfile<<"Independent Set ("<<n-s<<"): ";
  for(j=0; j<cover.size(); j++) if(cover[j]==0) 
    //outfile<<j+1<<" ";
  //outfile<<endl;
  //cout<<"Independent Set Size: "<<n-s<<endl;
  covers.push_back(cover);
  if(s<=k){ found=true; break; }
 }
//Pairwise Intersections
 for(p=0; p<covers.size(); p++)
 {
  if(found) break;
  for(q=p+1; q<covers.size(); q++)
  {
   if(found) break;
   counter++; 
   //cout<<counter<<". ";  
   //outfile<<counter<<". ";
   vector<int> cover=allcover;
   for(r=0; r<cover.size(); r++)
   if(covers[p][r]==0 && covers[q][r]==0) cover[r]=0;
   cover=procedure_1(neighbors,cover);
   s=cover_size(cover);
   if(s<min) min=s;
   if(s<=k)
   {
    //outfile<<"Independent Set ("<<n-s<<"): ";
    for(j=0; j<cover.size(); j++) if(cover[j]==0) 
        //outfile<<j+1<<" ";
    //outfile<<endl;
    //cout<<"Independent Set Size: "<<n-s<<endl;
    found=true;
    break;
   }
   for(j=0; j<k; j++)
   cover=procedure_2(neighbors,cover,j);
   s=cover_size(cover);
   if(s<min) min=s;
   //outfile<<"Independent Set ("<<n-s<<"): ";
   for(j=0; j<cover.size(); j++) if(cover[j]==0) 
    /*outfile<<j+1<<" ";
   outfile<<endl;*/
   //cout<<"Independent Set Size: "<<n-s<<endl;
   if(s<=k){ found=true; break; }
   }
 }
 if(found)
  {
        cout<<n<<endl;
}
    //cout<<"Found Independent Set of size at least "<<K<<"."<<endl;
 else 
    cout<<n-min<<endl;
// cout<<"See sets.txt for results."<<endl;
 return 0;
}

bool removable(vector<int> neighbor, vector<int> cover)
{
 bool check=true;
 for(int i=0; i<neighbor.size(); i++)
 if(cover[neighbor[i]]==0)
 {
  check=false;
  break;
 }
 return check;
}

int max_removable(vector<vector<int> > neighbors, vector<int> cover)
{
 int r=-1, max=-1;
 for(int i=0; i<cover.size(); i++)
 {
  if(cover[i]==1 && removable(neighbors[i],cover)==true)
  {
   vector<int> temp_cover=cover;
   temp_cover[i]=0;
   int sum=0;
   for(int j=0; j<temp_cover.size(); j++)
   if(temp_cover[j]==1 && removable(neighbors[j], temp_cover)==true)
   sum++;
   if(sum>max)
   {
    if(r==-1)
    {
     max=sum;
     r=i;
    }
    else if(neighbors[r].size()>=neighbors[i].size())
    {
     max=sum;
     r=i;
    }
   }
  }
 }
 return r;
}

vector<int> procedure_1(vector<vector<int> > neighbors, vector<int> cover)
{
 vector<int> temp_cover=cover;
 int r=0;
 while(r!=-1)
 {
  r= max_removable(neighbors,temp_cover);
  if(r!=-1) temp_cover[r]=0;
 }
 return temp_cover;
}

vector<int> procedure_2(vector<vector<int> > neighbors, vector<int> cover, int k)
{
 int count=0;
 vector<int> temp_cover=cover;
 int i=0;
 for(int i=0; i<temp_cover.size(); i++)
 {
  if(temp_cover[i]==1)
  {
   int sum=0, index;
   for(int j=0; j<neighbors[i].size(); j++)
   if(temp_cover[neighbors[i][j]]==0) {index=j; sum++;}
   if(sum==1 && cover[neighbors[i][index]]==0)
   {
    temp_cover[neighbors[i][index]]=1;
    temp_cover[i]=0;
    temp_cover=procedure_1(neighbors,temp_cover);
    count++;
   }
   if(count>k) break;
  }
 }
 return temp_cover;
}

int cover_size(vector<int> cover)
{
 int count=0;
 for(int i=0; i<cover.size(); i++)
 if(cover[i]==1) count++;
 return count;
}

