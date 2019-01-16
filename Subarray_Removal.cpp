#include <bits/stdc++.h>
 
 using namespace std;
  typedef long long int lli;
  const int lim= 1e5+10;
  lli arr[lim];
  lli sumf[lim] = {} , sume[lim] = {};
  lli st[lim] = {} , en[lim] = {};
  int main(){
  	int n,mn;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld",&arr[i]);
		sume[i] = arr[i] + sume[i-1];
	}
	mn = 0 ;
	en[1] = sume[1];
	if(sume[mn] >= sume[1])mn = 1;
	for(int i = 2 ; i <= n ; ++i){
		en[i] = max(sume[i] - sume[mn] , en[i-1]);
		if(sume[i] <= sume[mn])mn = i;
	}
	sumf[n] = arr[n];
	for(int i = n-1 ; i >= 1 ; --i){
		sumf[i] = arr[i] + sumf[i+1];
	}
	mn = n+1;
	st[n] = sumf[n];
	if(sumf[n] <= sumf[mn])mn = n;
	for(int i = n-1 ;  i >= 1 ; --i){
			st[i] = max(sumf[i] - sumf[mn],st[i+1]);
			if(sumf[i] <= sumf[mn])mn = i;		
	}
	lli ans = -1e18;
	for(int i = 1 ; i <= n ; ++i){	
	//	printf("%d : %d + %d = %d \n",i , en[i-1] , st[i+1] , en[i-1] + st[i+1]);
		ans = max(ans , en[i-1] + st[i+1]);
	}
	printf("%lld",ans);
  }
