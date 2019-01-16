#include <bits/stdc++.h>
#define fi first
#define se second
  using namespace std;
  typedef pair<int,int> pii;
  const int lim = 1<<20;
  pii seg[4*lim] = {};
  int n,k;
  void push(int p , int l  , int r){
	if(l == r){
		seg[p].se = 1;
		return;
	}
  	if(seg[p].fi and seg[p<<1].fi and seg[p<<1|1].fi == 0){
		seg[p<<1|1].fi = 1;	
		push(p<<1|1 ,(l+r)/2 + 1, r);	
	}
	if(seg[p].fi and seg[p<<1|1].fi and seg[p<<1].fi == 0){
		seg[p<<1].fi = 1;
		push(p<<1 , l, (l+r)/2);
	}
	if(seg[p<<1].se and seg[p<<1].se)seg[p].se = 1;
  }
  void update(int a , int b , int p = 1 , int l = 0 , int r = n-1){
        if(b < l or a > r)return;
	if(a <= l and r <= b){
		seg[p].fi = 1;
		if(l == r) seg[p].se = 1;
		else if(seg[p].fi and seg[p<<1].fi and seg[p<<1|1].fi ==0){
			seg[p<<1|1].fi = 1;
			push(p<<1|1 , (l+r)/2 + 1 ,r);
		}else if(seg[p].fi and seg[p<<1|1].fi and seg[p<<1].fi == 0){
			seg[p<<1].fi = 1;
			push(p<<1 , l , (l+r)/2);
		}
		if(seg[p<<1].se and seg[p<<1|1].se) seg[p].se = 1;
	}else{
		update(a,b,p<<1 , l , (l+r)/2);	
		update(a,b,p<<1|1, (l+r)/2+ 1 , r);
		if(seg[p].fi == 1 and seg[p<<1].fi == 1 and seg[p<<1|1].fi ==0){
			seg[p<<1|1].fi = 1;
			push(p<<1|1 , (l+r)/2 + 1, r);
		}
		if(seg[p].fi and seg[p<<1|1].fi and seg[p<<1].fi == 0){
			seg[p<<1].fi = 1;
			push(p<<1 , l , (l+r)/2);
		}
		if(seg[p<<1].se and seg[p<<1|1].se) seg[p].se = 1;
		if(seg[p<<1].fi and seg[p<<1|1].fi) seg[p].fi = 1;
	}	
  }
  int main(){
  	int  m ;
	scanf("%d%d",&k,&m);
	n = (1<<k);
	bool pau = false;
	for(int i = 0 ; i < m ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		if(!pau){
			update(b , b + (1<<a)-1);
			if(seg[1].se == 1){
				pau = true;
				printf("%d",i+1);
			}
		}
	//	printf("(%d,%d) (%d,%d) (%d,%d)\n",seg[1].fi ,seg[1].se , seg[2].fi , seg[2].se , seg[3].fi ,seg[3].se);
		for(int i = 1 ; i <= 7 ; ++i){
			printf("%d : %d %d\n",i,seg[i].fi,seg[i].se);
		}
	}
  }
