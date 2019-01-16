#include <bits/stdc++.h>
 
 using namespace std;

 bool isprime(int n){
 for(int i = 2 ; i*i < n ;++i ){
 	if(n%i == 0)return false;
 }
return true; 
}
 int main(){
 	int n;
	scanf("%d",&n);
	for(;not isprime(n);n++){}
	printf("%d",n);
 }
