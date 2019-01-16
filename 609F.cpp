#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define ls(x) (x&(-x))
  using namespace std;
  const int lim = 2e5 + 10;
  typedef pair<int,int> pii;
  vector<pii> frog;
  vector<int> mos, sz;
  int n , m;
  int ft[lim] = {};
  
 int main(){
	scanf("%d%d",&n,&m);
	for(int i =0 ;  i < n ;++i){
		int x ,t;
		scanf("%d%d",&x,&t);
		frog.eb(x,t);
	}
	mos.eb(-1);
	pow.eb(0);
	for(int i = 1 ; i <=  m ; ++i){
		int p , b;
		scanf("%d%d",&p,&b);
		mos.eb(p);
		pow.eb(b);
	}
	
 }
