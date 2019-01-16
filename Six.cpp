#include <bits/stdc++.h>

 using namespace std;
 typedef long long int lli;
 lli fre[6] = {} ;
 const lli mod = 1e9+7;
 int k;
 map<vector<int> , lli> mp;
 lli rec(const vector<int>& vec){

	//printf("|\n");
 	if(mp.count(vec))return mp[vec];
	lli ans  =0 ; 
	for(int i = 1 ; i < (1<<k) ; ++i){
		if(vec[i] == 2)continue;
		vector<int> nv = vec;
		for(int j = 0 ; j < (1<<k) ; ++j){
			if(i&j)nv[j]++ , nv[j] = min(nv[j] , 2);
		}
		lli mul = 1;
		for(int j = 0 ; j < k ; ++j){
			if(i&(1<<j))mul *= fre[j];	
		}
		ans += (mul*(1 + rec(nv)))%mod;
		ans %= mod;
	}
	return mp[vec] = ans;
 }
  int main(){
  	lli n;
	k = 0 ;
	scanf("%lld",&n);
	lli tmp = n;
	for(lli i= 2 ; i*i <= n ; ++i){
			if(tmp%i == 0){
			while(tmp%i == 0){
				tmp = tmp/i;
				fre[k]++;
			}
			k++;
			}
	}
	if(tmp != 1){
		fre[k] =1;
		k++;
	}
	lli ans = rec(vector<int>((1<<k),0));
	ans %= mod;
	printf("%lld", ans);
  }
