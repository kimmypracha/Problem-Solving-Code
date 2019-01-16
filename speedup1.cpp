#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back 
 using namespace std;
 typedef pair<int,int> pii;
 typedef long long int lli;
 typedef pair<lli , int > pli;
 const int lim = 8e4+10;
 const lli inf = 1e18;
 bool hve[lim] = {};
 int idx[lim];
 vector<int> lst;
 vector<pii> G[lim];
 lli wei[13][13]; 
 lli d[lim];
 lli dp[10][13];
 bool v[10][13] = {};
 bool vis[lim] = {};
 int n;
 void bfs(int now , int pos ){
 	fill(d , d + lim , inf);
 	fill(vis , vis + lim , false);
	d[now] = 0;
	priority_queue<pli , vector<pli> , greater<pli> > pq;
	pq.push({0LL , now});
	while(not pq.empty()){
		now = pq.top().se;
		pq.pop();
		if(vis[now])continue;
		vis[now] = true;
		for(pii u : G[now]){
			if(d[u.fi] > d[now] + (lli)u.se){
				d[u.fi] = d[now] + (lli)u.se;
				pq.push({d[u.fi],u.fi});
			}
		}
	}
	for(int i = 0 ; i < lst.size() ;++i){
		wei[pos][i] = d[lst[i]];
	}
 }
 int main(){
  	int  m , l , Q;
	scanf("%d%d%d%d",&n,&m,&l,&Q); 
	for(int i = 0 ; i < m ; ++i){
		int A , B , W;
		scanf("%d%d%d",&A,&B,&W);
		G[A].eb(B,W);
	}
	for(int i = 0 ; i < l ;++i){
		int X;
		scanf("%d",&X);
		lst.eb(X);
		hve[X] = true;
	}
	if(not hve[1])lst.eb(1);
	if(not hve[n])lst.eb(n);
	sort(lst.begin() , lst.end());
	for(int i = 0 ; i < lst.size() ; ++i){
		idx[lst[i]] = i;
	}
	for(int i =0  ;i  < lst.size() ; ++i){
//		printf("%d ",lst[i]);
		bfs(lst[i] , i);	
 	}
//	printf("\n");
	for(int k = 0 ; k < lst.size() ; ++k){
		for(int i = 0 ; i < lst.size() ; ++i){
			for(int j = 0 ; j  < lst.size() ; ++j){
				wei[i][j] = min(wei[i][j] , wei[i][k]+wei[k][j]);
			}
		}
	}
//	for(int i =0  ; i < lst.size() ;++i){
//		for(int j = 0 ; j < lst.size() ; ++j){	
//			printf("%lld ",wei[i][j]);
//		}	
//		printf("\n");
//	}
	for(int i = 0 ; i  <10 ; ++i){
		for(int j = 0 ; j < 13 ; ++j){
			dp[i][j] = inf;
		}
	}
	
	queue<pii> q;
	dp[0][0]  = 0;
	q.push({0 , 0});
	v[0][0] = true;
	while(not q.empty()){
		int now = q.front().se;
		int st = q.front().fi;
		q.pop();
		v[st][now] = false; 
		for(int i = 0 ; i < lst.size(); ++i){
			if(wei[now][i] >= inf)continue;
			if(i != now and dp[st][i] > dp[st][now] + wei[now][i]/(1LL<<st)){
				dp[st][i] = dp[st][now] + wei[now][i]/(1LL<<st);
				if(not v[st][i])
				q.push({st , i}) , v[st][i] = true;
			}
			if(i != now and hve[lst[now]] and st+1 <= Q and dp[st+1][i] > dp[st][now] + wei[now][i]/(1LL<<(st+1))){
				dp[st+1][i] = dp[st][now] + wei[now][i]/(1LL<<(st+1)); 
				if(not v[st+1][i])
				q.push({st+1 , i}) , v[st+1][i] = true; 
			}
		}
	}
	lli ans = inf;
	for(int i = 0 ; i <= Q;  ++i){
//		printf("%d ",dp[i][lst.size()-1]);
		ans = min(ans , dp[i][lst.size()-1]);
	}
//	printf("\n");
	printf("%lld",ans);
 }
