//제곱수의 합
#include <iostream>
using namespace std;
int arr[320]={0,};
int dp[100001] = {0, };

int main(){
	int N;
	//제곱수 계산
	for(int i=1;i<=320;++i){
		arr[i]=i*i;
	}	
	//자연수 N입력
	cin>>N;
	dp[0]=0;
	//계산	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=320;++j){
			if(arr[j]>N||i-arr[j]<0){
				break;
			}
			//cout<<"i: "<<i<<" arr: "<<arr[j]<<" j: "<<j<<"\n";
			//cout<<dp[i-arr[j]]+1<<"\n";
			if(dp[i]>dp[i-arr[j]]+1||dp[i]==0){
				dp[i]=dp[i-arr[j]]+1;
			}
		}
		//cout<<"dp["<<i<<"]: "<<dp[i]<<"\n";
	}
	
	//최소항 출력
	cout<<dp[N]<<"\n";
	return 0;
}