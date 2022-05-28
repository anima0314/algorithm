#include <stdio.h>
#include <algorithm>
using namespace std;


class coor{	//시간저장 클래스
	public:
		int x;//시작 시간
		int y;//끝나는 시간
};
bool compare(coor a, coor b) {	//끝나는 시간이 빠른 순으로
	if(a.y==b.y){	//끝나는 시간이 같다면
		return a.x < b.x;	//시작시간 오름차순
	}
	else{
		return a.y < b.y;
	}
}

int main(void){
	int N,i;
	scanf("%d",&N);
	coor arr[N];
	for(i=0;i<N;i++){
		scanf("%d %d",&arr[i].x, &arr[i].y);
	}
	
	sort(arr,arr+N,compare);
	
	// for(i=0;i<N;i++){	// sort테스트
	// 	printf("%d %d\n",arr[i].x, arr[i].y);
	// }
	
	int end=0, cnt=0;
	for(int i=0;i<N;i++){
		if(arr[i].x >= end){
			end = arr[i].y;
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}