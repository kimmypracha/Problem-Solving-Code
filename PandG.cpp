#include <bits/stdc++.h>
#define fi first
#define se second
  using namespace std;
  typedef pair<int,int> pii;
  int dp1[110][110] , dp2[110][110];
  char arr[110][110];  
  int dir[2][4] = {{1, 0 , -1, 0 } , {0 ,  1 , 0 , -1}};
  int main(){
  	int K;
	scanf("%d",&K);
	while(K--){
		for(int i =0 ; i < 110 ; ++i){
			for(int j = 0 ; j < 110 ; ++j){
				dp1[i][j] = dp2[i][j]  = 1e9;
			}
		}
		int R, C  ,n , T , r , c;
		queue<pii> q;
		scanf("%d%d%d%d%d%d",&R,&C,&n,&T,&r,&c);
		dp1[r][c]= 0;
		q.push({r,c});
		while(not q.empty()){
			int nx  = q.front().fi;
			int ny  = q.front().se;
			q.pop();
			for(int i = 0 ; i < 4 ; ++i){
				int A = nx  + dir[0][i];
				int B = ny + dir[1][i];
				if(A < 0 or B < 0 or A >= R  or B >= C)continue;
				if(arr[A][B] == '#')continue;
				if(dp1[A][B] > dp1[nx][ny] + 1){
					dp1[A][B] = dp1[nx][ny] + 1;
					if(dp1[A][B] < T)
						q.push({A,B});
				}
			}
		}
		for(int i = 0 ; i  < n ; ++i){
			int t,x , y;
			scanf("%d%d%d",&t,&x,&y);
			dp2[x][y] = min(dp2[x][y] , t);
		}
		for(int i = 0 ; i < R ;  ++i){
			scanf("%s",arr[i]);
		}
		for(int i = 0 ; i  < R ;++i ){
			for(int j = 0 ; j < C ; ++j){
				if(dp2[i][j] != 1e9 and dp2[i][j] != T)q.push({i,j});
			}
		}
		while(not q.empty()){
			int nx = q.front().fi;
			int ny = q.front().se;
			q.pop();
			for(int i = 0 ; i  <4 ; ++i){
				int A = nx + dir[0][i];
				int B  = ny + dir[1][i];
				if(A < 0 or B < 0 or A >= R or B >= C)continue;
				if(arr[A][B] == '#')continue;
				if(dp2[A][B] > dp2[nx][ny] + 1 ){
					dp2[A][B] = dp2[nx][ny] + 1;
					if(dp2[A][B] < T)q.push({A,B});
				}
			}
		}
		bool ans = false;
		for(int i = 0 ; i  <R ; ++i){
			for(int j = 0;  j < C ; ++j){
	//			printf("(%d , %d) ", dp1[i][j] , dp2[i][j]);
				if(dp1[i][j] <= T and dp2[i][j] == 1e9){
					ans = true;
					break;
				}
			}
		//	printf("\n");	
			if(ans)break;
		}
		if(ans)printf("YES\n");
		else printf("NO\n");
	} 
 }
