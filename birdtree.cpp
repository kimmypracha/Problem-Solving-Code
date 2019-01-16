#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
 int gcd(int a , int b){
	return (!b)? a : gcd(b , a%b);	
 }
  int main(){
  	int T;
	scanf("%d",&T);
	while(T--){
		int a , b;
		scanf("%d/%d",&a,&b);
		while(a != 1 or b != 1){
			if(a > b){
				printf("R");
				a -=b;
				swap(a,b);
				int g = gcd(a,b);
				a /= g;
				b /= g;
			}else{
				printf("L");
				swap(a,b);
				a -= b;
				int g = gcd(a,b);
				a /= g;
				b /= g;
			}
		}
		printf("\n");
	}
  }
