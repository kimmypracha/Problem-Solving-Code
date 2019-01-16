#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 typedef pair<int,int> pii;
 const int lim = 1e5 + 10;
 vector<pii> vi;
  int main(){
  	int N;
	scanf("%d",&N);
	for(int i =0 ; i  < N ; ++i){
		int x , y;
		scanf("%d%d",&x,&y);
		vi.eb(x,y);
	}
	sort(vi.begin() , vi.end() , [](const pii &a , const pii &b)->bool{return})
  }
