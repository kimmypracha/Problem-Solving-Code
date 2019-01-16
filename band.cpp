#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef pair<int,int> pii;
 typedef long long int lli; 
 const int lim= 1010;
 bool G[lim][lim] = {};
 vector<pii> vi;
int main(){
 	int n , m;
	scanf("%d%d",&n,&m);
	for(int i =0 ; i <  m ;++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a][b] = true;
		G[b][a] = true;
		vi.eb(a,b);
	}
	lli ans = 0 ;
	for(int i = 0 ; i < m ; ++i){
		int a = vi[i].fi;
		int b = vi[i].se;
		lli cnt = 0;
		for(int j =1 ; j <= n ; ++j){
			if(G[a][j] and G[b][j]){
			cnt++;	
			}	
		}
		ans += (cnt * (cnt-1LL))/2LL;
	}
	lli ax =0 ; 
	for(int i =0 ; i < m ; ++i){
		for(int j = i +1 ; j < m ; ++j){
			int a = vi[i].fi;
			int b = vi[i].se;
			int c = vi[j].fi;
			int d = vi[j].se;
			if(G[a][c] and G[a][d] and G[b][c] and G[b][d])ax++;
		}
	}
	printf("%lld",ans - (5*ax)/3);
 }
