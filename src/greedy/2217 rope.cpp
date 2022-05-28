#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int N,i;
	cin>>N;
	int arr[N];
	for(i=0;i<N;i++){
		cin >> arr[i];
	}
	sort(arr,arr+N);
	
	int max=0;
	for(i=0; i<N; i++){				//최대로 버틸수있는 무게는 자기 로프의 최대무게 * 버리지 않은 로프들의 개수
		if(max < arr[i] * (N-i) ){	//왜나면 sort 해주었기 때문에 arr[i]로프가 남은줄 중에 가장 약한 줄이기 때문이다.
			max = arr[i] * (N-i);	//이후 하나씩 로프를 줄여가며 버틸수있는 최대 무게를 확인하고 모든 로프를 확인하면
		}
	}
	cout << max;		//최댓값 출력
	
	return 0;
}