#include <bits/stdc++.h>
  using namespace std;
   const int lim = 1e5 + 10;
   int arr[lim] = {};
   int main(){
  	int n;
	scanf("%d",&n);
	for(int i =1 ; i <= n ; ++i){
		scanf("%d",&arr[i]);
		arr[i] += arr[i-1];
	}
	if(arr[n]&1){
		printf("NO");
		return 0;
	}
	int tar = arr[n]/2;
	for(int i = 1 ; i < n ;++i){
		if(arr[i] == tar){
			printf("%d",i);
			return 0;
		}
	}
	int a = 1;
	for(int i = 2 ; i < n ; ++i){
		while(arr[i] - arr[a] > tar){
			a++;
		}
		if(arr[i]-arr[a] == tar){
			printf("%d %d\n",a , i);
			return 0;
		}
	}
	printf("NO");
	return 0;
   }
