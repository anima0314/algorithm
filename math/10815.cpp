//숫자카드
#include <iostream>
using namespace std;
#define max 10000000

int arr[20000001]={0,};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,M;
	int temp;
	
	//입력
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>temp;
		arr[temp+max]++;
	}
	//출력
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>temp;
		if(arr[temp+max]){
			cout<<"1 ";
		}
		else
			cout<<"0 ";
	}
	
    return 0;
}