#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define ls(x) (x&(-x))
  using namespace std;
  typedef long long int lli;
  typedef pair<int,int> pii;
  const lli mod = 1e9 + 7;
  const int lim = 1e5 + 10;
  vector<pii> vi;
  lli ft[lim] = {};
  lli dp[lim] = {};
  int n;
  void update(int pos , lli val){
  	for(;pos < lim ; pos += ls(pos)){
		ft[pos] += val;
	}
  }
  lli rmq(int pos){
  	lli sum = 0;
	for( ; pos ; pos -= ls(pos)){
		sum += ft[pos];
	}
	return sum;
  }
  int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n;  ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		vi.eb(a,b);
	}
	dp[0] = 1;
	sort(vi.begin() , vi.end());
	for(int i = 1 ; i < n ; ++i){
		if(vi[i].fi != vi[i-1].fi){
			for(int j = i-1 ; j >= 0 and vi[j].fi == vi[i-1].fi; --j ){
				update(vi[j].se , dp[j]);
			}
		}
			dp[i] = (((rmq(lim-1) - rmq(vi[i].se))%mod) + mod)%mod;
//			printf("||%lld ",dp[i]);
			dp[i] = (dp[i] + 1)%mod;
//			printf("::%lld\n",dp[i]);
	}
	lli ans = 0;
	for(int i = 0; i < n; ++i){
		//printf("%d\n", dp[i]);
		ans = (ans + dp[i])%mod;
	}
	printf("%lld",ans);
  }
