//포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,M;
	map<string,int> dic;
	vector<string> v;
	cin>>N>>M;
	string x;
	for(int i=0; i<N; ++i){
		cin>>x;
		dic.insert( {x,i+1} );
		v.push_back(x);
	}
	
	for(int i=0; i<M; ++i){
		cin>>x;
		if( dic.find(x) != dic.end() ){
			cout<<dic[x]<<"\n";
		}
		else{
			cout<<v[ stoi(x)-1 ]<<"\n";
		}
	}
	return 0;
}