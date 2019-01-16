#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back 
 using namespace std;
 const int lim = 1e5 + 10;
 typedef pair<int,int> pii;
 vector<pii> G[lim];
 int n, k;
 queue<int> q;
 int seg[4*lim];
 int lev[lim] = {};
 int noi[lim] = {};
 int dp[lim];
vector<int> eul;

 void dfs(int now){
	eul.eb(now);
	noi[now] = eul.size() -1; 
	for(auto i : G[now]){
		if(dp[i.fi ] > dp[now] + i.se){
			dp[i.fi] = dp[now] + i.se;
			lev[i.fi] = lev[now] + 1;
			dfs(i.fi);
			eul.eb(now);
		}
	}
 }
 int rmq(int a,  int b){
	int Max = eul[a];
	a += eul.size();
	b += eul.size();
 	for(; a < b ; a >>= 1 , b >>= 1){
		if(a&1){
			 Max =  (lev[seg[a]] > lev[Max] )? Max : seg[a] ;
			 a++; 
		}
		if(b&1){
			 b--;
			 Max =  (lev[seg[b]] > lev[Max])? Max : seg[b];
		}   
	}	
	return Max;
 }
 void build(){
 	for(int i = 0 ; i < eul.size();  ++i){
		seg[eul.size() + i] = eul[i];
	}
	for(int i = eul.size() - 1; i >= 1 ; --i){
		seg[i] = (lev[seg[i<<1]] < lev[seg[i<<1|1]])? seg[i<<1] : seg[i<<1|1]; 
	}
 }
  int main(){
	scanf("%d%d",&n,&k);
	for(int i= 0; i < n-1 ; ++i){
		int a , b , w;
		scanf("%d%d%d",&a,&b,&w);
		G[a].eb(b,w);
		G[b].eb(a,w);
	}
	fill(dp , dp + n , 1e9);
	dp[0] = 0;
	dfs(0);
	build();
	for(int i =0 ;  i < k ; ++i){
		int x , y;
		scanf("%d%d",&x,&y);
		if(noi[x] < noi[y])
		printf("%d\n", dp[y] +  dp[x] - 2*dp[rmq(noi[x] , noi[y]+ 1)] );
		else 
		printf("%d\n", dp[y] + dp[x] - 2*dp[rmq(noi[y] , noi[x] + 1)]);
	}
  }
