#include <bits/stdc++.h>

 using namespace std;
 const int lim = 1e5 + 10; 
typedef long long int lli; 
lli A[lim];
 lli B[lim];
 int main(){
  int N , H , W; 
   scanf("%d%d%d",&N,&H,&W);
   for(int i= 0; i < N ; ++i){
   	scanf("%lld",&A[i]);
	A[i] = (i)? A[i] + A[i-1] : A[i];
   }
   for(int i = 0;  i <  N  ; ++i){
   	scanf("%lld",&B[i]);
	B[i] = (i)? B[i] +B[i-1] : B[i];
    }
    lli MA = A[H-1] , MB = B[W-1];
    for(int i = H;  i< N ; ++i){
   	MA = max(MA , A[i] - A[i-H]);
    }
    for(int i = W;  i < N ; ++i){
    	MB  =max(MB , B[i] - B[i-W]); 
   }
   printf("%lld" , (MA*(lli)W) + (MB*(lli)H)); 	
 }
