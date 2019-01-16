#include <bits/stdc++.h>
#define eb emplace_back
#define ls(x) (x&(-x))
  using namespace std;
 typedef long long int lli;
  const int lim=3e5+10;
  vector<int> G[30];
  int pos[30] = {};
  lli ft[lim] = {};
  string A , B;
  int n;
  lli rmq(int pos ){
	lli sum = 0 ;
	for(;pos ; pos -= ls(pos)){
		sum += ft[pos];
	}
	return sum;	
  }
  void update(int pos , lli val){
 	for(;  pos<=n ; pos += ls(pos)){
		ft[pos] += val;
	}	
  }
  int main(){
  	int m  , k;
	scanf("%d",&k);
	cin >> A >> B;
	n = (int)A.size();
	m = (int)B.size();
	for(int i = 1 ; i <= n ; ++i){
		update(i , 1);
	}
	for(int i = 0 ; i < A.size() ; ++i){
		G[A[i]- 'a'].eb(i+1);
	}
	lli ans =0 ;
	for(int i = 0 ; i < B.size() ; ++i){
		if((int)G[B[i]-'a'].size() <= pos[B[i]-'a']){
		//	printf("%c %d %d\n",B[i] , (int)G[B[i]-'a'].size() , pos[B[i]-'a']);
			printf("-1");
			return 0;
		}else{
			ans += rmq(G[B[i]-'a'][pos[B[i]-'a']]);
			if(k==1)update(G[B[i]-'a'][pos[B[i]-'a']] , -1);
			pos[B[i]-'a']++;
		}
	}
	printf("%lld",ans);
  }
