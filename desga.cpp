#include <bits/stdc++.h> 
 
 using namespace std;
  const int lim = 1e5 + 10;
  int arr[lim] = {};
  int main(){
 	int n, k ;
	scanf("%d%d",&n,&k);
	for(int i = 1;  i <= n ; ++i){
		string A;
		cin >> A;
		if(A == "UR"){
		arr[i] = 1;
		}
		arr[i] += arr[i-1];
	}
	int Max=  0;
	for(int i =k ; i <= n ; ++i){
		Max = max(Max , arr[i] - arr[i-k]);
	} 
	printf("%d",Max); 
 } 
