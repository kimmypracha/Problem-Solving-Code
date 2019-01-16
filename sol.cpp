#include <bits/stdc++.h>
 
using namespace std;
 int arr[200000];
int main(){
 	int n ,  m;
	scanf("%d%d", &n,  &m);
	for(int i = 0 ; i  < n;  ++i){
		scanf("%d", &arr[i]);	
	}
	sort(arr , arr + n );
	for(int i = 0 ; i  < m ; ++i){
		int a;
		scanf("%d", &a);
		if(binary_search(arr  , arr + n ,a ) ){
			printf("y\n");
		}else{
			printf("n\n");
		}
	}
 }
