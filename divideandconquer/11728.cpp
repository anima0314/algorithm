//배열 합치기
#include <iostream>
#include <vector>
using namespace std;

vector <int> a;
vector <int> b;

void input(){
	int num1;
	int num2;
	int temp;
	cin>>num1>>num2;
	for(int i=0; i<num1; ++i){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0; i<num2; ++i){
		cin>>temp;
		b.push_back(temp);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//입력
	input();
	//계산시작
	int acnt=0, bcnt=0, alen = a.size(), blen = b.size();
	//출력
	while( acnt < alen && bcnt < blen){
		if( a[acnt] < b[bcnt] ){
			cout<<a[acnt++]<<" ";
		}
		else{
			cout<<b[bcnt++]<<" ";
		}
	}
	
	while(acnt!=alen){
		cout<<a[acnt++]<<" ";
	}
	while(bcnt!=blen){
		cout<<b[bcnt++]<<" ";
	}
    return 0;
}