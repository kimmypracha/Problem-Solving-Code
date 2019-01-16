#include <bits/stdc++.h>

  using namespace std;
   typedef long long int lli;
   const int len = 1e5+10;
   const lli mod = 1e9+7;
   char str[len];
   int keep[26] = {};
   lli dp[len] = {};
   inline lli repet(int x){
	if(keep[x] == 0)return 0;
	else return dp[keep[x]-1];	
   }
   int main(){
  	int t;
	scanf("%d",&t);
	while(t--){
		fill(keep,keep + 26, 0);
		scanf("%s",str+1);
		int n = strlen(str+1);
		dp[0] = 1;
		for(int i = 1 ; i <= n ; ++i){
			dp[i] = 2*dp[i-1] - repet(str[i]-'A');
			dp[i] = (dp[i]+mod)%mod;
			keep[str[i]-'A'] = i;		
		}
		printf("%lld\n",(dp[n]+mod)%mod);
	}
   }
