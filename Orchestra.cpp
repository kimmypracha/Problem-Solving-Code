#include <bits/stdc++.h>

  using namespace std;
  int dp[110][510];
  int sum[110] = {};
  int main(){
  	int N,  M ,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i = 1 ; i <= M ; ++i){
		for(int j = 0; j <= K ; ++j){
			for(int k = 0 ; k <= j; ++k){
				dp[i][j] = min(dp[i][j] , div(sum[i] , j-k) + dp[i-1][k]);
			}
		}
	}
  }
