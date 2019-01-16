#include <bits/stdc++.h>
 
 using namespace std;
  typedef long long int lli;
  const int lim = 1e6 + 10;
  lli Arr[lim] = {0};
  lli TC[lim] = {0};
  lli DP[lim];
 int main(){
 	int N;
	scanf("%d",&N);
	for(int i =1  ; i <= N  ;++i){
		scanf("%lld",&Arr[i]);
		Arr[i] += Arr[i-1];
		if(i == 1) TC[i] = Arr[i];
		else TC[i] = Arr[i] -Arr[i-1] + TC[i-2];
	}
	TC[N+1] = TC[N-1];
	// except case 1 and 2 and
	if(N == 1){
		printf("%lld",Arr[1]);
		return 0;
	}else if(N == 2){	
		printf("%lld",Arr[2]- Arr[1]);
		return 0;
	}
	lli Min = (N-2)*Arr[1] + Arr[2]- Arr[1] + Arr[N] - Arr[2] ;
	for(int i = 1; i <= N/2-1 ; ++i){
		Min = min(Min , (N-2-i)*Arr[1] + (2*i+1)*(Arr[2] - Arr[1]) + Arr[N] - Arr[2] -(TC[N+1] - TC[N+1-2*i-2]));
	}
	printf("%lld",Min);	
 } 
