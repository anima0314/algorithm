//미로탐색
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 102
using namespace std;

//선언
int N=0,M=0;
int res;
queue< pair< pair<int,int>, int> > que;
int map[MAX][MAX] = {false,};
bool visited[MAX][MAX] = {false,};
int dx[4]={1, 0, -1, 0};	//이동 방식
int dy[4]={0, 1, 0, -1};

//입력
void input(){
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	return;
}

int BFS(int y, int x, int count){
	int qx,qy,qcount;		//큐에서 꺼낸 죄표
	int nx,ny,ncount;		//탐색할 좌표
	visited[y][x]=true;
	que.push({{y,x},count});
	while(!que.empty()){
		res++;
		qy=que.front().first.first;
		qx=que.front().first.second;
		qcount= que.front().second;
		que.pop();
		for(int k=0;k<4;++k){
			ny=qy+dy[k];
			nx=qx+dx[k];
			ncount=qcount+1;
			
			if(ny==N && nx==M) //종료조건
				return ncount;
			
			if(ny <= 0 || nx <= 0 || ny > N || nx > M)
				continue;
			if(!visited[ny][nx]){
				if(map[ny][nx]){
					visited[ny][nx]=true;
					que.push({{ny,nx},ncount});
				}
			}
		}
	}
	return 0;
}

int main() {
	input();
	cout<<BFS(1,1,1)<<"\n";
	return 0;
}