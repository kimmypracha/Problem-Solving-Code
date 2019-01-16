#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
  using namespace std;
	typedef pair<int,int> pii;
	const int lim = 2e5+10; 
  	const int ran = 1e6+10;
   	int ban[lim];
	pii sti[ran];
	bool pos[lim]={} , used[lim] = {};
  int main(){
  	int n , m , k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&ban[i]);
	}
	for(int i = 0 ; i < k ; ++i){
		int p , h;
		scanf("%d%d",&p,&h);
		sti[i].fi = h;
		sti[i].se = p;
	}
	sort(sti , sti + k , [](const pii &a , const pii &b) -> bool{return (a.fi == b.fi)? a.se > b.se : a.fi < b.fi;});
	int now;
	scanf("%d",&now);
	pos[now] = true;
	used[now+1] = true;
	used[now-1] = true;
	int high = 0; 
	queue<int> q;
	for(int i = 0 ; i < k ; ++i){
		while(not q.empty() and high < sti[i].fi){
			used[q.front()] = true;
			q.pop();
		}
		high = sti[i].fi;
		if(pos[sti[i].se]){
			pos[sti[i].se] = false;
			pos[sti[i].se+1] = true;
			used[sti[i].se] = true;
			used[sti[i].se+2] = true;
		}
		else if(pos[sti[i].se + 1]){
			pos[sti[i].se+1] = false;
			pos[sti[i].se] = true;
			used[sti[i].se+1] = true;
			q.push(sti[i].se-1);
		}
		if(used[sti[i].se] and not used[sti[i].se+1]){
			used[sti[i].se] = false;
			used[sti[i].se+1] = true;
		}else if(used[sti[i].se+1 ]and not used[sti[i].se]){
			used[sti[i].se] = true;
			used[sti[i].se+1] = false;
		}
	}
	while(q.empty()){
		used[q.front()] = true;
		q.pop();
	}
	int mxnu  = 0 , mxu = 0; 
	for(int i = 1 ; i<= n ; ++i){
		if(pos[i]){
			mxnu = max(mxnu , ban[i]);
			mxu = max(mxu , max(ban[i-1] , ban[i+1]));
		}
		if(used[i]){
			mxu = max(mxu , ban[i]);
		}
	}
	if(mxnu >= mxu){
		printf("%d\nNO",mxnu);
	}else printf("%d\nUSE",mxu);
  }
