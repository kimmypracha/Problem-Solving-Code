#include <bits/stdc++.h>
#define eb emplace_back
#define all(x) x.begin() , x.end()
 using namespace std;
  struct node{
  	int x, k , i;
	node(int a , int b , int c) : x(a) , k(b) , i(c) {};
  };
  const int lim = 1e5 + 10;	
  int arr[lim];
  vector<node> que;
  int main(){
  	int n , q;
	scanf("%d%d",&n,&q);
	for(int i =1 ;  i <= n ; ++i){	
		scanf("%d",&arr[i]);
	}
	for(int i =0  ; i < q ; ++i){
		int x , k;
		scanf("%d%d",&x,&k);
		que.eb(x,k,i);
	}
	sort(all(que) , [](const node &a , const node& b) -> bool {return (a.k ==  b.k)? a.x < b.x : a.k < b.k;});
	
  }
