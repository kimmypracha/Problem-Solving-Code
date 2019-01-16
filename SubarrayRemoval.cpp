#include <bits/stdc++.h>

  using namespace std;
  typedef long long int lli;
  const int lim = 1e5+10;
  lli arr[lim];
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n;  ++i){
		scanf("%lld",&arr[i]);	
		arr[i] += arr[i-1];
		printf("%lld ",arr[i]);
	}
	int mx = 0;
	lli ans = 1e18;
	for(int i = 1; i <= n ; ++i){
		if(i == n){
			if(mx != 0){
				ans = min(arr[i]- arr[mx] , ans);
			}else{
				for(int i = 1 ; i < n ; ++i){
					ans = min(arr[n]-arr[i],ans);
				}
			}
		}else{
			ans = min(arr[i] - arr[mx] , ans);
			mx = (arr[i] >= arr[mx])? i :mx;
		}
	}
	printf("%lld",arr[n] - ans); 
  }
