#include <bits/stdc++.h>
 
 using namespace std;
 typedef long long int lli;
  const lli mod = 1e9+7;
  lli dp[110][110];
  int pr[110];
  int in[110]; // keep position
  int posp[110];
  int posi[110];
  lli recur(int l  , int r){
	if(l >= r) return 1;
	if(dp[l][r] >= 0) return dp[l][r]%mod;
	int mn = l;
  	for(int i =  l+1 ; i <= r ; ++i){
		mn = (posp[in[i]] < posp[in[mn]])? i : mn;
	}
//	printf("::%d %d\n",l,r);
//	for(int i = l ; i < mn ; ++i){
//		printf("%d ",in[i]);	
//	}
//	printf("|%d |",in[mn]);
//	for(int i = mn+1 ; i<= r ;++i){
//		printf("%d ",in[i]);
//	}
//	printf("\n");
	lli ans1 = 0;
	ans1 += (mn == r)? 1 : recur(l,mn-1)*recur(mn+1 , r)*2;
	ans1 %= mod;
	int np = mn;
	lli ans2 = 0;
	for(int i = posp[in[mn]] +1; posi[pr[i]] < r ;++i ){
		if(posi[pr[i]] < np)continue;
		np = max(np , posi[pr[i]]);
	//	printf("%d %d : (%d %d ) ,(%d %d)\n",l,r,mn+1,posi[pr[i]],posi[pr[i]]+1,r);
		ans2 += recur(mn+1,posi[pr[i]])*recur(posi[pr[i]]+1 ,r);
		ans2 %= mod;
	}
//	printf("|| %d %d : %d %d \n",l,r , ans1 , ans2);
	return dp[l][r] = (ans1+ans2)%mod;
  }
  int main(){
   	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0; j < n ; ++j){
			dp[i][j] = -1;
		}
	}
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&pr[i]);
		posp[pr[i]] = i;
	}
	for(int i = 0 ; i < n;  ++i){
		scanf("%d",&in[i]);
		posi[in[i]] = i;
	}
	printf("%lld",recur(0,n-1)%mod);
 }
