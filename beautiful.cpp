#include <bits/stdc++.h>
#define ls(x) (x&(-x))
#define tb(x) ((x-ls(x))-ls(x-ls(x)))
#define eb emplace_back
 using namespace std;
  const int lim = 1e5+10;
  vector<int> G[lim];
  int d[lim] = {};
  int des[lim] = {};
  int sum = 0;
  int SP[20][20];
  int dp[1<<17];
  int n;
  int cnt;
  unordered_map<int,int> mpi;
  void bfs(int now ){
	int st = now;
	queue<int> q;
	fill(des, des + 1+ n , 1e9);
  	q.push(now);
	des[now] = 0;
//	printf("Start %d ",now);
	while(not q.empty()){
		now = q.front();
		q.pop();
		for(int i : G[now]){
			if(des[i] > des[now] + 1){
				des[i] = des[now] + 1;
				q.push(i);
			}
		}
	}
	for(int i = 1 ; i <= n;  ++i){
		if(d[i]&1){
	//		printf("%d %d : %d %d : %d\n",st , i , mpi[st] , mpi[i] , des[i]);
			SP[mpi[st]][mpi[i]] = des[i];	
		}
	}
  }
 int fb(int st){
	int ans = 1e9;
 	for(int i = 0 ; i < cnt ; ++i){
		if(st&(1<<i)){
			for(int j = i+1 ; j < cnt ; ++j){
	//			printf("%d %d : %d\n",i,j,SP[i][j]);
				if(st&(1<<j))ans = min(ans , SP[i][j] + dp[st^(1<<i)^(1<<j)]);
			}
		}
	} 
	return ans;
 }
  int main(){
	fill(dp , dp  + (1<<17)  ,1e9 );
  	int m;
	scanf("%d%d",&n,&m);
	for(int i =0 ; i < m ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b);
		G[b].eb(a);
		++d[a] , ++d[b];
	}
	cnt = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(d[i]&1){
			mpi[i] = cnt++;	
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(d[i]&1){
			bfs(i);
		}	
	}
	dp[0] =0;
	//printf(":: %d\n",cnt);
	for(int i = 1; i < (1<<cnt) ; ++i){
		if((i - ls(i)) == 0)continue;
			dp[i] = fb(i);	
			//printf("|%d : %d\n",i,dp[i]);
	}
	printf("%d",m-dp[(1<<cnt)-1]);
  }
