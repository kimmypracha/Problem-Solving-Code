#include <bits/stdc++.h>
 
 using namespace std;
 int dp[2510][2510];
 int arr[2510];
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	for(int L =1 ; L  <= n ; ++L){
		for(int i  = 0 ; i < n-L+1 ; ++i){
			int j =  i + L - 1;
			if(i == j){
				dp[i][j] = 0;
				continue;
			}else if(i+1 == j){
				dp[i][j] = (arr[i] == arr[j])? 1 : 0 ;
				continue;
			}
			if(arr[i] == arr[j]) dp[i][j] = dp[i+1][j-1] + 1;
			for(int k = i ; k < j ; ++k){
				dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k+1][j]);
			}			
		}
	}
	printf("%d",dp[0][n-1]);
 }
