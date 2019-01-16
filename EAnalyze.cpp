#include <bits/stdc++.h>
#define eb emplace_back 
using namespace std;
typedef struct node {
	int a , b , w;
	node(int x , int y , int z): a(x) , b(y) , w(z) {}; 
};
 const int lim  = 1e3+10;
 int par[lim];
 vector<node> el;
 int Fh(int now){
	return par[now] = (now == par[now])? now : Fh(par[now]);
 }
 int main(){
	int n;
	int cnt = 0; 
	scanf("%d", &n);
	for_each(par , par + n ,[&cnt](int& a){a = cnt++;}  );
	for(int i =0 ;  i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			if(i == j )continue;	
			el.eb(i , j , i^j);
		}
	}	
	int ans = 0 ;
	sort(el.begin() , el.end() , [](const node &a , const node &b) -> bool {return a.w < b.w ;});
	for(node i : el){
		if(Fh(i.a) != Fh(i.b)){
			par[Fh(i.a)] = Fh(i.b);
			ans += i.w;
		}	
	}
	printf("%d",ans);
 }
