#include <bits/stdc++.h>

  using namespace std;
  const int lim = 360;
  const int mod = 29947;
  typedef long long int lli;
  lli cnt[2*lim][lim] = {}  , dp[2*lim][lim] = {};
  int main(){
 	int a , b , c;
	scanf("%d%d%d",&a,&b,&c);
	a-- , b-- , c-- ;
	cnt[0][0] = 1;
	int A = max(a , b+c);
 	int B = max(a, max(b , c));
	for(int i = 1 ; i <= A ; ++i){
		for(int j = 0 ; j <= min( i , B) ;++j ){
			if(j == 0) cnt[i][j] = 1;
			else cnt[i][j] = (cnt[i-1][j-1] + cnt[i-1][j])%mod;
		}
	}
	for(int i = 0 ; i <= A ; ++i){
		for(int j = 0; j <= min( i , B); ++j){
			for(int k = 0 ; k <= j  ; ++k){
				dp[i][j] += (cnt[i][k]*cnt[j][k])%mod;
				dp[i][j] %= mod;
			}
			//printf("%lld ",dp[i][j]);
		}
	//	printf("\n");
	}
	lli ans = (b+c >= a)? dp[b+c][a] : dp[a][b+c];
	for(int i  = 1 ; i <= b ; ++i){
		for(int j= 1 ; j <= c ; ++j){
			int TA = max(a , b+c - i - j );
			int TB = min(a , b+c - i - j) ;
			if(i <= j)
			ans += dp[j-1][i-1] * ( (TB < 0 )? 0 : dp[TA][TB]);
			else ans += dp[i-1][j-1]*((TB < 0)? 0 : dp[TA][TB] );
			ans %= mod;	
		}
	}
	printf("%lld",ans%mod);
  }
