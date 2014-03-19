#include <bits/stdc++.h>
using namespace std;

vector<long long int> adjacency[1000];
bool visited[1000];
long long int cnt;
///Standard algorithm DFS

void dfs(long long int u){
    visited[ u ] = true;
    cnt++;
    for( long long int v = 0 ; v < adjacency[u].size(); ++v ){
        if( !visited[ adjacency[u][v] ] ){
            dfs( adjacency[u][v] );
        }
    }
}



int main()
{
         ///enumerate vertices from 1 to vertex
    	long long int vertex, edges , originNode ,destinationNode, i, j,cont =1,total,k;
        ///number of test cases
        long long int testCases,flag;
        long long int totalComponents;
        scanf ("%lld", &testCases);

        for (i=0; i<testCases; i++){
        flag=0;
        memset( visited , 0 , sizeof( visited ) );
        scanf("%lld %lld" , &vertex , &edges );
        //printf("vertex=%lld edge=%lld\n",vertex,edges);
        
        for (j=0; j<edges; j++){
            scanf("%lld %lld" , &originNode ,&destinationNode );
            originNode--;
            destinationNode--;
            adjacency[ originNode ].push_back( destinationNode );
            adjacency[ destinationNode ].push_back( originNode );
        }

        for(j=0;j<vertex;j++)
        {
        	printf("(%lld)%lld=",adjacency[j].size(),j+1);
        	for(k=0;k<adjacency[j].size();k++)
        	{
        		printf("%lld ",adjacency[j][k]+1);
        	}
        	printf("\n");
        }
        //if(vertex%2!=0){printf("NO\n");continue;}
            totalComponents =0;
            for( j = 0 ; j < vertex ; ++j ){
            	    // Loop through all possible vertex
                if( !visited[ j ] ){          //if we have not visited any one component from that node
                    cnt=0;
                    printf("vertex=%lld\n",j+1 );
                    dfs( j );
                    cout<<"cnt="<<cnt<<"\n";
                    if(cnt%2!=0){printf("NO\n");flag=1;}
                    
                                      //we travel from node i the entire graph is formed
                    totalComponents++;                   //increased amount of components
                }
                if(flag==1){break;}
            }
          	if(flag==0){printf("YES\n");}
            printf("Case %lld: %lld component (s) connected (s)\n" ,i, totalComponents);

        memset( adjacency , 0 , sizeof( adjacency ) );

        }
    return 0;
}
