//four squares
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> dp(n+1,0);
	dp[1]=1;
	//계산시작
	for(int i=2; i<=n; ++i){
		dp[i]=dp[i-1]+1;
		for(int j=2; j*j<=i; ++j){
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}
	//출력
	cout<<dp[n];
	
    return 0;
}