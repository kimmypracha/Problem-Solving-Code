#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
 using namespace std;
  struct node {
  	int u , v  , w;
	node(int a , int b , int c): u(a) , v(b) , w(c) {};
  };
  typedef pair<int,int> pii;
  const int lim = 2e5 +10;
  vector<pii> G[lim];
  vector<node> edge;
  int col[lim];
  int par[lim];
  int val[lim];
  int cnt = 1;
  map<int,int> mat[lim];
  multiset<int> seg[2*lim] , ans[lim] , ovr;
  set<int> lst[lim];
  int n , m;
  int fh(int now ){
  	return par[now] = (now == par[now])?  now : fh(par[now]);
  }
  int get(int u , int c){
	if(mat[u].find(c) == mat[u].end())mat[u][c] = cnt++;
	return mat[u][c];
  } 
  void kruskal(){
	for(int i = 1 ; i <= n ; ++i)par[i] = i;
	sort(edge.begin() , edge.end() , [](const node &a , const node &b) -> bool{return a.w < b.w;});
	for(node x : edge){
		if(fh(x.u) != fh(x.v)){
//			printf("::%d %d %d\n",x.u,x.v,x.w);
			G[x.u].eb(x.v, x.w);
			G[x.v].eb(x.u, x.w);
			par[fh(x.u)] = fh(x.v);
		}
	}	
  }
  void dfs(int u , int p = -1){
	par[u] = p;
  	for(pii v : G[u]){
		if(v.fi != p){
		//	printf("%d -> %d : %d\n",u,v.fi,v.se);
			val[v.fi] = v.se;
			lst[u].insert(col[v.fi]);		
			int tp = get(u,col[v.fi]);
			seg[tp].insert(val[v.fi]);
			dfs(v.fi,u);
		}
	}
  }
  int main(){ 
  	int k ,q ;
	scanf("%d%d%d%d",&n,&m,&k,&q);	
	for(int i = 1 ; i <= m ;  ++i){
		int a , b , w;
		scanf("%d%d%d",&a,&b,&w);
		edge.eb(a,b,w);	
	}
	for(int i = 1 ; i <= n ;++i){
		scanf("%d",&col[i]);
	}
	kruskal();
	dfs(1);
	for(int i = 1 ; i <= n; ++i){
//		printf("%d ",val[i]);
		for(int c : lst[i]){
			if(col[i] == c)continue;
			int tp = mat[i][c];
			//printf("||%d %d  : %d\n",i,c,*seg[tp].begin());
			ovr.insert(*seg[tp].begin());	
		}
		//if(!ans[i].empty())
		//	ovr.insert(*ans[i].begin());
	}
//	for(int x : ovr){
//		cout << x << " ";
//	}
//	printf("\n");
	for(int i = 1 ; i <= q;  ++i){
		int u , v;
		scanf("%d%d",&u,&v);
		int tp;	        
		if(col[u] == v){
			printf("%d\n",*ovr.begin());
			continue;
		}
		int old = *ovr.begin();
		int add = (mat[u].find(col[u]) == mat[u].end())? -1 : mat[u][col[u]];
		int rem = (mat[u].find(v) == mat[u].end())? -1 : mat[u][v];
		if(add != -1)
		add = (seg[add].empty())? -1 : *seg[add].begin();
		if(rem != -1)
		rem = (seg[rem].empty())? -1 : *seg[rem].begin();
		if(rem != -1)	ovr.erase(ovr.find(rem));
		if(add != -1)	ovr.insert(add);
		//printf("First : %d %d\n",add,rem);	
		if(u == 1){	
			printf("%d\n",*ovr.begin());
			col[u] = v;
			continue;
		}
		int p = par[u];
		add = -1;
		rem = -1;
		tp = get(p,col[u]);
		seg[tp].erase(seg[tp].find(val[u]));
		if(col[p] != col[u])
		ovr.erase(ovr.find(val[u]));
		tp = get(p,v);
		seg[tp].insert(val[u]);
		if(col[p] != v)
		ovr.insert(val[u]);
		//printf("Second : %d %d \n",add ,rem);
		printf("%d\n",*ovr.begin());
		col[u] = v;	 
	}
  }
  
