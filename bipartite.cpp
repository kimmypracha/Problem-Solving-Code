#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  const int lim = 1e5+10;
  vector<int> G[lim];
  int col[lim] = {};
  int n , m;
  void init(){
  for(int i =0 ;  i < lim  ;++i)G[i].clear();
  fill(col , col + lim , 0);
  }
  bool chbi(){
  	queue<int> q;
	q.push(1);
	col[1] = 1;
	while(not q.empty()){
  		int now = q.front();
		q.pop();
		for(int i : G[now]){
			if(col[i]*col[now] == 1)return false;
			if(col[i] == 0){
				col[i] = -col[now];
				q.push(i);
			}
		}
	}
//	for(int i = 1 ; i<= n; ++i){
//		printf("%d ",col[i]);
//	}
//	printf("\n");
	return true;
  }
  int main(){
  	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d%d",&n,&m);
		for(int i = 0 ; i < m ; ++i){
			int a , b;
			scanf("%d%d",&a,&b);
			G[a].eb(b);
			G[b].eb(a);
		}
		if(chbi())printf("yes\n");
		else printf("no\n");
	} 
  }
