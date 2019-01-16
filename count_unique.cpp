#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 typedef struct pii{
 	int fi , se , in;
	pii(int a,  int b,  int c) : fi(a) , se(b) , in(c) {};
 };
 const int lim = 2e6 + 10;
 vector<pii> vi;
 int arr[lim];
 int fre[lim] = {};
 int ans[lim] = {};
 int main(){ 
	int n , m;
	scanf("%d%d",&n,&m);
	for(int i =0 ; i < n;  ++i){
	 	scanf("%d",&arr[i]);
	}
	for(int i =0 ; i <  m ; ++i){
		int a , b;
		scanf("%d%d",&a, &b);
		vi.eb(a-1,b-1 , i);
	}
	int sq = sqrt(n);
	sort(vi.begin() ,vi.end(),[=](const pii &a , const pii &b) -> bool{return (a.fi/sq == b.fi/sq)? a.fi/sq < b.fi/sq : a.se < b.se;});
	int l = 0 ;
 	int r = 0 ;
	fre[arr[0]]++;
	int cnt =1 ;
	for(int i =0 ; i < m; ++i){
		while(l > vi[i].fi){
			l--;
			if(fre[arr[l]] == 0)cnt++;
			fre[arr[l]]++;
		}
		while(l < vi[i].fi ){
			fre[arr[l]]--;
			if(fre[arr[l]] == 0)cnt--;
			l++;
		}
		while(r < vi[i].se){
			r++;
			if(fre[arr[r]] == 0)cnt++;
			fre[arr[r]]++;
		}
		while(r > vi[i].se){
			fre[arr[r]]--;	
			if(fre[arr[r]] == 0)cnt--;
			r--;
		}
		ans[vi[i].in] = cnt;
	}
	for(int i =0 ;  i < m ; ++i){
		printf("%d\n", ans[i]);
	} 
 }
