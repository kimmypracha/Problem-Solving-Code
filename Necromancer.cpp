#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;

  const int lim = 2010;
  vector<int> lst[lim] , adj[lim];
  int G[lim][lim] = {} , org[lim][lim];
  int par[lim];
  int lev[lim];
  int n , k ;

  inline void bfs(){
  	fill(lev , lev + k+n+2 , 1e9);
	queue<int> q;
	lev[0] = 0;
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int v : adj[now]){
			if(G[now][v] and lev[v] > lev[now] + 1 ){
				lev[v] = lev[now] + 1;
				q.push(v);
			}
		}
	}
  }

  inline int AP(int now , int mx){
	if(now == k+n+1 or !mx) return mx;
	for(int v : adj[now]){
		if(G[now][v] and lev[v] == lev[now] + 1){
			int f = AP(v, min(mx , G[now][v]));
			if(f){
			G[now][v] -= f;
			G[v][now] += f;
			return f;
			}
		}
	}
	return 0;
  }

  inline bool MaxFlow(int num){
	for(int i = 0 ; i <= k+n+1 ; ++i)for(int j : adj[i])G[i][j] = org[i][j];
	for(int i = 2; i <= k ; ++i){
		G[i][k+n+1] = num;
	}
	while(bfs() , lev[k+n+1] != 1e9 ){
		while(AP(0,1e9);
	}
	int cnt = 0 ;
	for(int i = 1 ; i<= n ; ++i){
		cnt += G[0][k+i];	
	}
	if(!cnt)return true;
	return false;
  }

  int main(){
 	int vot = 0, x , L;
 	bool hve;
	scanf("%d%d",&n,&k);	
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&L);
		hve = false;
		for(int j = 1 ; j <= L ; ++j){
			scanf("%d",&x);
			lst[i].eb(x);
			if(x == 1)hve = true;	
		}
		if(lst[i][0] == 1 or !hve){
			++vot;
			continue;
		}
		for(int x : lst[i]){
			G[k+i][x] = -1;	
		}
		G[0][k+i] = 1;	
		adj[0].eb(k+i);
		adj[k+i].eb(0);
		for(int j = 1 ; j <= k ; ++j){
			++G[k+i][j];
			if(G[k+i][j])adj[k+i].eb(j) , adj[j].eb(k+i);	
		}
		assert(G[k+i][lst[i][0]] != 1);
		G[k+i][lst[i][0]] = 1;
		adj[k+i].eb(lst[i][0]) , adj[lst[i][0]].eb(k+i);
	}
	if(2*vot > n){
		printf("0");
		return 0;
	}
	for(int i = 2 ; i <= k ; ++i){
		adj[i].eb(k+n+1);
		adj[k+n+1].eb(i);
	}
	for(int i = 0 ; i <= n+k+1 ; ++i)for(int j = 0 ; j <= n+k+1 ; ++j)org[i][j] = G[i][j];
	int l = 1 , r = n;
	int m;
	while(l<r){
		m = (l+r)/2;
		if(MaxFlow(m)){
			r = m;
		}else{
			l = m+1;
		}
	}
	if(vot <= l)printf("%d",l - vot +1);
	else printf("0");	
  }
