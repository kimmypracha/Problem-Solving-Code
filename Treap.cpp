#include <bits/stdc++.h>
#define idx(x) ((x->l == NULL)? 1 : x->l->cnt + 1 )
#define sz(x) ((x == NULL)? 0 :  x->cnt)
 using namespace std;
 typedef struct node{
 	char dat;
	int rnd;
	int cnt;
	int rev;
	node *l, *r;
	node(char a): dat(a) , cnt(1) , rev(0), l(NULL) , r(NULL){
	//	srand(time(NULL));
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
 	printf("%c",t->dat);
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
 char str[100010] , ins[100010];
 int main(){
	node *root = NULL , *t1 , *t2;
	srand(time(NULL));
	scanf("%s" , str);
 	int q;
	scanf("%d",&q);
	int n = strlen(str);
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
		scanf("%s",op);
		if(op[0] == 'I'){
			int x;
			scanf("%d%s",&x ,ins);
			int s = strlen(ins);
			node *nr = NULL , *a1 , *a2;
			nr = new node(ins[0]);
			for(int j = 1 ; j < s ; ++j){
				split(nr , a1 , a2 ,j);
				merge(a1 , a1 , new node(ins[j]));
				merge(nr ,a1 , a2  );
			} 
			split(root , t1 , t2 , x);
			merge(t1 , t1 , nr);
			merge(root , t1 , t2);
		}else{
			int l , r;
			scanf("%d%d",&l,&r);
			reverse(root , l , r);
		}
	//	print(root);
	//	printf("\n");
	}
	print(root);
	printf("\0");
}
