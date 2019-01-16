#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 vector<int> st;
 vector<vector<int> > vvi;
 void pop_up(int idx){
 	int x = vvi[idx].back();
	vvi[idx].pop_back();
	if(vvi[idx].empty())vvi.pop_back();
	if(idx == 0) st.eb(x);
	else{
		for(int i = idx - 1 ; i >= 0 ; --i){
			int pos = upper_bound(vvi[i].begin() , vvi[i].end() , x) - vvi[i].begin();
			pos--;
			swap(vvi[i][pos] , x);
		}
		st.eb(x);
	}
 }
 void push_down(){
	int x= st.back();
	st.pop_back();
 	for(int i = 0 ; i < vvi.size(); ++i){
		int pos = upper_bound(vvi[i].begin() , vvi[i].end() , x) - vvi[i].begin();
		if(pos == vvi[i].size()){
			vvi[i].eb(x);
			return;	
		}
		swap(x , vvi[i][pos]); 
	}
	vvi.eb(vector<int>(1 , x));
 }
 void bt( ){
//	for(int i =0  ; i < vvi.size() ; ++i){
//		cout << vvi[i].size() << " ";
//	}
//	cout << "\n";
//	scanf("%*c");
	if(vvi.empty()){
		for(int i = st.size() -1 ; i>= 0 ; --i){
			printf("%d ", st[i]);
		}
		printf("\n");
		return;
	}
 	for(int i = 0 ; i < vvi.size() ; ++i){
		if( i != vvi.size()-1 and vvi[i].size() == vvi[i+1].size() )continue;
		pop_up(i);
		bt();
		push_down();
	}
 }
 int main(){
 	int r;
	scanf("%d",&r);
	for(int i = 0 ; i < r ; ++i){
		int L;
		scanf("%d",&L);
		vvi.eb(vector<int>());
		for(int j = 0 ; j  < L ; ++j){
			int x;
			scanf("%d",&x);
			vvi[i].eb(x);
		}
	}
	bt();
/*	printf("----------------------------------------------------------\n");
	pop_up(2);
	for(int i = 0 ; i < vvi.size() ; ++i){
		for(int j = 0 ;  j < vvi[i].size() ; ++j){
			printf("%d " , vvi[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------\n");
	push_down();
	for(int i = 0 ; i < vvi.size();   ++i){
		for(int j = 0 ; j < vvi[i].size() ; ++j){
			printf("%d ",vvi[i][j]);	
		}
		printf("\n");	
	}*/
 }
