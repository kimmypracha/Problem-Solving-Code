#include <bits/stdc++.h>

 using namespace std;
 typedef long long int lli;

 int main(){
	int cnt = 0 ;
	for(lli m = 1LL  ; m <= 60LL ; ++m){
		lli ans = (1LL<<m)*5 + 1;
		lli tmp = sqrt(ans);
		if(tmp*tmp == ans){
			cnt++;
			printf("%lld %lld\n",tmp , m);	
		}
	}
	printf("%d" ,cnt); 
}
