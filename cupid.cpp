#include <bits/stdc++.h>

 using namespace std;
 const int lim = 1e5 + 10;
 int M[lim] , F[lim]; 
 int main(){
	int n , k;
	scanf("%d%d",&n,&k);
	for(int i =0  ;i < n; ++i){
		scanf("%d%d",&M[i] , &F[i]);
	}
	int m = 0 , f = 0 ;
	while(m < n and f < n){
		int tmp = min(M[m] , F[f]);
		while(abs(m - f) >k ){
			if(m > f)f++;
			else m++; 
		}
		M[m] -= tmp;
		F[f] -= tmp;
		if(M[m] == 0)m++;
		if(F[f] == 0)f++;
	}
	bool Have = false;
	for(int i = 0 ; i < n ; ++i){
//                printf("%d %d\n" , M[i] , F[i]);
		Have |= ((M[i] != 0) or (F[i] != 0));
	}

	cout << ((not Have)? "YES" : "NO") ;
 }
