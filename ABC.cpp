#include <bits/stdc++.h>
 
 using namespace std;

  int main(){
  	string A;
	cin >> A;
	int a = 0 , b = 0  , c =  0;
	for(int i =0  ;i  < A.size() ; ++i){
		if(A[i] == 'a')a++;
		if(A[i] == 'b')b++;
		if(A[i] == 'c')c++;
 	}
	if(a ==1 and b == 1 and c == 1)printf("Yes");
	else printf("No"); 
 }
