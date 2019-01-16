#include <bits/stdc++.h>

  using namespace std;
 typedef struct node{
	int now;
	int st;
	node *left , *right;
	node(int x) : now(x) , st(1<<x) , left(NULL) , right(NULL) {};	
 };

 int main(){
	node *root = NULL;
	int n , c;
	scanf("%d%d",&n,  &c);
	for(int i = 0 ; i  < c ; ++i){
		int m , l , r;
		scanf("%d%d%d",&m , &l, &r);
		if(root == NULL){
		root = new node(m);
		root->left = new node(l);
		root->right = new node(r);
		root->st |= ((root->left->st)|(root->right->st));
		}else{
		Traverse(m, l , r);
		}
	}		
  }
