#include <bits/stdc++.h>
 
 using namespace std;
 const int mod = 2553;
 int DP[2][5001] = {};
 int Cnr[5001][5001] = {};
 int main(){
	int n , k ;
	scanf("%d%d",&n,&k);
	int lb = (n%k)? (n/k)+1 : n/k;
	for(int i = 0 ; i  <=  5000;  ++i){
		for(int j = 0 ; j <=i ;++j ){
			if(i == 0 and j== 0) Cnr[i][j] = 1;
			else if(j == 0) Cnr[i][j] = 1;
			else Cnr[i][j]  = (Cnr[i-1][j-1] + Cnr[i-1][j])%mod;
		}
	}
	int ans = 0;
	for(int i = 0 ; i <  n + n ; ++i){
		for(int j = 0 ; j  <= min(i,n-1) ; ++j){
			if(i == 0 and j ==0)DP[i%2][j] = 1;
			else if(j == 0 || j == i) DP[i%2][j] = 1;
			else DP[i%2][j] = (DP[(i-1)%2][j] + DP[(i-1)%2][j-1])%mod;
			if((-i + n + j)%k != 0)continue;
			int x = j+1;
			int b = (-i + n + j)/k;
			if(b >=  0 and b <= x and x >= lb){
				ans = (ans + ((b%2)? -1 : 1)*Cnr[x][b]*DP[i%2][j])%mod;
			}
		}
	}
	printf("%d",(((ans*ans)%mod)*ans)%mod);	
 }

