#include <bits/stdc++.h>
 
 using namespace std;
 typedef long long int lli; 	
  lli gcd(lli a , lli b){
	return (!b) ? a : gcd(b , a%b);	
  }
  int main(){
  	 lli r , t , ro , to;
	scanf("%lld%lld",&r,&t);
	ro = r;
	to = t;
	lli g = gcd(r,t);
	r /= g;
	t /= g;
	lli L = r*t*g;
	g = gcd(L , 400);
	
 }
