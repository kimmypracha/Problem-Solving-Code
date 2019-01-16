#include <bits/stdc++.h>
 
 using namespace std;
 typedef long long int lli;
 lli dp[200][200]= {};
 const lli mod = 1e9+7;
 int main(){
 	int n , k;
	scanf("%d%d",&n,&k);
	k--;
	dp[3][0] = 1;
	for(int i = 4 ; i <= n ; ++i){
		dp[i][0] = 1; 
		for(int j = 1 ; j <= k ; ++j){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			dp[i][j] %= mod;
			for(int l = 3 ; l < i ; ++l){
				for(int m = 0 ; m < j ; ++m){
					dp[i][j] += (m? (dp[l-1][m] + dp[l-1][m-1]) :1LL )*(dp[i-l+2][j-m-1])%mod;
					dp[i][j] %= mod;
				}
			}
		}
	}
	printf("%lld",dp[n][k]%mod); 
 }
