#include <bits/stdc++.h>

 using namespace std;
 const int lim  = 1e6 +10;
 int In[lim] , Out[lim];
  int main(){
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int N , X , Y , Z;
		scanf("%d%d%d%d",&N,&X,&Y,&Z);
		for(int i =0 ;  i < N ; ++i){
			scanf("%d%d",&In[i] , &Out[i]);
			Out[i]++;
		}
		sort(In , In + N);
		sort(Out , Out + N);
		int i  =0  , j = 0 ;
		int bef = 0 , now = 0;
		int Ans = max(N*Z,N*X);
		int lst = 0;
		while(i < N  and j <  N){
			if(In[i] < Out[j] ){
				now++;
				if((i+1 == N or In[i] != In[i+1] )and In[i] != Out[j])
				Ans = max(Ans , bef*Z + now*Y + (N-now-bef)*X); 	
				++i;
			}else{
				now--;
				bef++;	
				if((j+1 == N or Out[j] != Out[j+1] )and In[i] != Out[j]) 
				Ans = max(Ans , bef*Z + now*Y + (N-now-bef)*X);	
				++j;
			}
			
		}
		while(j <N){
			now--;
			bef++;
			if(j+1 == N or Out[j] != Out[j+1])
			Ans = max(Ans , bef*Z + now*Y + (N-now-bef)*X);
			++j;
		}
		printf("%d\n",Ans);
	}
 }
