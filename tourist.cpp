#include <bits/stdc++.h>
 #define eb emplace_back
 using namespace std;
 vector<string> vs;
 vector<int > ord; 
 typedef long long int lli;
 int main(){
  	int t , n,  k ;
	lli vf;
	int cnt = 1;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%lld",&n,&k,&vf);
		vs.clear();
		for(int i =0 ; i < n ; ++i){
			string A;
			cin >> A;
			vs.eb(A);
		}
		if(n == k){
			cout << "Case #" << cnt <<":";
			for(auto st : vs){
				cout << " " << st;
			}
			cout << "\n";	
		}else{
			lli tm=  2;
			int now = (k-1+ k)%n;
			while(now != k-1 ){
				now += k;
				now %= n;
				tm++;
			}
			tm--;
			int v = (int)(vf%tm);
			int beg = (n-k)%n;
			for(int i = 0 ; i < v ; ++i){
				beg = (beg+k)%n;
			}
			cout << "Case #" << cnt << ":";
			ord.clear();
			for(int i = 0 ;  i < k ; ++i){
				ord.eb((i+beg)%n);
			}	
			sort(ord.begin() , ord.end());
			for(int i =0 ;  i < k ; ++i){
				cout << " " << vs[ord[i]];
			}
			cout << "\n";
		}
		cnt++;
	}
 }
 
