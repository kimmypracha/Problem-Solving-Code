#include <bits/stdc++.h>

 using namespace std;
 const int lim = 2e3 + 10;
int A[lim] , B[lim];
 int main(){
 	int N;
	 scanf("%d",&N);
	for(int i =0 ; i  < N;  ++i){
		scanf("%d",&A[i]);
	}
	for(int i =0 ; i  < N ; ++i){
		scanf("%d",&B[i]);
	}
	sort(A , A + N);
	sort(B, B + N );
	int ans = 0 ;
	for(int i =0 ; i  < N;  ++i){
		ans += abs(A[i]-B[i]);
	}
	printf("%d",ans);
 }
