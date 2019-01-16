#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
  vector<int> vi;
  int main(){
  	int n , m , k;
	scanf("%d%d%d",&n,&m,&k);
	int tmp = 0;
	for(int i = 1 ; i <= m ; ++i){
		int x;
		scanf("%d",&x);
		if(i != 1){
			vi.eb(x-tmp-1);
		}
		tmp = x;
	}
	sort(vi.begin() , vi.end() , greater<int>());
	if(k-1 >= (int)vi.size()){
		printf("0");
	}else{
		int sum = 0;
		for(int i = k-1 ; i < vi.size() ; ++i){
			sum += vi[i];
		}
		printf("%d",sum);
	}
  }
