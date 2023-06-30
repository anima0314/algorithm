#include <iostream>
using namespace std;

int N;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

char pic[101][101]={0,};
bool vRGB[101][101]={false, };
bool vRB[101][101]={false, };

void DFS(int y, int x, char k){
	int nx,ny;	//탐색할 좌표
	vRGB[y][x]=true;
	for(int i=0;i<4;++i){
		ny=y+dy[i];
		nx=x+dx[i];
		if(ny < 0 || nx < 0 || ny >= N || nx >= N){
			continue;
		}
		if(vRGB[ny][nx]==false){
			if(pic[ny][nx] == k){
				DFS(ny, nx, k);
			}
		}
	}
}

void RBDFS(int y, int x, char k){
	int nx,ny;	//탐색할 좌표
	vRB[y][x]=true;
	
	if(k=='B'){
		
	}
	for(int i=0;i<4;++i){
		ny=y+dy[i];
		nx=x+dx[i];
		if(ny < 0 || nx < 0 || ny >= N || nx >= N){
			continue;
		}
		if(vRB[ny][nx]==false){
			if(k=='B'){
				if(pic[ny][nx] == k){
					RBDFS(ny, nx, 'B');
				}
			}
			else{
				if(pic[ny][nx] != 'B'){
					RBDFS(ny, nx, 'R');
				}
			}
		}	
	}
}

int main(){
	cin >> N;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin>>pic[i][j];
		}
	}
	int RGB=0;
	int RB=0;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(vRGB[i][j] == false){
				if(pic[i][j]=='R'){
					RGB++;
					DFS(i,j,'R');
				}
				else if(pic[i][j]=='G'){
					RGB++;
					DFS(i,j,'G');
				}
				else{
					RGB++;
					DFS(i,j,'B');
				}
			}
			if(vRB[i][j] == false){
				if(pic[i][j]=='R'||pic[i][j]=='G'){
					RB++;
					RBDFS(i,j,'R');
				}
				else{
					RB++;
					RBDFS(i,j,'B');
				}
			}
		}
	}
	cout<<RGB<<" "<<RB<<"\n";
}