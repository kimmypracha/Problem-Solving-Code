#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
  const int mxn = 3e4 + 10;
  const int mxk = 1e3 + 10;
  int dp[mxn][mxk]; 
  int arr[mxn];
  vector<int> seg[4*mxn];
  int n,  k ;
  void build(int p = 1 , int l = 0 , int r = n-1){
  	if(l == r){
		seg[p].eb(arr[l]);
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2+ 1,  r);
		auto& left = seg[p<<1];
		auto& right = seg[p<<1|1];
		auto& now = seg[p];
		int i = 0 , j = 0 ;
		while(i < left.size() and j < right.size()){
			if(left[i] < right[j]) now.eb(left[i++]);
			else now.eb(right[j++]);
		}
		while(i < left.size())now.eb(left[i++]);
		while(j < right.size())now.eb(right[j++]);
	}	
  }
  bool rsq(int a , int b , int x , int p = 1 , int l = 0 , int r = n-1 ){
	if(r < a or l > b) return false;
	if(a <= l and r <= b){
		return binary_search(seg[p].begin() , seg[p].end() , x);
	}else{
		bool p1 = rsq(a , b , x , p<<1 , l , (l+r)/2 );
		bool p2 = rsq(a , b , x , p<<1|1 , (l+r)/2 + 1 , r );
		return (p1 or p2);
	}  	
  }
 int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i  < n;  ++i){
		scanf("%d",&arr[i]);
	}
	build();
	for
 }
