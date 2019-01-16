#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 7e4 + 10;
 int ant[lim] = {};
 int main(){
 	int l, t , n;
	scanf("%d%d%d",&l,&t,&n);
	for(int i = 0;  i < n ; ++i){
		string A;
		scanf("%d",&ant[i]);
		cin >> A;
		if(A[0] == 'L'){
			 ant[i] = (l + (l - ant[i]))%(2*l);
		}
		ant[i] = (ant[i]  +t )%(2*l);
	}
	for(int i = 0 ; i < n;  ++i){
		if(ant[i] > l){
		//	printf("i = %d : %d" ,i,ant[i]);
			ant[i] = l - (ant[i] - l);
		//	printf(" : %d\n",ant[i]);
		}
	} 
	sort(ant  ,ant + n );
	for(int i =0  ; i < n ; ++i){
		printf("%d ",ant[i]);
	}
}
