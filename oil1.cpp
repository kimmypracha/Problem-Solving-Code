#include <bits/stdc++.h> 
 
 using namespace std;
 int n , m,  k;
 int arr[1600][1600];
 int qs[1600][1600];
 int dp[2][1600][1600] , dp1[2][1600][1600]; 
 int cnt  = 0;
 void rot(){
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			qs[j][n-i+1] = arr[i][j];		
		}
	}
	swap(n,m);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m; ++j){
			arr[i][j] = qs[i][j];
			qs[i][j] = arr[i][j] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
		}
	}
 }
 bool init(){
	if(cnt == 4)return false;
	if(cnt != 0){
		rot();
	}
  	int c , i , j ;
	for(c = 0 ; c < 2 ; ++c){
		for(i = 1 ; i < 1510 ; ++i){
			for(j= 1 ; j < 1510  ; ++j){
				dp[c][i][j]  = dp1[c][i][j] = 0;
			}
		}
	}
	cnt++;
	return true;
 }
 int main(){
	int c , i , j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1 ; i <= n ; ++i){
		for(j =1 ; j <=m ;++j){
			scanf("%d",&arr[i][j]);
			qs[i][j] = arr[i][j] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
		}
	}
	int ans = 0;
	int t = 4;
	while(t--){
		init();
		for( c = 1 ; c < 4 ; ++c ){
			for(i = k ; i <= n ; ++i ){
				for(j = k ; j <= m ; ++j){
					dp[c%2][i][j] = max(max(dp[c%2][i-1][j] , dp[c%2][i][j-1]) 
					, qs[i][j] - qs[i-k][j] - qs[i][j-k] + qs[i-k][j-k] +
					 max(max(dp[(c-1)%2][i-k][j] , dp[(c-1)%2][i][j-k]) , dp1[(c-1)%2][i-k][j] ));
				}
			}
			for(i = k ; i <= n ; ++i){
				for(j = m ; j >= k ; --j){
					dp1[c%2][i][j] = max(max(dp1[c%2][i-1][j] , dp1[c%2][i][j+1])
					, qs[i][j] - qs[i-k][j] - qs[i][j-k] + qs[i-k][j-k] + 
					max(
					((j+k <= m)? max(dp1[(c-1)%2][i-k][j] ,dp1[(c-1)%2][i][j+k]) : dp1[(c-1)%2][i-k][j])
					, dp[(c-1)%2][i-k][j]) );
				}
			}
		
		}
		ans = max(ans, max( dp[1][n][m] , dp1[1][n][k]));
	}
	printf("%d",ans);
 }
