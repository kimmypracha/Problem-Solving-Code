#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
  using namespace std;
 typedef long long int lli;
 typedef pair<lli,lli> pii; 
const int lim = 5e5+10;
 lli x[lim] , y[lim];
 lli s;
 int n;
 bool can(lli pow){
 	vector<pii> vx, vy;
	for(int i = 0;  i < n ; ++i){
		vx.eb(x[i]-pow , x[i]+pow);	
		vy.eb(y[i]-pow , y[i]+pow);	
	}
	for(int i = 0 ;i  < n; ++i){
		printf("(%d %d) ",vx[i].fi ,vx[i].se);
	}
	printf("\n");
	for(int i =0 ; i  < n ; ++i){
		printf("(%d %d) ",vy[i].fi,vy[i].se);
	}
	printf("\n:::");
	sort(vx.begin() , vx.end());
	sort(vy.begin() , vy.end());
	lli nx = 0 , ny = 0;
	//printf(":: %d\n",vx[0].fi);
 	bool ax = true, ay = true;
	if(vx[0].fi > 0)ax = false;
	nx = vx[0].se;
	for(int i =0  ; i < n ; ++i ){
	//	printf("%d %d\n",vx[i].fi , nx);
		if(vx[i].fi > nx)ax = false;
		nx = max(nx,vx[i].se);
	}
	//printf("y::%d\n",vy[0].se);
	if(vy[0].fi > 0)ay = false;
	ny = vy[0].se;
//	printf("SHOW");
	for(int i = 0 ; i < n ; ++i){
		if(vy[i].fi > ny)ay = false;
		ny = max(ny,vy[i].se);
	}
//	printf("show :%d %d\n",nx,ny);
	if((nx <= s and ax) or (ny <= s and ay))return true;
	return false;
 }
 int main(){
	scanf("%lld%d",&s,&n);
	s *= 1000LL;
	for(int i = 0 ; i < n ; ++i){
		scanf("%lld%lld",&x[i],&y[i]);
		x[i]*=1000LL;
		y[i]*=1000LL;
	} 
	sort(x , x + n);
	sort(y , y + n);
	lli l = 1 , r = s+1;
	lli m;
	cout << "Hello "<<  can(500);
	return 0;
	while(l < r){
		m = (l+r)/2;
//		printf("%lld %lld\n",l,r);
		if(can(m)){
		//	printf("%lld can \n",m);
			 r = m;
		}else{
			l = m+1;
		}
	}	
	printf("%.3lf",(double)l/1000);
 }
