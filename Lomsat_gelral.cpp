#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 const int lim = 1e5 + 10;
 typedef long long int lli;
 lli col[lim];
 vector<int> G[lim];
 int sz[lim] = {};
 bool hv[lim] = {};
 int cnt[lim] = {}; 
 lli sum[lim] = {};
 lli ans[lim] = {};
 int Max = 0;
 namespace getsz{
 int dfs(int now , int par = -1){
 	sz[now] = 1;
	for(auto v : G[now]){
		if(par != v)
			sz[now] += dfs(v, now);		
	}
	return sz[now];
 }
}
void add(int now , int par  , int val){
 	sum[cnt[col[now]]] -= col[now];
	if(Max == cnt[col[now]] and sum[cnt[col[now]]] == 0 and val == -1)Max--;
	cnt[col[now]] += val;
	sum[cnt[col[now]]] += col[now];
	Max = max(Max , cnt[col[now]]);
	for(auto v : G[now]){
		if(v != par and !hv[v]){
			add(v, now , val);
		}
	}
 }
 void dfs(int now , int par = -1 , int kep = 0 ){
 	int big = -1 , mxc = 0;
	for(auto v : G[now]){
		if(par != v and mxc <= sz[v]){
			mxc = sz[v];
			big = v;
		}
	}
	for(auto v : G[now]){
		if(par != v and v != big){
			dfs(v,  now , 0);		
		}
	}
	if(big != -1){
		dfs(big, now , 1);	
		hv[big] = true;	
	}
	add(now , par , 1);
	ans[now] = sum[Max];
	if(big != -1)
		hv[big] = false;
	if(kep == 0)
		add(now , par , -1);
 }
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i =1 ;  i <= n ; ++i){
		scanf("%lld",&col[i]);
		sum[0] += col[i];
	}
	for(int i =1 ; i <= n-1 ; ++i){
		int x,  y;
		scanf("%d%d",&x,&y);
		G[x].eb(y);
		G[y].eb(x);
	}
	getsz::dfs(1);
	dfs(1);
	for(int i = 1 ; i <= n ; ++i){
		printf("%lld ",ans[i]);
	}
 }
