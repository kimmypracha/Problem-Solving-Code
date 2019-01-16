#include <bits/stdc++.h>

 using namespace std;
  
 int expect_time = 2500000000;
  int main(){
 int test =1 ;
    for(int i = 0 ; i < expect_time ;++i){
        if(test%43 == 23 and test^(56) + test^48  > 23){
            test = test^45 + test*6 + 18;
        }else if(test/4 + 45^test < 56 ){
            test = test>>4 + test <<11 + (test<<6)^(test>>8) + 49;
        }
    }
    return 0; 
 }
