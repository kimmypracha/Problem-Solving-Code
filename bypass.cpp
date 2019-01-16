#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
 using namespace std;
 const int lim = 1e5+10;
 typedef long long int lli;
 typedef pair<int,lli> pii;
 lli subt[lim] = {};
 vector<int> G[lim];
 pii mxn[2][lim] = {};
 int n;
 namespace normal{
  	lli dp(int now , int par = -1){
  		subt[now] = 1LL;
		mxn[0][now] = mxn[1][now] = {-1, -1LL};
		for(int i : G[now]){
			if(i != par){
				subt[now] += dp(i, now); 
			}
		}
		for(int v : G[now]){
			lli val = (v == par)? (lli)n-subt[now] : subt[v];
			if(mxn[0][now].fi == -1) mxn[0][now] = {v , val};
			else if(mxn[0][now].se < val )mxn[0][now] = {v,  val};
		}
		for(int v : G[now]){
			if(v == mxn[0][now].fi)continue;
			lli val = (v == par)? n-subt[now] : subt[v];
			if(mxn[1][now].fi == -1) mxn[1][now] = {v ,val};
			else if(mxn[1][now].se < val)mxn[1][now] = {v , val};
		}	
		return subt[now];
   	}
 }
lli ans = 0;
 namespace real{
 	void dp(int now , int par = -1){
		if(par == -1){
			for(int v : G[now]){
				if(v != par)
				dp(v , now);	
			}
			return;
		}
		lli mv=  (mxn[0][par].fi != now)? mxn[0][par].se : mxn[1][par].se;
		int pos = (mxn[0][par].fi != now)? mxn[0][par].fi : mxn[1][par].fi;
		if(mv == -1){
			for(int v : G[now]){
				if(v != par)
				dp(v,  now);	
			}
			return;
		}
		for(int v : G[now]){
			if(v != par){
			//	printf("%d ( %d , %d ) %d | %lld : %lld\n",pos ,par , now , v , mv , subt[v]);
				ans = max(ans , mv*subt[v]);
				dp(v , now);
			}		
		}
	}
 }
  int main(){ 
	scanf("%d",&n);
	for(int i =0 ; i < n-1 ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b);
		G[b].eb(a);
	}
	normal::dp(1); 
	real::dp(1);
	printf("%lld",ans);
  }
