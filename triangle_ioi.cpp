#include <bits/stdc++.h>

  using namespace std;
 int arr[110][110]= {};
 int main(){
 	int n;
	scanf("%d",&n);
	int ans = 0 ;
	for(int i =1; i <= n ; ++i){
		for(int j = 1 ; j <= i ; ++j){
			scanf("%d",&arr[i][j]);
			arr[i][j] += max(arr[i-1][j-1] , arr[i-1][j]);
			ans = max(ans , arr[i][j]);
		}
	}
	printf("%d",ans);
 }
