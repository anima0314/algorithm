//이항계수 1
#include <iostream>
using namespace std;

int fact(int a){
	if(a==0){
		return 1;
	}
	return fact(a-1) * a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//입력
	int N,K,C;
	cin>>N>>K;
	C=fact(N)/fact(K)/fact(N-K);
	
	//출력
	cout<<C<<"\n";
    return 0;
}