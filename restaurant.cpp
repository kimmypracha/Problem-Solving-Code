#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 330;
 int mat[lim][lim];
  int main(){
  	int n , t;
	scanf("%d%d",&n,&t);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n; ++j){
			scanf("%d",&mat[i][j]);	
		}
	}
	for(int k = 1 ; k <= n ; ++k){
		for(int i = 1 ; i <= n ; ++i ){
			for(int j = 1 ; j <= n ; ++j){
				if(i == j or j == k or i == k)continue;
				if(mat[i][k] == 1e9 or mat[k][j] == 1e9)continue;
				if(mat[i][j] == mat[i][k] + mat[k][j]){
				//	printf("%d %d : %d %d %d\n",i,j,i,k,j);
					mat[i][j] = 2e9;
				}
			}
		}
	}
	int pr = 0;
	int cal =0;
	for(int i = 1 ; i <= n ; ++i){
		int cnt = 0 ;
		for(int j = 1 ; j <=  n ; ++j){
			if(mat[i][j] and mat[i][j] < 1e9)cnt++ , cal++;
		//	printf("%d ",mat[i][j]);	
		}
		//printf("\n");
		if(cnt >= 3){
			//pr++;
			if(t == 1)printf("%d",i);
			else printf("%d\n%d",i,cnt);
		}
	}
//	assert(pr == 1);
//	assert(cal/2 == n-1);
  }
