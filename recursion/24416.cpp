#include <iostream>
using namespace std;

int f[40]={0,};
int num=0;

int fib(int n){
	if (n == 1 || n == 2){
		num++;
		return 1;  //코드1
	}
	else return ( fib(n - 1) + fib(n - 2) );
}

int fibonacci(int n){
	f[1] = f[2] = 1;
	for(int i=3;i<=n;i++){
        f[i] = f[i - 1] + f[i - 2];  //코드2
	}
	return f[n];
}

int main() {
	int N;
	cin>>N;
	
	fib(N);
	fibonacci(N);
	cout<<num<<" "<<N-2<<"\n";
	return 0;
}