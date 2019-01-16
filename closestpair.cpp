#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin() , x.end()
 using namespace std;
 typedef long long int lli;
 typedef pair<lli,lli> pii;
 const int lim = 1e5+10;
 vector<pii> poi;
 lli dist(pii a , pii b){
 	return (a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se - b.se);
 }
 lli dq(int l , int r){
	if(r-l+1 <= 3){
		if(l == r)return 1e9;
		lli ans = dist(poi[l] , poi[l+1]);
		for(int i = l; i <=r  ; ++i){
			for(int j = i +1 ; j <= r  ; ++j){
				ans = min(ans, dist(poi[i], poi[j]));
			}
		}
		return ans;
	}
 	int m = (l+r)/2;
	lli dl = dq(l ,m);
	lli dr = dq(m+1 , r);
	lli d = min(dl,dr);
	vector<pii> vi;
	for(int i = l; i <= r ; ++i){
		if(poi[i].fi - poi[m].fi < d)vi.eb(poi[i]);
	}
	sort(all(vi) , [=](const pii &a , const pii &b) -> bool{return (a.se == b.se)? a.fi < b.fi : a.se < b.se;} );
	lli ans =d;
	for(int i = 0 ; i < vi.size() ; ++i){
		for(int j = i+1; j < vi.size() and vi[i].se - vi[j].se < ans ; ++j){
			ans = min(ans , dist(vi[i] , vi[j]));	
		}
	}
	return ans;
 }
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		lli a , b;
		scanf("%lld%lld",&a,&b);
		poi.eb(a,b);
	}  
	sort(all(poi));
	printf("%lld",dq(1 , n));
 }
