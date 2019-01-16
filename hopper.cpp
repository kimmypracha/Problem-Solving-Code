#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
  const int lim = 3010;
  typedef pair<int,int> pii;
  int m;
  int arr[lim];
  vector<pii> G[lim];
  vector<int> tp;
  int deg[lim] = {};
  int dp[lim] = {};
  int mark[lim] = {};
  bool Can(int k){
	fill(dp , dp + lim , 0);
	for(int i = 0 ; i < tp.size();  ++i){
		for(pii u : G[tp[i]]){
			if(u.se <= k)
				dp[mark[u.fi]] = max(dp[i]+1 , dp[mark[u.fi]]);
		}
	}
	for(int i = 0 ; i < tp.size(); ++i){
		if(dp[i] >= m)return true;
	}
	return false;	
  }
 int main(){
  	int n ;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n ; ++i){
		scanf("%d",&arr[i]);	
	}
	for(int i = 1; i<=n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(arr[i] < arr[j]){
				G[i].eb(j , (i < j)? j-i : n-i+j);
				deg[j]++;
			}
		}
	}
	queue<int> q;
	for(int i = 1 ; i <= n ; ++i){
		if(deg[i] == 0)q.push(i);
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
	  	tp.eb(now);
		for(pii u : G[now]){
			if(--deg[u.fi] == 0)q.push(u.fi);	
		}
	}
	for(int i = 0 ;i  < tp.size() ; ++i){
		mark[tp[i]] = i;
	}
	int l = 1 , r = n;
	int mid;
	while(l <r ){
		mid = (l+r)/2;
		if(Can(mid)){
			r = mid;
		}else{
			l = mid+1;
		}
	}
//	for(int i = 0 ; i < tp.size(); ++i){
//		for(int j = 0 ; j <= m-1 ; ++j){
//			if(dp[i][j] == 1e9)continue;
//			for(pii u : G[tp[i]]){
//				if(dp[mark[u.fi]][j+1] > max(dp[i][j],u.se)){	
//					dp[mark[u.fi]][j+1] = max(dp[i][j],u.se);
//				}
//			}
//		}
//	}
//	int ans = 1e9;
//	for(int i = 0 ; i < tp.size();  ++i){
//		ans = min(ans , dp[i][m]);
//	}
	printf("%d",l);
 }
