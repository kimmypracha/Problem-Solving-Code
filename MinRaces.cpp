#include <bits/stdc++.h>

#define fi first

#define se second

#define eb emplace_back

#define ls(x) (x&(-x))

using namespace std;

const int lim = 1e5 + 10;

typedef pair<int,int> pii;

vector<pii> vi;

int n , k ;

int ft[lim] = {};

int rsq(int idx){

        int sum = 0 ;

        for(;idx   ; idx -= ls(idx)){

                sum += ft[idx];

        }

        return sum;

}

void update(int idx){

        for(;idx <= k ; idx += ls(idx)){

                ++ft[idx];

        }

}

int main() {

    scanf("%d%d",&n,&k);

    for(int i = 0 ; i < n ; ++i){

            int a , b;

            scanf("%d%d",&a,&b);

            vi.eb(a,b);

    }

    sort(vi.begin() , vi.end() , [](const pii &a , const pii &b)-> bool{return a.se < b.se;});

    int ans = 1;

    for(int i = 0 ; i < n ; ++i){
            ans =max(ans , rsq(k+1 - vi[i].fi)+1); 
            int sh = rsq(k+1 - vi[i].fi) + 1;
//	   printf("%d :%d\n", i , sh);
	    update(k+1 - vi[i].fi);

    }

    printf("%d",ans);

    return 0;

}
