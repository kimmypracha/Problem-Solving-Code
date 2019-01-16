#include <bits/stdc++.h>
#define eb emplace_back
#define all(x) x.begin() , x.end()
 using namespace std;
 vector<int> vi;
 vector<int> df;
 int main(){
 	int n, m;
	scanf("%d",&n);
	for(int i =0 ; i  < n ; ++i){
		int a, b;
		scanf("%d%d",&a,&b);
		vi.eb(a);
		vi.eb(b); 
	}
	sort(all(vi));
	vi.resize(unique(all(vi))-vi.begin());
	for(int i = 1 ; i < n ; ++i){
		df.eb(vi[i] - vi[i-1]);
	}
	
 }
