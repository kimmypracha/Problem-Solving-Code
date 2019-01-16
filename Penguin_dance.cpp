#include <bits/stdc++.h>



using namespace std;

stack<int> st;

int main() {

    int n , p , t;

    scanf("%d%d%d",&n,&p,&t);

    int x = 1;

    for(int i = 0 ; i < t ; ++i){

            if(i%9 == 4)x+=1;

            else if(i%9 == 5)x-=1;

            else if(i%9 >= 6)x+=1;

    }

    if(p < x)printf("-1");

    else if(x+n-1 < p)printf("-1");

    else{

            printf("%d",p-x+1);

    }

}
