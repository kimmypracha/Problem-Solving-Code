#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin() , x.end()
 using namespace std;
 typedef pair<int,int> pii;
 int war[11][11];
 vector<int> As , Bs;
 vector<pii> El;
 int k; 
 int ssp(int a , int b){
 	int ans =0  ;
	if(a > (1<<k ) and b > (1<<k)){
		a-= (1<<k);
		b-= (1<<k);
	}
	while(a != b){
		if(a < b)++ans , b>>=1;
		else ++ans, a>>=1;
	}
	return ans;
 }
 int main(){
  	int  L , Q;
	scanf("%d%d%d",&k,&L,&Q);
	for(int i =0 ; i  < 11 ; ++i)for(int j = 0 ; j < 11 ; ++j)war[i][j] = 1e8;
	for(int i = 0 ; i < L ; ++i){
		int A , B;
		scanf("%d%d",&A,&B);
		As.eb(A);Bs.eb(B);
		El.eb(A,B);
	}
	sort(all(As));
	sort(all(Bs));
	As.resize(unique(all(As)) - As.begin());
	Bs.resize(unique(all(Bs)) - Bs.begin());
/*	printf("As : \n");
	for(int i : As)printf("%d ",i);
	printf("\nBs :\n");
	for(int i : Bs)printf("%d ",i);
	printf("\n");*/
	for(pii i : El){
		int p1 = lower_bound(all(As) , i.fi) - As.begin();
		int p2 = lower_bound(all(Bs) , i.se) - Bs.begin() + (int)As.size();
//		printf("%d %d\n",p1 ,p2);
		war[p1][p2] = war[p2][p1] = 1;
	}
	
	for(int i = 0 ; i < As.size() ; ++i){
		for(int j = i+1 ; j < As.size() ; ++j){
			war[i][j] = war[j][i] = ssp(As[i] , As[j]);
		}
	}
	L = (int)As.size();
	for(int i = 0 ; i  < Bs.size() ; ++i){
		for(int j = i+ 1 ; j < Bs.size() ; ++j){
			war[i+L][j+L] = war[j+L][i+L] = ssp(Bs[i] , Bs[j]);
		}
	}
	int S = (int)As.size() + (int)Bs.size();
	for(int i =0  ; i < S ; ++i){
		for(int j = 0 ; j < S  ;++j){
			for(int l =  0;  l < S ; ++l){	
				war[j][l] = min(war[j][l] , war[j][i] + war[i][l]);
			}
		}
	}
	for(int i = 0 ; i < Q ; ++i){
		int A , B;
		scanf("%d%d",&A,&B);
		int ans = 1e8;
		if((A < (1<<k) and B < (1<<k)) or (A > (1<<k) and B > (1<<k)))ans = ssp(A,B);
		for(int j = 0 ; j < (A < (1<<k)? As.size() : Bs.size()) ; ++j){
			for(int l = 0 ; l < (B < (1<<k)? As.size() : Bs.size()) ; ++l){
				int a = (A < (1<<k))? ssp(A , As[j]) : ssp(A , Bs[j]);
				int b = (B < (1<<k))? ssp(B , As[l]) : ssp(B , Bs[l]);
				ans = min(ans , a+b + war[(A<(1<<k))? j : j+L][(B<(1<<k))? l : l + L]);
			}
		}
		assert(ans>=0);
		printf("%d\n",ans);
	} 
 }
