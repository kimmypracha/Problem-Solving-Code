#include <bits/stdc++.h>
 
 using namespace std;
 typedef struct node{
  	int dat;
	node *l , *r;
	node(int a): dat(a) , l(NULL) , r(NULL) {};
 };
node *Med = NULL , *Head = NULL , *Curr = NULL;
 int main(){
  	int x;
 	int sz = 0 , mp = 0;
	while(scanf("%d",&x) != EOF){
		node *run;
		if(x == 0){
			printf("\n") , Head = Med = Curr = NULL;
			continue;
		}
		if(x == -1){
			printf("%d\n",Med->dat);
			if(sz == 1){
				sz = 0 ;
				Head = Med = Curr = NULL;
				continue;
			}
			node* tmp = Med->r;
			if(tmp == Curr) Curr = Med;
			Med->dat = tmp->dat;
			Med->r = tmp->r;
			if(Med->r != NULL)
				Med->r->l = Med;
			free(tmp);
			sz--;
			while(mp != sz/2 + (sz&1))--mp, Med = Med->l;
		}
		else if(Head == NULL){
			Head = Curr = Med = new node(x);
			sz = 1;
			mp = 1;
		}else{
			Curr->r = new node(x);
			node *tmp = Curr->r;
			tmp->l = Curr;
			Curr = Curr->r;
			sz++;
			while(mp != sz/2+(sz&1))mp++,Med = Med->r;
		}
	//	run = Head;
	//	while(run != NULL){
	//		printf("%d ",run->dat);
	//		run = run->r;
	//	}
	//	printf("\n");
	}
 }
