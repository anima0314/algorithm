//최소공배수
#include <iostream>
using namespace std;

int main() {
	int A,B;
	int temp;
	cin>>A>>B;
	for (int i = 1; i <= B; i++) {
		if (A % i == 0 && B % i == 0){
			temp=i;
		}
	}
	cout << temp << "\n";	
	
	//유클리드 호제법으로 해보기
	for (int j = 1; j <= B; j++) {
		if ((A * j) % B == 0) {
			cout << A * j << "\n";
			break;
		}
	}
	return 0;
}


