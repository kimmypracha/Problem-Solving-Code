#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
 const int lim = 1e3 + 10;
 vector<int> G[lim];
 int TC[lim][lim] = {};
 bool V[lim] = {};
 void dfs(int st , int now){
 	TC[st][now]  = 1;
	for(int i : G[now]){
		dfs(st , i);
	}
 }
 int main(){
 	int N , M , Q;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i =0 ;  i < M ; ++i){
		int A , B;
		scanf("%d%d",&A,&B);
		G[A].eb(B);
		G[B].eb(A);
	}
	for(int i =1  ; i <= N ; ++i){
		dfs(i , i);
	}
	for(int i =0 ; i  < Q; ++i){
		int A , B;
		scanf("%d%d",&A,&B);
		if(TC[A][B])printf("Yes\n");
		else printf("No\n");
	}
 }
