#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 const int lim = 1e4 + 10;
 typedef pair<int,int> pii;
 vector<pii> G[lim];
 int D[lim]  , D2[lim];
 class Comp{
	public:
	bool operator() (const pii &a , const pii &b) {
		if(a.se == b.se) return a.fi > b.fi;
		return a.se > b.se ;
	}
};
priority_queue<pii , vector<pii> , Comp> pq;
  int main(){
  	int n , m;
	int x ,y , z , L , S , T;
	scanf("%d%d",&n,&m);
	fill(D , D   + lim , 1e9 );
	fill(D2 , D2   + lim , 1e9 );
	scanf("%d%d%d", &S,&T,&L);
	D[S] = 0;
	pq.push({S , 0});
	for(int i =0 ; i  < m; ++i){
		scanf("%d%d%d", &x,&y,&z);
		G[x].eb(y,z);
		G[y].eb(x,z);
	}
	while(not pq.empty()){
		int now = pq.top().fi;
		int w  = pq.top().se;
		pq.pop();
		if(now == T){
			pq = priority_queue<pii , vector<pii> , Comp>();
			break;
		}	
		for(pii v : G[now]){
			if(D[v.fi] > D[now] + v.se and D[now] + v.se <= L){
				D[v.fi] = D[now] + v.se;
				pq.push({v.fi , D[v.fi]});
			}
		}
	}
	if(D[T] == 1e9){
		D2[T] = 0;
		pq.push({T , 0});
		while(not pq.empty()){
			int u = pq.top().fi;
			int w = pq.top().se;
//			printf("|now = %d|\n", u);
			pq.pop();
			if(D[u] != 1e9){
				printf("%d %d %d",u , D[u],D2[u]);
				break;
			}
			for(pii v : G[u]){
				if(D2[v.fi] > D2[u] + v.se ){
					D2[v.fi] = D2[u] + v.se;
					pq.push({v.fi , D2[v.fi]});
				}
			}
		}
	}else printf("%d %d %d",T , D[T] , 0);
  }
