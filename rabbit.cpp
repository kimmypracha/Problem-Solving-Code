#include <bits/stdc++.h>

  using namespace std;
  typedef long long int lli;
  int Arr[102];
  bool hsh[1000001] = {};
  lli fac[1000001] = {};
  map<int , int > rev;
  lli p = 1e9 +7 ;
  lli dp[102][102] = {};
  int pow(lli now , lli ex){
	if(rev[now] > 0)return rev[now];
	if(ex == 0) return 1;
  	if(ex == 1) return rev[now] = (int)(now%p);
	lli tmp = pow(now, ex/2);
	if(ex&1) return rev[now] = (((tmp*tmp)%p)*now)%p;
	else return rev[(int)now] =(int) ((tmp*tmp)%p);
  }
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i =0  ; i <  n;  ++i){
		scanf("%d",&Arr[i]);
		hsh[Arr[i]] = true;
	}
	fac[0] =1;
	for(int i =1 ; i < 1000001 ; ++i){
		fac[i] = (i*fac[i-1])%p;
	}
 //	return 0;
	for(int i =1 ; i <=n ; ++i ){
		for(int j =0  ; j < n-i+1 ; ++j){
			int k = j + i -1;
			if(i == 1){
				dp[j][j] = (lli)Arr[j];
			}else{
				for(int l = j ; l < k ; ++l ){
					lli A = max(dp[j][l] , dp[l+1][k]);
					lli B = min(dp[j][l] , dp[l+1][k]);
					dp[j][k] = max( (((fac[A]*pow(fac[A-B],p-2))%p)*pow(fac[B],p-2))%p , dp[j][k] );			
				
				//	lli tmp = pow(1000000,fac[1000000] , p-2);
				}
			}
		}
	}
	printf("%lld", dp[0][n-1]);
  }
