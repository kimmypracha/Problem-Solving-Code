#include <bits/stdc++.h>
#define eb emplace_back 
  using namespace std;
  const int lim = 2e5+10;
  int dat[2][lim];
  vector<int> G[lim];
  void dfs(int now , int par){
	G[par].eb(now);
  	if(dat[0][now] == -1 or dat[1][now] == -1){
		if(dat[0][now] != -1)dfs(dat[0][now] , par);
		else if(dat[1][now] != -1)dfs(dat[1][now],par);
	}else{
		dfs(dat[0][now] , dat[0][now]);
		dfs(dat[1][now] , dat[1][now]);
	}
  }
  void recur(int now , int L , int s , int a , int b){
//	printf("%d\n",now);
	if(L == 0){
		printf("%d\n",now);
		return;	
	}	
	if(dat[0][now] != -1 and dat[1][now] != -1){
		int res = ((s&8) >> 3);
		s = (s*a+b)%40507;
		recur(dat[res][now] , L-1 , s , a , b);
	}else{
		if(dat[0][now] == -1 and dat[1][now] == -1){
			printf("%d\n",now);
			return;
		}
		else if(G[now].size() > L){
			printf("%d\n",G[now][L]);
			return;
		}else{
			recur(G[now].back() , L - (int)G[now].size()+1 , s , a , b);
		}
	}	
  }
  int main(){
  	int n , q;
	scanf("%d%d",&n,&q);
	for(int i = 0 ; i < n ; ++i){
		int l , r;
		scanf("%d%d",&dat[0][i],&dat[1][i]);		
	}
	dfs(0,0);
	for(int i = 0; i < q ; ++i){
		int L , s , a  ,b;
		scanf("%d%d%d%d",&L,&s,&a,&b);
//		printf("------------------------------------------------------\n");
		recur(0 , L , s , a ,  b);
	} 
  } 
