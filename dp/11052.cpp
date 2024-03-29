//카드 구매하기
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001]={0,}, dp[1001]={0,};
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
		dp[i]=arr[i];
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<i;++j){
			dp[i] = max( dp[i], dp[j]+arr[i-j] );
		}
	}
	cout<<dp[N];
	return 0;
}