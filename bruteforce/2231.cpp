//분해합
#include <iostream>
using namespace std;

int main() {
	int N, num;
	cin>>N;
	for(int i=1;i<=N;i++){
		num=0;
		int temp = i;
		num=i;
		while(temp!=0){
			num+=temp%10;
			temp/=10;
		}
		if(num==N){
			cout<<i;
			return 0;
		}
	}
	cout<<"0";
    return 0;
}