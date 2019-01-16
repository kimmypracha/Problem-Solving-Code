#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  typedef pair<int,int> pii;
  struct node {
  	int u , v , w;
	node(int a , int b , int c): u(a) , v(b) , w(c) {}; 
  };
  const int mxn = 2e5+10;
 vector<node> edge;
 set<pii> st;
 set<int>
 int num[mxn];
  int main(){
  	int n , m , k , q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	edge.eb(0,0,0);
	for(int i = 1 ; i  <= m ; ++i){
		int a , b , w;
		scanf("%d%d%d",&a,&b,&w);
		edge.eb(a,b,w);	
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&num[i]);	
	}
	for()
	for(int i = 1;  i <= q ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);	
	}
  }
