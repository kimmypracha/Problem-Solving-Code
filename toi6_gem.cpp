#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 const int lim =  2e5 + 10;
 typedef pair<int,int> pii;
 vector<pii> vi;
 int opp[lim];
 int low[lim];
 int idx[lim] = {};
 int ins[lim] = {};
 int cnt= 1  , CC = 1;
 int ccp[lim] = {};
 stack<int> st;
 vector<int> G[lim];
 void dfs(int now) {
 	idx[now] = low[now] = cnt++;
	ins[now] = true;
	st.push(now);
	for(int i : G[now]){
		if(idx[i] == 0 ){
			dfs(i);
			low[now] = min(low[i] , low[now]);
		}else if(ins[i]){
			low[now] = min(low[now] , idx[i]);
		}
	}
	if(low[now] == idx[now]){
		while(st.top() != now ){
	//		printf("%d ",st.top());
			ccp[st.top()] = CC;
			ins[st.top()] = false;
			st.pop();
		}
	//	printf("%d\n",st.top());
		ccp[st.top()] = CC;
		ins[st.top()] = false;
		st.pop();
		CC++;
	}
 }
 	int main(){
		int round = 5;
		while(round--){
		int n  , m;
		scanf("%d%d",&n, &m);
		fill(idx +1  ,idx+ 1 + m , 0 );
		fill(ins + 1 , ins+1+m , false);
		cnt= 1;
		CC = 1;
		vi.clear();
		for(int i = 0 ; i < n; ++i ){
			int a, b;
			scanf("%d%d",&a,&b);
			vi.eb(a,b); 
		}
		for(int i = 0 ; i <  m/2;  ++i){
			int a , b ;
			scanf("%d%d",&a,&b);
			opp[a] = b;
			opp[b] = a;
		}
		for(int i =0  ; i < n; ++i){
		//	printf("%d %d \n",opp[vi[i].fi] , vi[i].se);
		//	printf("%d %d \n",opp[vi[i].se] , vi[i].fi);
			G[opp[vi[i].fi]].eb(vi[i].se);
			G[opp[vi[i].se]].eb(vi[i].fi);			
		}
		for(int i = 1 ; i <=  m ;++i ){
		if(idx[i] ==  0){
			dfs(i);
		//	printf("dfs at %d\n",i);
		}
		}
		bool Can = true;
		for(int i =1 ; i <= m ; ++i){
		//	printf("%d ",ccp[i] );
			if(ccp[i] == ccp[opp[i]]){
				printf("N");
				Can = false;
				break;
			}
		}
	//	printf("\n");
		if(Can)printf("Y");
		for(int i = 1 ; i  <= m ; ++i){
			G[i] = vector<int>();
			ccp[i] = 0;
		}
		}
	}
