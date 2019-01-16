#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 typedef long long int lli;
 const int lim = 1e5+10;
 vector<int> G[lim];
 lli dp[2][lim];
 lli score[lim];
 void dfs(int now , int par = -1){
  	vector<lli> vi;
	for(lli v : G[now]){
		if(v != par)
			dfs(v , now) , vi.eb(dp[1][v]);
	}
	sort(vi.begin() , vi.end() , greater<lli>());
	for(int i = 1 ; i < vi.size(); ++i){
		vi[i] += vi[i-1];
	}
	lli ans1 = score[0] , ans2 = score[1];
	for(int i = vi.size()-1 ;  i >= 0 ; i--){
		ans1 = max(ans1 , vi[i] + score[i+1]);
		ans2 = max(ans2 , vi[i] + score[i+2]);
	}
	dp[1][now] = ans2;
	dp[0][now] = ans1;
 }
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%lld",&score[i]);
	}
	for(int i = 0 ; i < n-1; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b);
		G[b].eb(a);
	}
	dfs(1); 
	lli ans = dp[0][1];
	for(int i = 2 ; i <=  n ; ++i) ans = max(ans , dp[0][i]);
 	printf("%lld",ans);
	}
