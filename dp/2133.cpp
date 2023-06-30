//타일 채우기
#include <iostream>
using namespace std;
int dp[31]={0,0,};

int main(){
	int N;
	cin>>N;
	dp[0]=1;
	dp[1]=0;
	dp[2]=3;
	for(int i=4;i<=N;i++){
		if(i%2==1){
			continue;
		}
		dp[i] = 3*dp[i-2];
		for(int k=i; k>2; k-=2){
			dp[i]+=dp[i-k]*2;
		}
	}
	
	cout<<dp[N]<<"\n";
	
	return 0;
}