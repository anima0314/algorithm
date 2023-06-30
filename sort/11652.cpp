#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long v[100001];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>v[i];
	}
	
	sort(v,v+N);
	
	int max=0;
	long long value=0;
	for(int i=0;i<N;++i){
		int up=upper_bound(v,v+N,v[i])-v;
		int low=lower_bound(v,v+N,v[i])-v;
		if(max < up-low){
			max=up-low;
			value=v[i];
		}
		i=up;
	}
	cout<<value<<"\n";
	return 0;
}