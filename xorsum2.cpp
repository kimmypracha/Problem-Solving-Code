#include <bits/stdc++.h>

  using namespace std;
  const int lim = 2e5 + 10;
  int Arr[lim];
  int main(){
  	int n;
	scanf("%d",&n);
	int sum = 0 , sor = 0 ,idx = 0;
	long long int ans = 0;
	for(int i =0 ; i < n;  ++i){
		scanf("%d",&Arr[i]);
		sum += Arr[i];
		sor ^= Arr[i];
		while(sum != sor){
	//		printf("%d %d\n" ,i , idx);
			ans +=(long long int ) (i -idx);
			sum -= Arr[idx];
			sor ^= Arr[idx];
			idx++;
		}
	}
	while(idx != n){
	//	printf("%d %d\n",n , idx );
		ans += (long long int )(n-idx);
		idx++;
	}
	printf("%lld",ans);
  }
