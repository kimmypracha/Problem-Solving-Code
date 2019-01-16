#include <bits/stdc++.h>

  using namespace std;
  const int lim = 1e6+10;
  struct node{
  	int m4 , m47,m74,  m7;	
	node(): m4(0) , m47(0) , m74(0) ,m7(0) {};
	node(int a , int b , int c , int d): m4(a) , m47(b) , m74(c) , m7(d){};
  };
  node seg[4*lim];
  int lz[4*lim] = {};
  int n;
  string A;
  void build(int p = 1 , int l = 0 , int r = n-1){
  	if(l == r){
		seg[p] = (A[l] == '4')? node(1,1,1,0) : node(0,1,1,1);
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 , r);
		seg[p].m4 = seg[p<<1].m4 + seg[p<<1|1].m4; 
		seg[p].m7 = seg[p<<1].m7 + seg[p<<1|1].m7;
		seg[p].m47 = max(max(seg[p<<1].m4 + seg[p<<1|1].m47,seg[p<<1].m47 + seg[p<<1|1].m7) , seg[p<<1].m4 + seg[p<<1|1].m7);
		seg[p].m74 = max(max(seg[p<<1].m7 + seg[p<<1|1].m74,seg[p<<1].m74 + seg[p<<1|1].m4) , seg[p<<1].m7 + seg[p<<1|1].m4);
	}
  }
  void update(int a , int b , int p = 1 , int l = 0 , int r = n-1){
  	if(lz[p] != 0){
		swap(seg[p].m4 , seg[p].m7);
		swap(seg[p].m47 , seg[p].m74);
		if(l!=r){
			lz[p<<1] ^= 1;
			lz[p<<1|1] ^= 1;
		}
		lz[p] = 0;
	}
	if(r < a or l > b)return;
	if(a <= l and r <= b){
		swap(seg[p].m4 , seg[p].m7);
		swap(seg[p].m47 , seg[p].m74);
		if(l != r){
			lz[p<<1] ^= 1;
			lz[p<<1|1] ^= 1;
		}
	}else{
		update(a , b,  p<<1 , l , (l+r)/2);
		update(a,b,p<<1|1 , (l+r)/2 + 1 , r);
		seg[p].m4 = seg[p<<1].m4 + seg[p<<1|1].m4;
		seg[p].m7 = seg[p<<1].m7 + seg[p<<1|1].m7;
		seg[p].m47 = max(max(seg[p<<1].m47 + seg[p<<1|1].m7 , seg[p<<1].m4 + seg[p<<1|1].m47) , seg[p<<1].m4 + seg[p<<1|1].m7);
		seg[p].m74 = max(max(seg[p<<1].m74 + seg[p<<1|1].m4 , seg[p<<1].m7 + seg[p<<1|1].m74) , seg[p<<1].m7 + seg[p<<1|1].m4);
	}
  }
  int main(){
  	int m;
	scanf("%d%d",&n,&m);
	cin >> A;
	build();
	for(int i =0  ; i < m ; ++i){
		string s;
		cin >> s;
		if(s == "switch"){
			int a , b;
			scanf("%d%d",&a,&b);
			a-- , b--;
			update(a,b);
		}else{
			//printf("%d %d %d %d\n",seg[1].m4 , seg[1].m47,seg[1].m74 , seg[1].m7);
			printf("%d\n",seg[1].m47);
		}
	}
  }
