#include <bits/stdc++.h>
#define fi first 
#define se second
 using namespace std;
 typedef pair<int,int> pii;
 const int lim = 2020;
 char arr[lim][lim];
 int dp[lim][lim];
 int dir[2][4] = {{1,0, -1, 0},{0, 1 , 0 , -1}};
 queue<pii> q;
 int main(){
 	int n, m;
        int cnt = 0 ;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i  < n ; ++i){
		scanf("%s" ,arr[i] );
	}
	for_each(dp, dp + lim , [=](int* a){fill(a , a + lim, (int)1e9);});
	for(int i =0 ; i < n; ++i){
		for(int j = 0 ; j < m ; ++j){
			if(arr[i][j] == 'X'){
				q.push({i , j });
				dp[i][j] = 0;
			}
		}
	}
	while(not q.empty()){
		int x  = q.front().fi;	
		int y  = q.front().se;
		q.pop();
		for(int i =0 ; i < 4 ; ++i){
			int A =  x + dir[0][i];
			int B =  y + dir[1][i];
			if(A <0  or B < 0 or A >= n or B >=m )continue;
			if(arr[A][B] != 'W' and dp[A][B] > dp[x][y] + 1){
				dp[A][B] = dp[x][y] +1;
				q.push({A,B});
			}
		}	
	}
	long long int Ans = 0;
	for(int i =0 ; i < n; ++i){
		for(int j= 0 ; j < m ; ++j){
			if(arr[i][j] == 'A' and dp[i][j] != 1e9){
				Ans += (long long int)(2*dp[i][j]);
				cnt++;
			}
		}
	}
	printf("%d %lld",cnt ,  Ans);
 }
