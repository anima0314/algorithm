//토마토 3차원
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int box[101][101][101]={0,0,};
int visited[101][101][101]={0,0,};
//que { {y,x}, {z,day} }
queue< pair< pair<int ,int>, pair<int ,int> > > que;
int dx[6]={-1,1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,-1,1};
int M=0,N=0,H=0;	//M은 x, N은 y, H는 z
//토마토 익히기
void BFS(){
	int qy,qx,qz;
	int ny,nx,nz;
	int day;
	
	while(!que.empty()){
		qz=que.front().second.first;
		qy=que.front().first.first;
		qx=que.front().first.second;
		day=que.front().second.second;
		box[qz][qy][qx]=day;
		que.pop();
		
		//cout<<"qx: "<<qx<<" qy: "<<qy<<" day:"<<day<<"\n";
		for(int k=0;k<6;k++){
			nz=qz+dz[k];
			ny=qy+dy[k];
			nx=qx+dx[k];
			if(nx<0 || ny<0 || nz<0 || nx>=M || ny>=N || nz>=H){
				continue;
			}
			if(box[nz][ny][nx]==-1){
				visited[nz][ny][nx]=1;
				continue;
			}
			if(visited[nz][ny][nx]==0){
				que.push( {{ny,nx},{nz,day+1}} );
				visited[nz][ny][nx]=1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//상자크기 입력
	cin>>M>>N>>H;
	for(int i=0;i<H;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				cin>>box[i][j][k];
			}
		}
	}
	
	//익은 토마토 찾기
	for(int i=0;i<H;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				if(visited[i][j][k]==0){
					if(box[i][j][k]==1){
						//cout<<"익은 토마토 있음"<<" x: "<<j<<" y :"<<i<<"\n";
						que.push({{j,k},{i,1}});
						visited[i][j][k]=1;
					}
				}
			}
		}
	}
	
	//토마토 익히기
	BFS();
	
	// cout<<"\n";
	// //상자 출력
	// for(int i=0;i<H;++i){
	// 	for(int j=0;j<N;++j){
	// 		for(int k=0;k<M;++k){
	// 			cout<<box[i][j][k]<<" ";
	// 		}
	// 		cout<<"\n";
	// 	}
	// }
	// cout<<"\n";
	
	//최소일수 찾기
	int max=0;
	for(int i=0;i<H;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				if(box[i][j][k]==0){
					cout<<"-1\n";
					return 0;
				}
				if(max<box[i][j][k])
					max=box[i][j][k];
			}
		}
	}
	
	//최소일수 출력
	cout<<max-1<<"\n";
	return 0;
}