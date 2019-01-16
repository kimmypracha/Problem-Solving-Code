#include <bits/stdc++.h>

 using namespace std;
 vector<int> vi;
 int main(){
	int n;
	scanf("%d",&n);
	for(int i =0 ; i < n; ++i){
		int A;
		scanf("%d",&A);
		int idx = upper_bound(vi.begin(), vi.end() , A) - vi.begin();
		if(idx == vi.size()) vi.push_back(A);
		else vi[idx] = A;
	}
	printf("%d",n - vi.size());
 }
