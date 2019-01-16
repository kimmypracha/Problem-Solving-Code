#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  const int lim = 1e5+10;
  vector<int> G[lim];
  int d[lim] = {};
  vector<int> vi;
  int main(){
  	int n ,m ;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < m ;++i){
		int u , v;
		scanf("%d%d",&u,&v);
		G[u].eb(v);
		d[v]++; 
	}
	queue<int> q;
	
	for(int i = 1 ; i <= n ;++i){
		if(d[i]== 0)q.push(i);
	}
	if(q.empty()){
		printf("no");
		return 0;
	}
	while(not q.empty()){
 		int now = q.front();
		q.pop();
		vi.eb(now);
		for(int i : G[now]){
			if(d[i] == 1){
				q.push(i);
			}
			d[i]--;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(d[i] != 0){
			printf("no");
			return 0;
		}
	}
	for(int i = 0 ;i  < n ; ++i){
		printf("%d\n",vi[i]);	
	} 
  }
