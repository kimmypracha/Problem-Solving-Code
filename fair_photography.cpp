#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
  using namespace std;
  typedef pair<int,int> pii;
  const int lim = 1e5+10;
  vector<pii> vec;
  int dp[lim][10] = {} , df[lim][10] = {};
  map<vector<int> , int > hsh;
  int main(){
  	int n , k;
//	FILE *fp = fopen("fairphoto.in","r");
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; ++i){
		int x,y;
		scanf("%d%d",&x,&y);
		vec.eb(x,y);
	}
	vec.eb(-1,0);
	sort(vec.begin() , vec.end());
	int ans = -1;
	vector<int> vi(9,0),key(9,0);
	hsh[vi] = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(i == n)vec[i].first = 1e9;
		for(int j = 1 ; j <= 9 ; ++j){
			dp[i][j] = dp[i-1][j];
			df[i][j] = dp[i-1][j];
		}
		dp[i][vec[i].second]++;
		copy(dp[i]+1,dp[i] + 10 , vi.begin());
		for(int l = 1 ; l <= 9 ; ++l){
			if(dp[i][l] == 0)continue;
			copy(vi.begin(),vi.end(),key.begin());
			int mn = dp[i][l] ,ds = 0;
			for(int j = 1 ; j <= 9 ; ++j){
				if(dp[i][j] == 0)continue;
				if(dp[i][j] >= mn)
					ds++;
			}
			for(int j = 0 ; j < 9 ; ++j){
				if(key[j]==0)continue;
				key[j] -= (key[j] >= mn)? mn : 0;
			}
	//		printf("%d : \n",vec[i].first);
	//		for(int a : vi){
	//			printf("%d ",a);
	//		}
	//		printf("\n");
	//		for(int a : key){
	//			printf("%d ",a);
	//		}
	//		printf("\n");
			//hsh[vi] = i;
			if(hsh.find(key) != hsh.end()){
				int x = hsh[key];
				printf("Enter %d %d %d\n",ds , vec[i].first,vec[x].first);
		//		printf("Enter:\n%d: \n",vec[i].first);
		//		for(int a : vi){
		//			printf("%d ",a);
		//		}
		//		printf("\n");
		//		for(int a : key){
		//			printf("%d ",a);
		//		}
		//		printf("\n");
				if(ds < k)continue;
			//printf("|| %d %d\n" , vec[x].first ,vec[i].first);
				ans = max(ans , vec[i].first-vec[x].first-1);
			}
		}
	}
	//fp = fopen("fairphoto.out","w");
	printf("%d",ans);
  }
