#include <bits/stdc++.h>
#define fi first 
#define se second
#define eb emplace_back
 using namespace std;
  const int lim = 1e6 + 10; 
typedef pair<int,int> pii; 
  int arr[lim];
  bool cal[lim] = {};
 vector<pii> vi;
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i =0  ; i  < n;  ++i){
		scanf("%d",&arr[i]);
		vi.eb(arr[i], -i);
	} 
	sort(vi.begin() , vi.end() );
	int now = 0;
	double ans = 0 ;
	for(int i =0 ; i  <n ; ++i){
		int pos = -vi[i].se;
		if(cal[pos])continue;
		int Max = arr[now] , Min = arr[now];
		for(;now <= pos ; ++now){
			Min = min(Min, arr[now]);
			Max = max(Max , arr[now]);
			cal[now] = true;
		}
		ans = max(ans , max((double)Max - (Min+Max)/2.00 , (Min+Max)/2.00 - (double)Min));
		// find min max avg ------
	}
	printf("%.6lf",ans);
  }
