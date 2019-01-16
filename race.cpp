#include <bits/stdc++.h>
#define fi first
#define se second 
#define eb emplace_back
 using namespace std;
 const int lim = 2e5 + 10;
 const int ran = 1e6 + 10;
 typedef pair<int,int> pii;
 vector<pii> G[lim];
 int sz[lim];
 int hsh[lim] = {};
 bool rem[lim] = {};
 int getsz(int now , int par = -1){
 	sz[now] = 1;
	for(auto v : G[now]){
		if(par != v.fi){
			sz[now] += getsz[v.fi];
		}
	}
	return sz[now];
 }
 void update(int now , int par,  int val){
 	
 }
 void dfs(int now , int par = -1 , int kep = 0){
 	int big = -1 , mxn  = 0;
 	for(auto v : G[now]){
		if(par != v.fi and mxn < sz[v.fi]){
			big = v.fi;
			mxn = sz[v.fi];
		}
	}
	for(auto v : G[now]){
		if(par != v.fi and v.fi != big){
			dfs(v.fi , now , 0);
		}
	}
	if(big != -1){
		dfs(big , now , 1);
		rem[big] = true; 
	}
	update(now , par , 1);
	if(big != -1)
		rem[big] = false;
	if(kep == 0)
		update(now , par , -1);
 }
  int main(){
   
 }
