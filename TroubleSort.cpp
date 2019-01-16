#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 1e5 + 10;
 int arr[lim];
 int E[lim];
 int O[lim];
 void TS(int n){
 	int se = 0 , so = 0;
	for(int i = 0 ;i < n ; ++i){
		if(i&1){
			O[so++] = arr[i];
		}else E[se++] = arr[i];
	}
	sort(O , O + so);
	sort(E , E + se);
	int io = 0 , ie = 0 ;
	for(int i = 0; i  < n ; ++i){
		if(i&1){
			arr[i] = O[io++];
		}else{
			arr[i] = E[ie++];
		}
	}
 }
 int main(){
 	int t;
	int cnt = 1 ;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i =0 ; i < n ; ++i){
			scanf("%d",&arr[i]);		
		}
		TS(n);
		int F = -1;
		for(int i= 0 ; i < n-1 ;++i){
			if(arr[i] > arr[i+1]){
				F  = i;
				break;
			}
		}
		if(F == -1) printf("Case #%d: OK\n",cnt++);
		else printf("Case #%d: %d\n",cnt++ ,F );	
	}
 }
