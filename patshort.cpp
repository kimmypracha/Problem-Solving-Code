#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define all(x) x.begin() , x.end()
#define se second
 using namespace std;
 typedef long long int lli;
 typedef pair<int,int> pii;
 const int lim = 330;
 const lli inf = 2e10;
 vector<pii> poi;
 vector<pair<pii , pii> > shp;
 lli G[lim][lim];
 map<pii, int > mpi;
 lli dist(pii a , pii b){
 	lli dx = (lli)abs(a.fi- b.fi);
	lli dy = (lli)abs(a.se - b.se);
	if(dx >= dy)return dx;
	else if(dx < dy) return ((dx+dy)&1)? dy+1 : dy;
 }
 int main(){
 	int M , Q;
	scanf("%d%d",&M,&Q);
	for(int i = 1 ; i <= M ; ++i){
		int a,b , c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		shp.eb(pii(a,b), pii(c,d));
		poi.eb(a,b);
		poi.eb(c,d); 
	}
	sort(all(poi));
	poi.resize(unique(all(poi)) - poi.begin());
	int n = (int)poi.size();
	for(int i = 0 ; i < poi.size() ; ++i){
		pii x = poi[i];
		mpi[x] = i;
	}
	for(int i = 0 ; i < n; ++i){
		for(int j = 0 ;  j <  n ; ++j){
			G[i][j] = (i==j)? 0 : inf;
		}
	}
	for(auto& x : shp){
		pii a = x.fi;	
		pii b = x.se;
		int p1= mpi[a];
		int p2 = mpi[b];
		G[p1][p2] = G[p2][p1] = 1;
	}
	for(int k = 0 ; k < n ; ++k){
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(i == j or i == k or j == k)continue;
				G[i][j] = min(G[i][j] , G[i][k] + G[k][j]);
				G[i][j] = min(G[i][j] , dist(poi[i] , poi[j]));
			}
		}
	}
	for(int i = 0 ; i < Q ; ++i){
		lli ans;
		int x1,y1,x2,y2,dx,dy,cnt = 0; // *----------------------
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ans = dist(pii(x1,y1),pii(x2,y2));
		for(int j = 0 ; j < n ; ++j){
			for(int k = 0; k < n;  ++k){
				ans = min(ans , dist(pii(x1,y1),poi[j]) + G[j][k] + dist(poi[k],pii(x2,y2)));
			}
		}
		printf("%lld\n",ans);
	}
 }
