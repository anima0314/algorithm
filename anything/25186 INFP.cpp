#include <stdio.h>

//(전체 옷 개수 / 2) >= 가장많은 옷개수이면 됨.
//가장많은 옷 사이사이에 다른옷을 넣어버리면 되기때문
int main() {
    int N,max=-1;
	int sum=0;
    scanf("%d",&N);
	int arr[N]={0,};
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<N;i++){
		max = (arr[i] > max) ? arr[i] : max;
		sum += arr[i];
//int범위를 벗어나면 가장 많은 옷의 최대(max)가 10만개인데
//전체옷개수(sum)가 20억이 넘으므로 항상 happy이다
		if(sum<0){
			printf("Happy");

			return 0;
		}
	}
	if(N==1 && max==1) printf("Happy");
	else if(sum/2 >= max){
		printf("Happy");
	}
	else{
		printf("Unhappy");
	}
    return 0;
}