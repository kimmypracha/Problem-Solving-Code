#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef pair<int,int> pii;
 const int lim = 5e5+10;
 bool pub[lim] = {};
  int n , m;
 int pri[lim] = {};
 int npn[lim] = {};
 int low[lim]  = {};
 int idx[lim] = {};
 int sz[lim] = {};
 int pos[lim]= {};
 bool ins[lim] = {};
 int ncc[lim] = {};
 bool puc[lim] = {};
 stack<int> st; 
 vector<pii> edl;
 
 int cnt = 1  , cc = 1;
void dfs(int now){
   low[now] = idx[now] = cnt++;
   ins[now] = true;
   st.push(now);
   for(int i= pos[now] ; i <pos[now]  +sz[now]; ++i) {
	int v = edl[i].se;
   	if(idx[v] == 0){
		dfs(v);
		low[now] = min(low[now] , low[v]);
	}else if(ins[v]){
		low[now] = min(low[now] , idx[v]);
	}
   }
   if(low[now] == idx[now]){
  	while(st.top() != now){
		ncc[st.top()] =cc;
		ins[st.top()] = false;
		st.pop();
	}
	ncc[st.top()] = cc;
	ins[st.top()] = false;
	st.pop();
	cc++;
  }
 }
 void cal(){
 	fill(pos , pos + lim , 0);
 	fill(sz , sz + lim , 0);
	for(int i = 0 ; i < m ; ){
		int tmp = edl[i].fi;
		pos[tmp] = i;
		for( ;edl[i].fi == tmp; sz[tmp]++,  i++){}
	}
 }
  int dp[lim]  = {};
  int main(){
	scanf("%d%d",&n,&m);
	for(int i =0  ; i < m; ++i){
		int a , b;
		scanf("%d%d",&a,&b);
		edl.eb(a,b);
		sz[a]++;
	}
	for(int i = 1 ; i<= n;  ++i ){
		scanf("%d",&pri[i]);
	}
	sort(edl.begin() , edl.end());
	cal();
	int s , p;
	scanf("%d%d",&s,&p);
	for(int i = 0 ; i < p ; ++i){
		int a;
		scanf("%d",&a);
		pub[a] = true;
	}
	dfs(s);
//	for(int i =1 ; i  <= n ; ++i){
//		printf("%d : %d\n" , i , ncc[i]);
//	}
	for(int i = 1 ;  i <= n ; ++i){
		if(pub[i])
			puc[ncc[i]] = true;
		npn[ncc[i]] += pri[i];		
	}
	for(int i =0  ; i < m ;++i ){
		edl[i].fi = ncc[edl[i].fi];
		edl[i].se = ncc[edl[i].se];
	}
	sort(edl.begin() , edl.end());
	cal();
	fill(ins , ins + lim , false);
	queue<int> q;
	q.push(ncc[s]);
	ins[ncc[s]] = true;
	dp[ncc[s]] = npn[ncc[s]];
	while(not q.empty()){
		int now = q.front();
//		printf("at %d\n",now);
		q.pop();
		ins[now] = false;
		for(int i = pos[now] ; i < pos[now] + sz[now] ; ++i ){
			int v = edl[i].se;
//			printf("%d to %d\n",now, v);
			if(dp[v] < dp[now] + npn[v] and now != v){
				dp[v] = dp[now]  + npn[v];
				if(not ins[v])
				q.push(v) , ins[v] = true;
			}
		}
	}
	int mxn = 0 ;
	for(int i =1 ; i <= n  ; ++i){
		if(puc[ncc[i]]){
			mxn = max(mxn , dp[ncc[i]]);
		}
	}
	printf("%d",mxn);
  }
