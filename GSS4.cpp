#include <bits/stdc++.h>
#define ls(x) (x&(-x))
 using namespace std;
 typedef long long int lli;
 const int lim = 1e5+10;
   int par[lim];
   lli arr[lim];
   lli ft[lim];
   int n;
   inline lli query(int x){
   	lli sum = 0 ;
	for(; x ; x -= ls(x)){
		sum += ft[x];
	}
	return sum;  
   }
   inline void update(int x , lli val){
	for(; x <= n ; x += ls(x)){
		ft[x] += val;	
	}
   }
   int travel(int l , int r){
	if(l > r) return l;
	lli x = sqrt(arr[l]);
	update(l,x-arr[l]);
	arr[l] = x;
	int nxt = travel(par[l],r);
	par[l] = nxt;
	if(arr[l] == 1) return nxt;
	else return l;
		
   }
  void rs(){
 	for(int i = 1 ; i <= n ; ++i){
		ft[i] = 0;
	} 
  }
   int main(){
  	int m;
	int idx = 1;
	while(scanf("%d",&n) != EOF){
		printf("Case #%d:\n",idx);
		for(int i = 1 ; i <= n ; ++i){
			scanf("%lld",&arr[i]);
			update(i,arr[i]);
			par[i] = i+1;
		}
		scanf("%d",&m);
		for(int i = 1 ; i <= m; ++i){
			int op , x ,y;
			scanf("%d%d%d",&op,&x,&y);
			if(x > y) swap(x,y);
			if(op == 1){
				printf("%lld\n",query(y) - query(x-1));
			}else{
				travel(x,y);
			}
		}
		rs();	
		idx++;
		printf("\n");
	}
   }
