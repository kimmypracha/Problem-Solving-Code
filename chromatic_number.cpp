#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  typedef long long int lli;
  typedef pair<int,lli> pii;
  typedef pair<lli,int> ppi;
  const int lim = 330;
  const lli mod = 1e9+7;
  lli d[lim];
  lli cp[lim] = {};
  lli hve[lim][lim];
  vector<pii> G[lim];
  lli dp[lim][lim] = {};
  lli cnr(int n , int k ){
  	if(dp[n][k] > 0) return dp[n][k]%mod;
	if(k == n or k == 0)return 1;
	if(k == 1 or k == n-1)return (lli)n;
	return dp[n][k] = (cnr(n-1 , k-1) + cnr(n-1,k))%mod;
  }
  int main(){
  	int n , m , k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1 ; i <= m ; ++i){
		int a , b;
 		lli c;
		scanf("%d%d%lld",&a,&b,&c);
		G[a].eb(b,c);
		G[b].eb(a,c);	
	}
	fill(d, d + lim , 1e18);
	priority_queue<ppi , vector<ppi> , greater<ppi> > pq;
	pq.push({0LL,1});
	d[1] = 0;
	hve[1][1] = 1;
	cp[1] = 1;
	while(not pq.empty()){
		int now = pq.top().se;
		pq.pop();
		for(pii x : G[now] ){
			if(d[x.fi] >= d[now] + x.se){
				if(d[x.fi] > d[now] + x.se){
					pq.push({d[now]  +x.se , x.fi});
					for(int i = 1 ; i <= n ; ++i){
						hve[x.fi][i] = hve[now][i];
					}
					hve[x.fi][x.fi] = cp[now];
					cp[x.fi] = cp[now]; 
				}
				else{
				for(int i = 1 ; i <= n ; ++i){
					hve[x.fi][i] += hve[now][i];
				}
				hve[x.fi][x.fi] += cp[now];
				cp[x.fi] += cp[now];
				}
				d[x.fi] = d[now] + x.se;
//				if(x.fi == 4)
//				printf("::%d\n",now);
			}	
		}
	}
//	for(int i = 1 ; i <= n ; ++i){
//		printf("::%d\n",cp[i]);
//		for(int j = 1 ; j <= n ; ++j){
//				printf("%d ",hve[i][j]);	
//		}
//		printf("\n");
//	}
	int cnt =0 ;
	vector<lli> vi;
	for(int i = 1 ; i <= n ; ++i){
		if(hve[n][i] != 0)
			vi.eb(hve[n][i]);
	}
	sort(vi.begin(),vi.end(), greater<lli>());
	lli mx = vi[min((int)vi.size()-1 , k-1)];
	int sel = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(hve[n][i] >= mx){
			cnt++;
		}
		if(hve[n][i] == mx){
			sel++;
		}
	}
	printf("%lld %lld",mx ,cnr(sel , k - (cnt-sel)));
  }
