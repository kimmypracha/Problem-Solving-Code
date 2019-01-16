#include <bits/stdc++.h>
#include <random>
 using namespace std;
 

 int main(){
 	FILE *fp = fopen("1.in", "w");
	srand(time(NULL));
	int n = 1 + rand()%200000;
	int m = 1 + rand()%200000;
	fprintf(fp , "%d %d\n", n , m );
	 for(int i = 1 ; i <= n ; ++i){
	fprintf(fp, "%d\n" ,rand()%1000000000 + 1 );
	}
	for(int i = 1 ; i <= m; ++i){
		fprintf(fp , "%d\n", rand()%1000000000 + 1);
	}
	fclose(fp);
 } 
