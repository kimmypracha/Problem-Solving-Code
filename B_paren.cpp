#include <bits/stdc++.h>
#define psh push_back
#define pop pop_back
  using namespace std;
 vector<char> st;
 int main(){
 	string A;
	cin >> A;
	int n = A.size();
	int cnt = 0 ;
	for(int i =0  ; i< n;  ++i){
		if(A[i] == '(')st.psh('(');
		else if(A[i] == ')' and not st.empty() and st.back() == '('){
			st.pop();
			cnt+= 2;
		}
	}
	printf("%d",cnt);
 }
