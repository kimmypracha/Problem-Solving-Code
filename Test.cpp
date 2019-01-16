#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int g=m-1;
    printf("#\n");
    for(int i=0;i<m;i++){
        if(i==0){
            continue;
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<g;k++){
                printf(" ");
            }
            for(int k=0;k<1+(2*i);k++){
                printf("#");
            }
            for(int k=0;k<g;k++){
                printf(" ");
            }
            printf("\n");
        }
        g--;
    }
}

