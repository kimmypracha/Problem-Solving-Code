#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
  const int lim = 1e5+10;
  struct node{
  	int val , pri,cnt;
	node *left,  *right;
	node(int a): val(a) , pri(rand()) , left(NULL) , right(NULL) , cnt(1){};
  };
  int cnt(node* p){
 	return (p)? p->cnt : 0;
  }
  vector<node*> vi;
  void update(node* p){
  	if(p)
		p->cnt = 1 + cnt(p->left) + cnt(p->right);
  }
  void Split(node* p ,int val, node* &l , node* &r){
  	if(!p)l = r = NULL;
	else if(p->val < val)Split(p->right ,p->right , r),l = p;
	else Split(p->left , l , p->left) , r = p;
	update(p);
  }
  void Merge(node* &p , node* l , node* r){
   	if(!l or !r)p = (l)? l : r;
	else if(l->pri > r->pri){
		Merge(l->right , l->right , r); p = l;
	}else{
		if(r->val > l->val)
		Merge(r->left , l , r->left); p =r;
	}
	update(p);
  }
  int Search(node* p , int stu){
//	printf("::%d\n",p->val);
	if(p->val == stu) return cnt(p->left) + 1;
  	if(p->val > stu) return Search(p->left , stu);
	else return cnt(p->left) + 1 + Search(p->right , stu);
  }
  int par[lim];
  int fh(int now){
  return par[now] = (now == par[now])? now : fh(par[now]); 
 }
  void print(node* p){
  	if(!p)return;
	print(p->left);
	printf("%d ",p->val);
	print(p->right);
  }
  int main(){
	int t;
	scanf("%d",&t);
	srand(time(NULL));
	while(t--){
		vi.clear();
  		int n,l;
		scanf("%d%d",&n,&l);
		vi.eb(new node(0));
		for(int i = 1 ; i <= n ; ++i){
			vi.eb(new node(i));
			par[i] = i;
		}
		for(int i =0 ; i < l ; ++i){
			int k;
			scanf("%d",&k);
			if(k == 1){
				int x , y;
				scanf("%d%d",&x,&y);
				if(vi[x]->val < vi[y]->val)
					Merge(vi[x] , vi[x] , vi[y]);
				else Merge(vi[x] , vi[y] ,vi[x]);
				print(vi[x]);
				printf("\n");
				par[fh(y)] = fh(x);
				
			}else{
				int j;
				scanf("%d",&j);
			//	printf("par %d is %d",j , par[j]);
		//		printf("%d\n",cnt(vi[fh(j)]) - Search(vi[fh(j)] , j)+1);
			}
		}
	}
  }
