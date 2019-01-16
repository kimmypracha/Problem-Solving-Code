#include <bits/stdc++.h>
#define fi first
#define se second
   using namespace std;
   const int lim = 1e5+10;
   typedef pair<int,int> pii;
   int par[lim];
   int con[lim];
   int pos[lim];
   int n;
   int fh(int now){
	return par[now] = (par[now] != now)? fh(par[now]) : now;
   }
   void init(){
  	for(int i = 1 ; i  <= n ; ++i){
		par[i] = con[i] = pos[i] =  i;
	}
   }
   int main(){
   	int m;
	scanf("%d%d",&n,&m);
	init();
	for(int i = 1 ;  i <= m  ;++i){
		int a , b;
		char c;
		scanf(" %c",&c);
		if(c == 'E'){
			scanf("%d%d",&a,&b);
			if(con[a]){ // fh find now[a]
				if(con[b]){
					par[fh(con[b])] = fh(con[a]);
					pos[fh(con[a])] = b;
					con[a] = 0;
				}else{
					pos[fh(con[a])] = b;
					con[b] = con[a];
					con[a] = 0;
				} 
			}	
		}else{
			scanf("%d",&a);
			printf("%d\n",pos[fh(a)]);
		}	
	}
   }
