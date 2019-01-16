#include <bits/stdc++.h>
 
 using namespace std;
  int arr[101][101] = {};
   void dfs(int x , int y){
	arr[x][y] = 0;
	if(arr[x-1][y] == 1)
		dfs(x-1,y);
	if(arr[x+1][y] == 1)
		dfs(x+1,y);
	if(arr[x][y-1] == 1)
		dfs(x , y-1);
	if(arr[x][y+1] == 1)
		dfs(x, y+1);	
   }
   int main(){
  	int n , m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i<= n ; ++i){
		for(int j = 1; j <= m ; ++j){
			scanf("%d",&arr[i][j]);
		}
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1; j <= m ; ++j){
			if(arr[i][j] == 1){
				dfs(i,j);
				cnt++;
			}
		}	
	}
	printf("%d",cnt);

   }
