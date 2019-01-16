#include <bits/stdc++.h>

  using namespace std;
const long long int lim = 1e6 + 10;
typedef long long int lli;  
int gcd(int a , int b){
  	return(!b)? a : gcd(b , a%b); 
 }
int sie[lim];
  int main(){
	for(lli i = 2 ; i< lim ; ++i){
		if(sie[i] == 0){
			for(lli j  = i  ; j < lim ; j *=i){
				for(lli k =j ; k < lim  ; k += j){
					sie[k]++;
				}
			} 
		}
	}
  	int a , b , c , d;
	while(scanf("%d%d%d%d",&a , &b , &c ,  &d)!=EOF){
	int ans =0 ;
	int A = -1 , B = -1;
	int k = min(b,d);
	
	for(int i = 2 ; i <=k ; ++i ){
		int x = b  - b%i;
		int y = d - d%i;
		if(a > x  or x > b or c > y or y > d)continue;
		if(ans < sie[i]){
			ans = sie[i];	
			A = x;
			B = y;	
		}else if(ans == sie[i] and x+y > A+B){
			A = x;
			B = y;
		}else if(ans == sie[i] and x+y == A+B and x > A){
			A  =x;
			B  =y;
		}
	}
//	printf("Compare :: %d %d\n" , sie[96] , sie[100]);
	printf("%d %d\n",A,B);
	}
  }
