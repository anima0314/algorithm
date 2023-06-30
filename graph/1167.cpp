//트리의 지름
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;


int N;
vector<pair<int, int>> tree[MAX];
bool visited[MAX] = {0,};

int cost=0;
int dist[MAX]={0,0,};

void DFS(int node){
	visited[node]=true;
	int len = tree[node].size();
	for(int i=0; i<len; i++){
		int next = tree[node][i].first;
		int nextcost = tree[node][i].second;
		if(!visited[next]){
			dist[next] = dist[node]+nextcost;
			//cout<<"dist["<<next<<"] : "<<dist[next]<<"\n";
			DFS(next);
		}
	}
}

void input(){
	cin>>N;
	for(int i=0; i<N; i++){
		int num, temp, len;
		cin>>num;
		while(1){
			cin>>temp;
			if(temp==-1){
				break;
			}
			cin>>len;
			tree[num].push_back({temp,len});
		}
	}
}

int main(){
	input();
	
	DFS(1);
	
	int max = -1;
	int start = -1;
	for (int i = 1; i <= N; i++) {
		if (max < dist[i]) {
			max = dist[i];
			start = i;
		}
	}
	//cout<<"DFS 처음 실행 결과 start= "<<start<<" max= "<<max<<"\n\n";
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	dist[start]=0;
	DFS(start);
	max = -1;
	for (int i = 1; i <= N; i++) {
		if (max < dist[i]) {
			max = dist[i];
		}
	}
	cout<<max<<"\n";
	return 0;
}