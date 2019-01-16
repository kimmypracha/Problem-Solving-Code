#include <bits/stdc++.h>

 using namespace std;
  
  typedef struct node{
  	int now;
	node *next;
	node(int a): now(a) , next(NULL) {};
  };
  node *head = NULL , *curr; 
  void insert(int a){
	if(head == NULL){
		head = new node(a);
		curr = head;
	}else{
		curr->next = new node(a);
		curr = curr->next;
	}
  }
 void del(){
 	curr->now= curr->next->now; 
	curr->next = curr->next->next;
 }
 int main(){
 	int n, k  ;
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n; ++i  ){
		insert(i);
	}
	curr->next = head;
	curr = head;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j<= k-1 ; ++j){
			curr = curr->next;
		}
		printf("%d ",curr->now);
		del();
	
	}
 return 0 ; 
}
