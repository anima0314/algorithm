//쉬운 계산 수
#include <iostream>
#define mod 1000000000
using namespace std;

int dp[101][10]={0,};

int main(){
	int N;
	cin>>N;
	
	for(int i=1;i<10;++i) dp[1][i]=1;
	for(int i=2;i<=N;++i){
		//너무 커질수있으니 계산마다 10억 나눠줌
		
		//0이 나오려면 이전 자리수가 1이어야만 가능
		dp[i][0] = dp[i-1][1] % mod;
		//9가 나오려면 이전 자리수가 8이어야만 가능
		dp[i][9] = dp[i-1][8] % mod;
		
		//나머지는 이전자리수가 +1이거나 -1이면 됨
		for(int j=1;j<9;++j){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1]) % mod;
		}
	}
	
	int sum=0;
	for(int k=0;k<10;++k){
		//더하면서 10억이 넘어가면 오버플로우 날수있으니 더하면서 나눠줌
		sum = (sum + dp[N][k]) % mod;
	}
	
	cout<<sum % mod<<"\n";
	return 0;
}