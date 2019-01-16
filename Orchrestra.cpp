#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 lli Sum[102] = {};
 lli dp[102][502];
 lli Ans = -1;	
 lli play(int m , int k ){
 	if(Ans == -1){
		Ans = (Sum[m]*(Sum[m] + 1))/2 ;
	}else{
		lli div = 1;
		while(div <= k)div<<=1;
		Ans -= (Sum[m]/div)*(Sum[m]/div);
	}
	return Ans;
 }
 int main(){
 	int n, m  , k ;
	scanf("%d%d%d",&n,&m,&k);
	for(int i =0 ;  i < n ; i++){
		int A;	
		scanf("%d",&A);
		Sum[A]++;
	}
	for(int i = 1 ; i <= m ; ++i){
		for(int j = 0 ; j <= k ; ++j){
			for(int l = 0 ; l <= j ; ++l){
				dp[i][j] = play(i, j-l) + dp[i-1][l];	
			}
			Ans = -1;
		}
	}
	printf("%lld",dp[m][k]);
 }
