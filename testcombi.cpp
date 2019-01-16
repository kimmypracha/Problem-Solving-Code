#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
char a[] = {'a' ,'b' , 'c'};
int b[] = {1 , 2 ,3 ,4};
 int cnt = 0 ;
 vector<int> st;
 int arr[4] = {};
 bool vis[4] = {};
 void rec(int now){
	if(now == 3){
		if(arr[0] == 2 or arr[1] == 2 or arr[1] == 3){
			printf("STart %d: \n", cnt);
			for(int i = 0 ; i < 3 ; ++i){
	//			if(arr[i] != 0 )printf("%c %d\n",a[i] , arr[i]);
			}
			cnt = cnt + 1;
	//		printf("End %d\n",cnt);
		}
		return;
	}
  	for(int i = 1 ; i <= 4 ; ++i){
		if(not vis[i]){
		arr[now] = i;
		vis[i] = true;
		rec(now+ 1);
		vis[i] = false;
		}
	}
 }
  int main(){
  	 rec(0);
 	printf("%d\n",cnt);
 }
