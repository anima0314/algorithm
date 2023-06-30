//최소 신장 트리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	//그래프 입력
	int V,E;
	cin>>V>>E;
	vector< pair<int,int> > graph[V];
	int a,b,c;
	for(int i=0;i<E;++i){
		cin>>a>>b>>c;
		graph[a-1].push_back({b-1,c});
		graph[b-1].push_back({a-1,c});
	}
	
	bool visited[V+1]={false,};
	//우선순위큐	pair< weight, end >
	priority_queue< pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	
	//계산
	int sum=0, nowedge=0, e=0;
	while(e != V-1){
		visited[nowedge]=true;
		//우선순위 큐에 간선 넣기
		for(auto temp_edge : graph[nowedge]){
			if(visited[temp_edge.first]==false)
				pq.push( {temp_edge.second, temp_edge.first} );
		}
		
		//우선순위큐에서 작은 순으로 꺼내면서 신장트리 만들기
		while(1){
			auto temp_pq = pq.top(); pq.pop();
			if(visited[temp_pq.second]==false){
				nowedge = temp_pq.second;
				sum+=temp_pq.first;
				break;
			}
		}
		e++;
	}
	
	//최소신장트리 값 출력
	cout<<sum<<"\n";
	return 0;
}