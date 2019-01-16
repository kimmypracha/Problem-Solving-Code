#include <bits/stdc++.h>
#define fi first
#define se second
  using namespace std;
 typedef pair<int,int> pii;
  int dir[2][6] = {{1 , -1 , 1, -1 , 1 , -1},{0 , 0 , -1, -1 , 1 ,1}};
  int dp[2020][2020];
  int main(){
  	for(int i = 1 ; i <= 2000 ; ++i){
		for(int j = 1 ;  j <= 2000 ; ++j){
			dp[i][j] = 1e9;
		}
	}
	dp[1][1] = 0;
	queue<pii> q;
	q.push(pii(1,1));
	while(not q.empty()){
		int nx = q.front().fi;
		int ny = q.front().se;
		q.pop();
		for(int i = 0 ; i < 6 ; ++i){
			int A  = nx + dir[0][i];	
			int B = ny + dir[1][i];
			if(A < 1 or B < 1 or A > 2000 or B  > 2000)continue;
			if(dp[A][B] > dp[nx][ny] + 1){
				dp[A][B] = dp[nx][ny] +1;
				q.push(pii(A,B));
			}
		}
	}
	for(int i = 1 ; i <= 2000 ; ++i){
		for(int j= 1;  j<= 2000 ; ++j){
			int dx = i-1;
			int dy = j-1;
			int sum;
			if(dx >= dy) sum = dx;
			else sum = ((dx+dy)&1)? dy+1 : dy;
			if(sum != dp[i][j]){
				printf("%d %d : %d %d\n",i,j,dp[i][j],sum);
			}
		}
	}
  }
