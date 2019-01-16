#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 const int lim = 1e3 + 10;
 int n  , m ;
 vector<int> G[lim];
 int cur[lim] = {}, low[lim] = {} ,idx = 1;
 bool brd[lim][lim] = {};
 bool vis[lim] = {};
 void dfs(int now , int par = -1){
  	cur[now] = low[now] = idx++;
	for(int v : G[now]){
		if(cur[v] == 0){
			dfs(v , now);
			low[now] = min(low[now] , low[v]);
			if(low[v] > cur[now]){
				brd[v][now] = brd[now][v] = true;
			}
		}else if(v != par){
			low[now] = min(low[now] , cur[v]);
		}	
	}
 }
 void flood(int now ){
	vis[now] = true;
 	for(int v  : G[now]){
		if(not vis[v] and not brd[now][v]){
			flood(v);
		}
	}
 } 
 int main() { 
   	scanf("%d%d",&n,&m);
	for(int i =0  ; i < m; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b);
		G[b].eb(a);
	}
	dfs(1);
	int cnt = 0 ;
	for(int i = 1 ; i <= n;  ++i){
		if(not vis[i]){
			flood(i);
			cnt++;
		}
	}
	printf("%d",cnt);	
 } 
