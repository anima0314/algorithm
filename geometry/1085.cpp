//직사각형에서 탈출
#include <iostream>
using namespace std;
int x,y,w,h;

void input(){
	cin>>x>>y>>w>>h;
}

int solve(){
	int tempx,tempy,result;
	
	if(w-x<x) tempx=w-x;
	else tempx=x;
	
	if(h-y<y) tempy=h-y;
	else tempy=y;
	
	
	result = (tempx<tempy) ? tempx : tempy;
	
	return result;
}

int main() {
	//입력
	input();
	//계산시작
	cout<<solve();
    return 0;
}