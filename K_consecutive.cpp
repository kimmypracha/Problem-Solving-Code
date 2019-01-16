#include <bits/stdc++.h>
 
 using namespace std;
  typedef long long int lli;
  const int lim = 5e3  + 10;
  const lli mod = 1e9 + 7;
  lli dp[lim][lim];   // [n][k]
  lli par[lim][lim]; // [n][x]
  int main(){
	lli n , k ;
	scanf("%lld%lld",&n,&k);
	for(lli i = 0 ; i <= n ; ++i){
		par[i][0] = 1;
	}
	for(lli i = 1 ; i <= n ; ++i){
		for(lli j = 1 ; j <= i ; ++j){
			par[i][j] = par[i-1][j-1] + par[i-1][j]	 -((i-k-1 >= 0)? par[i-k-1][j-1] : 0);
			par[i][j] %= mod;
		}
	}
	dp[1][0] = 1 ;
	for(lli i = 2 ; i <= n ; ++i){
		for(lli j = 0 ; j <= i-1 ; ++j){
			dp[i][j] = dp[i-1][j]*(i-j-1) + dp[i-1][j+1]*(j+1) + ((j-1 >= 0)? dp[i-1][j-1] : 0 );
			dp[i][j] %= mod; 
		}
	}
	lli ans = 0;
	for(lli i = 1 ; i <= n ; ++i){
		ans += (dp[i][0]*(par[n][i] - par[n-1][i]) )%mod;
		ans %= mod; 
	}
	ans += mod;
	ans %= mod;
	printf("%lld" , ans);
 }
