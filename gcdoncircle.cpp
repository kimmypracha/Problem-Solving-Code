#include <bits/stdc++.h>

  using namespace std;
 const int lim = 1e5 + 10;
 int arr[lim]; 
 int dp[lim] = {};
 int seg[lim<<1] = {};
 int n;
 int rmq(int l , int r ){
	int ans = 0;
 	for( l+= n , r += n ; l < r ; l >>= 1 , r >>= 1 ){
		if(l&1) ans = (ans)? gcd(ans , seg[l++]) : seg[l++];
		if(r&1) ans = (ans)? gcd(ans , seg[--r]) : seg[--r];
	}
	return ans;
 }
 int fnd(int idx){
 	int l = 0 , r = idx+1 ;
	int m;
	while(l < r){
		m = (l+r)/2;
		if(rmq(0 , m) == 1){
			l = m+1;
		}else{
			r = m;
		}
	}
 }
 void build(){
	for(int i= n ; i < n +n ; ++i){
		seg[i] = arr[i];
	}
 	for(int i = n-1 ;i; ++i){
		seg[i] = gcd(seg[i<<1] , seg[i<<1|1]);
	}
  }

 int main(){
	scanf("%d",&n);
	for(int i = 0 ; i < n;  ++i){	
		scanf("%d",&arr[i]);
	}
	int tmp = arr[0];
	int s = n;
	for(int i = 1 ; i < n;  ++i){
		tmp = gcd(tmp , arr[i]);
		if(tmp == 1){
			s = i ;
			break;
		}
	}
	rotate(arr , arr + s , arr + n);	
	for(int i =0 ; i < n; ++i){
		int far = fnd(i);
		dp[i] = i - far +((i)?  dp[i-1] : 0);
	}
	printf("%d",dp[i]);
 }
