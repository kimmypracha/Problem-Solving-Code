#include <bits/stdc++.h>
 
 using namespace std;
  typedef long long int lli;
  const int lim = 110;
  const int mxn = 1e6+10;
  lli Sum[lim] = {};
  lli arr[lim][lim];
  int main(){
  	int N , L , Q;
	scanf("%d%d%d",&N,&L,&Q);
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= L ; ++j){	
			arr[i][j] = j;
		}
		arr[i][0] = L;
		for(int i)
	}
	for(int i = 0 ; i <= L ; ++i){
		if(i == 0) Sum[i] = (lli)(L)*(lli)N;
		else Sum[i] = (lli)(i)*(lli)N;
	}
	for(int i = 0 ; i < Q ; ++i){
		char c;
		int a , b;
		scanf(" %c%d",&c,&a);
		if(c == 's'){
			scanf("%d",&b);
			for(int j = pos[a]+1 ; j <= L ; ++j){
			//	printf("%d : %d \n",j,j-pos[a]);
				Sum[j] -= lli(j-pos[a]);
			}
			for(int j = 0 ; j <= pos[a]; ++j){
			//	printf("%d : %d\n",L-(pos[a]-j));
				Sum[j] -= lli(L-(pos[a]-j));
			}
			pos[a] = (pos[a] + b)%L;
			for(int j = pos[a]+1 ; j <= L ; ++j){
				Sum[j] += lli(j-pos[a]);
			}
			for(int j = 0 ; j <= pos[a] ; ++j){
				Sum[j] += lli(L-pos[a]+j);
			}
		}else if(c == 'q'){
			printf("%lld\n",Sum[a]);
		}
	}
	
  }
