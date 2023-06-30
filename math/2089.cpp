//-2진수
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	//변수선언
	int num;
	string str;		//출력할 결과
	
	//입력
	cin>>num;
	if(num==0){
		cout<<"0";
		return 0;
	}
	int r;
	//계산
	while(num){
		r = num % -2;
		if(r==-1){
			str.push_back('1');
			num = num/-2 +1;
		}
		else{
			str.push_back(r+'0');
			num /= -2;
		}
	}
	reverse(str.begin(), str.end());
	//출력
	cout<<str;
	return 0;
}