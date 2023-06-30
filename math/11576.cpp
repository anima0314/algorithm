//Base Conversion 
#include <iostream>
using namespace std;

int arrA[25] = {0,0,};
int arrB[25] = {0,0,};

int main() {
	//변수선언
	int A,B;
	int m;
	int tennum=0;
	int temp=1;
	int lenA;
	//입력
	cin>>A>>B;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>arrA[i];
	}
	//계산시작
	//A->10진법
	for(int n = m-1; n>=0; n--){
		tennum += arrA[n] * temp;
		temp = temp * A;
	}
	
	//10->B진법
	int n=0;
	while(tennum){
		arrB[n] = tennum % B;
		tennum = tennum/B;
		n++;
	}
	
	//출력
	for(int i=n-1; i>=0 ;--i){
		if(i==0){
			cout<<arrB[i];
			break;
		}
		cout<<arrB[i]<<" ";
	}
    return 0;
}