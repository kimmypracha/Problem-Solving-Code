#include <bits/stdc++.h>

 using namespace std;
int arr[100010];
  int main(){

	int n;
	scanf("%d",&n);
	int g = 1;
	for(int i = 1 ;  i<= n ; ++i){
		int x;
		scanf("%d",&x);
		if(i == 1)g = x;
		else  g = __gcd(g,x);
		arr[i] = x;
	}
	long long int ans = 0 ;
	for(int i =1 ; i <= n ; ++i){
		ans += (long long int)arr[i]/g;
	}
	printf("%lld",ans); 
}
