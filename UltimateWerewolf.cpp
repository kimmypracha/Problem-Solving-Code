#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 const int lim = 5e5+10;
 vector<int> G[lim];
 int dp[2][lim] = {} , dpl[2][2][lim];
  bool v[lim] = {};
  int par[lim] = {};
  bool inc[lim] = {};
  vector<int> lst;
  void dfs(int now , int p = -1){
 	v[now] = true;
	printf("||= %d\n",now);
	scanf("%*c");
	for(int i : G[now]){
		if(i != p and not v[i]){
			par[i] = now;
			dfs(i , now);
		}else if(i != p and not inc[i]){
			int x = now;
			for(;x != i ; x = par[x]){
				printf("-> %d\n",x);
				scanf("%*c");
				inc[x] = true;
				lst.eb(x);
			}
			lst.eb(x);
			inc[x] = true;
		}
	}
 }
 int get_dp(int now,int st , int  p =-1){
	dp[st][now] = st;
 	for(int i : G[now]){
		if(i != p and not inc[i]){
			int p1= 0 , p2 = 0; 
			if(st == 0 ) p1 = get_dp(i , 1 , now);
			p2 = get_dp(i,0,now);
			dp[st][now] += max(p1 , p2);
		}
	}
	return dp[st][now];
 }
 int main(){
	int Q;
	scanf("%d",&Q);
	while(Q--){
 	int n ;
	scanf("%d",&n);
	for(int i = 1 ; i <= n;  ++i){
		int x;
		scanf("%d",&x);
		G[i].eb(x);
		G[x].eb(i);
	}
	for(int i = 1 ; i <= n; ++i){
		if(G[i].empty() or G[i].size() == 1) continue;
		sort(G[i].begin() , G[i].end());
		auto it=  unique(G[i].begin() , G[i].end());
		G[i].resize(it - G[i].begin());
	}
	int ans = 0;
	for(int t = 1 ; t <= n ; ++t){
	if(v[t])continue;
	lst.clear();
	dfs(t);
	for(int i= 0 ; i < lst.size(); ++i){
		get_dp(lst[i],0);
		get_dp(lst[i],1);
//		printf("%d : %d %d\n",lst[i] , dp[0][lst[i]] , dp[1][lst[i]]);
	}
	for(int i = 0 ; i < lst.size(); ++i){
		if(i == 0){
			dpl[0][0][i]  = dp[0][lst[i]];
			dpl[1][1][i] = dp[1][lst[i]];
		}else if(i == 1){
			dpl[0][0][i] = dp[0][lst[i]] + dpl[0][0][i-1];
			dpl[0][1][i] = dp[1][lst[i]] + dpl[0][0][i-1];
			dpl[1][0][i] = dp[0][lst[i]] + dpl[1][1][i-1];
		}else if(i == 2){
			dpl[0][0][i] = dp[0][lst[i]] + max(dpl[0][0][i-1] , dpl[0][1][i-1]);
			dpl[0][1][i] = dp[1][lst[i]] + dpl[0][0][i-1];
			dpl[1][0][i] = dp[0][lst[i]] + dpl[1][0][i-1];
			dpl[1][1][i] = dp[1][lst[i]] + dpl[1][0][i-1];
		}else if(i == lst.size()-1){
			dpl[0][0][i] = max(dpl[0][1][i-1] + dp[0][lst[i]] , dpl[0][0][i-1] + dp[0][lst[i]]);
			dpl[0][1][i] = dpl[0][0][i-1] + dp[1][lst[i]];
			dpl[1][0][i] = max(dpl[1][0][i-1] + dp[0][lst[i]] , dpl[1][1][i-1] + dp[0][lst[i]] );
		}else{
			dpl[0][0][i] = dp[0][lst[i]] + max(dpl[0][1][i-1] , dpl[0][0][i-1]);
			dpl[0][1][i] = dpl[0][0][i-1] + dp[1][lst[i]];
			dpl[1][0][i] = dp[0][lst[i]] + max(dpl[1][0][i-1] , dpl[1][1][i-1] );
			dpl[1][1][i] = dpl[1][0][i-1] + dp[1][lst[i]];
		}
	}
	ans += max(max(dpl[1][0][lst.size()-1] , dpl[0][1][lst.size()-1]) , dpl[0][0][lst.size()-1]);
	printf(":: %d\n",ans);
	}
	printf("%d\n",n - ans);
	for(int i = 1; i <= n ; ++i){
		G[i].clear();
		v[i] = inc[i] = false;
	}
	}
 }
