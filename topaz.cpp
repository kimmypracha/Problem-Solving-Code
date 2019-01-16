#include <bits/stdc++.h>

  using namespace std;
   typedef long long int lli;
   char A[100] , B[100] , C[100] , D[100];
   int dp[52][52][52][52] = {};
    template<typename T>
	T Max(T now){
		return now;
	}
    template<typename T , typename... Args>
	T Max(T now , Args... arg){
		return max(now , Max(arg...));
	}
    int res(int a , int b ,int c , int d){
    	for(int i = 0 ; i <= a ; ++i){
		for(int j = 0 ; j <= b ; ++j){
			for(int k = 0 ; k <= c ; ++k){
				for(int l = 0 ; l <= d ; ++l){
					dp[i][j][k][l] = 0;
				}
			}
		}
	}
    }
    int main(){
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%s%s%s%s",A , B, C , D);
            int a = strlen(A);
            int b = strlen(B);
            int c  = strlen(C);
            int d = strlen(D);
            for(int i = 0 ; i <= a ; ++i){
                for(int j = 0 ; j <= b ; ++j){
                    for(int k = 0 ; k <= c ; ++k){
                        for(int l = 0 ; l <= d ; ++l){
			   if(i == 0 or j == 0 or k == 0 or l == 0)continue;
                            dp[i][j][k][l] = Max( dp[i-1][j][k][l] , dp[i][j-1][k][l] ,  dp[i][j][k-1][l]  ,  dp[i][j][k][l-1]

                                            , dp[i-1][j-1][k][l] , dp[i-1][j][k-1][l]  , dp[i-1][j][k][l-1]
                                            , dp[i][j-1][k-1][l] , dp[i][j-1][k][l-1] , dp[i][j][k-1][l-1]

                                            , dp[i-1][j-1][k-1][l] , dp[i-1][j-1][k][l-1] , dp[i-1][j][k-1][j-1] , dp[i][j-1][k-1][l-1]

                                            , dp[i-1][j-1][k-1][l-1]);
                            if(A[i-1] == B[j-1] and B[j-1] == C[k-1] and C[k-1] == D[l-1]){
                                dp[i][j][k][l] = 1 + dp[i-1][j-1][k-1][l-1] ;
                            }
                        }
                    }
                }
            }
	    
	    res(a, b, c,d);
        }
    }
