#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  const int lim = 1e5+10;
  vector<int> G[lim];
  int h[lim] = {};
  int seg[4*lim];
  vector<int> eu;
  int pos[lim];
  int n , sn;
  void dfs(int now , int par = -1){
	eu.eb(now);
	pos[now] = (int)eu.size()-1;
 	for(int v : G[now]){
		if(v != par){
			h[v]  =h[now] + 1;
			dfs(v,now);
			eu.eb(now);
		}
	} 
 }
 void build(){
	sn = (int)eu.size();
  	for(int i = 0 ; i < sn; ++i){
		seg[sn + i] = eu[i];
	}
	for(int i = sn-1 ; i >= 1 ; --i){
		seg[i] = (h[seg[i<<1]] > h[seg[i<<1|1]])? seg[i<<1|1] : seg[i<<1];
	}
 }
 int lca(int l , int r){
	l = pos[l] ;
	r = pos[r];
	if(l > r) swap(l,r);
	r++;
 	int mx = seg[sn+l];
	for(l = sn + l , r = sn + r;l < r ; l >>= 1 , r >>= 1){
		if(l&1)mx = (h[mx] > h[seg[l++]])?seg[l-1] :mx;
		if(r&1)mx = (h[mx] > h[seg[--r]])?seg[r] : mx;  
	}
	return mx;	
 }
  int main(){
  	int m;	
	scanf("%d",&n);	
	for(int i = 1 ; i <= n-1; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b);
		G[b].eb(a);
	}
	dfs(1);
	build();
//	for(int i : eu){
//		cout << i << " ";
//	}
//	cout << "\n";
	vector<int> ord;
	scanf("%d",&m);
	for(int i = 1;  i <= m ; ++i){
		int x;
		scanf("%d",&x);
		ord.eb(x);
	}
	int ans = h[1] + h[ord[0]] - 2*h[lca(1,ord[0])];
//	printf("::%d\n",ans);
	for(int i = 1 ; i < m ; ++i){
		ans += h[ord[i-1]] + h[ord[i]] - 2*h[lca(ord[i-1] , ord[i])];
//		printf("%d",h[ord[i-1]] , h[ord[i]] , lca(ord[i-1],ord[i]) , h[lca(ord[i-1] , ord[i])]);
	}
//	ans += h[n] + h[ord.back()] - 2*h[lca(ord.back() , n)];
	printf("%d",ans);
  }
