#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 2e5+10;
 int s[lim] = {} , t[lim] , p[lim];
 int dp[lim];
 vector<int> vi;
 int main(){
 	int n ,m , k;
	scanf("%d%d%d",&n,&m,&k);
	fill(dp + 1 , dp + 1 + n , 1e9);
	dp[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d%d%d",&s[i],&t[i],&p[i]);
		dp[i] = s[i] - s[i-1] + dp[i-1];
	} 
	for(int i = 1 ; i <= k ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(dp[i])
		}
	}
 }
