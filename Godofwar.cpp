#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 const int lim = 1e5 +10;
 typedef pair<int,int> pii;
 typedef struct node {
 	int a ,  b , w;
	node(int x , int y ,int z): a(x) , b(y) , w(z){};
 };
 vector<node> vi; 
 vector<pii> G[lim];
 int cnt = 0 ;
 int ans = 0 ;
 int d[2][lim];
 void dijkstra(int s ){
 	priority_queue<pii , vector<pii> , greater<pii> > pq;
	d[cnt][s] = 0;
	pq.push({0 , s});
	while(not pq.empty()){
		int now = pq.top().se;
		pq.pop();
		for(auto i : G[now]){
			if(d[cnt][i.fi] > d[cnt][now] + i.se){
				d[cnt][i.fi] = d[cnt][now] + i.se;
				pq.push({d[cnt][i.fi] , i.fi});
			}
		}
	}
 }
 int main(){
 	int n, m, s,t ,mxa = 0;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	fill(d[0], d[0] + lim , 2e9+10);
	fill(d[1], d[1] + lim , 2e9+10);
	for(int i = 0 ; i < m ; ++i){
		int a , b, c;
		scanf("%d%d%d",&a,&b,&c);
		vi.eb(a,b,c);
		G[a].eb(b,c);
		G[b].eb(a,c);
		ans += c;
		mxa = max(mxa , c);
	}
	dijkstra(s);
	if(d[0][t] == 2e9+10){
		printf("%d",mxa);
		return 0;
	}
	cnt++;
	dijkstra(t);
	int Max = 0;
	for(int i =0 ;  i < m ; ++i){
		Max = max(Max , ans - d[0][vi[i].a] - d[1][vi[i].b]);
		Max = max(Max , ans - d[0][vi[i].b] - d[1][vi[i].a]);
	}
	printf("%d",Max);
 }
