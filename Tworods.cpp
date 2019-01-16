#include <bits/stdc++.h>
#include <crectlib.h>
 using namespace std;
 
  int main(){
  	int n = gridsize();
	int l = 1 , r = n+1;
	int m;
	while(l < r){
		m = (l+r)/2;
		if(rect(1,n,1,m)){
			r = m;
		}else{
			l = m+1;
		}	
	}
	int a = l;
	l = 1;r = n+1;
	while(l < r){
		m = (l+r)/2;
		if(rect(1,n,m,n)){
			l = m+1;	
		}else{
			r = m;
		}
	}
	int b = l-1;
	l = 1 , r = n+1;
	while(l < r){
		m = (l+r)/2;
		if(rect(1,m,1,n)){
			r = m;	
		}else{
			l = m+1;
		}
	}
	int c = l;
	l = 1 , r = n+1;
	while(l < r){
		m = (l+r)/2;
		if(rect(m,n,1,n)){
			l = m+1;
		}else{
			r = m;
		}
	}
	int d = l-1;
	int a1,b1,a2,b2, c1,d1,c2,d2;
	if(!rect(c,c,a,a)){
		l =  a ; r = b+1;
		while(l < r){
			m = (l+r)/2;
			if(rect(c,c,a,m)){
				r = m;
			}else{	
				l = m+1;
			}
		} 
	}else if(!rect(d,d,a,a)){
		l = a; r = b+1;
		while(l < r){
			m = (l+r)/2;
			if(rect(d,d,a,m)){
				r = m;
			}else{
				l = m+1;
			}	
		}
		
	}	
  }
