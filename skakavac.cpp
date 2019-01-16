#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
 using namespace std;
 const int lim = 1500;
 const int llim = 1500*1500;
 typedef pair<int,short > pis;
 typedef pair<short,short> pss;
 typedef struct node{
 	int val;
	short x , y;
	node(int a, int b , int c): val(a) , x(b) , y(c) {};
 };
 int Max;
 int n;
 int arr[lim][lim];
 vector<pis> L[lim] , U[lim];
 pss Ord[llim];
 int lz[llim];
 void update(node t){
 	L[t.x].eb( t.val , t.y);
	U[t.y].eb( t.val , t.x);
	sort(L[t.x].begin() , L[t.x].end() ,greater<pis>());
	sort(U[t.y].begin() , U[t.y].end() ,greater<pis>());
	if(L[t.x].size() > 4)L[t.x].pop_back();
	if(U[t.y].size() > 4)U[t.y].pop_back();
 }
 void v_get(short x , short y){
 	Max = -1;
	if(x-1>= 0 and not L[x-1].empty()){
		for(pis i : L[x-1]){
			if(abs(i.se - y) > 1){
				Max = max(i.fi , Max);
				break;
			}
		}	
	}
	
	if(x+1 < n and not L[x+1].empty()){
		for(pis i : L[x+1]){
			if(abs(i.se - y) > 1){
				Max = max(i.fi , Max);
				break;
			}
		}
	}
	if(y-1 >=0 and not U[y-1].empty()){
		for(pis i : U[y-1]){
			if(abs(i.se - x) > 1){
				Max = max(Max , i.fi);
				break;
			}
		}
	}
	if(y +1 < n and not U[y+1].empty()){
		for(pis i : U[y+1]){
			if(abs(i.se - x) > 1){
				Max = max(Max , i.fi);
				break;
			}
		}
	}
 }
 int main(){
 	int  r , c;
	scanf("%d%d%d",&n,&r,&c);
	r--;
	c--;
	for(int i = 0 ; i < n;  ++i){
		for(int j = 0 ; j < n ; ++j){
			scanf("%d",&arr[i][j]);	
			Ord[i*n + j] =  { (short)i,  (short)j };
		}
	}
	sort(Ord , Ord + n*n , [=](const pss &a ,  const pss &b) -> bool {return arr[a.fi][a.se] < arr[b.fi][b.se];});
	int Ans = 1;
	int now = 0 ;
	pss i;
	for(int idx = 0 ; idx < n*n;  ++idx){
		i = Ord[idx];
		lz[idx] = -1;
		if(i.fi == (short)r and i.se ==(short) c){
			lz[idx] = 1;
		}else{
			v_get(i.fi,i.se);
			if(Max != -1){
	//			printf("%d in %d %d from %d\n" , arr[i.fi][i.se] , i.fi  , i.se , Max);
	//			printf("%d in %d %d from %d\n" , arr[i.fi][i.se] , i.fi  , i.se , Max);
				Ans = max(Ans, Max+1);
				lz[idx] = Max+1;
			}
		}
		if((idx + 1 < n*n and arr[Ord[idx].fi][Ord[idx].se] != arr[Ord[idx+1].fi][Ord[idx+1].se])or idx == n*n-1 ){
			for(; now <= idx; now++){
			if(lz[now] != -1)
				update({lz[now] , Ord[now].fi , Ord[now].se});
			}
		}
	}
	printf("%d",Ans);
 }
