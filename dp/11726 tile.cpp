//타일링 2
#include <iostream>
#include <map>
using namespace std;

int dp[1001]={0,};


int main(){
	int N;
	cin>>N;
	dp[1]=1;
	dp[2]=3;	//타일링 1은 2가 2임
	for(int i=3;i<=N;++i){
		dp[i]=( dp[i-1] + 2*dp[i-2] )%10007;
	}
	cout<<dp[N]<<"\n";
}