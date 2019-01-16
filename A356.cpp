#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 3e5+10;
 int seg[4*lim];
 int los[lim] = {};
 int par[lim] = {};
 int n , m;
 int findhead(int now){
 	return (now == par[now]? now :  findhead(par[now]));
 }
 void build(int p = 1 , int l = 1 , int r = n){
  	if(l == r){
		seg[p] = l;
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2+ 1,  r);
		seg[p] = 0;
	}
 }
 void update(int a , int b ,int x, int p = 1 , int l = 1 , int r = n){
  	if(r< a or b < l)return;
	if(a <= l and r <= b and seg[p] != 0 ){
		if(a<=findhead(seg[p]) and findhead(seg[p]) <= b){
			los[findhead(seg[p])] = x;
			par[findhead(seg[p])] = x;
			seg[p] = x;
		}
	}else{
		if(seg[p] == 0){
			update(a , b , x , p<<1 , l , (l+r)/2);
			update(a , b , x , p<<1|1 , (l+r)/2 +1 , r);
			seg[p] = (seg[p<<1] == seg[p<<1|1])? seg[p<<1] : 0;
		}
		else if(a <= findhead(seg[p]) and findhead(seg[p]) <= b){
			los[findhead(seg[p])] = x;
			par[findhead(seg[p])] = x;
			seg[p] = x;
		}
	}
 }
 int main(){
	scanf("%d%d",&n,&m);
	build();
	for(int i = 1 ; i <= n ; ++i){
		par[i] = i;
	}
	for(int i = 1 ; i <= m ;++i){
		int l , r , x;
		scanf("%d%d%d",&l,&r,&x);
		update(l,r,x);
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d ", (par[i] == i)? 0 : par[i]);
	}
	printf("\n");
 }
