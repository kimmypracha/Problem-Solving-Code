#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  const int lim = 1e5 + 10;
  vector<int> vi;
  int arr[lim];
  int brr[lim] = {};
  int main(){
  	int n , m;
	scanf("%d%d",&n,&m);
	brr[0] = -1;
	for(int i =1  ; i <= n ; ++i){
		scanf("%d",&arr[i]);
		vi.eb(i);
	} 
	brr[n+1] = -1;
	sort(vi.begin() , vi.end(),[=](const int &a ,const int &b) -> bool{return (arr[a] == arr[b])? a < b : arr[a] >  arr[b];});
//	for(int i = 0 ; i < n ; ++i){
//		cout << vi[i] << " ";
//	}
//	printf("\n");
	int idx = 0;
	for(int i = 0 ; i < m ;++i){
		int L;
		scanf("%d",&L);
		int cnt = 0;
		queue<int> q;
	//	printf(":: %d\n",arr[vi[idx]]);
		while(idx < n and arr[vi[idx]] > L ){
			if(brr[vi[idx]] != -1){
				q.push(vi[idx]-1);
				q.push(vi[idx]+1);
				cnt++;
				brr[vi[idx]] = -1;
			}
			idx++;
		}
	//	printf("::%d ",cnt);
		while(not q.empty()){
			int now = q.front();
			q.pop();
			if(brr[now] != -1)cnt++;
			brr[now] = -1;	
		}
		printf("%d\n",cnt);
	}
  }
