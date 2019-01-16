#include <bits/stdc++.h>
#define eb emplace_back 
 using namespace std;
 const int lim = 1e5+10;
 int Q[lim];
 int dp[2][lim];
 vector<int> G[lim];
 int ans =-1;
  void dfs(int now , int par = -1 , int epa = -1){
	dp[0][now] = (G[now].empty())? -1 : G[now][0];
	for(int v : G[now]){
		if(Q[dp[0][now]] < Q[v]){
			dp[0][now] =v;	
		}
	}
	dp[1][now] = -1;
	if(dp[0][now] != -1){
	for(int v : G[now]){
		if((dp[1][now] == -1 and v != dp[0][now]) or (Q[dp[1][now]] < Q[v] and v != dp[0][now] )){
			dp[1][now] = v;
		}
	}
	}
//	printf("::%d %d %d\n",now,dp[0][now] , dp[1][now]);
	for(int v : G[now]){
		if(v != par){
			dfs(v , now , par);
		}
	}
	vector<int> tmp;
	for(int v : G[now]){
		if(dp[0][v] != now and dp[0][v] != -1){
			tmp.eb(Q[dp[0][v]]);
		}
		else if(dp[1][v] != now and dp[1][v] != -1){
			tmp.eb(Q[dp[1][v]]);	
		}
		if(tmp.size() >= 3)sort(tmp.begin(),tmp.end()) , tmp.pop_back();	
	}
	
	if(tmp.size() >= 2){
		ans = max(ans , tmp[0] + tmp[1]);
	}
	if(epa != -1){
		tmp.clear();
		if(dp[0][epa] != par and dp[0][epa] != -1)tmp.eb(Q[dp[0][epa]]);
		else if(dp[1][epa] != par and dp[1][epa] != -1)tmp.eb(Q[dp[1][epa]]);
		if(dp[0][now] != par and dp[0][now] != -1 and not tmp.empty())ans = max(ans ,Q[dp[0][now]] + tmp[0]);
		else if(dp[1][now] != par and dp[1][now] != -1 and not tmp.empty()) ans = max(ans , Q[dp[1][now]] + tmp[0]);
	}
 }
 void init(){
 	fill(dp[0] ,dp[0] + lim , 0);
	fill(dp[1] , dp[1] + lim , 0);
	for(int i = 0 ; i < lim ; ++i){
		G[i].clear();
	}
	ans = -1;
  }
  int main(){
  	int t , n;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++i){
			scanf("%d",&Q[i]);
		}
		for(int i = 1 ; i <= n-1; ++i){
			int u , v;
			scanf("%d%d",&u,&v);
			G[u].eb(v);
			G[v].eb(u);	
		}
		dfs(1);	
		printf("%d\n",ans);
	}
  }
