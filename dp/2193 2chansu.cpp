//이천수
#include <iostream>
using namespace std;

long long dp[90][2]={0,0,};

int main(){
	int N;
	cin>>N;
	//초기화
	dp[1][0]=0;
	dp[1][1]=1;
	//N까지 계산
	for(int i=2;i<=N;++i){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	long long sum=0;
	sum = dp[N][0] + dp[N][1];

	cout<<sum<<"\n";
	return 0;
}