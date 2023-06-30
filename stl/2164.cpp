//카드2
#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> que;

void input(){
	cin>>N;
	for(int i=1;i<=N;i++){
		que.push(i);
	}
}

void solve(){
	while(que.size()!=1){
		que.pop();
		if(que.size()==1){
			break;
		}
		que.push(que.front());
		que.pop();
	}
}

int main() {
	//입력
	input();
	//계산시작
	solve();
	//출력
	cout<<que.front();
	
    return 0;
}