//카드 구매하기
//틀린풀이인데 우선순위큐 사용법에대한 내용을 담고있어서 살려둠
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dp[1000];
//우선순위큐는 특이하게 내림차순과 오름차순의 bool값이 반대임
struct cmp{
    bool operator()(pair<int,float> a, pair<int,float> b){
		//1개당 가격 내림차순
		if(a.second < b.second){
			return true;
		}
		else if(a.second == b.second){
			//카드 개수 오름차순
			if(a.first > b.first){
				return true;
			}
		}
		else{
			return false;
		}
		return false;
	};
};
 
int main(){
	int N,num,len;
	cin>>N;
	len=N;
	priority_queue< pair<int,float>, vector<pair<int,float> >, cmp> pq;
	for(int i=1;i<=N;++i){
		cin>>num;
		pq.push({i, num/(float)i});
	}
	int sum=0;
	pair<int,float> temp_pack;
	for(int i=0;i<len;i++){
		temp_pack = pq.top();
		pq.pop();
		if(N<temp_pack.first){
			continue;
		}
		int mul = N/temp_pack.first;
		sum += (int)(temp_pack.first * temp_pack.second) * mul;
		N -= temp_pack.first*mul;
		if(N==0){
			break;
		}
	}
	cout<<sum<<"\n";
	return 0;
}