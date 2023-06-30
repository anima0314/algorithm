//순열 사이클
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int graph[1002]={0,};
bool DFS_arr[1002]={false,};
int count=0;

void DFS(int a){
	DFS_arr[a]=true;
	if(DFS_arr[ graph[a] ]==false){	//DFS 종료조건임 사이클에 되면 멈춤
		DFS(graph[a]);			//방문안한곳이면 방문함 
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//변수선언
	int T,N;
	//입력
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;++i){
			cin>>graph[i];//그래프 입력
		}
		
		//계산시작
		for(int i=1;i<=N;++i){
			if(DFS_arr[i]==false){
				DFS(i);
				count++;
			}
		}
		
		//출력
		cout<<count<<"\n";
		
		//초기화
		count=0;
		for(int i=1;i<=N;++i){
			DFS_arr[i]=false;
		}
	}
    return 0;
}