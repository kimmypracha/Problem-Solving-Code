#include <bits/stdc++.h>
#define ls(x) (x&(-x))
#define eb emplace_back
#define all(x) x.begin(),x.end()
  using namespace std;
  const int lim=  1e5+10;
  const int invalid = -999999;
  int arr[lim] = {};
  int dp[lim] = {};
  int m;
  int ft[lim] = {};
  int mx[lim] = {};
  unordered_map<int,int> hsh;
  vector<int> keep;
  void update(int now, int val){
	for(; now <= m ; now += ls(now)){	
		ft[now] = max(ft[now] , val);
	}	
  }
  int rmq(int now){
	int ans = invalid;
	for( ; now ; now -= ls(now)){
		ans = max(ans , ft[now]);
	}
	return ans;	
  }	
  int main(){
  	int n;
	scanf("%d",&n);
	keep.eb(0);
	for(int i = 1;  i <= n ; ++i){
		scanf("%d",&arr[i]);
		arr[i] += arr[i-1];
		keep.eb(arr[i]);	
	}
	sort(all(keep)) , keep.resize(unique(all(keep))-keep.begin());
	 m = keep.size();
	// i to i+1
	fill(ft+1 , ft + m + 1 , invalid);
	int pos = lower_bound(all(keep),0) - keep.begin();
	update(pos+1,0);
	for(int i = 1 ; i <= n ; ++i){
		int idx = lower_bound(all(keep),arr[i]) - keep.begin();
		if(idx == 0){
			dp[i] = invalid;
		}else{
			int pre = rmq(idx);
			if(pre == invalid) dp[i] = invalid;
			else dp[i] = pre + 1;	
			update(idx+1,dp[i]);
		}
	}
	printf("%d",dp[n]);
  }
