#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
  using namespace std;
  typedef pair<int,int> pii;
  const int lim = 1e5 + 10;
  int par[lim];
  int dif[lim];
  int h[lim];
  set<pii> st;
  vector<pii> que;
  priority_queue<int> pq;
  int fh(int now ){
  	return par[now]= (par[now] == now)? now : fh(par[now]);
 }
  int main(){
  	int n,  m;
	scanf("%d%d",&n,&m);
	h[0] = 2e9;h[n+1] = -2e9;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&h[i]);
		dif[i-1] = h[i] - h[i-1];
		pq.push(dif[i-1]);
		par[i] = i;
		st.insert(make_pair(dif[i-1] , i-1));
	}
	par[n+1] = n+1;
	dif[n] = h[n+1] - h[n];
	st.insert(make_pair(dif[n] , n));
	while(not pq.empty()){
		int df = pq.top();
		int cnt =0 ;
		pq.pop();
		if(df <= 0 )break;
		if(not que.empty() and que.back().fi+1 == df)continue;
		for(auto it = st.lower_bound(make_pair(df, 0)) ; it != st.end() ; ){
			int pos = it->se;
			if(par[pos] != pos){
				it = st.erase(it);
				continue;
			}
			int des;
			for(des = fh(pos+1) ; des <= n and h[des] - h[pos] >= df ;){
				cnt++;
				par[des] = par[des+1];
				des = des +1;
				des = fh(des);
			}
			it++;
				st.erase(make_pair(dif[pos] ,pos ));
				dif[pos] = h[fh(pos+1)] - h[pos];
				st.insert(make_pair(dif[pos] , pos));
		}
		que.eb(df-1 , cnt);
	}
	for(int i = 1 ;  i < que.size() ; ++i){
		que[i].se += que[i-1].se;
	}
	sort(que.begin() , que.end());
	que.eb(2e9 , 0);
//	for(int i =0 ; i < que.size(); ++i){
//		printf("%d %d\n", que[i].fi , que[i].se);
//	}
	for(int i = 0 ; i < m;  ++i){
		int x;
		scanf("%d",&x);
		int pos = upper_bound(que.begin() , que.end() , make_pair(x , 2e9+1)) - que.begin();
		printf("%d\n",que[pos-1].se); 
	}
  }
