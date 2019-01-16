#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin() , x.end()
#define ls(x) (x&(-x))
 using namespace std;
  typedef pair<int,int> pii;
  const int lim = 3e4+10;
  vector<int> vi;
  vector<pii> ans;
  unordered_map<int,int> mpi;
  int arr[lim];
  int ft[lim] = {};
  int m;
  int rmq(int x){
  	int sum =0 ;
	for(; x ; x-=ls(x)){
  		sum += ft[x];
	}
	return sum;
  }
  void update(int x , int v){
  	for( ; x <= m ; x += ls(x)){
		ft[x] += v;
	} 
 }
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 0;  i < n ; ++i){
		scanf("%d",&arr[i]);
		vi.eb(arr[i]);
	}
	sort(all(vi));
	vi.resize(unique(all(vi)) - vi.begin());
	for(int i = 0;  i < vi.size() ; ++i){
		mpi[vi[i]] = i+1;
	}
	m = (int)vi.size();
	update(mpi[arr[n-1]] , 1);
	for(int i = n-2 ; i >= 0 ; --i){
		int k = rmq(mpi[arr[i]]-1);
		if( k != 0)
		ans.eb(i+1 , k);
		update(mpi[arr[i]] , 1);
	}
	printf("%d\n",(int)ans.size());
	for(pii x : ans){
		printf("%d %d %d\n",x.fi , x.fi , x.se);
	}
  }
