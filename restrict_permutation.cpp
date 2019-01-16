#include <bits/stdc++.h> 
 
 using namespace std;
 const int lim = 2e3+10;
 const int mod = 1e9+7;
 int arr[lim];
 int dp[lim][lim] = {};
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i = 2 ; i<= n; ++i){
		scanf("%d",&arr[i]);	
	}
	for(int i = 1 ; i <= n;  ++i){
		for(int j = 1 ; j <= i ; ++j){
			if(i == 1)dp[i][j] = 1;
			else{
				if(arr[i] == 1){
					dp[i][j] = dp[i-1][j-1];
				//	printf("%d %d : %d\n",i,j,dp[i][j]);
				}else{
					dp[i][j] = dp[i-1][i-1] - dp[i-1][j-1];
				//	printf("%d %d : %d\n", i,j,dp[i][j]);
					dp[i][j] += mod;
					dp[i][j] %= mod;
				}
			}
		}
		for(int j = 1; j <= i+1 ; ++j){
			dp[i][j] = dp[i][j] + dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
	printf("%d",dp[n][n]%mod);
 }
