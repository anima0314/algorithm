//블랙잭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N,M;
	cin>>N>>M;
	int temp;
	vector<int> vec;
	for(int i=0;i<N;++i){
		cin>>temp;
		vec.push_back(temp);
	}
	sort( vec.begin(), vec.end() );
	
	//M이 목표값
	int max=0;	
	for(int i=0;i<N-2;++i){
		for(int j=i+1;j<N-1;++j){
			for(int k=j+1;k<N;++k){
				temp = vec[i] + vec[j] + vec[k];
				if(temp>max && temp<=M){
					max=temp;
				}
				if(temp>M){
					break;
				}
			}
		}
	}
	
	cout<<max;
	
    return 0;
}