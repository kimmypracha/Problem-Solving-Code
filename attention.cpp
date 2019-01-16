#include <bits/stdc++.h>
 #define fi first
#define se second
 using namespace std;
 const int lim = 3e5 + 10;
 typedef pair<int,int > pii;
 pii Arr[lim]  = {};
 int main(){
  	int n;
	scanf("%d",&n);
	string A;
	cin >> A;
	for(int i = 0 ; i < A.size(); ++i ){
		if(A[i] == 'E') Arr[i+1].fi = 1;
		else Arr[i+1].se = 1;
	} 
	for(int i= 1 ; i <= n ; ++i){
		Arr[i].fi += Arr[i-1].fi;
		Arr[i].se += Arr[i-1].se;
		//printf("%d ",Arr[i]);
	}
	//printf("\n");
	int ans = 1e9 + 10;
	for(int i=1 ; i <= n ; ++i){
	//	if(i == 1)
	//	printf("%d %d\n" , (n-i)  ,  (Arr[n] - Arr[i]));
		ans = min(ans , abs((i-1) - Arr[i-1].fi) + abs((n-i) - (Arr[n].se-Arr[i].se)) ); 
	}
	printf("%d" ,ans);
 }
