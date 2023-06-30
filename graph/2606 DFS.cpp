#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int graph[101][101]={ 0, };
bool arr[101]={ false, };

void DFS(int N, int a){
	arr[a]=true;
	for(int i=0;i<N;i++){
		if(graph[a][i]==1 && arr[i]==false){
			//cout<<a+1<<"에서"<<i+1<<"\n";
			DFS(N,i);
		}
	}
}

int main() {
	int N,M;
	cin>>N;	//컴퓨터 수
	cin>>M;	//간선 수
	
	int A,B;
	for(int i=0;i<M;i++){
		cin>>A>>B;
		graph[A-1][B-1]=1;
		graph[B-1][A-1]=1;
	}
	
	DFS(N,0);
	
	//cout<<"1번 컴퓨터: 1"<<"\n";
	
	int sum=0;
    for(int k=1;k<N;k++){
		if(arr[k]==true){
			sum+=1;
			
		}
		//cout<<k+1<<"번 컴퓨터: "<<arr[k]<<"\n";
	}
	
	// 인접행렬 출력
	// for(int i=0;i<N;i++){
	// 	for(int k=0;k<N;k++){
	// 		cout<<graph[i][k]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	cout<<sum<<"\n";
	return 0;
}