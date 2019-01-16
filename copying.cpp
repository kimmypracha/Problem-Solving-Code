#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  const int lim = 4e4 + 10;
  typedef pair<int,int> pii;
  vector<pii> G[lim];
  vector<pii> Lst;
  int CC[lim];
  int  N , P;
  int Cnt;
  void DFS(int now,int k){
	CC[now] = Cnt;
	for(pii i : G[now]){
		if(i.se < k and not CC[i.fi]){
			DFS(i.fi , k);
		}	
	}
  }
  bool Can(int k){
  	Cnt =  1;
	fill(CC + 1  , CC + 1 + N , 0);
    	for(int i= 1 ; i <= N ; ++i){
		if(not CC[i]){
			DFS(i, k);
			Cnt++;
		}
	}
	for(int i = 0 ; i < P ; ++i){
		if(CC[Lst[i].fi]== CC[Lst[i].se])return false;
	}
	return true;
  }
  int main(){
 	int  M ;
	scanf("%d%d%d",&N,&M,&P);
	for(int i =0 ; i  < M ; ++i){
		int x , y , z;
		scanf("%d%d%d",&x,&y,&z);
		G[x].eb(y,z);
		G[y].eb(x,z);
	}
	for(int i =0 ; i < P ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		Lst.eb(a,b);
	}
	int l = 0  , r = 1e9 + 10;
	while(l < r ){
		int m = (l+r)/2;
//		printf("%d %d\n", l , r);
		if(Can(m)){
			l = m+1;
		}else{
			r = m;
		}
	}
	if(not Can(l))l--;
	if(l >  1e9) printf("-1");
	else printf("%d",l);
 }
  
