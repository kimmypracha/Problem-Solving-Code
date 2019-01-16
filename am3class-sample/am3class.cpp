#include <bits/stdc++.h>
 
 using namespace std;
 int R[110][110] , G[110][110] , B[110][110];
 int main(){
	int W  ,H;
	scanf("%d%d",&W,&H);
	int sum = 0;
	for(int i = 1; i <= H ; ++i){
		for(int j = 1 ; j <= W ; ++j){
			scanf("%d%d%d",&R[i][j] , &G[i][j] , &B[i][j]);
			sum += R[i][j];	
		}
	}
//	printf("%d",sum);
//	return 0;
	if(sum <= 700000) printf("M");
	else if(sum <=1350000)printf("A");
	else printf("3");
 }
