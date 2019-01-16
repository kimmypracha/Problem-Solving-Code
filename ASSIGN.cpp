#include <bits/stdc++.h>
#define fi first
#define se second
 using namespace std;
 typedef struct pii{
	int first , second;	
 };
 bool asn[21][21];
 map<int , int > mpi;
 queue<pii> q;
 int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		q = queue<pii>();
		mpi = map<int,int>();
		int n;
		scanf("%d",&n);
		for(int i = 0 ; i  < n ; ++i){
			for(int j=  0 ; j  < n ; ++j){
				scanf("%d",&asn[i][j]);
			}
		}
		for(int i = 0 ; i < n ; ++i){
			if(not asn[0][i])continue;
			q.push({1 , (1<<i)});
			mpi[(1<<i)] = 1;
		}
		while(not q.empty()){ 
			int now = q.front().fi;
			int st = q.front().se;
//			printf("%d %d\n" , st ,mpi[st]);
			q.pop();
			if(now == n+1) continue;
			for(int i=0 ; i < n ; ++i ){
				if(not asn[now][i])continue;
//				printf("%d : %d\n",i ,  st&(1<<i));
				if((st&(1<<i)) == 0){
//					printf("IN STEP2\n");
					if(mpi.find(st|(1<<i))==mpi.end()){
						mpi[st|(1<<i)] = mpi[st]; 
						q.push({now + 1,st|(1<<i)});
//						printf("Add Next Step %d\n",st);
					}else{
						mpi[st|(1<<i)] += mpi[st];
					}
				}
			}
		}
		printf("%d\n",mpi[(1<<n)-1]);
	}
 }
