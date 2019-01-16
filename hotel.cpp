#include <bits/stdc++.h>

  using namespace std;
  typedef long long int lli; 
  int chi[4] = {1 , 2 , 5 , 15};
  lli pri[4] = {500 , 800, 1500 , 3000};	
  lli dp[1000020] = {}; 
  int main(){
 	int n;
	scanf("%d",&n);
	lli ans = 0;
	for(int i =1  ; i <= n+15 ; ++i ){
		for(int j = 0 ; j < 4 ; ++j){
			if( i >= chi[j]){
				if(dp[i] == 0 )
				dp[i] = dp[i - chi[j]] + pri[j];
				else
				dp[i] = min(dp[i] , dp[i-chi[j]] + pri[j]);
			}
		}
		if(i == n) ans = dp[n];
		else if(i > n) ans = min(ans , dp[i]);
	}
	printf("%lld", ans); 
 }
