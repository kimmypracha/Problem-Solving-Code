#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 5e5+10;
 int arr[lim];
  int n, b;
 bool can(int now ){
	int ans = 0;
	for(int i = 0 ; i <n ; ++i){
		ans += (arr[i]%now == 0)? arr[i]/now : arr[i]/now + 1 ;
	}
	if(ans <= b)return true;
	else return false;	
 }
 int main(){
	scanf("%d%d",&n,&b);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&arr[i]);
	}
	int l = 1 , r = 2e6+1;
	int m;
	while(l < r){
		m = (l+r)/2;
		if(can(m)){
			r = m;
		}else{
			l = m+1;
		}
	} 
	printf("%d",l);
 }
