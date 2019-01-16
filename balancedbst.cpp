#include <bits/stdc++.h>
 
 using namespace std;
  struct node{
  	int val , pri;
 	node *l , *r;
	node(int a): val(a) , pri(rand()) , l(NULL) , r(NULL){};
  };
 void Split(node* t ,int val, node* &l , node* &r){
 	if(!t) l = r = NULL;
	else if(t->val < val){
		Split(t->r ,val ,  t->r , r) , l = t;
	}else{
		Split(t->l,val ,  l , t->l) , r = t;
	}
 }
  void Insert(node* &t , node* p){
	if(!t) t = p;
  	else if(p->pri > t->pri){
		Split(t ,p->val ,  p->l , p->r);
		t = p;
	}else{
		Insert(((t->val < p->val)? t->r : t->l) , p);
	}
  }
 bool Search(node* p , int x){
 	if(!p)return false;
	if(p->val == x)return true;
	if(p->val < x)return Search(p->r , x);	
	return Search(p->l , x);
 }
 void Print(node* p){
 	if(!p)return ;
	Print(p->l);
	printf("%d ",p->val);
	Print(p->r);
 }
  int main(){
	srand(time(NULL));
  	int n , m;
	scanf("%d%d",&n,&m);
	node* root = NULL;
	for(int i = 1 ; i <= n ; ++i){
		int A;
		scanf("%d",&A);
		if(not Search(root, A))
			Insert(root , new node(A));
//		Print(root);
//		printf("\n");
	}
	for(int i = 1 ; i <=m ; ++i){
		int X;
		scanf("%d",&X);
		if(Search(root , X)){
			printf("y\n");	
		}else printf("n\n");
	}
  }
