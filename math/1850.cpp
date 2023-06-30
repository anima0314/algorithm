//최대공약수
#include <iostream>
using namespace std;

long long GCD(long long a, long long b){
    if(b==0)return a;
    else return GCD(b,a%b);
}

int main() {
	long long a,b,i;
	cin>>a>>b;
	if(a>b){
		i = GCD(a,b);	
	}
	else if(b>a){
		i = GCD(b,a);	
	}
	
	for (int j = 0; j < i; j++) {
		cout << "1";
	}
	
	return 0;
}