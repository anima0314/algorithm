//상수
#include <stdio.h>
#include <iostream>
using namespace std;
int num1[3] = {0,0,0};
int num2[3] = {0,0,0};

void input(){
	for(int i=0;i<3;i++){
		num1[i] = getchar()-48;
		//scanf("%d",&num1[i]);
	}
	getchar();
	for(int i=0;i<3;i++){
		num2[i] = getchar()-48;
		//scanf("%d",&num2[i]);
	}	
}

void solve(){
	if( num1[2] > num2[2] ){
		for(int i=2;i>=0;i--){
			printf("%d",num1[i]);
		}
	}
	else if( num1[2] < num2[2] ){
		for(int i=2;i>=0;i--){
			printf("%d",num2[i]);
		}
	}
	else {
		if( num1[1] > num2[1] ){
			for(int i=2;i>=0;i--){
				printf("%d",num1[i]);
			}
		}
		else if( num1[1] < num2[1] ){
			for(int i=2;i>=0;i--){
				printf("%d",num2[i]);
			}
		}
		else{
			if(num1[0] > num2[0]){
				for(int i=2;i>=0;i--){
					printf("%d",num1[i]);
				}
			}
			else if( num1[0] < num2[0] ){
				for(int i=2;i>=0;i--){
					printf("%d",num2[i]);
				}
			}
		}
	}
}

int main() {
	//입력
	input();
	//계산시작
	solve();
	//출력
	
    return 0;
}