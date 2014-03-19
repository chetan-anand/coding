#include <bits/stdc++.h>

#define MAX 110
#define undef -2
#define empty -1
#define noEdge 0
#define unmatched 1
#define matched 2
#define forward 0
#define reverse 0
     


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
 
inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
 
    str[i] = '\0';
}

struct Label {      
       int even;    
       int odd[2];  
};                  
                
struct elem {            
       int vertex,type;  
};                       
 
 
int g[MAX][MAX];         
int blossom[MAX];        
int path[2][MAX],endPath[2];  
bool match[MAX];  
Label label[MAX]; 
elem queue[2*MAX];         
int queueFront,queueBack;  
 
void initGraph(int n){
     for (int i=0; i<n; i++)
         for (int j=0; j<n; j++) g[i][j]=noEdge;
}
 
int readGraph(){
     int n,e,a,b;
     scanf(" %d %d",&n,&e);      
     //initGraph(n);               
     //ver=n;e=edg;
     //if(n%2!=0){return -1;}
     for (int i=0; i<e; i++){    
         scanf(" %d %d",&a,&b);
         if (a!=b)
            g[a-1][b-1]=g[b-1][a-1]=unmatched;
     }
     return n;
}
 
void initAlg(int n){             
     queueFront=queueBack=0;     
     for (int i=0; i<n; i++){    
         blossom[i]=i;
         label[i].even=label[i].odd[0]=label[i].odd[1]=undef;
     }
}
 
void backtrace (int vert, int pathNum, int stop, int parity, int direction){
     if (vert==stop) return;           
     else if (parity==0){              
        if (direction==reverse){
           backtrace(label[vert].even,pathNum,stop,(parity+1)%2,reverse);
           path[pathNum][endPath[pathNum]++]=vert;
        }                             
        else if (direction==forward){ 
             path[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].even,pathNum,stop,(parity+1)%2,forward);
        }
     }

     else if (parity==1 && label[vert].odd[1]==undef){
        if (direction==reverse){
           backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,reverse);
           path[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==forward){
             path[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,forward);
        }
     }
     
     else if (parity==1 && label[vert].odd[1]!=undef){
          if (direction==reverse){
             backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,reverse);
             backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,forward);
             path[pathNum][endPath[pathNum]++]=vert;
          }
          else if (direction==forward){
               backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,reverse);
               backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,forward);
               path[pathNum][endPath[pathNum]++]=vert;
          }
     }
}
 
void enqueue (int vert, int t){
     elem tmp;               
     tmp.vertex=vert;        
     tmp.type=t;             
     queue[queueBack++]=tmp; 
}
 
void newBlossom (int a, int b){     
     int i,base,innerBlossom,innerBase;
     for (i=0; path[0][i]==path[1][i]; i++);   
     i--;                                      
     base=blossom[path[0][i]];                 
                                               
     for (int j=i; j<endPath[0]; j++) blossom[path[0][j]]=base;
     for (int j=i+1; j<endPath[1]; j++) blossom[path[1][j]]=base; 
     for (int p=0; p<2; p++){                                     
        for (int j=i+1; j<endPath[p]-1; j++){
            if (label[path[p][j]].even==undef){        
               label[path[p][j]].even=path[p][j+1];    
               enqueue(path[p][j],0);                  
            }
            else if (label[path[p][j]].odd[0]==undef && label[path[p][j+1]].even==undef){
                 label[path[p][j]].odd[0]=path[p][j+1];
                 enqueue(path[p][j],1);                 
            }                                           
           
            else if (label[path[p][j]].odd[0]==undef && label[path[p][j+1]].even!=undef){
                 
                 innerBlossom=blossom[path[p][j]];
                 innerBase=j;
                 for (; blossom[j]==innerBlossom && j<endPath[p]-1; j++);
                 j--;
                 label[path[p][innerBase]].odd[0]=path[p][j+1];
                 label[path[p][innerBase]].odd[1]=path[p][j];
                 enqueue(path[p][innerBase],1);
            }
        }
     }
     if (g[a][b]==unmatched){           
        if (label[a].odd[0]==undef){    
           label[a].odd[0]=b;           
           enqueue(a,1);                
        }                               
        if (label[b].odd[0]==undef){
           label[b].odd[0]=a;
           enqueue(b,1);
        }                              
     }
     else if (g[a][b]==matched){
          if (label[a].even==undef){
             label[a].even=b;
             enqueue(a,0);
          }
          if (label[b].even==undef){
             label[b].even=a;
             enqueue(b,0);
          }
     }
}
 
void augmentPath (){           
     int a,b;                  
     for (int p=0; p<2; p++){
         for (int i=0; i<endPath[p]-1; i++){
             a=path[p][i];             
             b=path[p][i+1];           
             if (g[a][b]==unmatched)   
                g[a][b]=g[b][a]=matched;
             else if (g[a][b]==matched)
                  g[a][b]=g[b][a]=unmatched;
         }
     }
     a=path[0][endPath[0]-1];
     b=path[1][endPath[1]-1];
     if (g[a][b]==unmatched) g[a][b]=g[b][a]=matched;
     else if (g[a][b]==matched) g[a][b]=g[b][a]=unmatched;
     //After this, a and b are included in the matching.
     match[path[0][0]]=match[path[1][0]]=true;
}
 
bool augmentMatching (int n){  
     int node,nodeLabel;       
     initAlg(n);               
     for (int i=0; i<n; i++) if (!match[i]){
         label[i].even=empty;
         enqueue(i,0);          
     }                          
     
     while (queueFront<queueBack){
         node=queue[queueFront].vertex;
         nodeLabel=queue[queueFront].type;
         if (nodeLabel==0){
            for (int i=0; i<n; i++) if (g[node][i]==unmatched){
                if (blossom[node]==blossom[i]);
                
                else if (label[i].even!=undef){
                     
                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,empty,0,reverse);
                     backtrace(i,1,empty,0,reverse);
                     
                     if (path[0][0]==path[1][0]) newBlossom(node,i);
                     
                     else {
                          augmentPath();
                          return true;
                          
                     }
                }
                else if (label[i].even==undef && label[i].odd[0]==undef){
                     
                     label[i].odd[0]=node;
                     enqueue(i,1);
                }
            }
         }
         else if (nodeLabel==1){ 
            for (int i=0; i<n; i++) if (g[node][i]==matched){
                if (blossom[node]==blossom[i]);
                else if (label[i].odd[0]!=undef){
                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,empty,1,reverse);
                     backtrace(i,1,empty,1,reverse);
                     if (path[0][0]==path[1][0]) newBlossom(node,i);
                     else {
                          augmentPath();
                          return true;
                     }
                }
                else if (label[i].even==undef && label[i].odd[0]==undef){
                     label[i].even=node;
                     enqueue(i,0);
                }
            }
         }
         
         queueFront++;
     }
     
     return false;
}
 
void findMaximumMatching (int n){

     for (int i=0; i<n; i++) match[i]=false;
     
     while (augmentMatching(n));
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,cnt;
        cnt=0;
        n=readGraph();

        findMaximumMatching(n);
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++)
            {
                if (g[i][j]==matched)
                {

                    cnt++;

                }
            }     
        }

        if(n%2!=0){printf("NO\n");}
        else{
            if((n/2)!=cnt){printf("NO\n");}
            else{printf("YES\n");}
        }
        
        memset(g,0,sizeof(g));
    }
    return 0;
}