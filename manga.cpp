#include <bits/stdc++.h>
 #define eb emplace_back
#define fi  first
#define se second
 using namespace std;
 const int lim = 50010;
 int N , M ,  K;
 typedef pair<int, int > pii;
 typedef struct node{
	int v , w , t;
	node(int a,  int b , int c): v(a) , w(b) , t(c) {};
 };
 class Comp{
 	bool operator () (const pii &a ,const pii &b ){
		return a.se > b.se;
	}
 }
 int D[lim];
 vector<node> G[lim];
 priority_queue<pii , vector<pii> , Comp> pq;
 bool Can(int num){
 	pq.push(1, 0);
	
 }
 int main(){
	fill(D , D + lim , 1e9);
	scanf("%d%d%d",&N,&M,&K);
	for(int i = 0 ; i <  M ;  ++i){
		int A , B , C; 
		scanf("%d%d%d",&A,  &B , &C);	
		G[A].eb(B, C  ,i);
		G[B].eb(A,C , i);
	}
	int l = 0 , r = M ,  m;
	while(l < r ){
		m = (l+r)/2 ;
		if(Can(m)){
			r = m;
		}else {
			l = m+1;
		}
	}
 }
