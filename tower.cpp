#include <bits/stdc++.h>
 
 using namespace  std;
 typedef struct node{
 	int mx , cnt , l , r;
 };
 const int lim = 2e5 + 10;
 int n;
 node seg[4*lim];
 int lz[4*lim] = {}; 
void build(int p = 1 ,  int l = 1 ,  int r= n ){
 	if(l == r){
		seg[p] = {0 , 1 , 0 , 0};
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2+1 , r);
		seg[p] = {0, 1 , 0 , 0};
	}
 }
 void update(int a , int b ,int x , int p = 1 , int l = 1 , int r = n){
	if(lz[p] != 0){
		if(l != r){
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];	
		}
		seg[p].mx += lz[p];
		seg[p].l += lz[p];
		seg[p].r += lz[p];
		lz[p] = 0; 
	}
	if(r < a or b < l)return ;
	if(a <= l and r <= b){
		seg[p].mx += x;
		seg[p].l += x;
		seg[p].r += x;
		if(l != r){
			lz[p<<1]  += x;
			lz[p<<1|1] += x; 
		}
	}else{
		update(a ,b , x , p<<1 , l , (l+r)/2);
		update(a,b,x , p<<1|1 , (l+r)/2 + 1 ,r);
		seg[p].mx  = max(seg[p<<1].mx , seg[p<<1|1].mx);
		if(seg[p<<1].mx == seg[p<<1|1].mx){
			seg[p].cnt = seg[p<<1].cnt + seg[p<<1|1].cnt;
			seg[p].cnt += (seg[p<<1].r != seg[p<<1|1].l)? 0 :(seg[p<<1].r == seg[p].mx)? -1 : 0;
		}else{
			seg[p].cnt = (seg[p<<1].mx == seg[p].mx)? seg[p<<1].cnt : seg[p<<1|1].cnt;
		}
		seg[p].l = seg[p<<1].l;
		seg[p].r = seg[p<<1|1].r; 
	}
 }
 int main(){
 	int m;
	scanf("%d%d",&n,&m);
	build();
	for(int i = 1 ; i <= m ; ++i){
		int a , b , x;
		scanf("%d%d%d",&a,&b,&x);
		update(a,b,x);
		printf("%d %d\n",seg[1].mx , seg[1].cnt);
//		printf(":: %d %d %d %d \n",seg[3].mx , seg[3].cnt , seg[3].l , seg[3].r);
	}

 }
