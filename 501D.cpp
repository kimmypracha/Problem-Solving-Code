#include <bits/stdc++.h>
#define ls(x) (x&(-x))
  using namespace std;
 const int lim = 2e5+ 10;
 int n;
 int ft[lim] = {};
 int A[lim] = {};
 int B[lim] = {};
 int C[lim] = {};
 int rmq(int pos){
  	int ans =0 ; 
	for( ; pos ; pos -= ls(pos)){
		ans += ft[pos];
//		printf("*\n");
	}
	return ans;
 }
 void update(int pos , int val){
 	for( ; pos <= n ; pos += ls(pos)){
		ft[pos] += val;
//		printf("%d\n",pos);
	}
 }
 int find(int pos){
 	int ans;
	int l = 1 , r = n+1;
	int m;
	while(l < r){
		m = (l+r)/2;
		if(rmq(m) >= pos){
			r = m;
		}else {
		 	l = m+1;
		}
	//	printf("%d %d\n",l , r); 
//		printf("BS\n");
	}
	return l;
 }
 void init(){
 	for(int i = 1 ; i <= n; ++i){
		update(i , 1);
	}
 }
 int main(){
	scanf("%d",&n);
	init();
	for(int i =n-1 ; i >= 0 ;--i){
		int X;
		scanf("%d",&X);
		int ans = rmq(X+1);
		A[i] = ans-1;
		update(X+1 , -1);
	}
	init();
	for(int i =n-1 ;  i >=0  ; --i){
		int X;
		scanf("%d",&X);
		int ans = rmq(X+1);
		B[i] = ans-1;
		update(X+1 , -1);	
	}
	for(int i =0 ; i < n ; ++i){
		int X = A[i] + B[i];
		C[i] = X%(i+1);
		A[i+1] += X/(i+1); 
	}
	init();
	for(int i =n-1; i >= 0  ;--i){
		int pos = find(C[i]+1);
		printf("%d ",pos-1);
		update(pos , -1);
	}
 }
