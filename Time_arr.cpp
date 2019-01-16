#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef pair<int,int> pii;
vector<pii> vi;
  int main(){
 	int N ;
	scanf("%d",&N);
	for(int i =0 ; i < N ; ++i){
		int s , f;
		scanf("%d%d",&s, &f);
		vi.eb(s,f);
	}
	sort(vi.begin(), vi.end() , [](const pii &a ,const pii &b)->bool{return (a.se == b.se)? a.fi > b.fi : a.se < b.se;});
	int lst = -1 , cnt = 0;
 	for(int i =0  ;i <  N ; ++i){
		if(vi[i].fi >= lst){
			cnt++;
			lst = vi[i].se;	
		}
	}
	printf("%d",cnt);
}

