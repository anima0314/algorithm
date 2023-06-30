//진법변환
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n,num;
	cin >> num >> n;	//num은 n진법으로 변환할 값, n은 몇진법인지
	string str;		//출력할 결과
	int temp;	//나머지 저장
	char ch;
	
	while(1){
		temp = num % n;
		if(temp>9){
			ch = temp + 55;
		}
		else{
			ch = temp + 48;
		}
		str.push_back(ch);
		num/=n;
		
		if( num/n==0 && num%n==0 ){
			reverse(str.begin(),str.end());
			break;
		}
	}
	cout<<str;		//십진수 출력
	return 0;
}