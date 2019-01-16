#include <bits/stdc++.h>
#define ls(x) (x&(-x))
 using namespace std;
  int arr[1010];
  int ord[1010];
  int fre[1010] = {};
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ;++i){
		scanf("%d",&arr[i]);
		for(int j = arr[i] ; j <= n ; ++j){
			fre[j]++;
		}
		ord[n-i] = arr[i]-fre[arr[i]];
	}
	for(int i = 1 ;i < n ; ++i){
		if(ord[i] + 1 <= i){
			ord[i]++;
			break;
		}else{
			ord[i] = 0;
		}	
	}
	fill(fre+1 , fre+1 + n , 0);
	int idx = 1;
	for(int i = n-1 ; i >= 0 ; --i){
		for(int j = 1 ; j <= n ; ++j){
			if(j - fre[j] == ord[i]+1){
				for(int k = j; k <= n ; ++k) fre[k]++;
				arr[idx++] = j;
				break;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d\n",arr[i]);
	}
  }
