#include <bits/stdc++.h>

  using namespace std;
   typedef long long int lli;
   struct node{
   	lli ml , mx , mr;
	node(): ml(0), mx(0),mr(0) {};
	node(lli a , lli b , lli c): ml(a),mx(b),mr(c) {};
   };
   const int lim = 1e5+10;
   const lli inf = 1e16+10;
   int n , m;
   lli d[2*lim]= {} , h[2*lim];
   node seg[8*lim];
   void build(int p = 1 , int l = 1  , int r = 2*n-1){
   	if(l == r){
		seg[p] = node(2*h[l] -d[l-1],0,2*h[l]+d[l-1]);
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2+1 , r);
		seg[p].ml = max(seg[p<<1].ml , seg[p<<1|1].ml);
		seg[p].mr = max(seg[p<<1].mr , seg[p<<1|1].mr);
		seg[p].mx = max(max(seg[p<<1].mx, seg[p<<1|1].mx) , seg[p<<1].ml + seg[p<<1|1].mr);
	}
   }
   node rmq(int a , int b , int p = 1 , int l = 1 , int r = 2*n-1){
   	if(l >b or a >r)return node(-inf,0,0);
	if(a <= l and r <= b){
	//	printf("%d %d : %d %d %d\n",l , r , seg[p].ml , seg[p].mx , seg[p].mr);
		return seg[p];
	}else{
		node p1 , p2;
		p1 = rmq(a , b,  p<<1 , l , (l+r)/2);
		p2 = rmq(a , b,  p<<1|1 , (l+r)/2+1 , r);
		if(p1.ml == -inf){
	//	printf("%d %d : %d %d %d\n",l , r , p2.ml , p2.mx , p2.mr);
			return p2;
		}else if(p2.ml == -inf){
	//	printf("%d %d : %d %d %d\n",l , r , p1.ml , p1.mx , p1.mr);
			return p1;
		}else{
			node ans;
			ans.ml = max(p1.ml , p2.ml);
			ans.mr = max(p1.mr , p2.mr);
			ans.mx = max(max(p1.mx,p2.mx) ,p1.ml + p2.mr);
		       // printf("%d %d : %d %d %d\n",l , r , ans.ml , ans.mx , ans.mr);
			return ans;
		}
	}
   }
   int main(){
	scanf("%d%d",&n,&m);
	for(int i =1 ;  i <= n ; ++i){
		scanf("%lld",&d[i]);
		d[i+n] = d[i];
	}
	for(int i = 1 ; i <= 2*n ; ++i){
		d[i] = d[i] + d[i-1];
	}
	for(int i = 1 ; i <= n; ++i){
		scanf("%lld",&h[i]);
		h[i+n] = h[i];
	}
	build();
	for(int i =0 ;  i < m ; ++i){	
		int a , b;
		node ans1 , ans2;
		scanf("%d%d",&a,&b);
		if(a <= b){
			ans1 = rmq(b+1 , n + a-1);
			printf("%lld\n",ans1.mx);
		}else if(a > b){
			ans1 = rmq(b+1,a-1);
			printf("%lld\n",ans1.mx);
		}	
	}
   }
