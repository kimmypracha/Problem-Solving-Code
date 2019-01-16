#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 const int lim = 330;
 typedef pair<int,int> pii;
vector<pii> vi;
 int dp[lim][lim]; 
 int main(){
	int t;
	scanf("%d",&t);
	while(t--){
  	int n;
	scanf("%d",&n);
	vi.clear();
	for(int i =0  ; i <  n ;++i){
		int s  ,t ;
		scanf("%d%d",&s,&t);
		vi.eb(s,t);	
	}
	sort(vi.begin()  , vi.end(), [](const pii &a , const pii &b)-> bool{return (a.fi == b.fi)? a.se > b.se : a.fi < b.fi;});
	for(int L = 1 ;  L <= n ; ++L){
		for(int i = 0 ; i < n-L+1 ; ++i){
			int j = i+L-1;
			dp[i][j] = 0;
			if(i == j){
				dp[i][j] = 1;
				continue;
			}
			for(int k = i+1 ; k<=j ; ++k){
				if(vi[i].se <= vi[k].fi or vi[i].se >= vi[k].se)
					dp[i][j] = max(dp[i][j] , dp[i][i]  +dp[k][j]);
			}
		}
	}
	printf("%d\n",dp[0][n-1]);
	}
  }
