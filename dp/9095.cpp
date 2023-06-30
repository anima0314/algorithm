//1,2,3더하기
#include <iostream>
#include <map>
using namespace std;

int dp[12]={0,};


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	cin>>N;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	int M, max=4;
	for(int i=0; i<N; ++i){
		cin>>M;
		for(int k=max;k<=M;++k){
			dp[k]=(dp[k-1]+dp[k-2]+dp[k-3]);
			//cout<<"계산한 항; "<<i<<"\n";
		}
		//cout<<"M: "<<dp[M]<<"\n";
		cout<<dp[M]<<"\n";
		max = (max>M+1) ? max : M+1;
	}
}