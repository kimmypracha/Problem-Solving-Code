#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ls(x) (x&(-x))
 using namespace std;
 const int mxn = 3e4+10;
 const int mxk = 1e3+10;
 int arr[mxn];
 int dp[mxn] = {};
 vector<int> vi , cs[mxn] , sc[mxn];
 unordered_map<int , int > mpi;
 void update(int idx , int pos , int val){
 	int now =  lower_bound(cs[idx].begin() , cs[idx].end() , pos) - cs[idx].begin();
	sc[idx][now] = max(sc[idx][now] , val);
//	if(idx == 4)
//		for(auto i : cs[idx]){
//			cout << i << " " ;
//		}
//	cout << "\n";
//	if(idx == 4)printf("|||| %d\n",now);
	for(; now < sc[idx].size() and now ; now += ls(now) ){
//		if(idx == 4)printf("||| %d\n",now);
		sc[idx][now] = max(sc[idx][now ] , val);
	}
 }
 int mxl(int idx , int pos = -1){
 	int now = (pos == -1)? (int)cs[idx].size()-1 : (lower_bound(cs[idx].begin() , cs[idx].end() , pos) - cs[idx].begin());
	int ans = sc[idx][0] ;
	if(pos != -1 and cs[idx][now] != pos ){
		if(now){
			now = now -1 ;
		}else{
			return 0;
		}
	}
//	if(idx == 3)printf("(%d)",now);
	for(; now ;  now -= ls(now)){
		ans = max(ans , sc[idx][now]);
	}
//	if(idx == 3)printf("(%d)" , ans);
	return ans;
 }
 int main(){
 	int n , k;
	scanf("%d%d",&n,&k);
	for(int i =0 ; i < n ; ++i){
		scanf("%d",&arr[i]);
		vi.eb(arr[i]);
	}
	//return 0 ;
	sort(vi.begin() , vi.end());
	auto it = unique(vi.begin() , vi.end());
	vi.resize(it - vi.begin());
	for(int i =0 ; i  < vi.size() ; ++i){
		mpi[vi[i]] = i;
	}
	for(int i = 0 ; i < n ; ++i){
		int idx = mpi[arr[i]];
		cs[idx].eb(i);
		sc[idx].eb(0);
	}
	for(int i = 0 ; i <= k ; ++i){
		for(int j = 0;  j < n; ++j){
		//	printf("%d %d \n" , i , j );

			if(i == 0){
				if(mpi.find(arr[j]-1)!= mpi.end()){
					int idx = mpi[arr[j]-1];
					int now = idx+1;
				//	if(arr[j] == 5) printf("|| %d \n",idx);

					dp[now] = max( mxl(idx , j-1) + 1 , dp[now]);
					update(now , j, dp[now]);
				}else update(mpi[arr[j]] , j , 1 ) , dp[mpi[arr[j]]] = max(dp[mpi[arr[j]]] , 1);
			}else{
				if(mpi.find(arr[j]-1)!=mpi.end()){
					int idx = mpi[arr[j]-1];
					int now = idx+1;
					dp[now] = max(mxl(idx) + 1  , dp[now]) ;
					update(now , j , dp[now]);
				}else update(mpi[arr[j]] , j ,1) , dp[mpi[arr[j]]] = max(dp[mpi[arr[j]]], 1);
			}
//			printf("%d ",dp[mpi[arr[j]]]);
		}
//		printf("\n");
	}

	int ans = 0 ;
	for(int i = 0 ; i < n ; ++i) ans = max(ans , dp[i]);
//	printf("|||||||| %d \n" ,(int)cs[3].size() );
	printf("%d",ans);
 }
