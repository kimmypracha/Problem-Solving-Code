#include <bits/stdc++.h>
#define ls(x) (x&(-x))
 using namespace std;
 const int lim = 2e5+10;
 int n;
 int ft[lim] ={};
 void update(int pos , int val){
 	for(; pos <= n ; pos += ls(pos)){
		ft[pos] += val;
	}
 }
 int rmq(int pos){
	int sum = 0 ;	
 	for(; pos ; pos -=ls(pos)){
		sum += ft[pos];
	}
	return sum;
 }
  int main(){
  	int  m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ;++i){
		int a ,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a == 1){
			update(c,b);	
		}else{
			printf("%d\n",rmq(c)-rmq(b-1));
		}
	}
  }
