#include <bits/stdc++.h>

 using namespace std;
  bitset<1003> bs, a , b;
 int lest(){
 	for(int i = 1002 ; i >= 0 ; i--){
		if(a[i] != b[i])
			return (a[i] == 1 )? 1 : -1;
	}
	return 0;
 }
 void plusa(){
 	for(int i = 1 ;  i < 1003 ; ++i){
		if(a[i] == 1){
			a.reset(i);
		}else{
			a.set(i);
			break;
		}
	}
 }
void plusb(){
 	for(int i = 1 ; i < 1003 ; ++i){
		if(b[i] == 1){
			b.reset(i);
		}else {
			b.set(i);
			break;
		}
	}
 }
  int main(){
	int cnt = 0 ;
 	for(int i = 1 ; i  < 1000 ; ++i ){
		bs.reset();
		bs.set(i);
		bs.set(i+2);
		for(int j = 0 ; j < i ; ++j){
			a.reset();
			b.reset();
			a.set(j);
			a.set(j+2);
			b.set(i-j);
		int cmp = lest();
		if(cmp == 0)continue;
		if(cmp < 0 ){
			plusa();
		}else {
			plusb();	
		}
		if(lest() == 0){
			cnt++;	
		}
		}
	}
	printf("%d",cnt);
 }
 
