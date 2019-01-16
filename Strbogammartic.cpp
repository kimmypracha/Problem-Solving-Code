#include <bits/stdc++.h>
#define eb emplace_back
  using namespace std;
  int idx = 0 ; 
  queue<int> q;
  bool tomirror(int x){
	int tmp = x , mir = 0;
	while(!q.empty())q.pop();
	while(tmp){
		if(tmp%10 == 0 or tmp%10 == 1 or tmp%10 == 8 or tmp%10 == 6 or tmp%10 == 9){
			if(tmp%10 == 6) q.push(9);
			else if(tmp%10 == 9) q.push(6);
			else q.push(tmp%10);	
		}else return false;
		tmp /= 10;
	}
	while(!q.empty()){
		mir *= 10;
		mir += q.front();
		q.pop();
	}
	if(mir == x)return true;
	else return false;	
  }
  int main(){
  	int n;
	scanf("%d",&n);
	for(int i = 0 ; ; ++i){
		if(tomirror(i))idx++;
		if(idx == n){
			printf("%d",i);
			break;
		}
	}
	//printf("%d",idx);
  }
