#include <bits/stdc++.h>
 
 using namespace std;
 typedef long long int lli;
 lli dp[2][60] = {};
 int main(){
 	string A;
	cin >> A;
	int n = A.size();	
	for(int i = n-1 ; i >= 0 ; --i){
		if(i == n-1){
			dp[1][i] = (A[i] == '1')? 0 : 1;
			dp[0][i] = (A[i] == '0')? 0 : 1;
		}else{
			if(A[i] == '1'){
				dp[0][i] = dp[1][i+1] + 1 + (1LL<<(n-i-1)) - 1;
				dp[1][i] = dp[0][i+1];
			}else{
				dp[0][i] = dp[0][i+1];
				dp[1][i] = dp[1][i+1] + 1 + (1LL<<(n-i-1)) - 1;
			}
		}
	}
	printf("%lld",dp[0][0]);
 }
