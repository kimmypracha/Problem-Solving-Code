#include <bits/stdc++.h>

  using namespace std;
  vector<int> vi;
  int main(){
 	int A , B , K;
	scanf("%d%d%d",&A,&B,&K);
	for(int i  = A ; i < min(A + K , B +1) ; ++i){
		vi.push_back(i);
	}
	for(int i = B ; i > max(B-K , A-1) ; --i){
		vi.push_back(i);
	}
	sort(vi.begin() , vi.end());
	vector<int>::iterator it = unique(vi.begin() , vi.end());
	vi.resize(distance(vi.begin() ,it ));
	for(int i =0 ; i  < vi.size() ; ++i){
		printf("%d\n",vi[i]);
	}
  }
