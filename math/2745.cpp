//진법변환
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n,sum=0;
	string num;
	cin >> num >> n;	//num은 10진법으로 변환할 수, n은 몇진법인지
	int len = num.size()-1;
	
	char temp;	//현재 자리수
	int tempint;
	int i=0, rad=0;
	
	for(len; len>=0; len--){
		temp = num[len];
		
		if(temp>=65){	//현재 자리수 값
			tempint=temp-55;
		}
		else{
			tempint=temp-48;
		}
		
		if(rad==0){ 
			rad=1;
		}
		else{	//진수를 반복해서 곱함
			rad*=n;
		}
		
		sum += rad*tempint; //현재자리수에대한 10진수 값을 구하고 합에 더함.
		i++;
	}
	cout<<sum;		//십진수 출력
	return 0;
}