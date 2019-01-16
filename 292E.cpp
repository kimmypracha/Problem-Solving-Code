#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 const int lim = 1e5+10;
 typedef pair<int,int> pii;
 int arr[lim] , brr[lim];
 int seg[4*lim] = {};
 int n , m , q;
 vector<pii> vp;
 void update(int idx, int p = 1 , int l= 0 , int r = n-1 ){
 	int y = vp[idx-1].se-1;
//	printf("%d %d\n",l , r);

	if(y+q <= l or y > r  )return;
	if(y <= l and r <= y+q-1){
			seg[p] = idx;
			return; 
	}else{
		if(seg[p] > 0 ){
			seg[p<<1] = seg[p];
			seg[p<<1|1] = seg[p];
			seg[p] = 0;
		}
		update(idx , p<<1 , l , (l+r)/2);
		update(idx,  p<<1|1 , (l+r)/2 + 1 , r);
	}
 }
 int rmq(int pos , int p = 1 , int l = 0 , int r = n-1){
 	if(seg[p] > 0)return seg[p];
	if(l == r) return seg[p];
	int m = (l+r)/2;
	if(pos <= m)return rmq(pos , p<<1 , l , (l+r)/2);
	return rmq(pos,  p<<1|1 ,(l+r)/2 + 1 , r);
 }
 int main(){
	scanf("%d%d",&n,&m);
	
	for(int i =0 ;  i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&brr[i]);
	}
	
	for(int i = 0 ;  i < m ; ++i){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int x , y ;
			scanf("%d%d%d",&x,&y,&q);
			vp.eb(x,y);
			update(vp.size());
		}else{
			int x;
			scanf("%d",&x);
			int ans = rmq(x-1);
			if(ans == 0)printf("%d\n",brr[x-1]);
			else printf("%d\n",arr[vp[ans-1].fi + (x-vp[ans-1].se)-1]);
		}
	}
 }
