#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)x.size();
 
 using namespace std;
 typedef pair<int,int> pii;
 typedef pair<char,int> pci;
 struct node{
	int par;
  	char dat;
	vector<int> nxt;
	node(): par(-1) , dat(NULL) , nxt() {};
	node(int x , char y , vector<int> z): par(x) , dat(y) , nxt(z) {};
 };
 vector<pci> all , his;
 vector<node> trie;
 vector<int> pos;	
 // HLD Declaration :: 
 void preprocess(){
	int idx = 0;
	int now = 0;
	trie.eb(-1, '\0' , vector<int>());
	pos.eb(0);
 	for(int i = 0 ; i < sz(his) ; ++i){
		char op;int x;
		tie(op,x) = his[i];
		if(op == 'T'){
			trie[now].nxt.eb(++idx);
			trie.eb(now , x , vector<int>());
			now = idx;			
		}else{
			now = pos[i-x]; // (i+1 - x - 1)
		}
		pos.eb(now);	
	} 
	// hld process :: 
 } 
   int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n ; ++i){
		char op;
		int x;
		scanf(" %c%d",&op,&x);
		if(op != 'P')
			all.eb(op,x);
		his.eb(op,x);
	} 
	preprocess();
	int now = 0;
	int _i = 0 ;
	for(auto p : all){
		char op; int x;
		tie(op,x)  = p;
		switch(op){
			case 'T': case 'U': 
				now = pos[_i];
				++_i; 
			break;
			case 'P' : 
				query(x);
			break;
		}
	}
   }
