#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 typedef struct edge{
	int a , b ,w ;
	edge(int x, int y , int z): a(x) , b(y) , w(z) {};
 };
const int lim = 1e5 + 10;
int par[lim];
vector<edge> edlst;
 int Findhead(int now ){ // Union - Find 
	if(now != par[now]) return Findhead(par[now]);
	return now;
 }
 int main(){
 	int n , m;
	scanf("%d%d",&n,&m);
	int cnt =1 ;
	for_each(par+ 1 , par  +1+ n , [&cnt](int& a){a = cnt++;} );
	for(int i = 0 ; i <  m ; ++i){
		int a,  b , w;
		scanf("%d%d%d",&a,&b ,&w);
		edlst.eb(a,b,w);
	}
	int ans = 0 ;
	sort(edlst.begin() , edlst.end() , [](const edge &a , const edge &b) -> bool{return a.w < b.w; });
	for(int i =0 ; i  < m; ++i){
		if(Findhead(edlst[i].a) != Findhead(edlst[i].b)){
			par[Findhead(edlst[i].a)] = Findhead(edlst[i].b);	
			ans += edlst[i].w;
		}
	}
	printf("%d",ans);
 }
