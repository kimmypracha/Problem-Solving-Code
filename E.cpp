#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
  const int lim = 2e5+10; 
  int arr[lim] , brr[lim];
  vector<int> keep[4*lim] = {};
  void build(int p = 1 , int l = 1 , int r = n){
	if(l == r){
		keep[p].eb(brr[l]);	
		if(arr[l] == brr[l])cnt[p] = 1;
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 , r);
		for(int x : keep[p<<1]){
			keep[p].eb(x);
		}
		for(int x : keep[p<<1|1]){
			keep[p].eb(x);
		}
		sort(keep[p].begin(),keep[p].end());	
	}	
  } 
  vector<int> trf;
  int main(){
  	int n , m;
	scanf("%d%d",&n,&m);
	arr[0] = 0;
	for(int i = 1;  i <= n ; ++i)scanf("%d",&arr[i]);
	for(int i = 1;  i <= n ; ++i)scanf("%d",&brr[i]);
	copy(arr  , arr + 1 + n ,trf.begin());
	sort(trf.begin(),trf.end());
	for(int i = 1; i  <= n; ++i){
		int idx = find(arr+1 , arr+1+n , brr[i]) - arr;
		brr[i] = idx;
	}
	build();
	for(int i = 1;  i <= m ; ++i){
		int op;
		scanf("%d",&op);
		if(op == 1){
			int la , ra , lb, rb;
			scanf("%d%d%d%d",&la,&ra,&lb,&rb);
			printf("%d\n",rmq(la,ra,lb,rb));
		}else{
			int x , y;
			scanf("%d%d",&x,&y);
			update(x,)
		}
	}
  }
