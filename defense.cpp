#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 3030;
 const int inf = 1e9+10;
 int arr[lim];
 int dp[lim][lim];
 int mn[lim][lim];
 int main(){
 	int n , k ;
	scanf("%d%d",&n,&k);
	for(int i =1  ; i <= n;  ++i){
		scanf("%d",&arr[i]);	
	}
	for(int i = 1 ;i  <= n ; ++i){
		for(int j = 0 ; j <= k-1 ; ++j ){
			dp[i][j] = mn[i][j] = inf;
		}
		for(int j = 1 ;j <= min(i , k-1) ; ++j){
			dp[i][j] = mn[i-j][k-j] + arr[i];
		}
		for(int j = 1 ; j <= k-1 ; ++j){
			mn[i][j] = min(dp[i][j] , mn[i][j-1]);	
		}
	}
	int ans = inf;
	for(int i = n-k+2 ; i <= n ; ++i){
		ans = min(ans , mn[i][k - (n-i) - 1]);
	}
	printf("%d",ans);
 }
