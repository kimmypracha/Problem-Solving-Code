#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 const int lim = 1e5+10;
 int arr[lim] = {};
 vector<int> vi;
 int main(){
 	int n , k;
	scanf("%d%d",&n,&k);
	for(int i =0 ;  i < n ; ++i){
		int x , y;
		scanf("%d%d",&x,&y);
		arr[n+1-y] = x;
	}
	for(int i = 1 ; i <= n;  ++i){
		int idx = upper_bound(vi.begin() , vi.end() , arr[i]) - vi.begin();
		if(idx == (int)vi.size())vi.eb(arr[i]);
		else vi[idx] = arr[i];
	}
	printf("%d",(int)vi.size());
 }
