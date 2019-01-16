#include <bits/stdc++.h>
#define eb emplace_back 
 using namespace std;
  typedef struct node{
  	int x , y , i;
	node(int a,  int b , int c) : x(a), y(b) , i(c) {};
  };
  vector<node> vi;
  int main(){
  	int n , x;
	scanf("%d%d",&n,&x);
	for(int i = 1 ; i <= n ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		vi.eb(a,b,i);
	}
	sort(vi.begin() , vi.end() ,
	[](const node &a , const node &b)->bool{return (a.x == b.x)? a.y > b.y : a.x < b.x;});
	for(int i = 1 ; i  < n ; ++i){
		if(vi[i-1].x == vi.[i].x )vi[i-1].x = 2e9;
	}
	sort(vi.begin() , vi.end() ,
	[](const node &a , const node &b)->bool{return a.x < b.x;});
	while(vi.back().x == 2e9)vi.pop_back();
	int m = vi.size();
	for(int i = 0 ; i < m-1 ; ++i){
		findmx(vi[i] , vi[i+1]);	
	}
  }
