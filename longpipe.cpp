#include <bits/stdc++.h>
 
 using namespace std;
 typedef long long int lli;
 const lli mod = 1e9+7;
 lli dp[1<<3][1<<3];
 lli mat[1<<3][1<<3] = {};
 bool isone(int x){
	if((x - (x&(-x))) == 0)return true;
	return false;
 }
 void rec(int n ){
	if(n == 1){
		for(int i = 0 ; i < 8 ; ++i){
			for(int j = 0 ; j  < 8 ; ++j){
				dp[i][j] = mat[i][j];
			}	
		}
		return;
	}
	rec(n/2);
	lli tmp[8][8] = {};
	for(int i = 0 ; i < 8 ; ++i){
		for(int j = 0; j < 8 ; ++j){
			for(int k = 0 ; k < 8 ; ++k){
				if(n == 2 and i == 1 and j == 1 and dp[i][k]*dp[k][j] > 0)
					printf("%d :%d %d\n",k,dp[i][k],dp[k][j]);
				tmp[i][j] += dp[i][k]*dp[k][j];
				tmp[i][j] %= mod;
			}
		}
	}
	if(n&1){
		for(int i = 0 ; i < 8 ; ++i){
			for(int j = 0 ; j < 8 ; ++j){
				dp[i][j] = 0;
				for(int k = 0 ;  k < 8 ; ++k){
					dp[i][j] += tmp[i][k]*mat[k][j];
					dp[i][j] %= mod;
				}
			}	
		}
	}else{
		for(int i = 0 ; i  < 8;  ++i){
			for(int j = 0 ; j < 8 ; ++j){
				dp[i][j] = tmp[i][j];
			}
		}
	}	
 }
 bool can(int a , int b){
	if(a == 1 and (b == 1 or b == 2 or b == 7))return true;	
	if(a == 2 and (b == 4 or b == 2 or b == 1))return true;	
	if(a == 4 and (b == 4 or b == 2 or b == 7))return true;	
	if(a == 5 and (b == 6 or b == 3 or b == 5))return true;	
	if(a == 3 and (b == 3 or b == 5 ))return true;	
	if(a == 6 and (b == 6 or b == 5))return true;	
	if(a == 7 and (b == 1 or b == 4 or b == 7))return true;	
	return false; 
}
 int main(){
 	int n;
	scanf("%d",&n);
	lli ans = 0 ;
	for(int i = 0 ; i < 8 ; ++i){
		for(int j = 0 ; j < 8 ; ++j){
			if(can(i,j))mat[i][j] = 1;
		}
	}
	rec(n);
	for(int i = 0 ; i < 8 ; ++i){
		for(int j = 0 ; j < 8 ; ++j){
			if(isone(i) and isone(j)){
			//printf("%d %d : %d\n",i,j,dp[i][j]);
			ans += dp[i][j];
			ans %= mod;
			}
		}
	}
	printf("%lld",ans);
 }
