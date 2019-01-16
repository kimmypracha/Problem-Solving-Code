#include <bits/stdc++.h>

 using namespace std;
  const int lim = 1e6+10;
  typedef long long int lli;
  int sie[lim] = {};
 int main(){
 	int A , B , C , D;
	scanf("%d%d%d%d",&A,&B, &C, &D);
	int ans = B+D , sz = 1;
 	for(lli i = 2 ; i <= 1000000 ; ++i){
		if(sie[i] == 0){
			for(lli j = i ; j <= 1000000 ; j *= i){
				for(lli k = j ; k <= 1000000 ; k += j){
					sie[k]++;
				}
			}
		}
	}
	int a = B, b = D;
	for(int i = 2 ; i <= B ; ++i){
		int x = B - B%i;
		int y = D - D%i;
		if(A > x or C > y )continue;
		if(sz < sie[i]){
			sz = sie[i];
			a = x;
			b = y;
			ans = x+y;
		}else if(sz == sie[i] and ans < x+y){
			ans = x+y;
			a = x;
			b = y;
		}
	}
	printf("%d %d",a,b);
 }
