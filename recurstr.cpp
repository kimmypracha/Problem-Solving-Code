#include <bits/stdc++.h>
 
 using namespace std;
  int fn[36] = {1 , 1 , 1};
  int main(){
  	int n , k ;
	for(int i = 3 ; i <= 35 ; ++i){
		fn[i] = fn[i-1] + fn[i-2] + fn[i-3];
	}
	scanf("%d%d",&n,&k);
	if(fn[n] < k){
		printf("-1");
		return 0;
	}
	int pos = n;
	while(true){
		if(pos == 0){	
			printf("a");
			break;
		}else if(pos == 1){
			printf("b");
			break;
		}else if(pos == 2){
			printf("c");
			break;
		}
		if(fn[pos-1] >= k){
			pos = pos-1;
		}else if(fn[pos-1] + fn[pos-2] >= k){
			k -= fn[pos-1];
			pos = pos-2;
		}else if(fn[pos-1] + fn[pos-2] + fn[pos-3] >= k){
			k -= fn[pos-1] + fn[pos-2];
			pos = pos-3;
		}
	}
  }
