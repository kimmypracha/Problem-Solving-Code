#include <bits/stdc++.h>

 using namespace std;
 int arr[52][52];
 int col[52][52] = {};
 int sz[3000] = {};
 int dir[2][4] = { {0 , -1 , 0 , 1} , {-1 , 0 , 1 , 0}};
 int chk[4] = {1 , 2 , 4 , 8};
 int cnt = 1;
  int n , m;
 void dfs(int x , int y){
	sz[cnt]++;
 	for(int i =  0 ; i < 4 ; ++i){
		if(arr[x][y]&chk[i])continue;
		int nx = x + dir[0][i];
		int ny = y + dir[1][i];
		if(nx <= 0 or ny <= 0 or nx > n or ny > m)continue;
		if(col[nx][ny] == 0){
			col[nx][ny] = cnt;
			dfs(nx, ny);
		}
	}
 }
  int main(){
	scanf("%d%d",&m,&n);
	for(int i = 1 ; i <=  n ; ++i ){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d",&arr[i][j]);
		}
	}
	int mx = 0;
	for(int i = 1 ; i <= n ; ++i){	
		for(int j = 1 ; j <=m ; ++j){
			if(col[i][j] == 0){
				col[i][j] = cnt;
				dfs(i , j);
		//		if(sz[cnt] == 10)printf(":: %d\n",cnt);
				mx = max(mx, sz[cnt]);
				cnt++;
			}
		}
	}
//	for(int i= 1 ; i <= n ; ++i){
//		for(int j =1 ; j<=m ; ++j){
//			printf("%d ",col[i][j]);	
//		}
//		printf("\n");
//	}
	printf("%d\n",cnt-1);
	printf("%d\n",mx);
	int ans = 0 , x , y , dir = 0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(col[i-1][j] != col[i][j] and col[i-1][j] != 0){
				if(ans < sz[col[i-1][j]] + sz[col[i][j]]){
					ans = sz[col[i-1][j]] + sz[col[i][j]];
					x = i;
					y = j;
					dir = 1;
				}else if(ans == sz[col[i-1][j]] + sz[col[i][j]]){
					if(j > y){
						x = i;
						y = j;
						dir = 1;
					}else if(j == y and )
				}
			}
		}
	}
  }

