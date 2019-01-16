#include <bits/stdc++.h>
 
  using namespace std;
  int arr[110] = {};
  int main(){
  	int w, h;
	scanf("%d%d",&w,&h);
	for(int i =1 ; i <= 2 ; ++i){
		int a  , b;
		scanf("%d%d",&a,&b);
		arr[b] = a;
	}
	int now = w;
	for(int i = h; i >= 0 ; --i){
		now += i;
		now -= arr[i];	
		if(now < 0 )now = 0;
	}
	printf("%d",now);
  }
