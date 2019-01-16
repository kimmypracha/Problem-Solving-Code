#include <bits/stdc++.h>

  using namespace std;

  int main(){
  FILE *fp = fopen("textshow.txt" , "r");
  char c;
  do{
  	c = fgetc(fp);
	if(c!=EOF)
	printf("%c",c);
  }while(c != EOF);
  fclose(fp);
 }
