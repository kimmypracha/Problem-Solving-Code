#include <bits/stdc++.h>
#define eb emplace_back
#define all(x) x.begin() , x.end()
#define ls(x) (x&(-x))
  using namespace std;
  typedef long long int lli;
  const int lim = 1e5+10;
  int arr[lim];
  int brr[lim];
  int tmp[lim];
  int ft[2][lim] = {};
  lli inv = 0;
  int n;
  void findinv(int l = 0  , int r = n-1){
  	if(l == r){
		return;
	}else{
		findinv( l , (l+r)/2);
		findinv((l+r)/2 + 1 , r);
		int idx = 0 , i = l , j = (l+r)/2+1;
		while( i <= (l+r)/2 and j <= r){
			if(brr[i] > brr[j]){
				inv += (l+r)/2 - i+1;
				tmp[idx++] = brr[j++];
			}else tmp[idx++] = brr[i++];	
		}
		while(i <= (l+r)/2)tmp[idx++] = brr[i++];
		while(j <= r )tmp[idx++] = brr[j++];
		for(int i =0  ; i < idx ; ++i){
			brr[l+i] = tmp[i];
		}
  	}
  }
  int rmq(int idx , int pos){
	int ans =0 ;
  	for( ; pos  ; pos -= ls(pos)){
		ans += ft[idx][pos];
	}
	return ans;
  }
  void update(int pos  ,int val){
//	printf("%d %d : %d %d %d\n" , pos , val  , rmq(0 , n) - rmq(0 , pos) , rmq(1 , pos-1) , inv);
  	if(val == -1){
		int idx = pos;
  		for( ;pos <= n ; pos += ls(pos) ){
			--ft[1][pos];	
		}
		inv -= rmq(0,n) - rmq(0 , idx) + rmq(1 , idx-1);
	}else{
		inv += rmq(1,pos-1) + rmq(0 , n) - rmq(0 , pos);
		for( ; pos <= n ; pos += ls(pos)){
			++ft[0][pos];
		}
	}	 
  }
  vector<int> vi;
  unordered_map<int, int > mpi;
  int main(){
	lli k;
	scanf("%d",&n);
	cin >> k;
	for(int i =0 ; i < n ; ++i){
		scanf("%d",&arr[i]);
		brr[i] = arr[i];
		vi.eb(arr[i]);
	}
	sort(all(vi));
	vi.resize(unique(all(vi)) - vi.begin());
	for(int i =0 ;  i < vi.size() ; ++i){
		mpi[vi[i]] =  i + 1;
	}
	findinv();
//	printf("inv  = %d\n",inv);
	int a = 0;
	for(int i = mpi[arr[0]] ; i <= n ; i += ls(i)){
			++ft[0][i];
	}
	for(int i = 1; i < n ; ++i){
		for(int j = mpi[arr[i]] ; j <= n ; j += ls(j)){
			++ft[1][j];
		}
	}
	lli ans = ((lli)n*((lli)n-1))/2LL;
	for(int i =1 ; i < n ; ++i){
		
		while(a < i and inv <= k){
			if(i != ++a)
			update(mpi[arr[a]] , 1);
		}
//		printf("%d %d : %d\n", i , a , inv);
		ans -= max(lli(i - a) , 0LL);
		if(a != i)
 		update(mpi[arr[i]] , -1);
	}	
	cout << ans;
  }
