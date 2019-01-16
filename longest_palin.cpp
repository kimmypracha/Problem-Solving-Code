#include <bits/stdc++.h>

  using namespace std;
  int dp[1002][1002];
  char A[1002];
 int main(){
 	int t;
	scanf("%d%*c",&t);
	while(t--){
		for(int i =0 ; i < 1002 ; ++i){
			for(int j = 0 ; j < 1002 ; ++j){
				dp[i][j] = 0;
			}
		}
		gets(A);
		int len = strlen(A);
		for(int i = 1 ; i <= len; ++i){
			for(int j = 0 ; j < len-i+1 ; ++j){
				int k = j + i -1;
				if(j == k){
					dp[j][k] = 1;
				}else if(A[j] == A[k]){
					dp[j][k] =2+dp[j+1][k-1];
				}else{
					dp[j][k] = max(dp[j+1][k] , dp[j][k-1]);
				}
			}
		}
		printf("%d\n",dp[0][len-1]);
	} 
 }
