//트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> tree[100001];
queue<int> que;
int parentarr[100001] = {0,};
bool visited[100001] = {false,};

void BFS(int i){
	visited[i]=true;
	que.push(i);
	int pi,ni;;
	while(!que.empty()){
		pi = que.front();
		que.pop();
		int len = tree[pi].size();
		for(int k=0; k<len; k++){
			ni = tree[pi][k];
			if(!visited[ni]){
				parentarr[ni]=pi;
				//cout<<ni<<"의 부모는 "<<pi<<"\n";
				visited[ni]=true;
				que.push(ni);
			}
		}
	}
	return;
}

void input(){
	int a,b;
	cin>>N;
	for(int i=1;i<N;++i){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	//입력
	input();
	//계산시작
	BFS(1);
	//출력
	for(int i=2;i<=N;i++){
		cout<<parentarr[i]<<"\n";
	}
	
    return 0;
}