#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
 using namespace std;
typedef pair<int,int> pii;
 const int lim = 1e4  + 10; 
 typedef struct node{
   int a , b;
   long long int w;
   node(int x , int y ,long long int  z): a(x) , b(y) , w(z) {};
 };
 long long int DP[9][lim];
 vector<pii> G[lim];
 queue<node> q;
 int main(){ 
 	int N , M, T , X , Y;
	scanf("%d%d%d",&N,&M,&T);
	scanf("%d%d",&X,&Y);
	for(int i = 0 ; i < M ; ++i){
		int a, b;
		long long int w;
		scanf("%d%d%lld",&a,&b,&w);
		G[a].eb(b,w);
	}
	for(int i = 0 ;i < 9 ; ++i){
		for(int j = 0;  j < lim ; ++j){
			DP[i][j] = 1e18;
		}
	}
	q.push({X,1%T,0});
	DP[1%T][X] = 0;
	while(not q.empty()){
		int now = q.front().a;
		int rhy = q.front().b;
		long long int w = q.front().w;
	//	printf("%d %d %lld\n",now , rhy, w);
		q.pop();
		for(pii i : G[now]){
			if(DP[(rhy+1)%T][i.fi] > DP[rhy][now] + i.se){
				DP[(rhy+1)%T][i.fi] = DP[rhy][now] + i.se;
				q.push({i.fi, (rhy+1)%T , w + i.se});
			}
		} 
	}
	if(DP[0][Y] == 1e18)printf("-1");
	else printf("%lld" , DP[0][Y]);
 }
