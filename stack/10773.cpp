//제로
#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//입력
	int K,temp;
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>temp;
		if(temp==0){
			vec.pop_back();
			continue;
		}
		vec.push_back(temp);
	}
	//계산시작
	int length = vec.size();
	int num=0;
	for(auto au : vec){
		num += au;
	}
	cout<<num<<"\n";
	
    return 0;
}