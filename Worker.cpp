#include <bits/stdc++.h> 
#define eb emplace_back
using namespace std;
 typedef struct node{
  int a , b ;
  long long int w;
  node(int x , int y , long long int z) : a(x) , b(y) , w(z) {};
  };
  const int lim = 1e3 + 10;
  int p[lim] = {};
 vector<node> el;
  long long int A[lim];
  int fh(int now){
return p[now] =  (now== p[now])? now : fh(p[now]);
  }
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i =1 ;  i <=n ; ++i){
		p[i] = i;
		long long int  T;
		scanf("%lld",&T);
		el.eb(0,i,T);	
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld",&A[i]);
	}
	for(int i= 1 ; i <= n ; ++i){
		for(int j = i + 1 ; j <= n ; ++j){
			el.eb(i , j , A[i] + A[j]);
		}
	}
	long long int ans = 0 ;
	sort(el.begin() , el.end() , [](const node &a , const node &b)->bool{return a.w < b.w;});
	for(int i = 0; i < el.size(); ++i){
		if(fh(el[i].a) != fh(el[i].b)){
			p[fh(el[i].a)] = fh(el[i].b);
			ans  += el[i].w;
		}
	}
	printf("%lld",ans);
 }
