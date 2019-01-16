#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  typedef long long int lli;
  const int lim = 1010;
  int G[lim][lim] = {};
  int n , m ;
  map<lli, int > mpi; 
  int ans = 0 ;
  void dfs(int now , int a=-1 , int b =-1 , int c = -1){
	if(c !=-1){
		int cnt = 0 ;
		if(G[now][a]) cnt++;
		if(G[now][b]) cnt++;
		if(G[now][c]) cnt++;
		if(G[a][b]) cnt++;
		if(G[a][c]) cnt++;
		if(G[b][c]) cnt++;
	//	printf("%d %d %d %d : %d\n",now , a , b , c, cnt);
		if(cnt >= 5){
			vector<int> vi;
			vi.eb(now);
			vi.eb(a);
			vi.eb(b);
			vi.eb(c);
			sort(vi.begin() , vi.end());
			lli hsh = 0;
 			for(int i = 0 ; i < 4 ;++i){
				hsh *= 1003LL;
				hsh += (lli)vi[i];
			}
			if(mpi.find(hsh) != mpi.end()){
				return;
			}else {
				mpi[hsh]= 1;
				ans++;
			}
		}
		return;
	}
	for(int i =1 ;  i<= n; ++i ){
		if(i != a and i != b and i != c and i != now and G[now][i] ){
			dfs(i , now , a , b );
		}
	}
  }
  int main(){
	scanf("%d%d",&n,&m);
	for(int i =0 ; i < m ; ++i){
		int x , y;
		scanf("%d%d",&x,&y);
		G[x][y] = 1;
		G[y][x] = 1;
	}
	for(int i =1 ;  i <= n ; ++i ){
		dfs(i);
	}
	printf("%d",ans);
 }
