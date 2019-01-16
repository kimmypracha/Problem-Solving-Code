#include <bits/stdc++.h>
#define eb emplace_back
#define all(x) x.begin() , x.end()
  using namespace std;
  const int lim = 1e5+10;
  vector<char> seg[4*lim];
  int n , q;
  int lz[4*lim] = {};
  string S;
  void build(int p = 1 , int l = 0 , int r = n-1){
  	if(l == r){
		seg[p].eb(S[l]);
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 ,r);
		merge(all(seg[p<<1]),all(seg[p<<1|1]), seg[p].begin());
	}
  }
  void update(int a , int b ,int p = 1 , int l = 0 , int r = n-1){
  	if(lz[p] != 0){
		reverse(all(seg[p]));
		if(l != r){
			seg[p<<1] ^= 1;
			seg[p<<1|1] ^= 1;	
		}
	}
	if(r < a or l > b)return;
	if(a <= l and r <= b){
		reverse(all(seg[p]));
		if(l != r){
			seg[p<<1] ^= 1;
			seg[p<<1|1] ^= 1;
		}
	}else{
		update(a , b , p<<1 , l , (l+r)/2);
		update(a , b , p<<1|1 , (l+r)/2 + 1 , r);
		reverse(seg[p].begin() + (a-l) , seg[p].begin() + (b-l)+1);
	}
  }
  int main(){
	scanf("%d%d",&n,&q);
	cin >> S;
	build();
	for(int i = 0 ; i< q ; ++i){
		
	}
  }
