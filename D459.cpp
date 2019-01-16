#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
   const int lim  = 1e6+10;
   typedef long long int lli; 
  vector<int> seg[2*lim];
 set<int> st;
 map<int , int > mp; 
  int arr[lim];
  int n;
 int rmq(int l , int r , int x){
	int ans =0 ;
 	for(l += n , r += n ; l < r ; l >>= 1 , r >>= 1){
		if(l&1){
			int a = upper_bound(seg[l].begin() , seg[l].end() , x) - seg[l].begin();
			ans += (int)seg[l].size() -a; 
			l++;	
		}
		if(r&1){
			--r;
			int a = upper_bound(seg[r].begin() , seg[r].end() , x) - seg[r].begin();
			ans += (int)seg[l].size()-a;
		}
	}
	return ans; 
 }
  int main(){
	scanf("%d",&n);
	for(int i =0  ; i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	for(int i= 0 ; i < n ; ++i){
		mp[arr[i]]++;
//		printf("%d ",st.count(arr[i]));
		seg[n+ i].eb(mp[arr[i]]);
	}
//	printf("\n");
	for(int pos = n-1 ; pos>=1 ; --pos){
		auto& a = seg[pos<<1];
		auto& b = seg[pos<<1|1];
		auto& c = seg[pos];
		int i = 0 ,  j = 0 ;
		while(i < a.size()  and j < b.size()){
			if(a[i] < b[j]){
				c.eb(a[i++]);
			}else{
				c.eb(b[j++]);
			}
		}
		while(i < a.size())c.eb(a[i++]);
		while(j < b.size())c.eb(b[j++]);
	}
	mp.clear();
	lli ans = 0 ;
	for(int i = n-1 ; i >= 1 ; --i){
		mp[arr[i]]++;
//		printf("i = %d : %d %d \n",i , st.count(arr[i]), rmq(0 ,  i , st.count(arr[i])));
		ans += (lli)rmq(0 , i  , mp[arr[i]]);
	}
//	printf("\n");
	printf("%lld",ans);
 } 
