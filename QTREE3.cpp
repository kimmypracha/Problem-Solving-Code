#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 const int lim = 1e5 + 10;
  vector<int> G[lim];
  int col[lim] = {};
  int subt[lim];
  int hev[lim];
  int pos[lim];
  int root[lim]; 
  int par[lim];
  int lev[lim] = {};
  int inc[lim];
  int arr[lim];
  int seg[4*lim];
  bool mark[lim] = {};
  int idx = 0 , num = 0;
  int n;
  void init(){
 	lev[1] = 0;
	 
  }
  void dfs(int u , int p = -1){
	subt[u] = 1;
	int mx = -1;
	for(int v : G[u]){
		if(p != v){
			par[v] = u;
 			lev[v] = lev[u] + 1;
			dfs(v  ,u);
			subt[u] += subt[v];
			if(mx == -1) mx = v;
			else if(subt[mx] < subt[v])mx = v;
		}
	}
	hev[u]  =mx;
  }
  void hld(int u , int p = -1){
	if(!mark[u]){
	//	printf("||%d : \n",u);
		for(int now = u ; now != -1 ; now = hev[now]){
	///		printf("%d\n",now);
			mark[now] = true;
			arr[idx] = now;
			pos[now] = idx++;
			inc[now] = num;
			root[now] = u;
 		}
		num++;
	}
  	for(int v : G[u]){
		if(v != p){
			hld(v,u);
		}
	}
  }
  int rmq(int a , int b , int p = 1 , int l = 0 , int r = n-1 ){
	if(r < a or l > b) return -1;
	if(a <= l and r <= b){
		return seg[p];
	}else{
		int p1 = rmq(a , b ,  p<<1 , l , (l+r)/2);
		int p2 = rmq(a , b , p<<1|1 , (l+r)/2 + 1 , r);
		if(p1 == -1) return p2;
		return p1;
	}	
  }
  void build(int p = 1 ,int l = 0 , int r =  n-1 ){
	if(l == r){
		seg[p] = (!col[arr[l]])? -1 : arr[l];	
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 , r);
		seg[p] = (seg[p<<1] == -1)? seg[p<<1|1] : seg[p<<1];
	}	
  }
  void update(int a , int x ,int p = 1,  int l = 0 , int r = n-1){
	if(r < a or l > a)return ;
	if(l == r){
		col[arr[l]] = x;
		seg[p] = (!col[arr[l]])? -1 : arr[l];
	}else{
		update(a , x  , p<<1 , l , (l+r)/2);
		update(a,x , p<<1|1 , (l+r)/2 + 1 , r);
		seg[p] = (seg[p<<1] == -1)? seg[p<<1|1] : seg[p<<1]; 
	}	
  }
  int que(int now){
//	printf("::%d\n",now);
	if(now == 0) return -1;
	if(now == 1) return (!col[now])? -1 : now; 
 	int rt = root[now];
	int p1 = que(par[rt]);
	int p2 = rmq(pos[rt] , pos[now]);
	if(p1 == -1)return p2;
	else return p1;
  }
  int main(){ 
 	int q;
	scanf("%d%d",&n,&q);
	for(int i =  1 ; i <= n-1 ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b);
		G[b].eb(a);
	}
	dfs(1);
	hld(1);
	build();
//	for(int i = 0 ; i < n;  ++i){
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
	for(int i = 1;  i <= q  ; ++i){
		int c , v;
		scanf("%d%d",&c,&v);	
		if(c == 1){
			printf("%d\n",que(v));
		}else{
			update(pos[v],!col[v]);	
		}		
	}
  }
