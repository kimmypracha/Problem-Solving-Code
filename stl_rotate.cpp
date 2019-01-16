#include <bits/stdc++.h>
#define idx(x) ((x->l == NULL)? 1 : x->l->cnt + 1 )
#define sz(x) ((x == NULL)? 0 :  x->cnt)
 using namespace std;
 typedef struct node{
 	int dat;
	int rnd;
	int cnt;
	int rev;
	node *l, *r;
	node(char a): dat(a) , cnt(1) , rev(0), l(NULL) , r(NULL){
		rnd = rand();
	};
 };
 void push(node* t){
 	if(!t) return;
	if(t->rev == 0) return ; 
		swap(t->l , t->r);
	if(t->l != NULL) t->l->rev ^= 1;
	if(t->r != NULL) t->r->rev ^= 1;
	t->rev = 0 ;
 }
void print(node* t){
	if(!t)return;
	push(t);
	print(t->l);
 	printf("%d ",t->dat);
	print(t->r);
 }
 void split(node* t , node* &l , node* &r ,int key , int add = 0){
 	push(t);
	if(!t) l = r = NULL;
	else if(add + sz(t->l) < key){
		split(t->r , t->r , r , key , add + idx(t) ) , l = t;
	}else split(t->l , l , t->l , key , add) , r = t;
	if(t) t->cnt = sz(t->l) + sz(t->r) + 1;
 }
 void merge(node* &t , node* l , node* r){
 	push(l);
	push(r);
	if(not l or not r) t = (not l)? r : l;
	else if(l->rnd < r->rnd){
		merge(l->r , l->r , r) , t = l;
	}else
		merge(r->l , l , r->l) , t = r;
	if(t) t->cnt = sz(t->l) + sz(t->r) + 1;
 }
 void reverse(node* t , int l , int r){
 	node *t1 , *t2 , *t3;
	split(t , t1 , t2 , l-1);
	split(t2 , t2 , t3 , r-l + 1);
	if(t2 != NULL)
	t2->rev ^= 1;
//	printf("T1 : \n");
//	print(t1);
//	printf("\nT2 : \n");
//	print(t2);
//	printf("\nT3 : \n");
//	print(t3);	
//	printf("\n");
	merge(t , t1 , t2);
	merge(t , t , t3);
 }
 int str[100010] , ins[100010];
 int main(){
	node *root = NULL , *t1 , *t2 , *t3 , *t4;
	srand(time(NULL));
	int n;
	scanf("%d" , &n);
	for(int i =0 ;  i < n ; ++i){
		scanf("%d",&str[i]);
	}
 	int q;
	scanf("%d",&q);
	for(int i =0 ;   i < n;  ++i){
		if(i == 0){
			root = new node(str[i]);
		}else{
			split(root , t1 , t2 , i+1);
			merge(t1 , t1 , new node(str[i]));
			merge(root , t1 , t2);	
		}
 	}
 	char op[2] ;
	for(int i = 0 ; i < q ; ++i){
		int l , m , r;
		scanf("%d%d%d",&l,&m,&r);
		split(root , t1 , t2 , l);
		split(t2 , t2 , t3 , (r-l));
		split(t2 , t2 , t4 , m-l);
		merge(root , t1 ,t4);
		merge(root , root , t2);
		merge(root , root , t3);
		
	//	print(root);
	//	printf("\n");
	}
	print(root);
	printf("\0");
}

