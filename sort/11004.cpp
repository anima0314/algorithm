#include <iostream>
#include <algorithm>
using namespace std;
int arr[5000001]={0,};
int main(){
	ios:sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	
	sort(arr,arr+N);
	
	cout<<arr[K-1]<<"\n";
	return 0;
}