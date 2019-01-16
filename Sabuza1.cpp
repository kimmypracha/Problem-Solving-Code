#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 const int lim = 5e4 + 10;
 typedef long long int lli;
 typedef pair<lli,lli> pii;
 vector<pii> vi , nvi , lev;
 int pt = 0 ;
 bool cross(int t){
 	int a = t-1;
	int b = t-2;
	int c = t-3;
	return (lev[c].se-lev[a].se)*(lev[b].fi - lev[c].fi) < (lev[c].se - lev[b].se)*(lev[a].fi - lev[c].fi); 
 } 
 void add(lli m , lli c){
 	lev.eb(m,c);
	while(lev.size() >= 3 and cross((int)lev.size())){
		swap(lev[lev.size()-1] , lev[lev.size()-2]);
		lev.pop_back();
	}
 }
 lli query(lli x){
 	if(pt >= lev.size()){
		pt = (int)(lev.size())-1;
	}
	int N = (int)lev.size();
	while(pt < N-1 and lev[pt].fi*x + lev[pt].se > lev[pt+1].fi*x + lev[pt+1].se){
		pt++;
	}
	return lev[pt].fi*x + lev[pt].se;
 }
 int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		lli a , h , z;
		scanf("%lld%lld%lld",&a,&h,&z);
		vi.eb(a*h, z);
	}
	sort(vi.begin() , vi.end());
	for(int i =0 ; i < n ; ++i){
		while(not nvi.empty() and nvi.back().se <= vi[i].se)nvi.pop_back();
		nvi.eb(vi[i]);
	}
	pt = 0;
	add(nvi[0].se , 0);
 	lli val = 0;
	for(int i = 0 ; i < nvi.size() ; ++i ){
		val =  query(nvi[i].first);
		if(i < (int)nvi.size() - 1) add(nvi[i+1].se , val);
	}
	printf("%lld", val);
 }
