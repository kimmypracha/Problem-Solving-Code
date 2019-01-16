#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
   const int lim = 1e5+10;
   int a[lim] , b[lim];
   bool vis[lim];
  vector<int> G[lim];
  void init(){
   	fill(vis , vis + lim , false);
	for(int i = 0 ; i < lim ; ++i)G[i].clear(); 
 }
  bool iscy(int now ,int par = -1){
  	bool ans = false;
	vis[now] = true;
	//printf("::%d %d\n",now,par);
	for(int v : G[now]){
		if(v == par)continue;
		if(vis[v]){
			return true;
		}
		if(!vis[v]){
			ans |= iscy(v , now); 
		}
	}
	return ans;
  }
  int main(){
  	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		init();
		for(int i = 0 ; i < n;  ++i){
			scanf("%d",&a[i]);	
		}
		for(int i =0 ; i < n ; ++i){
			scanf("%d",&b[i]);
		}
		for(int i =0 ;  i < n ;++i){
			if(a[i] == 0 or b[i] == 0){
				continue;
			}
			if(a[i] == b[i]) continue;
			G[a[i]].eb(b[i]);
			G[b[i]].eb(a[i]);
		}
 		bool Can = true;
		for(int i = 1 ; i <= n ; ++i){
			if(not G[i].empty() and not vis[i]){
				Can &= !iscy(i);
			}
		}
		if(Can)printf("YES\n");
		else printf("NO\n");
	}
  }
