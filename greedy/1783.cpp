#include <iostream>
using namespace std;

int x,y;

int main(){
	cin>>y>>x;
	if(y == 1)
		cout<<"1";
	else if(y == 2){
		cout<<min((x+1)/2,4);
	}else if(y>=3 && x<7){
		cout<<min(x,4);
	}else{
		cout<<x-2;
	}
}