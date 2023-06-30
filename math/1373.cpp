//2진수 8진수
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	//변수선언
	char binum[1000001] = {0,};
	int temp=0,flag;
	string eightnum;
	
	//입력
	cin >> binum;	//num은 8진법으로 변환할 값
	int len = strlen(binum)-1;
	
	//전처리
	if(len%3==2){
		flag=4;
	}
	else if(len%3==1){
		flag=2;
	}
	else{
		flag=1;
	}
	
	//계산시작
	for( int i=0; i<=len; ++i){
		//cout<<"i= "<<i<<" flag: "<<flag<<" binum: "<<binum[i]<<"\n";
		if(binum[i]=='1'){
			temp+=flag;
		}
		if(flag==1){
			flag=4;
			eightnum.push_back(temp+48);
			temp=0;
			continue;
		}
		flag/=2;
	}
	//출력
	cout<<eightnum<<"\n";
	return 0;
}