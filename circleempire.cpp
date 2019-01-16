#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef long long int lli;
 typedef pair<int,int> pii;
 typedef pair<lli,int> pli;
 typedef pair<int,lli> pil;
 const int limk = 220;
 const int limn = 10010;
 const lli inf = 1e18+10;
 vector<pil> G[limn];   
 lli dp[limk][limn]; 
 int K , L , M , Q;
 void ssp(int st){
	priority_queue<pli , vector<pli> , greater<pli> > pq;
	vector<lli> tmp(limn,inf);
	tmp[st] = 0LL;
	pq.push({0LL,st});
	while(not pq.empty()){
		int u = pq.top().se;
		pq.pop();
		for(pii x : G[u]){
			int v = x.fi;
			lli w = x.se;
			if(tmp[v] > tmp[u] + w){
				tmp[v] = tmp[u] + w;
				pq.push({tmp[v],v});
			} 
		}
	}
	copy(tmp.begin(),tmp.end(),dp[st/L]);	
 }
 int main(){
	scanf("%d%d%d%d",&K,&L,&M,&Q);
	for(int i = 1 ; i <= M;  ++i){
		int a , b , c;
		scanf("%d%d%d",&a,&b,&c);
		G[a].eb(b,c);
		G[b].eb(a,c);
	}
	//PreCompute Session
	for(int i = 1 ; i <= K; ++i){
		ssp(L*i);
	}
 	//End PreCompute Session
	for(int i = 1 ; i <= Q; ++i){
		int a  ,b;
		scanf("%d%d",&a,&b);
		lli ans = inf;
		for(int j = 1 ; j <= K; ++j){
			ans = min(ans , dp[j][a] + dp[j][b]);
		}
		printf("%lld\n",ans);	
	} 
 }
