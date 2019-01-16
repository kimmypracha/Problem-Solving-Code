#include <bits/stdc++.h>
 
 using namespace std;
 
 int main(){
  	int n;
	while(scanf("%d",&n)!= EOF){
		set<long long int > st;
		long long int sum = 0 ;
		for(int i = 1 ; i <= n; ++i){
			long long int A;
			scanf("%lld",&A);
			printf("%d:",i);
			while(not st.empty() and *(st.begin()) < A){
				sum += *(st.begin());
				printf("%d ",*st.begin());
				st.erase(st.begin());
			}
			printf("\n");
			st.insert(A);
		}
		printf("%lld\n",sum);
	}
 }
