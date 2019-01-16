#include <bits/stdc++.h>
#define fi first
#define se second
 using namespace std;
  typedef pair<int,int> pii;
  const int lim = 1e5+10;
  pii seg[4*lim]  = {};
  int lz[4*lim] = {};
int n; 
 int arr[lim];
  void build(int p = 1 , int l = 0 , int r = n-1){
  	if(l == r){
		seg[p] = pii(arr[l],arr[l]);
	} else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 , r);
		seg[p].fi = min(seg[p<<1].fi , seg[p<<1|1].fi);
		seg[p].se = max(seg[p<<1].se , seg[p<<1|1].se);
		//printf("%d %d : %d %d\n",l , r , seg[p].fi , seg[p].se);
	}
  }
  void update(int a, int p =1 ,int l = 0 , int r = n-1){
	if(r < a or l > a)return ;
	if(l == r){
//		printf("||%d %d : %d\n",l,r,a);
		seg[p] = pii(arr[a],arr[a]);
	}else{
		update(a,p<<1 , l , (l+r)/2);
		update(a,p<<1|1 , (l+r)/2 + 1 , r);
		seg[p] = pii(min(seg[p<<1].fi ,seg[p<<1|1].fi) , max(seg[p<<1].se , seg[p<<1|1].se));
	}
//	printf("%d %d : %d %d\n",l,r,seg[p].fi , seg[p].se);
  }
  pii rmq(int a , int b , int p = 1 ,int l = 0 , int r = n-1){
	if(r <a or l > b)return pii(1e9,-1e9);
	if(a <= l and r <= b)return seg[p];
	else{
		pii p1 , p2;
		p1 = rmq(a,b,p<<1 , l , (l+r)/2);
		p2 = rmq(a,b,p<<1|1, (l+r)/2 + 1 , r);
		pii ans = pii(min(p1.fi , p2.fi) , max(p1.se , p2.se));
		return ans;
	}
  } 
  int main(){
  	int  m;
	scanf("%d%d",&n,&m);
	int nh = 0;
	for(int i = 0 ; i < n ; ++i){
		arr[i] =i;
	}
	build();
	for(int i = 0 ; i < m ; ++i){
		int q ,a , b;
		scanf("%d%d%d",&q,&a,&b);
		if(q == 0){
			swap(arr[a],arr[b]);
			update(a);
			update(b);
		}else if(q == 1){
			pii ch = rmq(a,b);
//			printf("::%d %d\n",ch.fi , ch.se);
			if(ch.fi == a and ch.se == b){
				printf("YES\n");
			}else printf("NO\n");
		}
	}
  }
