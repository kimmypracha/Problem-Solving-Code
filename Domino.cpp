#include <bits/stdc++.h>

  using namespace std;
 int st[100];
 void enu(int n , int idx){
	if(n < 0 )return;
	if(n == 0){
		for(int i=0 ;i < idx; ++i ){
			if(st[i] == 1)printf("--\n");
			else printf("||\n");
		}
		printf("E\n");
	}else{
		st[idx] = 1;
		enu(n- 1 , idx+1);
		st[idx] = 2;
		enu(n-2 , idx+1);
	}
 }
 int main(){
 	int n;
	scanf("%d",&n);
	enu(n , 0);
 }
