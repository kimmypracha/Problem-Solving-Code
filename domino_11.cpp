#include <bits/stdc++.h>
#define fi first
#define se second 
#define eb emplace_back
#define all(x) x.begin() , x.end()
  using namespace std;
  const int lim = 1e5 + 10;
  typedef pair<char ,int > pci;
  typedef pair<int,int> pii;
  vector<pci> vi;
  vector<int> idx;
  pii segv[4*lim] , segh[4*lim];
  pii lzv[4*lim] , lzh[4*lim];
  int main(){
  	int n , m ;
	scanf("%d%d",&n,&m);
	for(int i =0 ; i <  m; ++i)
	{
		char op ;
		int pos;
		scanf(" %c%d",&op,&pos);
		idx.eb(pos);
		vi.eb(op,pos);
	}
	sort(all(idx));
	auto it = unique(all(idx));
	idx.resize(it - idx.begin());
	fill(segv , segv + 4*idx.size() , make_pair(1 ,N ));
	fill(segh , segh + 4*idx.size() , make_pair(1 ,N ));
	fill(lzv , lzv + 4*idx.size() , make_pair(-1 ,-1 ));	
	fill(lzh , lzh + 4*idx.size() , make_pair(-1 ,-1 ));
	for(int i =0 ; i < m ; ++i){
		if(vi[i].fi == 'N'){
			
		}else if(vi[i].fi == 'S'){
		
		}else if(vi[i].fi == 'E'){
		
		}else if(vi[i].fi == 'W'){
			
		}
	}
 }
