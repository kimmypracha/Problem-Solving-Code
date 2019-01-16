#include <bits/stdc++.h>

  using namespace std;
  typedef long long int lli;
  int k;
  lli cost[1<<8];
  lli dp[30][1<<8][1<<8] = {};
  int cm = 0  , cd = 0;
  lli Merge(int sta , int stb , int sz , int add = 0){
  	int pos = 0;
 	lli ans = 0;
	cm++;
	if(sz < k ){
		for(int i = 0 ; i  < sz ;++i ){
			pos <<= 1;
			if(sta&(1<<i))pos |= 1;	
		}
		for(int i = 0 ; i < sz ; ++i){
			pos <<= 1;
			if(stb&(1<<i))pos |= 1;
		}
		
	//	if(sz == 2 )printf("\nbit : %d\n",pos);
		for(int i = 2*sz ; i >= k ; --i){
			ans += cost[pos%(1<<k)];
			pos >>= 1;
		}
		return ans;
	}else{
		for(int i = 0 ; i < k  ;++i){
			pos <<= 1;
			if(sta&(1<<i))pos |= 1;
		}
		for(int i = 0;  i < k ; ++i){
			pos <<= 1;
			if(stb&(1<<i))pos |= 1;
		}
	//	if(sz == 2)
	//	printf("\nbits : %d\n",pos);
		for(int i = 2*k ; i >= k ; --i,pos >>=1){

			if(i == k and add == 0)continue;
			if(i == 2*k)continue;
			ans += cost[pos%(1<<k)];
		}
		return ans;
	}
  }
  lli rec(int sta , int stb , int n , int c){
	lli ans = 0;
	if(dp[c][sta][stb] > 0) return dp[c][sta][stb];
	if(n < k) return 0;
	else if(n == k and sta != stb)return -1e18;
	else if(n == k)return cost[(1<<k)-1-sta];
	//printf("::%d\n",n);
	cd++;
	for(int i  = 0 ; i < (1<<k) ; ++i){
		for(int j = 0 ; j < (1<<k) ; ++j){
			if(n&1){
		//		printf("st : %d %d | %d %d n = %d : %d + %d : %d %d \n"
		//		,sta,i,j,stb,n,rec(sta,i,n/2,c+1)
		//		,rec(j,stb,n/2,c+1) , Merge(i>>1|(1<<(k-1)),j,n/2,1) , 
		//		Merge(i>>1,j,n/2,1));
				ans = max(rec(sta , i,n/2,c+1) + rec(j , stb ,n/2 , c+1) + 
				max(Merge(i>>1|(1<<(k-1)),j,n/2,1) , Merge(i>>1,j,n/2 ,1))
				,ans);
			}
			else 
				ans = max(rec(sta,i,n/2,c+1)+rec(j,stb,n/2,c+1)+Merge(i,j,n/2),ans);
		}
	}
	//printf("%d %d %d: %d\n",sta,stb,n,ans);
	//scanf("%*c");
	return dp[c][sta][stb] = ans;
  }
  int main(){
  	int n ;
	scanf("%d%d",&n,&k);	
	for(int i = 0 ; i < (1<<k) ; ++i){
		scanf("%lld",&cost[i]);
	}
	lli ans = 0 ;
	for(int i = 0 ; i < (1<<k) ; ++i){
		for(int j = 0 ; j  < (1<<k) ; ++j){
	//		printf("%d %d : %d \n",i,j,rec(i,j,n,0));
//			printf("::%d %d\n",i,j);
			ans = max(rec(i , j ,n , 0) , ans);	
		}
	}
//	printf("DP : %d | Merge : %d\n",cd , cm);
	printf("%lld",ans);
  }
