#include <bits/stdc++.h> 
 
 using namespace std;
 const int lim = 1e5+10;
 int arr[lim];
 int sum[lim] = {0};
  int main(){
  	int n , m ;
	scanf("%d%d",&n,&m);
	for(int i =  1 ; i <=n ; ++i){
		scanf("%d",&arr[i]);	
		sum[i] = arr[i] + sum[i-1];
	}
	
  }
