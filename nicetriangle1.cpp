#include <bits/stdc++.h>
 
 
	using namespace std;
 typedef long long int lli;
 const int mxn = 352;
 const lli mod = 29947;
 lli cnr[2*mxn][mxn];
 lli dp[2*mxn][mxn];
 int main(){
 	int x , y, z;
	scanf("%d%d%d",&x,&y,&z);
	--x , --y , --z;
	int A = max(x , y+z);
	int B = max(x , max(y,z));
	for(int i = 0 ; i <= A ; ++i){
		for(int j = 0 ; j <= min(i,B) ;++j){
			cnr[i][j] = (j == 0 or j == i)? 1 : cnr[i-1][j-1] + cnr[i-1][j];
			cnr[i][j] %= mod;	
		}
	}
	lli ans = 0;
	for(int i = 0 ; i <= A;++i){
		for(int j = 0 ; j <= min(i,B) ; ++j){
			for(int k = 0 ; k <= j; ++k){
				dp[i][j] += cnr[i][k]*cnr[j][k];
				dp[i][j] %= mod;
			}	
		}
	}
	ans += (y+z > x)? dp[y+z][x] : dp[x][y+z];
	ans %= mod;
	for(int i = 1 ; i <= y ; ++i){
		for(int j = 1 ; j<= z ; ++j){
			int atl = y+z-i-j;
			int A = max(x , atl);
			int B = min(x,atl);
			if(i >= j)
				ans += dp[i-1][j-1]*((atl < 0)? 0 : dp[A][B]);
			else 	ans += dp[j-1][i-1]*((atl < 0)? 0 : dp[A][B]);
			ans %= mod;	
		}
	}
	printf("%lld",ans%mod);
 }		
 
