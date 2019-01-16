#include <bits/stdc++.h>

 using namespace std;
 
 int main(){
 	int n , x , y , A;
	printf("Please enter number of terminal number (n) :\n ");
	scanf("%d",&n);
	printf("Please enter minimum number that can count (x) :\n ");
	scanf("%d", &x);
	printf("Please enter maximum number that can count (y) : \n");
	scanf("%d" , &y);
	A = (n-x)%(y+x);
	if(A!=x and A != y and A != (x+y) and !(x <= A and A <= y)) 
		printf("Error Sequence\n");
	else if(A == 0){
		printf("No way that player1 can win\n");
	}else {
		printf("Optimal Solution that player1 can win\n");
		for(; A <= n; A += x+y){
			printf("%d ",A);
		}
		printf("\n");
	}
 }
