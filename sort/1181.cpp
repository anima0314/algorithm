//단어정렬
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


struct Compare {
	bool operator() (const string &a, const string &b) const{
		if( a.size() == b.size() ){
			return a<b;
		}
		else 
			return a.size()<b.size();
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(); cout.tie();
	
	int N;
	set<string,Compare> setstr;
	//입력
	cin>>N;
	string temp;
	for(int i=0;i<N;i++){	//글자수단위로 입력
		cin>>temp;
		setstr.insert(temp);
	}
	//계산시작
	for(auto iter : setstr){
		cout<<iter<<"\n";
	}
	return 0;
}