#include <bits/stdc++.h>

 using namespace std;
 typedef struct node {
 	 int a ,b , c;
 };
 queue<node> q;
 int DP[100][100][100];
 int main(){
  	int A , B , C;
	scanf("%d%d%d",&A, &B , &C);
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; ++j){	
			for(int k = 0 ;  k < 100 ; ++k){
				DP[i][j][k] = 1e9;
			}
		}
	}
	DP[A][B][C] = 0 ;
	q.push({A,B,C});
	while(not q.empty()){
		A = q.front().a;
		B = q.front().b;
		C = q.front().c;
		q.pop();
		if(A == B and B == C ){
			printf("%d",DP[A][B][C]);
			break;
		}
		if(A >= 100 or B >= 100 or C >= 100 ){
			continue;
		}
		if(A + 1 < 100 and B+ 1 < 100 and DP[A+1][B+1][C] > DP[A][B][C] + 1 ){
			DP[A+1][B+1][C] = DP[A][B][C] + 1;
			q.push({A+1, B + 1 , C});
		}
		if(A + 1 < 100 and C  +1  < 100 and DP[A+1][B][C+1] > DP[A][B][C] + 1){
			DP[A+1][B][C+1] = DP[A][B][C]  +1;
			q.push({A+1 , B , C+1});
		}
		if(B  +1 < 100 and C + 1 < 100 and DP[A][B+1][C+1] > DP[A][B][C] +  1){
			DP[A][B+1][C+1] = DP[A][B][C] + 1 ;
			q.push({A , B  +1 , C+1});
		}
		if(A+ 2  < 100 and DP[A+2][B][C] > DP[A][B][C] + 1) q.push({A+2, B ,C}) , DP[A+2][B][C] = DP[A][B][C]  +1 ;
		if(B+ 2  < 100 and DP[A][B+2][C] > DP[A][B][C] + 1) q.push({A, B+2 ,C}) , DP[A][B+2][C] = DP[A][B][C]  +1 ;
		if(C+ 2  < 100 and DP[A][B][C+2] > DP[A][B][C] + 1) q.push({A, B ,C+2}) , DP[A][B][C+2] = DP[A][B][C]  +1 ;
	}
 }
