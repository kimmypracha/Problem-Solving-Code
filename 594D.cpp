#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define ls(x) (x&(-x))
using namespace std;
 struct node{
  	int l , r , i;
 	node() : l(0) , r(0) , i(0){};
	node(int a,  int b ,int c): l(a) , r(b) , i(c) {};
 };
 typedef long long int lli;
 const int mxn =2e5+10;
 const int lim = 1e6+10;
 const lli mod = 1e9+7;
 int n; 
 lli arr[mxn];
 lli inv[lim];
 lli ft[mxn];
 int fre[lim] = {};
 bool Sieve[lim] = {};
 vector<int> lsp[lim]; 
 void update(int pos , lli v){
 	for( ; pos <= n ; pos += ls(pos)){
		ft[pos] *= v;
	}
 }
 lli rmq(int pos ){
	lli mul = 1;
 	for( ; pos ; pos -= ls(pos)){
		mul *= ft[pos];
		mul %= mod; 
	}
	return mul;
 }
 lli pw(lli now , lli p){
	if(p == 1) return now%mod;
 	lli tmp = pw(now , p/2);
	if(p&1)return (now*((tmp*tmp)%mod))%mod;
	else return (tmp*tmp)%mod;
 }
 lli qans[mxn];
 vector<node> que;
 int main(){
 	int q;
	scanf("%d",&n);
	fill(ft , ft + 1 + n , 1);
	for(int i = 2 ; i < lim ; ++i){
		if(Sieve[i])continue;
		lsp[i].eb(i);
		for(int j = 2*i ; j < lim ; j += i){
			lsp[j].eb(i);
			Sieve[j] = true;
		}
	}
	for(int i = 2;  i < lim ; ++i){
		inv[i] = pw(i,mod-2);
	}	
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld",&arr[i]);
	}
	scanf("%d",&q);
 	for(int i = 1 ; i <= q ; ++i){
		int  l ,r;
		scanf("%d%d",&l,&r);
		que.eb(l,r , i);
	}
	sort(que.begin() , que.end() , 
		[](const node &a , const node &b) -> bool{return a.l > a.l;});
	int now = n+1;
 	for(int i =0 ;  i < que.size() ; ++i){
		while(now > que[i].l){
			--now , update(now ,arr[now]);
			for(int j : lsp[arr[now]]){
				if(++fre[j] == 1){
					update(now , j-1);
					update(now , inv[j]);
				}
			}
			printf("%d : %lld\n",now , rmq(n));
		}
		qans[i] = rmq(que[i].r); 
	}
	for(int i = 1; i <= q ; ++i){
		printf("%lld\n",qans[i]);
	}
	printf(":: %lld",arr[7]*arr[8]*arr[9]*in)
 }
