#include <bits/stdc++.h>

 
 using namespace std;
 
  int main(){
  	FILE *fp = fopen("textshow.txt", "r");
	char c;
	if(fp == NULL){
		printf("Can't Found");
		return 0;
	}
	do{
		c = fgetc(fp);	
		if(c != EOF)printf("%c",c);
	}while(c != EOF);
	fclose(fp);
  }
