#include <bits/stdc++.h>
 
 using namespace std;
  const int lim = 1<<18;
 int seg[2*lim];
 void update(int pos){
 	pos >>=1 ;
	int st = 0;
	for(; pos; pos>>=1 ){
		seg[pos] = (st)? (seg[pos<<1]^seg[pos<<1|1]) : (seg[pos<<1]|seg[pos<<1|1]);
		st ^= 1;
	}
 }
  int main(){
  	int n  ,m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < (1<<n) ; ++i){
		scanf("%d",&seg[(1<<n) + i]);
	}
	int st = 0;
	int lft = (1<<(n-1));
	int mx = lft;
	for(int i = (1<<n)-1 ; i >= 1 ; --i) {
		if(lft == 0){
			lft = mx>>1;
			mx >>= 1;
			st ^= 1;	
		}
		if(st == 0){
			seg[i] = seg[i<<1]|seg[i<<1|1];
		}else{
			seg[i] = seg[i<<1]^seg[i<<1|1];
		}
		lft--;
	}
//	printf(":: %d %d %d\n", seg[1] , seg[2] , seg[3]);
	for(int i = 0 ; i < m ; ++i){
		int p , b;
		scanf("%d%d",&p,&b);
		p--;
		seg[(1<<n) + p] = b;
		update((1<<n) + p);
		printf("%d\n",seg[1]);
	}
 }
