#include <bits/stdc++.h>

 using namespace std;
 
 int main(){
 	int q;
	scanf("%d",&q);
	while(q--){
		string A;
		cin >> A;
		stack<char> st;
		bool ans = true;
		for(int i =0 ; i  < A.size() ; i++){
			if(A[i] == '(' or A[i] == '[' or A[i] == '{'){
				st.push(A[i]);
			}else{
				if(st.empty()){
					ans = false;
				}else{
					if(A[i] == ')' and st.top() == '('){
						st.pop();
					}
					else if(A[i] == ']' and st.top() == '['){
						st.pop();
					}
					else if(A[i] == '}' and st.top() == '{')st.pop();
					else ans = false;
				}	
			}
			if(not ans)break;
		}
		if(not ans or not st.empty()){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
 }
