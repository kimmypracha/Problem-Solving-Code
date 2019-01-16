#include <bits/stdc++.h>
 
  using namespace std;
  typedef long long int lli;
  const int lim = 1e3+10;
  const lli mod = 1e9+7;
  set<int> st;
  int fre[lim];
  int pos[lim];
  int hsh[lim];
  int sf[lim];
  lli dp[lim][lim];
  lli cnt[lim][lim];
  inline lli cnr(int n , int r){
	if(n < 0 or r < 0 or n < r)return 0;
	return cnt[n][r];	
  }
  void prep(){
	for(int i = 1 ; i < lim ; ++i){
		for(int j = 0 ; j  <= i ; ++i){
			if(j == 0 or j == i)cnt[i][j] = 1;	
			else cnt[i][j] = cnt[i-1][j] + cnt[i-1][j-1];
			cnt[i][j] %= mod;
		}	
	}	
  }
  int main(){ 
  	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i){
		int x;	
		scanf("%d",&x);
		fre[x]++;
		st.insert(x);
	}
	int idx = 1;
	hsh[0] = 0;
	for(int x : st){
		hsh[idx] = x;
		sf[x] = sf[hsh[pos[x]-1]] + fre[x];
		pos[x] = idx++;	
	}
	for(int x : st){
		int i = pos[x];
		if(i == 1){
			dp[i][fre[x]] = 1;	
		}else{
			for(int j = 0 ; j <= n ; ++j){
				for(int k = 0 ; k <= fre[x] and j+k <= n; ++k){
					int m = sf[hsh[pos[x]-1]]+1;
					dp[i][j] += 
					dp[i-1][j+k]*cnr(j+k,k)*cnr(m-(j+k),fre[x]-k); 
					dp[i][j] %= mod;
				}
			}
		}	
	}
	printf("||%d\n",idx);
	printf("%lld",dp[idx-1][0]);
  }
