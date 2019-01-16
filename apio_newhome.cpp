#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin(),x.end()
 using namespace std;
  typedef pair<int,int> pii;
  typedef tuple<int,int,int> tri;
  const int lim = 3e5+10;
  int typ[lim];
  int pos[lim];
  int hsh[lim];
  vector<tri> ord;
  vector<int> idx;
  vector<int> ycp; // year compressed
  unordered_map<int,int> ver;
  bool Comp(const tri& a ,const tri& b){
	int a2,b2;
	tie(ignore,a2,ignore) = a;
	tie(ignore,b2,ignore) = b;
	return 	a2 < b2;
  }
  int main(){
  	int n ,k , q;
	scanf("%d%d%d",&n,&k,&q);
	for(int i = 1;  i <= n ; ++i){
		int l , r;
		scanf("%d%d%d%d",&pos[i],&typ[i],&l,&r);
		ord.eb(i,l,1);
		ord.eb(i,r,-1);
		idx.eb(pos[i]);		
	}
	sort(ord.begin() , ord.end() , Comp);
	sort(idx.begin() , idx.end());
	idx.resize(unique(idx) - idx.begin());
	for(int i = 1 ; i <=n ; ++i){
		int x = lower_bound(idx.begin(),idx.end(),pos[i]) - idx.begin();
		hsh[i] = x;
	//	hsh[idx[i]] = i; // Warning!! Becareful in case query not have that position; hsh[x]=0
	}
	// Compress Index Completed
	int pst = 1; // tell version number
	for(auto x : ord){
		int _idx,_year,_st;
		tie(_idx,_year,_st) = x;
		if(ver.find(year) != ver.end()){
			// Update in lastest version
		}else{
			ycp.eb(_year);
			// Update new version
		} 
	}
	sort(ycp.begin(),ycp.end());
	// Start to query
	for(int i = 1 ; i <= q ; ++i){
		int x , y;
		scanf("%d%d",&x,&y);
		// include version 0 (default by implicit) so should upper_bound
		int _v = upper_bound(ycp.begin(),ycp.end(),y) - ycp.begin();
		printf("%d\n",solve(x,_v)); // solve undone
	}
  }
