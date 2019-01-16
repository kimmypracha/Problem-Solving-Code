#include <bits/stdc++.h>
#define fi first
#define se second 
 using namespace std;
 const int lim = 2020;
 typedef pair<int,int> pii;
 int arr[lim] = {0};
 int dp[lim][lim];
  queue<pii> q;
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&arr[i]);
	}
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = 2e9+100;
		}
	}
	dp[0][0] = 0;
	q.push({0 , 0});
	int ans = 0 ;
	while(not q.empty()){
		int st = q.front().fi;
		int now = q.front().se;
		printf("%d %d : %d \n",st , now , dp[st][now]);
		q.pop();
		if(st == 0){
			ans = max(ans , dp[st][now]);
		}
		if(now == n-1){
			continue;
		}
		if(st >= 2 and dp[st-2][now+1] > dp[st][now] - arr[now+1]){
			dp[st-2][now+1] = dp[st][now] - arr[now+1];
			q.push({st - 2 , now+1});
		}
		if(dp[st+1][now+1] > dp[st][now] + arr[now+1]){
			dp[st+1][now+1] = dp[st][now] + arr[now+1];
			q.push({st+1 , now+1});
		}
	}
	printf("%d",ans);
 }
