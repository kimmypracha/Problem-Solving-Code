#include <bits/stdc++.h>
 
 using namespace std;
 const int lim = 5e5+10;
 struct node{
 	int x , y , st; 
	node(int a , int b ,int c): x(a) ,y(b) , st(c) {};
 };
 int dp[8][lim];
 int dir[2][]
 int main(){
  	int n;
	scanf("%d",&n);
	queue<node> q;
	q.eb(0,1 , 1);
	q.eb(1,1 , 2);
	q.eb(2,1 , 4);
	while(!q.empty()){
		int nx = q.front().x;
		int ny = q.front().y;
		int nst = q.front().st;
		q.pop();
		for(int )
	}
 }
