//오르막수
#include <iostream>
#define mod 10007
using namespace std;

int dp[1001][10]={0,};

int main(){
	int N;
	cin>>N;
	//초기화
	for(int i=0;i<10;++i) dp[1][i]=1;
	//N까지 계산
	for(int i=2;i<=N;++i){		
		for(int j=0;j<10;++j){
			for(int k=j;k<10;++k){
				//오버플로우 날까봐 이렇게 함.
				dp[i][k] = (dp[i][k]+dp[i-1][j]) % mod;
			}
		}
	}
	int sum=0;
	for(int k=0;k<10;++k){
		sum = (sum + dp[N][k]) % mod;
	}
	
	cout<<sum % mod<<"\n";
	return 0;
}