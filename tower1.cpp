#include <bits/stdc++.h>
 
 using namespace std;
  struct node{
  	int mx,  l , r, cnt;
  	node(): mx(0) , l(0) , r(0) , cnt(1) {};
	node(int a , int b ,int c , int d):mx(a),l(b),r(c) , cnt(d){}; 
  };
  const int lim = 2e5+10;
  node seg[4*lim] = {};
  int lz[4*lim] = {};
  int n;
  void build(int p = 1  , int l =1  ,int r = n){
 	if(l == r){
		seg[p] = node(0,0,0,1);
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 , r);
		seg[p] = node(0,0,0,1);
	}	
  }
  void update(int a , int b , int x , int p = 1 , int l = 1 , int r = n ){
	if(lz[p] != 0){
		seg[p].mx += lz[p];
		seg[p].l += lz[p];
		seg[p].r += lz[p];
		if(l != r){
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];
		}
		lz[p ] = 0;	
	}
	if(r < a or l > b)return;
	if(a <= l and r <= b){
		seg[p].mx += x;
		seg[p].l += x;
		seg[p].r += x;
		if(l != r){
			lz[p<<1] += x;
			lz[p<<1|1] +=x;
		}
	}else{
		update(a ,b , x , p<<1 , l , (l+r)/2);
		update(a,b,x , p<<1|1 , (l+r)/2+ 1, r);
		seg[p].mx = max(seg[p<<1].mx , seg[p<<1|1].mx);
		seg[p].l = seg[p<<1].l;
		seg[p].r = seg[p<<1|1].r;
		if(seg[p<<1].mx == seg[p<<1|1].mx){
			seg[p].cnt = seg[p<<1].cnt + seg[p<<1|1].cnt;
			if(seg[p<<1].r == seg[p<<1|1].l and seg[p<<1].r == seg[p].mx)seg[p].cnt -=1 ;
		}else if(seg[p].mx == seg[p<<1].mx) seg[p].cnt = seg[p<<1].cnt;
		else seg[p].cnt = seg[p<<1|1].cnt;
	}	
  }
  int main(){
  	int  m;
	scanf("%d%d",&n,&m);
	build();
	for(int i = 1 ; i <= m ; ++i){
		int a , b, x;
		scanf("%d%d%d",&a,&b,&x);
		update(a , b , x);
		printf("%d %d\n",seg[1].mx , seg[1].cnt);
	}
  }
