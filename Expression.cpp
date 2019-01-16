#include <bits/stdc++.h>

 
 using namespace std;	
	char expr[1010];
	int cmd[1010];
	stack<char> st;
	bool wrong;
	int k;
	void op(char *str , int idx){
		int len = strlen(str);
		int cnt = cmd[idx];
		char low = '(';
		if(idx == k and not wrong){
			printf("%s",str);
			return;
		}
		bool hve = false;
		for(int i = 0 ;i  < len ; ++i){
			if(str[i] == '('){
				hve = true;
				st.push(str[i]);
				i++;
				while(not st.empty()){
					if(str[i] == '(')
						st.push(str[i]);
					else if(str[i] == ')')
						st.pop();
					i++;
				}
			}
			if(str[i] == '+')low = str[i];
			else if(str[i] == '*' and low != '+')low = str[i];
			else if(str[i] == '^' and low != '*' and low != '+')low = str[i];
		}
		if(low == '(' and not hve){
			if(cnt != 1){
				wrong = true;
				return;
			}
			op(str, idx+1);
			return;
		}
		else if(low == '('){
			if(cnt != 1){
				wrong = true;
				return;
			}
			str[len-1] = '\0';
			op(str+1 ,idx+1);
			str[len-1] = ')';
			return;
		}
		else{
			char* beg = str;
			for(int i = 0 ; i < len ; ++i){	
				if(str[i] == '('){
					st.push(str[i]);
					i++;
					while(not st.empty()){
						if(str[i] == '(')
							st.push(str[i]);
						else if(str[i] == ')')
							st.pop();
						i++;
					}
				}	
				if(str[i] == low){
					cnt--;
					if(cnt == 0){
						char tmp = str[i];
						str[i] = '\0';
						op(beg , idx+1);
						str[i] = tmp;	
						return;
					}
					beg = &str[i+1];
				}
			}
			cnt--;
			if(cnt == 0){
				op(beg,idx+1);
			}
			else wrong = true;
			return;
		}
	}
 	int main(){
 		int n , m ;
		scanf("%s",expr);
		scanf("%d",&m);
		bool Found = false;
		for(int i = 0 ; i < m ;++i){
		//	printf("\nstring is %s\n" ,expr);
			k = 0;
			while(scanf("%d",&cmd[k]) ,cmd[k] != 0 ){
				k++;
			}
			wrong = false;
			for(int i = k - 1 ; i >= 0; --i){
					printf("op(%d,",cmd[i]);
			}
			printf("p");
			for(int i =0 ;  i < k ; ++i)printf(")");
			printf("=");
			op(expr, 0);
			if(wrong) printf("null");
			printf("\n");
				
		}
	}
