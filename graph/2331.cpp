//반복수열
#include <iostream>
#include <vector>
using namespace std;

int visited[300000] = {0, 0,};

int pow(int A, int P){
	int result=A;
	for(int i=1;i<P;i++){
		result*=A;
	}
	return result;
}

int DFS(int A, int P, int cnt){
	//cout<<"A= "<<A<<"\n";
	int num, temp = A;
	int sum=0;
	while(temp){
		num = temp%10;
		sum+=pow(num,P);
		temp/=10;
	}
	if( visited[sum] ){
		return visited[sum]-1;
	}
	
	visited[sum]=cnt;
	
	return DFS(sum,P,++cnt);
}

int main() {
	//변수선언
	int A,P;
	int result;
	
	//입력
	cin>>A>>P;
	visited[A]=1;
	
	//계산시작
	result = DFS(A, P, 2);
	
	//출력
	cout<<result<<"\n";
    return 0;
}