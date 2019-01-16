#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef long long int lli;
 typedef pair<lli ,lli> pii;
 vector<pii> vi;
 lli ans;
 set<pii> st;
 void update(int i, int p){
			auto it = st.lower_bound(vi[i]);
			if(it == st.begin()){
				ans += (abs(it->fi - vi[i].fi) + abs(it->se - vi[i].se))*p;	
			}else if(it  == st.end()){
				--it;
				ans += (abs(it->fi - vi[i].fi) + abs(it->se - vi[i].se))*p;
			}else{
				auto pit = it;
				--it;
				swap(pit,it);
			//	printf("ENTER (%d %d) (%d %d)\n",pit->fi ,pit->se ,it->fi , it->se);
				ans -= (abs(it->fi - pit->fi) + abs(it->se - pit->se))*p;
				ans += (abs(it->fi -vi[i].fi ) + abs(it->se - vi[i].se))*p;
				ans += (abs(pit->fi - vi[i].fi) + abs(pit->se - vi[i].se))*p;
			}
 } 
 int main(){
 	int n , k;
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < n;  ++i){
		lli a , b;
		scanf("%lld%lld",&a,&b);
		vi.eb(a,b);
	}
	sort(vi.begin() ,vi.end() , [](const pii &a , const pii &b)->bool{return a.se < b.se;});
	lli fin;
	ans = 0;
//	for(int i = 0 ; i < vi.size() ; ++i){
	//	printf("::%d %d \n" , vi[i].fi , vi[i].se);
//	}
	
	for(int i = 0 ; i < k ; ++i){
		if(i){
		update(i,1);
		}
		st.insert(vi[i]);
	//	printf("||||::%d\n",ans);

	}
//	printf("||%d\n",ans);
	fin = ans;
	for(int i = k ; i < n ; ++i){
		st.erase(vi[i-k]);
		update(i-k,-1);
		update(i,1);
		st.insert(vi[i]);
		fin = min(fin , ans);
	}
	printf("%lld",fin);
 }
