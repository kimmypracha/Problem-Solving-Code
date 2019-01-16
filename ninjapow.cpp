#include <bits/stdc++.h>

 using namespace std;
 int Arr[1<<22] = {};
 int DP[1<<22] = {};
 int lim = (1<<21);
 int main(){
 	int N;
	scanf("%d",&N);
	for(int i =0 ; i < N ; ++i){
		scanf("%d",&Arr[i]);	
	}
	for(int i =N-1 ; i >= 0 ; --i){
		DP[i] = Arr[i];
		DP[i] += (2*i + 1 < lim)? DP[2*i + 1] : 0 ;
		DP[i] += (2*i + 2 < lim)? DP[2*i + 2] : 0 ;
	}
	printf("%d\n",DP[0]);
	int M;
	scanf("%d",&M);
	for(int i =0 ; i  < M;  ++i){
		int A , B;
		scanf("%d%d",&A,&B);
		if(DP[A] > DP[B])printf("%d>%d\n",A, B);
		else if(DP[A] == DP[B]) printf("%d=%d\n",A,B);
		else if(DP[A] < DP[B])printf("%d<%d\n",A,B);
	}
 }
