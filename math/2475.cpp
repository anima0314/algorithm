//검증수
#include <iostream>
using namespace std;
int result=0;

void solve(){
	int num;
	for(int i=0;i<5;i++){
		cin>>num;
		result+=num*num;
	}
	result = result%10;
}

int main() {
	//계산시작
	solve();
	//출력
	cout<<result;
    return 0;
}