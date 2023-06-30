#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool map[50][50]={false,false, };
bool visited[50][50]={false,false, };
queue<pair<int,int>> que;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int sum=0;	//배추흰지렁이 수
int TC;
int X,Y,K;

void BFS(int y, int x){	//붙어있는 배추는 방문해버림
	int qx,qy;		//큐에서 꺼낸 죄표
	int nx,ny;		//탐색할 좌표
	++sum;			//배추흰지령이 추가
	visited[y][x]=true;
	que.push({y,x});
	while(!que.empty()){
		qy=que.front().first;
		qx=que.front().second;
		que.pop();
		for(int k=0;k<4;++k){
			ny=qy+dy[k];
			nx=qx+dx[k];
			if(ny < 0 || nx < 0 || ny >= Y || nx >= X)
				continue;
			if(!visited[ny][nx]){
				if(map[ny][nx]){
					visited[ny][nx]=true;
					que.push({ny,nx});
				}
			}
		}
	}
}

int main() {
	cin>>TC;
	int a,b;
	while(TC>0){
		cin>>X>>Y>>K;

		for(int i=0;i<K;++i){
			cin>>a>>b;
			map[b][a]=true;
		}
		
		// cout<<"\n";
		// // 밭 출력
		// for(int i=0;i<Y;++i){
		// 	for(int j=0;j<X;++j){
		// 		cout<<map[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		// cout<<"\n";
		
		for(int i=0;i<Y;++i){
			for(int j=0;j<X;j++){
				if(!visited[i][j]){
					if(map[i][j]){
						BFS(i,j);
					}
					else{
					visited[i][j]=true;
					}
				}
			}
		}
		
		cout<<sum<<"\n";
		sum=0;
		for(int i=0;i<Y;++i){	//밭과 방문함수 초기화
			for(int j=0;j<X;j++){
				map[i][j]=false;
				visited[i][j]=false;
			}
		}
		--TC;
	}
	return 0;
}