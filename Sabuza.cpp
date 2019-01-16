#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
  using namespace std;
  const int lim = 5e5 + 10;
  typedef long long int lli;
  typedef pair<lli , lli> pii;
  vector<pii> vi;
  lli dp[lim] = {};
  stack<pii> st;
  int main(){
  	int N;
	scanf("%d",&N);
	for(int i =0 ; i  < N ;++i){
		lli A , H , Z;
		scanf("%lld%lld%lld",&A,&H,&Z);
		vi.eb(A*H , Z);
	}
	vi.eb(0,1e9);
	sort(vi.begin() , vi.end());
	lli Min = vi[N].se;
	for(int i =N-1 ;  i >= 1 ;  --i){
		if(Min >= vi[i].se)vi[i].fi = vi[i].se = 1e9;
		else Min = vi[i].se;
	}
	sort(vi.begin() , vi.end());
	while(not vi.empty() and vi.back().fi == 1e9)vi.pop_back();
	N =  vi.size() - 1;
	int idx = 0 ;
	for(int i = 1;  i <= N ; ++i){
	//	printf("|%lld %lld|\n",vi[i].fi , vi[i].se);
		if(i == 1){
			dp[i] = vi[i].fi * vi[i].se;	
		}else{
			dp[i] = vi[i].fi*vi[idx+1].se + dp[idx] ;
			while(idx+2 <= i and dp[i] >= vi[i].fi*vi[idx+2].se + dp[idx+1]){
				idx++;
				dp[i] = vi[i].fi*vi[idx+1].se + dp[idx];
			}
		}
	}
	printf("%lld",dp[N]);

  }
