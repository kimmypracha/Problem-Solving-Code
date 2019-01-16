#include <bits/stdc++.h>
#define fi first
#define se second
 using namespace std;
typedef pair<int,int> pii;
 const int lim = 1e3 + 10;
 char Arr[lim][lim]; 
 int DP[lim][lim];
 int dir[2][4] = {{1 , 0 , -1 , 0}, {0 , 1 , 0 , -1}};
 int main(){
  	int Q;
	scanf("%d",&Q);
	while(Q--){
		int R , C;
		scanf("%d%d",&R,&C);
		for(int i =0 ;  i < R ;++i){
			scanf("%s",Arr[i]);
			fill(DP[i] , DP[i] + C , 1e9 + 10);
		}
		queue<pii> q; 
		for(int i =0  ; i < R ; ++i){
			for(int j = 0 ; j < C ;++j){
				if(Arr[i][j] == 'A'){
					q.push({i,j});
					DP[i][j] = 0;
					break;
				}
			}
			if(not q.empty())break;
		}
		bool hva = false;
		while(not q.empty()){
			int x = q.front().fi;
			int y = q.front().se;
			q.pop();
			if(Arr[x][y] == 'B'){
				printf("%d\n",DP[x][y]);
				hva = true;
				break;	
			}
			for(int i =0 ; i < 4 ; ++i){
				int A = x + dir[0][i];
				int B = y + dir[1][i];
				if(A < 0 or B < 0 or A >= R or B >= C)continue;
				if(DP[A][B] > DP[x][y] + 1 and Arr[A][B] != '#' ){
					DP[A][B] = DP[x][y] + 1; 
					q.push({A,B});
				}
			}
		}
		if(not hva)printf("-1\n");
	} 
 }
