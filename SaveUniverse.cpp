#include <bits/stdc++.h>
#define fi first
#define se second
  using namespace std;
  typedef pair<int,int> pii;
  stack<pii> S;
  int main(){
 	int t;
	scanf("%d",&t);
	int cnt = 1 ;
	while(t--){
		int d;
		string P;
		scanf("%d", &d);
		cin >> P;
		int st = 0 ;
		int curr = 1;
		int CS = 0;
		for(int i = 0 ; i < P.size() ; ++i){
			if(P[i]=='C')curr <<= 1;
			else{
			 CS++;
			 st += curr;
			}
		}
		if((curr == 1 and st > d)or (CS > d)){
			printf("Case #%d: IMPOSSIBLE\n", cnt);
			cnt++;
			continue;
		}
		curr = 1;
		S = stack<pii>();
		for(int i = 0 ; i < P.size();  ++i){
			if(P[i] == 'C'){
				curr<<=1;
				S.push({i ,curr- (curr>>1)});
			}
		}
		int ans = 0;
		while(not S.empty()){
			int now = S.top().fi;
			int x = S.top().se;
			S.pop();
			if(st <= d)break;
			if(now + 1 == P.size() or P[now+1] == 'C'){
				continue;
			}
			ans++;
			st -= x;
			swap(P[now] , P[now+1]);
			S.push({now + 1 , x});
		}
		printf("Case #%d: %d\n",cnt , ans);	
		cnt++;
	}
 }
