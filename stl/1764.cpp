#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

vector<string> v;
map<string,int> m;
vector<string> ans;

int main(){
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	int N,M;
	cin>>N>>M;
	string str;
	
	//듣도 못한놈
	for(int i=0;i<N;++i){
		cin>>str;
		v.push_back(str);
	}
	
	//보도 못한놈
	for(int i=0;i<M;++i){
		cin>>str;
		m.insert({str,1});
	}
	sort(v.begin(),v.end());
	
	int vlen = v.size();
	for(int i=0;i<vlen;++i){
		if(m[v[i]]==1){
			ans.push_back(v[i]);
		}
	}
	
	cout<<ans.size()<<"\n";
	//듣도 보도 못한놈
	for(string item : ans){
		cout<<item<<"\n";
	}
	
	return 0;	
}