#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool map[50][50]={false,false, };
bool visited[50][50]={false,false, };
queue<pair<int,int>> que;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
int sum=0;	//섬의 수
int X,Y;

void BFS(int y, int x){	//붙어있는 섬 방문
	int qx,qy;		//큐에서 꺼낸 죄표
	int nx,ny;		//탐색할 좌표
	++sum;			//섬 추가
	visited[y][x]=true;
	que.push({y,x});
	while(!que.empty()){
		qy=que.front().first;
		qx=que.front().second;
		que.pop();
		for(int k=0;k<8;++k){
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
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(1){
		cin>>X>>Y;
		if(X==0&&Y==0)
			break;
		for(int i=0;i<Y;++i){
			for(int j=0;j<X;j++){
				cin>>map[i][j];
			}
		}
		
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
		for(int i=0;i<Y;++i){	//방문함수 초기화
			for(int j=0;j<X;j++){
				map[i][j]=false;
				visited[i][j]=false;
			}
		}
	}
	return 0;
}