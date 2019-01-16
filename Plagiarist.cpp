#include <bits/stdc++.h>
#define ls(x) (x&(-x))
  using namespace std;
  const int lim  = 2e5  + 10;
  int Arr[lim];
  int ft[lim] = {};
  int N;
  void add(int x , int v){
   	for(; x <= N ; x+=ls(x) ){
		ft[x] += v;
	} 
 }
 int rsq(int x){ 
 	int sum = 0 ;
	for( ; x ; x-= ls(x)){
//		printf("\n rsq %d +%d\n", x , ft[x]);
 		sum += ft[x];
	}
	return sum;
 }
 int BS(int x){
  	int l = 1 , r = N+1, m ;
	while(l  <r ){
		m = (l + r)/2;
//		printf("%d %d\n" , m , rsq(m));
		if(rsq(m) >= x){
			r = m;
		}else{
			l = m+1;
		}
	} 
	return l;
  }
  int main() { 
	 scanf("%d",&N);
	for(int i=  1 ; i <= N ; ++i){
		scanf("%d",&Arr[i]);
		add(i , 1);
	}
//	for(int i= 1 ; i <= N ; ++i){
//		printf("%d ",ft[i]);
//	}
//	printf("\n");
	for(int i = 1 ; i <= N ; ++i){
		int idx;
		scanf("%d",&idx);
		int ind = BS(idx);
		printf("%d\n",Arr[ind]);
		add(ind , -1);
	}
  }
