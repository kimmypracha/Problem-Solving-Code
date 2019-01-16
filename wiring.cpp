#include <bits/stdc++.h>

  using namespace std;
  const int lim = 1e5+10;
  int arr[lim];
  int brr[lim];
  int u[lim] , d[lim];
  map<int,int> mpi;
  int main(){
  	int t;
	scanf("%d",&t);
	while(t--){
		mpi.clear();
		fill(u , u + lim , 0);
		fill(d , d+ lim , 0);
		int n;
		scanf("%d",&n);
		for(int i =0 ;  i < n ; ++i){
			scanf("%d",&arr[i]);
			if(arr[i] != 0)
				mpi[arr[i]] = i;	
		}
		bool Can = true;
		for(int i = 0 ; i  < n ; ++i){
			scanf("%d",&brr[i]);
			if(brr[i] == 0)continue;
			if(!Can) continue;
			int pos = mpi[brr[i]];
			if(u[i] == 0 or d[pos] == 0){
				u[pos] = 1;
				d[i] = 1;
			}else{
				Can = false;
			}
		}
		if(Can)printf("YES\n");
		else printf("NO\n");
	}
  }
