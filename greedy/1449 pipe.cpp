#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	int N=0,tapelen=0,cnt=0;
	cin >> N >> tapelen;
	
	int broken[N];
	for(int i=0;i<N;i++){
		cin >> broken[i];
	}
	sort(broken,broken+N);
	int broken_point=0;
	for(int i=0;i<N;i++){
		broken_point = broken[i];	//테이프 붙이기
		cnt++;
		while(broken[i+1] < broken_point + tapelen){ //테이프 하나로 덮을 수 있는 파이프구멍 확인
			i++;
		}
	}
	cout << cnt;
	return 0;
}