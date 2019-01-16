#include <bits/stdc++.h>

  using namespace std;
  int arr[10010];
  bitset<1000010> bs = 1;
  int main(){ 
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&arr[i]);
		bs |= (bs<<arr[i]);
	}
	int k = 0 ;
	while(scanf("%d",&k)!=EOF){
		if(k >= 1000010){
			printf("NO\n");
		}else{
			printf("%s\n",(bs[k])? "YES" : "NO");
		}
	}
  }
