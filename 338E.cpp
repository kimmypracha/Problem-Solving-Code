#include <bits/stdc++.h>

  using namespace std;
 const int lim = 2e5+10;
 int a[lim] ,b[lim];
 int seg[4*lim]={};
 int lz[4*lim] = {};
  int n ,m , h;
 void build(int p = 1 , int l = 0 , int r = m-1){
 	if(l == r){
		seg[p] = -(l+1);			
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 , r);
		seg[p] = min(seg[p<<1] , seg[p<<1|1]);
	}
  }
  void update(int a , int b , int val , int p = 1 , int l = 0 , int r = m-1){
	if(a > b)return;
	if(lz[p] != 0){
		seg[p] += lz[p];
		if(l != r){
			lz[p<<1] += lz[p];
			lz[p<<1|1] += lz[p];
		}
		lz[p] = 0;
	}
	if(r < a or l > b)return;
	if(a <= l and r <= b){
		seg[p] += val;
		if(l != r){
			lz[p<<1] += val;
			lz[p<<1|1] += val;
		}
	}else{
		update(a, b,  val , p<<1 , l , (l+r)/2 );
		update(a, b, val , p<<1|1 , (l+r)/2 + 1 , r);
		seg[p] = min(seg[p<<1] , seg[p<<1|1]);
	}
  } 
  int idx[lim];
  int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i = 0 ; i < m ; ++i){
		scanf("%d",&b[i]);
	}
	for(int i =0 ;  i < n ; ++i){
		scanf("%d",&a[i]);
	}
	sort(b , b+m);
	build();
//	printf("$:%d\n",seg[1]);
	for(int i = 0 ; i < m ; ++i){
		int pos = lower_bound(b , b + m , h-a[i]) - b;
		idx[i] = pos;
		update(pos , m-1 , 1);
	}
//	printf("::%d %d %d\n",seg[1], seg[2]+lz[2] , seg[3]+lz[3]);
	int ans =0 ;
	if(seg[1] >= 0) ans++;
	int s = 0;
	for(int i = m ; i < n ; ++i){
		int pos = lower_bound(b , b+m , h-a[i]) - b;
		idx[i] = pos;
		update(pos , m-1 , 1);
		update(idx[s++] , m-1 , -1);
//		printf("$%d %d %d\n",seg[1], seg[2]+lz[2] ,seg[3]+lz[3]);
		if(seg[1] >= 0)ans++;
	}
	printf("%d",ans);
  }
