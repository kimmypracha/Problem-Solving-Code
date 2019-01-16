#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 typedef struct node{
 	int a , b , c;
	node(): a(0), b(0) , c(0){};
	node(int x, int y , int z): a(x) , b(y) , c(z) {}; 
 };
 const int lim = 1e6+10;
 char str[lim];
 int arr[lim] = {};
 int n;
 node seg[4*lim];
 void build(int p =1 , int l = 1 , int r = n){
 	if(l == r){
		seg[p] = (str[l] == '(')? node(0 , 1 , 0) : node(0 , 0 , 1);
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 ,(l+r)/2+1 , r);
		node p1 =seg[p<<1];
		node p2 = seg[p<<1|1];
		int t = min(p1.b , p2.c);
		int a = p1.a + p2.a + t;
		int b = p1.b + p2.b - t;
		int c = p1.c + p2.c - t;
		seg[p] = node(a ,b , c);
	}
//	printf("%d %d %d : %d %d %d\n",p , l , r,  seg[p].a , seg[p].b , seg[p].c);
 }
 node rmq(int L , int R , int p = 1 , int l = 1 ,int r = n){
//	printf("%d %d : %d %d\n", L , R , l , r);
 	if(r < L or R < l)return node(0 , 0 , 0);
	if(L <= l and r <= R){
//		printf("%d %d : %d %d %d\n",l ,r , seg[p].a , seg[p].b , seg[p].c);
		return seg[p];
	}else{
		node p1 = rmq(L , R , p<<1 , l , (l+r)/2);
		node p2 = rmq(L , R , p<<1|1 , (l+r)/2+1 , r);
		int t = min(p1.b , p2.c);
		int a = p1.a + p2.a +t;
		int b = p1.b + p2.b -t;
		int c = p1.c + p2.c -t;
//		printf("%d %d : %d %d %d\n", l , r , a , b , c);
		return node(a, b, c);
	}
 }
 int main(){
  	scanf("%s",str+1);
	n = strlen(str+1);
	int m;
	scanf("%d",&m);
	for(int i = 1 ; i <=n  ; ++i){
		arr[i] = (str[i] == '(')? 1 : -1;
		arr[i] += arr[i-1];
	}
	build();
	for(int i = 0 ; i < m ; ++i){
		int l  , r;
		scanf("%d%d",&l , &r);
		node ans = rmq(l , r);
		printf("%d\n",2*ans.a);
	}
 }
