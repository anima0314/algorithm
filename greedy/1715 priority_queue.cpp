#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int main(void){
	priority_queue <int, vector<int>,greater<int>> pq;
	int N,sum=0,temp;
	cin>>N;
	for(int i=0;i<N;i++){
		cin >> temp;
		pq.push(temp);
	}
	if(N==1){	//N=1은 비교x
		cout<<"0";
		return 0;
	}
	int box;
	while(1){
		box=pq.top();
		pq.pop();
		box+=pq.top();
		pq.pop();
		sum += box;
		pq.push(box);
		if(pq.size()==1){
			break;
		}
	}
	cout << sum;
	return 0;
}