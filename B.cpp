#include <bits/stdc++.h>
 

 using namespace std;
 
  int main(){
  	int n;
	scanf("%d",&n);
	int m = sqrt(n)+1;
	m = m*m;
	int ans = 2e9;
//	printf("||%d\n",m);
	for(int i = 1 ; i*i <= n ; ++i){
		if(n%i == 0) ans = min(i + n/i , ans);
	}
	for(int i = n+1 ; i <= n+100 ; ++i){
		for(int j = 1; j*j <= i ; ++j){
			if(i%j == 0) ans = min(j + i/j , ans);
		}
	}
	printf("%d",ans);
  }
