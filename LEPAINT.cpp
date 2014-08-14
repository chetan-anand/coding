#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAXN 100
#define MOD 1000000007
#define LL long long int

long double comb[MAXN + 4][MAXN + 4];
LL count[MAXN + 2];
long double count_rem[MAXN + 4][MAXN + 4];

long double val[MAXN + 2], sum[MAXN + 2];


void ncr(LL n){
    LL i, j;
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            comb[i][j] = 0.0;
        }
    }
 	comb[0][0] = 1.0;
    for(j = 1; j <= n; j++){
        comb[0][j] = 0.0;
    }

    for(i = 1; i <= n; i++){
        comb[i][0] = comb[i - 1][0] / 2.0;
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1] + 0.0) / 2.0;
        }
    }
    return;
}

inline void Solve(){
    LL n, k, c, i, j, x, y, index;
    cin>>n>>c>>k;

    for(i = 0; i <= MAXN; i++){
        for(j = 0; j <= MAXN; j++){
            count_rem[i][j] = 0;
        }
    }

    sum[0] = 1.0;
    sum[1] = 0.0;
    for(i = 0; i <= c - 1; i++){
        count_rem[1][i] = 1;
        sum[1] += i * 1.0 / c;
    }
    LL num;
    for(i = 2; i <= 100; i++){
        sum[i] = 0.0;
        for(j = 0; j <= c - 1; j++){
            for(index = 0; index <= c - 1; index++){
                num = (index * j) % (c);
                count_rem[i][num] += count_rem[i - 1][j];
            }
        }
        for(j = 0; j <= c - 1; j++){
            sum[i] += (j * count_rem[i][j] + 0.0);
        }

        for(j = 1; j <= i; j++){
            sum[i] /= (c + 0.0);
        }
    }

    for(i = 0; i <= 100; i++){
    	//cout<<count_rem[100][i]<<endl;
    }
    //cout<<"pramod"<<endl;

    for(i = 0; i <= 100; i++){
        count[i] = 0;
        val[i] = 1.0;
    }
    for(i = 0; i < k; i++){
        cin>>x>>y;
        for(j = x; j <= y; j++){
            count[j]++;
        }
    }

    long double ans = 0.0;
    long double temp_ans;
    for(i = 1; i <= n; i++){
        index = count[i];
        temp_ans = 0.0;
        for(j = 0; j <= index; j++){
            temp_ans += (comb[index][j] * sum[j] + 0.0);
        }
        for(j = 1; j <= index; j++){
            //temp_ans /= 2.0;
        }
        ans += temp_ans;

    }


    printf("%0.9LF\n", ans);
    return;
}

int main(){
    ncr(102);
    LL t;
    cin>>t;
    while(t--){
        Solve();
    }
}
