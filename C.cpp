#include <bits/stdc++.h> 
 
 using namespace std;
  char str[220];
  int main(){
  	int k;
	int n;
	scanf("%s%d",str,&k);
	n = strlen(str);
	int can = 0 , ast = 0;
	for(int i = 0 ; i < n ; ++i){
		if(str[i] == '?')can++;
		if(str[i] == '*')ast++;
	}
	if(n - can < k and ast == 0){
		printf("Impossible");
		exit(0);
	}
	if(n > k and can == 0 and ast == 0){
		printf("Impossible");
		exit(0);
	}
	if(n-can-ast > k){
		int x = n-can-ast-k;
		if(x > can+ast){
			printf("Impossible");
			exit(0);
		}
		for(int i = 0 ; i < n ; ++i){
			if(x and i!=n and (str[i+1] == '?' or str[i+1] == '*')){
				x--;
				continue;
			}
			if(str[i] == '?' or str[i] == '*')continue;
			printf("%c",str[i]);
			
		}
	}else if(n - can - ast < k){
		int p = k - n +can +ast;
		for(int i = 0 ; i < n ; ++i){
			if(p and (str[i] == '*')){
				for(int j = 0 ; j < p ; ++j)printf("%c",str[i-1]);
				p = 0;
			}
			if(str[i] == '?' or str[i] == '*')continue;
			printf("%c",str[i]);
		}
	}else{
		for(int i = 0;  i< n ; ++i){
			if(str[i] == '*' or str[i] == '?')continue;
			printf("%c",str[i]);
		}
	}
  }
