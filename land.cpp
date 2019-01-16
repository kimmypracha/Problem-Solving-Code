#include <bits/stdc++.h>
#define ls(x) (x&(-x))
 using namespace std;
  const int lim = 2e5+10;
  int ft[lim] = {};
  int n;
  void update(int pos , int val){
  	for( ; pos <= n; pos += ls(pos)){
		ft[pos] += val;
	} 
  }
  int rmq(int pos){
  	int sum =  0;
	for(; pos ; pos -= ls(pos)){
		sum += ft[pos];	
	}
	return sum;
  }
  int main(){
   	int  m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++i){
		int A;
		scanf("%d",&A);
		if(A==1){
			int a , b , v;
			scanf("%d%d%d",&a,&b,&v);
			update(a,v);update(b+1,-v);
		}else{
			int x;
			scanf("%d",&x);
			printf("%d\n",rmq(x));
		}
	}
  }
