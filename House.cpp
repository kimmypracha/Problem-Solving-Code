#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 2e5+10;
 typedef struct node{
 	int mn  ,mx , ans ; 
 };
 node seg[4*lim];
 int arr[lim];
 int n;
 void build(int p = 1 , int l = 0 , int r = n){
  	if(l == r){
		seg[p] = {arr[l] ,arr[l] ,0};
	}else{
		build(p<<1 , l , (l+r)/2);
		build(p<<1|1 , (l+r)/2 + 1 ,r);
		seg[p].ans = max(max(seg[p<<1].ans ,seg[p<<1|1].ans) , seg[p<<1|1].mx - seg[p<<1].mn);
		seg[p].mn = min(seg[p<<1].mn , seg[p<<1|1].mn);
		seg[p].mx = max(seg[p<<1].mx , seg[p<<1|1].mx);
	}
 }
 node rmq(int a , int b , int p = 1 , int l = 0 , int r = n){
  	if(r < a or l > b)return {0 , 0 ,-1};
	if(a <= l and r <= b)return seg[p];
	else{
		node p1= rmq(a , b ,p<<1,  l , (l+r)/2);
		node p2 = rmq(a , b ,p<<1|1,  (l+r)/2+ 1 , r);
		if(p1.ans == -1){
			return p2;
		}else if(p2.ans == -1){
			return p1;
		}else{
			node tmp;
			tmp.mn = min(p1.mn , p2.mn);
			tmp.mx = max(p1.mx , p2.mx);
			tmp.ans = max(max(p1.ans , p2.ans) , p2.mx - p1.mn);
			return tmp;	
		}
	}
 }
 int main(){
 	int m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&arr[i]);
		arr[i] += arr[i-1]; 
	}
	build();
	for(int i =0 ; i < m ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		printf("%d\n",(rmq(a,b+1)).ans);
	}
 }
