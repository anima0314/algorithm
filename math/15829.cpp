//Hashing
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//아스키코드 a-96 = 1

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//입력
	int L;
	cin>>L;
	char arr[51];
	cin>>arr;
	
	int temp;
	int len = strlen(arr);
	long long sum=0;
	long long pow=1;
	for(int i=0;i<len;++i){
		temp = arr[i]-96;
		sum += temp*pow;
		pow = (pow * 31) % 1234567891;
		sum = sum % 1234567891;
	}
	cout<<sum;	
    return 0;
}