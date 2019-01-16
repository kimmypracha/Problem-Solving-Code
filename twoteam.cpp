#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  typedef pair<int,int> pii;
  const int lim = 1e5 + 10;
  int col[lim];
  vector<pii> G[lim];
  int n;
  bool can(int edg){
   	fill(col , col + 1+ n , 0);
	queue<int> q;
	for(int i = 1 ; i <= n ; ++i){
	if(col[i] != 0)continue;
	col[i] = 1;
	q.push(i);
	while(not q.empty()){
		int now = q.front();
		q.pop();
		for(pii v : G[now]){
			int i = v.fi;
			if(v.se > edg)continue;
			if(col[i] == 0){
				col[i] = -col[now];	
				q.push(i);
			}else if(col[i] == col[now])return false;	
		}
	}
	}
	return true;
  }
  int main(){
  	int m;
	scanf("%d%d",&n,&m);
	for(int i =0 ; i <m ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b,i);
		G[b].eb(a,i);
	}
	int l = 0 , r = m , mid;
	while(l < r){
		mid = (l+r)/2 ;
		if(can(mid)){
			l = mid+1;
		}else{
			r = mid;
		}
	}
	printf("%d\n",l);
  }
