#include <bits/stdc++.h>
#define eb emplace_back
 using namespace std;
 class Point{
	public : 
 		double x ,y , z;
		Point(double a ,double b , double c) : x(a) , y(b) , z(c) {};
		void Rotate(double rad){
			double xp = x*cos(rad) - y*sin(rad);
			double yp = y*cos(rad) + x*sin(rad);
			x = xp;
			y = yp;
		} 
 };
 class Cubic{
	vector<Point> FCP;
 	public :
		Cubic(){
			FCP.eb(0.5 , 0,5 , 0.5);
			FCP.eb(0.5 , 0.5 ,-0.5);
			FCP.eb(0.5 , -0.5 , 0.5);
			FCP.eb(0 ,-0.5 ,-0.5 );
			FCP.eb(-0.5 , 0.5 , 0.5);
			FCP.eb(-0.5 , 0.5 , -0.5);
			FCP.eb(-0.5 ,- 0.5 , 0.5);
			FCP.eb(-0.5 ,-0.5 ,-0.5);
		}
		void Rotate(double rad){
			for(Point& i : FCP){
				i.Rotate(rad);
			}
		}
		double GetArea(){
			double Min = FCP[i].x;
			double Max = FCP[i].x;
			for(Point i  : FCP){
				Min = min(Min , FCP[i].x);
				Max = max(Max , FCP[i].x);
			}
			return Max - Min;
		}
 }
 void CubicUFO(double A){
	
 }
 int main(){
 	int t;
	scanf("%d",&t);
	while(t--){
		double A;
		scanf("%lf",&A);
		CubicUFO(A);	
	}
 }
