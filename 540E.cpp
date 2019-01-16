#include <bits/stdc++.h>
#define eb emplace_back
#define ls(x) (x&(-x))
#define all(x) x.begin() , x.end() 
#define fi first
#define se second 
using namespace std;
 typedef long long int lli;
 typedef pair<int,int> pii;
 const int lim = 2e5+10;
 lli ft[lim] = {};
 vector<int> vi;
 vector<pii> que; 
 int pos[lim];
 int n,m;
 lli arr[lim] = {};
 lli rsq(int now){
 	lli sum = 0;
	for( ; now ; now -= ls(now)){
		sum += ft[now];
	}
	return sum;
  }
 void update(int now , int val){
	for(; now <= n ; now += ls(now)){	
		ft[now] += val;
	}		
 }
int main(){
	scanf("%d",&m);
	for(int i = 0 ; i < m; ++i){
		int x , y;
		scanf("%d%d",&x,&y);	
		que.eb(x,y);
		vi.eb(x);
		vi.eb(y);
	}
	sort(all(vi));
	vi.resize(unique(all(vi)) - vi.begin());
	n = (int)vi.size();
	for(int i =0 ;i < n ;i++){
		pos[i] = i+1;
		if(i == n-1){
			arr[i] = 0;		
		}else{
			arr[i] = vi[i+1] - vi[i]-1;
		}
	}
	for(int i = 0 ; i < m ; ++i){
		int p1 = lower_bound(all(vi) , que[i].fi) - vi.begin() ;
		int p2 = lower_bound(all(vi) , que[i].se) - vi.begin() ;
		swap(pos[p1] , pos[p2]);
	}
	lli ans = 0;
	for(int i = n-1 ; i>= 0; i--){
		ans += (arr[i])*(rsq(i+1));
		update(i+1 , arr[i]);
		ans += rsq(pos[i]-1);
		update(pos[i] , 1);
	} 
	printf("%lld",ans);
 }
