#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int N;
	cin>>N;
	int tmp;
	for(int i=0;i<N;++i){
		cin>>tmp;
		if(tmp==0){
			if(pq.empty()){
				cout<<"0"<<"\n";
				continue;
			}
			cout<<pq.top()<<"\n";
			pq.pop();
			continue;
		}
		pq.push(tmp);
	}
}