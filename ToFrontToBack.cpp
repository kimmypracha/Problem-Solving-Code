#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  const int lim = 1e5+10;
  int pos[lim];
  int arr[lim];
  int dp[lim];
  int par[lim] = {};
  int mx = -1;
  vector<int> L , R;
  int main(){
  	int n;
	scanf("%d",&n); 
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&arr[i]);
		pos[arr[i]] = i;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(i == 1 or arr[i] == 1)dp[i] = 1;
		else if(i > pos[arr[i]-1]){
			dp[i] = dp[pos[arr[i]-1]] + 1;
			par[i] = pos[arr[i]-1];
		}else{
			dp[i] = 1;
		}
		if(mx == -1) mx = i;
		else if(dp[mx] < dp[i]) mx = i;	
	}
	int l , r = arr[mx];
	for(int i = mx ;i != 0 ; i = par[i]){
	//	printf("||%d\n",i);
		l = arr[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] < l)L.eb(arr[i]);
		else if(arr[i] > r)R.eb(arr[i]);
	}
	sort(L.begin(), L.end() , greater<int>());
	sort(R.begin(), R.end());
	printf("%d\n",int(L.size()) + int(R.size()));
	for(int i : L){
		printf("%d 0\n",i);
	}
	for(int i : R){
		printf("%d 1\n",i);
	}
  }
