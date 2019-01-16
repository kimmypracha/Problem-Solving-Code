#include <bits/stdc++.h>
#define eb emplace_back 
#define all(x) x.begin() , x.end()
 using namespace std;
 typedef long long int lli;
 const int lim = 3e5+10;
 int subt[lim];
 lli dp[lim];
 vector<int> cen;
 vector<int> G[lim];
 bool hsh[lim] = {};
 set<lli> coll;
 int n;
 void get_sz(int u , int p= -1){
	subt[u] = 1;
	for(int v : G[u])if(v != p){
		get_sz(v,u);
		subt[u] += subt[v]; 
	}	 
 }
 void dfs(int u , int p = -1){
	bool iscen = true;
	for(int v : G[u])if(v != p){
		dfs(v,u);
		if(subt[v] > n/2)iscen = false;
	}
	if(n-subt[u] > n/2)iscen = false;
	if(iscen)cen.eb(u);	
 }
 lli ans = 0;
 void find_dp(int u , int p = -1){
	dp[u] = 0;
	for(int v : G[u])if(v != p){
		find_dp(v,u);
		dp[u] += dp[v] + 1;	
	}
	ans += dp[u];	
 }
 lli find_mx(vector<lli> sm){ 
 	map<lli ,int> fre;
	for(lli x : sm){
		fre[x]++;
	}
	coll.clear();
	coll.insert(0);
	fill(hsh, hsh + n/2 + 1 , false);
	sort(sm.begin(),sm.end());
	sm.resize(unique(all(sm))-sm.begin());
	for(lli x : sm){
	//	printf("Enter %lld\n",x);
		for(auto it = coll.rbegin() ; it != coll.rend() ; ++it ){
			lli now = *it;
	//		printf("Here : %lld\n",now);
			lli cnt = 1;
			lli lm = fre[x]; 	
			while(cnt <= lm and now+cnt*x <= n/2 and not hsh[now+cnt*x]){
				hsh[now + cnt*x] = true;
				coll.insert(now + cnt*x);
				++cnt;
			}		
		}
	}
	lli tmp = 0;
	for(lli i = (lli)n/2 ; i >= 1 ; --i){
		if(hsh[i]){
	//		printf("now : : %lld\n",i);
			tmp = max(tmp , i*(n-i-1));
		}
	}
	return tmp; 
 }
 int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n-1 ; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		G[a].eb(b);
		G[b].eb(a);
	}
	get_sz(1);
	dfs(1);
	lli res = 0;
	for(int x : cen){
		//printf("cen : %d\n",x);
		ans = 0;
		find_dp(x);
		vector<lli> sum;
		for(int s : G[x]){
			//printf("%d ",dp[s]);
			sum.eb(dp[s]+1);
		}
		//sort(sum.begin() , sum.end());
		
		ans += find_mx(sum);
		res = max(res , ans);
	} 
	printf("%d %lld",n-1,res);
 }
