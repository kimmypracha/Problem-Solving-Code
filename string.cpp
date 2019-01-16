#include <bits/stdc++.h>

 using namespace std;
 const int lim = 1e5  + 10;
 char str[lim];
 class rope{
  	public: 
		int sl;
		int si;
		char let;
		rope *l , *r;
		int rs;
		int h;
		rope *par;
		rope(char x): sl(1) , let(x) , l(NULL) , r(NULL) , rs(1),par(NULL) , h(1) , si(1) {};
 };
  int getbal(rope* p){
 	int L = (p->l == NULL)? 0 : p->l->h;
	int R = (p->r == NULL)? 0 : p->r->h;
	p->h = max(L , R) +1;
	return L-R;
  }
  void getsiz(rope* p){
  	int L = (p->l == NULL)? 0 : p->l->si;
	int R = (p->r == NULL)? 0 : p->r->si;
	p->si = L + R;
	p->sl = L;
  }
 rope* lr(rope* p){
 	rope *tmp = p->r;
	p->r = tmp->l;
	tmp->l = p;
	getsiz(p);
	getbal(p);
	getsiz(tmp);
	getbal(tmp);
	return tmp;
 }
 rope* rr(rope* p){
 	rope *tmp = p->l;
	p->l = tmp->r;
	tmp->r = p;
	getsiz(p);
	getbal(p);
	getsiz(tmp);
	getbal(tmp);
	return tmp;
 }
 rope* balance(rope* p ){
 	if(p == NULL) return p;
	int bal = getbal(p);
	int LL = (p->l->l == NULL)? 0 : p->l->l->h;
	int LR = (p->l->r == NULL)? 0 : p->l->r->h;
	int RL = (p->r->l == NULL)? 0 : p->r->l->h;
	int RR = (p->r->r == NULL)? 0 : p->r->r->h;
	if(bal > 1 and LR > LL){
		p->l = lr(p->l);
	}else if(bal <  -1 and RL > RR){
		p->r = rr(p->r);
	}
	if(bal > 1){
		p = rr(p);
	}else if(bal < -1){
		p = lr(p);
	}
	return p;
 }
 rope* concat(rope* a , rope*b){
 	rope* tmp = new rope('\0');
	a->par = b->par = tmp;
	tmp->l = a ;
	tmp->r = b;
	tmp->sl = a->si;
	tmp->si = a->si + b->si;
	tmp->h = max(a->h, b->h)  +1;
	int bal;
	while(bal = getbal(tmp) , (bal < -1 or bal > 1)){
	tmp = balance(tmp);
	}
	return tmp;
 }
 rope* Insert(rope* p , char x , int idx){
 	if(p == NULL)return new rope(x);
	if(p->rs != 1){
		p->rs = 1;
		if(p->l != NULL) p->l->rs  *= -1;
		if(p->r != NULL) p->r->rs *= -1;
		swap(p->l , p->r);
		p->sl = (p->l == NULL)? 0 : p->l->si;
	}
	if(idx < p->sl){
		p->l = Insert(p->l , x , idx);
	}else{
		p->r = Insert(p->r , x , idx-p->sl);
	}
	balance(p);
 }
 int main(){
	scanf("%s",str);
	int len  = strlen(str);
	int M;
	rope *Head = NULL;
	for(int i = 0 ; i < len ; ++i){
		if(Head == NULL){
			Head = new rope(str[i]);
		}else {
			Head = concat(Head , new rope(str[i]));
		}
	}
	scanf("%d",&M);
	while(M--){
	
	}
  }
 
