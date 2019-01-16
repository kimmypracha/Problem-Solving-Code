#include <bits/stdc++.h>
 
using namespace std;
	int dp[21][1<<21] = {};
	int mid = 1<<20;
 int main(){
	for(int i =0 ;  i < 20 ; ++i){
		if(i == 0){
		dp[i][mid] = 1 ;
		dp[i][mid+1] = 1;
		dp[i][mid-1] = 1;
		}else{
			dp[i][mid] += dp[i-1][mid -(1<<i)];
			dp[i][mid] += dp[i-1][mid + (1<<i)];
			dp[i][mid] += dp[i-1][mid];
			for(int j= -(1<<20) + 1 ; j < (1<<20) ; ++j){
				if(j == 0 ) continue;
				if(mid + j - (1<<i) >= 0 )
				dp[i][mid + j ] += dp[i-1][mid + j -(1<<i)];
				if(mid + j + (1<<i) < (1<<21))
				dp[i][mid + j ] += dp[i-1][mid + j +(1<<i)];
				dp[i][mid + j ] += dp[i-1][mid + j ];  
			}
		}
	}
  	int t;
	scanf("%d",&t);
	while(t--){
		int x , y;
		scanf("%d%d",&x , &y);
		if(x < (1<<20) && x > -(1<<20)){
			printf("%d\n" ,dp[y-1][mid + x]);
		}
		else{
			printf("0\n");
		}
	} 
 }
