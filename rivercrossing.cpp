#include <bits/stdc++.h>
#define ls(x) (x&(-x))
#define eb emplace_back
  using namespace std;
  typedef long long int lli;
  const int lim = 5e4 + 10;
  const lli mod = 30011;
  vector<int> GL[lim] ,  GR[lim];
  int A[lim] = {} , B[lim] = {};
  int sa[lim] = {} , sb[lim] = {};
  lli fa[lim] = {} , fb[lim] = {};
  int fpa[lim] = {},  fpb[lim] = {};
  int n , m  , k , l;
  lli rsq(int type , int pos ){
  	lli sum = 0 ;
	for( ; pos ; pos -= ls(pos)){
		sum += (type)? fb[pos] : fa[pos];
	}
	return sum;
  }
  void add(int type , int idx , lli val){
  	if(type == 0){
		for( ; idx <= n ; idx += ls(idx)){
			fa[idx] += val;
		}
	}else{
		for( ; idx <= m ; idx += ls(idx)){
			fb[idx] += val;
		}
	}
  }
  int find(int type , lli val){
  	int l = 1 , r = (type)? m : n;
	int mid;
	r++;
	while(l < r){
		mid = (l+r)/2;
		if(rsq(type , mid) >= val){
			r = mid;
		}else{
			l = mid+1;
		}
	}
	return l;
  }
  int main(){
	scanf("%d%d%d%d",&n,&m,&k,&l);
	for(int i = 0 ; i < l ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		GL[a].eb(b);
		GR[b].eb(a);
 	}
	for(int i =1 ; i <=n ; ++i){
		scanf("%d%d",&A[i],&sa[i]);
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d%d",&B[i],&sb[i]);
	}
	for(int i = 1 ; i <= n; ++i){
		add(0 , i , 1LL);
	}
	for(int i = 1 ; i <= m; ++i){
		add(1 , i , 1LL);
	}
	//printf("\n");
	for(int i = 1 ; i <= n ; ++i){
		for(int j : GL[i]){
			add(1 , j , -1LL);
		}
		fpa[i] = find(1 , rsq(1 , (lli)sa[i]) + A[i] -1);
		for(int j : GL[i]){
			add(1 , j , 1LL);
		}
	//	printf("%d ",fpa[i]);
	}
	//printf("\n");
	for(int i = 1 ; i <= m ; ++i){
		for(int j : GR[i]){
			add(0 , j , -1LL);
		}
		fpb[i] = find(0 , rsq(0 , (lli)sb[i])+B[i]-1);
		for(int j : GR[i]){
			add(0 , j , 1LL);
		}
	//	printf("%d ",fpb[i]);
	}
	//printf("\n");
	for(int i = 1 ; i <= n; ++i){
		fa[i] = 0;
	}
	for(int i = 1 ; i <= m ; ++i){
		fb[i ] = 0;
	}
	add(0 , 1, 1);
	lli ans = 0 ;
	for(int i =0 ;  i <= k ; ++i){
		int Li = (i&1)? m : n;
		for(int j = 1 ; j <= Li ; ++j){	
			int pos = (i&1)? fpb[j] : fpa[j];
			lli now = rsq(i&1 , j);
			now = now%mod;
		//	printf("%d ", now);
			if(i&1) ans = (now + ans)%mod;
			if(i == k)continue;
			if((i&1) == 0 ){
				for(int v : GL[j]){
					if(v < sa[j] or v > pos)continue;
					add((i+1)%2 , v ,-now);
					add((i+1)%2 , v+1 , now);
				}	
			//	printf("|sa[%d] = %d %d\n",j,sa[j] , pos+1);
				add((i+1)%2 , sa[j] , now);
				add((i+1)%2 , pos+1 , -now); 
			}else{
				for(int v :GR[j]){
					if(v < sb[j] or v > pos)continue;
					add((i+1)%2 , v , -now);
					add((i+1)%2 , v+1 , now);	
				}
			//	printf("|%d %d\n",sb[j] ,pos+1 );
				add((i+1)%2 , sb[j] , now);
				add((i+1)%2 , pos+1 , -now); 	
			}
		}
	//	printf("\n");
		for(int j = 1 ; j <= Li ; ++j){
			if(i&1)fb[j] = 0;
			else fa[j] = 0 ;
		}
	}
	printf("%lld",ans);
 }
