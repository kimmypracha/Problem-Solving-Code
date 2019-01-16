#include <bits/stdc++.h>

 using namespace std;
  int arr[100001] = {}; 
 int main(){
  	int n;
	scanf("%d",&n);
	for(int i =0 ; i  < n;  ++i){
		int l , r;
		scanf("%d%d",&l,&r);
		arr[l]++;
		arr[r]--;
	}
	int Max = 0 ;
	for(int i = 0 ; i <= 100000 ; ++i){
		Max = max(arr[i] , Max);
	}
	if(Max == n) printf("no");
	else printf("yes %d",Max);
 }
