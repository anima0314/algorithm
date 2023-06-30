//랜선자르기
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

//선언
ll N,K;
ll arr[10001]={0,0,};

void input(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
}

ll check(ll mid){
	ll cnt=0;
	for(int i=0; i<N; i++){
		cnt+=arr[i]/mid;
	}
	return cnt;
}

void solve(){
	ll mid,ans;
	ll upper = check(1)/K; //*max_element(arr,arr+N);
	ll lower = 1;
	while(lower <= upper){
		mid = (upper+lower)/2;
		ll cnt = check(mid);
		cout<<"mid= "<<mid<<" cnt= "<<cnt<<" upper= "
			<<upper<<" lower= "<<lower<<"\n";
		//mid 조절
		if(cnt<K){
			upper = mid-1;
		}
		else{
			ans=mid;
			lower = mid+1;
		}
	}
	//출력
	cout<<ans<<"\n";
}

int main() {
	//입력
	input();
	//계산시작
	solve();
    return 0;
}