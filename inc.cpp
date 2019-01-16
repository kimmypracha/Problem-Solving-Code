#include <bits/stdc++.h>
 #define eb emplace_back
using namespace std;
  const int lim = 1e5+10;
  int arr[lim] = {};
  vector<int> lis;
  int main(){
  	int n;
	scanf("%d",&n); 
	for(int i =0 ;  i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	for(int i = 0 ; i  < n ;++i){
		if(lis.empty())lis.eb(arr[i]);
		else if(lis.back() < arr[i])lis.eb(arr[i]);
		else {
			int pos = lower_bound(lis.begin() , lis.end() , arr[i]) - lis.begin();
			lis[pos] = arr[i];
		}
	}
	printf("%d",(int)lis.size());
 }
