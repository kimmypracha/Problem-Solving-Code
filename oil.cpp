#include <bits/stdc++.h>
 
 using namespace std;
 int dp[4][2020][2020] = {};
 int arr[2020][2020]; 
 int org[2020][2020]; 
 int tmp[2020][2020]; 
 int  n , m , k ;
 void rot(){
	auto f = [](int* b){fill(b , b + 2020 , 0);};
 	for_each(dp , dp+ 4 , [=](int (*a)[2020]){for_each(a , a+2020 ,f );});
	for(int i =1 ; i  <= n ; ++i){
		for(int j= 1 ; j <= m ; ++j){
			tmp[j][n-i+1] = org[i][j];  
		}
	}
	for(int i =1 ; i<= m ; ++i){
		for(int j =1 ; j <=n ; ++j ){
			arr[i][j] = org[i][j]= tmp[i][j];
			arr[i][j] += arr[i-1][j]  + arr[i][j-1] - arr[i-1][j-1];
		}
	}
	swap(n,m);
 }
 int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1 ; i  <= n; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d",&org[i][j]);
			arr[i][j] = org[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		} 
	}
	int t = 4;
	int ans = 0; 
	while(t--){
		for(int c = 1 ; c < 4; ++c){
			for(int i =k ; i <= n ; ++i){
				for(int j = k ; j <= m;  ++j){
					if(c == 1){
						dp[c][i][j] =max(arr[i][j] - arr[i-k][j] - arr[i][j-k]  + arr[i-k][j-k] , 
								 max(dp[c][i-1][j] , dp[c][i][j-1])                    );			
					}else{
						dp[c][i][j] = max(max(dp[c][i-1][j],dp[c][i][j-1]) , 
								 arr[i][j] - arr[i-k][j] - arr[i][j-k] + arr[i-k][j-k] 
								+  max(dp[c-1][i][j-k] , dp[c-1][i-k][j]));
					}
				}
			}
		}
		ans = max(ans , dp[3][n][m]);
		rot();
	}
	printf("%d",ans);
 }

