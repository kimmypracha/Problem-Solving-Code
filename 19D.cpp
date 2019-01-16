#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin() , x.end()
  using namespace std;
  typedef pair<int,int> pii;
  const int lim = 2e5+10;
  char s[10];
  int x[lim] , y[lim];
  char t[lim];
  int m;
  vector<int> vi;
  vector<pii> que;
  unordered_map<int,int> mpi;
  int seg[4*lim];
  set<int> hve[lim];
  void update(int pos , int p =1 , int l = 0 , int r = m-1){
  	if(l > pos or r < pos) return;
	if(l == r){
		if(hve[pos].empty())seg[p] = -1;
		else seg[p] = *(--hve[pos].end());
//		printf("%d %d : %d\n", l , r , seg[p]);
	}else{
		update(pos , p<<1 , l , (l+r)/2);
		update(pos , p<<1|1 , (l+r)/2 + 1 , r);
		seg[p] = max(seg[p<<1] , seg[p<<1|1]);
//		printf("%d %d : %d\n" , l , r , seg[p]);
	}
  }
  int rmq(int a , int b , int p =1 , int l = 0 , int r = m-1){
  	if(a >= m) return -1;
	if(r < a )return -1;
	if(seg[p] < b)return -1;
	if(l == r)return l;
		int p1 = rmq(a , b , p<<1 , l , (l+r)/2 );
		if(p1 == -1){	
		//	printf("YES %d %d %d\n" , a , b , seg[p<<1]);
			return rmq(a , b , p<<1|1 , (l+r)/2 + 1 , r);	
		}else{
			return p1;
		}
  }
  int main(){
	fill(seg , seg + 4*lim , -1);
  	int n,a ,b;
	scanf("%d",&n);
	for(int i = 0; i  < n ; ++i){
		scanf("%s%d%d",s,&a,&b);
		if(s[0] == 'a')vi.eb(a);
			x[i] = a;
			y[i] = b;
			t[i] = s[0];
	}
	sort(all(vi));
	vi.resize(unique(all(vi)) - vi.begin());
	m = vi.size();
	for(int i =0 ; i  < m ; ++i){
		mpi[vi[i]] = i;
	}
	for(int i = 0;  i < n ; ++i){
		if(t[i] == 'a'){
	//		printf("ADD:\n");
			hve[mpi[x[i]]].insert(y[i]);
			update(mpi[x[i]]);
		}else if(t[i] == 'r'){	
//			printf("REM:\n");
			hve[mpi[x[i]]].erase(y[i]);
			update(mpi[x[i]]);
		}else{
		//	printf("FIND:\n");
			int idx = upper_bound(all(vi) , x[i]) - vi.begin();
			int pos = rmq(idx ,y[i]+1);
			if(pos == -1)printf("-1\n");
			else{
				int yy = *(hve[pos].upper_bound(y[i]));
				printf("%d %d\n",vi[pos] , yy);
			}
		}
//		printf("::%d\n",hve[0].size());
	}
  }
