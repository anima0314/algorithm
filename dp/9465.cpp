//스티커
#include <iostream>
using namespace std;

int max(int a,int b){
	return (a>b) ? a : b;	
} 

int card[2][100001]{0,0,};
int dp[3][100001]={0,0,};

int main(){
	int N,T;
	int result;
	cin>>T;
	while(T--){
		cin>>N;
		//스티커 입력
		for(int i=0;i<2;++i){
			for(int k=1;k<=N;++k){
				cin>>card[i][k];
			}
		}
		//첫항 계산
		dp[0][1]=card[0][1];
		dp[1][1]=card[1][1];
		dp[2][1]=0;
		//가장 큰값 찾기
		for(int i=2;i<=N;++i){
			dp[0][i]= max(dp[1][i-1],dp[2][i-1]) + card[0][i];	//위에 스티커 때는 경우
			dp[1][i]= max(dp[0][i-1],dp[2][i-1]) + card[1][i];	//아래 스티커 때는 경우
			dp[2][i]= max(dp[0][i-1],dp[1][i-1]);				//스티커를 안때는 경우
		}
		//출력
		result=max(dp[0][N], dp[1][N]);
		cout<<result<<"\n";
	}
	
	return 0;
}