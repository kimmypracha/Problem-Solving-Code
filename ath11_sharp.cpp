#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
  typedef pair<int,int> pii;
  vector<pii> vi;
  bool cut(pii p1 , pii p2){
		pii u ,v ,w;
		v = vec(p2,p1);
		u = vec(v[0] ,p1);
		w = vec(v.back() ,p1);
		if(cross(v,u) != cross(v,w))return true;
		int l = 0 , r = n-2;
		int m;
		while(l < r){
			m = (l+r)/2;
			u = vec(v[m],p1);
			w = vec(v[m+1],p1);
			int a1 = cross(v,u);
			int a2 = cross(v,w);
			if(a1 != a2)return true;
			if(a1 < 0 )r = m;
			else l = m+1;
		}
  }
  int main(){
 	int n , m;
	scanf("%d%d",&n,&m);
	for(int i  = 0 ; i < n ; ++i){
		int a  ,b;
		scanf("%d%d",&a,&b);
		vi.eb(a,b);
	} 
	for(int i = 0; i < m ; ++i){
		int a ,b , c ,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		cut(pii(a,b) , pii(c,d));
	} 
 }
