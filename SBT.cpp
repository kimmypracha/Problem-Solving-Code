#include <bits/stdc++.h>
#define sz(x) ( (x == NULL)? 0 : x->size)
 using namespace std;
typedef struct node{
	int key;
	int size;
	node *left, *right;
	node(int a) : key(a) , size(1) , left(NULL) , right(NULL) {};
};

void Search(node* t,  int A){
	if(t == NULL){
		printf("n\n");
		return;
	}
	if(t->key == A){
		printf("y\n");
		return;
	}else if(t->key > A){
		Search(t->left , A);
	}else{
		Search(t->right,  A);
	}
}

void maintain(node* &root){
	node *t , *a , *b , *c , *d ,*l , *r;
	if(root == NULL) return ;
	t = root;
	l = root->left;
	r = root->right;
	a = (l == NULL)? NULL :root->left->left;
	b =(l == NULL)? NULL  : root->left->right;
	c = (r == NULL)? NULL :	root->right->left;
	d = (r == NULL)? NULL : root->right->right;
	if( sz(a) > sz(r)){
		t->left = l->right;
		l->right = t;
		t->size = sz(t->left) + sz(t->right)  + 1;
		l->size = sz(l->left) + sz(l->right)  +1 ;
		root = l;
		maintain(root->right);
		maintain(root);
	}else if( sz(b) > sz(r)){
		l->right = b->left;
		b->left = l;
		t->left = b->right;
		b->right = t;
		l->size = sz(l->left) + sz(l->right)  +1 ;
		t->size = sz(t->left) + sz(t->right)  +1;
		b->size = sz(b->left) + sz(b->right) + 1;
		root = b;
		maintain(root->left);
		maintain(root->right);
		maintain(root);
	}else if(sz(c) > sz(l)){
		r->left = c->right;
		c->right = r;
		t->right = c->left;
		c->left = t;
		r->size = sz(r->left) + sz(r->right) + 1;
		t->size = sz(t->left) + sz(t->right) + 1;
		c->size = sz(c->left) + sz(c->right)  +1;
	        root = c; 
		maintain(root->left);
		maintain(root->right);
		maintain(root);
	}else if( sz(d) > sz(l)){
		t->right = r->left;
		r->left =  t;
		t->size = sz(t->left) + sz(t->right);
		r->size = sz(r->left) + sz(r->right);
		root = r;
		maintain(root->left);
		maintain(root);
	}
	return;
}
void Insert(node* &t , int A){
	if(t == NULL){
		t = new node(A);	
		return;
	}
	if(t->key == A) return;
	 if(t->key > A){
		Insert(t->left , A);
	}else {
		Insert(t->right , A);
	}
       maintain(t);
}
 int main(){
	node *root  = NULL;
 	int n , m ;
	scanf("%d%d",&n, &m);
	for(int i = 1 ; i <= n;  ++i){
		int A;
		scanf("%d",&A);
		Insert(root , A);
	}
	for(int i = 1 ; i <= m; ++i){
		int A;
		scanf("%d", &A);
		Search(root, A);
	}
 }
 
