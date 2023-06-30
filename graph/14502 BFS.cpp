#include <iostream>
#include <queue>
using namespace std;

class coor{	//위치저장 클래스
	public:
		int y;
		int x;
};

int N,M;	//연구소 크기

int map[10][10]={0,0,};		//연구소 맵
int temp[10][10]={0,0,};	//연구소 임시 맵

int dx[4]={-1, 1, 0, 0};	//이동 방식
int dy[4]={0, 0, -1, 1};
//결과
int result=-1;

void copy(){	//연구소 임시 맵에 지금 맵을 복사한다.
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			temp[i][j] = map[i][j];
		}
	}
}

//바이러스를 퍼트린다.
void BFS(){
	copy();
	queue<coor> que;	//2를 큐에 저장	
	coor a;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(temp[i][j]==2){
				a.y=i;
				a.x=j;
				que.push(a);
			}
		}
	}
	
	while(!que.empty()){
		int cur_x = que.front().x;
		int cur_y = que.front().y;
		que.pop();
		for(int i=0;i<4;i++){
			int ty = cur_y + dy[i];
			int tx = cur_x + dx[i];
			if(ty < 0 || tx < 0 || ty >= N || tx >= M)
				continue;
			if(temp[ty][tx]==0){
				temp[ty][tx]=2;
				a.y = ty;
				a.x = tx;
				que.push(a);
			}
		}
	}
	
	// // 맵 출력
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		cout<<temp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	
	//안전지역 계산
	int cnt=0;
	for(int i=0;i<N;i++){	
		for(int j=0;j<M;j++){
			if(temp[i][j]==0){
				cnt++;
			}
		}
	}
	result = (cnt>result) ? cnt:result;
};

//벽세우기
void block(int y, int x, int cnt){
	if(cnt==3){
		BFS();
		return;
	}
	
	for(int j=x;j<M;j++){
		if(map[y][j]==0){
			map[y][j]=1;
			block(y,j,cnt+1);
			map[y][j]=0;
		}
	}
	for(int i=y;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==0){
				map[i][j]=1;
				block(i,j,cnt+1);
				map[i][j]=0;
			}
		}
	}
	
}
int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin>>N>>M;
		
	for(int i=0;i<N;i++){	//연구소 맵입력
		for(int k=0;k<M;k++){
			cin>>map[i][k];
		}
	}
	for(int i=0;i<N;i++){	//벽세우기
		for(int j=0;j<M;j++){
			if(map[i][j]==0){
				map[i][j]=1;
				block(i,j,1);
				map[i][j]=0;
			}
		}
	}
	
	cout<<result<<"\n";
	return 0;
}
