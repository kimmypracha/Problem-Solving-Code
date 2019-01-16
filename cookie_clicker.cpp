#include <bits/stdc++.h>



using namespace std;

const int lim = 2e5+10;

int dp[1<<5][lim] = {}; 

int cost[5];

int pay[1<<5] = {};

int bon[5];

int got[1<<5] = {};

int main() {

    int n,  c, s;

    scanf("%d%d%d",&n,&c,&s);

    for(int i = 0 ; i < n ; ++i){

            scanf("%d%d",&cost[i],&bon[i]);

    }
    for(int i = 1 ; i  < (1<<n) ; ++i)dp[i][0] = -1e9;
    for(int i = 0 ; i < (1<<n); ++i ){

        got[i] += s;

            for(int j = 0 ; j < n ; ++j){

                    if(i&(1<<j)){

                            got[i] += bon[j];

                            pay[i] += cost[j];

                    }

            }

    }

    for(int i = 1; i < lim ; ++i){

            for(int j = 0 ; j < (1<<n) ; ++j){
		 dp[j][i] = -1e9;

                    for(int k = 0 ; k < (1<<n) ; ++k){

                            if(j&k != k)continue;

                            if(dp[k][i-1] < pay[j^(j&k)])continue;
			 //   if(i == 1 and j == 1){
			   //	printf("dp[%d][%d] : %d  , pay[%d] : %d\n" , k , i-1 , dp[k][i-1] , j^(j&k) , pay[j^(j&k)]); 
                          // }

                            dp[j][i] = max(dp[j][i], dp[k][i-1] - pay[j^(j&k)] + got[j]);

                    }

                    if(dp[j][i] >= c){

                            printf("%d",i);

                            return 0;

                    }
//		   printf("%d %d : %d\n" ,j , i , dp[j][i] );

            }

    }

}
