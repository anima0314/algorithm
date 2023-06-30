#include <iostream>
#include <algorithm>
using namespace std;
#define Max 1000000001;
int main(void){
	int T=0;
	cin >> T;
	T--;
	long WayLength[T], Price[T];
	
	for(int i=0;i<T;i++){
		cin >> WayLength[i];
	}	
	for(int i=0;i<T;i++){
		cin >> Price[i];
	}
	
	long sum=0;
	int now_Price = Max;
	for(int i=0;i<T;i++){	//기름을 도시에 가서 기름가격이 비싸면 이전가격으로 샀다고 생각
		if(now_Price>Price[i]){ //기름이 이전도시보다 싸면 이도시에서 다음 도시까지의 기름을 구매
			now_Price=Price[i];
		}
		sum += now_Price * WayLength[i];
		//cout << i+1 <<"번째 도시의 기름 가격은" << now_Price << " 총비용:" << sum << "\n";
	}
	cout << sum;
	return 0;
}