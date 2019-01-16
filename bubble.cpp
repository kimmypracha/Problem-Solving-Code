#include <bits/stdc++.h>
#define ls(x) (x&(-x))
#define eb emplace_back
#define all(x) x.begin() , x.end()
  using namespace std;
   struct node{
   	int x , k , i;
	node(): x(0), k(0) , i(0) {};
	node(int a , int b , int c): x(a), k(b),i(c){};
   };
   const int lim = 1e5+10;
   int arr[lim];
   int ft[lim];
   vector<node> que;
   vector<int> vi;
   void update(int pos , int val){
  	for( ; pos <= n ; pos += ls(pos)){
		ft[pos] += val;
	} 
   }
   int rmq(int pos){
	int sum = 0;
	for(; pos ; pos -= ls(pos)){
		sum += ft[pos];
	}
	return sum;	
   }
   int main(){
   	int n , q;
	scanf("%d%d",&n,&q);
	vi.eb(0);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&arr[i]);
		vi.eb(arr[i]);
	}
	for(int i = 1 ; i <= q ; ++i){
		int x , k;
		scanf("%d%d",&x,&k);
		que.eb(x,k,i);
	}
	sort(all(que) ,[](const node &a , const node &b)->bool {return (a.k == b.k)? a.x < b.x : a.k < b.k;});
	for(int i =0  ; i <)
   }
