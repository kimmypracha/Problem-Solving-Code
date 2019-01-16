#include <bits/stdc++.h>

  using namespace std;
   const int lim = 3e5+10;
   int h[lim];
   char st[lim];
   int dp[lim] = {};
   int main(){
   	int n , k ;
	scanf("%d%d",&n,&k);
	for(int i =1 ; i <= n ; ++i){
		scanf("%d",&h[i]);	
	}
	scanf("%s",st);
	dp[k] = 1;
  	bool hve = false;
	if(st[k] != 'T'){
		int mxn = 0;
		int pos = 0;
		for(int i = k+1 ; i<= n ; ++i){
			if(h[i] <= h[i-1]){
				dp[i] = dp[i-1] + 1;
				mxn = max(mxn , dp[i]);
				pos = i;
			}
			if(st[i] == 'T')hve = true;
			if(st[i] == 'T' or h[i] > h[i-1])break;
		}
		if(not hve){
			printf("%d\n",mxn);
			return 0;	
		}else{
			int ans = 0;
			for(int i = 1 ;  i < k ; ++){
				if(h[i] <= h[i-1] and i != 1 and st[i-1] != 'T'){
					dp[i] = dp[i-1] + 1;
				}else{
					dp[i] = 1;
				}
				if(st[i] == 'T'){
					ans += dp[i];	
				}
			}
			for(int i = pos +1 ; i <= n ; ++i){
				if(h[i] <= h[i-1] and i != 1 and st[i-1] != 'T'){
					dp[i] = dp[i-1] + 1;
				}else{
					dp[i] = 1;
				}
				if(st[i] == 'T'){
					ans += dp[i];
				}
			}
		}
	}else{
		hve = true;
	}
   }
