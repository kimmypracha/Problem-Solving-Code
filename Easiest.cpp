#include <bits/stdc++.h>

 using namespace std;
 const int lim = 2e6 + 10;
 priority_queue<int> pq;
  int main(){
	ios_base::sync_with_stdio(false);
 	int P , d;
	char op[5];
	scanf("%d",&P);
	for(int i =0 ; i  < P ; ++i){
		scanf("%s",op);
		if(op[0] == 'A'){
			scanf("%d", &d);	
			pq.push(-d);
		}else{
			if(pq.empty())printf("-1\n");
			else {
				printf("%d\n",-pq.top());
				pq.pop();
			}
		}
	}
 }
