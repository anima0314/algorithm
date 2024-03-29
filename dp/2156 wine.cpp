//포도주 시식
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
	int dp[10010] = { 0 }, N, arr[10010] = { 0 };
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin>>arr[i];
	
	dp[1]=arr[1];
	dp[2]=dp[1]+arr[2];
	
	for (int i = 3; i <= N; i++) {
		dp[i] = max( {dp[i-1],dp[i-2]+arr[i],dp[i - 3]+arr[i-1]+arr[i]} );
	}
	cout << dp[N];
	return 0;
}