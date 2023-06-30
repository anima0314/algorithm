//8진수 2진수
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	//변수선언
	char eightnum[333336] = {0,};
	int temp,flag;
	string binum;
	
	//입력
	cin >> eightnum;
	int len = strlen(eightnum);
	
	if(eightnum[0]=='0'){
		cout<<"0";
		return 0;
	}
	
	//계산시작
	for( int i=0; i<len; ++i){
		temp = eightnum[i]-'0';
		flag=4;
		while(flag!=0){
			binum.push_back( temp/flag + '0');
			temp = temp % flag;
			flag /= 2;
		}
	}
	while( binum[0]=='0' ){
		binum.erase(0,1);
	}
	
	//출력
	cout<<binum<<"\n";
	return 0;
}