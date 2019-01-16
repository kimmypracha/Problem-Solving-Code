#include <bits/stdc++.h>  
#define fi first
#define se second
#define eb emplace_back
 using namespace std;
 typedef pair<double , double> pii;
 vector<pii> vs;
 priority_queue<double> pq;
 int main(){
  	double h;
	int q;
	scanf("%lf%d",&h,&q);
	for(int i = 0 ; i < q ;++i){
		double t , h;
		scanf("%lf%lf",&t,&h);
		vs.eb(t,h);
	}
	for(int i = 0 ; i <q ; ++i){
		double now = h;
		pq.push(vs[i].se);
		
	}
	
  }
