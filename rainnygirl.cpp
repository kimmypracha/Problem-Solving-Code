#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std; 
 int G[21];
 int d[1<<21];
 int v[1<<21];
 int p[1<<21];
 int pth[1<<21];
 queue<int> q;
 int main(){
 	int n , m;
	while(scanf("%d%d",&n,&m) , not (n == 0 and m == 0)){
		fill(d , d + (1<<n) , 1e9);
		fill(G , G + n , 0);
		q = queue<int>();
		for(int i =0 ;  i< m;  ++i){
			int a , b;
			scanf("%d%d",&a,&b);
			G[a] |= (1<<b);
			G[b] |= (1<<a);		
		}
		for(int i =0 ; i < n; ++i){
			q.push(((1<<n) - 1)^(1<<i));
			d[(((1<<n)-1)^(1<<i))] = 1;
			v[(((1<<n)-1)^(1<<i))] = i;
			p[(((1<<n)-1)^(1<<i))] = (1<<n)-1;				
		}
		while(not q.empty()){
			int st =q.front();
			q.pop();
			if(st == 0)break;
 			int nst = 0;
			for(int i =0 ;  i < n ; ++i){
				if(st&(1<<i)){
					nst |= G[i];
				}
			}
			for(int  i =0 ; i < n; ++i){
				if((G[v[st]]&(1<<i)) and d[nst&(~(1<<i))] > d[st]+1){
					 d[nst&(~(1<<i))] = d[st]+1;
					 v[nst&(~(1<<i))] = i;
					 p[nst&(~(1<<i))] = st;
					 q.push(nst&(~(1<<i)));
				}
			}
			if(d[nst&(~(1<<v[st]))] > d[st]+1){
				d[nst&(~(1<<v[st]))] = d[st]+1;
				v[nst&(~(1<<v[st]))] = v[st];
				p[nst&(~(1<<v[st]))] = st;
				q.push(nst&(~(1<<v[st])));
			}
		}
		if(d[0] == 1e9)printf("Impossible\n");
		else{	
			printf("%d:",d[0]);
			int idx =d[0]-1;
			for(int i = 0; i != (1<<n)-1 ; i = p[i] ,idx-- ){
				pth[idx] = v[i];
			}
			for(int i =0 ;  i < d[0] ; ++i){
				printf(" %d",pth[i]);
			}
			printf("\n");
		}
	}
 }
