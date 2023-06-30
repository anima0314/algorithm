//암호코드
#include <iostream>
#include <string>
#define mod 1000000
using namespace std;
int dp[5001][2]={0,0,};

int solve(string num){
	if(num[0]=='0') return 0;
	dp[0][0]=1;	dp[0][1]=0;	//첫항 초기화 부분
	int len=num.size();
	for(int i=1;i<len;++i){
		if(num[i]=='0'){	//지금 자리값이 0임
			if(num[i-1]>='3') return 0;
			else{
				dp[i][1]=dp[i-1][0]; //10,20인 j,t 경우만 커버
				dp[i][0]=0;	//지금 자리값이 0이므로 혼자 암호화불가
				continue;
			}
		}
		if(num[i-1]>='3'){
			dp[i][0]=dp[i-1][0]+dp[i-1][1];
			dp[i][1]=0;
		}
		else {
			if(num[i-1]=='2'&&num[i]>'6'){
				dp[i][0]=dp[i-1][0]+dp[i-1][1];
				dp[i][1]=0;
			}
			else{
				dp[i][0]=dp[i-1][0]+dp[i-1][1];
				dp[i][1]=dp[i-1][0];
			}
		}
		dp[i][0] = dp[i][0] % mod;
		dp[i][1] = dp[i][1] % mod;
		//printf("dp[%d] : %d %d\n", i, dp[i][0], dp[i][1]);
	}
	int ans=dp[len-1][0]+dp[len-1][1];
	return ans % mod;
}
int main(){
	string num;
	cin>>num;
	int ans=solve(num);
	cout<<ans<<"\n";
	return 0;
}