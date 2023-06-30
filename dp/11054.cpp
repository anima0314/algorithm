//가장 긴 바이토닉 부분수열
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1002]={0,};
int rdp[1002]={0,};
int arr[1002]={0,};

int main(){
	int N;
	cin>>N;
	//입력
	for(int i=1;i<=N;++i){
		cin>>arr[i];
	}
	int answer=0;
	int max=0;

	//앞에서 시작 부분
	for(int i=1;i<=N;++i){
		max=0;
		for(int j=0;j<=i;++j){
			if(arr[i]>arr[j]){
				if(max<dp[j]){
					max=dp[j];
				}
			}
		}
		dp[i]=max+1;
	}
	//뒤에서 시작 부분
	for(int i=N;i>0;--i){
		max=0;
		for(int j=N;j>=i;--j){
			if(arr[i]>arr[j]){
				if(max<rdp[j]){
					max=rdp[j];
				}
			}
		}
		rdp[i]=max+1;
	}
	for(int i=1;i<=N;++i){
		if(answer<rdp[i]+dp[i]-1){
			answer=rdp[i]+dp[i]-1;
		}
	}
	cout<<answer<<"\n";
	return 0;
}