#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  typedef pair<int,int> pii;
  struct node {
  	int a , b  ,w;
	node(int x , int y , int z): a(x) ,b(y) , w(z) {};
	bool operator < (const node& v)const {
 		return w < v.w;
	} 
  };
  const int lim = 4e5+10;
  vector<pii> G[lim];
  int L;
  int par[lim] = {};
  vector<node> vi;
  bool mst[lim] = {};
  int wei[lim];
  int lev[lim] = {};
  int seg[2*lim] = {};
  int pos[lim]= {};
 vector<int> eu;
  const int dx =  401;
  int fh(int now){
 return par[now] = (now == par[now])? now : fh(par[now]);  
 }
  void dfs(int now , int p = -1){
	//printf("%d",now);
	pos[now] = max(pos[now] , (int)eu.size());
	eu.eb(wei[now]);
  	for(pii u : G[now]){
		if(u.fi != p){
			par[u.fi] = now;
			lev[u.fi] = lev[now] + 1;
			wei[u.fi] = u.se;
			dfs(u.fi, now);
			pos[now] = max(pos[now],(int)eu.size());
			eu.eb(wei[u.fi]);
		}
	}
  }
  int lca(int a , int b){
//	printf("%d %d\n",a,b);
	int ans = 0;
	if(pos[a] > pos[b])swap(a,b);
	for(a += L , b += L ; a < b ; a >>= 1 , b >>= 1){
		if(a&1) ans = max(ans , seg[a++]);
		if(b&1) ans = max(ans , seg[--b]);
	}
	return ans;
  }
  int main(){
  	int n , m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < 2*n-1 ; ++i){
		if(i%2==0){
			for(int j = 0 ; j < m-1 ; ++j){
				int s = i/2;
 				int x;
				scanf("%d",&x);
				vi.eb(dx*s + j , dx*s + j+1 , x);
			}	
		}else{
			for(int j = 0 ;  j < m ; ++j){
				int s = i/2;
				int x;
				scanf("%d",&x);
				vi.eb(dx*s + j , dx*(s+1) + j , x);
			}
		}
	} 
	//printf("END INPUT\n");
	sort(vi.begin(), vi.end());
	for(int i = 0 ; i < lim ; ++i){
		par[i] = i;
	}
	int ans1 = 0;
	int idx = 0;
	int rt = -1;
	for(node u : vi){
		if(fh(u.a) != fh(u.b)){
			ans1 += u.w;
			par[fh(u.a)] = fh(u.b);
			mst[idx] = true;
			G[u.a].eb(u.b , u.w);
			G[u.b].eb(u.a , u.w);
			if(rt == -1) rt = u.a;
		}
		idx++;
	}
	par[rt] = -1;
	lev[rt] = 0;
	dfs(rt);
	L = eu.size();
	for(int i = 0 ; i < L ; ++i){
		seg[L+i] = eu[i];
	}
	for(int i = L-1; i >= 1 ; --i){
		seg[i] = max(seg[i<<1],seg[i<<1|1]);	
	}
	int ans2 = 1e9;
	for(int i = 0 ; i < vi.size() ; ++i)	{
		if(!mst[i]){
			ans2 = min(ans2 , vi[i].w - lca(pos[vi[i].a],pos[vi[i].b]));		
		}
	}
	printf("%d",ans2);
  }
