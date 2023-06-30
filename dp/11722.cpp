//가장 긴 감소하는 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1002]={0,};
int dp[1002]={0,};

int main(){
	int N;
	int max=0, answer=0;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
	}
	
	for(int i=1;i<=N;++i){
		max=0;
		for(int j=0;j<i;++j){
			if(arr[i]<arr[j]){
				if(max<dp[j]){
					max=dp[j];	
				}
			}
		}
		dp[i] = max+1;
		if(answer<dp[i])
			answer=dp[i];
	}
	cout<<answer<<endl;
	
	return 0;
}