#include <bits/stdc++.h>
 
 using namespace std;
  
 int main(){
  	int n;
 	srand(time(NULL));
	n = rand()%20 + 1;
	int k;
	k = rand()%7 + 1;
	printf("%d %d\n",n,k);
	for(int i = 0 ; i < (1<<k) ; ++i){
		printf("%d\n",rand()%1000);
	}
	return 0;
 }
