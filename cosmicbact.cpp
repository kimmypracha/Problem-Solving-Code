#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
  typedef pair<int,int> pii;
  vector<pii> vi;
  const int lim = 1e6+10;
  int cnt[lim] = {};
 int main(){
 	int n , L;
	scanf("%d%d",&n,&L);
	for(int i = 1 ; i <= n;  ++i){
		int x , y;
		scanf("%d%d",&x,&y);
		vi.eb(x,y);
	}
	for(int i = 0 ; i <= L ; ++i){
		int idx = 0;
		int mn = abs(vi[0].fi-i) + vi[0].se;
		
		for(int j = 1 ; j < n ; ++j){
			if(abs(vi[j].fi-i)+vi[j].se+j < mn){
				mn = abs(vi[j].fi-i) + vi[j].se+j;
				idx = j;
			}
		}
		cnt[idx]++;
	}
	for(int i = 0 ; i < n ;++i){
		printf("%d\n",cnt[i]);
	}
 }
