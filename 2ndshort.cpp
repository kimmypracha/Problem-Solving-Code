#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef long long int lli;
 const int lim = 1e5+10;
 typedef pair<int,int> pii;
 vector<pii> G[lim], GT[lim];
 int par[lim];
 lli d[2][lim];
 int main(){
 	int n , m ,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i = 1 ; i <= m ; ++i){
		int a , b , w;
		scanf("%d%d%d",&a,&b,&w);
		G[a].eb(b,w);
		GT[b].eb(a,w);
	}
	fill(par , par + lim , -1);
	fill(d[0] , d[0] + lim ,  2e9);
	fill(d[1] , d[1] + lim ,  2e9);
	priority_queue<pii , vector<pii>, greater<pii> > pq;
	d[0][s] = 0;
	d[1][t] = 0;
	pq.push({0, s});
	while(not pq.empty()){
		int now = pq.top().se;
		pq.pop();
		for(pii x : G[now]){
			if(d[0][x.fi] > d[0][now] + (lli)x.se){
				d[0][x.fi] = d[0][now] +(lli)x.se;
				pq.push({d[0][x.fi] , x.fi});
			}
		}
	}
	pq.push({0,t});
	while(not pq.empty()){
		int now = pq.top().se;
		pq.pop();
		for(pii x : GT[now]){
			if(d[1][x.fi] > d[1][now] + (lli)x.se){
				d[1][x.fi] = d[1][now] + (lli)x.se;
				pq.push({d[1][x.fi] , x.fi});
			}
		}
	}
	lli md = d[0][t];
	lli ans = 2e9;
	for(int i = 1 ; i <= n ; ++i){
		for(pii x : G[i]){
			if(d[0][i] + x.se + d[1][x.fi] > md){
				ans = min(ans , d[0][i] + (lli)x.se + d[1][x.fi]);
			}	
		}
	}
	printf("%lld",ans);
 }
