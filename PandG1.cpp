#include <bits/stdc++.h>
#define rep(i , j , k ) for(int i = j ; i <= k ;++i)
#define fi first
#define se second
 using namespace std;
    typedef struct node {
        int x  ,y , t;
        node(int a , int b , int c) : x(a) , y(b) , t(c) {};
    };
  bool dp[1<<10][1<<7][1<<7];
  char arr[1<<7][1<<7];
  int dir[2][4] = {{1, 0, -1 , 0} , {0 , 1,  0 ,-1}};
  queue<node> q;
  int main(){
    int k;
    int R , C  , n , T  , r  ,c  ;
    int x  , y , t , A , B ;
    bool F;
    scanf("%d",&k);
    while(k--){
    scanf("%d%d%d%d%d%d", &R,&C, &n ,&T, &r , &c);
    rep(i ,0 , T ){
        rep(j , 0 , R-1){
            rep(k , 0 ,C-1){
                dp[i][j][k] = false;
            }
        }
    }
    rep(i ,1 , n){
        scanf("%d%d%d" , &t , &x, &y);
        if(not dp[t][x][y])q.emplace(x , y, t);
	for(; t <= T and not dp[t][x][y]; ++t) dp[t][x][y] = true;
    }
    rep(i ,0 , R-1){
        scanf("%s",arr[i]);
    }
    while(not q.empty()){
         x = q.front().x;
         y = q.front().y;
         t = q.front().t;
//        printf("Ghost : %d %d %d \n" , t ,x , y);
//        getch();
        q.pop();
        if(t == T) continue;
        rep(i , 0  , 3  ){
            A = x + dir[0][i];
            B = y + dir[1][i];
            if(A < 0 or B < 0 or A >= R or B >= C) continue;
            if(not dp[t+1][A][B] and arr[A][B] != '#'){
                    dp[t+1][A][B] = true;
                q.emplace(A , B , t+1);
            }
        }
	for( ; t <= T ; ++t)dp[t][x][y] = true;
    }
    F = true;
    if(not dp[0][r][c]) q.emplace(r ,c , 0);
    while(not q.empty()){
         x = q.front().x;
         y = q.front().y;
         t = q.front().t;
        q.pop();
//        if(dp[t][x][y]) continue;
//        printf("Pac : %d %d %d \n", t , x  ,y);
        dp[t][x][y] = true;
        if(t == T){
            q = queue<node>();
            printf("YES\n");
            F = false;
            break;
        }
        rep(i , 0  , 3 ){
             A  = x  + dir[0][i];
             B  = y  + dir[1][i];
            if(A < 0 or B < 0 or A >= R or B >= C) continue;
            if(not dp[t+1][A][B] and arr[A][B] != '#'){
                dp[t+1][A][B] = true;
                q.emplace(A , B  ,t+1);
            }
        }
        for(t = t+1;t <= T and not dp[t][x][y]; ++t){
		dp[t][x][y] = true;
		if(t == T){
			q = queue<node>();
			printf("YES\n");
			F = false;
		}
	}
	if(not F)break;
    }
    if(F)printf("NO\n");
    }
  }
