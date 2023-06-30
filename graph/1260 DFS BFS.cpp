#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int graph[1001][1001]={ 0,0, };
bool DFS_arr[1001]={false,};
bool BFS_arr[1001]={false,};
queue<int> que;

void DFS(int a, int N){
	DFS_arr[a]=true;
	cout<<a<<" ";	//출력부분
	for(int i=1;i<N+1;i++){
		if(graph[a][i]!=0 && DFS_arr[i]==false){
			DFS(i,N);	//간선이 있는데 방문안한곳이면 바로 방문함 
		}
	}
};
void BFS(int a, int N){
	int vo;
	que.push(a);
	BFS_arr[a]=true;
	while(!que.empty()){	//큐가 빌때까지
		vo=que.front();
		que.pop();
		cout<<vo<<" ";	//출력부분
		for(int i=1;i<N+1;i++){
			if(graph[vo][i]==1 && BFS_arr[i]==false){	//간선이있는데 방문안한곳이면 queue에 넣기
				que.push(i);
				BFS_arr[i]=true;	//큐에 들어갔으니 방문표시
			}
		}
	}
};

int main() {
	int N,M,V;
	cin>>N>>M>>V;
	int A,B;
	for(int i=0;i<M;i++){
		cin>>A>>B;
		graph[A][B]=1;
		graph[B][A]=1;
	}

	DFS(V,N);
	cout<<"\n";
	BFS(V,N);
	
	return 0;
}