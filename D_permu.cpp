#include <bits/stdc++.h>

  using namespace std;
   const int lim = 1e5  + 10;
   long long int arr[lim];
    long long int gcd(long long int a , long long int b){
        return (!b)? a : gcd(b , a%b);
    }
    int main(){
            int n;
            scanf("%d",&n);
            long long int ans = 0;
            for(int i =1 ; i <= n ; ++i){
                scanf("%lld",&arr[i]);
                ans += arr[i]*(4L*(long long int )i - 2L*n - 1);
            }
            long long int g = gcd(ans , n);
            ans /=g ;
            n /= g;
            printf("%lld %lld",ans,n);
    }
