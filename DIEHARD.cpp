#include <bits/stdc++.h>
 
 using namespace std;
typedef struct node{
	int p , h, a; 
};
  int dp[3][3020][3020] = {};
  int ch[] = {3 , -5 , -20};
  int ca[] = {2 , -10 , 5};
 int main(){
 	int t;
	scanf("%d",&t);
	while(t--){
		int H , A;
		scanf("%d%d",&H,&A);
		queue<node> q;
		q.push({0 , H,A});
		q.push({1,H,A});
		q.push({2,H,A});
		int ans = 0 ;
		while(not q.empty()){
			int st = q.front().p;
			int he = q.front().h;
			int ar = q.front().a;
			q.pop();
			ans = max(ans , dp[st][he][ar]);
			for(int i = 0 ; i <3 ; ++i ){
				if(i != st and he + ch[i] > 0 and ar + ca[i] > 0 and dp[i][he + ch[i]][ar + ca[i]] < dp[st][he][ar] + 1){
					dp[i][he+ch[i]][ar + ca[i]] = dp[st][he][ar] +1;
					q.push({i , he+ch[i] , ar + ca[i]});
				}
			}
		}
		for(int i = 0 ; i < 3020 ; ++i){
			for(int j = 0 ; j < 3020 ; ++j){
				dp[0][i][j] = dp[1][i][j] = dp[2][i][j]= 0;
			}	
		}
		printf("%d\n",ans);
	}
 }
