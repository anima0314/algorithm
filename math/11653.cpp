//소인수분해
#include <iostream>
using namespace std;

int main() {
	//변수선언
	int N;
	int temp=2;
	//입력
	cin>>N;
	//계산시작
	while(N!=1){	//N이 1이면 소인수분해 끝
		while(N%temp==0){	//temp를 2부터 증가시키면서 나누면
			//4,6,9같은수는 2와 3에서 걸러지므로 항상 소수만 나누게됨
			cout<<temp<<"\n";
			N = N/temp;
		}
		temp++;
		
	}
    return 0;
}