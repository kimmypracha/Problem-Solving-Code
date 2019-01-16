#include <bits/stdc++.h>

  using namespace std;
  const int lim = 1010;
  const int mod = 1e9 + 7;
  int n , m ;
  int arr[lim][lim];
  int dp[lim][lim] = {};
  int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++i){	
		for(int j= 1 ; j <= m ; ++j){
			scanf("%d",&arr[i][j]);
			if(i == 1 and j  == 1)dp[i][j] = 1;
			else dp[i][j] = (arr[i][j])? 0 : dp[i-1][j] + dp[i][j-1];	
			dp[i][j] %= mod;
		}
	}
	printf("%d",dp[n][m]%mod);
  }
