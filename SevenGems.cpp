#include <bits/stdc++.h>

 using namespace std;
 const int lim = 220;
 typedef struct node{
	int t , st , x , y;
 };
  char arr[lim][lim];
  int dp[7][1<<7][lim][lim];
  int dir[2][5] = {{0,1, 0 , -1,0} , {0,0, 1, 0 ,-1}};
  queue<node> q;
  int chk(int v){
	  int ans= 0;
	for(int i = 0 ; i < 7 ; ++i){
		if((1<<i)&v)ans++;
	}
	return ans;
  }
  int sh(int v){
	int ans = 0;
	for(int i = 6 ; i >= 0 ; i-- ){
		ans *=10;
		if((1<<i)&v)ans++;
	}
	return ans;
  }
   int main(){
		int n , m;
		scanf("%d%d",&n,&m);
		for(int i = 0 ; i < n;  ++i){
			scanf("%s",arr[i]);
		}
		for(int i = 0 ; i < 7 ; ++i){
			for(int j= 0 ; j < (1<<7) ; ++j){
				for(int k = 0 ; k < n ; ++k){
					for(int l = 0 ; l < m ; ++l ){
						dp[i][j][k][l] = 1e9;
					}
				}
			}
		}
		int cnt = 0;
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < m ; ++j){
				if(arr[i][j] == 'G')arr[i][j] =  'a' + cnt++;
				if(arr[i][j] == 'S'){
							arr[i][j] = '.';
							q.push({0,0,i,j});
							dp[0][0][i][j] = 0;
				}
			}
		}
		while(not q.empty()){
			int t = q.front().t;
			int st = q.front().st;
			int x = q.front().x;
			int y = q.front().y;
		   // printf("%d %d %d %d\n",t , sh(st),x,y);
			q.pop();
			if(st == (1<<7)-1){
				printf("%d",dp[t][st][x][y]);
				return 0;
			}
			for(int i = 0;  i < 5; ++i){
				int A  = x + dir[0][i];
				int B = y + dir[1][i];
				if(A < 0 or B < 0 or A >= n or B  >= m)continue;
				if(isalpha(arr[A][B]) and dp[(t+1)%6][st|(1<<(arr[A][B]-'a'))][A][B] > dp[t][st][x][y] + 1){
					dp[(t+1)%6][st|(1<<(arr[A][B]-'a'))][A][B] = dp[t][st][x][y] + 1;
					q.push({(t+1)%6 , st|(1<<(arr[A][B]-'a')) ,A , B});
				}else if(arr[A][B]>= '1' and arr[A][B] <= '6' and (((t+1)%6==(arr[A][B]-'1')) or chk(st) >= (arr[A][B] - '0'))and dp[(t+1)%6][st][A][B]  > dp[t][st][x][y] + 1){
					dp[(t+1)%6][st][A][B]  = dp[t][st][x][y] + 1;
					q.push({(t+1)%6 , st ,A , B});
				}else if(arr[A][B] == '.' and dp[(t+1)%6][st][A][B]  > dp[t][st][x][y] + 1){
					dp[(t+1)%6][st][A][B]  = dp[t][st][x][y] + 1;
					q.push({(t+1)%6 , st ,A , B});
				}
			}
		}
		printf("-1");
   }

