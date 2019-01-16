#include <bits/stdc++.h>

  using namespace std;
  typedef long long int lli;
  const int lim = 5e3+10;
 lli a[lim];
 lli b[lim];
 lli dp[2][lim] = {}; 
 int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 0 ; i <  n ; ++i){
		scanf("%lld",&a[i]);
		b[i] = a[i];
	}
	sort(b , b +n );
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n;  ++j){
			if(i == 0 and j == 0) dp[i%2][j] = abs(a[0]-b[0]);
			else if(i == 0) dp[i%2][j] = min(dp[i%2][j-1] , abs(a[i] - b[j]));
			else if(j == 0) dp[i%2][j] = abs(a[i]-b[j]) + dp[(i-1)%2][j];
			else dp[i%2][j] = min(dp[i%2][j-1] , dp[(i-1)%2][j] + abs(a[i] - b[j]));	
		}
	}
	printf("%lld",dp[(n-1)%2][n-1]);
 }
