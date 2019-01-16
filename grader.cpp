#include <bits/stdc++.h>

 using namespace std;
 const int lim = 1e5+ 10;
 int arr[lim];
 int main(){
  	int n;
	scanf("%d",&n);
	for(int i =0 ; i  < n;  ++i){
		scanf("%d",&arr[i]);	
	}
	sort(arr , arr + n);
	int q;
	scanf("%d",&q);
	while(q--){
	 	int  l , r;
		int a , b;
		scanf("%d%d",&l,&r);
		if(l  > r ) swap(l,r);		
		 a = lower_bound(arr , arr+ n , l) -arr;
		 b = upper_bound(arr , arr + n , r) - arr;
		printf("%d\n" ,b - a); 
	}
 }
