#include <bits/stdc++.h>

 using namespace std;
 int dp[26][110] = {};
 int main(){
 	int n;
	string S;
	scanf("%d",&n);
	cin >> S;
	for(int i =0 ; i < n ; ++i){
		for(int j = 0 ; j < 26 ; ++j){
			dp[j][i] = (i)? dp[j][i-1] : 0 ;
		}
		dp[S[i] - 'a'][i]++;
	}
	int ans = 0 ;
	for(int i =0 ; i< n-1 ; ++i){
		int cnt = 0; 
		for(int j = 0 ; j < 26 ; ++j){
			if(dp[j][i] > 0 and  dp[j][n-1] - dp[j][i] > 0 )cnt++;
		}
		ans = max(ans, cnt);
	}
	printf("%d",ans);
 }
