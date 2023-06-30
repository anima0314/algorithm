#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		if(i==N-1){
			for(int j=0;j<2*(N-1)+1;++j){
				printf("*");
			}
			return 0;
		}
		for(int j=0;j<N-1;++j){
			if(N-i-1==j){
				printf("*");
			}
			else{
			printf(" ");
			}
		}
		if(i==0||i==N-1){
			printf("*");
		}
		else{
			printf(" ");
		}
		for(int j=0;j<N-1;++j){
			if(i-1==j){
				printf("*");
			}
			else{
				printf(" ");
				if(i==j){
					break;	
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}
	