#include <bits/stdc++.h>
#define ls(x) (x&(-x))
  using namespace std;
  typedef long long int lli;
  const int lim = 1030;
  lli ft[lim][lim] = {};
  int s;
  void update(int x , int y , int a){
  	for(;x <= s ; x += ls(x)){
		for( int j = y; j <= s ; j += ls(j)){
			ft[x][j] += (lli)a;
		}
	} 
  }
  lli rmq(int x , int y){
 	lli ans =0 ;
	if(x == 0 or y == 0)return 0; 
	for( ; x  ; x -= ls(x)){
		for(int j = y ; j ; j -= ls(j)){
			ans += ft[x][j]	;
		}
	}
	return ans;
  }
  lli rmq(int l , int r , int b , int t){
//	printf("%d %d : %d\n",r,t,rmq(r,t));
//	printf("%d %d : %d\n",r, b-1 , rmq(r,b-1));
//	printf("%d %d : %d\n",l-1 , t , rmq(l-1,t));
//	printf("%d %d : %d\n",l-1 , b-1, rmq(l-1,b-1));
	return rmq(r,t) - rmq(r, b-1) - rmq(l-1 , t) + rmq(l-1, b-1);	
  }
  int main() { 
	int x , y , a , l , r , b , t , cmd;  
 	while(true){
		scanf("%d",&cmd);
		switch(cmd){
			case 0 : scanf("%d",&s); break;
			case 1 : scanf("%d%d%d",&x,&y,&a); update(x+1, y+1 , a); break;
			case 2 : scanf("%d%d%d%d",&l,&b,&r,&t); printf("%lld\n",rmq(l+1,r+1,b+1,t+1));fflush(stdout);break;
			case 3 : break;
		}
		if(cmd == 3)break;
	}  	
  } 
