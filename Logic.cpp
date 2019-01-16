#include <bits/stdc++.h>

 using namespace std;
 const int lim = 110;
 bool have ;
 bool taua[lim]  , taub[lim] ;
long long  int sta[lim], stb[lim];
 int ST[1<<5];
 int sat[1<<5];
 int n , m ;
 int main(){
	int t;
	scanf("%d",&t);
	while(t--){
	have = false;
	fill(taua , taua + lim , false);
	fill(taub , taub + lim , false);
	fill(sat , sat + lim , 0);
		fill(sta , sta + lim , 0);
		fill(stb , stb + lim , 0);
	scanf("%d%d",&n,&m);
	for(int i =0 ; i  < n;  ++i){
		int x;
		scanf("%d", &x);
		for(int j = 0 ; j < x ; ++j){
			string A;
			cin >> A;
			if(A[0] == '-'){
				sta[i] |= (1LL<<(16 + A[1] - 'a'));
			}else {
				sta[i] |= (1LL<<(A[1]-'a'));
			}
		}
	}
	for(int i = 0 ; i < m ; ++i){
		int x;
		scanf("%d",&x);
		for(int j = 0 ; j < x ;  ++j){
			string B;
			cin >> B;
			if(B[0] == '-'){
				stb[i] |= (1LL<<(16 + B[1] - 'a'));
			}else{
				stb[i] |= (1LL<<(B[1] - 'a'));
			}
		}
	}			
	have = false; 
	for(int i =0 ; i < (1<<16) ; ++i){
		long long  St = (long long )i;
		for(int j = 0 ; j < 16 ; ++j){
			if(i&(1<<j))continue;
			St |= (1LL<<(16+j));
		}
		bool A = true , B  = true;
		for(int j = 0; j  < n ; ++j){
			A = A&&((St^sta[j]) != (St|sta[j]));
		}
		for(int j = 0 ; j < m; ++j){
			B = B&&((St^stb[j]) != (St|stb[j]));
		} 
		if(not ((not A)or B)){
			have = true;
			//printf("|%d|\n",i);
			break;	
		}
	}
	if(not have)printf("YES\n");
	else printf("NO\n");
	}
 }

