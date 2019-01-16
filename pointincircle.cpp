#include <bits/stdc++.h>

  using namespace std;
  typedef long long int lli;
  lli G[1010][1010];
  lli pos[1010];
  set<int> st;
  int main(){
  	int k;
 	lli n;
	scanf("%lld%d",&n,&k);
	for(int i = 0 ; i < k ; ++i){
		for(int j = 0 ; j < k ; ++j){
			scanf("%lld",&G[i][j]);
		}
	}
	pos[0] = 0;
	if(k > 1)
		pos[1] = G[0][1];
	for(int i = 2 ; i < k ; ++i){
		lli A = G[0][i];
		lli B = G[0][1];
		lli C = G[1][i];
		if(A == B + C){
			pos[i] = A;
		}else if(C == A+B){
 			pos[i] = n- G[0][i];
		}else if(B == A + C){
			pos[i] = A;
		}else{
			pos[i] = B+C;
		}
	}
	for(int i =0 ; i  < k ; ++i){
	//	assert(st.find(pos[i]) == st.end());
		printf("%lld\n",pos[i]);
	//	st.insert(pos[i]);
	}
  }
