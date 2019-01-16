#include <bits/stdc++.h>
 
 using namespace std;
 typedef long long int lli;
 const lli mod = 1e9+7;
 const int lim = 1010;
 int f[lim] = {};
 int s[lim] = {};
 lli dp[lim][lim] = {};
 lli mem[lim][lim] = {};
 lli cnr(int n , int r){
	if(mem[n][r] > 0 )return mem[n][r]%mod;
 	if(r == 0 or r==n )return 1;
	if(r < 0 or r > n)return 0;
	return mem[n][r] = (cnr(n-1,r) + cnr(n-1,r-1))%mod;
 }
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n;  ++i){
		int x;
		scanf("%d",&x);
		f[x]++;
	}
	for(int i = 1 ; i <= n ; ++i){
		s[i] = f[i] + s[i-1];
	}
	for(int i = 1 ; i <= n ; ++i){
		if(i == 1){
			if(s[i] != 0)
				dp[i][s[i]-1] = 1;
		}else{
			for(int j = 0 ; j <= s[i] ; ++j){
				if(f[i] == 0){
					dp[i][j] = dp[i-1][j];
					continue;
				}
				dp[i][j] = (j == s[i]-1)? 1 : 0;
				//printf("||%d %d : %lld\n",i,j,dp[i][j]);
				for(int k = 0 ; k <= f[i] ; ++k){
				//	printf("%lld %lld (%d,%d) (%d,%d) \n",dp[i][j],dp[i-1][j+f[i]-k] ,j+f[i]-k , f[i]-k , s[i-1]+1-j , k);
					lli a1 , a2 , a3 ;
					a1 = dp[i-1][j+f[i]-k];
					a2 = cnr(j+f[i]-k,f[i]-k);
					a3 = cnr(s[i-1]-j+f[i],s[i-1]-j-1);	
					a1 *= a2;
					a1 %= mod;
					a1 *= a3;
					a1 %= mod;
					//if(i== 6 and j == 2)
					//printf("%d %d: %d %d\n",i,j,s[i-1]+1-(j+f[i]-k) , k);
					//printf(": %lld + %lld \n",dp[i][j] , ans);
					dp[i][j] += a1;
					dp[i][j] %= mod;
		//			printf("%d %d : %lld\n",i,j,dp[i][j]);
				}
			//	if(i%3 == 0)	
			//	printf("%d %d : %lld\n",i,j,dp[i][j]);			
			}
		}
	}
	//printf("dp[5][2] : %lld\n",dp[5][2]);
	printf("%lld",dp[n][0]);	
 }
