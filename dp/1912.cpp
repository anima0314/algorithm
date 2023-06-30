//연속합
#include <iostream>
using namespace std;
int arr[100001]={0,};
int dp[100001]={0,};
int main(){
	int N;
	cin>>N;
	//입력
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	
	dp[0]=arr[0];
	//연속합 계산
	int max, sum, max_sum= -1001;
	for(int i=1;i<N;++i){
		dp[i] = dp[i-1]+arr[i]>arr[i] ? dp[i-1]+arr[i]:arr[i];
	}
	
	max_sum=dp[0];
	for(int i=1;i<N;++i){
		if(max_sum<dp[i]){
			max_sum=dp[i];
		}
	}
	//출력
	cout<<max_sum<<"\n";
}