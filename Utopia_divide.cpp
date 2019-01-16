#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  const int lim = 2e4 + 10;
  int num[lim];
  int arr[lim];
  int brr[lim];
  int que[lim];
  vector<int> xl , yl;
 int a1= 1 , a2 = 4 , b1 =2 ,b2 = 3;
 bool issame(int x , int y){
 	if((x == a1 or x == a2) and (y == a1 or y == a2))return true;
 	if((x == b1 or x == b2) and (y == b1 or y == b2))return true;
	return false;
 }
  int main(){ 
  	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < 2*n ; ++i){
		scanf("%d",&num[i]);
	}
	sort(num , num + 2*n);
	for(int i = 0 ; i < 2*n ; ++i) {
		if(i&1)brr[i/2] = num[i];
		else arr[i/2] = num[i];
	}
	for(int i =0 ;  i < n ; ++i){
		scanf("%d",&que[i]);
	}
	int c = 0 ;
	for(int i =1 ; i < n ; ++i){
		if(not issame(que[i] , que[i-1]))c++;
	}
	int a , b ;
	a  = b  = n-1-c;
	int pos = (issame(que[0] , 1))? arr[b] : -arr[b];
	if(issame(que[0] , 1))xl.eb(arr[b]);
	else xl.eb(-arr[b]);
	b++;
	for(int i = 1 ; i < n ; ++i){
		 if(not issame(que[i] , que[i-1])){
			if(issame(que[i] , 1))xl.eb(arr[b]) , pos += arr[b++];
			else xl.eb(-arr[b]) , pos -= arr[b++];
		}else{
			if(abs(pos) > arr[--a]){
				if(issame(que[i] , 1))xl.eb(-arr[a]) ,pos -= arr[a];
				else xl.eb(arr[a]) , pos += arr[a]; 
			}else{
				if(issame(que[i] , 1))xl.eb(arr[a]) , pos += arr[a];
				else xl.eb(-arr[a]) , pos -= arr[a];
			}
		}	
	}
	// Change a1 , a2 , b1, b2 
	a1 = 1 ;
	a2 = 2;
	b1 = 3;
	b2 = 4;
	c =  0;
	pos = 0;
	for(int i =1 ; i  < n ; ++i){
		if(not issame(que[i] , que[i-1]))c++;
	}
	a = b = n-1-c;
	if(issame(que[0] , 1)){
		yl.eb(brr[b]);
		pos += brr[b++];
	}else{
		yl.eb(-brr[b]);
		pos -= brr[b++];
	}
	for(int i = 1 ; i < n ;++i){
		if(not issame(que[i] , que[i-1])){
			if(issame(que[i] , 1)){
//				cout << "A" ;
				pos += brr[b];
				yl.eb(brr[b++]);
			}else{
//				cout << "B";
				pos -= brr[b];
				yl.eb(-brr[b++]);
			}	
		}else{
			if(abs(pos) > brr[--a]){
//				cout << "C";
				if(issame(que[i] , 1))yl.eb(-brr[a]) , pos -= brr[a];
				else yl.eb(brr[a]) , pos += brr[a];
			}else{
//				cout << "D" << pos << " " << brr[a] << "\n";
				if(issame(que[i] , 1))yl.eb(brr[a]) , pos += brr[a];
				else yl.eb(-brr[a]) , pos -= brr[a];
			}
		}
	}
	for(int i =0 ; i < n ; ++i){
		printf("%+d %+d\n" ,xl[i] , yl[i]);
	}
}
