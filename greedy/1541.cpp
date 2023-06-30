//잃어버린 괄호
#include <iostream>
#include <cstring>
using namespace std;

//-뒤에 +는 모두 합치고 -나오면 앞에서 괄화 자르기
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	char string[51];
	//입력
	cin>>string;
	int len = strlen(string);
	//계산시작
	int result = 0;
	int temp = 0;
	bool flag_minus=false;
	
	for(int i=0;i<len;++i){
		if(string[i]=='+'){
			if(flag_minus==true){
				result-=temp;
			}
			else{	//flag_minus==false
				result+=temp;
			}
			temp=0;
		}
		else if(string[i]=='-'){
			if(flag_minus==true){
				result-=temp;
			}
			else{	//flag_minus==false
				result+=temp;
			}
			flag_minus=true;
			temp=0;
		}
		else{		//숫자일 경우
			temp*=10;
			temp+=string[i]-48;
		}	
	}
	if(flag_minus==true){
		result-=temp;
	}
	else{
		result+=temp;
	}
	//출력
	
	cout<<result;
    return 0;
}