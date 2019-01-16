#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin(),x.end() 
 using namespace std;
  typedef long long int lli;
  typedef pair<int,int> pii;
  const int lim = 1e6+10;
  bool vis[lim] = {};
  bool mrk[lim] = {};
  bool inc[lim] = {};
  lli dp[lim] = {};
  vector<pii> G[lim];
  map<pii,int> edge;
  vector<int> keep , cyc ;
  vector<lli> wei_t , wei ;
  lli ans = 0 , sum =0 ,tmp =0 , res = 0;
  void dfs(int now , int p = -1){
	vis[now] = true;
	mrk[now] = true;
	keep.eb(now);
//	printf("%d\n",now);
	for(pii x : G[now]){
		int v = x.fi;
		lli w = lli(x.se);
		if(v == p)continue;
		if(!vis[v]){
			tmp += w;
			wei_t.eb(w);
			dfs(v, now);
			tmp -= w;
		//	if(wei_t.empty())printf("wei_t is out!!\n") , exit(0);
			wei_t.pop_back();
		}else if(cyc.empty()){
			int pos = find(all(keep),v) - keep.begin();
			cyc.assign(keep.begin() + pos , keep.end());
			wei.assign(wei_t.begin() + pos ,wei_t.end());
		//	printf("cyc : ");
		//	for(int x : cyc){
		//		printf("%d ",x);
		//	}
		//	printf("\n wei : ");
		//	for(int x : wei){
		//		printf("%d ",x);
		//	}
		//	printf("\n");
			//copy(all(keep),cyc.begin());
			//copy(all(wei_t),wei.begin());
			sum = tmp;
		}
	}
	vis[now] = false;
//	if(keep.empty())printf("keep is out!!\n") , exit(0);
	keep.pop_back();
  }
  void find_dp(int now , int p = -1){
	vector<lli> fm;
	for(pii x : G[now]){
		int v = x.fi;
		lli w = x.se;
		if(v != p and !inc[v]){
			find_dp(v,now);
			dp[now] = max(dp[now] , dp[v] + w);
			fm.eb(dp[v]+w);
		}
	}
	if(fm.size() >= 2){
		nth_element(fm.begin() , fm.begin()+1 , fm.end() , greater<lli>());
		ans = max(ans , fm[0] + fm[1]);
	}
	ans = max(ans , dp[now]);		
  }
  void findmxpath(int now){
	keep.clear();
	cyc.clear();
	wei.clear();
	wei_t.clear();
	sum = 0;
	ans = 0;
  	dfs(now);
	if(!cyc.empty()){
		lli mx = 0, mn = 1e9;
		for_each(all(cyc),[&](const int &x){inc[x] = true;});
		now = cyc[0];
		for_each(all(G[now]),
		  [&](const pii &x){mx=(x.fi==cyc.back())? max(mx,lli(x.se)) : mx;});	
		sum += (lli)mx;
		tmp = 0;
		wei.insert(wei.begin(),0);
		for(lli& x : wei){   // DEBUG :: Check sum == wei.back()
			x = tmp + x;
			tmp = x;
		}
		//printf("::%d %d %d\n",sum ,tmp, mx );
		mx = 0 ;
	//	printf("\nqs : ");
	//	for(int x : wei){
	//		printf("%d ", x);
	//	}
	//	printf("\n");
		int idx = 1;
		for(int x : cyc){
			find_dp(x);
			if(idx != 1)	
				ans = max(ans , max(dp[x] + wei[idx-1] + mx ,
						dp[x] + sum - wei[idx-1] - mn ));
			mx = max(mx , dp[x]-wei[idx-1]);
			mn = min(mn , dp[x]-wei[idx-1]);
			idx++;
		}
	}else{
		find_dp(now);
	}
	// Linear Dynamic Programming Session
	}
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i){
		int v , w;
		scanf("%d%d",&v,&w);
		int mx = max(edge[pii(i,v)] , edge[pii(v,i)]);
		mx = max(mx , w);
		edge[pii(i,v)] = edge[pii(v,i)] = mx;
	}
	for(auto it = edge.begin() ; it != edge.end() ; ++it){
		G[(*it).fi.fi].eb((*it).fi.se,(*it).se);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!mrk[i]){
			findmxpath(i);
			res += ans;
		}	
	}
	printf("%lld",res);
  }
