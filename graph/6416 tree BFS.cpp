//트리인가?
//1 2 2 3 3 1 4 5 0 0 = 트리아님
#include <iostream>
#include <vector>
#include <queue>
#define MAX_NUM 100
using namespace std;


bool visited[MAX_NUM]={false,};
vector<int> v_in[MAX_NUM];
vector<int> v_out[MAX_NUM];
queue<int> bfsque;
bool BFS();

int main(){
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test_cnt=0;
	while(++test_cnt){
		//초기화
		int cnt=0;
		bool result=true;
		for(int i=0;i<MAX_NUM;++i){
			visited[i]=false;
			v_in[i].clear();
			v_out[i].clear();
		}
		while(!bfsque.empty()){
			bfsque.pop();
		}
		//간선과 노드 입력
		int u,v;
		while(1){
			cin>>u>>v;
			//비어있어도 트리임
			if(u==0 && v==0 && cnt==0){
				cout<<"Case "<<test_cnt++<<" is a tree.\n";
				continue;
			}
			if(u==0 && v==0){
				break;
			}
			if(u==-1 && v==-1){
				return 0;
			}
			//u에서 v로 간선이 연결됨.
			v_in[v].push_back(u);
			v_out[u].push_back(v);
			cnt++;
		}
		
		//트리인지 확인
		result = BFS();
		//결과출력
		if(result)	cout<<"Case "<<test_cnt<<" is a tree.\n";
		else	cout<<"Case "<<test_cnt<<" is not a tree.\n";
	}
	return 0;
}

bool BFS(){
	int root_node=0;
	int total_node=0;
	int visit_node=0;
	//루튼 노드구하기 겸 트리가 안되는 경우 체크
	for(int i=0;i<MAX_NUM;i++){
		//루트노드
		if(v_in[i].size()==0&&v_out[i].size()>0){
			if(root_node!=0){
				cout<<"루트 노드가 2개 이상이다.\n";
				return false;
			}
			root_node=i;
		}
		//루트가 아닌 노드
		if(v_in[i].size()==1){
			total_node++;
		}
		//입력이 2개인 노드
		if(v_in[i].size()>1){
			cout<<"들어가는 노드가 2개 이상이다.\n";
			return false;
		}
	}
	//
	if(root_node==0){
		cout<<"루트노드가 없음\n";
		return false;
	}
	
	//트리 탐색 BFS
	visited[root_node]=true;
	for(auto temp=v_out[root_node].begin(); temp!=v_out[root_node].end(); ++temp){
		cout<<"루트에서 연결된 노드: "<<*temp<<"\n";
		bfsque.push(*temp);	
	}
	
	while(!bfsque.empty()){
		int now_node=bfsque.front();
		bfsque.pop();
		visit_node++;
		if(visited[now_node]==true){
			cout<<"방문한 노드를 또 방문함\n";
			return false;
		}
		visited[now_node]=true;
		for(auto temp=v_out[now_node].begin(); temp!=v_out[now_node].end(); ++temp){
			cout<<now_node<<"에서 연결된 노드: "<<*temp<<"\n";
			bfsque.push(*temp);
		}
	}
	cout<<"total_node: "<<total_node<<" visit_node: "<<visit_node<<"\n";
	if(total_node!=visit_node){
		cout<<"모든 노드를 방문하지 않았음\n";
		return false;
	}
	return true;
}