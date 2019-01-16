#include <bits/stdc++.h>
#define fi first
#define se second
 using namespace std;
  const int lim= 1e3 + 10;
  typedef pair<int,int> pii;
  pii Arr[lim][lim] = {};
  pii dp2[lim][lim] = {} , dp5[lim][lim] = {}; 
  int par2[lim][lim] = {} , par5[lim][lim] = {}
  int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n;  ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp2[i][j]  = dp5[i][j]= 2e9;
			int A;
			scanf("%d",&A);
			int a=  0 , b = 0;
			while(A%5 == 0){
				A/=5;
				a++;
			}
			while(A%2 == 0){
				A/=2;
				b++;
			}
			Arr[i][j] = {b,a};
		}
	}
	for(int i =1 ; i <= n; ++i){
		for(int j =1 ; j <= n;  ++j){
			if(dp2[i][j].fi > dp2[i-1][j].fi + Arr[i][j].fi){
				dp2[i][j].fi = dp2[i-1][j].fi + Arr[i][j].fi;
				dp2[i][j].se = dp2[i-1][j].se + Arr[i][j].se;
				par2[i][j] = 1;
			}
			if(dp2[i][j].fi >= dp2[i][j-1].fi + Arr[i][j].fi){
				if(dp2[i][j].fi == dp2[i][j-1].fi + Arr[i][j].fi and dp2[i][j].se > dp2[i][j-1].se + Arr[i][j].se){
					dp2[i][j].se = dp2[i][j-1].se + Arr[i][j].se;
					par2[i][j] = 2;
				}else if(dp[i][j].fi > dp2[i][j-1].fi + Arr[i][j].fi){
					dp2[i][j].fi = dp2[i][j-1].fi + Arr[i][j].fi;
					dp2
				}
			}
		}
	}
 }
