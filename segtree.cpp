#include <bits/stdc++.h>

  using namespace std;
  const int lim = 1e5 + 10;
  int Arr[lim];
  int Seg[4*lim];
  int N;
  void Build(int p = 1 , int l =  0 , int r = N-1){
	if(l == r){
		Seg[p] = Arr[l];
	}else {
		Build(p<<1 ,l , (l+r)/2 );
		Build(p<<1|1 , (l+r)/2 + 1 , r) ;
		Seg[p] = min(Seg[p<<1],Seg[p<<1|1]); 
	}	
  }
 int RMQ(int a , int b , int p = 1  , int l = 0  , int r = N-1){
 	if(b < l or a > r)return 1e9;
	if(a<=l and r <=b) return Seg[p];
	else{
		int p1 = RMQ(a ,b , p<<1 ,l , (l+r)/2 );
		int p2 = RMQ(a , b , p<<1|1 , (l+r)/2 + 1 , r);
		return min(p1,p2);
	}
 }
 void update(int x ,int v, int p = 1 , int l = 0 , int r = N-1){
 	if(x < l or x > r) return ;
	if(l == r and l == x) Seg[p] = v;
	else {
		update(x,v,p<<1, l, (l+r)/2);
		update(x,v,p<<1|1 , (l+r)/2 + 1 ,r);	
		Seg[p] = min(Seg[p<<1] , Seg[p<<1|1]);
	}   
 }
  int main(){
	scanf("%d",&N);
	for(int i =0 ;  i < N ; ++i){
		scanf("%d",&Arr[i]);
	} 
	Build();
	int Q;
	scanf("%d",&Q);
	for(int i= 0 ; i < Q; ++i){
		string A;
		cin >> A;
		if(A == "CHANGE"){ // change Arr[idx] to val
			int idx , val ;
			scanf("%d%d",&idx,&val);
			Arr[idx] = val;
			update(idx,val);
		}
		else if(A == "MIN"){ 	//Find Minimum Value in Range [a,b]
			int a, b;
			scanf("%d%d",&a,&b);
			int ans = RMQ(a,b);
			printf("%d",ans);
		}
	}
 }
