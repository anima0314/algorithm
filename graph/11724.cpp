//연결요소의 개수
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int graph[1001][1001]={ 0,0, };
bool BFS_arr[1001]={false,};
queue<int> que;
int count=0;

void check(int N);
void BFS(int a, int N);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,M,V;
	cin>>N>>M;
	int A,B;
	for(int i=0;i<M;i++){
		cin>>A>>B;
		graph[A][B]=1;
		graph[B][A]=1;
	}

	check(N);
	
	cout<<count<<"\n";
	
	return 0;
}

void check(int N){
	for(int i=1; i<=N; ++i){
		if(BFS_arr[i]==0){
			++count;
			BFS(i,N);
		}
	}
}

void BFS(int a, int N){
	int vo;
	que.push(a);
	BFS_arr[a]=true;
	while(!que.empty()){	//큐가 빌때까지
		vo=que.front();
		que.pop();
		for(int i=1; i<=N; ++i){
			if(graph[vo][i]==1 && BFS_arr[i]==false){	//간선이있는데 방문안한곳이면 queue에 넣기
				que.push(i);
				BFS_arr[i]=true;	//큐에 들어갔으니 방문표시
			}
		}
	}
}