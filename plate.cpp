#include <bits/stdc++.h>
 
 using namespace std;
int cls[10010] = {};
 bool inq[11] ={};
 queue<int> q[11]; 
 queue<int> cq;
 int main(){
 	int N , S ;
	scanf("%d%d",&N, &S );
	for(int i =0 ; i  <S ; ++i){	
		int c , id;
		scanf("%d%d",&c,&id);
		cls[id] = c;
	}
	while(true){
		string A;
		cin >> A;
		if(A == "E"){
			int x;
			scanf("%d",&x);
			q[cls[x]].push(x);
			if(not inq[cls[x]]){
				inq[cls[x]] = true;
				cq.push(cls[x]);
			}
		}else if(A == "D"){
			if(cq.empty()){
				printf("empty\n");
			}else{
				printf("%d\n",q[cq.front()].front());
				q[cq.front()].pop();
				if(q[cq.front()].empty()){
					inq[cq.front()] = false;
					cq.pop();
				}	
			}
		}else {
			printf("0");
			break;	
		}

	}
 }
