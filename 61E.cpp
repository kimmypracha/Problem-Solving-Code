#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 typedef long long int lli;
 const int lim = 1e6+10;
 typedef vector<int> Vec;
 vector<int> seg[4*lim];
 int arr[lim];
 int n;
 void build(int p = 1 , int l = 0 , int r = n-1){
  	if(l == r){
		seg[p].eb(arr[l]);
	}
	else {
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 , r);
		Vec& A = seg[p<<1];
		Vec& B = seg[p<<1|1];
		Vec& C = seg[p];
		int i= 0 , j = 0;
		while(i < A.size() and j < B.size())C.eb((A[i] < B[j])? A[i++] : B[j++]);
		while(i < A.size())C.eb(A[i++]);
		while(j < B.size())C.eb(B[j++]);
	}
 }
 int cnt(int a , int b ,int m ,  int p = 1 , int l = 0 , int r = n-1){
	if(r < a or l > b)return 0;
	if(a <= l and r <= b){
		int x;
		if(m == 1)
			 x = lower_bound(seg[p].begin() , seg[p].end() , arr[a-1]) - seg[p].begin();
		else 
			 x = (int)seg[p].size() - (upper_bound(seg[p].begin() , seg[p].end() , arr[b+1]) - seg[p].begin());
		return x;
	}else{
		int p1 = cnt(a , b ,m , p<<1 , l , (l+r)/2 );
		int p2 = cnt(a , b ,m , p<<1|1 , (l+r)/2 + 1 , r);
		return p1 + p2;
	}
 }
 int main(){
	scanf("%d",&n);
	for(int i =0 ; i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	build();
	lli ans = 0;
	for(int i = 1; i < n-1 ; ++i){
		ans += ( (lli)cnt(0, i-1 , -1) )*( (lli)cnt(i+1 , n-1 , 1) );
	}
	printf("%lld",ans);
 }
