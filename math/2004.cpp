//조합 0의 개수
#include <iostream>
#include <algorithm>
using namespace std;

long long two(long long A){
	long long result=0;
	for( long long i=2; i<=A; i*=2){
		result += A/i;	
	}
	return result;
}

long long five(long long A){
	long long result=0;
	for( long long i=5; i<=A; i*=5){
		result += A/i;
	}
	return result;
}


int main() {
	//변수선언
	long long N,M;
	//입력
	cin>>N>>M;
	long long FIVE,TWO;
	//계산시작
	FIVE = five(N) - five(M) - five(N-M);
	TWO = two(N) - two(M) - two(N-M);
	
	//결과
	cout<<min(TWO, FIVE);
    
	return 0;
}