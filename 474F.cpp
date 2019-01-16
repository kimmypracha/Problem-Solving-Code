#include <bits/stdc++.h>
#define fi first
#define se second
  using namespace std;
  typedef struct pii{
  	int fi, se , th;
	pii(): fi(0) , se(0) , th(0) {};
	pii(int a , int b , int c): fi(a) , se(b) , th(c) {};
  };
  const int lim = 1e5+10;
  pii seg[2*lim];
  int n;
  int gcd(int a , int b){
  	return (!b)? a : gcd(b , a%b);
  }
  pii cmb(pii a , pii b){
 	pii ans;
	ans.fi = gcd(a.fi , b.fi);
	ans.se = min(a.se , b.se);
	if(a.se == ans.se)ans.th += a.th;
	if(b.se == ans.se)ans.th += b.th;
	return ans;
  }
  void build(){
  	for(int i = n-1 ; i >= 1 ; --i){
		seg[i] = cmb(seg[i<<1] , seg[i<<1|1]);
//		printf("%d : %d %d %d \n" , i , seg[i].fi , seg[i].se ,seg[i].th);
	}
//	for(int i =n ; i < n+n ; ++i){
//		printf("%d : %d %d %d\n", i , seg[i].fi , seg[i].se , seg[i].th);
//	}
  }
  pii rmq(int l , int r){
	pii ans = seg[l+n];
	l++;
	l+=n;
	r+=n;
//	printf("%d %d %d\n",ans.fi , ans.se , ans.th);	
	for( ; l < r ; l >>= 1 , r >>= 1){
		if(l&1)ans =  cmb(ans , seg[l++]);
		if(r&1)ans =  cmb(ans , seg[--r]);
//		printf("%d %d %d \n" , ans.fi , ans.se , ans.th);
	}
	return ans;
 }
 int main(){
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&seg[n+i].fi);
		seg[n+i].se = seg[n+i].fi;
		seg[n+i].th = 1;
	}
	build();
	int t;
	scanf("%d",&t);
	for(int i =0 ; i < t ; ++i){
		int l , r ;
		scanf("%d%d",&l,&r);
		int ran = r-l+1;
		l--;
		pii ans = rmq(l,r);
//		printf("%d %d %d\n",ans.fi , ans.se , ans.th);
		if(ans.fi%ans.se == 0 )printf("%d\n",ran - ans.th);
		else printf("%d\n",ran);
	}
 }
