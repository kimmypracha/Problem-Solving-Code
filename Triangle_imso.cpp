#include <bits/stdc++.h>

  using namespace std;
  typedef long long int lli;
  const int lim = 110;
  const lli mod = 1e9 +7;
  lli dp[lim][lim];
  int main(){
  	int n , k;
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i <= n ;++i ){
		dp[i][0] = 1LL;
		dp[0][i] = 1LL;
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			for(int l = 1 ; l <= k ; ++l){
				if(j-l-1 >= 0 )
					dp[i][j] += dp[i-1][j-l-1];
				if(i-l-1 >= 0)
					dp[i][j] += dp[i-l-1][j-1];
			}
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			dp[i][j] %= mod; 
		}
	}
	printf("%lld", (dp[n][n]-1 + mod)%mod); 
 }
