#include <bits/stdc++.h>
#define ls(x) (x&(-x))
  using namespace std;
  const int lim = 1e6+10;
  int n;
  int ft[lim] = {} , del[lim] = {};
  int mark[lim] = {};
  void update(int pos , int val){
  	for( ; pos <= n ; pos += ls(pos))ft[pos] += val;
  }
  void add(int pos){
	for(;pos <= n ; pos += ls(pos))del[pos] += 2;
  }
  int rmq(int pos){
  	int sum = 0;
	for(;pos;pos -= ls(pos)){
		sum += ft[pos];
	}
	return sum;
  }
  int gotdel(int pos){
  	int sum = 0;
	for(;pos;pos -= ls(pos))sum += del[pos];
	return sum;
  }
  void rem(int val){
  	int l = 1 ,r = n+1;
	int m;
	while(l < r){
//		printf("::%d %d %d\n",l,m,r);
		m = (l+r)/2;
		if(rmq(m) >= val){
			r = m;
		}else l = m+1;
	}
//	printf("::%d | %d %d %d\n",val, l,rmq(l),rmq(l-1));
	if(val - rmq(l-1) == 1 and mark[l] == 0){
		mark[l] = 1;
		add(l);
//		printf("DEL %d\n",l);
	}
	update(l,-1);
  }
  void putg(int val){
  	int l = 1 , r = n + 1;
	int m;
	while(l < r){
		m = (l+r)/2;
		if(rmq(m) >= val){
			r = m;
		}else{
			l = m+1;
		}
	}
	update(l , 1);
  }
  int main(){
  	int m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++i){
		update(i , 1);
	}
	for(int i = 1 ; i <= m ; ++i){
		char c;
		int a , b;
		scanf(" %c",&c);
		scanf("%d",&a);
		if(c == 'i'){
			scanf("%d",&b);
			printf("%d\n",rmq(b-1) - rmq(a-1)-(b-a) + gotdel(b) - gotdel(a-1));
		}else if(c == 'd'){
			rem(a+1);
		}else{
			putg(a+1);	
		}	
	} 
  }
