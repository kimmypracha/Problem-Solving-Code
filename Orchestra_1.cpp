#include <bits/stdc++.h>
  
using namespace std;
typedef long long int lli;

  lli Sum[101] = {};
  lli F[101][501] = {};
  lli dp[101][501] = {};
  int main(){
  	int n , m , k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0 ; i < n ; ++i){
		int A;
		scanf("%d",&A);
		Sum[A]++;
	}
	for(int i = 1 ; i <= m ; ++i){
		priority_queue<int> pq;
		pq.push(Sum[i]);
		int j =1 ;
		while(not pq.empty() and j <= min((lli)k , Sum[i]-1)){
			int now = pq.top();
			pq.pop();
			int Max = max(now/2 , now - now/2);
			F[i][j] = (now/2)*Max + F[i][j-1];
			j++;
			pq.push(now/2);
			pq.push(now - now/2);
		}
		
	}
	for(int i =1 ; i <= m  ; ++i){
		for(int j = 0 ; j <= k ; ++j){
			dp[i][j] = 1e18;
			for(int l = 0 ; l <= j ; ++l){
				dp[i][j] =min(dp[i-1][l] + (Sum[i]*(Sum[i]+1))/2 - F[i][j-l] , dp[i][j]);
			}
		}
	}
	printf("%lld", dp[m][k]);	
  }
