#include <bits/stdc++.h>
#define input() (*std::istream_iterator<int>(std::cin))
#define rep(i,k,n) for(auto i=k;i!=n;++i)
typedef long long lli;
typedef std::vector<lli> Vec;
typedef std::vector<Vec> Vvc;
const lli inf = 1e12;

int main(){
    lli n = input();
    int k = input();
    int lm = 1 << (k);
    int mk = 1 << (k-1);
    Vec nw(lm,0);
    Vvc dp(lm,Vec(lm, -inf));
    rep(i,0,lm){
        dp[i>>1][i] = dp[i>>1|mk][i] = input();
    }
    for (n -= k-1; n != 0; n >>= 1){
        if(n & 1){
            Vec nx(lm, -inf);
            rep(i,0,lm){
            rep(j,0,lm){
                nx[i] = std::max(nx[i], dp[i][j] + nw[j]);
            }}
            nw = std::move(nx);
        }
        Vvc tm(lm,Vec(lm, -inf));
        rep(i,0,lm){
        rep(j,0,lm){
        rep(k,0,lm){
            tm[i][j] = std::max(tm[i][j], dp[i][k] + dp[k][j]);
        }}}
        dp = std::move(tm);
    }
    std::cout << *std::max_element(nw.begin(), nw.end());
}
