#include <bits/stdc++.h>

  using namespace std;
 	int st[100];
	void dfs(int now , int idx){
		if(now < 0 ) return ;
		if(now == 0){
			for(int i =0 ; i  < idx; ++i){
				printf("%s" , (st[i] == 1)? "--\n"  :  "||\n" );
			}
			printf("E\n");
		}
		st[idx] = 1;
		dfs(now - 1 , idx+1);
		st[idx] = 2;
		dfs(now - 2 , idx+1);
	}
	 int main(){
 		int n;
		scanf("%d",&n);
		dfs(n , 0);
	}	
