#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
  struct node{
 	int st , num , wei;
	node(int a , int b , int c): st(a) , num(b) , wei(c){};
	bool operator < (const node& a) const {
		return wei > a.wei;
	} 
};
 typedef pair<int,int> pii; 
 const int lim = 5e4 + 10;
 int ord[lim];
 int dp[32][lim];
 vector<pii> G[lim];
 int main(){
  	int n , m , l , s , t;
	scanf("%d%d%d%d%d",&n,&m,&l,&s,&t);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&ord[i]);
	}
	for(int i = 1 ; i <= m ; ++i){
		int a , b , c;
		scanf("%d%d%d",&a,&b,&c);
		G[a].eb(b,c);
	}
	for(int i = 0 ; i <= l+1 ; ++i){
		for(int j = 0 ; j <= n ; ++j){
			dp[i][j] = 1e9;
		}
	}
	dp[0][s] = 0;
	priority_queue<node> pq;
	pq.push(node(0,s,0));
	while(not pq.empty()){
		int now = pq.top().num;
		int st = pq.top().st;
		pq.pop();
		for(pii v : G[now]){
			if(ord[v.fi] == st + 1 and dp[st+1][v.fi] > dp[st][now] + v.se){
				dp[st+1][v.fi] = dp[st][now] + v.se;
				pq.push(node(st+1, v.fi , dp[st+1][v.fi]));
			}
			if(dp[st][v.fi] > dp[st][now] + v.se){
				dp[st][v.fi] = dp[st][now] + v.se;
				pq.push(node(st,v.fi , dp[st][v.fi]));
			}
		}
	}
	if(dp[l][t]== 1e9)printf("-1");
	else printf("%d",dp[l][t]); 
 }
