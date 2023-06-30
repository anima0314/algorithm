//프린터 큐
#include <iostream>
#include <queue>
using namespace std;


int solve(){
	int N,k,temp;
	queue<int> que;
	priority_queue<int> sortque;
	//입력
	cin>>N>>k;
	for(int i=0;i<N;i++){
		cin>>temp;
		que.push(temp);
		sortque.push(temp);
	}
	int cnt=0;
	while(!que.empty()){
		if( que.front() == sortque.top() ){
			que.pop();
			sortque.pop();
			cnt++;
			if(k==0){
				break;
			}
		}
		else{
			que.push(que.front());
			que.pop();
		}	
		k--;
		if(k==-1){
			k+=que.size();
		}
	}
	
	return cnt;
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;	//테스트 개수
	cin>>T;
	for(int i=0;i<T;i++){
		cout<<solve()<<"\n";
	}
	
	return 0;
}