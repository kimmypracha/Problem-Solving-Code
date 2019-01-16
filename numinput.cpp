#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  typedef pair<int,int> pii;
  vector<int> vi;
  int mx[1010];
  int mn[1010];
  int dp[2020][1020] = {};
  const int mod = 9901;
  vector<int> que;
  int cnr(int n , int r){
	if(dp[n][r] > 0) return dp[n][r];
 	if(n == r or r == 0) return 1;
	if(1 == r or r == n-1)  return n;
	return dp[n][r] = ( cnr(n-1,r-1) + cnr(n-1,r) )%mod ;
  }
  int main(){
  	int n , m;
	scanf("%d%d",&n,&m);
	vi.eb(0);
	for(int i = 1 ; i <= n ; ++i){
		int s;
		scanf("%d",&s);
		for(int j = 1 ; j <= s ; ++j){
			vi.eb(i);
		}
	}
	if(m == 0){
		int N  = vi.size() -1;
		//printf("::%d %d\n",N , n);
		printf("%d",cnr(N-1 , n-1));
		return 0;
	}
	fill(mn  , mn + 1010 , 1e9);
	fill(mx,  mx +1010 , -1e9);
	mn[1] = 1;
	mx[1] =1;
	mx[n] = vi.size()-1;
	for(int i = 1 ; i <= m ; ++i){
		int x;
		scanf("%d",&x);
		mx[vi[x]] = max(mx[vi[x]] , x);
		mn[vi[x]] = min(mn[vi[x]] , x);
	}
	if(mn[n] == 1e9)mn[n] = vi.size()-1;
	for(int i = 1 ; i <= n ; ++i){
		if(mx[i] == -1e9)continue;
		que.eb(i);
	}
	int ans = 1;
	for(int i = 1 ; i < que.size(); ++i){
		int M = que[i] - que[i-1] + 1;
		int N = mn[que[i]] - mx[que[i-1]]-1;
		ans *= cnr(N+M-1 - (M-2) , M-1);
		ans %= mod;	
	}
	printf("%d",ans);
  }
