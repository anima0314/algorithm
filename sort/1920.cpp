//수 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<int> Nvec;
	
	int N,M,temp;
	cin>>N;
	for(int i=0; i<N; ++i){
		cin>>temp;
		Nvec.push_back(temp);
	}
	
	sort(Nvec.begin(), Nvec.end());
	
	cin>>M;
	for(int i=0;i<M;++i){
		cin>>temp;
		cout<<binary_search(Nvec.begin(), Nvec.end(),temp)<<"\n";
	}
	
    return 0;
}