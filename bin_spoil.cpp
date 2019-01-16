#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 const int lim = 1e6 + 10; 
 int In[lim] , Out[lim];
vector<int> vi;
int sta[lim] , stb[lim];
  int main(){
	int Q;
	scanf("%d",&Q);
	while(Q--){
		vi = vector<int>();
		int N , X, Y , Z;
		scanf("%d%d%d%d",&N,&X,&Y,&Z);
		for(int i =0 ; i  < N ; ++i){
			int A,  B;
			scanf("%d%d",&A , &B);
			B++;
			In[i] = A;
			Out[i] = B;
			vi.eb(A);
			vi.eb(B);	
		}
		sort(vi.begin() , vi.end());
		auto it = unique(vi.begin() , vi.end());
		vi.resize(it-  vi.begin());
		fill(sta , sta + lim , 0);
		fill(stb , stb + lim , 0);
		for(int i =0 ;  i <  N;  ++i){
			int A  = lower_bound(vi.begin() , vi.end() , In[i]) - vi.begin();
			int B  = lower_bound(vi.begin() , vi.end() , Out[i]) - vi.begin();
			sta[A]++;
			stb[B]--;
		}
		int bef = 0 , now = 0;
		int Ans = max(N*X , N*Z);
		for(int i =0 ;  i < vi.size() ;++i){
			now += sta[i];
			now += stb[i];
			bef -= stb[i];
			
//			printf("%d : %d %d\n",vi[i],bef,now );
			Ans = max(Ans , bef*X + now*Y + (N-now-bef)*Z);
		}
		printf("%d\n",Ans);

	}
  }
