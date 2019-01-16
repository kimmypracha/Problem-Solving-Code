#include <bits/stdc++.h>

 
 using namespace std;
  typedef struct node{
	int idx , rnd;
  	char dat;
	node *l ,*r;
	node(char x): idx(1) , dat(x) , l(NULL) , r(NULL) {
		srand(time(NULL);
		 rnd = rand();
	};
  };
  node* Insert(node* t ,node* &pl , node* &pr ,int sz, char key){
  	if(t->idx <= sz){
		t = Insert(t->l , t , pr ,sz , key);
	} 
  }
 int main(){
 	string A;
	cin >> A;
	node *root;
	for(int i =0 ; i < A.size() ; ++i){
		if(i == 0){
			root = new node(A[i]);
		}else{
			root = Insert(root ,root->l , root->r ,  A[i]);
		}
	}
 }
