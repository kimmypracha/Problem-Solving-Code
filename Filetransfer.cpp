#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 const int lim = 1e3 + 10; 
 vector<int> G[lim];
 bool inq[lim];
 bool Can(int a , int b){
 	queue<int> q;
	fill(inq , inq + lim , false);
	q.push(a);
	inq[a] = true;
	while(not q.empty()){
		int now = q.front();
		q.pop();
		if(now == b){
			return true;
		}
		for(int i : G[now]){	
			if(not inq[i]){
				q.push(i);
				inq[i] = true;
			}
		}
	}
	return false;
 }
 int main(){
  	int N , M , Q  , a ,b;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=0  ; i < M ; ++i){
		scanf("%d%d",&a,&b);
		G[a].eb(b);
	} 
	for(int i =0 ;  i < Q ; ++i){
		scanf("%d%d",&a,&b);
		if(Can(a , b)){
			printf("Yes\n");
		}else printf("No\n");
	}
 }
