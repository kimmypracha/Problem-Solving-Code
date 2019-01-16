#include <bits/stdc++.h>

 using namespace std;
 vector<int> A[101] , B[101];
 bool ch(int st){
	bool a1 = true;
 	for(int i = 0 ; i < 101; ++i){
		bool tmp = false;
		for(int j : A[i]){
			tmp |= (j >0)? ((st>>abs(j))!=0) : ((st>>abs(j))==0); 
		}
		if(not A[i].empty())
			a1 &= tmp;
	}
	bool b1 = true;
	for(int i = 0; i < 101 ; ++i){
		bool tmp  = false;
		for(int j : B[i]){
			tmp |= (j>0)? ((st>>abs(j))!=0) : ((st>>abs(j))==0);
		}
		if(not B[i].empty())
			b1 &= tmp;
	}
	return ((!a1)||b1);
 }
 int main(){
 	int t;
	scanf("%d",&t);
	while(t--){
		int n , m;
		scanf("%d%d",&n,&m);
		for(int i = 0 ;i < 101 ; ++i){
			A[i].clear();
			B[i].clear();
		}
		for(int i = 0 ; i < n ;++i){
			int s ;
			char st[3];
			scanf("%d" , &s);
			for(int j = 0 ; j < s;  ++j){
				scanf("%s",st);
				if(st[0] == '+')A[i].push_back(st[1]-'a');
				else A[i].push_back(-(st[1]-'a'));
			}
		}
		for(int i = 0; i  < m ; ++i){
			int s;
			char st[3];
			scanf("%d" , &s);
			for(int j = 0 ; j < s ; ++j){
				scanf("%s" , st);
				if(st[0] == '+')B[i].push_back(st[1] - 'a');
				else B[i].push_back(-(st[1]-'a'));
			}
		}
		bool ans = true;
		for(int i = 0 ; i < (1<<16) ; ++i){
			ans &= ch(i);
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
 	}
 }
