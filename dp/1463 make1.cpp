//1로 만들기
#include <iostream>
#include <algorithm>
using namespace std;
int dp[3000001] = {0, };

int main(void){
	int N;
	cin>>N;
	for(int i=1;i<=N;++i){
		cout<<i<<": "<<dp[i]<<"\n";
		if(dp[i+1]==0||dp[i+1]>dp[i]+1)
			dp[i+1]=dp[i]+1;
		if(dp[2*i]==0||dp[2*i]>dp[i]+1)
			dp[2*i]=dp[i]+1;
		if(dp[3*i]==0||dp[3*i]>dp[i]+1)
			dp[3*i]=dp[i]+1;
	}
	
	cout<<dp[N]<<"\n";
	
	return 0;
}