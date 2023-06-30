//가장 큰 증가하는 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1002]={0,};
int arr[1002]={0,};

int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
	}
	int answer=0;
	for(int i=1;i<=N;++i){
		int max=0;
		for(int j=0;j<=i;++j){
			if(arr[i]>arr[j]){
				if(max<dp[j]){
					max=dp[j];
				}
			}
		}
		dp[i]=max+arr[i];
		if(answer<dp[i]){
			answer=dp[i];
		}
	}
	cout<<answer<<"\n";
	return 0;
}