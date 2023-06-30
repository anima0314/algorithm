//단지번호붙이기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//선언
int N=0,cnt=0;
int map[26][26] = {false,};
bool visited[26][26] = {false,};
vector<int> res;
int dx[4]={-1, 1, 0, 0};	//이동 방식
int dy[4]={0, 0, -1, 1};

//입력
void input(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	return;
}

//그래프탐색
void DFS(int y, int x){
	cnt++;
	visited[y][x] = true;
	int nx,ny;
	for(int i=0;i<4;i++){
		nx= x+dx[i];
		ny= y+dy[i];
		if(ny<0 || nx<0 || ny>=N || nx>=N){
			continue;
		}
		if(visited[ny][nx] == false){
			if(map[ny][nx]==1){
				DFS(ny,nx);
			}
		}
	}
	return;
}


//계산
void solve(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]==false){
				if(map[i][j]==1){
					cnt=0;
					DFS(i,j);
					res.push_back(cnt);
				}
				else{
					visited[i][j]=true;
				}
			}
		}
	}
	return;
}

int main() {
	input();
	solve();
	//출력
	int len = res.size();
	sort(res.begin(), res.end());
	cout<<len<<"\n";
	for(int i=0; i<len; i++){
		cout<<res[i]<<"\n";
	}
    return 0;
}