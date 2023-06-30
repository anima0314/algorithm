//팩토리얼 0의 개수
#include <iostream>
using namespace std;

int main() {
	//변수선언
	int N;
	int result=0;
	//입력
	cin>>N;
	//계산시작
	if(N==0){
		cout<<result;
		return 0;
	}
	for(int i=1;i<=N;i++){
		if(i%5==0){
			result++;
		}
		if(i%25==0){
			result++;
		}
		if(i%125==0){
			result++;
		}
	}
	
	//출력
	cout<<result;
    return 0;
}