#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef pair<int,int> pii;
 map<pii , int > mpi;
 vector<pii> vi , cvh;
 bool comp(pii a , pii b){
	int a1 = (a.fi-vi[0].fi);
	int a2 = (a.se-vi[0].se);
	int b1 = (b.fi-vi[0].fi);
	int b2 = (b.se-vi[0].se);
	return (a2*b1 == b2*a1)? a1*a1 + a2*a2 < b1*b1 + b2*b2 :a2*b1 < b2*a1;	
 }
 bool isleft(int pos , pii x ){
	int a = cvh[pos].fi - cvh[pos-1].fi;
	int b = cvh[pos].se - cvh[pos-1].se;
	int c = x.fi - cvh[pos-1].fi;
	int d = x.se - cvh[pos-1].se;
//	printf("%d %d - %d %d | | %d %d - %d %d\n",vi[pos-1].fi,vi[pos-1].se , vi[pos].fi , vi[pos].se
//						  ,vi[pos-1].fi,vi[pos-1].se , x.fi , x.se);
//	printf("::%d\n",a*d-b*c);
	return (a*d - b*c >= 0);	
 }
 int main(){
 	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i){
		int x  , y;
		scanf("%d%d",&x,&y);
		vi.eb(x,y);
	}
	int m ;
	scanf("%d",&m);
	for(int i = 1 ; i <= m ; ++i){
		int x , y;
		scanf("%d%d",&x,&y);
		vi.eb(x,y);
		mpi[pii(x,y)] = 1;
	}
	sort(vi.begin(), vi.end());
	sort(vi.begin()+1 , vi.end(), 
	[](const pii &a , const pii &b)->bool{return comp(a,b);});
	cvh.eb(vi[0]);
	cvh.eb(vi[1]);
	int idx = 1;
	for(int i = 2 ; i <n+m ; ++i){
		while(idx != 0 and !isleft(idx,vi[i])){
			cvh.pop_back();
			--idx;
		}
		cvh.eb(vi[i]);
		++idx;
	}
	
	bool hve = false;
	for(pii x : cvh){
	//	printf("|%d %d|\n",x.fi ,x.se);
		if(mpi.find(x) != mpi.end())hve = true;
	}
	printf("%s",(hve)? "NO" : "YES");
 }
