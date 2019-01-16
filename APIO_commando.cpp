#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  typedef long long int lli;
  typedef pair<lli,lli> pii;
  const int lim = 1e6+10;
  lli arr[lim] = {};
  lli dp[lim]; 
  vector<pii> le;
  int idx = 0;
  bool cross(pii a = le[le.size()-3] , pii b = le[le.size()-2] , pii c = le[le.size()-1]){
  	return (a.se - c.se)*(b.fi - a.fi) <= (a.se - b.se)*(c.fi - a.fi);
  }
  void add(lli m , lli b){
  	le.eb(m,b);
	while(le.size() >= 3 and cross()){
		swap(le[le.size()-1] , le[le.size()-2]);
		le.pop_back();
	}
  }
  lli query(lli x){
   	if(idx >= (int)le.size())idx = (int)le.size()-1;
	while(idx < (int)le.size()-1 and le[idx].fi*x +le[idx].se < le[idx+1].fi*x + le[idx+1].se )
		idx++;
	return le[idx].fi*x + le[idx].se;
  }
  int main(){
   	int n;
	scanf("%d",&n);
	lli a  ,b , c;
	scanf("%lld%lld%lld",&a,&b,&c);
	for(int i = 1; i <= n ;++i){
		scanf("%lld",&arr[i]);
		arr[i] += arr[i-1];	
	}
	add(0,0);
	for(int i = 1 ; i <= n;  ++i){
			dp[i] = a*arr[i]*arr[i] + b*arr[i] + c + query(arr[i]);	
	//	printf("dp %d : %d\n",i,dp[i]);
	//	printf("%d , %d\n",-2*a*arr[i], a*arr[i]*arr[i] - b*arr[i] + dp[i]);
		add(-2*a*arr[i],a*(arr[i]*arr[i]) - b*arr[i] + dp[i]);
	}
	printf("%lld",dp[n]);
 }
