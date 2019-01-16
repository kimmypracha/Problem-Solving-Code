#include <bits/stdc++.h>
 
 using namespace std;
typedef long long int lli;
typedef struct node{
 	int num , fi , se;
	bool operator < (const node &a) const{
 		return (num == a.num)? ((fi == a.fi)? se < a.se : fi < a.fi) : num < a.num; 
	}
 };
 lli pv[1<<8] = {};
 lli pre[1<<8][1<<8] = {};
 map<node , lli> dp;
 int n , k;
 lli div(int now , int st , int en){
 	if(dp[{now , st , en}]> 0)return dp[{now , st , en}];
	if(now < k )return 0;
	lli ans =0 ;
	for(int i = 0 ; i < (1<<k); ++i){
		for(int j = 0 ; j < (1<<k) ; ++j){
			lli tmp = div(now/2 , st , i) + div(now - now/2 , j , en);
	//		string A = bitset<2>(i).to_string();
	//		string B = bitset<2>(j).to_string();
	//		reverse(A.begin() , A.end());
	//		reverse(B.begin() , B.end());
		//	cout <<"||Start : " <<A << " " << B << "\n";
		//	cout << "||size : " << now/2  << " " << now - now/2  << "\n";
			if(now/2 >= k and now - now/2 >= k)tmp += pre[i][j];
			else{
				int val = i|(j<<(now/2));
				for(int l = k; l <= now ; ++l){
	//				string C = bitset<2>(val%(1<<k)).to_string();
	//				reverse(C.begin() , C.end());
				//	cout << C << "\n";
					tmp += pv[val%(1<<k)];
					val >>=1;
				}
			}
			ans = max(ans , tmp);
		}
	}
	dp[{now , st , en}] = ans;
	return ans;
 }
 int main(){
	scanf("%d%d",&n,&k);
	for(int i =0  ; i < (1<<k) ; ++i){
		scanf("%lld",&pv[i]);
	}
	for(int i =0 ; i < (1<<k) ; ++i){
		for(int j = 0 ; j < (1<<k) ; ++j){
			lli sum = pv[i];
			int now = i;
	//		cout << "Start "<<bitset<2>(i) << " " << bitset<2>(j) << "\n";
			for(int l = 0 ; l < k ; ++l){
				now >>= 1;
				now |= ((j>>l)&1)<<(k-1);
				sum += pv[now];
	//			cout << bitset<2>(now) << "\n";
			}
		}
	}
	lli ans = 0;
	for(int i = 0 ; i < (1<<k) ; ++i){
		for(int j = 0 ; j < (1<<k) ; ++j){
			ans = max(ans , div(n , i , j));		
		}
	}
	printf("%lld",ans);
 }
