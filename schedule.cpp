#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef struct node{
 	int s ,f , i; 
	node(int a ,int b , int c): s(a) , f(b) , i(c) {};
 };
 const int lim = 5e5 + 10;
 vector<node> vi;
 int ans[lim] = {};
 priority_queue<int, vector<int> , greater<int> > pq; 
int main(){
 	int n , m , k;
	scanf("%d%d%d",&n,&k,&m);
	for(int i = 0 ; i < n; ++i){
		int s, f;
		scanf("%d%d",&s,&f);
		vi.eb(s,f,i);
	}
	int sur = 0 ;
	sort(vi.begin() , vi.end() , [](const node &a , const node &b) -> bool {return a.s < b.s;});
	for(int i = 0 ; i < vi.size() ; ++i){
		while(not pq.empty() and pq.top() < vi[i].s)pq.pop() , sur--; 
		if(sur < k) pq.push(vi[i].f) ,sur++ , ans[vi[i].i] = 1;
	}
	for(int i =0 ; i < m ; ++i){
		int x;
		scanf("%d",&x);
		printf("%c ",(ans[x-1])? 'Y': 'N');
	}
 } 
