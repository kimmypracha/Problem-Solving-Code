#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  const int lim  = 5e4+10;
  vector<int> cp[lim];
  vector<int> ll[lim] , fl[lim];
  int dp[1<<5][1<<5][2];
  int n;
  int cal(int val){	
  	return (val < 0)? val + n : val;  
  }
  int cost(int st ,int pos){
	int cnt = 0;
	bitset<5> tmp(st);
	for(int peo : cp[pos]){
		bool hve = false; 
		for(int idx : ll[peo]){
			if(tmp[cal(idx-pos)])hve = true;
		}
		for(int idx : fl[peo]){
			if(tmp[cal(idx-pos)] == 0)hve = true;
		}
		if(hve)cnt++;	
	}
	return cnt;	
  }
  bool eq(int j , int k , int pos){
	bitset<5> a(j), b(k);
  	for(int i = 0 ; i < pos-n+4 ; ++i){
		if(a[i] != b[i+n-pos+1]){
		//	printf("||%d not equal %d||\n",i,i+n-pos+1);
		//	printf("::%d %d\n",j,k);
		//	printf("::%d %d\n",1<<i , 1<<(i+n-pos+1));
		//	printf("||%d %d\n",)
			return false;
		}
	}
	return true;
  }
  int main(){
  	int  c;
	scanf("%d%d",&n,&c);
	for(int i = 1 ; i <= c; ++i){
		int E , F , L;
		scanf("%d%d%d",&E,&F,&L);
		cp[E].eb(i);
		for(int j = 0 ; j < F ; ++j){
			int x;
			scanf("%d",&x);
			fl[i].eb(x);
		}
		for(int j = 0 ; j < L ; ++j){
			int x;
			scanf("%d",&x);
			ll[i].eb(x);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 0 ; j < (1<<5) ; ++j){
			for(int k = 0 ; k  < (1<<5) ; ++k){
				dp[j][k][i%2] = -1;
			}
		}
		for(int j = 0 ; j < (1<<5) ; ++j){
			if(i == 1){	
				dp[j][j][i] = cost(j,i);
			//	if(dp[j][j][i] > 0)
			//		printf("%d %d %d : %d\n",j,j,i,dp[j][j][i]);
			}
			else{
				for(int k = 0 ; k < (1<<5)  ; ++k){
					if(i > n-4 and !eq(j,k ,i))continue;
			//		if(i == 12 )printf("||%d %d\n",j,k);
					if(dp[j][(k<<1)%32][(i-1)%2]==-1 and dp[j][(k<<1|1)%32][(i-1)%2] == -1)continue;
					dp[j][k][i%2] = max(dp[j][(k<<1)%32][(i-1)%2] , dp[j][(k<<1|1)%32][(i-1)%2]) + cost(k,i);
		//			if(j == 9 and k == 4){
		//				printf("%d %d %d\n",dp[j][(k<<1)%32][(i-1)%2], dp[j][(k<<1|1)%32][(i-1)%2] , cost(j,i));
					//}
						//if(i == 12 and dp[j][k][i%2] > 0)printf("%d %d %d : %d\n",j,k,i,dp[j][k][i%2]);
				 }
			}
			
		}
	}
	//for(int i = 0 ; i < (1<<5) ; ++i){
	//	if(eq(31,i,12))printf("YES %d\n",i);
	//}
//printf("\n%d\n",eq(31,0,12)); 
	//printf("%d\n",eq(24,3,13));
	int ans = 0 ;
	for(int j = 0 ; j < (1<<5) ; ++j){
		ans = max(ans , max(dp[j][(j<<1)%32][n%2] , dp[j][(j<<1|1)%32][n%2]));
	}
	printf("%d",ans);
  }
