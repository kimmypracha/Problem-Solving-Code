#include <bits/stdc++.h>

  using namespace std;
  const int lim = 2e4+10;
  int mat[6][lim];
  int seg[6][6][4*lim] = {};
  int n , m , q;
  void build(int p = 1 , int l = 1 , int r = m){
   	if(l == r){
		for(int i = 1 ; i <= n ; ++i){
			seg[i][i][p] = mat[i][l];
		//	if(l == 2)
			//printf("%d %d : %d %d : %d\n",i,i,l,r,seg[i][i][p]);		
		}
	}else{
		int ans = 0;
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 ,r);
		for(int i = 1 ; i <= n ; ++i){
			for(int o = 1; o <= n ; ++o){
				for(int j= 1 ; j <= n ;++j){
					for(int k = 1 ; k <= n ; ++k){
						if(abs(j-k) > 1)continue;
	//					if(l == 1 and r == 2 and i == 1 and o == 2){
	//						printf("%d %d : %d | %d %d : %d || %d\n",i,j,seg[i][j][p<<1] , k,o,seg[k][o][p<<1|1] , seg[i][o][p]);
						//}
						if(seg[i][j][p<<1] == -1 or seg[k][o][p<<1|1] == -1)continue;
						seg[i][o][p] = max(seg[i][o][p] , seg[i][j][p<<1] + seg[k][o][p<<1|1]);
						ans = max(ans , seg[i][o][p]);
					}
				}
			//	printf("%d %d , %d %d : %d\n ",i , o , l , r , seg[i][o][p]);
			}
		}
	//	printf("%d %d :: %d\n",l,r, ans);
	}
  }
  void update(int a, int b , int v , int p = 1 , int l = 1 , int r = m){
 	if(r < b or l > b)return;
	if(l == r){
		seg[a][a][p] = v;
	}else{
		update(a , b , v , p<<1 , l , (l+r)/2 );
		update(a , b , v , p<<1|1 , (l+r)/2 + 1 ,r);
		for(int i = 1 ; i <= n ; ++i){
			for(int o = 1 ; o <= n ; ++o){
				seg[i][o][p] = 0;
				for(int j = 1 ; j <= n ; ++j){	
					for(int k = 1 ; k <= n  ;++k){
						if(abs(j-k) > 1)continue;
						if(seg[i][j][p<<1] == -1 or seg[k][o][p<<1|1] == -1)continue;
						seg[i][o][p] = max(seg[i][o][p] , seg[i][j][p<<1] + seg[k][o][p<<1|1]);	
					}
				}
			//	printf("%d %d : %d %d : %d \n",i,o,l,r,seg[i][o][p]);
			}
		}
	}	
  }
  int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d",&mat[i][j]);		
		}
	}
	for(int i = 1 ;  i<= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			for(int k = 1 ; k <= 4*m ;++k ){
				seg[i][j][k]  = -1;
			}
		}
	}
	build();
	int ans = 0 ;
	for(int i = 1 ; i <= n ; ++i){	
		for(int j = 1 ; j <= n ; ++j){
			ans = max(ans , seg[i][j][1]);
		}
	}
	//printf("%d",ans);
	for(int i = 1 ; i<=q ; ++i){
		int r , c , t;
		scanf("%d%d%d",&r,&c,&t);
		update(r,c,t);
		int ans = 0 ;
		for(int i = 1 ; i <= n ;++i){
			for(int j = 1 ; j <= n ; ++j){
				ans = max(ans , seg[i][j][1]);
			}
		}
		printf("%d\n",ans);
	}
  }
