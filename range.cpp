#include <bits/stdc++.h>
 
 using namespace std;
  typedef long long int lli;
  const int lim = 1e6 + 10;
  int arr[lim];
  lli sve[lim] = {};
  deque<int> mx , mn;
  int main(){
  	int n , p , q;
	scanf("%d%d%d",&n,&p,&q);
	int st = 0;
	lli ans = 0;
	for(int i =0  ; i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	for(int i =0 ; i < n and p;  ++i){
		while(not mn.empty() and arr[mn.back()] >= arr[i])mn.pop_back();
		while(not mx.empty() and arr[mx.back()] <= arr[i])mx.pop_back();
		mn.push_back(i);
		mx.push_back(i);
		while(arr[mx.front()] - arr[mn.front()] >= p){
			st++;
			while(mn.front() < st)mn.pop_front();
			while(mx.front() < st)mx.pop_front();
		}
		sve[i] =(lli)(i-st+1);
	}
	mn.clear();
	mx.clear();
	st = 0 ;
	for(int i = 0 ; i < n ; ++i){
		while(not mn.empty() and arr[mn.back()] >= arr[i])mn.pop_back();
		while(not mx.empty() and arr[mx.back()] <= arr[i])mx.pop_back();
		mn.push_back(i);
		mx.push_back(i);
		while(arr[mx.front()] - arr[mn.front()] > q){
			st++;
			while(mn.front() < st)mn.pop_front();
			while(mx.front() < st)mx.pop_front();
		}
		ans += (lli)(i-st+1) - sve[i];
	}
	printf("%lld",ans);
  }
