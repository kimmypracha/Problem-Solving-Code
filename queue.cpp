#include <bits/stdc++.h> 
#define ls(x) (x&(-x))
 using namespace std;
 const int lim = 2e5+10;
 const int n = 1e5;
 int m;
 int ft[lim] = {};
 int no[lim] = {};
 int idx[lim] = {};
 int rmq(int pos){
 	int sum = 0;
 	for(;pos; pos -= ls(pos)){
		sum += ft[pos];
	}
	return sum;
 }
 int find(int val){
 	int l = 1 , r = n+1;
	int m;
	while(l < r){
		m = (l+r)/2;
		if(rmq(m) >= val){
			r = m;	
		}else{
			l = m+1;
		}
	}
	return l;
 }
 void update(int pos , int val){
	for( ; pos <= n ; pos += ls(pos)){
		ft[pos] += val;
	}	
 }
 int main(){
  	int m;
	scanf("%d",&m);
	int cnt =1 ;
	for(int i =0 ;  i <  m ; ++i){
		int c;
		scanf("%d",&c);
		switch(c){
			case 1 :
			{
				int p;
				scanf("%d",&p);
				idx[cnt] = p;
				no[p] = cnt++;
				update(p , 1);
			}
				break;
			case 2 :
			{
				int pos = find(1);
				printf("%d\n",no[pos]);
				idx[no[pos]] = 0;
				no[pos] = 0; 
				update(pos , -1);
			}
				break;
			case 3 :
			{
				int q;
				scanf("%d",&q);
				int peo = rmq(idx[q]);
				printf("%d\n",peo-1);
			}
				break;	
		}
	}
  }
