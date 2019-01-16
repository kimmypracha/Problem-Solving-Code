#include <bits/stdc++.h>

  using namespace std;
  const int lim = 1010;
  int arr[lim][lim];
  int sum[lim][lim] = {}; 
  int dir[2][8] = {{-1 , -1 , -1 , 0 , 0 , 1, 1, 1} , {-1, 0 , 1 , -1 , 1 , -1 , 0, 1}};
  int ans = -1;
  int n , m;
  void Flood(int x , int y){
  	for(int i = 0 ;  i < 8 ; ++i){
		int A =  x  + dir[0][i];
		int B =  y + dir[1][i];
		if(A > n or B > m or A < 1 or B < 1 )continue;
		if(arr[A][B]){
			arr[A][B] = 0;
			Flood(A,B);	
		}
	}
  }
 
  void Sol(int x , int y){
  	int A = 0 , B = 0;
	for(int i =x  ; i <= n and arr[i][y] == 1 ; ++i){
		A++;
	}
	for(int i = y ; i <= m and arr[x][i] == 1 ; ++i){
		B++;
	}
	if(x+A-1 < n and y+B-1 < m and sum[x+A-1][y+B-1] - sum[x+A-1][y-1] - sum[x-1][y+B-1] + sum[x-1][y-1] == A*B){
		if(sum[x+A][y+B] - sum[x+A][y-2] - sum[x-2][y+B] + sum[x-2][y-2] == A*B) 
						ans = max(A*B,ans);
	}
	Flood(x,y);
  }
  int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ;  j <= m ; ++j){
			scanf("%d",&arr[i][j]);	
			sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	for(int i = 2 ; i <= n-1 ; ++i){
		for(int j = 2 ; j <= m-1 ; ++j){
			if(arr[i][j] == 1){
				Sol(i,j);	
			}
		}
	}
	printf("%d",ans);
  }
