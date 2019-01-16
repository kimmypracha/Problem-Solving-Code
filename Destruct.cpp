#include <bits/stdc++.h>

 using namespace std;
 const int lim = 5e4+ 10;
 long long int  DP[2][lim] = {};
 long long int  Arr[lim] = {};
 int main(){
  	int N , K , M;
	scanf("%d%d%d",&N,&K,&M);
	for(int i = 1; i <= N ;++i){
		scanf("%lld",&Arr[i]);
		Arr[i] = Arr[i] + Arr[i-1];
	}
	long long int MA;
	for(int i = 1 ; i <= K ; ++i){
		fill(DP[i%2] , DP[i%2] + lim,  1e18);
		MA = -1e18;
		for(int j = M*i+i-1 ; j <= N ; ++j){
			if(i == 1){
				MA = max(MA , Arr[j-M]);
				if(j != M)
					DP[i%2][j] = min(Arr[j] - MA , DP[i%2][j-1]);
				else DP[i%2][j] = Arr[j] - MA;
			}else{
				MA = max(MA , Arr[j-M] - DP[(i-1)%2][j-M-1]);
				if(j != M*i + i -1){
					DP[i%2][j] = min(Arr[j] - MA , DP[i%2][j-1]);
				}
				else DP[i%2][j] = Arr[j] - MA;
			}
		}
	}
	printf("%lld",Arr[N] - DP[K%2][N]);
 }
