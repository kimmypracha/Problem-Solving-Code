#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef struct node{
  	int st , now  , las;
 };
 typedef long long int lli;
 const int lim = 8e4+10;
 const long long int inf = 1e18+10;
 typedef pair<int,int> pii;
 vector<pii> G[lim];
 bool hve[lim]=  {};
 lli dp[9][lim];
 queue<node> q;
  int main(){
  	int n , m , l , Q;
	scanf("%d%d%d%d",&n,&m,&l,&Q);
	for(int i = 0 ; i  < m ; ++i ){
		int A , B ;
		int W;	
		scanf("%d%d%d",&A,&B,&W);
		G[A].eb(B,W);
	} 
	for(int i = 0;  i < l ; ++i){
		int X;
		scanf("%d",&X);
		hve[X] = true;
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 0 ;j < 8  ; ++j){
			dp[j][i] = inf;
		}
	}
	dp[0][1] = 0;
	q.push({0 , 1 , 0});
	while(not q.empty()){
		int st = q.front().st;
		int now = q.front().now;
		int las = q.front().las;
		q.pop();
		for(pii u : G[now]){
			if(dp[st][u.fi] > dp[st][now] + (lli)u.se/(1LL<<st)){
				dp[st][u.fi] = dp[st][now] + (lli)u.se/(1LL<<st);
				q.push({st , u.fi , las});
			}
			if(hve[now] and now != las and st +1 <= Q and dp[st+1][u.fi] > dp[st][now] +(lli)u.se/(1LL<<(st+1))){
				dp[st+1][u.fi] = dp[st][now] + (lli)u.se/(1LL<<(st+1));
				q.push({st+1 , u.fi , now});
			}
		}
	}
	lli ans =inf ; 
	for(int i = 0 ; i <= Q ; ++i){
		ans = min(ans , dp[i][n]);
	}
	printf("%lld",ans);
}
