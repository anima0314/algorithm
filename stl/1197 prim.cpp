//최소 신장 트리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class edge{//간선 저장 클래스
	public:
	int end;
	int weight;
	
	edge(int i,int j){
		this->end = i;
		this->weight = j;
	}
	
	bool operator < (const edge& i) const {
		return this->weight > i.weight ;
	}
};

//방문한 곳 저장
bool visited[10001]={false,};
//가장작은 간선 찾는 곳
priority_queue<edge> pq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//노드 간선수 입력
	int V,E;
	cin>>V>>E;
	//이차원 배열에 값은 end와 weight를 가지고 있음
	vector< vector< pair<int,int> > > graph(V);
	//간선 입력
	int a,b,c;
	for(int i=0;i<E;++i){
		cin>>a>>b>>c;
		graph[a-1].push_back({b-1,c});
		graph[b-1].push_back({a-1,c});
	}
	//신장트리구하기 0에서 시작 간선이 V-1개가 되면 멈춤
	int sum=0, nowedge=0, e=0;
	visited[nowedge]=true;
	while(e != V-1){
		int now_lengh = graph[nowedge].size();
		//우선순위 큐에 간선 넣기
		for(int i=0;i<now_lengh;++i){
			if(visited[graph[nowedge][i].first]==true){
				continue;
			}
			pq.push( edge( graph[nowedge][i].first, graph[nowedge][i].second ) );
		}
		//우선순위큐에서 작은 순으로 꺼내면서 신장트리 만들기
		edge temp_pq(0,0);
		while(1){
			temp_pq = pq.top(); pq.pop();
			if(visited[temp_pq.end]==false){
				nowedge = temp_pq.end;
				sum+=temp_pq.weight;
				break;
			}
			//cout<<"방문한 간선\n";
		}
		e++;
		visited[nowedge]=true;
	}
	
	//최소신장트리 값 출력
	cout<<sum<<"\n";
	return 0;
}